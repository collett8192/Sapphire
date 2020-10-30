// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda139 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda139() : Sapphire::ScriptAPI::EventScript( 68005 ){}; 
  ~StmBda139() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 6 entries
  //SEQ_3, 5 entries
  //SEQ_4, 8 entries
  //SEQ_5, 3 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1020436
  //ACTOR1 = 1020439
  //ACTOR10 = 5010000
  //ACTOR11 = 1020443
  //ACTOR12 = 1020444
  //ACTOR13 = 1020445
  //ACTOR14 = 1020454
  //ACTOR15 = 1020450
  //ACTOR16 = 1020451
  //ACTOR17 = 1020452
  //ACTOR18 = 1020453
  //ACTOR19 = 1021740
  //ACTOR2 = 1020396
  //ACTOR3 = 1020014
  //ACTOR4 = 1020441
  //ACTOR5 = 1020442
  //ACTOR6 = 1020447
  //ACTOR7 = 1020448
  //ACTOR8 = 1020449
  //ACTOR9 = 1023076
  //CUTSCENEN01 = 1398
  //CUTSCENEN02 = 1399
  //CUTSCENEN03 = 1400
  //CUTSCENEN04 = 1401
  //INSTANCEDUNGEON0 = 52
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019541
  //LOCACTOR03 = 1018509
  //LOCACTOR04 = 1003785
  //LOCACTOR05 = 1019542
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //POPRANGE0 = 6848086
  //POPRANGE1 = 6848154
  //SCREENIMAGE0 = 491
  //TERRITORYTYPE0 = 680
  //TERRITORYTYPE1 = 628

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LYSE
        break;
      }
      case 1:
      {
        if( param1 == 1020439 || param2 == 1020439 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1020396 || param2 == 1020396 ) // ACTOR2 = TATARU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1020014 || param2 == 1020014 ) // ACTOR3 = ALISAIE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020441 || param2 == 1020441 ) // ACTOR4 = LYSE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020442 || param2 == 1020442 ) // ACTOR5 = KRAKENSDECKHAND
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00007( player ); // Scene00007: Normal(CutScene), id=unknown
        }
        if( param1 == 1020442 || param2 == 1020442 ) // ACTOR5 = KRAKENSDECKHAND
        {
          Scene00008( player ); // Scene00008: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND
        }
        if( param1 == 1020396 || param2 == 1020396 ) // ACTOR2 = TATARU
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1020439 || param2 == 1020439 ) // ACTOR1 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020014 || param2 == 1020014 ) // ACTOR3 = ALISAIE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020441 || param2 == 1020441 ) // ACTOR4 = LYSE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020447 || param2 == 1020447 ) // ACTOR6 = CARVALLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, FadeIn, TargetCanMove), id=CARVALLAIN
          }
        }
        if( param1 == 1020442 || param2 == 1020442 ) // ACTOR5 = KRAKENSDECKHAND
        {
          Scene00014( player ); // Scene00014: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND
        }
        if( param1 == 1020448 || param2 == 1020448 ) // ACTOR7 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( param1 == 1020449 || param2 == 1020449 ) // ACTOR8 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( param1 == 1023076 || param2 == 1023076 ) // ACTOR9 = KRAKENSDECKHAND
        {
          Scene00017( player ); // Scene00017: Normal(Talk), id=KRAKENSDECKHAND
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020442 || param2 == 1020442 ) // ACTOR5 = KRAKENSDECKHAND
        {
          Scene00018( player ); // Scene00018: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND
        }
        if( param1 == 1020443 || param2 == 1020443 ) // ACTOR11 = ALPHINAUD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020444 || param2 == 1020444 ) // ACTOR12 = ALISAIE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020445 || param2 == 1020445 ) // ACTOR13 = LYSE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020447 || param2 == 1020447 ) // ACTOR6 = CARVALLAIN
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=CARVALLAIN
        }
        if( param1 == 1023076 || param2 == 1023076 ) // ACTOR9 = KRAKENSDECKHAND
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND
        }
        if( param1 == 1020448 || param2 == 1020448 ) // ACTOR7 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
        }
        if( param1 == 1020449 || param2 == 1020449 ) // ACTOR8 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
        }
        break;
      }
      case 5:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00026( player ); // Scene00026: Normal(CutScene), id=unknown
        }
        if( param1 == 1020442 || param2 == 1020442 ) // ACTOR5 = KRAKENSDECKHAND
        {
          Scene00027( player ); // Scene00027: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND
        }
        if( param1 == 1023076 || param2 == 1023076 ) // ACTOR9 = KRAKENSDECKHAND
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020454 || param2 == 1020454 ) // ACTOR14 = CARVALLAIN
        {
          Scene00029( player ); // Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CARVALLAIN
        }
        if( param1 == 1020450 || param2 == 1020450 ) // ACTOR15 = ALPHINAUD
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020451 || param2 == 1020451 ) // ACTOR16 = ALISAIE
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020452 || param2 == 1020452 ) // ACTOR17 = LYSE
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020453 || param2 == 1020453 ) // ACTOR18 = TATARU
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1021740 || param2 == 1021740 ) // ACTOR19 = KRAKENSDECKHAND
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND
        }
        if( param1 == 1020442 || param2 == 1020442 ) // ACTOR5 = KRAKENSDECKHAND
        {
          Scene00035( player ); // Scene00035: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda139:68005 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00005: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00006: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00007: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00008: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 680 );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00009: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00012: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00013: Normal(Talk, FadeIn, TargetCanMove), id=CARVALLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00014: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 680 );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00017: Normal(Talk), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00018: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 680 );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00021: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00022: Normal(Talk, TargetCanMove), id=CARVALLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 628, -130.2, -7, -59, 1.57, false );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00023: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00026: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00027: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 680 );
      }
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00028: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CARVALLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00031: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00032: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00033: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00034: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda139:68005 calling Scene00035: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 35, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda139 );
