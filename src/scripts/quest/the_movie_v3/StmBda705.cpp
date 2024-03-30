// FFXIVTheMovie.ParserV3.12
// param used:
//SCENE_20 = actor5
//SCENE_28 = HAKURO
//WARP_SCENE28 = 621|555.83|162|70|1.555|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda705 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda705() : Sapphire::ScriptAPI::QuestScript( 68088 ){}; 
  ~StmBda705() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 11 entries
  //SEQ_2, 10 entries
  //SEQ_3, 13 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1021698
  //ACTOR1 = 1021719
  //ACTOR10 = 1023671
  //ACTOR11 = 1023672
  //ACTOR12 = 1022738
  //ACTOR13 = 1022739
  //ACTOR14 = 1023617
  //ACTOR15 = 1023618
  //ACTOR16 = 1023619
  //ACTOR17 = 1023620
  //ACTOR18 = 1021724
  //ACTOR19 = 1021723
  //ACTOR2 = 1021720
  //ACTOR20 = 1021725
  //ACTOR21 = 1020598
  //ACTOR22 = 1023838
  //ACTOR3 = 1021722
  //ACTOR4 = 1021721
  //ACTOR5 = 1023666
  //ACTOR6 = 1023667
  //ACTOR7 = 1023668
  //ACTOR8 = 1023669
  //ACTOR9 = 1023670
  //BINDACTOR01 = 6870707
  //BINDACTOR02 = 6925986
  //BINDACTOR03 = 6998812
  //BINDACTOR04 = 6998813
  //BINDACTOR05 = 6998814
  //BINDACTOR06 = 6998815
  //BINDACTOR07 = 6870712
  //CUTSCENEN01 = 1482
  //CUTSCENEN02 = 1614
  //EOBJECT0 = 2008285
  //ITEM0 = 2002188
  //LOCACTION01 = 4244
  //LOCACTION02 = 2
  //LOCACTION03 = 1
  //LOCACTION04 = 34
  //LOCACTOR01 = 1022007
  //LOCACTOR02 = 1022008
  //LOCACTOR03 = 1022009
  //LOCACTOR04 = 1021968
  //LOCACTOR05 = 1004753
  //LOCBGM01 = 74
  //LOCSE01 = 78
  //POPRANGE0 = 7010783
  //POPRANGE1 = 6926033
  //QUESTBATTLE0 = 167
  //TERRITORYTYPE0 = 687

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
      //seq 0 event item ITEM0 = UI8BH max stack 1
      case 0:
      {
        if( param1 == 1021698 ) // ACTOR0 = RAUBAHN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1021719 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021720 ) // ACTOR2 = URIANGER
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( param1 == 1021722 ) // ACTOR3 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00005: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind, CreateCharacterTalk), id=unknown
          }
          break;
        }
        if( param1 == 1021721 ) // ACTOR4 = ALPHINAUD
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021720 ) // ACTOR2 = URIANGER
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1021698 ) // ACTOR0 = RAUBAHN
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1023666 ) // ACTOR5 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023667 ) // ACTOR6 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023668 ) // ACTOR7 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023669 ) // ACTOR8 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023670 ) // ACTOR9 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023671 ) // ACTOR10 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023672 ) // ACTOR11 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1022738 ) // ACTOR12 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00016( quest, player ); // Scene00016: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=ALPHINAUD
            // +Callback Scene00017: Normal(CutScene, AutoFadeIn, ReturnTrue), id=unknown
          }
          break;
        }
        if( param1 == 1021722 ) // ACTOR3 = PIPIN
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 2008285 ) // EOBJECT0 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023666 ) // ACTOR5 = actor5
        {
          Scene00020( quest, player ); // Scene00020: Empty(None), id=actor5
          break;
        }
        if( param1 == 1023667 ) // ACTOR6 = unknown
        {
          Scene00021( quest, player ); // Scene00021: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023668 ) // ACTOR7 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023669 ) // ACTOR8 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023670 ) // ACTOR9 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023671 ) // ACTOR10 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023672 ) // ACTOR11 = unknown
        {
          Scene00026( quest, player ); // Scene00026: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1022739 ) // ACTOR13 = HAKURO
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove, Menu, ENpcBind), id=HAKURO
            // +Callback Scene00028: Normal(CutScene, AutoFadeIn), id=HAKURO
          }
          break;
        }
        if( param1 == 1022738 ) // ACTOR12 = ALPHINAUD
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1023617 ) // ACTOR14 = unknown
        {
          Scene00030( quest, player ); // Scene00030: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023618 ) // ACTOR15 = unknown
        {
          Scene00031( quest, player ); // Scene00031: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023619 ) // ACTOR16 = unknown
        {
          Scene00032( quest, player ); // Scene00032: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023620 ) // ACTOR17 = unknown
        {
          Scene00033( quest, player ); // Scene00033: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023666 ) // ACTOR5 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023667 ) // ACTOR6 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023668 ) // ACTOR7 = unknown
        {
          Scene00036( quest, player ); // Scene00036: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023669 ) // ACTOR8 = unknown
        {
          Scene00037( quest, player ); // Scene00037: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023670 ) // ACTOR9 = unknown
        {
          Scene00038( quest, player ); // Scene00038: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023671 ) // ACTOR10 = unknown
        {
          Scene00039( quest, player ); // Scene00039: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023672 ) // ACTOR11 = unknown
        {
          Scene00040( quest, player ); // Scene00040: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021724 ) // ACTOR18 = PIPIN
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1021723 ) // ACTOR19 = ALPHINAUD
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021725 ) // ACTOR20 = AYMERIC
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1020598 ) // ACTOR21 = LUCIA
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1023838 ) // ACTOR22 = RAUBAHN
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=RAUBAHN
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
    quest.setUI8BH( 1 );
  }
  void checkProgressSeq1( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setUI8BH( 0 );
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
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00003: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00005( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }
  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind, CreateCharacterTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00007: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00008: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00009: Empty(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00010: Empty(None), id=unknown" );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00011: Empty(None), id=unknown" );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00012: Empty(None), id=unknown" );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00013: Empty(None), id=unknown" );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00014: Empty(None), id=unknown" );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00016: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00017( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }
  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00017: Normal(CutScene, AutoFadeIn, ReturnTrue), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      //quest battle
      eventMgr().eventFinish( player, result.eventId, 1 );
      teriMgr().createAndJoinQuestBattle( player, 167 );
    };
    eventMgr().playQuestScene( player, getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00018: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00019: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00020: Empty(None), id=actor5" );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00021: Empty(None), id=unknown" );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00022: Empty(None), id=unknown" );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00023: Empty(None), id=unknown" );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00024: Empty(None), id=unknown" );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00025: Empty(None), id=unknown" );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00026: Empty(None), id=unknown" );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR13, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00027: Normal(Talk, TargetCanMove, Menu, ENpcBind), id=HAKURO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00028( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }
  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR13, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00028: Normal(CutScene, AutoFadeIn), id=HAKURO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 621 )->getGuId(), { 555.83, 162, 70 }, 1.555 );
    };
    eventMgr().playQuestScene( player, getId(), 28, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00030: Empty(None), id=unknown" );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00031: Empty(None), id=unknown" );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00032: Empty(None), id=unknown" );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00033: Empty(None), id=unknown" );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00034: Empty(None), id=unknown" );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00035: Empty(None), id=unknown" );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00036: Empty(None), id=unknown" );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00037: Empty(None), id=unknown" );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00038: Empty(None), id=unknown" );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00039: Empty(None), id=unknown" );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00040: Empty(None), id=unknown" );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00041: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 41, HIDE_HOTBAR, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00042: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00043: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, HIDE_HOTBAR, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00044: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda705:68088 calling Scene00045: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda705 );
