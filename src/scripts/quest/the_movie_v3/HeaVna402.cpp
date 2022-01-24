// FFXIVTheMovie.ParserV3.8
// param used:
//PRIVATE_SCENE1 = 0
//_ACTOR7 = B
//_ACTOR7B = 2|2
//_ACTOR8 = B
//_ACTOR8B = 2|2
//_ACTOR9 = B
//_ACTOR9B = 2|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna402 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna402() : Sapphire::ScriptAPI::QuestScript( 67174 ){}; 
  ~HeaVna402() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 4 entries
  //SEQ_2, 5 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1012751
  //ACTOR1 = 1012753
  //ACTOR10 = 1013332
  //ACTOR11 = 1013333
  //ACTOR2 = 1012754
  //ACTOR3 = 1012755
  //ACTOR4 = 1012752
  //ACTOR5 = 1013381
  //ACTOR6 = 1013128
  //ACTOR7 = 1013340
  //ACTOR8 = 1013341
  //ACTOR9 = 1013342
  //LOCACTOR0 = 5864612
  //LOCACTOR1 = 5864600
  //LOCACTOR2 = 5864601
  //LOCACTOR3 = 5864602
  //LOCACTOR4 = 5859640
  //LOCMUSIC0 = 317
  //POPRANGE0 = 5827750

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
        if( param1 == 1012751 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1012753 ) // ACTOR1 = LUCIA
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1012754 ) // ACTOR2 = HAURCHEFANT
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=HAURCHEFANT
          break;
        }
        if( param1 == 1012755 ) // ACTOR3 = EDMONT
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=EDMONT
          break;
        }
        if( param1 == 1012752 ) // ACTOR4 = ESTINIEN
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1013381 ) // ACTOR5 = TATARU
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=TATARU
          }
          break;
        }
        if( param1 == 1013128 ) // ACTOR6 = ALPHINAUD
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012754 ) // ACTOR2 = HAURCHEFANT
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=HAURCHEFANT
          break;
        }
        if( param1 == 1012755 ) // ACTOR3 = EDMONT
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=EDMONT
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1013340 ) // ACTOR7 = THEPOORA01638, CB=2
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=THEPOORA01638
          }
          else
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=THEPOORA01638
          }
          break;
        }
        if( param1 == 1013341 ) // ACTOR8 = THEPOORB01638, CB=2
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=THEPOORB01638
          }
          else
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=THEPOORB01638
          }
          break;
        }
        if( param1 == 1013342 ) // ACTOR9 = THEPOORC01638, CB=2
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=THEPOORC01638
          }
          else
          {
            Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=THEPOORC01638
          }
          break;
        }
        if( param1 == 1013332 ) // ACTOR10 = ALPHINAUD
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013333 ) // ACTOR11 = TATARU
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1013332 ) // ACTOR10 = ALPHINAUD
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013340 ) // ACTOR7 = THEPOORA01638
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=THEPOORA01638
          break;
        }
        if( param1 == 1013341 ) // ACTOR8 = THEPOORB01638
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=THEPOORB01638
          break;
        }
        if( param1 == 1013342 ) // ACTOR9 = THEPOORC01638
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=THEPOORC01638
          break;
        }
        if( param1 == 1013333 ) // ACTOR11 = TATARU
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=TATARU
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
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.exitInstance();
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00002: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00003: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00004: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00008: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00009: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, UI8AL = 3, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00010: Normal(Talk, TargetCanMove), id=THEPOORA01638" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }
  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, UI8AL = 3, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00011: Normal(Talk, TargetCanMove), id=THEPOORA01638" );
    eventMgr().playQuestScene( player, getId(), 11, NONE, nullptr );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, UI8AL = 3, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00012: Normal(Talk, TargetCanMove), id=THEPOORB01638" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }
  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, UI8AL = 3, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00013: Normal(Talk, TargetCanMove), id=THEPOORB01638" );
    eventMgr().playQuestScene( player, getId(), 13, NONE, nullptr );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, UI8AL = 3, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00014: Normal(Talk, TargetCanMove), id=THEPOORC01638" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }
  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, UI8AL = 3, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00015: Normal(Talk, TargetCanMove), id=THEPOORC01638" );
    eventMgr().playQuestScene( player, getId(), 15, NONE, nullptr );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00017: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00019: Normal(Talk, TargetCanMove), id=THEPOORA01638" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00020: Normal(Talk, TargetCanMove), id=THEPOORB01638" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00021: Normal(Talk, TargetCanMove), id=THEPOORC01638" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna402:67174 calling Scene00022: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna402 );
