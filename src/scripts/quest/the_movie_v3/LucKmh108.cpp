// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_9 = URIANGER
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmh108 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmh108() : Sapphire::ScriptAPI::EventScript( 69304 ){}; 
  ~LucKmh108() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 1 entries
  //SEQ_2, 6 entries
  //SEQ_3, 10 entries
  //SEQ_4, 6 entries
  //SEQ_5, 2 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1032526
  //ACTOR1 = 1032522
  //ACTOR10 = 1032536
  //ACTOR11 = 1032537
  //ACTOR12 = 1032538
  //ACTOR13 = 1032656
  //ACTOR14 = 1032531
  //ACTOR15 = 1032533
  //ACTOR16 = 1032554
  //ACTOR17 = 1032555
  //ACTOR18 = 1032690
  //ACTOR19 = 1032691
  //ACTOR2 = 1032523
  //ACTOR20 = 1032692
  //ACTOR21 = 1032689
  //ACTOR22 = 1032693
  //ACTOR3 = 1032524
  //ACTOR4 = 1032525
  //ACTOR5 = 1032527
  //ACTOR6 = 1032528
  //ACTOR7 = 1030333
  //ACTOR8 = 1032534
  //ACTOR9 = 1032535
  //EOBJECT0 = 2010278
  //EOBJECT1 = 2010280
  //EOBJECT2 = 2010282
  //EOBJECT3 = 2009908
  //EVENTACTION0 = 1
  //LOCACTORFISHERMEN = 1032675
  //LOCACTORURIANGER = 1026570
  //LOCBINDALISAIE = 8260097
  //LOCBINDALISAIE02 = 8260357
  //LOCBINDALPHINAUD = 8260091
  //LOCBINDALPHINAUD02 = 8260356
  //LOCBINDFISHERMEN02 = 8262667
  //LOCBINDRYNE = 8260101
  //LOCBINDRYNE02 = 8260360
  //LOCBINDSOLDIER01 = 8262666
  //LOCBINDSOLDIER02 = 8262665
  //LOCBINDTHANCRED = 8260098
  //LOCBINDTHANCRED02 = 8260358
  //LOCBINDTOLSHSAATH = 7823472
  //LOCBINDURIANGER = 8262664
  //LOCBINDYSHTOLA = 8260099
  //LOCBINDYSHTOLA02 = 8260359
  //LOCSECRYBISMARCK02 = 251
  //LOCSESPLASH = 50
  //NCUTLUCKMH00120 = 2243
  //POPRANGE0 = 8260364
  //POPRANGE1 = 8306951

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1032526 || param2 == 1032526 ) // ACTOR0 = URIANGER
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032522 || param2 == 1032522 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032523 || param2 == 1032523 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032524 || param2 == 1032524 ) // ACTOR3 = THANCRED
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1032525 || param2 == 1032525 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032527 || param2 == 1032527 ) // ACTOR5 = RYNE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 1:
      {
        Scene00007( player ); // Scene00007: Normal(CutScene, AutoFadeIn), id=unknown
        break;
      }
      case 2:
      {
        if( param1 == 1030333 || param2 == 1030333 ) // ACTOR7 = URIANGER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=URIANGER
            // +Callback Scene00009: Normal(Talk, FadeIn, TargetCanMove), id=URIANGER
          }
          break;
        }
        if( param1 == 1032534 || param2 == 1032534 ) // ACTOR8 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032535 || param2 == 1032535 ) // ACTOR9 = ALISAIE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032536 || param2 == 1032536 ) // ACTOR10 = THANCRED
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1032537 || param2 == 1032537 ) // ACTOR11 = YSHTOLA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032538 || param2 == 1032538 ) // ACTOR12 = RYNE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2010278 || param2 == 2010278 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00016( player ); // Scene00016: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2010280 || param2 == 2010280 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00018( player ); // Scene00018: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2010282 || param2 == 2010282 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00020( player ); // Scene00020: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1032656 || param2 == 1032656 ) // ACTOR13 = ALISAIE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 2009908 || param2 == 2009908 ) // EOBJECT3 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1032534 || param2 == 1032534 ) // ACTOR8 = ALPHINAUD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032536 || param2 == 1032536 ) // ACTOR10 = THANCRED
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1032537 || param2 == 1032537 ) // ACTOR11 = YSHTOLA
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032538 || param2 == 1032538 ) // ACTOR12 = RYNE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030333 || param2 == 1030333 ) // ACTOR7 = URIANGER
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1030333 || param2 == 1030333 ) // ACTOR7 = URIANGER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=URIANGER
            // +Callback Scene00029: Normal(Talk, FadeIn, Menu), id=unknown
          }
          break;
        }
        if( param1 == 1032534 || param2 == 1032534 ) // ACTOR8 = ALPHINAUD
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032535 || param2 == 1032535 ) // ACTOR9 = ALISAIE
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032536 || param2 == 1032536 ) // ACTOR10 = THANCRED
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1032537 || param2 == 1032537 ) // ACTOR11 = YSHTOLA
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032538 || param2 == 1032538 ) // ACTOR12 = RYNE
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1032531 || param2 == 1032531 ) // ACTOR14 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=THANCRED
            // +Callback Scene00036: Normal(Talk, FadeIn, TargetCanMove), id=THANCRED
          }
          break;
        }
        if( param1 == 1032533 || param2 == 1032533 ) // ACTOR15 = URIANGER
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1032554 || param2 == 1032554 ) // ACTOR16 = THANCRED
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=THANCRED
          // +Callback Scene00039: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=THANCRED
          break;
        }
        if( param1 == 1032555 || param2 == 1032555 ) // ACTOR17 = URIANGER
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032690 || param2 == 1032690 ) // ACTOR18 = BRAVESOLDIER
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=BRAVESOLDIER
          break;
        }
        if( param1 == 1032691 || param2 == 1032691 ) // ACTOR19 = SOLDIER03608
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=SOLDIER03608
          break;
        }
        if( param1 == 1032692 || param2 == 1032692 ) // ACTOR20 = FISHERB03768
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=FISHERB03768
          break;
        }
        if( param1 == 1032689 || param2 == 1032689 ) // ACTOR21 = FISHERA03768
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=FISHERA03768
          break;
        }
        if( param1 == 1032693 || param2 == 1032693 ) // ACTOR22 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 1 )
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
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmh108:69304 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00004: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00006: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00007: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00008: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00009: Normal(Talk, FadeIn, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00012: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00014: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00016: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00018: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00020: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00024: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00025: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00026: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00027: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00028: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00029( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00029: Normal(Talk, FadeIn, Menu), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq4( player );
      }
    };
    player.playScene( getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00031: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00032: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00033: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00034: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00035: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00036( player );
    };
    player.playScene( getId(), 35, NONE, callback );
  }
  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00036: Normal(Talk, FadeIn, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00037: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00038: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00039( player );
    };
    player.playScene( getId(), 38, NONE, callback );
  }
  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00039: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=THANCRED" );
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
    player.playScene( getId(), 39, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00040: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00041: Normal(Talk, TargetCanMove), id=BRAVESOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00042: Normal(Talk, TargetCanMove), id=SOLDIER03608" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00043: Normal(Talk, TargetCanMove), id=FISHERB03768" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00044: Normal(Talk, TargetCanMove), id=FISHERA03768" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKmh108:69304 calling Scene00045: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( LucKmh108 );
