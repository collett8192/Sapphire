#include <string>
#include <typeinfo>
#include <typeindex>
#include "NativeScriptApi.h"
#include <cassert>

#include "Actor/Player.h"
#include <Service.h>
#include "Script/ScriptMgr.h"
#include "Script/NativeScriptMgr.h"
#include "Territory/InstanceContent.h"

#ifdef _MSC_VER
#define EXPORT __declspec( dllexport )
#else
#define EXPORT __attribute__((visibility("default")))
#endif

using namespace Sapphire;

namespace Sapphire::ScriptAPI
{
  ScriptObject::ScriptObject( uint32_t id, std::size_t type ) :
    m_id( id ),
    m_type( type )
  {
  }

  uint32_t ScriptObject::getId() const
  {
    return m_id;
  }

  std::size_t ScriptObject::getType() const
  {
    return m_type;
  }

  void ScriptObject::onDebug( Entity::Player& player, uint32_t param )
  {
  }

  void ScriptObject::the_movie_callback( Sapphire::Entity::Player& player, const Sapphire::Event::SceneResult& result, uint32_t questId, uint8_t targetSeq, const uint32_t* sceneList, uint32_t index )
  {
    auto instance = player.getCurrentTerritory()->getAsDirector();
    int mode = 1;
    if( player.getCurrentQuestBattle() )
      mode = 2;
    auto nextScene = sceneList[ index + 1 ];
    if( nextScene == 0 )
    {
      player.eventFinish( instance->getDirectorId(), 1 );
      player.updateQuest( questId, targetSeq );
      player.exitInstance();
      switch( mode )
      {
        case 1:
        {
          Sapphire::Common::Service< Sapphire::Scripting::ScriptMgr >::ref().getNativeScriptHandler().getScript< InstanceContentScript >( instance->getDirectorId() )->the_movie_on_content_skipped( player );
          break;
        }
        case 2:
        {
          Sapphire::Common::Service< Sapphire::Scripting::ScriptMgr >::ref().getNativeScriptHandler().getScript< QuestBattleScript >( instance->getDirectorId() )->the_movie_on_content_skipped( player );
          break;
        }
      }
    }
    else
    {
      switch( mode )
      {
        case 1:
        {
          player.playScene( instance->getDirectorId(), 3, 3074, 0, 1, nextScene, std::bind( &ScriptObject::the_movie_callback, this, std::placeholders::_1, std::placeholders::_2, questId, targetSeq, sceneList, index + 1 ) );
          break;
        }
        case 2:
        {
          player.playScene( instance->getDirectorId(), nextScene, 3074, 0, 0, 0, std::bind( &ScriptObject::the_movie_callback, this, std::placeholders::_1, std::placeholders::_2, questId, targetSeq, sceneList, index + 1 ) );
          break;
        }
      }
    }
  }

  ///////////////////////////////////////////////////////////////////

  StatusEffectScript::StatusEffectScript( uint32_t effectId ) :
    ScriptObject( effectId, typeid( StatusEffectScript ).hash_code() )
  {
  }

  void StatusEffectScript::onTick( Entity::Chara& actor )
  {
  }

  void StatusEffectScript::onApply( Entity::Chara& actor )
  {
  }

  void StatusEffectScript::onRemove( Entity::Chara& actor )
  {
  }

  void StatusEffectScript::onExpire( Entity::Chara& actor )
  {
  }

  void StatusEffectScript::onPlayerCollision( Entity::Chara& actor, Entity::Chara& actorHit )
  {
  }

  void StatusEffectScript::onPlayerFinishCast( Entity::Chara& actor )
  {
  }

  void StatusEffectScript::onPlayerDamaged( Entity::Chara& actor )
  {
  }

  void StatusEffectScript::onPlayerDeath( Entity::Chara& actor )
  {
  }

  ///////////////////////////////////////////////////////////////////

  ActionScript::ActionScript( uint32_t actionId ) :
    ScriptObject( actionId, typeid( ActionScript ).hash_code() )
  {
  }

  void ActionScript::onBeforePreCheck( Sapphire::World::Action::Action& action )
  {
  }

  void ActionScript::onStart( Sapphire::World::Action::Action& action )
  {
  }

  void ActionScript::onExecute( Sapphire::World::Action::Action& action )
  {
  }

  void ActionScript::onBeforeBuildEffect( Sapphire::World::Action::Action& action, uint8_t victimCounter, uint8_t validVictimCounter )
  {
  }

  void ActionScript::onAfterBuildEffect( Sapphire::World::Action::Action& action )
  {
  }

  void ActionScript::onInterrupt( Sapphire::World::Action::Action& action )
  {
  }

  ///////////////////////////////////////////////////////////////////

  EventScript::EventScript( uint32_t eventId ) :
    ScriptObject( eventId, typeid( EventScript ).hash_code() )
  {
  }

  void EventScript::onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId )
  {
  }

  void EventScript::onBNpcKill( uint32_t nameId, Entity::Player& player )
  {
  }

  void EventScript::onEmote( uint64_t actorId, uint32_t eventId, uint32_t emoteId, Entity::Player& player )
  {
    player.m_the_movie_hack_flag = 1;
  }

  void EventScript::onEnterTerritory( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2 )
  {
  }

  void EventScript::onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z )
  {
  }

  void EventScript::onOutsideRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z )
  {
  }

  void EventScript::onEventItem( Entity::Player& player, uint32_t eventItemId, uint32_t eventId, uint32_t castTime,
                                 uint64_t targetId )
  {
  }

  void EventScript::onEventHandlerTradeReturn( Entity::Player& player, uint32_t eventId, uint16_t subEvent, uint16_t param,
                                              uint32_t catalogId )
  {
  }

  void EventScript::onEObjHit( Sapphire::Entity::Player& player, uint64_t actorId, uint32_t actionId )
  {
  }

  void EventScript::onEventYield( Sapphire::Entity::Player& player, uint16_t scene, std::vector< uint32_t > param )
  {
  }

  Event::EventHandler::QuestAvailability EventScript::getQuestAvailability( Sapphire::Entity::Player& player, uint32_t eventId )
  {
    return Event::EventHandler::QuestAvailability::Available;
  }

  ///////////////////////////////////////////////////////////////////

  QuestScript::QuestScript( uint32_t eventId ) : ScriptObject( eventId, typeid( QuestScript ).hash_code() )
  {
  }

  void QuestScript::onTalk( World::Quest& quest, Entity::Player& player, uint64_t actorId )
  {
  }

  void QuestScript::onSay( World::Quest& quest, Entity::Player& player, uint64_t actorId, uint32_t sayId )
  {
  }

  void QuestScript::onEventItem( World::Quest& quest, Entity::Player& player, uint64_t actorId )
  {
  }

  void QuestScript::onBNpcKill( World::Quest& quest, uint16_t nameId, uint32_t layoutId, Entity::Player& player )
  {
  }

  void QuestScript::onBNpcKill( World::Quest& quest, Entity::BNpc& bnpc, Entity::Player& player )
  {
  }

  void QuestScript::onTriggerOwnerDeaggro( World::Quest& quest, uint32_t layoutId, uint32_t entityId, Sapphire::Entity::Player& player )
  {
  }

  void QuestScript::onEmote( World::Quest& quest, uint64_t actorId, uint32_t emoteId, Entity::Player& player )
  {
  }

  void QuestScript::onEnterTerritory( World::Quest& quest, Entity::Player& player, uint16_t param1, uint16_t param2 )
  {
  }

  void QuestScript::onWithinRange( World::Quest& quest, Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z )
  {
  }

  void QuestScript::onOutsideRange( World::Quest& quest, Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z )
  {
  }

  void QuestScript::onEventHandlerTradeReturn( Entity::Player& player, uint32_t eventId, uint16_t subEvent, uint16_t param, uint32_t catalogId )
  {
  }

  void QuestScript::onEObjHit( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId, uint32_t actionId )
  {
  }

  ///////////////////////////////////////////////////////////////////

  EventObjectScript::EventObjectScript( uint32_t eobjId ) :
    ScriptObject( eobjId, typeid( EventObjectScript ).hash_code() )
  {
  }

  void EventObjectScript::onTalk( uint32_t eventId, Sapphire::Entity::Player& player, Entity::EventObject& eobj )
  {
  }

  ///////////////////////////////////////////////////////////////////

  BattleNpcScript::BattleNpcScript( uint32_t npcId ) :
    ScriptObject( npcId, typeid( BattleNpcScript ).hash_code() )
  {
  }

  void BattleNpcScript::onInit( Entity::BNpc& bnpc )
  {
  }

  void BattleNpcScript::onUpdate( Entity::BNpc& bnpc, uint64_t tickCount )
  {
  }

  void BattleNpcScript::onHateListAdd( Entity::BNpc& bnpc, Entity::Chara& target )
  {
  }

  void BattleNpcScript::onHateListRemove( Entity::BNpc& bnpc, Entity::Chara& target )
  {
  }

  void BattleNpcScript::onDeath( Entity::BNpc& bnpc )
  {
  }

  ///////////////////////////////////////////////////////////////////

  ZoneScript::ZoneScript( uint32_t zoneId ) :
    ScriptObject( zoneId, typeid( ZoneScript ).hash_code() )
  {
  }

  void ZoneScript::onZoneInit()
  {
  }

  ///////////////////////////////////////////////////////////////////

  InstanceContentScript::InstanceContentScript( uint32_t instanceContentId ) :
    ScriptObject( uint32_t{ 0x8003 } << 16 | instanceContentId, typeid( InstanceContentScript ).hash_code() )
  {
  }

  void InstanceContentScript::onInit( InstanceContent& instance )
  {
  }

  void InstanceContentScript::onUpdate( InstanceContent& instance, uint64_t tickCount )
  {
  }

  void InstanceContentScript::onEnterTerritory( InstanceContent& instance, Entity::Player& player, uint32_t eventId,
                                                uint16_t param1, uint16_t param2 )
  {
  }

  bool InstanceContentScript::the_movie_on_content_skipped( Sapphire::Entity::Player& player )
  {
    return false;
  }

  ///////////////////////////////////////////////////////////////////

  QuestBattleScript::QuestBattleScript( uint32_t questBattleId ) :
    ScriptObject( uint32_t{ 0x8006 } << 16 | questBattleId, typeid( QuestBattleScript ).hash_code() )
  {
  }

  void QuestBattleScript::onDutyComplete( Sapphire::QuestBattle& instance, Entity::Player& player )
  {

  }

  void QuestBattleScript::onPlayerSetup( Sapphire::QuestBattle& instance, Entity::Player& player )
  {
  }

  void QuestBattleScript::onInit( QuestBattle& instance )
  {
  }

  void QuestBattleScript::onUpdate( QuestBattle& instance, uint64_t tickCount )
  {
  }

  void QuestBattleScript::onDutyCommence( QuestBattle& instance, Entity::Player& player )
  {
  }

  void QuestBattleScript::onEnterTerritory( QuestBattle& instance, Entity::Player& player, uint32_t eventId,
                                            uint16_t param1, uint16_t param2 )
  {
  }

  bool QuestBattleScript::the_movie_on_content_skipped( Sapphire::Entity::Player& player )
  {
    return false;
  }

  PublicContentScript::PublicContentScript( uint32_t contentId ) :
    ScriptObject( uint32_t{ 0x8004 } << 16 | contentId, typeid( PublicContentScript ).hash_code() )
  {
  }

  void PublicContentScript::onInit( PublicContent& instance )
  {
  }

  void PublicContentScript::onUpdate( PublicContent& instance, uint64_t tickCount )
  {
  }

  void PublicContentScript::onPlayerZoneIn( PublicContent& instance, Entity::Player& player )
  {
  }

  void PublicContentScript::onLeaveTerritory( PublicContent& instance, Entity::Player& player )
  {
  }

  void PublicContentScript::onEnterTerritory( PublicContent& instance, Entity::Player& player, uint32_t eventId,
    uint16_t param1, uint16_t param2 )
  {
  }

}

