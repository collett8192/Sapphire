// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdd105 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdd105() : Sapphire::ScriptAPI::EventScript( 68610 ){}; 
  ~StmBdd105() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 6 entries
  //SEQ_2, 2 entries
  //SEQ_3, 1 entries
  //SEQ_4, 2 entries
  //SEQ_5, 4 entries
  //SEQ_6, 4 entries
  //SEQ_7, 4 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1024999
  //ACTOR1 = 1024998
  //ACTOR10 = 1025574
  //ACTOR11 = 5010000
  //ACTOR12 = 1025528
  //ACTOR13 = 1025529
  //ACTOR14 = 1025530
  //ACTOR15 = 1025538
  //ACTOR16 = 1025541
  //ACTOR17 = 1025539
  //ACTOR18 = 1025540
  //ACTOR19 = 1025597
  //ACTOR2 = 1025009
  //ACTOR20 = 1024974
  //ACTOR3 = 1025545
  //ACTOR4 = 1025354
  //ACTOR5 = 1025523
  //ACTOR6 = 1025524
  //ACTOR7 = 1025525
  //ACTOR8 = 1025575
  //ACTOR9 = 1025576
  //INSTANCEDUNGEON0 = 20055
  //LOCBGM01 = 459
  //LOCENPCALISAIE01 = 1019541
  //LOCFACE01 = 6216
  //LOCLEVELALIDOMA = 7348673
  //LOCLEVELALIKAWA = 7348609
  //LOCLEVELALIKIENKAN = 7227017
  //LOCLEVELALPHKAWA = 7348605
  //LOCLEVELALPHKIENKAN = 7227009
  //LOCLEVELHIENKAWA = 7343505
  //LOCLEVELRASYOKAWA = 7343509
  //LOCLEVELYUUDOMA = 7348679
  //LOCLEVELYUUFUL = 7394052
  //LOCLEVELYUUKAWA = 7348610
  //LOCLEVELYUUKIENKAN = 7343652
  //LOCSCREENIMAGE0 = 600
  //NCUT01 = 1700
  //NCUT02 = 1701
  //NCUT03 = 1702
  //NCUT04 = 1703
  //NCUT05 = 1704
  //POPRANGE0 = 7226900
  //POPRANGE1 = 7394018
  //POPRANGE2 = 7394348
  //POPRANGE3 = 7394351
  //POPRANGE4 = 7348680
  //TERRITORYTYPE0 = 744
  //TERRITORYTYPE1 = 786
  //TERRITORYTYPE2 = 759

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1024999 || param2 == 1024999 ) // ACTOR0 = HIEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1024998 || param2 == 1024998 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025009 || param2 == 1025009 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025545 || param2 == 1025545 ) // ACTOR3 = YUGIRI
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1025354 || param2 == 1025354 ) // ACTOR4 = KIENKANGATEKEEPER03028
        {
          Scene00005( player ); // Scene00005: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1025523 || param2 == 1025523 ) // ACTOR5 = BOATMAN03074
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=BOATMAN03074
          }
          break;
        }
        if( param1 == 1025524 || param2 == 1025524 ) // ACTOR6 = HIEN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1025525 || param2 == 1025525 ) // ACTOR7 = RASHO
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=RASHO
          break;
        }
        if( param1 == 1025575 || param2 == 1025575 ) // ACTOR8 = ALISAIE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025576 || param2 == 1025576 ) // ACTOR9 = YUGIRI
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1025574 || param2 == 1025574 ) // ACTOR10 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00012( player ); // Scene00012: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1025523 || param2 == 1025523 ) // ACTOR5 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(FadeIn), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1025523 || param2 == 1025523 ) // ACTOR5 = BOATMAN03074
        {
          Scene00014( player ); // Scene00014: Normal(Talk, YesNo, TargetCanMove), id=BOATMAN03074
          // +Callback Scene00015: Normal(Talk, YesNo, TargetCanMove), id=BOATMAN03074
          break;
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00016( player ); // Scene00016: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1025523 || param2 == 1025523 ) // ACTOR5 = BOATMAN03074
        {
          Scene00017( player ); // Scene00017: Normal(Talk, YesNo, TargetCanMove), id=BOATMAN03074
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1025528 || param2 == 1025528 ) // ACTOR12 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove, AutoFadeIn), id=HIEN
          }
          break;
        }
        if( param1 == 1025529 || param2 == 1025529 ) // ACTOR13 = ALISAIE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025530 || param2 == 1025530 ) // ACTOR14 = YUGIRI
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1025523 || param2 == 1025523 ) // ACTOR5 = BOATMAN03074
        {
          Scene00021( player ); // Scene00021: Normal(Talk, YesNo, TargetCanMove), id=BOATMAN03074
          break;
        }
        break;
      }
      case 6:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00022( player ); // Scene00022: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1025528 || param2 == 1025528 ) // ACTOR12 = HIEN
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove, AutoFadeIn), id=HIEN
          break;
        }
        if( param1 == 1025529 || param2 == 1025529 ) // ACTOR13 = ALISAIE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025530 || param2 == 1025530 ) // ACTOR14 = YUGIRI
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 1025538 || param2 == 1025538 ) // ACTOR15 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1025541 || param2 == 1025541 ) // ACTOR16 = IHANASHI
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=IHANASHI
          break;
        }
        if( param1 == 1025539 || param2 == 1025539 ) // ACTOR17 = ALISAIE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025540 || param2 == 1025540 ) // ACTOR18 = YUGIRI
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1025597 || param2 == 1025597 ) // ACTOR19 = HIEN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1025009 || param2 == 1025009 ) // ACTOR2 = ALISAIE
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025545 || param2 == 1025545 ) // ACTOR3 = YUGIRI
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024974 || param2 == 1024974 ) // ACTOR20 = KIENKANGATEKEEPER03028
        {
          Scene00033( player ); // Scene00033: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028
          break;
        }
        if( param1 == 1025541 || param2 == 1025541 ) // ACTOR16 = IHANASHI
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=IHANASHI
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    player.updateQuest( getId(), 7 );
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdd105:68610 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00005: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00006: Normal(Talk, TargetCanMove), id=BOATMAN03074" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      Scene00012( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00007: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00008: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00010: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00012: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      Scene00016( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00013: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00014: Normal(Talk, YesNo, TargetCanMove), id=BOATMAN03074" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00016( player );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00015: Normal(Talk, YesNo, TargetCanMove), id=BOATMAN03074" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00016( player );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00016: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 786 );
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00017: Normal(Talk, YesNo, TargetCanMove), id=BOATMAN03074" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00018: Normal(Talk, TargetCanMove, AutoFadeIn), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00021: Normal(Talk, YesNo, TargetCanMove), id=BOATMAN03074" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 786 );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00022: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00023: Normal(Talk, TargetCanMove, AutoFadeIn), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 759, 7.8, 0, 16.1, -1.57, false );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00027: Normal(Talk, TargetCanMove), id=IHANASHI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00029: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00030: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HIEN" );
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
    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00031: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00032: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00033: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 744 );
      }
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBdd105:68610 calling Scene00034: Normal(Talk, TargetCanMove), id=IHANASHI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdd105 );
