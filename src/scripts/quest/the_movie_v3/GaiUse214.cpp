// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse214 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse214() : Sapphire::ScriptAPI::EventScript( 66894 ){}; 
  ~GaiUse214() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 7 entries
  //SEQ_3, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006614
  //ACTOR1 = 1008683
  //ACTOR2 = 1008684
  //ACTOR3 = 1008685
  //ENEMY0 = 4628586
  //ENEMY1 = 4628587
  //ENEMY2 = 4628588
  //EOBJECT0 = 2003590
  //EVENTRANGE0 = 4628585
  //EVENTACTIONPROCESSLONG = 17
  //EVENTACTIONPROCESSMIDDLE = 16
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001214
  //ITEM1 = 2001215

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FALKBRYDA
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( actor == 1008683 || actorId == 1008683 ) // ACTOR1 = FALKBRYDA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, Inventory, TargetCanMove), id=FALKBRYDA
            // +Callback Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=FALKBRYDA
          }
          else
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=FALKBRYDA
          }
        }
        if( actor == 1006614 || actorId == 1006614 ) // ACTOR0 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 4628585 || actorId == 4628585 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
          }
        }
        if( actor == 4628586 || actorId == 4628586 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4628587 || actorId == 4628587 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 4628588 || actorId == 4628588 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 2003590 || actorId == 2003590 ) // EOBJECT0 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          // +Callback Scene00008: Normal(None), id=unknown
        }
        if( actor == 1008684 || actorId == 1008684 ) // ACTOR2 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          // +Callback Scene00010: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 1008685 || actorId == 1008685 ) // ACTOR3 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
        }
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack 2
      case 3:
      {
        if( actor == 1008684 || actorId == 1008684 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
          }
        }
        if( actor == 1008685 || actorId == 1008685 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00013( player ); // Scene00013: Normal(None), id=unknown
            // +Callback Scene00014: Normal(None), id=unknown
          }
          else
          {
            Scene00015( player ); // Scene00015: Normal(None), id=unknown
          }
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 2
      case 255:
      {
        Scene00016( player ); // Scene00016: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FALKBRYDA
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
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
      if( player.getQuestUI8AL( getId() ) == 2 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 255 );
        player.setQuestUI8BH( getId(), 2 );
      }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse214:66894 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling Scene00002: Normal(Talk, Inventory, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling [BranchTrue]Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling [BranchFalse]Scene00004: Normal(Talk, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling Scene00006: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 3 );
    checkProgressSeq2( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling [BranchTrue]Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling Scene00013: Normal(None), id=unknown" );
    Scene00014( player );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling [BranchTrue]Scene00014: Normal(None), id=unknown" );
    Scene00015( player );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling [BranchFalse]Scene00015: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling Scene00016: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00017( player );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse214:66894 calling [BranchTrue]Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse214 );
