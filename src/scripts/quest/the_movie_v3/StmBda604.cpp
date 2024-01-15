// FFXIVTheMovie.ParserV3.12
// param used:
//WARP_RESISTANCEGATEGUARD = 612|-65.76|56|217|1.08|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda604 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda604() : Sapphire::ScriptAPI::QuestScript( 68066 ){}; 
  ~StmBda604() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 2 entries
  //SEQ_2, 14 entries
  //SEQ_255, 15 entries

  //ACTOR0 = 1020568
  //ACTOR1 = 1020573
  //ACTOR10 = 1022322
  //ACTOR11 = 1022323
  //ACTOR12 = 1022324
  //ACTOR13 = 1022325
  //ACTOR14 = 1022326
  //ACTOR15 = 1020620
  //ACTOR16 = 1020621
  //ACTOR17 = 1020578
  //ACTOR18 = 1020579
  //ACTOR19 = 1022363
  //ACTOR2 = 1022089
  //ACTOR20 = 1022364
  //ACTOR3 = 1022090
  //ACTOR4 = 1020567
  //ACTOR5 = 1022327
  //ACTOR6 = 1022328
  //ACTOR7 = 1022329
  //ACTOR8 = 1022330
  //ACTOR9 = 1022331
  //BINDACTOR01 = 6912876
  //BINDACTOR02 = 6912877
  //CUTSCENEN01 = 1464
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019541
  //LOCACTOR03 = 1018509
  //LOCACTOR04 = 1021982
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //POPRANGE0 = 7021955
  //POPRANGE1 = 6865939
  //POPRANGE2 = 6853889
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
        if( param1 == 1020568 ) // ACTOR0 = CONRAD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, AutoFadeIn, CreateCharacterTalk), id=CONRAD
          }
          break;
        }
        if( param1 == 1020573 ) // ACTOR1 = RESISTANCEGATEGUARD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD
          break;
        }
        if( param1 == 1022089 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1022090 ) // ACTOR3 = ALISAIE
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020567 ) // ACTOR4 = LYSE
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020573 ) // ACTOR1 = RESISTANCEGATEGUARD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD
          }
          break;
        }
        if( param1 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1022327 ) // ACTOR5 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove, ENpcBind), id=LYSE
          }
          break;
        }
        if( param1 == 1020573 ) // ACTOR1 = RESISTANCEGATEGUARD
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD
          break;
        }
        if( param1 == 1022328 ) // ACTOR6 = PIPIN
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1022329 ) // ACTOR7 = ARENVALD
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022330 ) // ACTOR8 = VMAHTIA
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022331 ) // ACTOR9 = JMOLDVA
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1022322 ) // ACTOR10 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022323 ) // ACTOR11 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022324 ) // ACTOR12 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022325 ) // ACTOR13 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022326 ) // ACTOR14 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020620 ) // ACTOR15 = ALPHINAUD
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020621 ) // ACTOR16 = ALISAIE
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020578 ) // ACTOR17 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Normal(CutScene, AutoFadeIn), id=unknown
          // +Callback Scene00023: Normal(FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1020573 ) // ACTOR1 = RESISTANCEGATEGUARD
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD
          break;
        }
        if( param1 == 1022322 ) // ACTOR10 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022323 ) // ACTOR11 = unknown
        {
          Scene00026( quest, player ); // Scene00026: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022324 ) // ACTOR12 = unknown
        {
          Scene00027( quest, player ); // Scene00027: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022325 ) // ACTOR13 = unknown
        {
          Scene00028( quest, player ); // Scene00028: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022326 ) // ACTOR14 = unknown
        {
          Scene00029( quest, player ); // Scene00029: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1022328 ) // ACTOR6 = PIPIN
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1022329 ) // ACTOR7 = ARENVALD
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022330 ) // ACTOR8 = VMAHTIA
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022331 ) // ACTOR9 = JMOLDVA
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1020579 ) // ACTOR18 = LYSE
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1022363 ) // ACTOR19 = ALPHINAUD
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1022364 ) // ACTOR20 = ALISAIE
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=ALISAIE
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
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, AutoFadeIn, CreateCharacterTalk), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI | INVIS_ENPC, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00002: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 612 )->getGuId(), { -65.76, 56, 217 }, 1.08 );
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00005: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 1, true );
        eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
        checkProgressSeq1( quest, player );
        eventMgr().eventFinish( player, result.eventId, 1 );
        warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 612 )->getGuId(), { -65.76, 56, 217 }, 1.08 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00007: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00008: Normal(Talk, TargetCanMove, ENpcBind), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00009: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 612 )->getGuId(), { -65.76, 56, 217 }, 1.08 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00010: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00011: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00012: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00013: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00014: Empty(None), id=unknown" );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00016: Empty(None), id=unknown" );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00017: Empty(None), id=unknown" );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00018: Empty(None), id=unknown" );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00019: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00022: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00023( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00023: Normal(FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
        playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
        eventMgr().eventFinish( player, result.eventId, 1 );
        warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
      }
    };
    eventMgr().playQuestScene( player, getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00024: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 612 )->getGuId(), { -65.76, 56, 217 }, 1.08 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00025: Empty(None), id=unknown" );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00026: Empty(None), id=unknown" );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00027: Empty(None), id=unknown" );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00028: Empty(None), id=unknown" );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00029: Empty(None), id=unknown" );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00030: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00031: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00032: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00033: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00034: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00035: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, HIDE_HOTBAR, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda604:68066 calling Scene00037: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda604 );
