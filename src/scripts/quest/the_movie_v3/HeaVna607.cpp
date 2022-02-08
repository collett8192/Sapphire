// FFXIVTheMovie.ParserV3.8
// param used:
//SCENE_10 = actor4
//SCENE_11 = golem_a
//SCENE_12 = golem_a
//SCENE_13 = golem_b
//SCENE_14 = golem_b
//_ACTOR5 = C
//_ACTOR5C = 2|2
//_ACTOR6 = C
//_ACTOR6C = 2|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna607 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna607() : Sapphire::ScriptAPI::QuestScript( 67192 ){}; 
  ~HeaVna607() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 5 entries
  //SEQ_2, 7 entries
  //SEQ_255, 3 entries

  //ACTIONTIMELINEBATTLECORPSE = 73
  //ACTIONTIMELINEBATTLEDEAD = 72
  //ACTOR0 = 1012097
  //ACTOR1 = 1012409
  //ACTOR10 = 1012412
  //ACTOR11 = 1012408
  //ACTOR2 = 1012410
  //ACTOR3 = 1013191
  //ACTOR4 = 1014563
  //ACTOR5 = 1012413
  //ACTOR6 = 1014413
  //ACTOR7 = 1012414
  //ACTOR8 = 1012415
  //ACTOR9 = 1012411
  //QSTACTOR0 = 5863807

  static constexpr auto EVENT_ON_TALK = 0;
  static constexpr auto EVENT_ON_EMOTE = 1;
  static constexpr auto EVENT_ON_BNPC_KILL = 2;
  static constexpr auto EVENT_ON_WITHIN_RANGE = 3;
  static constexpr auto EVENT_ON_ENTER_TERRITORY = 4;
  static constexpr auto EVENT_ON_EVENT_ITEM = 5;
  static constexpr auto EVENT_ON_EOBJ_HIT = 6;

private:
  void onProgress( World::Quest& quest, Entity::Player& player, uint32_t type, uint64_t param1, uint32_t param2, uint32_t param3 )
  {
    switch( quest.getSeq() )
    {
      case 0:
      {
        if( param1 == 1012097 ) // ACTOR0 = SLOWFIX
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SLOWFIX
          }
          break;
        }
        if( param1 == 1012409 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012410 ) // ACTOR2 = YSHTOLA
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1013191 ) // ACTOR3 = unknown
        {
          Scene00004( quest, player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1014563 ) // ACTOR4 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012410 ) // ACTOR2 = YSHTOLA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove, SystemTalk, ENpcBind), id=YSHTOLA
          }
          break;
        }
        if( param1 == 1012409 ) // ACTOR1 = ALPHINAUD
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012097 ) // ACTOR0 = SLOWFIX
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=SLOWFIX
          break;
        }
        if( param1 == 1013191 ) // ACTOR3 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1014563 ) // ACTOR4 = actor4
        {
          Scene00010( quest, player ); // Scene00010: Normal(None), id=actor4
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1012413 ) // ACTOR5 = golem_a
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove, SystemTalk), id=golem_a
            // +Callback Scene00012: Normal(NpcDespawn, TargetCanMove, SystemTalk), id=golem_a
          }
          break;
        }
        if( param1 == 1014413 ) // ACTOR6 = golem_b
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove, SystemTalk), id=golem_b
            // +Callback Scene00014: Normal(NpcDespawn, TargetCanMove, SystemTalk), id=golem_b
          }
          break;
        }
        if( param1 == 1012414 ) // ACTOR7 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012415 ) // ACTOR8 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012411 ) // ACTOR9 = ALPHINAUD
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012412 ) // ACTOR10 = YSHTOLA
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012408 ) // ACTOR11 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012097 ) // ACTOR0 = SLOWFIX
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SLOWFIX
          break;
        }
        if( param1 == 1012409 ) // ACTOR1 = ALPHINAUD
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012410 ) // ACTOR2 = YSHTOLA
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA
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

  void onBNpcKill( World::Quest& quest, uint16_t nameId, uint32_t entityId, Sapphire::Entity::Player& player ) override
  {
    onProgress( quest, player, EVENT_ON_BNPC_KILL, static_cast< uint64_t >( nameId ), entityId, 0 );
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
    if( quest.getUI8AL() == 2 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setBitFlag8( 2, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SLOWFIX" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove, SystemTalk, ENpcBind), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00008: Normal(Talk, TargetCanMove), id=SLOWFIX" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00010: Normal(None), id=actor4" );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 2, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00011: Normal(Talk, TargetCanMove, SystemTalk), id=golem_a" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00012( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }
  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 2, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00012: Normal(NpcDespawn, TargetCanMove, SystemTalk), id=golem_a" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 2, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00013: Normal(Talk, TargetCanMove, SystemTalk), id=golem_b" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00014( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }
  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 2, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00014: Normal(NpcDespawn, TargetCanMove, SystemTalk), id=golem_b" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SLOWFIX" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna607:67192 calling Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna607 );
