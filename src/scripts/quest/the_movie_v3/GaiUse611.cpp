// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_5 = SCIENTIST00423_2
//SCENE_14 = SCIENTIST00423_3
//SCENE_16 = SCIENTIST00423_4
//SCENE_25 = SCIENTIST00423_5
//SCENE_27 = SCIENTIST00423_6
//SCENE_40 = SCIENTIST00423_7
//SCENE_42 = SCIENTIST00423_8
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse611 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse611() : Sapphire::ScriptAPI::EventScript( 65959 ){}; 
  ~GaiUse611() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_4, 5 entries
  //SEQ_5, 1 entries
  //SEQ_6, 1 entries
  //SEQ_7, 5 entries
  //SEQ_8, 1 entries
  //SEQ_9, 1 entries
  //SEQ_10, 7 entries
  //SEQ_11, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1010897
  //ACTOR1 = 1011615
  //ACTOR2 = 1011616
  //ACTOR3 = 1010984
  //ACTOR4 = 1010985
  //ACTOR5 = 1010986
  //ACTOR6 = 1010987
  //ENEMY0 = 5607525
  //ENEMY1 = 5607526
  //ENEMY10 = 5607542
  //ENEMY2 = 5607527
  //ENEMY3 = 5607530
  //ENEMY4 = 5607531
  //ENEMY5 = 5607534
  //ENEMY6 = 5607537
  //ENEMY7 = 5607538
  //ENEMY8 = 5607540
  //ENEMY9 = 5607541
  //EOBJECT0 = 2005065
  //EOBJECT1 = 2005066
  //EOBJECT2 = 2005067
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONWATCHGUARDMIDDLE = 56
  //LOCACTOR0 = 5607561

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA
        break;
      }
      case 1:
      {
        if( actor == 1011615 || actorId == 1011615 ) // ACTOR1 = HOARYBOULDER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=HOARYBOULDER
          }
        }
        if( actor == 1011616 || actorId == 1011616 ) // ACTOR2 = COULTENET
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=COULTENET
        }
        break;
      }
      case 2:
      {
        Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423
        break;
      }
      case 3:
      {
        Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=SCIENTIST00423_2
        break;
      }
      case 4:
      {
        if( actor == 2005065 || actorId == 2005065 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
            // +Callback Scene00007: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 5607525 || actorId == 5607525 ) // ENEMY0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          // +Callback Scene00009: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 5607526 || actorId == 5607526 ) // ENEMY1 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          // +Callback Scene00011: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 5607527 || actorId == 5607527 ) // ENEMY2 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          // +Callback Scene00013: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 1010985 || actorId == 1010985 ) // ACTOR4 = SCIENTIST00423_3
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=SCIENTIST00423_3
        }
        break;
      }
      case 5:
      {
        Scene00015( player ); // Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423
        break;
      }
      case 6:
      {
        Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=SCIENTIST00423_4
        break;
      }
      case 7:
      {
        if( actor == 2005066 || actorId == 2005066 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00017( player ); // Scene00017: Normal(None), id=unknown
            // +Callback Scene00018: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 5607530 || actorId == 5607530 ) // ENEMY3 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          // +Callback Scene00020: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 5607531 || actorId == 5607531 ) // ENEMY4 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          // +Callback Scene00022: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 5607534 || actorId == 5607534 ) // ENEMY5 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          // +Callback Scene00024: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 1010986 || actorId == 1010986 ) // ACTOR5 = SCIENTIST00423_5
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=SCIENTIST00423_5
        }
        break;
      }
      case 8:
      {
        Scene00026( player ); // Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423
        break;
      }
      case 9:
      {
        Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=SCIENTIST00423_6
        break;
      }
      case 10:
      {
        if( actor == 2005067 || actorId == 2005067 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00028( player ); // Scene00028: Normal(None), id=unknown
            // +Callback Scene00029: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 5607537 || actorId == 5607537 ) // ENEMY6 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          // +Callback Scene00031: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 5607538 || actorId == 5607538 ) // ENEMY7 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          // +Callback Scene00033: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 5607540 || actorId == 5607540 ) // ENEMY8 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          // +Callback Scene00035: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 5607541 || actorId == 5607541 ) // ENEMY9 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          // +Callback Scene00037: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 5607542 || actorId == 5607542 ) // ENEMY10 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          // +Callback Scene00039: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 1010987 || actorId == 1010987 ) // ACTOR6 = SCIENTIST00423_7
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=SCIENTIST00423_7
        }
        break;
      }
      case 11:
      {
        Scene00041( player ); // Scene00041: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423
        break;
      }
      case 255:
      {
        Scene00042( player ); // Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SCIENTIST00423_8
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
    onProgress( player, param1, param1, 3, param1 );
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
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 6 );
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    player.updateQuest( getId(), 7 );
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 8 );
    }
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    player.updateQuest( getId(), 9 );
  }
  void checkProgressSeq9( Entity::Player& player )
  {
    player.updateQuest( getId(), 10 );
  }
  void checkProgressSeq10( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 5 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 11 );
    }
  }
  void checkProgressSeq11( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00003: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00005: Normal(Talk, TargetCanMove), id=SCIENTIST00423_2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00014: Normal(Talk, TargetCanMove), id=SCIENTIST00423_3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00016: Normal(Talk, TargetCanMove), id=SCIENTIST00423_4" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00017: Normal(None), id=unknown" );
    Scene00018( player );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00018: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00019: Normal(None), id=unknown" );
    Scene00020( player );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00020: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00021: Normal(None), id=unknown" );
    Scene00022( player );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00022: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00023: Normal(None), id=unknown" );
    Scene00024( player );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00024: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00025: Normal(Talk, TargetCanMove), id=SCIENTIST00423_5" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00027: Normal(Talk, TargetCanMove), id=SCIENTIST00423_6" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq9( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00028: Normal(None), id=unknown" );
    Scene00029( player );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00029: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 5 );
      checkProgressSeq10( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00030: Normal(None), id=unknown" );
    Scene00031( player );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00031: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq10( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00032: Normal(None), id=unknown" );
    Scene00033( player );
  }
  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00033: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq10( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00034: Normal(None), id=unknown" );
    Scene00035( player );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00035: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq10( player );
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00036: Normal(None), id=unknown" );
    Scene00037( player );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00037: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq10( player );
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00038: Normal(None), id=unknown" );
    Scene00039( player );
  }
  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling [BranchTrue]Scene00039: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq10( player );
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00040: Normal(Talk, TargetCanMove), id=SCIENTIST00423_7" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00041: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq11( player );
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SCIENTIST00423_8" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 42, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse611 );
