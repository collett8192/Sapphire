// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda415 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda415() : Sapphire::ScriptAPI::EventScript( 68050 ){}; 
  ~StmBda415() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_255, 12 entries

  //ACTOR0 = 1021628
  //ACTOR1 = 1021627
  //ACTOR10 = 1020539
  //ACTOR11 = 1021633
  //ACTOR12 = 1021631
  //ACTOR13 = 1021632
  //ACTOR14 = 1019382
  //ACTOR15 = 1021634
  //ACTOR16 = 1021636
  //ACTOR17 = 1021637
  //ACTOR18 = 1021638
  //ACTOR2 = 1022076
  //ACTOR3 = 1019417
  //ACTOR4 = 1021731
  //ACTOR5 = 1022078
  //ACTOR6 = 1019431
  //ACTOR7 = 1021630
  //ACTOR8 = 1021605
  //ACTOR9 = 1021629
  //BINDGOUSETSU002 = 6865741
  //BINDLISE001 = 6870959
  //LOCBGMGEKITKI = 485
  //LOCBGMYUSO = 459
  //LOCBINDBAATU = 6887824
  //LOCBINDGOUSETSU = 6872468
  //LOCHIEN = 1019544
  //LOCLISE = 1018509
  //LOCMAGUNAIWEP = 2008349
  //LOCMAGUNAIWEPPOS = 7021939
  //POPRANGE0 = 6997740

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1021628 || param2 == 1021628 ) // ACTOR0 = GOSETSU
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021627 || param2 == 1021627 ) // ACTOR1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(None), id=unknown
          break;
        }
        if( param1 == 1022076 || param2 == 1022076 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR3 = MAGNAI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=MAGNAI
          }
          break;
        }
        if( param1 == 1021731 || param2 == 1021731 ) // ACTOR4 = GOSETSU
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021627 || param2 == 1021627 ) // ACTOR1 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1022076 || param2 == 1022076 ) // ACTOR2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1022078 || param2 == 1022078 ) // ACTOR5 = BAATU
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=BAATU
          break;
        }
        if( param1 == 1019431 || param2 == 1019431 ) // ACTOR6 = DAIDUKUL
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=DAIDUKUL
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1021630 || param2 == 1021630 ) // ACTOR7 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1021605 || param2 == 1021605 ) // ACTOR8 = GOSETSU
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021629 || param2 == 1021629 ) // ACTOR9 = LYSE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR3 = MAGNAI
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=MAGNAI
          break;
        }
        if( param1 == 1022078 || param2 == 1022078 ) // ACTOR5 = BAATU
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=BAATU
          break;
        }
        if( param1 == 1019431 || param2 == 1019431 ) // ACTOR6 = DAIDUKUL
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=DAIDUKUL
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR10 = CIRINA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021633 || param2 == 1021633 ) // ACTOR11 = HIEN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021631 || param2 == 1021631 ) // ACTOR12 = GOSETSU
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021632 || param2 == 1021632 ) // ACTOR13 = LYSE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR14 = TEMULUN
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1021634 || param2 == 1021634 ) // ACTOR15 = MOLA02514
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=MOLA02514
          break;
        }
        if( param1 == 1021636 || param2 == 1021636 ) // ACTOR16 = MOLC02514
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 || param2 == 1021637 ) // ACTOR17 = MOLD02514
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 || param2 == 1021638 ) // ACTOR18 = MOLE02514
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        if( param1 == 1019431 || param2 == 1019431 ) // ACTOR6 = DAIDUKUL
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=DAIDUKUL
          break;
        }
        if( param1 == 1022078 || param2 == 1022078 ) // ACTOR5 = BAATU
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=BAATU
          break;
        }
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR3 = MAGNAI
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=MAGNAI
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda415:68050 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00002: Normal(None), id=unknown" );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=MAGNAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00005: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00008: Normal(Talk, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00009: Normal(Talk, TargetCanMove), id=DAIDUKUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00011: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00012: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00013: Normal(Talk, TargetCanMove), id=MAGNAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00014: Normal(Talk, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00015: Normal(Talk, TargetCanMove), id=DAIDUKUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CIRINA" );
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
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00017: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00018: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00019: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00020: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00021: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00022: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00023: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00024: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00025: Normal(Talk, TargetCanMove), id=DAIDUKUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00026: Normal(Talk, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda415:68050 calling Scene00027: Normal(Talk, TargetCanMove), id=MAGNAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda415 );
