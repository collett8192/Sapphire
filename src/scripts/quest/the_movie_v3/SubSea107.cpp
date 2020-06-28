// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea107 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea107() : Sapphire::ScriptAPI::EventScript( 65940 ){}; 
  ~SubSea107() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1003244
  //EOBJECT0 = 2001262
  //EOBJECT1 = 2001263
  //EVENTACTIONSEARCHMIDDLE = 3
  //ITEM0 = 2000345

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=LYULF
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( actor == 2001262 || actorId == 2001262 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(None), id=unknown
            // +Callback Scene00100: Normal(None), id=unknown
          }
          else
          {
            Scene00099( player ); // Scene00099: Normal(None), id=unknown
          }
        }
        if( actor == 2001263 || actorId == 2001263 ) // EOBJECT1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(None), id=unknown
          // +Callback Scene00098: Normal(Message), id=unknown
          // +Callback Scene00097: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        Scene00003( player ); // Scene00003: NpcTrade(Talk), id=LYULF
        // +Callback Scene00096: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYULF
        // +Callback Scene00095: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea107:65940 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=LYULF" );
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
    player.sendDebug( "SubSea107:65940 calling Scene00001: Normal(None), id=unknown" );
    Scene00100( player );
  }
  void Scene00100( Entity::Player& player )
  {
    player.sendDebug( "SubSea107:65940 calling [BranchTrue]Scene00100: Normal(None), id=unknown" );
    Scene00099( player );
  }
  void Scene00099( Entity::Player& player )
  {
    player.sendDebug( "SubSea107:65940 calling [BranchFalse]Scene00099: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 99, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea107:65940 calling Scene00002: Normal(None), id=unknown" );
    Scene00098( player );
  }
  void Scene00098( Entity::Player& player )
  {
    player.sendDebug( "SubSea107:65940 calling [BranchTrue]Scene00098: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00097( player );
    };
    player.playScene( getId(), 98, NONE, callback );
  }
  void Scene00097( Entity::Player& player )
  {
    player.sendDebug( "SubSea107:65940 calling [BranchChain]Scene00097: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 97, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea107:65940 calling Scene00003: NpcTrade(Talk), id=LYULF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00096( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00096( Entity::Player& player )
  {
    player.sendDebug( "SubSea107:65940 calling [BranchTrue]Scene00096: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYULF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00095( player );
      }
    };
    player.playScene( getId(), 96, NONE, callback );
  }
  void Scene00095( Entity::Player& player )
  {
    player.sendDebug( "SubSea107:65940 calling [BranchChain]Scene00095: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 95, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea107 );
