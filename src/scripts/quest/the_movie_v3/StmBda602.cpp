// FFXIVTheMovie.ParserV3.12
// param used:
//WARP_SCENE29 = 612|-94.6|50|189.46|2.67|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda602 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda602() : Sapphire::ScriptAPI::QuestScript( 68064 ){}; 
  ~StmBda602() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 4 entries
  //SEQ_2, 4 entries
  //SEQ_3, 1 entries
  //SEQ_4, 9 entries
  //SEQ_5, 1 entries
  //SEQ_255, 8 entries

  //ACTOR0 = 1020304
  //ACTOR1 = 1020354
  //ACTOR10 = 1020390
  //ACTOR11 = 1020391
  //ACTOR12 = 1023298
  //ACTOR13 = 1023762
  //ACTOR14 = 1023763
  //ACTOR15 = 1020559
  //ACTOR16 = 1020560
  //ACTOR17 = 1020561
  //ACTOR18 = 1020562
  //ACTOR19 = 1020565
  //ACTOR2 = 1020392
  //ACTOR20 = 1020563
  //ACTOR21 = 1020564
  //ACTOR22 = 1020566
  //ACTOR23 = 1020567
  //ACTOR24 = 1020568
  //ACTOR25 = 1020569
  //ACTOR26 = 1020572
  //ACTOR27 = 1022087
  //ACTOR28 = 1022088
  //ACTOR29 = 1020570
  //ACTOR3 = 1020393
  //ACTOR30 = 1020571
  //ACTOR4 = 1020205
  //ACTOR5 = 1020206
  //ACTOR6 = 1020432
  //ACTOR7 = 1020554
  //ACTOR8 = 1019466
  //ACTOR9 = 1020334
  //BINDACTOR01 = 6829445
  //BINDACTOR02 = 6841685
  //BINDACTOR03 = 6841686
  //CUTSCENEN01 = 1461
  //CUTSCENEN02 = 1462
  //CUTSCENEN03 = 1463
  //EOBJECT0 = 2008197
  //LOCACTOR01 = 1018318
  //LOCACTOR02 = 1019082
  //LOCACTOR03 = 1011887
  //LOCACTOR04 = 1017687
  //LOCACTOR05 = 1018509
  //LOCACTOR06 = 1019537
  //LOCBGM01 = 485
  //LOCBGM02 = 459
  //POPRANGE0 = 7021074
  //QUESTBATTLE0 = 160
  //TERRITORYTYPE0 = 671
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
            Scene00000( quest, player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=RAUBAHN
            // +Callback Scene00001: Normal(CutScene, AutoFadeIn), id=unknown
            // +Callback Scene00002: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, CreateCharacterTalk), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1020354 ) // ACTOR1 = PIPIN
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020392 ) // ACTOR2 = SERPENTOFFICER
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020393 ) // ACTOR3 = STORMOFFICER
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1020205 ) // ACTOR4 = ALPHINAUD
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020206 ) // ACTOR5 = ALISAIE
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020432 ) // ACTOR6 = LYSE
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020554 ) // ACTOR7 = ARENVALD
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019466 ) // ACTOR8 = CONRAD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=CONRAD
          }
          break;
        }
        if( param1 == 1020334 ) // ACTOR9 = LYSE
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020390 ) // ACTOR10 = MNAAGO
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020391 ) // ACTOR11 = ARENVALD
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1023298 ) // ACTOR12 = BURLYPRIVATE02638
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00014( quest, player ); // Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=BURLYPRIVATE02638
          }
          break;
        }
        if( param1 == 1023762 ) // ACTOR13 = ALAMHIGAN02528
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00015( quest, player ); // Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=ALAMHIGAN02528
          }
          break;
        }
        if( param1 == 1023763 ) // ACTOR14 = STRAPPINGLAD02528
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00016( quest, player ); // Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=STRAPPINGLAD02528
          }
          break;
        }
        if( param1 == 1019466 ) // ACTOR8 = CONRAD
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        break;
      }
      case 3:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00018( quest, player ); // Scene00018: Normal(Talk, FadeIn, TargetCanMove, Menu), id=CONRAD
        break;
      }
      case 4:
      {
        if( param1 == 1020559 ) // ACTOR15 = CONRAD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00019( quest, player ); // Scene00019: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=CONRAD
          }
          break;
        }
        if( param1 == 2008197 ) // EOBJECT0 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Normal(CutScene, AutoFadeIn, ReturnTrue), id=unknown
          break;
        }
        if( param1 == 1020560 ) // ACTOR16 = LYSE
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020561 ) // ACTOR17 = MNAAGO
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020562 ) // ACTOR18 = ARENVALD
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1020565 ) // ACTOR19 = ANANTASOLDIER
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=ANANTASOLDIER
          break;
        }
        if( param1 == 1020563 ) // ACTOR20 = unknown
        {
          Scene00026( quest, player ); // Scene00026: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020564 ) // ACTOR21 = unknown
        {
          Scene00027( quest, player ); // Scene00027: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020566 ) // ACTOR22 = unknown
        {
          Scene00028( quest, player ); // Scene00028: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00029( quest, player ); // Scene00029: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020567 ) // ACTOR23 = LYSE
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020568 ) // ACTOR24 = CONRAD
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020569 ) // ACTOR25 = ARENVALD
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1020572 ) // ACTOR26 = ANANTASOLDIER
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=ANANTASOLDIER
          break;
        }
        if( param1 == 1022087 ) // ACTOR27 = MNAAGO
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022088 ) // ACTOR28 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020570 ) // ACTOR29 = unknown
        {
          Scene00036( quest, player ); // Scene00036: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020571 ) // ACTOR30 = unknown
        {
          Scene00037( quest, player ); // Scene00037: Empty(None), id=unknown
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
    if( quest.getUI8BL() == 1 )
      if( quest.getUI8AL() == 1 )
        if( quest.getUI8BH() == 1 )
        {
          quest.setUI8BL( 0 );
          quest.setUI8AL( 0 );
          quest.setUI8BH( 0 );
          quest.setBitFlag8( 1, false );
          quest.setBitFlag8( 2, false );
          quest.setBitFlag8( 3, false );
          quest.setSeq( 3 );
        }
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 4 );
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 5 );
    }
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=RAUBAHN" );
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
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00001: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00002( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, CreateCharacterTalk), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI | INVIS_ENPC, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00003: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00005: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00008: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00009: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00010: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00011: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00012: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00013: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, UI8BL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=BURLYPRIVATE02638" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=ALAMHIGAN02528" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR14, UI8BH = 1, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=STRAPPINGLAD02528" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00017: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00018: Normal(Talk, FadeIn, TargetCanMove, Menu), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        checkProgressSeq3( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR15, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00019: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        //quest battle
        eventMgr().eventFinish( player, result.eventId, 1 );
        teriMgr().createAndJoinQuestBattle( player, 160 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00020: Normal(CutScene, AutoFadeIn, ReturnTrue), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00022: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00023: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00024: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00025: Normal(Talk, TargetCanMove), id=ANANTASOLDIER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00026: Empty(None), id=unknown" );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00027: Empty(None), id=unknown" );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00028: Empty(None), id=unknown" );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_5: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00029: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq5( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 612 )->getGuId(), { -94.6, 50, 189.46 }, 2.67 );
    };
    eventMgr().playQuestScene( player, getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00031: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR25, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00032: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR26, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00033: Normal(Talk, TargetCanMove), id=ANANTASOLDIER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR27, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00034: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR28, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00035: Empty(None), id=unknown" );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR29, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00036: Empty(None), id=unknown" );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR30, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda602:68064 calling Scene00037: Empty(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda602 );
