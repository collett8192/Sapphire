// FFXIVTheMovie.ParserV3
// id hint used:
//ACTOR1 = REFUGEE01444
//ACTOR2 = null
//ACTOR3 = null
//ACTOR4 = null
//ACTOR5 = null
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse303 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse303() : Sapphire::ScriptAPI::EventScript( 66980 ){}; 
  ~GaiUse303() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 13 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_4, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1009049
  //ACTOR1 = 1009050
  //ACTOR2 = 1009051
  //ACTOR3 = 1009052
  //ACTOR4 = 1009053
  //ACTOR5 = 1009054
  //ACTOR6 = 1009055
  //ACTOR7 = 1004576
  //ENEMY0 = 4841637
  //ENEMY1 = 4841638
  //ENEMY2 = 4841640
  //ENEMY3 = 4841641
  //ENEMY4 = 4841642
  //ENEMY5 = 4841643
  //ENEMY6 = 4841644
  //EVENTACTIONSEARCH = 1

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TREMBLEMAN01443
        break;
      }
      case 1:
      {
        if( actor == 1009050 || actorId == 1009050 ) // ACTOR1 = REFUGEE01444
        {
          if( player.getQuestUI8AL( getId() ) != 7 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, Message, PopBNpc, TargetCanMove), id=REFUGEE01444
          }
        }
        if( actor == 4841637 || actorId == 4841637 ) // ENEMY0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 4841638 || actorId == 4841638 ) // ENEMY1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 4841640 || actorId == 4841640 ) // ENEMY2 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 4841641 || actorId == 4841641 ) // ENEMY3 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 4841642 || actorId == 4841642 ) // ENEMY4 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 4841643 || actorId == 4841643 ) // ENEMY5 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 4841644 || actorId == 4841644 ) // ENEMY6 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 1009049 || actorId == 1009049 ) // ACTOR0 = TREMBLEMAN01443
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=TREMBLEMAN01443
        }
        if( actor == 1009051 || actorId == 1009051 ) // ACTOR2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 1009052 || actorId == 1009052 ) // ACTOR3 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( actor == 1009053 || actorId == 1009053 ) // ACTOR4 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 1009054 || actorId == 1009054 ) // ACTOR5 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 1009050 || actorId == 1009050 ) // ACTOR1 = REFUGEE01444
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=REFUGEE01444
          }
        }
        if( actor == 1009049 || actorId == 1009049 ) // ACTOR0 = TREMBLEMAN01443
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=TREMBLEMAN01443
        }
        if( actor == 1009051 || actorId == 1009051 ) // ACTOR2 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( actor == 1009052 || actorId == 1009052 ) // ACTOR3 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        if( actor == 1009053 || actorId == 1009053 ) // ACTOR4 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( actor == 1009054 || actorId == 1009054 ) // ACTOR5 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( actor == 1009049 || actorId == 1009049 ) // ACTOR0 = TREMBLEMAN01443
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk, NpcDespawn, TargetCanMove), id=TREMBLEMAN01443
          }
        }
        if( actor == 1009050 || actorId == 1009050 ) // ACTOR1 = REFUGEE01444
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=REFUGEE01444
        }
        if( actor == 1009051 || actorId == 1009051 ) // ACTOR2 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        if( actor == 1009052 || actorId == 1009052 ) // ACTOR3 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
        }
        if( actor == 1009053 || actorId == 1009053 ) // ACTOR4 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
        }
        if( actor == 1009054 || actorId == 1009054 ) // ACTOR5 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
        }
        break;
      }
      case 4:
      {
        Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ELE
        break;
      }
      case 255:
      {
        if( actor == 1004576 || actorId == 1004576 ) // ACTOR7 = SWIFT
        {
          Scene00028( player ); // Scene00028: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SWIFT
        }
        if( actor == 1009055 || actorId == 1009055 ) // ACTOR6 = ELE
        {
          Scene00029( player ); // Scene00029: Normal(Talk), id=ELE
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
    onProgress( player, param1, param1, 3, param1 );
  }

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 7 )
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
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse303:66980 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TREMBLEMAN01443" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00002: Normal(Talk, Message, PopBNpc, TargetCanMove), id=REFUGEE01444" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 7 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00004: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00010: Normal(Talk, TargetCanMove), id=TREMBLEMAN01443" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00015: Normal(Talk, TargetCanMove), id=REFUGEE01444" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00016: Normal(Talk, TargetCanMove), id=TREMBLEMAN01443" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00021: Normal(Talk, NpcDespawn, TargetCanMove), id=TREMBLEMAN01443" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00022: Normal(Talk, TargetCanMove), id=REFUGEE01444" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00027: Normal(Talk, TargetCanMove), id=ELE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00028: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SWIFT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse303:66980 calling Scene00029: Normal(Talk), id=ELE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse303 );
