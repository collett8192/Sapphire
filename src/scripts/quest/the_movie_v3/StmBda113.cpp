// FFXIVTheMovie.ParserV3.11
// param used:
//ACTOR3 = RAUBAHN
//ACTOR4 = ALISAIE
//SCENE_13 = RAUBAHN
//SCENE_19 = dummyt
//SCENE_20 = dummyt
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda113 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda113() : Sapphire::ScriptAPI::QuestScript( 67989 ){}; 
  ~StmBda113() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 5 entries
  //SEQ_2, 6 entries
  //SEQ_3, 1 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1020304
  //ACTOR1 = 1020355
  //ACTOR2 = 1020354
  //ACTOR3 = 1020503
  //ACTOR4 = 1020502
  //ACTOR5 = 1020504
  //ACTOR6 = 1020505
  //ACTOR7 = 1020361
  //ACTOR8 = 1020358
  //BINDACTOR01 = 6829573
  //BINDACTOR02 = 6829576
  //CUTSCENEN01 = 1386
  //CUTSCENEN02 = 1387
  //ENEMY0 = 7021908
  //ENEMY1 = 7021909
  //EOBJECT0 = 2007955
  //EOBJECT1 = 2007956
  //EVENTACTION0 = 50
  //EVENTACTION1 = 1
  //LOCACTOR01 = 1017687
  //LOCACTOR02 = 1022485
  //LOCACTOR03 = 1018318
  //LOCACTOR04 = 1019082
  //LOCACTOR05 = 1019700
  //LOCACTOR06 = 1019701
  //LOCACTOR07 = 1019702
  //LOCACTOR08 = 1019703
  //LOCIDLE01 = 4295
  //QUESTBATTLE0 = 159
  //TERRITORYTYPE0 = 670
  //TERRITORYTYPE1 = 612

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
        if( param1 == 1020304 ) // ACTOR0 = RAUBAHN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1020355 ) // ACTOR1 = ALISAIE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020354 ) // ACTOR2 = PIPIN
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2007955 ) // EOBJECT0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT0
        if( param1 == 7021908 ) // ENEMY0 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7021909 ) // ENEMY1 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1020354 ) // ACTOR2 = PIPIN
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020304 ) // ACTOR0 = RAUBAHN
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020503 ) // ACTOR3 = RAUBAHN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00012( quest, player ); // Scene00012: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=RAUBAHN
            // +Callback Scene00013: Normal(CutScene, AutoFadeIn, ReturnTrue), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1020502 ) // ACTOR4 = ALISAIE
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020504 ) // ACTOR5 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020505 ) // ACTOR6 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Empty(None), id=unknown
          break;
        }
        if( param1 == 2007956 ) // EOBJECT1 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020354 ) // ACTOR2 = PIPIN
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        break;
      }
      case 3:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = dummyt
        {
          Scene00019( quest, player ); // Scene00019: Normal(CutScene, AutoFadeIn), id=dummyt
          // +Callback Scene00020: Normal(Talk, FadeIn, Dismount), id=dummyt
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020361 ) // ACTOR7 = MNAAGO
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020358 ) // ACTOR8 = ALISAIE
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020354 ) // ACTOR2 = PIPIN
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020304 ) // ACTOR0 = RAUBAHN
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=RAUBAHN
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
    if( quest.getUI8AL() == 2 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 2 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 3 );
    }
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00003: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 2, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 2 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 2 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00010: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00011: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00012: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00013( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }
  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00013: Normal(CutScene, AutoFadeIn, ReturnTrue), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      //quest battle
      eventMgr().eventFinish( player, result.eventId, 1 );
      teriMgr().createAndJoinQuestBattle( player, 159 );
    };
    eventMgr().playQuestScene( player, getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00016: Empty(None), id=unknown" );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00017: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00018: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00019: Normal(CutScene, AutoFadeIn), id=dummyt" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00020( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00020: Normal(Talk, FadeIn, Dismount), id=dummyt" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00023: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda113:67989 calling Scene00024: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda113 );
