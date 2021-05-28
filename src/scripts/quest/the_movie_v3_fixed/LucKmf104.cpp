// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmf104 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmf104() : Sapphire::ScriptAPI::EventScript( 69183 ){}; 
  ~LucKmf104() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 1 entries
  //SEQ_2, 8 entries
  //SEQ_3, 6 entries
  //SEQ_4, 7 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1030327
  //ACTOR1 = 1030322
  //ACTOR10 = 1030331
  //ACTOR11 = 1030332
  //ACTOR12 = 1030333
  //ACTOR13 = 1030339
  //ACTOR14 = 1030334
  //ACTOR15 = 1030335
  //ACTOR16 = 1030336
  //ACTOR17 = 1030337
  //ACTOR18 = 1030338
  //ACTOR2 = 1030323
  //ACTOR3 = 1030324
  //ACTOR4 = 1030325
  //ACTOR5 = 1030326
  //ACTOR6 = 1030346
  //ACTOR7 = 1030328
  //ACTOR8 = 1030329
  //ACTOR9 = 1030330
  //BINDACTOR01 = 7936331
  //BINDACTOR02 = 7936332
  //BINDACTOR03 = 7936333
  //BINDACTOR04 = 7936334
  //BINDACTOR05 = 7936336
  //CUTSCENE0 = 2058
  //CUTSCENE1 = 2059
  //CUTSCENE2 = 2060
  //EOBJECT0 = 2010137
  //EOBJECT1 = 2010138
  //EOBJECT2 = 2010140
  //EVENTACTION0 = 2
  //LOCBGM01 = 673
  //LOCBGM02 = 89
  //POPRANGE0 = 7954162
  //TERRITORYTYPE0 = 818

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030327 || param2 == 1030327 ) // ACTOR0 = URIANGER
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030322 || param2 == 1030322 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030323 || param2 == 1030323 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030324 || param2 == 1030324 ) // ACTOR3 = THANCRED
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030325 || param2 == 1030325 ) // ACTOR4 = RYNE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030326 || param2 == 1030326 ) // ACTOR5 = YSHTOLA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 1:
      {
        Scene00007( player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=URIANGER
        break;
      }
      case 2:
      {
        if( param1 == 2010137 || param2 == 2010137 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2010138 || param2 == 2010138 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1030328 || param2 == 1030328 ) // ACTOR7 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030329 || param2 == 1030329 ) // ACTOR8 = ALISAIE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030330 || param2 == 1030330 ) // ACTOR9 = THANCRED
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030331 || param2 == 1030331 ) // ACTOR10 = RYNE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030332 || param2 == 1030332 ) // ACTOR11 = YSHTOLA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030333 || param2 == 1030333 ) // ACTOR12 = URIANGER
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1030333 || param2 == 1030333 ) // ACTOR12 = URIANGER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove, Menu), id=URIANGER
          }
          break;
        }
        if( param1 == 1030328 || param2 == 1030328 ) // ACTOR7 = ALPHINAUD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030329 || param2 == 1030329 ) // ACTOR8 = ALISAIE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030330 || param2 == 1030330 ) // ACTOR9 = THANCRED
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030331 || param2 == 1030331 ) // ACTOR10 = RYNE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030332 || param2 == 1030332 ) // ACTOR11 = YSHTOLA
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00024( player ); // Scene00024: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1030328 || param2 == 1030328 ) // ACTOR7 = ALPHINAUD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030329 || param2 == 1030329 ) // ACTOR8 = ALISAIE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030330 || param2 == 1030330 ) // ACTOR9 = THANCRED
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030331 || param2 == 1030331 ) // ACTOR10 = RYNE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030332 || param2 == 1030332 ) // ACTOR11 = YSHTOLA
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030333 || param2 == 1030333 ) // ACTOR12 = URIANGER
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove, Menu), id=URIANGER
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030339 || param2 == 1030339 ) // ACTOR13 = URIANGER
        {
          Scene00031( player ); // Scene00031: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=URIANGER
          break;
        }
        if( param1 == 1030334 || param2 == 1030334 ) // ACTOR14 = ALPHINAUD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030335 || param2 == 1030335 ) // ACTOR15 = ALISAIE
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030336 || param2 == 1030336 ) // ACTOR16 = THANCRED
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030337 || param2 == 1030337 ) // ACTOR17 = RYNE
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030338 || param2 == 1030338 ) // ACTOR18 = YSHTOLA
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 2010140 || param2 == 2010140 ) // EOBJECT2 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(YesNo), id=unknown
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
      {
        player.setQuestUI8BH( getId(), 0 );
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmf104:69183 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00004: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00005: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00009: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00011: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00014: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00015: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00016: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00017: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00018: Normal(Talk, TargetCanMove, Menu), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq3( player );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 818, 280, 414.8, -861, 0.66, false );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00021: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00022: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00023: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00024: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00026: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00027: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00028: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00030: Normal(Talk, TargetCanMove, Menu), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 818, 280, 414.8, -861, 0.66, false );
      }
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00031: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=URIANGER" );
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
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00033: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00034: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00035: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00036: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmf104:69183 calling Scene00037: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 37, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmf104 );
