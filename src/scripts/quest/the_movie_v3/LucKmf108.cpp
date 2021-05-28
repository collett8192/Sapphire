// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_3 = dummy_seq1
//SCENE_4 = dummy_seq1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmf108 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmf108() : Sapphire::ScriptAPI::EventScript( 69187 ){}; 
  ~LucKmf108() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 8 entries
  //SEQ_4, 5 entries
  //SEQ_5, 6 entries
  //SEQ_6, 7 entries
  //SEQ_7, 7 entries
  //SEQ_8, 8 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1030586
  //ACTOR1 = 1027757
  //ACTOR10 = 1030532
  //ACTOR11 = 1030529
  //ACTOR12 = 1030530
  //ACTOR13 = 1030527
  //ACTOR14 = 1030531
  //ACTOR15 = 1031595
  //ACTOR16 = 1030528
  //ACTOR17 = 1031596
  //ACTOR18 = 1030534
  //ACTOR19 = 1030540
  //ACTOR2 = 1031279
  //ACTOR20 = 1030539
  //ACTOR21 = 1030541
  //ACTOR22 = 1030542
  //ACTOR23 = 1030543
  //ACTOR24 = 1030544
  //ACTOR25 = 1030344
  //ACTOR26 = 1030340
  //ACTOR27 = 1030341
  //ACTOR28 = 1030342
  //ACTOR29 = 1030343
  //ACTOR3 = 1030570
  //ACTOR30 = 1030345
  //ACTOR4 = 1030521
  //ACTOR5 = 1030522
  //ACTOR6 = 1030523
  //ACTOR7 = 1030524
  //ACTOR8 = 1030525
  //ACTOR9 = 1030526
  //BINDACTOR01 = 7952458
  //BINDACTOR02 = 7952459
  //BINDACTOR03 = 7952460
  //BINDACTOR04 = 7952462
  //BINDACTOR05 = 7952463
  //BINDACTOR06 = 7952464
  //BINDOBJECT01 = 8049761
  //CUTSCENE0 = 2061
  //CUTSCENE1 = 2062
  //EVENTRANGE0 = 7952485
  //ITEM0 = 2002675
  //LOCACTION01 = 169
  //LOCACTION02 = 170
  //POPRANGE0 = 7952453
  //POPRANGE1 = 7956198
  //POPRANGE2 = 7952487
  //TERRITORYTYPE0 = 818

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack 1
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GRENOLDT
        // +Callback Scene00002: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=GRENOLDT
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        Scene00003( player ); // Scene00003: NpcTrade(Talk, TargetCanMove), id=dummy_seq1
        // +Callback Scene00004: Normal(CutScene, AutoFadeIn), id=dummy_seq1
        break;
      }
      case 2:
      {
        if( param1 == 1031279 || param2 == 1031279 ) // ACTOR2 = GUIDEOFONDO03651
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=GUIDEOFONDO03651
          }
          break;
        }
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR1 = TOLSHSAATH
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=TOLSHSAATH
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1030570 || param2 == 1030570 ) // ACTOR3 = GUIDEOFONDO03651
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=GUIDEOFONDO03651
          }
          break;
        }
        if( param1 == 1030521 || param2 == 1030521 ) // ACTOR4 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030522 || param2 == 1030522 ) // ACTOR5 = ALISAIE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030523 || param2 == 1030523 ) // ACTOR6 = THANCRED
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030524 || param2 == 1030524 ) // ACTOR7 = RYNE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030525 || param2 == 1030525 ) // ACTOR8 = YSHTOLA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030526 || param2 == 1030526 ) // ACTOR9 = URIANGER
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR1 = TOLSHSAATH
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=TOLSHSAATH
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1030532 || param2 == 1030532 ) // ACTOR10 = URIANGER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=URIANGER
          }
          break;
        }
        if( param1 == 1030570 || param2 == 1030570 ) // ACTOR3 = GUIDEOFONDO03651
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=GUIDEOFONDO03651
          break;
        }
        if( param1 == 1030529 || param2 == 1030529 ) // ACTOR11 = THANCRED
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030530 || param2 == 1030530 ) // ACTOR12 = RYNE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR1 = TOLSHSAATH
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=TOLSHSAATH
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1030527 || param2 == 1030527 ) // ACTOR13 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1030529 || param2 == 1030529 ) // ACTOR11 = THANCRED
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030530 || param2 == 1030530 ) // ACTOR12 = RYNE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030531 || param2 == 1030531 ) // ACTOR14 = YSHTOLA
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1031595 || param2 == 1031595 ) // ACTOR15 = URIANGER
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR1 = TOLSHSAATH
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=TOLSHSAATH
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1030528 || param2 == 1030528 ) // ACTOR16 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1030529 || param2 == 1030529 ) // ACTOR11 = THANCRED
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030530 || param2 == 1030530 ) // ACTOR12 = RYNE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030531 || param2 == 1030531 ) // ACTOR14 = YSHTOLA
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1031595 || param2 == 1031595 ) // ACTOR15 = URIANGER
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1031596 || param2 == 1031596 ) // ACTOR17 = ALPHINAUD
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR1 = TOLSHSAATH
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=TOLSHSAATH
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 1030534 || param2 == 1030534 ) // ACTOR18 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00033( player ); // Scene00033: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1030529 || param2 == 1030529 ) // ACTOR11 = THANCRED
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030530 || param2 == 1030530 ) // ACTOR12 = RYNE
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030531 || param2 == 1030531 ) // ACTOR14 = YSHTOLA
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1031595 || param2 == 1031595 ) // ACTOR15 = URIANGER
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1031596 || param2 == 1031596 ) // ACTOR17 = ALPHINAUD
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR1 = TOLSHSAATH
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=TOLSHSAATH
          break;
        }
        break;
      }
      case 8:
      {
        if( param1 == 7952485 || param2 == 7952485 ) // EVENTRANGE0 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(CutScene, Dismount, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1030540 || param2 == 1030540 ) // ACTOR19 = ALISAIE
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove, AutoFadeIn), id=ALISAIE
          break;
        }
        if( param1 == 1030539 || param2 == 1030539 ) // ACTOR20 = ALPHINAUD
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030541 || param2 == 1030541 ) // ACTOR21 = THANCRED
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030542 || param2 == 1030542 ) // ACTOR22 = RYNE
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030543 || param2 == 1030543 ) // ACTOR23 = YSHTOLA
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030544 || param2 == 1030544 ) // ACTOR24 = URIANGER
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR1 = TOLSHSAATH
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=TOLSHSAATH
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030344 || param2 == 1030344 ) // ACTOR25 = YSHTOLA
        {
          Scene00048( player ); // Scene00048: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030340 || param2 == 1030340 ) // ACTOR26 = ALPHINAUD
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030341 || param2 == 1030341 ) // ACTOR27 = ALISAIE
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030342 || param2 == 1030342 ) // ACTOR28 = THANCRED
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030343 || param2 == 1030343 ) // ACTOR29 = RYNE
        {
          Scene00052( player ); // Scene00052: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030345 || param2 == 1030345 ) // ACTOR30 = URIANGER
        {
          Scene00053( player ); // Scene00053: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR1 = TOLSHSAATH
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=TOLSHSAATH
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
    player.setQuestUI8BH( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 8 );
    }
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmf108:69187 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GRENOLDT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=GRENOLDT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00003: NpcTrade(Talk, TargetCanMove), id=dummy_seq1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00004( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00004: Normal(CutScene, AutoFadeIn), id=dummy_seq1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=GUIDEOFONDO03651" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00006: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00007: Normal(Talk, TargetCanMove), id=GUIDEOFONDO03651" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00010: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00011: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00013: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00014: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00016: Normal(Talk, TargetCanMove), id=GUIDEOFONDO03651" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00017: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00018: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00019: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00020: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00021: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00022: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00023: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00024: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00025: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00027: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00028: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00030: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00032: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00033: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 33, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00034: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00035: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00036: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00037: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00038: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00039: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00040: Normal(CutScene, Dismount, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq8( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 40, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00041: Normal(Talk, TargetCanMove, AutoFadeIn), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00042: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00043: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00044: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00045: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00046: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00047: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00048: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA" );
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
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00049: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00050: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00051: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00052: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00053: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "LucKmf108:69187 calling Scene00054: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmf108 );
