// FFXIVTheMovie.ParserV3.12
// param used:
//_ACTOR2 = B
//_ACTOR2B = 1|2
//_ACTOR3 = B
//_ACTOR3B = 1|2
//_ACTOR4 = B
//_ACTOR4B = 1|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBdb102 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBdb102() : Sapphire::ScriptAPI::QuestScript( 68499 ){}; 
  ~StmBdb102() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1024137
  //ACTOR1 = 1024138
  //ACTOR2 = 1024130
  //ACTOR3 = 1024131
  //ACTOR4 = 1024132
  //ACTOR5 = 1024133
  //ACTOR6 = 1024103
  //ACTOR7 = 1024104
  //BINDACTOR01 = 7074886
  //EVENTPICTRUESTMBDB10201 = 561
  //EVENTPICTRUESTMBDB10202 = 562
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019537
  //LOCBGM01 = 459
  //LOCBGM02 = 92

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
        if( param1 == 1024137 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1024138 ) // ACTOR1 = ARENVALD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1024130 ) // ACTOR2 = MIDDLEAGEMAN, CB=2
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=MIDDLEAGEMAN
          }
          else
          {
            Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=MIDDLEAGEMAN
          }
          break;
        }
        if( param1 == 1024131 ) // ACTOR3 = MIDDLEAGEWOMAN, CB=2
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=MIDDLEAGEWOMAN
          }
          else
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=MIDDLEAGEWOMAN
          }
          break;
        }
        if( param1 == 1024132 ) // ACTOR4 = MIDDLEAGEHELLSGUARD, CB=2
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=MIDDLEAGEHELLSGUARD
          }
          else
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=MIDDLEAGEHELLSGUARD
          }
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1024133 ) // ACTOR5 = ERNOLD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ERNOLD
          }
          break;
        }
        if( param1 == 1024130 ) // ACTOR2 = MIDDLEAGEMAN
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=MIDDLEAGEMAN
          break;
        }
        if( param1 == 1024131 ) // ACTOR3 = MIDDLEAGEWOMAN
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=MIDDLEAGEWOMAN
          break;
        }
        if( param1 == 1024132 ) // ACTOR4 = MIDDLEAGEHELLSGUARD
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=MIDDLEAGEHELLSGUARD
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1024103 ) // ACTOR6 = ARENVALD
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=ARENVALD
          break;
        }
        if( param1 == 1024133 ) // ACTOR5 = ERNOLD
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=ERNOLD
          break;
        }
        if( param1 == 1024104 ) // ACTOR7 = ALPHINAUD
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
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
    if( quest.getUI8AL() == 3 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setBitFlag8( 2, false );
      quest.setBitFlag8( 3, false );
      quest.setSeq( 2 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, HIDE_HOTBAR, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00002: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 3, Flag8(1)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00003: Normal(Talk, TargetCanMove), id=MIDDLEAGEMAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 3 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }
  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 3, Flag8(1)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00004: Normal(Talk, TargetCanMove), id=MIDDLEAGEMAN" );
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, nullptr );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 3, Flag8(2)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00005: Normal(Talk, TargetCanMove), id=MIDDLEAGEWOMAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 2, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 3 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }
  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 3, Flag8(2)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00006: Normal(Talk, TargetCanMove), id=MIDDLEAGEWOMAN" );
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, nullptr );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 3, Flag8(3)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00007: Normal(Talk, TargetCanMove), id=MIDDLEAGEHELLSGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 3, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 3 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }
  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 3, Flag8(3)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00008: Normal(Talk, TargetCanMove), id=MIDDLEAGEHELLSGUARD" );
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, nullptr );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00009: Normal(Talk, TargetCanMove), id=ERNOLD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00010: Normal(Talk, TargetCanMove), id=MIDDLEAGEMAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00011: Normal(Talk, TargetCanMove), id=MIDDLEAGEWOMAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00012: Normal(Talk, TargetCanMove), id=MIDDLEAGEHELLSGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00014: Normal(Talk, TargetCanMove), id=ERNOLD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb102:68499 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBdb102 );
