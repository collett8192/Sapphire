// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmb113 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmb113() : Sapphire::ScriptAPI::EventScript( 68850 ){}; 
  ~LucKmb113() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 4 entries
  //SEQ_2, 5 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1029564
  //ACTOR1 = 1029569
  //ACTOR2 = 1029570
  //ACTOR3 = 1029571
  //ACTOR4 = 1029572
  //ENEMY0 = 10255
  //ITEM0 = 2002537
  //LOCACT01 = 5627

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029564 || param2 == 1029564 ) // ACTOR0 = WYDAENC
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=WYDAENC
          break;
        }
        if( param1 == 1029569 || param2 == 1029569 ) // ACTOR1 = URIANGER
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029570 || param2 == 1029570 ) // ACTOR2 = THANCRED
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029571 || param2 == 1029571 ) // ACTOR3 = RYNE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029572 || param2 == 1029572 ) // ACTOR4 = MARNOSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MARNOSE
          }
          break;
        }
        if( param1 == 1029569 || param2 == 1029569 ) // ACTOR1 = URIANGER
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029570 || param2 == 1029570 ) // ACTOR2 = THANCRED
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029571 || param2 == 1029571 ) // ACTOR3 = RYNE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 2
      case 2:
      {
        if( param1 == 10255 || param2 == 10255 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
            checkProgressSeq2( player );
          }
          break;
        }
        if( param1 == 1029569 || param2 == 1029569 ) // ACTOR1 = URIANGER
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029570 || param2 == 1029570 ) // ACTOR2 = THANCRED
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029571 || param2 == 1029571 ) // ACTOR3 = RYNE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029572 || param2 == 1029572 ) // ACTOR4 = MARNOSE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MARNOSE
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( param1 == 1029572 || param2 == 1029572 ) // ACTOR4 = MARNOSE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, SystemTalk), id=MARNOSE
          break;
        }
        if( param1 == 1029569 || param2 == 1029569 ) // ACTOR1 = URIANGER
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029570 || param2 == 1029570 ) // ACTOR2 = THANCRED
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029571 || param2 == 1029571 ) // ACTOR3 = RYNE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=RYNE
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
      //player.updateQuest( getId(), 2 );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 2 )
    {
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmb113:68850 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=WYDAENC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00002: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00003: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00004: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00005: Normal(Talk, TargetCanMove), id=MARNOSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00006: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00007: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00008: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }


  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00009: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00010: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00011: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00012: Normal(Talk, TargetCanMove), id=MARNOSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, SystemTalk), id=MARNOSE" );
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
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00014: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00015: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmb113:68850 calling Scene00016: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmb113 );
