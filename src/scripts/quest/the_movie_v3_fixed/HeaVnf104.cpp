// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_22 = ALPHINAUD
//fix: skip dungeon
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnf104 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnf104() : Sapphire::ScriptAPI::EventScript( 67890 ){}; 
  ~HeaVnf104() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 1 entries
  //SEQ_2, 7 entries
  //SEQ_3, 7 entries
  //SEQ_4, 2 entries
  //SEQ_5, 3 entries
  //SEQ_6, 2 entries
  //SEQ_7, 2 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1018020
  //ACTOR1 = 1018021
  //ACTOR10 = 1018024
  //ACTOR11 = 1018025
  //ACTOR12 = 1018010
  //ACTOR13 = 5010000
  //ACTOR14 = 1018026
  //ACTOR15 = 1018027
  //ACTOR16 = 1018028
  //ACTOR17 = 1018029
  //ACTOR18 = 1018030
  //ACTOR19 = 1018031
  //ACTOR2 = 1018022
  //ACTOR3 = 1018359
  //ACTOR4 = 1018360
  //ACTOR5 = 1018361
  //ACTOR6 = 1018362
  //ACTOR7 = 1018363
  //ACTOR8 = 1018032
  //ACTOR9 = 1018023
  //BINDACTOR1 = 6449999
  //BINDACTOR2 = 6495212
  //CUTSCENEN01 = 1300
  //CUTSCENEN02 = 1301
  //CUTSCENEN03 = 1302
  //CUTSCENEN04 = 1303
  //CUTSCENEN05 = 1304
  //EVENTACTIONTIMELINEEVENTSPIRIT = 1071
  //INSTANCEDUNGEON0 = 48
  //LOCACTOR0 = 1017687
  //LOCACTOR1 = 1011896
  //LOCACTOR2 = 1016758
  //LOCACTOR3 = 1015833
  //LOCACTOR4 = 1015842
  //LOCACTOR5 = 1011887
  //LOCACTOR6 = 1008178
  //LOCACTOR7 = 1008179
  //LOCACTOR8 = 1011895
  //LOCACTOR9 = 1011278
  //LOCBGM1 = 96
  //LOCBGM2 = 66
  //LOCSE0 = 39
  //LOCSE1 = 40
  //POPRANGE0 = 6572669
  //POPRANGE1 = 6647699
  //POPRANGE2 = 6487409
  //SCREENIMAGE0 = 470
  //TERRITORYTYPE0 = 351
  //TERRITORYTYPE1 = 152

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1018020 || param2 == 1018020 ) // ACTOR0 = ALISAIE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1018021 || param2 == 1018021 ) // ACTOR1 = YUGIRI
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00003( player ); // Scene00003: Normal(Talk, FadeIn), id=unknown
        }
        break;
      }
      case 2:
      {
        if( param1 == 1018022 || param2 == 1018022 ) // ACTOR2 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1018359 || param2 == 1018359 ) // ACTOR3 = ALISAIE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1018360 || param2 == 1018360 ) // ACTOR4 = YDA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YDA
        }
        if( param1 == 1018361 || param2 == 1018361 ) // ACTOR5 = PAPALYMO
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( param1 == 1018362 || param2 == 1018362 ) // ACTOR6 = YUGIRI
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1018363 || param2 == 1018363 ) // ACTOR7 = THANCRED
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1018032 || param2 == 1018032 ) // ACTOR8 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( param1 == 1018023 || param2 == 1018023 ) // ACTOR9 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1018359 || param2 == 1018359 ) // ACTOR3 = ALISAIE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1018360 || param2 == 1018360 ) // ACTOR4 = YDA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=YDA
        }
        if( param1 == 1018361 || param2 == 1018361 ) // ACTOR5 = PAPALYMO
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( param1 == 1018362 || param2 == 1018362 ) // ACTOR6 = YUGIRI
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1018363 || param2 == 1018363 ) // ACTOR7 = THANCRED
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1018032 || param2 == 1018032 ) // ACTOR8 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        break;
      }
      case 4:
      {
        if( param1 == 1018024 || param2 == 1018024 ) // ACTOR10 = SERPENTSCOUT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, FadeIn, TargetCanMove), id=SERPENTSCOUT
            // +Callback Scene00019: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1018359 || param2 == 1018359 ) // ACTOR3 = ALISAIE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 5:
      {
        if( param1 == 1018025 || param2 == 1018025 ) // ACTOR11 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00022: Normal(FadeIn), id=ALPHINAUD
          }
        }
        if( param1 == 1018359 || param2 == 1018359 ) // ACTOR3 = ALISAIE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1018010 || param2 == 1018010 ) // ACTOR12 = SERPENTSCOUT
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=SERPENTSCOUT
        }
        break;
      }
      case 6:
      {
        if( param1 == 1018359 || param2 == 1018359 ) // ACTOR3 = ALISAIE
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1018010 || param2 == 1018010 ) // ACTOR12 = SERPENTSCOUT
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=SERPENTSCOUT
        }
        break;
      }
      case 7:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00027( player ); // Scene00027: Normal(CutScene), id=unknown
        }
        if( param1 == 1018359 || param2 == 1018359 ) // ACTOR3 = ALISAIE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 255:
      {
        if( param1 == 1018026 || param2 == 1018026 ) // ACTOR14 = YDA
        {
          Scene00029( player ); // Scene00029: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=YDA
        }
        if( param1 == 1018027 || param2 == 1018027 ) // ACTOR15 = HILDA
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1018028 || param2 == 1018028 ) // ACTOR16 = PIPIN
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=PIPIN
        }
        if( param1 == 1018029 || param2 == 1018029 ) // ACTOR17 = ALPHINAUD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1018030 || param2 == 1018030 ) // ACTOR18 = YUGIRI
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1018031 || param2 == 1018031 ) // ACTOR19 = THANCRED
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1018359 || param2 == 1018359 ) // ACTOR3 = ALISAIE
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALISAIE
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
    player.updateQuest( getId(), 2 );
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnf104:67890 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00003: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00006: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00007: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00009: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00013: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00014: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00015: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00016: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00018: Normal(Talk, FadeIn, TargetCanMove), id=SERPENTSCOUT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling [BranchTrue]Scene00019: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00021: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00022( player );
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling [BranchTrue]Scene00022: Normal(FadeIn), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00024: Normal(Talk, TargetCanMove), id=SERPENTSCOUT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00026: Normal(Talk, TargetCanMove), id=SERPENTSCOUT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00027( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00027: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00029: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00030: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00031: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00034: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf104:67890 calling Scene00035: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnf104 );
