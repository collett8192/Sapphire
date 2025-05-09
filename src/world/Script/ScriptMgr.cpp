#include <Logging/Logger.h>
#include <Exd/ExdDataGenerated.h>

#include <watchdog/Watchdog.h>
#include <Service.h>

#include "Territory/Territory.h"
#include "Territory/InstanceContent.h"
#include "Territory/QuestBattle.h"
#include "Territory/PublicContent.h"
#include "Actor/Player.h"
#include "Actor/BNpc.h"
#include "Actor/EventObject.h"
#include "Actor/BNpc.h"
#include "ServerMgr.h"
#include "Event/EventHandler.h"
#include "Action/Action.h"

#include "Manager/EventMgr.h"

#include "StatusEffect/StatusEffect.h"

#include "Network/PacketWrappers/ServerNoticePacket.h"

#include "Script/ScriptMgr.h"

#include "NativeScriptMgr.h"
#include "ServerMgr.h"

// enable the ambiguity fix for every platform to avoid #define nonsense
#define WIN_AMBIGUITY_FIX

namespace fs = std::filesystem;

Sapphire::Scripting::ScriptMgr::ScriptMgr() :
  m_firstScriptChangeNotificiation( false )
{
  m_nativeScriptMgr = createNativeScriptMgr();
}

Sapphire::Scripting::ScriptMgr::~ScriptMgr()
{
  Watchdog::unwatchAll();
}

void Sapphire::Scripting::ScriptMgr::update()
{
  m_nativeScriptMgr->processLoadQueue();
}

bool Sapphire::Scripting::ScriptMgr::init()
{
  std::set< std::string > files;
  auto& serverMgr = Common::Service< World::ServerMgr >::ref();

  auto status = loadDir( serverMgr.getConfig().scripts.path, files, m_nativeScriptMgr->getModuleExtension() );

  if( !status )
  {
    Logger::error( "ScriptMgr: failed to load modules, the server will not function correctly without scripts loaded." );
    return false;
  }

  uint32_t scriptsFound = 0;
  uint32_t scriptsLoaded = 0;

  for( auto itr = files.begin(); itr != files.end(); ++itr )
  {
    auto& path = *itr;

    scriptsFound++;

    if( m_nativeScriptMgr->loadScript( path ) )
      scriptsLoaded++;
  }

  Logger::info( "ScriptMgr: Loaded {0}/{1} modules", scriptsLoaded, scriptsFound );

  watchDirectories();

  return true;
}

void Sapphire::Scripting::ScriptMgr::watchDirectories()
{
  auto& serverMgr = Common::Service< World::ServerMgr >::ref();
  auto shouldWatch = serverMgr.getConfig().scripts.hotSwap;
  if( !shouldWatch )
    return;

  Watchdog::watchMany( serverMgr.getConfig().scripts.path + "*" +
                       m_nativeScriptMgr->getModuleExtension(),
                       [ this ]( const std::vector< ci::fs::path >& paths )
                       {
                         if( !m_firstScriptChangeNotificiation )
                         {
                           // for whatever reason, the first time this runs, it detects every file as changed
                           // so we're always going to ignore the first notification
                           m_firstScriptChangeNotificiation = true;
                           return;
                         }

                         for( const auto& path : paths )
                         {
                           if( m_nativeScriptMgr->isModuleLoaded( path.stem().string() ) )
                           {
                             Logger::debug( "Reloading changed script: {0}", path.stem().string() );

                             m_nativeScriptMgr->queueScriptReload( path.stem().string() );
                           }
                           else
                           {
                             Logger::debug( "Loading new script: {0}", path.stem().string() );

                             m_nativeScriptMgr->loadScript( path.string() );
                           }
                         }
                       } );
}

bool Sapphire::Scripting::ScriptMgr::loadDir( const std::string& dirname, std::set< std::string >& files,
                                              const std::string& ext )
{
  Logger::info( "ScriptMgr: loading scripts from: {0}", dirname );

  if( !fs::exists( dirname ) )
  {
    Logger::error( "ScriptMgr: scripts directory doesn't exist" );
    return false;
  }

  fs::path targetDir( dirname );

  fs::directory_iterator iter( targetDir );

  for( const auto& i : iter )
  {
    if( fs::is_regular_file( i ) && fs::path( i ).extension() == ext )
    {
      files.insert( fs::path( i ).string() );
    }
  }

  if( !files.empty() )
    return true;
  else
  {
    Logger::error( "ScriptMgr: couldn't find any script modules" );
    return false;
  }
}

void Sapphire::Scripting::ScriptMgr::onDebug( uint32_t id, Entity::Player& player, uint32_t param )
{
  auto script = m_nativeScriptMgr->getScript( id );
  if( script )
    script->onDebug( player, param );
  else
    player.sendUrgent( "{script {} not found.}", id );
}

void Sapphire::Scripting::ScriptMgr::onPlayerFirstEnterWorld( Entity::Player& player )
{
//   try
//   {
//      std::string test = m_onFirstEnterWorld( player );
//   }
//   catch( const std::exception &e )
//   {
//      std::string what = e.what();
//   }
}

bool Sapphire::Scripting::ScriptMgr::onTalk( Entity::Player& player, uint64_t actorId, uint32_t eventId )
{
  // check if the actor is an eobj and call its script if we have one
  auto zone = player.getCurrentTerritory();
  if( auto eobj = zone->getEObj( actorId ) )
  {
    auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::EventObjectScript >( eobj->getObjectId() );
    if( script )
    {
      script->onTalk( eventId, player, *eobj );
      return true;
    }
  }

  // check for a direct eventid match first, otherwise default to base type
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::EventScript >( eventId );
  if( script )
  {
    script->onTalk( eventId, player, actorId );
    return true;
  }
  else
  {
    auto threePointOhScript = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestScript >( eventId );
    if( threePointOhScript )
    {
      auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
      auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
      auto quest = eventMgr.getPlayerQuestDataFromEventId( player, eventId );
      auto newQuest = false;
      if( quest.getId() == 0 )
      {
        quest.setId( static_cast< uint16_t >( eventId & 0x0000FFFF ) );
        newQuest = true;
      }
      auto copy = quest;
      threePointOhScript->onTalk( quest, player, actor );
      if( quest != copy && quest.getSeq() > 0 && ( newQuest || player.hasQuest( quest.getId() ) ) )
        player.updateQuest( quest );
      return true;
    }
    script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::EventScript >( eventId & 0xFFFF0000 );
    if( !script )
      return false;

    script->onTalk( eventId, player, actorId );
    return true;
  }
}

bool Sapphire::Scripting::ScriptMgr::onEnterTerritory( Entity::Player& player, uint32_t eventId,
                                                       uint16_t param1, uint16_t param2 )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::EventScript >( eventId );
  if( !script )
  {
    auto threePointOhScript = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestScript >( eventId );
    if( threePointOhScript )
    {
      auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
      auto quest = eventMgr.getPlayerQuestDataFromEventId( player, eventId );
      if( quest.getId() > 0 )
      {
        auto copy = quest;
        threePointOhScript->onEnterTerritory( quest, player, param1, param2 );
        if( quest != copy )
          player.updateQuest( quest );
        return true;
      }
    }
    return false;
  }
  script->onEnterTerritory( player, eventId, param1, param2 );
  return true;
}

bool Sapphire::Scripting::ScriptMgr::onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1,
                                                    float x, float y, float z )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::EventScript >( eventId );
  if( !script )
  {
    auto threePointOhScript = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestScript >( eventId );
    if( threePointOhScript )
    {
      auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
      auto quest = eventMgr.getPlayerQuestDataFromEventId( player, eventId );
      if( quest.getId() > 0 )
      {
        auto copy = quest;
        threePointOhScript->onWithinRange( quest, player, eventId, param1, x, y, z );
        if( quest != copy )
          player.updateQuest( quest );
        return true;
      }
    }
    return false;
  }
  script->onWithinRange( player, eventId, param1, x, y, z );
  return true;
}

bool Sapphire::Scripting::ScriptMgr::onOutsideRange( Entity::Player& player, uint32_t eventId, uint32_t param1,
                                                     float x, float y, float z )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::EventScript >( eventId );
  if( !script )
  {
    auto threePointOhScript = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestScript >( eventId );
    if( threePointOhScript )
    {
      auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
      auto quest = eventMgr.getPlayerQuestDataFromEventId( player, eventId );
      if( quest.getId() > 0 )
      {
        auto copy = quest;
        threePointOhScript->onOutsideRange( quest, player, eventId, param1, x, y, z );
        if( quest != copy )
          player.updateQuest( quest );
        return true;
      }
    }
    return false;
  }
  script->onOutsideRange( player, eventId, param1, x, y, z );
  return true;
}

bool Sapphire::Scripting::ScriptMgr::onEmote( Entity::Player& player, uint64_t actorId,
                                              uint32_t eventId, uint8_t emoteId )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::EventScript >( eventId );
  if( !script )
  {
    auto threePointOhScript = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestScript >( eventId );
    if( threePointOhScript )
    {
      auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
      auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
      auto quest = eventMgr.getPlayerQuestDataFromEventId( player, eventId );
      if( quest.getId() > 0 )
      {
        auto copy = quest;
        threePointOhScript->onEmote( quest, actor, emoteId, player );
        if( quest != copy )
          player.updateQuest( quest );
        return true;
      }
    }
    return false;
  }
  script->onEmote( actorId, eventId, emoteId, player );
  return true;
}

bool Sapphire::Scripting::ScriptMgr::onEventHandlerReturn( Entity::Player& player, uint32_t eventId,
                                                           uint16_t subEvent, uint16_t param1, uint16_t param2,
                                                           uint16_t param3 )
{

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onEventHandlerTradeReturn( Entity::Player& player, uint32_t eventId,
                                                                uint16_t subEvent, uint16_t param, uint32_t catalogId )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::EventScript >( eventId );
  if( script )
  {
    script->onEventHandlerTradeReturn( player, eventId, subEvent, param, catalogId );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onEventItem( Entity::Player& player, uint32_t eventItemId,
                                                  uint32_t eventId, uint32_t castTime, uint64_t targetId )
{
  auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();

  std::string eventName = "onEventItem";
  std::string objName = eventMgr.getEventName( eventId );
  player.sendDebug( "Calling: {0}.{1} - {2}", objName, eventName, eventId );

  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::EventScript >( eventId );
  if( script )
  {
    player.eventStart( targetId, eventId, Event::EventHandler::Item, 0, 0 );

    script->onEventItem( player, eventItemId, eventId, castTime, targetId );
    return true;
  }
  else
  {
    auto threePointOhScript = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestScript >( eventId );
    if( threePointOhScript )
    {
      auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
      auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( targetId ) );
      auto quest = eventMgr.getPlayerQuestDataFromEventId( player, eventId );
      if( quest.getId() > 0 )
      {
        auto copy = quest;
        threePointOhScript->onEventItem( quest, player, actor );
        if( quest != copy )
          player.updateQuest( quest );
        return true;
      }
    }
  }
  return false;
}

bool Sapphire::Scripting::ScriptMgr::onBNpcKill( Entity::Player& player, Entity::BNpc& bnpc )
{
  auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();

  // loop through all active quests and try to call available onBNpcKill callbacks
  for( size_t i = 0; i < 30; i++ )
  {
    auto activeQuests = player.getQuestActive( static_cast< uint16_t >( i ) );
    if( !activeQuests )
      continue;

    uint32_t questId = activeQuests->c.questId | static_cast< uint16_t >( Event::EventHandler::EventHandlerType::Quest ) << 16;

    auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::EventScript >( questId );
    if( script )
    {
      std::string objName = eventMgr.getEventName( questId );

      player.sendDebug( "Calling: {0}.onBnpcKill nameId#{1}", objName, bnpc.getBNpcNameId() );

      script->onBNpcKill( bnpc.getBNpcNameId(), player );
    }
    else
    {
      auto threePointOhScript = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestScript >( questId );
      if( threePointOhScript )
      {
        std::string objName = eventMgr.getEventName( questId );

        player.sendDebug( "Calling: {0}.onBnpcKill nameId={1}, layoutId={2}", objName, bnpc.getBNpcNameId(), 0 );
        auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
        auto quest = eventMgr.getPlayerQuestDataFromEventId( player, questId );
        if( quest.getId() > 0 )
        {
          auto copy = quest;
          threePointOhScript->onBNpcKill( quest, bnpc.getBNpcNameId(), 0, player );
          threePointOhScript->onBNpcKill( quest, bnpc, player );
          if( quest != copy )
            player.updateQuest( quest );
          return true;
        }
      } 
    }
  }

  return true;
}

bool Sapphire::Scripting::ScriptMgr::onEObjHit( Sapphire::Entity::Player& player, uint64_t actorId, uint32_t actionId )
{
  auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
  bool didCallScript = false;

  for( size_t i = 0; i < 30; i++ )
  {
    auto activeQuests = player.getQuestActive( static_cast< uint16_t >( i ) );
    if( !activeQuests )
      continue;

    uint32_t questId = activeQuests->c.questId | static_cast< uint16_t >( Event::EventHandler::EventHandlerType::Quest ) << 16;

    auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::EventScript >( questId );
    if( script )
    {
      didCallScript = true;
      std::string objName = eventMgr.getEventName( questId );

      player.sendDebug( "Calling: {0}.onEObjHit actorId#{1}", objName, actorId );

      script->onEObjHit( player, actorId, actionId );
    }
    else
    {
      auto threePointOhScript = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestScript >( questId );
      if( threePointOhScript )
      {
        auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
        auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
        auto quest = eventMgr.getPlayerQuestDataFromEventId( player, questId );
        if( quest.getId() > 0 )
        {
          auto copy = quest;
          threePointOhScript->onEObjHit( quest, player, actor, actionId );
          if( quest != copy )
            player.updateQuest( quest );
          return true;
        }
      }
    }
  }

  return didCallScript;
}

bool Sapphire::Scripting::ScriptMgr::onBeforePreCheck( World::Action::Action& action )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::ActionScript >( action.getId() );

  if( script )
  {
    script->onBeforePreCheck( action );
    return true;
  }
  return false;
}

bool Sapphire::Scripting::ScriptMgr::onExecute( World::Action::Action& action )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::ActionScript >( action.getId() );

  if( script )
  {
    script->onExecute( action );
    return true;
  }
  return false;
}

bool Sapphire::Scripting::ScriptMgr::onBeforeBuildEffect( World::Action::Action& action, uint8_t victimCounter, uint8_t validVictimCounter )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::ActionScript >( action.getId() );

  if( script )
  {
    script->onBeforeBuildEffect( action, victimCounter, validVictimCounter );
    return true;
  }
  return false;
};

bool Sapphire::Scripting::ScriptMgr::onAfterBuildEffect( World::Action::Action& action )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::ActionScript >( action.getId() );

  if( script )
  {
    script->onAfterBuildEffect( action );
    return true;
  }
  return false;
}

bool Sapphire::Scripting::ScriptMgr::onInterrupt( World::Action::Action& action )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::ActionScript >( action.getId() );

  if( script )
  {
    script->onInterrupt( action );
    return true;
  }
  return false;
}

bool Sapphire::Scripting::ScriptMgr::onStart( World::Action::Action& action )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::ActionScript >( action.getId() );

  if( script )
  {
    script->onStart( action );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onStatusReceive( Entity::CharaPtr pActor, uint32_t effectId )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::StatusEffectScript >( effectId );

  if( script )
  {
    if( pActor->isPlayer() )
      pActor->getAsPlayer()->sendDebug( "Calling status receive for statusid#{0}", effectId );

    script->onApply( *pActor );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onStatusTick( Entity::CharaPtr pChara, Sapphire::StatusEffect::StatusEffect& effect )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::StatusEffectScript >( effect.getId() );
  if( script )
  {
    if( pChara->isPlayer() )
      pChara->getAsPlayer()->sendDebug( "Calling status tick for statusid#{0}", effect.getId() );

    script->onTick( *pChara );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onStatusTimeOut( Entity::CharaPtr pChara, uint32_t effectId )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::StatusEffectScript >( effectId );
  if( script )
  {
    if( pChara->isPlayer() )
      pChara->getAsPlayer()->sendDebug( "Calling status timeout for statusid#{0}", effectId );

    script->onExpire( *pChara );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onZoneInit( TerritoryPtr pZone )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::ZoneScript >( pZone->getTerritoryTypeId() );
  if( script )
  {
    script->onZoneInit();
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onInstanceInit( InstanceContentPtr instance )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::InstanceContentScript >( instance->getDirectorId() );
  if( script )
  {
    script->onInit( *instance );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onInstanceUpdate( InstanceContentPtr instance, uint64_t tickCount )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::InstanceContentScript >( instance->getDirectorId() );

  if( script )
  {
    script->onUpdate( *instance, tickCount );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onInstanceEnterTerritory( InstanceContentPtr instance, Entity::Player& player,
                                                               uint32_t eventId, uint16_t param1, uint16_t param2 )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::InstanceContentScript >( instance->getDirectorId() );
  if( script )
  {
    script->onEnterTerritory( *instance, player, eventId, param1, param2 );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onPlayerSetup( QuestBattle& instance, Entity::Player& player )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestBattleScript >( instance.getDirectorId() );
  if( script )
  {
    script->onPlayerSetup( instance, player );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onInstanceInit( QuestBattlePtr instance )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestBattleScript >( instance->getDirectorId() );
  if( script )
  {
    script->onInit( *instance );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onInstanceUpdate( QuestBattlePtr instance, uint64_t tickCount )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestBattleScript >( instance->getDirectorId() );

  if( script )
  {
    script->onUpdate( *instance, tickCount );
    return true;
  }

  return false;
}


bool Sapphire::Scripting::ScriptMgr::onDutyCommence( QuestBattle& instance, Entity::Player& player )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestBattleScript >( instance.getDirectorId() );

  if( script )
  {
    script->onDutyCommence( instance, player );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onInstanceEnterTerritory( QuestBattlePtr instance, Entity::Player& player,
                                                               uint32_t eventId, uint16_t param1, uint16_t param2 )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestBattleScript >( instance->getDirectorId() );
  if( script )
  {
    script->onEnterTerritory( *instance, player, eventId, param1, param2 );
    return true;
  }

  return false;
}

Sapphire::Scripting::NativeScriptMgr& Sapphire::Scripting::ScriptMgr::getNativeScriptHandler()
{
  return *m_nativeScriptMgr;
}

bool Sapphire::Scripting::ScriptMgr::onDutyComplete( Sapphire::QuestBattlePtr instance, Sapphire::Entity::Player& player )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::QuestBattleScript >( instance->getDirectorId() );
  if( script )
  {
    script->onDutyComplete( *instance, player );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onEventYield( Sapphire::Entity::Player& player, uint32_t eventId, uint16_t scene, std::vector< uint32_t > param )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::EventScript >( eventId );
  if( script )
  {
    script->onEventYield( player, scene, param );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onPublicContentInit( PublicContentPtr instance )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::PublicContentScript >( instance->getDirectorId() );
  if( script )
  {
    script->onInit( *instance );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onPublicContentUpdate( PublicContentPtr instance, uint64_t tickCount )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::PublicContentScript >( instance->getDirectorId() );

  if( script )
  {
    script->onUpdate( *instance, tickCount );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onPublicContentPlayerZoneIn( PublicContentPtr instance, Entity::Player& player )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::PublicContentScript >( instance->getDirectorId() );
  if( script )
  {
    script->onPlayerZoneIn( *instance, player );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onPublicContentLeaveTerritory( PublicContentPtr instance, Entity::Player& player )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::PublicContentScript >( instance->getDirectorId() );
  if( script )
  {
    script->onLeaveTerritory( *instance, player );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onPublicContentEnterTerritory( PublicContentPtr instance, Entity::Player& player,
  uint32_t eventId, uint16_t param1, uint16_t param2 )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::PublicContentScript >( instance->getDirectorId() );
  if( script )
  {
    script->onEnterTerritory( *instance, player, eventId, param1, param2 );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onBNpcInit( Entity::BNpc& bnpc )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::BattleNpcScript >( bnpc.getBNpcBaseId() );
  if( script )
  {
    script->onInit( bnpc );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onBNpcUpdate( Entity::BNpc& bnpc, uint64_t tickCount )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::BattleNpcScript >( bnpc.getBNpcBaseId() );
  if( script )
  {
    script->onUpdate( bnpc, tickCount );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onBNpcHateListAdd( Entity::BNpc& bnpc, Entity::Chara& target )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::BattleNpcScript >( bnpc.getBNpcBaseId() );
  if( script )
  {
    script->onHateListAdd( bnpc, target );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onBNpcHateListRemove( Entity::BNpc& bnpc, Entity::Chara& target )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::BattleNpcScript >( bnpc.getBNpcBaseId() );
  if( script )
  {
    script->onHateListRemove( bnpc, target );
    return true;
  }

  return false;
}

bool Sapphire::Scripting::ScriptMgr::onBNpcDeath( Entity::BNpc& bnpc )
{
  auto script = m_nativeScriptMgr->getScript< Sapphire::ScriptAPI::BattleNpcScript >( bnpc.getBNpcBaseId() );
  if( script )
  {
    script->onDeath( bnpc );
    return true;
  }

  return false;
}
