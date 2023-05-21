// FFXIVTheMovie.ParserV3.11
// param used:
//WARP_SCENE18 = 612|-660|130|-533.333|0.96|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda101 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda101() : Sapphire::ScriptAPI::QuestScript( 67982 ){}; 
  ~StmBda101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 9 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_4, 2 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1018330
  //ACTOR1 = 1020284
  //ACTOR10 = 1020300
  //ACTOR11 = 1018329
  //ACTOR12 = 1012813
  //ACTOR13 = 1020301
  //ACTOR14 = 1020302
  //ACTOR15 = 1020303
  //ACTOR16 = 1020304
  //ACTOR17 = 1020525
  //ACTOR18 = 1020526
  //ACTOR19 = 1020527
  //ACTOR2 = 1020285
  //ACTOR20 = 1020308
  //ACTOR21 = 1020495
  //ACTOR3 = 1020286
  //ACTOR4 = 1020287
  //ACTOR5 = 1020288
  //ACTOR6 = 1020289
  //ACTOR7 = 1020290
  //ACTOR8 = 1020291
  //ACTOR9 = 1020518
  //CUTSCENEN01 = 1379
  //CUTSCENEN02 = 1380
  //CUTSCENEN03 = 1381
  //LOCACTION01 = 112
  //LOCACTION02 = 113
  //LOCACTION03 = 114
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1017687
  //LOCACTOR03 = 1018384
  //LOCACTOR04 = 1018509
  //LOCACTOR05 = 1011889
  //LOCACTOR06 = 1015833
  //LOCACTOR07 = 1015903
  //LOCACTOR08 = 1011900
  //LOCACTOR09 = 1011891
  //LOCBGM01 = 77
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //LOCIDLE03 = 34
  //LOCSE01 = 78
  //POPRANGE0 = 6829336
  //POPRANGE1 = 6829350
  //POPRANGE2 = 6843192
  //TERRITORYTYPE0 = 612

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(CutScene, QuestAccept, AutoFadeIn), id=unknown
        // +Callback Scene00002: Normal(CutScene, AutoFadeIn), id=unknown
        break;
      }
      case 1:
      {
        if( param1 == 1020284 ) // ACTOR1 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00003( quest, player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020285 ) // ACTOR2 = ALISAIE
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020286 ) // ACTOR3 = LYSE
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020287 ) // ACTOR4 = YSHTOLA
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1020288 ) // ACTOR5 = KRILE
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1020289 ) // ACTOR6 = YUGIRI
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020290 ) // ACTOR7 = GOSETSU
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020291 ) // ACTOR8 = TATARU
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1020518 ) // ACTOR9 = RIOL
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=RIOL
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020300 ) // ACTOR10 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1018329 ) // ACTOR11 = YSHTOLA
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012813 ) // ACTOR12 = KRILE
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1020301 ) // ACTOR13 = ALISAIE
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020302 ) // ACTOR14 = LYSE
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020303 ) // ACTOR15 = SERPENTOFFICER
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020303 ) // ACTOR15 = SERPENTOFFICER
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00018( quest, player ); // Scene00018: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=SERPENTOFFICER
          }
          break;
        }
        if( param1 == 1018329 ) // ACTOR11 = YSHTOLA
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012813 ) // ACTOR12 = KRILE
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1020301 ) // ACTOR13 = ALISAIE
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020302 ) // ACTOR14 = LYSE
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020300 ) // ACTOR10 = ALPHINAUD
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 4:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00024( quest, player ); // Scene00024: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1020303 ) // ACTOR15 = SERPENTOFFICER
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=SERPENTOFFICER
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020304 ) // ACTOR16 = RAUBAHN
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020525 ) // ACTOR17 = ALPHINAUD
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020526 ) // ACTOR18 = ALISAIE
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020527 ) // ACTOR19 = LYSE
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020308 ) // ACTOR20 = KRILE
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1020303 ) // ACTOR15 = SERPENTOFFICER
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020495 ) // ACTOR21 = YSHTOLA
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=YSHTOLA
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
      quest.setSeq( 4 );
    }
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00001: Normal(CutScene, QuestAccept, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00002( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00002: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=ALPHINAUD" );
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
    eventMgr().playQuestScene( player, getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00005: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00007: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00009: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00010: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00011: Normal(Talk, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00014: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00016: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00017: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR15, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00018: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 1, true );
        eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
        checkProgressSeq3( quest, player );
        eventMgr().eventFinish( player, result.eventId, 1 );
        warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 612 )->getGuId(), { -660, 130, -533.333 }, 0.96 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00019: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00020: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00022: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_4: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00024: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00025: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
      }
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00026: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00029: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00030: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00031: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
      }
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda101:67982 calling Scene00032: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda101 );
