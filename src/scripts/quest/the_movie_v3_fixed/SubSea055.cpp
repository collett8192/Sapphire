// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea055 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea055() : Sapphire::ScriptAPI::EventScript( 66003 ){}; 
  ~SubSea055() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002627
  //ACTOR1 = 1002629
  //ACTOR2 = 1002631
  //EOBJECT0 = 2001237
  //EOBJECT1 = 2001238
  //EOBJECT2 = 2001239
  //EVENTACTIONPROCESSMIDDLE = 16
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000347

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=GURCANT
        break;
      }
      case 1:
      {
        Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=RHOTWYDA
        break;
      }
      //seq 2 event item ITEM0 = UI8CH max stack 3
      case 2:
      {
        if( actor == 2001237 || actorId == 4298896562 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
            // +Callback Scene00100: Normal(None), id=unknown
          }
          else
          {
            Scene00099( player ); // Scene00099: Normal(None), id=unknown
          }
        }
        if( actor == 2001238 || actorId == 4298896563 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
            // +Callback Scene00098: Normal(None), id=unknown
          }
          else
          {
            Scene00097( player ); // Scene00097: Normal(None), id=unknown
          }
        }
        if( actor == 2001239 || actorId == 4298896564 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
            // +Callback Scene00096: Normal(None), id=unknown
          }
          else
          {
            Scene00095( player ); // Scene00095: Normal(None), id=unknown
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        Scene00005( player ); // Scene00005: NpcTrade(Talk, TargetCanMove), id=PFREWAHL
        // +Callback Scene00094: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PFREWAHL
        // +Callback Scene00093: Normal(None), id=unknown
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
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 3 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea055:66003 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=GURCANT" );
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
    player.sendDebug( "SubSea055:66003 calling Scene00001: Normal(Talk, TargetCanMove), id=RHOTWYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea055:66003 calling Scene00002: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }
  void Scene00100( Entity::Player& player )
  {
    player.sendDebug( "SubSea055:66003 calling [BranchTrue]Scene00100: Normal(None), id=unknown" );
    Scene00099( player );
  }
  void Scene00099( Entity::Player& player )
  {
    player.sendDebug( "SubSea055:66003 calling [BranchFalse]Scene00099: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 99, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea055:66003 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }
  void Scene00098( Entity::Player& player )
  {
    player.sendDebug( "SubSea055:66003 calling [BranchTrue]Scene00098: Normal(None), id=unknown" );
    Scene00097( player );
  }
  void Scene00097( Entity::Player& player )
  {
    player.sendDebug( "SubSea055:66003 calling [BranchFalse]Scene00097: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 97, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea055:66003 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }
  void Scene00096( Entity::Player& player )
  {
    player.sendDebug( "SubSea055:66003 calling [BranchTrue]Scene00096: Normal(None), id=unknown" );
    Scene00095( player );
  }
  void Scene00095( Entity::Player& player )
  {
    player.sendDebug( "SubSea055:66003 calling [BranchFalse]Scene00095: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 95, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubSea055:66003 calling Scene00005: NpcTrade(Talk, TargetCanMove), id=PFREWAHL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00094( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00094( Entity::Player& player )
  {
    player.sendDebug( "SubSea055:66003 calling [BranchTrue]Scene00094: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PFREWAHL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00093( player );
      }
    };
    player.playScene( getId(), 94, NONE, callback );
  }
  void Scene00093( Entity::Player& player )
  {
    player.sendDebug( "SubSea055:66003 calling [BranchChain]Scene00093: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 93, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea055 );
