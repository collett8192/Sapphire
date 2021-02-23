// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmb117 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmb117() : Sapphire::ScriptAPI::EventScript( 68854 ){}; 
  ~LucKmb117() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 4 entries
  //SEQ_3, 11 entries
  //SEQ_4, 4 entries
  //SEQ_255, 4 entries

  //ACTIONTIMELINEEVENTFLYAWAY = 4265
  //ACTIONTIMELINEEVENTSING = 947
  //ACTOR0 = 1029577
  //ACTOR1 = 1029578
  //ACTOR2 = 1029579
  //ACTOR3 = 1027690
  //ACTOR4 = 1030874
  //ACTOR5 = 1029581
  //ACTOR6 = 1029582
  //ENEMY0 = 7948094
  //ENEMY1 = 7948095
  //ENEMY2 = 7948096
  //ENEMY3 = 7948097
  //ENEMY4 = 7948100
  //ENEMY5 = 7948101
  //ENEMY6 = 7948105
  //LOCACT01 = 5627
  //LOCACT02 = 4236
  //SEEVENTMOTHAMARO = 230

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029577 || param2 == 1029577 ) // ACTOR0 = URIANGER
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029578 || param2 == 1029578 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029579 || param2 == 1029579 ) // ACTOR2 = RYNE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1027690 || param2 == 1027690 ) // ACTOR3 = SETO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, TargetCanMove, Menu), id=SETO
          }
          break;
        }
        if( param1 == 1029577 || param2 == 1029577 ) // ACTOR0 = URIANGER
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029578 || param2 == 1029578 ) // ACTOR1 = THANCRED
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029579 || param2 == 1029579 ) // ACTOR2 = RYNE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1030874 || param2 == 1030874 ) // ACTOR4 = SETO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=SETO
          }
          break;
        }
        if( param1 == 1029577 || param2 == 1029577 ) // ACTOR0 = URIANGER
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029578 || param2 == 1029578 ) // ACTOR1 = THANCRED
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029579 || param2 == 1029579 ) // ACTOR2 = RYNE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1030874 || param2 == 1030874 ) // ACTOR4 = SETO
        {
          if( player.getQuestUI8AL( getId() ) != 7 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, Message, PopBNpc, TargetCanMove), id=SETO
          }
          break;
        }
        if( param1 == 7948094 || param2 == 7948094 ) // ENEMY0 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00014: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7948095 || param2 == 7948095 ) // ENEMY1 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00016: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7948096 || param2 == 7948096 ) // ENEMY2 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00018: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7948097 || param2 == 7948097 ) // ENEMY3 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7948100 || param2 == 7948100 ) // ENEMY4 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 7948101 || param2 == 7948101 ) // ENEMY5 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 7948105 || param2 == 7948105 ) // ENEMY6 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 1029577 || param2 == 1029577 ) // ACTOR0 = URIANGER
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029578 || param2 == 1029578 ) // ACTOR1 = THANCRED
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029579 || param2 == 1029579 ) // ACTOR2 = RYNE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1030874 || param2 == 1030874 ) // ACTOR4 = SETO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=SETO
          }
          break;
        }
        if( param1 == 1029577 || param2 == 1029577 ) // ACTOR0 = URIANGER
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029581 || param2 == 1029581 ) // ACTOR5 = THANCRED
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029582 || param2 == 1029582 ) // ACTOR6 = RYNE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1027690 || param2 == 1027690 ) // ACTOR3 = SETO
        {
          Scene00027( player ); // Scene00027: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SETO
          break;
        }
        if( param1 == 1029577 || param2 == 1029577 ) // ACTOR0 = URIANGER
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029581 || param2 == 1029581 ) // ACTOR5 = THANCRED
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029582 || param2 == 1029582 ) // ACTOR6 = RYNE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=RYNE
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
    if( player.getQuestUI8AL( getId() ) == 7 )
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
    player.sendDebug( "LucKmb117:68854 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmb117:68854 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00003: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove, Menu), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00005: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00006: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00007: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00008: Normal(Talk, TargetCanMove), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00009: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00010: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00011: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00012: Normal(Talk, Message, PopBNpc, TargetCanMove), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 7 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00015: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00016: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00017: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00018: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00019: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }




  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00020: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00021: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00022: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00024: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00025: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00026: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00027: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SETO" );
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
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00028: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00029: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmb117:68854 calling Scene00030: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmb117 );
