// FFXIVTheMovie.ParserV3
// id hint used:
//ENEMY2 = enemy2
//ENEMY3 = enemy3
//ENEMY4 = enemy4
//SCENE_28 = enemy2
//SCENE_29 = enemy3
//SCENE_30 = enemy4
//ACTOR3 = dummy3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda124 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda124() : Sapphire::ScriptAPI::EventScript( 67994 ){}; 
  ~StmBda124() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 5 entries
  //SEQ_2, 15 entries
  //SEQ_3, 15 entries
  //SEQ_4, 7 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1020379
  //ACTOR1 = 1020378
  //ACTOR10 = 1020515
  //ACTOR11 = 1023755
  //ACTOR12 = 1023756
  //ACTOR13 = 1020381
  //ACTOR14 = 1020380
  //ACTOR15 = 1023757
  //ACTOR16 = 1023758
  //ACTOR17 = 1023759
  //ACTOR18 = 1020382
  //ACTOR19 = 1020383
  //ACTOR2 = 1020360
  //ACTOR3 = 1020362
  //ACTOR4 = 1020508
  //ACTOR5 = 1020842
  //ACTOR6 = 1020509
  //ACTOR7 = 1020510
  //ACTOR8 = 1020513
  //ACTOR9 = 1020514
  //BINDACTOR01 = 6836936
  //ENEMY0 = 7021915
  //ENEMY1 = 7021917
  //ENEMY2 = 7022968
  //ENEMY3 = 7005944
  //ENEMY4 = 7022969
  //EOBJECT0 = 2008681
  //EOBJECT1 = 2008065
  //EOBJECT2 = 2008317
  //EVENTACTION0 = 50
  //EVENTRANGE0 = 6840940
  //EVENTRANGE1 = 6875129
  //LOCACTION01 = 1
  //LOCACTOR01 = 1018509
  //LOCACTOR02 = 1019543
  //LOCACTOR03 = 1021691
  //LOCACTOR04 = 1022500
  //LOCIDLE01 = 34

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020379 || param2 == 1020379 ) // ACTOR0 = MEFFRID
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MEFFRID
        }
        if( param1 == 1020378 || param2 == 1020378 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020360 || param2 == 1020360 ) // ACTOR2 = WISCAR
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=WISCAR
        }
        if( param1 == 1020362 || param2 == 1020362 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( param1 == 1020508 || param2 == 1020508 ) // ACTOR4 = BEWILDEREDWOMEN
        {
          Scene00005( player ); // Scene00005: Normal(Talk), id=BEWILDEREDWOMEN
        }
        break;
      }
      case 1:
      {
        if( param1 == 2008681 || param2 == 2008681 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(FadeIn), id=unknown
          }
        }
        if( param1 == 1020360 || param2 == 1020360 ) // ACTOR2 = WISCAR
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=WISCAR
        }
        if( param1 == 1020362 || param2 == 1020362 ) // ACTOR3 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( param1 == 1020508 || param2 == 1020508 ) // ACTOR4 = BEWILDEREDWOMEN
        {
          Scene00010( player ); // Scene00010: Normal(Talk), id=BEWILDEREDWOMEN
        }
        if( param1 == 1020842 || param2 == 1020842 ) // ACTOR5 = SHARPEYEDWOMEN
        {
          Scene00011( player ); // Scene00011: Normal(Talk), id=SHARPEYEDWOMEN
        }
        break;
      }
      case 2:
      {
        if( param1 == 6840940 || param2 == 6840940 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00012( player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 7021915 || param2 == 7021915 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( param1 == 7021917 || param2 == 7021917 ) // ENEMY1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( param1 == 1020360 || param2 == 1020360 ) // ACTOR2 = WISCAR
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=WISCAR
        }
        if( param1 == 1020362 || param2 == 1020362 ) // ACTOR3 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( param1 == 1020509 || param2 == 1020509 ) // ACTOR6 = LYSE
        {
          Scene00017( player ); // Scene00017: Normal(Talk), id=LYSE
        }
        if( param1 == 1020510 || param2 == 1020510 ) // ACTOR7 = MEFFRID
        {
          Scene00018( player ); // Scene00018: Normal(Talk), id=MEFFRID
        }
        if( param1 == 1020513 || param2 == 1020513 ) // ACTOR8 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( param1 == 1020514 || param2 == 1020514 ) // ACTOR9 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        if( param1 == 1020515 || param2 == 1020515 ) // ACTOR10 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
        }
        if( param1 == 2008065 || param2 == 2008065 ) // EOBJECT1 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
        }
        if( param1 == 1020842 || param2 == 1020842 ) // ACTOR5 = SHARPEYEDWOMEN
        {
          Scene00023( player ); // Scene00023: Normal(Talk), id=SHARPEYEDWOMEN
        }
        if( param1 == 1020508 || param2 == 1020508 ) // ACTOR4 = BEWILDEREDWOMEN
        {
          Scene00024( player ); // Scene00024: Normal(Talk), id=BEWILDEREDWOMEN
        }
        if( param1 == 1023755 || param2 == 1023755 ) // ACTOR11 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
        }
        if( param1 == 1023756 || param2 == 1023756 ) // ACTOR12 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( param1 == 6875129 || param2 == 6875129 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00027( player ); // Scene00027: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 7022968 || param2 == 7022968 ) // ENEMY2 = enemy2
        {
          Scene00028( player ); // Scene00028: Normal(None), id=enemy2
        }
        if( param1 == 7005944 || param2 == 7005944 ) // ENEMY3 = enemy3
        {
          Scene00029( player ); // Scene00029: Normal(None), id=enemy3
        }
        if( param1 == 7022969 || param2 == 7022969 ) // ENEMY4 = enemy4
        {
          Scene00030( player ); // Scene00030: Normal(None), id=enemy4
        }
        if( param1 == 1020509 || param2 == 1020509 ) // ACTOR6 = LYSE
        {
          Scene00031( player ); // Scene00031: Normal(Talk), id=LYSE
        }
        if( param1 == 1020510 || param2 == 1020510 ) // ACTOR7 = MEFFRID
        {
          Scene00032( player ); // Scene00032: Normal(Talk), id=MEFFRID
        }
        if( param1 == 1020513 || param2 == 1020513 ) // ACTOR8 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
        }
        if( param1 == 1020514 || param2 == 1020514 ) // ACTOR9 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
        }
        if( param1 == 1020515 || param2 == 1020515 ) // ACTOR10 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
        }
        if( param1 == 1020381 || param2 == 1020381 ) // ACTOR13 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
        }
        if( param1 == 1020380 || param2 == 1020380 ) // ACTOR14 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(Message), id=unknown
        }
        if( param1 == 2008317 || param2 == 2008317 ) // EOBJECT2 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
        }
        if( param1 == 1023757 || param2 == 1023757 ) // ACTOR15 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
        }
        if( param1 == 1023758 || param2 == 1023758 ) // ACTOR16 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
        }
        if( param1 == 1023759 || param2 == 1023759 ) // ACTOR17 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020380 || param2 == 1020380 ) // ACTOR14 = WERCRATA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00042( player ); // Scene00042: Normal(Talk, FadeIn, TargetCanMove), id=WERCRATA
          }
        }
        if( param1 == 1020381 || param2 == 1020381 ) // ACTOR13 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
        }
        if( param1 == 1020509 || param2 == 1020509 ) // ACTOR6 = LYSE
        {
          Scene00044( player ); // Scene00044: Normal(Talk), id=LYSE
        }
        if( param1 == 1020510 || param2 == 1020510 ) // ACTOR7 = MEFFRID
        {
          Scene00045( player ); // Scene00045: Normal(Talk), id=MEFFRID
        }
        if( param1 == 1020513 || param2 == 1020513 ) // ACTOR8 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
        }
        if( param1 == 1020514 || param2 == 1020514 ) // ACTOR9 = unknown
        {
          Scene00047( player ); // Scene00047: Normal(None), id=unknown
        }
        if( param1 == 1020515 || param2 == 1020515 ) // ACTOR10 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020382 || param2 == 1020382 ) // ACTOR18 = LYSE
        {
          Scene00049( player ); // Scene00049: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
        }
        if( param1 == 1020383 || param2 == 1020383 ) // ACTOR19 = MEFFRID
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=MEFFRID
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
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda124:67994 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00003: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00005: Normal(Talk), id=BEWILDEREDWOMEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00007: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00008: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00010: Normal(Talk), id=BEWILDEREDWOMEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00011: Normal(Talk), id=SHARPEYEDWOMEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00015: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00017: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00018: Normal(Talk), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00023: Normal(Talk), id=SHARPEYEDWOMEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00024: Normal(Talk), id=BEWILDEREDWOMEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00027: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00028: Normal(None), id=enemy2" );
    checkProgressSeq3( player );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00029: Normal(None), id=enemy3" );
    checkProgressSeq3( player );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00030: Normal(None), id=enemy4" );
    checkProgressSeq3( player );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00031: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00032: Normal(Talk), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00037: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00038: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00042: Normal(Talk, FadeIn, TargetCanMove), id=WERCRATA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 42, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00044: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00045: Normal(Talk), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00046: Normal(None), id=unknown" );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00047: Normal(None), id=unknown" );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00048: Normal(None), id=unknown" );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00049: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "StmBda124:67994 calling Scene00050: Normal(Talk, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda124 );
