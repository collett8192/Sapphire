// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_46 = TATARU
//SCENE_32 = A14
//SCENE_33 = A14
//SCENE_34 = A14
//SCENE_35 = dummyt
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmf111 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmf111() : Sapphire::ScriptAPI::EventScript( 69190 ){}; 
  ~LucKmf111() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 5 entries
  //SEQ_2, 4 entries
  //SEQ_3, 3 entries
  //SEQ_4, 2 entries
  //SEQ_5, 1 entries
  //SEQ_6, 1 entries
  //SEQ_7, 6 entries
  //SEQ_8, 2 entries
  //SEQ_9, 1 entries
  //SEQ_10, 2 entries
  //SEQ_11, 7 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1030557
  //ACTOR1 = 1030556
  //ACTOR10 = 1030363
  //ACTOR11 = 1030364
  //ACTOR12 = 1030365
  //ACTOR13 = 1030366
  //ACTOR14 = 1030575
  //ACTOR15 = 1030576
  //ACTOR16 = 1030563
  //ACTOR17 = 1030564
  //ACTOR18 = 1030565
  //ACTOR19 = 1030566
  //ACTOR2 = 1030558
  //ACTOR20 = 1030567
  //ACTOR21 = 1030568
  //ACTOR22 = 1031257
  //ACTOR23 = 1029800
  //ACTOR3 = 1030559
  //ACTOR4 = 1030560
  //ACTOR5 = 1030561
  //ACTOR6 = 1030562
  //ACTOR7 = 5010000
  //ACTOR8 = 1030361
  //ACTOR9 = 1030362
  //CUTSCENE0 = 2064
  //CUTSCENE1 = 2065
  //CUTSCENE2 = 2066
  //CUTSCENE3 = 2067
  //CUTSCENE4 = 2068
  //CUTSCENE5 = 2069
  //CUTSCENE6 = 2070
  //CUTSCENE7 = 2071
  //CUTSCENE8 = 2072
  //INSTANCEDUNGEON0 = 67
  //INSTANCEDUNGEON1 = 20066
  //LOCBGM01 = 685
  //LOCBGM02 = 241
  //LOCBGM03 = 653
  //LOCBGM04 = 573
  //LOCFACIAL01 = 6253
  //POPRANGE0 = 7955956
  //POPRANGE1 = 7955910
  //POPRANGE2 = 7952791
  //POPRANGE3 = 7952845
  //QUEST01 = 66031
  //SCREENIMAGE0 = 747
  //SCREENIMAGE1 = 750
  //TERRITORYTYPE0 = 881
  //TERRITORYTYPE1 = 844

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030557 || param2 == 1030557 ) // ACTOR0 = ALISAIE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030556 || param2 == 1030556 ) // ACTOR1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1030558 || param2 == 1030558 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1030559 || param2 == 1030559 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1030560 || param2 == 1030560 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(TargetCanMove, SystemTalk), id=unknown
          break;
        }
        if( param1 == 1030561 || param2 == 1030561 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(TargetCanMove, SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1030556 || param2 == 1030556 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1030558 || param2 == 1030558 ) // ACTOR2 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1030559 || param2 == 1030559 ) // ACTOR3 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1030560 || param2 == 1030560 ) // ACTOR4 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(TargetCanMove, SystemTalk), id=unknown
          break;
        }
        if( param1 == 1030561 || param2 == 1030561 ) // ACTOR5 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(TargetCanMove, SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1030561 || param2 == 1030561 ) // ACTOR5 = URIANGER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=URIANGER
          }
          break;
        }
        if( param1 == 1030558 || param2 == 1030558 ) // ACTOR2 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1030559 || param2 == 1030559 ) // ACTOR3 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1030560 || param2 == 1030560 ) // ACTOR4 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(TargetCanMove, SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1030560 || param2 == 1030560 ) // ACTOR4 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=YSHTOLA
          }
          break;
        }
        if( param1 == 1030558 || param2 == 1030558 ) // ACTOR2 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1030559 || param2 == 1030559 ) // ACTOR3 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1030558 || param2 == 1030558 ) // ACTOR2 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED
          }
          break;
        }
        if( param1 == 1030559 || param2 == 1030559 ) // ACTOR3 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        Scene00021( player ); // Scene00021: Normal(Talk, FadeIn, TargetCanMove, Menu), id=RYNE
        break;
      }
      case 6:
      {
        Scene00022( player ); // Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=OFFICIAL03654
        // +Callback Scene00023: Normal(CutScene, AutoFadeIn), id=unknown
        // +Callback Scene00024: Normal(FadeIn), id=unknown
        break;
      }
      case 7:
      {
        if( param1 == 1030361 || param2 == 1030361 ) // ACTOR8 = ALPHINAUD
        {
          Scene00025( player ); // Scene00025: MsqDungeon(Talk, TargetCanMove, Menu), id=ALPHINAUD
          break;
        }
        if( param1 == 1030362 || param2 == 1030362 ) // ACTOR9 = ALISAIE
        {
          Scene00026( player ); // Scene00026: MsqDungeon(Talk, TargetCanMove, Menu), id=ALISAIE
          break;
        }
        if( param1 == 1030363 || param2 == 1030363 ) // ACTOR10 = THANCRED
        {
          Scene00027( player ); // Scene00027: MsqDungeon(Talk, TargetCanMove, Menu), id=THANCRED
          break;
        }
        if( param1 == 1030364 || param2 == 1030364 ) // ACTOR11 = RYNE
        {
          Scene00028( player ); // Scene00028: MsqDungeon(Talk, TargetCanMove, Menu), id=RYNE
          break;
        }
        if( param1 == 1030365 || param2 == 1030365 ) // ACTOR12 = YSHTOLA
        {
          Scene00029( player ); // Scene00029: MsqDungeon(Talk, TargetCanMove, Menu), id=YSHTOLA
          break;
        }
        if( param1 == 1030366 || param2 == 1030366 ) // ACTOR13 = URIANGER
        {
          Scene00030( player ); // Scene00030: MsqDungeon(Talk, TargetCanMove, Menu), id=URIANGER
          break;
        }
        break;
      }
      case 8:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00031( player ); // Scene00031: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1030575 || param2 == 1030575 ) // ACTOR14 = A14
        {
          Scene00033( player );
          break;
        }
        break;
      }
      case 9:
      {
        if( param1 == 1030575 || param2 == 1030575 ) // ACTOR14 = A14
        {
          Scene00034( player );
          break;
        }
        break;
      }
      case 10:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = dummyt
        {
          Scene00035( player ); // Scene00035: Normal(CutScene), id=dummyt
          break;
        }
        if( param1 == 1030575 || param2 == 1030575 ) // ACTOR14 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(YesNo), id=unknown
          break;
        }
        break;
      }
      case 11:
      {
        if( param1 == 1030576 || param2 == 1030576 ) // ACTOR15 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00037( player ); // Scene00037: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 4302920093 || param2 == 4302920093 ) // ACTOR16 = ALPHINAUD
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 4302920094 || param2 == 4302920094 ) // ACTOR17 = ALISAIE
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 4302920095 || param2 == 4302920095 ) // ACTOR18 = THANCRED
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 4302920102 || param2 == 4302920102 ) // ACTOR19 = RYNE
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 4302920111 || param2 == 4302920111 ) // ACTOR20 = YSHTOLA
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 4302920113 || param2 == 4302920113 ) // ACTOR21 = URIANGER
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1031257 || param2 == 1031257 ) // ACTOR22 = TATARU
        {
          Scene00044( player ); // Scene00044: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, AutoFadeIn), id=TATARU
          // +Callback Scene00045: Normal(CutScene), id=unknown
          // +Callback Scene00046: Normal(SystemTalk), id=TATARU
          break;
        }
        if( param1 == 1029800 || param2 == 1029800 ) // ACTOR23 = COINACHINVESTIGATOR03279
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=COINACHINVESTIGATOR03279
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
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
    player.updateQuest( getId(), 6 );
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    player.updateQuest( getId(), 7 );
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    player.updateQuest( getId(), 8 );
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    player.updateQuest( getId(), 9 );
  }
  void checkProgressSeq9( Entity::Player& player )
  {
    player.updateQuest( getId(), 10 );
  }
  void checkProgressSeq10( Entity::Player& player )
  {
    player.updateQuest( getId(), 11 );
  }
  void checkProgressSeq11( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmf111:69190 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00002: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00003: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00004: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00005: Normal(TargetCanMove, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00006: Normal(TargetCanMove, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00008: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00009: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00010: Normal(TargetCanMove, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00011: Normal(TargetCanMove, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00013: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00014: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00015: Normal(TargetCanMove, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00017: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00018: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00019: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00020: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00021: Normal(Talk, FadeIn, TargetCanMove, Menu), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq5( player );
      }
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=OFFICIAL03654" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00023: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00024( player );
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00024: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00025: MsqDungeon(Talk, TargetCanMove, Menu), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00031( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00026: MsqDungeon(Talk, TargetCanMove, Menu), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00031( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00027: MsqDungeon(Talk, TargetCanMove, Menu), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00031( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00028: MsqDungeon(Talk, TargetCanMove, Menu), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00031( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00029: MsqDungeon(Talk, TargetCanMove, Menu), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00031( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00030: MsqDungeon(Talk, TargetCanMove, Menu), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00031( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00031: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq8( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 31, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00032: Normal(FadeIn), id=A14" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00033: Normal(YesNo), id=A14" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 33, NONE, callback );
  }
  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00034: Normal(YesNo), id=A14" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00035( player );
      }
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00035: Normal(CutScene), id=dummyt" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq10( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 844 );
    };
    player.playScene( getId(), 35, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00036: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00037: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq11( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 156, 22.33, 21.26, -634.35, -0.365, false );
    };
    player.playScene( getId(), 37, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00038: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00039: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00040: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00041: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00042: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00043: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00044: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, AutoFadeIn), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00045( player );
      }
    };
    player.playScene( getId(), 44, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI | INVIS_ALL, callback );
  }
  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00045: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00046( player );
    };
    player.playScene( getId(), 45, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00046: Normal(SystemTalk), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "LucKmf111:69190 calling Scene00047: Normal(Talk, TargetCanMove), id=COINACHINVESTIGATOR03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmf111 );
