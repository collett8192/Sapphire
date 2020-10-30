// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda133 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda133() : Sapphire::ScriptAPI::EventScript( 67999 ){}; 
  ~StmBda133() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 7 entries
  //SEQ_2, 1 entries
  //SEQ_255, 23 entries

  //ACTOR0 = 1020354
  //ACTOR1 = 1020525
  //ACTOR10 = 1020411
  //ACTOR11 = 1020190
  //ACTOR12 = 1020412
  //ACTOR13 = 1020419
  //ACTOR14 = 1020414
  //ACTOR15 = 1020415
  //ACTOR16 = 1020417
  //ACTOR17 = 1020420
  //ACTOR18 = 1020416
  //ACTOR19 = 1019965
  //ACTOR2 = 1020526
  //ACTOR20 = 1019471
  //ACTOR21 = 1019472
  //ACTOR22 = 1019476
  //ACTOR23 = 1019477
  //ACTOR24 = 1019479
  //ACTOR25 = 1019481
  //ACTOR26 = 1019483
  //ACTOR27 = 1019484
  //ACTOR28 = 1019486
  //ACTOR29 = 1019488
  //ACTOR3 = 1020392
  //ACTOR30 = 1019489
  //ACTOR31 = 1019490
  //ACTOR4 = 1020393
  //ACTOR5 = 1020399
  //ACTOR6 = 1020397
  //ACTOR7 = 1020398
  //ACTOR8 = 1020304
  //ACTOR9 = 1020400
  //BGMSWITCHREWARD = 371
  //BINDACTOR01 = 6844562
  //BINDACTOR02 = 6844563
  //CUTSCENEN01 = 1391
  //CUTSCENEN02 = 1392
  //CUTSCENEN03 = 1393
  //CUTSCENEN04 = 1395
  //CUTSCENEN05 = 1396
  //EOBJECT0 = 2008179
  //QUESTBATTLE0 = 155
  //TERRITORYTYPE0 = 659
  //TERRITORYTYPE1 = 635

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020354 || param2 == 1020354 ) // ACTOR0 = PIPIN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PIPIN
        }
        if( param1 == 1020525 || param2 == 1020525 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020526 || param2 == 1020526 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020392 || param2 == 1020392 ) // ACTOR3 = SERPENTOFFICER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
        }
        if( param1 == 1020393 || param2 == 1020393 ) // ACTOR4 = STORMOFFICER
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=STORMOFFICER
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020399 || param2 == 1020399 ) // ACTOR5 = PIPIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=PIPIN
            // +Callback Scene00007: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1020397 || param2 == 1020397 ) // ACTOR6 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020398 || param2 == 1020398 ) // ACTOR7 = ALISAIE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020304 || param2 == 1020304 ) // ACTOR8 = RAUBAHN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=RAUBAHN
        }
        if( param1 == 1020392 || param2 == 1020392 ) // ACTOR3 = SERPENTOFFICER
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
        }
        if( param1 == 1020393 || param2 == 1020393 ) // ACTOR4 = STORMOFFICER
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=STORMOFFICER
        }
        if( param1 == 2008179 || param2 == 2008179 ) // EOBJECT0 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00014( player ); // Scene00014: Normal(CutScene), id=unknown
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020400 || param2 == 1020400 ) // ACTOR9 = RAUBAHN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN
        }
        if( param1 == 1020411 || param2 == 1020411 ) // ACTOR10 = MEFFRID
        {
          Scene00016( player ); // Scene00016: Normal(Talk), id=MEFFRID
        }
        if( param1 == 1020190 || param2 == 1020190 ) // ACTOR11 = WISCAR
        {
          Scene00017( player ); // Scene00017: Normal(Talk), id=WISCAR
        }
        if( param1 == 1020412 || param2 == 1020412 ) // ACTOR12 = ALPHINAUD
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020419 || param2 == 1020419 ) // ACTOR13 = ALISAIE
        {
          Scene00019( player ); // Scene00019: Normal(Talk), id=ALISAIE
        }
        if( param1 == 1020414 || param2 == 1020414 ) // ACTOR14 = LYSE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020415 || param2 == 1020415 ) // ACTOR15 = YSHTOLA
        {
          Scene00021( player ); // Scene00021: Normal(Talk), id=YSHTOLA
        }
        if( param1 == 1020417 || param2 == 1020417 ) // ACTOR16 = KRILE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1020420 || param2 == 1020420 ) // ACTOR17 = PIPIN
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=PIPIN
        }
        if( param1 == 1020416 || param2 == 1020416 ) // ACTOR18 = CONRAD
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=CONRAD
        }
        if( param1 == 1019965 || param2 == 1019965 ) // ACTOR19 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
        }
        if( param1 == 1019471 || param2 == 1019471 ) // ACTOR20 = TEBBE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=TEBBE
        }
        if( param1 == 1019472 || param2 == 1019472 ) // ACTOR21 = CARMA
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=CARMA
        }
        if( param1 == 1019476 || param2 == 1019476 ) // ACTOR22 = AHELISSA
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=AHELISSA
        }
        if( param1 == 1019477 || param2 == 1019477 ) // ACTOR23 = RANULF
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=RANULF
        }
        if( param1 == 1019479 || param2 == 1019479 ) // ACTOR24 = ORTWIN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=ORTWIN
        }
        if( param1 == 1019481 || param2 == 1019481 ) // ACTOR25 = MATHILD
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=MATHILD
        }
        if( param1 == 1019483 || param2 == 1019483 ) // ACTOR26 = ODILA
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ODILA
        }
        if( param1 == 1019484 || param2 == 1019484 ) // ACTOR27 = DHANNA
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=DHANNA
        }
        if( param1 == 1019486 || param2 == 1019486 ) // ACTOR28 = ORELLA
        {
          Scene00034( player ); // Scene00034: Normal(Talk), id=ORELLA
        }
        if( param1 == 1019488 || param2 == 1019488 ) // ACTOR29 = EMMET
        {
          Scene00035( player ); // Scene00035: Normal(Talk), id=EMMET
        }
        if( param1 == 1019489 || param2 == 1019489 ) // ACTOR30 = BERINHARD
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=BERINHARD
        }
        if( param1 == 1019490 || param2 == 1019490 ) // ACTOR31 = HUGHOC
        {
          Scene00037( player ); // Scene00037: Normal(Talk), id=HUGHOC
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda133:67999 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00005: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00006: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 != 50 )
      {
        Scene00007( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling [BranchTrue]Scene00007: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      //player.setQuestUI8AL( getId(), 1 );
      //checkProgressSeq1( player );
      Scene00014( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00010: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00011: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00012: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00014: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 635, 68.31, 0, -77.65, 1.04, false );
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00016: Normal(Talk), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00017: Normal(Talk), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00019: Normal(Talk), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00020: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00021: Normal(Talk), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00022: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00023: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00024: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00026: Normal(Talk, TargetCanMove), id=TEBBE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00027: Normal(Talk, TargetCanMove), id=CARMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00028: Normal(Talk, TargetCanMove), id=AHELISSA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00029: Normal(Talk, TargetCanMove), id=RANULF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00030: Normal(Talk, TargetCanMove), id=ORTWIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00031: Normal(Talk, TargetCanMove), id=MATHILD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00032: Normal(Talk, TargetCanMove), id=ODILA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00033: Normal(Talk, TargetCanMove), id=DHANNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00034: Normal(Talk), id=ORELLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00035: Normal(Talk), id=EMMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00036: Normal(Talk, TargetCanMove), id=BERINHARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda133:67999 calling Scene00037: Normal(Talk), id=HUGHOC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda133 );
