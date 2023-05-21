// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda133 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda133() : Sapphire::ScriptAPI::QuestScript( 67999 ){}; 
  ~StmBda133() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 7 entries
  //SEQ_2, 1 entries
  //SEQ_255, 23 entries

  //ACTOR0 = 1020354
  //ACTOR1 = 1020525
  //ACTOR10 = 1020411
  //ACTOR11 = 1020190
  //ACTOR12 = 1020412
  //ACTOR13 = 1020419
  //ACTOR14 = 1020414
  //ACTOR15 = 1020415
  //ACTOR16 = 1020417
  //ACTOR17 = 1020420
  //ACTOR18 = 1020416
  //ACTOR19 = 1019965
  //ACTOR2 = 1020526
  //ACTOR20 = 1019471
  //ACTOR21 = 1019472
  //ACTOR22 = 1019476
  //ACTOR23 = 1019477
  //ACTOR24 = 1019479
  //ACTOR25 = 1019481
  //ACTOR26 = 1019483
  //ACTOR27 = 1019484
  //ACTOR28 = 1019486
  //ACTOR29 = 1019488
  //ACTOR3 = 1020392
  //ACTOR30 = 1019489
  //ACTOR31 = 1019490
  //ACTOR4 = 1020393
  //ACTOR5 = 1020399
  //ACTOR6 = 1020397
  //ACTOR7 = 1020398
  //ACTOR8 = 1020304
  //ACTOR9 = 1020400
  //BGMSWITCHREWARD = 371
  //BINDACTOR01 = 6844562
  //BINDACTOR02 = 6844563
  //CUTSCENEN01 = 1391
  //CUTSCENEN02 = 1392
  //CUTSCENEN03 = 1393
  //CUTSCENEN04 = 1395
  //CUTSCENEN05 = 1396
  //EOBJECT0 = 2008179
  //QUESTBATTLE0 = 155
  //TERRITORYTYPE0 = 659
  //TERRITORYTYPE1 = 635

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
        if( param1 == 1020354 ) // ACTOR0 = PIPIN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=PIPIN
          }
          break;
        }
        if( param1 == 1020525 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020526 ) // ACTOR2 = ALISAIE
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020392 ) // ACTOR3 = SERPENTOFFICER
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020393 ) // ACTOR4 = STORMOFFICER
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020399 ) // ACTOR5 = PIPIN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, SystemTalk, CanCancel), id=PIPIN
            // +Callback Scene00007: Normal(CutScene, AutoFadeIn, ReturnTrue), id=unknown
          }
          break;
        }
        if( param1 == 1020397 ) // ACTOR6 = ALPHINAUD
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020398 ) // ACTOR7 = ALISAIE
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020304 ) // ACTOR8 = RAUBAHN
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020392 ) // ACTOR3 = SERPENTOFFICER
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020393 ) // ACTOR4 = STORMOFFICER
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 2008179 ) // EOBJECT0 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00014( quest, player ); // Scene00014: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020400 ) // ACTOR9 = RAUBAHN
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020411 ) // ACTOR10 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1020190 ) // ACTOR11 = WISCAR
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1020412 ) // ACTOR12 = ALPHINAUD
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020419 ) // ACTOR13 = ALISAIE
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020414 ) // ACTOR14 = LYSE
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020415 ) // ACTOR15 = unknown
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1020417 ) // ACTOR16 = KRILE
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1020420 ) // ACTOR17 = PIPIN
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020416 ) // ACTOR18 = CONRAD
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1019965 ) // ACTOR19 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019471 ) // ACTOR20 = TEBBE
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=TEBBE
          break;
        }
        if( param1 == 1019472 ) // ACTOR21 = CARMA
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=CARMA
          break;
        }
        if( param1 == 1019476 ) // ACTOR22 = AHELISSA
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=AHELISSA
          break;
        }
        if( param1 == 1019477 ) // ACTOR23 = RANULF
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=RANULF
          break;
        }
        if( param1 == 1019479 ) // ACTOR24 = ORTWIN
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=ORTWIN
          break;
        }
        if( param1 == 1019481 ) // ACTOR25 = MATHILD
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=MATHILD
          break;
        }
        if( param1 == 1019483 ) // ACTOR26 = ODILA
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=ODILA
          break;
        }
        if( param1 == 1019484 ) // ACTOR27 = DHANNA
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=DHANNA
          break;
        }
        if( param1 == 1019486 ) // ACTOR28 = ORELLA
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=ORELLA
          break;
        }
        if( param1 == 1019488 ) // ACTOR29 = EMMET
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=EMMET
          break;
        }
        if( param1 == 1019489 ) // ACTOR30 = BERINHARD
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=BERINHARD
          break;
        }
        if( param1 == 1019490 ) // ACTOR31 = HUGHOC
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=HUGHOC
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
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00005: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00006: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, SystemTalk, CanCancel), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00007( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }
  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00007: Normal(CutScene, AutoFadeIn, ReturnTrue), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      //quest battle
      eventMgr().eventFinish( player, result.eventId, 1 );
      teriMgr().createAndJoinQuestBattle( player, 155 );
    };
    eventMgr().playQuestScene( player, getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00010: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00011: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00012: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00013: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00014: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00016: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00017: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00020: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00021: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00022: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00023: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00024: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00025: Empty(None), id=unknown" );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00026: Normal(Talk, TargetCanMove), id=TEBBE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00027: Normal(Talk, TargetCanMove), id=CARMA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00028: Normal(Talk, TargetCanMove), id=AHELISSA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00029: Normal(Talk, TargetCanMove), id=RANULF" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00030: Normal(Talk, TargetCanMove), id=ORTWIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR25, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00031: Normal(Talk, TargetCanMove), id=MATHILD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR26, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00032: Normal(Talk, TargetCanMove), id=ODILA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR27, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00033: Normal(Talk, TargetCanMove), id=DHANNA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR28, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00034: Normal(Talk, TargetCanMove), id=ORELLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR29, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00035: Normal(Talk, TargetCanMove), id=EMMET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, HIDE_HOTBAR, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR30, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00036: Normal(Talk, TargetCanMove), id=BERINHARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR31, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda133:67999 calling Scene00037: Normal(Talk, TargetCanMove), id=HUGHOC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda133 );
