// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBdz003 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBdz003() : Sapphire::ScriptAPI::QuestScript( 68173 ){}; 
  ~StmBdz003() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1021167
  //ACTOR1 = 1021168
  //ACTOR2 = 1021169
  //ACTOR3 = 1021170
  //ACTOR4 = 1021171
  //ACTOR5 = 1021172
  //QSTACTION0 = 954

  static constexpr auto EVENT_ON_TALK = 0;
  static constexpr auto EVENT_ON_EMOTE = 1;
  static constexpr auto EVENT_ON_BNPC_KILL = 2;
  static constexpr auto EVENT_ON_WITHIN_RANGE = 3;
  static constexpr auto EVENT_ON_ENTER_TERRITORY = 4;
  static constexpr auto EVENT_ON_EVENT_ITEM = 5;
  static constexpr auto EVENT_ON_EOBJ_HIT = 6;
  static constexpr auto EVENT_ON_SAY = 7;

private:
  void onProgress( World::Quest& quest, Entity::Player& player, uint32_t type, uint64_t param1, uint32_t param2, uint32_t param3 )
  {
    switch( quest.getSeq() )
    {
      case 0:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ANANTASOLDIER02637
        break;
      }
      case 1:
      {
        if( param1 == 1021168 ) // ACTOR1 = BRAVESOLDIER02637
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=BRAVESOLDIER02637
          }
          break;
        }
        if( param1 == 1021169 ) // ACTOR2 = YOUNGSOLDIER02637
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00003( quest, player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=YOUNGSOLDIER02637
          }
          break;
        }
        if( param1 == 1021170 ) // ACTOR3 = YANGSOLDIER02637
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00004( quest, player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=YANGSOLDIER02637
          }
          break;
        }
        if( param1 == 1021171 ) // ACTOR4 = SINGANSOLDIER02637
        {
          if( !quest.getBitFlag8( 4 ) )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=SINGANSOLDIER02637
          }
          break;
        }
        if( param1 == 1021172 ) // ACTOR5 = SOWASOWAUSOLDIER02637
        {
          if( !quest.getBitFlag8( 5 ) )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=SOWASOWAUSOLDIER02637
          }
          break;
        }
        if( param1 == 1021167 ) // ACTOR0 = ANANTASOLDIER
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ANANTASOLDIER
          break;
        }
        break;
      }
      case 255:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00008( quest, player ); // Scene00008: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=ANANTASOLDIER02637
        break;
      }
      default:
      {
        playerMgr().sendUrgent( player, "Sequence {} not defined.", quest.getSeq() );
        break;
      }
    }
  }

public:
  void onTalk( World::Quest& quest, Entity::Player& player, uint64_t actorId ) override
  {
    onProgress( quest, player, EVENT_ON_TALK, actorId, 0, 0 );
  }

  void onEmote( World::Quest& quest, uint64_t actorId, uint32_t emoteId, Sapphire::Entity::Player& player ) override
  {
    playerMgr().sendDebug( player, "emote: {}", emoteId );
    onProgress( quest, player, EVENT_ON_EMOTE, actorId, 0, emoteId );
  }

  void onBNpcKill( World::Quest& quest, Entity::BNpc& bnpc, Entity::Player& player ) override
  {
    onProgress( quest, player, EVENT_ON_BNPC_KILL, static_cast< uint64_t >( bnpc.getBNpcNameId() ), bnpc.getLayoutId(), 0 );
  }

  void onWithinRange( World::Quest& quest, Sapphire::Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( quest, player, EVENT_ON_WITHIN_RANGE, static_cast< uint64_t >( param1 ), 0, 0 );
  }

  void onEnterTerritory( World::Quest& quest, Sapphire::Entity::Player& player, uint16_t param1, uint16_t param2 ) override
  {
    onProgress( quest, player, EVENT_ON_ENTER_TERRITORY, static_cast< uint64_t >( param1 ), static_cast< uint32_t >( param2 ), 0 );
  }
  void onEventItem( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId ) override
  {
    onProgress( quest, player, EVENT_ON_EVENT_ITEM, actorId, 0, 0 );
  }
  void onEObjHit( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId, uint32_t actionId ) override
  {
    onProgress( quest, player, EVENT_ON_EOBJ_HIT, actorId, actionId, 0 );
  }
  void onSay( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId, uint32_t sayId ) override
  {
    onProgress( quest, player, EVENT_ON_SAY, actorId, sayId, 0 );
  }

private:
  void checkProgressSeq0( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 1 );
  }
  void checkProgressSeq1( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 5 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setBitFlag8( 2, false );
      quest.setBitFlag8( 3, false );
      quest.setBitFlag8( 4, false );
      quest.setBitFlag8( 5, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdz003:68173 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, HIDE_HOTBAR, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdz003:68173 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ANANTASOLDIER02637" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 5, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdz003:68173 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=BRAVESOLDIER02637" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 5 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 5, Flag8(2)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdz003:68173 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=YOUNGSOLDIER02637" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 2, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 5 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 5, Flag8(3)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdz003:68173 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=YANGSOLDIER02637" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 3, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 5 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 5, Flag8(4)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdz003:68173 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=SINGANSOLDIER02637" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 4, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 5 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 5, Flag8(5)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdz003:68173 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=SOWASOWAUSOLDIER02637" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 5, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 5 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdz003:68173 calling Scene00007: Normal(Talk, TargetCanMove), id=ANANTASOLDIER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdz003:68173 calling Scene00008: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=ANANTASOLDIER02637" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBdz003 );
