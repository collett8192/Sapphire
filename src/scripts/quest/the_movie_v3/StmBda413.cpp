// FFXIVTheMovie.ParserV3.11
// param used:
//_ACTOR6 = B
//_ACTOR6B = 3|2
//_ACTOR7 = B
//_ACTOR7B = 3|2
//_ACTOR8 = B
//_ACTOR8B = 3|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda413 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda413() : Sapphire::ScriptAPI::QuestScript( 68048 ){}; 
  ~StmBda413() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 1 entries
  //SEQ_3, 5 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1021625
  //ACTOR1 = 1021608
  //ACTOR10 = 1021615
  //ACTOR2 = 1022085
  //ACTOR3 = 1021611
  //ACTOR4 = 1021612
  //ACTOR5 = 1021613
  //ACTOR6 = 1019321
  //ACTOR7 = 1019320
  //ACTOR8 = 1019322
  //ACTOR9 = 1021626
  //JPOZIGI = 5481
  //NCUTEVENT04070 = 1442
  //QSTACTOR1 = 6866108
  //STANDLISTEN = 801

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
        if( param1 == 1021625 ) // ACTOR0 = GOSETSU
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GOSETSU
          }
          break;
        }
        if( param1 == 1021608 ) // ACTOR1 = DOTHARL02511
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=DOTHARL02511
          break;
        }
        if( param1 == 1022085 ) // ACTOR2 = unknown
        {
          Scene00003( quest, player ); // Scene00003: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1021611 ) // ACTOR3 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1021612 ) // ACTOR4 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021608 ) // ACTOR1 = DOTHARL02511
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=DOTHARL02511
          break;
        }
        if( param1 == 1022085 ) // ACTOR2 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00008( quest, player ); // Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=GOSETSU
        break;
      }
      case 3:
      {
        if( param1 == 1019321 ) // ACTOR6 = MERGEN, CB=2
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=MERGEN
          }
          else
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=MERGEN
          }
          break;
        }
        if( param1 == 1019320 ) // ACTOR7 = KOKO, CB=2
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=KOKO
          }
          else
          {
            Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=KOKO
          }
          break;
        }
        if( param1 == 1019322 ) // ACTOR8 = QOYAR, CB=2
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=QOYAR
          }
          else
          {
            Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=QOYAR
          }
          break;
        }
        if( param1 == 1021626 ) // ACTOR9 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021615 ) // ACTOR10 = GOSETSU
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021615 ) // ACTOR10 = GOSETSU
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=GOSETSU
          break;
        }
        if( param1 == 1021626 ) // ACTOR9 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019321 ) // ACTOR6 = MERGEN
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=MERGEN
          break;
        }
        if( param1 == 1019320 ) // ACTOR7 = KOKO
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=KOKO
          break;
        }
        if( param1 == 1019322 ) // ACTOR8 = QOYAR
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=QOYAR
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
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 2 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 3 );
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 3 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setBitFlag8( 2, false );
      quest.setBitFlag8( 3, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00002: Normal(Talk, TargetCanMove), id=DOTHARL02511" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00003: Empty(None), id=unknown" );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00005: Empty(None), id=unknown" );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00006: Normal(Talk, TargetCanMove), id=DOTHARL02511" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00007: Empty(None), id=unknown" );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, UI8AL = 3, Flag8(1)=True, Branch(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00009: Normal(Talk, TargetCanMove), id=MERGEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 3 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }
  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, UI8AL = 3, Flag8(1)=True, Branch(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00010: Normal(Talk, TargetCanMove), id=MERGEN" );
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, nullptr );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 3, Flag8(2)=True, Branch(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00011: Normal(Talk, TargetCanMove), id=KOKO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 2, true );
      eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 3 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }
  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 3, Flag8(2)=True, Branch(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00012: Normal(Talk, TargetCanMove), id=KOKO" );
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, nullptr );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 3, Flag8(3)=True, Branch(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00013: Normal(Talk, TargetCanMove), id=QOYAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 3, true );
      eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 3 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }
  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 3, Flag8(3)=True, Branch(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00014: Normal(Talk, TargetCanMove), id=QOYAR" );
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, nullptr );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00016: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00018: Empty(None), id=unknown" );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00019: Normal(Talk, TargetCanMove), id=MERGEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00020: Normal(Talk, TargetCanMove), id=KOKO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda413:68048 calling Scene00021: Normal(Talk, TargetCanMove), id=QOYAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda413 );
