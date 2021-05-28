// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_7 = A6
//SCENE_8 = A6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmf105 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmf105() : Sapphire::ScriptAPI::EventScript( 69184 ){}; 
  ~LucKmf105() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 7 entries
  //SEQ_2, 8 entries
  //SEQ_3, 3 entries
  //SEQ_4, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1030336
  //ACTOR1 = 1030334
  //ACTOR10 = 1031592
  //ACTOR11 = 1031593
  //ACTOR12 = 1031594
  //ACTOR13 = 1030515
  //ACTOR14 = 1027757
  //ACTOR15 = 1030516
  //ACTOR16 = 1027758
  //ACTOR17 = 1030517
  //ACTOR2 = 1030335
  //ACTOR3 = 1030337
  //ACTOR4 = 1030338
  //ACTOR5 = 1030339
  //ACTOR6 = 1030514
  //ACTOR7 = 1031589
  //ACTOR8 = 1031590
  //ACTOR9 = 1031591
  //BINDACTOR01 = 7823474
  //BINDACTOR02 = 7935530
  //BINDACTOR03 = 7935531
  //BINDACTOR04 = 7935536
  //BINDACTOR05 = 7935537
  //BINDACTOR06 = 7935538
  //BINDACTOR07 = 7823472
  //ENEMY0 = 10316
  //EVENTACTION0 = 35
  //LOCACTION0 = 5665
  //LOCACTOR01 = 1026568
  //LOCACTOR02 = 1026567
  //LOCACTOR03 = 1026569
  //LOCACTOR04 = 1027137
  //LOCACTOR05 = 1026571
  //LOCACTOR06 = 1026570
  //LOCBGM01 = 71
  //POPRANGE0 = 8049639

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030336 || param2 == 1030336 ) // ACTOR0 = THANCRED
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030334 || param2 == 1030334 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030335 || param2 == 1030335 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030337 || param2 == 1030337 ) // ACTOR3 = RYNE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030338 || param2 == 1030338 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030339 || param2 == 1030339 ) // ACTOR5 = URIANGER
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1030514 || param2 == 1030514 ) // ACTOR6 = A6
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=A6
          }
          break;
        }
        if( param1 == 1031589 || param2 == 1031589 ) // ACTOR7 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031590 || param2 == 1031590 ) // ACTOR8 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1031591 || param2 == 1031591 ) // ACTOR9 = THANCRED
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1031592 || param2 == 1031592 ) // ACTOR10 = RYNE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1031593 || param2 == 1031593 ) // ACTOR11 = YSHTOLA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1031594 || param2 == 1031594 ) // ACTOR12 = URIANGER
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1030515 || param2 == 1030515 ) // ACTOR13 = MANOFONDO03648
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, FadeIn, TargetCanMove, Menu), id=MANOFONDO03648
          }
          break;
        }
        if( param1 == 1031589 || param2 == 1031589 ) // ACTOR7 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031590 || param2 == 1031590 ) // ACTOR8 = ALISAIE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1031591 || param2 == 1031591 ) // ACTOR9 = THANCRED
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1031592 || param2 == 1031592 ) // ACTOR10 = RYNE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1031593 || param2 == 1031593 ) // ACTOR11 = YSHTOLA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1031594 || param2 == 1031594 ) // ACTOR12 = URIANGER
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR14 = TOLSHSAATH
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=TOLSHSAATH
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1030516 || param2 == 1030516 ) // ACTOR15 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1027758 || param2 == 1027758 ) // ACTOR16 = PAUSHSOOAN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=PAUSHSOOAN
          break;
        }
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR14 = TOLSHSAATH
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=TOLSHSAATH
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 10316 || param2 == 10316 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq4( player );
          }
          break;
        }
        if( param1 == 1027758 || param2 == 1027758 ) // ACTOR16 = PAUSHSOOAN
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=PAUSHSOOAN
          break;
        }
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR14 = TOLSHSAATH
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=TOLSHSAATH
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1027758 || param2 == 1027758 ) // ACTOR16 = PAUSHSOOAN
        {
          Scene00028( player ); // Scene00028: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=PAUSHSOOAN
          break;
        }
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR14 = TOLSHSAATH
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=TOLSHSAATH
          break;
        }
        if( param1 == 1030517 || param2 == 1030517 ) // ACTOR17 = YSHTOLA
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=YSHTOLA
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
      player.updateQuest( getId(), 255 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmf105:69184 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00004: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00006: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=A6" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00011: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00012: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00014: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00015: Normal(Talk, FadeIn, TargetCanMove, Menu), id=MANOFONDO03648" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00018: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00019: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00020: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00021: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00022: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00024: Normal(Talk, TargetCanMove), id=PAUSHSOOAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00025: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }


  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00026: Normal(Talk, TargetCanMove), id=PAUSHSOOAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00027: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00028: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=PAUSHSOOAN" );
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
    player.playScene( getId(), 28, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00029: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmf105:69184 calling Scene00030: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmf105 );
