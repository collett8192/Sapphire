// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_11 = dummy
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil064 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil064() : Sapphire::ScriptAPI::EventScript( 65843 ){}; 
  ~SubWil064() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1001447
  //ENEMY0 = 3785130
  //ENEMY1 = 3785131
  //ENEMY2 = 3785134
  //EOBJECT0 = 2000268
  //ITEM0 = 2000212

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WARIN
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( actor == 2000268 || actorId == 2000268 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00001( player ); // Scene00001: Normal(Inventory), id=unknown
            // +Callback Scene00002: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 3785130 || actorId == 3785130 ) // ENEMY0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          // +Callback Scene00004: Normal(None), id=unknown
          // +Callback Scene00005: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 3785131 || actorId == 3785131 ) // ENEMY1 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          // +Callback Scene00007: Normal(None), id=unknown
          // +Callback Scene00008: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 3785134 || actorId == 3785134 ) // ENEMY2 = dummy
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          // +Callback Scene00010: Normal(None), id=unknown
          // +Callback Scene00011: Normal(Message, PopBNpc), id=dummy
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        Scene00012( player ); // Scene00012: Normal(None), id=unknown
        // +Callback Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WARIN
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WARIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling Scene00001: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling [BranchTrue]Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling Scene00003: Normal(None), id=unknown" );
    Scene00004( player );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling [BranchTrue]Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling [BranchChain]Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling [BranchChain]Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling [BranchTrue]Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling [BranchChain]Scene00011: Normal(Message, PopBNpc), id=dummy" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil064:65843 calling [BranchTrue]Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WARIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil064 );
