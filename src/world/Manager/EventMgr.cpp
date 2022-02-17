#include <Common.h>
#include <Exd/ExdDataGenerated.h>
#include <Util/Util.h>
#include <Service.h>

#include <Exd/ExdDataGenerated.h>
#include <datReader/DatCategories/bg/LgbTypes.h>
#include <datReader/DatCategories/bg/lgb.h>

#include "EventMgr.h"
#include "Event/EventHandler.h"

#include "Territory/InstanceObjectCache.h"

#include "Actor/Player.h"

using namespace Sapphire::Common;

std::string Sapphire::World::Manager::EventMgr::getEventName( uint32_t eventId )
{
  auto& exdData = Common::Service< Data::ExdDataGenerated >::ref();
  auto eventType = static_cast< Event::EventHandler::EventHandlerType >( eventId >> 16 );

  auto unknown = std::string{ "unknown" };

  switch( eventType )
  {
    case Event::EventHandler::EventHandlerType::Quest:
    {
      auto questInfo = exdData.get< Sapphire::Data::Quest >( eventId );
      if( !questInfo )
        return unknown + "Quest";

      std::string name = questInfo->id;
      std::size_t pos = name.find_first_of( "_" );

      return name.substr( 0, pos );
    }
    case Event::EventHandler::EventHandlerType::CustomTalk:
    {
      auto customTalkInfo = exdData.get< Sapphire::Data::CustomTalk >( eventId );
      if( !customTalkInfo )
        return unknown + "CustomTalk";

      std::string name = customTalkInfo->name;
      std::size_t pos = name.find_first_of( "_" );

      return customTalkInfo->name.substr( 0, pos );
    }
    case Event::EventHandler::EventHandlerType::Opening:
    {
      auto openingInfo = exdData.get< Sapphire::Data::Opening >( eventId );
      if( openingInfo )
        return openingInfo->name;
      return unknown + "Opening";
    }
    case Event::EventHandler::EventHandlerType::Aetheryte:
    {
      auto aetherInfo = exdData.get< Sapphire::Data::Aetheryte >( eventId & 0xFFFF );
      if( aetherInfo->isAetheryte )
        return "Aetheryte";
      return "Aethernet";
    }
    case Event::EventHandler::EventHandlerType::ICDirector:
    {
      // auto contentInfo = pExdData->get< Sapphire::Data::InstanceContent >( eventId & 0xFFFF );
      return "InstanceContentDirector#" + std::to_string( eventId & 0xFFFF );
    }
    case Event::EventHandler::EventHandlerType::QuestBattleDirector:
    {

      auto qbInfo = exdData.get< Sapphire::Data::QuestBattle >( eventId & 0xFFFF );
      if( !qbInfo )
        return "unknown";
      auto questInfo = exdData.get< Sapphire::Data::Quest >( qbInfo->quest );
      if( !questInfo )
        return "unknown";

      std::string name = questInfo->name;
      std::string remove( ",â˜…_ '()[]-\x1a\x1\x2\x1f\x1\x3.:" );
      Util::eraseAllIn( name, remove );
      name[ 0 ] = toupper( name[ 0 ] );
      return name;
    }
    case Event::EventHandler::EventHandlerType::PublicContentDirector:
    {
      auto pcInfo = exdData.get< Sapphire::Data::PublicContent >( eventId & 0x0000FFFF );
      if( !pcInfo )
        return "unknown";
      return pcInfo->name;
    }


    case Event::EventHandler::EventHandlerType::Warp:
    {
      auto warpInfo = exdData.get< Sapphire::Data::Warp >( eventId );
      if( warpInfo )
        return "WarpTaxi";
      return unknown + "ChocoboWarp"; //who know
    }

    case Event::EventHandler::EventHandlerType::Shop:
    {
      auto shopInfo = exdData.get< Sapphire::Data::GilShop >( eventId );

      return "GilShop" + std::to_string( eventId );
      /*if( shopInfo )
      {
        if( shopInfo->name.empty() || shopInfo->name == " " )
          return "GilShop" + std::to_string( eventId );
        return shopInfo->name;
      }*/
      //return unknown + "GilShop";
    }

    case Event::EventHandler::EventHandlerType::SwitchTalk:
    {
      return "FcTalk";
    }
    default:
    {
      return unknown;
    }
  }
}

uint32_t Sapphire::World::Manager::EventMgr::mapEventActorToRealActor( uint32_t eventActorId )
{
  auto& instanceObjectCache = Common::Service< InstanceObjectCache >::ref();
  auto& exdData = Common::Service< Data::ExdDataGenerated >::ref();
  auto levelInfo = exdData.get< Sapphire::Data::Level >( eventActorId );
  if( levelInfo )
    return levelInfo->object;
  else if( auto pObj = instanceObjectCache.getEObj( eventActorId ) )
    return pObj->data.eobjId;
  else if( auto pNpc = instanceObjectCache.getENpc( eventActorId ) )
    return pNpc->data.enpcId;

  return 0;
}

Sapphire::World::Quest Sapphire::World::Manager::EventMgr::getPlayerQuestDataFromEventId( Entity::Player& player, uint32_t eventId )
{
  for( uint16_t i = 0; i < 30; i++ )
  {
    auto activeQuests = player.getQuestActive( i );
    if( !activeQuests )
      continue;

    uint32_t id = activeQuests->c.questId | static_cast< uint16_t >( Event::EventHandler::EventHandlerType::Quest ) << 16;
    if( id == eventId )
    {
      return World::Quest( *activeQuests );
    }
  }
  return {};
}

void Sapphire::World::Manager::EventMgr::playQuestScene( Entity::Player& player, uint32_t eventId, uint32_t scene, uint32_t flags, Event::EventHandler::QuestSceneReturnCallback eventCallback )
{
  if( eventCallback )
  {
    player.playScene( eventId, scene, flags, [ eventId, eventCallback, this ]( Entity::Player& player, const Event::SceneResult& result )
      {
        auto quest = getPlayerQuestDataFromEventId( player, eventId );
        auto newQuest = false;
        if( quest.getId() == 0 )
        {
          quest.setId( static_cast< uint16_t >( eventId & 0x0000FFFF ) );
          newQuest = true;
        }
        auto copy = quest;
        eventCallback( quest, player, result );
        if( quest != copy && quest.getSeq() > 0 && ( newQuest || player.hasQuest( quest.getId() ) ) )
          player.updateQuest( quest );
      });
  }
  else
  {
    player.playScene( eventId, scene, flags, nullptr );
  }
}

void Sapphire::World::Manager::EventMgr::eventFinish( Sapphire::Entity::Player& player, uint32_t eventId, uint32_t freePlayer )
{
  player.eventFinish( eventId, freePlayer );
}

void Sapphire::World::Manager::EventMgr::sendEventNotice( Entity::Player& player, uint32_t questId, int8_t noticeId, uint8_t numOfArgs, uint32_t var1, uint32_t var2 )
{
  player.sendQuestMessage( questId, noticeId, numOfArgs, var1, var2 );
}

void Sapphire::World::Manager::EventMgr::eventActionStart( Entity::Player& player, uint32_t eventId, uint32_t action,
  World::Action::ActionCallback finishCallback, World::Action::ActionCallback interruptCallback,
  uint64_t additional )
{
  player.eventActionStart( eventId, action, finishCallback, interruptCallback, additional );
}