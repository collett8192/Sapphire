// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda602 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda602() : Sapphire::ScriptAPI::EventScript( 68064 ){}; 
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

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020304 || param2 == 1020304 ) // ACTOR0 = RAUBAHN
        {
          Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=RAUBAHN
          // +Callback Scene00001: Normal(CutScene, AutoFadeIn), id=unknown
          // +Callback Scene00002: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=RAUBAHN
          break;
        }
        if( param1 == 1020354 || param2 == 1020354 ) // ACTOR1 = PIPIN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020392 || param2 == 1020392 ) // ACTOR2 = SERPENTOFFICER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020393 || param2 == 1020393 ) // ACTOR3 = STORMOFFICER
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1020205 || param2 == 1020205 ) // ACTOR4 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020206 || param2 == 1020206 ) // ACTOR5 = ALISAIE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020432 || param2 == 1020432 ) // ACTOR6 = LYSE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020554 || param2 == 1020554 ) // ACTOR7 = ARENVALD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019466 || param2 == 1019466 ) // ACTOR8 = CONRAD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, FadeIn, TargetCanMove), id=CONRAD
          }
          break;
        }
        if( param1 == 1020334 || param2 == 1020334 ) // ACTOR9 = LYSE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020390 || param2 == 1020390 ) // ACTOR10 = MNAAGO
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020391 || param2 == 1020391 ) // ACTOR11 = ARENVALD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1023298 || param2 == 1023298 ) // ACTOR12 = BURLYPRIVATE02638
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=BURLYPRIVATE02638
          }
          break;
        }
        if( param1 == 1023762 || param2 == 1023762 ) // ACTOR13 = ALAMHIGAN02528
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=ALAMHIGAN02528
          }
          break;
        }
        if( param1 == 1023763 || param2 == 1023763 ) // ACTOR14 = STRAPPINGLAD02528
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=STRAPPINGLAD02528
          }
          break;
        }
        if( param1 == 1019466 || param2 == 1019466 ) // ACTOR8 = CONRAD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        break;
      }
      case 3:
      {
        Scene00018( player ); // Scene00018: Normal(Talk, FadeIn, TargetCanMove, Menu), id=CONRAD
        break;
        break;
      }
      case 4:
      {
        if( param1 == 1020559 || param2 == 1020559 ) // ACTOR15 = CONRAD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=CONRAD
          }
          break;
        }
        if( param1 == 2008197 || param2 == 2008197 ) // EOBJECT0 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1020560 || param2 == 1020560 ) // ACTOR16 = LYSE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020561 || param2 == 1020561 ) // ACTOR17 = MNAAGO
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020562 || param2 == 1020562 ) // ACTOR18 = ARENVALD
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1020565 || param2 == 1020565 ) // ACTOR19 = ANANTASOLDIER
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ANANTASOLDIER
          break;
        }
        if( param1 == 1020563 || param2 == 1020563 ) // ACTOR20 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020564 || param2 == 1020564 ) // ACTOR21 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020566 || param2 == 1020566 ) // ACTOR22 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00029( player ); // Scene00029: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020567 || param2 == 1020567 ) // ACTOR23 = LYSE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020568 || param2 == 1020568 ) // ACTOR24 = CONRAD
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020569 || param2 == 1020569 ) // ACTOR25 = ARENVALD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1020572 || param2 == 1020572 ) // ACTOR26 = ANANTASOLDIER
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=ANANTASOLDIER
          break;
        }
        if( param1 == 1022087 || param2 == 1022087 ) // ACTOR27 = MNAAGO
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022088 || param2 == 1022088 ) // ACTOR28 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020570 || param2 == 1020570 ) // ACTOR29 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020571 || param2 == 1020571 ) // ACTOR30 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        break;
      }
      default:
      {
        player.sendUrgent( "Sequence {} not defined.", player.getQuestSeq( getId() ) );
        break;
      }
    }
  }

public:
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    onProgress( player, actorId, actor, 0, 0 );
  }

  void onEmote( uint64_t actorId, uint32_t eventId, uint32_t emoteId, Entity::Player& player ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    onProgress( player, actorId, actor, 1, emoteId );
  }

  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
  {
    onProgress( player, npcId, 0, 2, 0 );
  }

  void onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( player, param1, param1, 3, 0 );
  }

  void onEnterTerritory( Sapphire::Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2 ) override
  {
    onProgress( player, param1, param2, 4, 0 );
  }

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 3 );
        }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00001: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00003: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00005: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00008: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00009: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00010: Normal(Talk, FadeIn, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00011: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00012: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00013: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=BURLYPRIVATE02638" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=ALAMHIGAN02528" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=STRAPPINGLAD02528" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00017: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00018: Normal(Talk, FadeIn, TargetCanMove, Menu), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00019: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq4( player );
        //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
        //player.eventFinish( getId(), 1 );
        //player.forceZoneing();
        Scene00029( player );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00020: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00022: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00023: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00024: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00025: Normal(Talk, TargetCanMove), id=ANANTASOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00029: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00031: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00032: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00033: Normal(Talk, TargetCanMove), id=ANANTASOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00034: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda602:68064 calling Scene00037: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda602 );
