// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda207 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda207() : Sapphire::ScriptAPI::EventScript( 68012 ){}; 
  ~StmBda207() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 2 entries
  //SEQ_2, 8 entries
  //SEQ_3, 5 entries
  //SEQ_255, 9 entries

  //ACTIONTIMELINEEVENTJPBOW = 1062
  //ACTOR0 = 1020484
  //ACTOR1 = 1020481
  //ACTOR10 = 1020452
  //ACTOR11 = 1020464
  //ACTOR12 = 1020466
  //ACTOR13 = 1019891
  //ACTOR14 = 1019888
  //ACTOR15 = 1019889
  //ACTOR16 = 1019890
  //ACTOR2 = 1020482
  //ACTOR3 = 1020483
  //ACTOR4 = 1020465
  //ACTOR5 = 1020490
  //ACTOR6 = 1020491
  //ACTOR7 = 1020485
  //ACTOR8 = 1020488
  //ACTOR9 = 1020451
  //BINDACTOR0 = 6843880
  //BINDACTOR1 = 6843881
  //BINDACTOR2 = 6843879
  //BINDACTOR3 = 6875110
  //BINDACTOR4 = 6848150
  //BINDACTOR5 = 6880137
  //BINDACTOR6 = 6843927
  //CUTSCENEN01 = 1408
  //EOBJECT0 = 2008177
  //LOCACTOR0 = 1018509
  //LOCACTOR1 = 1011887
  //LOCACTOR2 = 1019541
  //LOCACTOR3 = 1019084
  //LOCACTOR4 = 1019085
  //LOCACTOR5 = 1019548
  //LOCACTOR6 = 1008182
  //LOCACTOR7 = 1019710
  //LOCBGMTOHO = 465
  //LOCOTONA = 4295
  //LOCPOSLYSE001 = 6949435
  //LOCSEDOOR = 39
  //LOCSEDOORCLOSE = 40
  //POPRANGE0 = 6938534
  //POPRANGE1 = 6881549
  //TERRITORYTYPE0 = 639
  //TERRITORYTYPE1 = 613

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020484 || param2 == 1020484 ) // ACTOR0 = GOSETSU
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1020481 || param2 == 1020481 ) // ACTOR1 = HANCOCK
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HANCOCK
        }
        if( param1 == 1020482 || param2 == 1020482 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020483 || param2 == 1020483 ) // ACTOR3 = LYSE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020465 || param2 == 1020465 ) // ACTOR4 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020490 || param2 == 1020490 ) // ACTOR5 = GYODO
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=GYODO
        }
        if( param1 == 1020491 || param2 == 1020491 ) // ACTOR6 = SEKISHINTAISOLDIER
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=SEKISHINTAISOLDIER
        }
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00008( player ); // Scene00008: Normal(Talk, FadeIn), id=unknown
        }
        if( param1 == 1020491 || param2 == 1020491 ) // ACTOR6 = SEKISHINTAISOLDIER
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=SEKISHINTAISOLDIER
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020485 || param2 == 1020485 ) // ACTOR7 = SOROBAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove, Menu), id=SOROBAN
          }
        }
        if( param1 == 1020488 || param2 == 1020488 ) // ACTOR8 = GOSETSU
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1020451 || param2 == 1020451 ) // ACTOR9 = ALISAIE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020452 || param2 == 1020452 ) // ACTOR10 = LYSE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020465 || param2 == 1020465 ) // ACTOR4 = ALPHINAUD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020464 || param2 == 1020464 ) // ACTOR11 = HANCOCK
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=HANCOCK
        }
        if( param1 == 1020466 || param2 == 1020466 ) // ACTOR12 = TATARU
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1020490 || param2 == 1020490 ) // ACTOR5 = GYODO
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=GYODO
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00018( player ); // Scene00018: Normal(CutScene), id=unknown
        }
        if( param1 == 1020464 || param2 == 1020464 ) // ACTOR11 = HANCOCK
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=HANCOCK
        }
        if( param1 == 1020465 || param2 == 1020465 ) // ACTOR4 = ALPHINAUD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020466 || param2 == 1020466 ) // ACTOR12 = TATARU
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1020490 || param2 == 1020490 ) // ACTOR5 = GYODO
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=GYODO
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019891 || param2 == 1019891 ) // ACTOR13 = SOROBAN
        {
          Scene00023( player ); // Scene00023: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SOROBAN
        }
        if( param1 == 1019888 || param2 == 1019888 ) // ACTOR14 = LYSE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019889 || param2 == 1019889 ) // ACTOR15 = ALISAIE
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019890 || param2 == 1019890 ) // ACTOR16 = GOSETSU
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 2008177 || param2 == 2008177 ) // EOBJECT0 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
        }
        if( param1 == 1020464 || param2 == 1020464 ) // ACTOR11 = HANCOCK
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=HANCOCK
        }
        if( param1 == 1020465 || param2 == 1020465 ) // ACTOR4 = ALPHINAUD
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020466 || param2 == 1020466 ) // ACTOR12 = TATARU
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1020490 || param2 == 1020490 ) // ACTOR5 = GYODO
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=GYODO
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda207:68012 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00002: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00006: Normal(Talk, TargetCanMove), id=GYODO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00007: Normal(Talk, TargetCanMove), id=SEKISHINTAISOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00008: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00009: Normal(Talk, TargetCanMove), id=SEKISHINTAISOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00010: Normal(Talk, TargetCanMove, Menu), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 613, 825.88, 5.924, 854.36, -2.345, false );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00011: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00015: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00016: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00017: Normal(Talk, TargetCanMove), id=GYODO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00018: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00019: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00021: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00022: Normal(Talk, TargetCanMove), id=GYODO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00023: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00024: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00026: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00028: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00030: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda207:68012 calling Scene00031: Normal(Talk, TargetCanMove), id=GYODO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda207 );
