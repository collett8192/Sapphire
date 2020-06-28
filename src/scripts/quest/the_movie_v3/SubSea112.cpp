// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea112 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea112() : Sapphire::ScriptAPI::EventScript( 65945 ){}; 
  ~SubSea112() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002233
  //ACTOR1 = 1002453
  //ACTOR2 = 1002455
  //EOBJECT0 = 2000762
  //EOBJECT1 = 2000763
  //EVENTACTIONGATHERSHORT = 6
  //ITEM0 = 2000218
  //SEQ0ACTOR0 = 0
  //SEQ1ACTOR1 = 1
  //SEQ1ACTOR2 = 2
  //SEQ1EOBJECT0 = 3
  //SEQ1EOBJECT0EVENTACTIONNO = 99
  //SEQ1EOBJECT0EVENTACTIONOK = 100
  //SEQ1EOBJECT1 = 4
  //SEQ1EOBJECT1EVENTACTIONNO = 97
  //SEQ1EOBJECT1EVENTACTIONOK = 98
  //SEQ2ACTOR0 = 5
  //SEQ2ACTOR0NPCTRADENO = 95
  //SEQ2ACTOR0NPCTRADEOK = 96

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WAFUFU
        break;
      }
      //seq 1 event item ITEM0 = UI8CL max stack 4
      case 1:
      {
        if( actor == 1002453 || actorId == 1002453 ) // ACTOR1 = LYNGSTYRM
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=LYNGSTYRM
          }
        }
        if( actor == 1002455 || actorId == 1002455 ) // ACTOR2 = MAETIMYND
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MAETIMYND
          }
        }
        if( actor == 2000762 || actorId == 2000762 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
            // +Callback Scene00100: Normal(None), id=unknown
          }
          else
          {
            Scene00099( player ); // Scene00099: Normal(None), id=unknown
          }
        }
        if( actor == 2000763 || actorId == 2000763 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
            // +Callback Scene00098: Normal(None), id=unknown
          }
          else
          {
            Scene00097( player ); // Scene00097: Normal(None), id=unknown
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 4
      case 255:
      {
        Scene00005( player ); // Scene00005: NpcTrade(Talk, TargetCanMove), id=WAFUFU
        // +Callback Scene00096: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WAFUFU
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

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestUI8CL( getId(), 0 );
            player.updateQuest( getId(), 255 );
            player.setQuestUI8BH( getId(), 4 );
          }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea112:65945 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WAFUFU" );
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
    player.sendDebug( "SubSea112:65945 calling Scene00001: Normal(Talk, TargetCanMove), id=LYNGSTYRM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea112:65945 calling Scene00002: Normal(Talk, TargetCanMove), id=MAETIMYND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea112:65945 calling Scene00003: Normal(None), id=unknown" );
    Scene00100( player );
  }
  void Scene00100( Entity::Player& player )
  {
    player.sendDebug( "SubSea112:65945 calling [BranchTrue]Scene00100: Normal(None), id=unknown" );
    Scene00099( player );
  }
  void Scene00099( Entity::Player& player )
  {
    player.sendDebug( "SubSea112:65945 calling [BranchFalse]Scene00099: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 99, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea112:65945 calling Scene00004: Normal(None), id=unknown" );
    Scene00098( player );
  }
  void Scene00098( Entity::Player& player )
  {
    player.sendDebug( "SubSea112:65945 calling [BranchTrue]Scene00098: Normal(None), id=unknown" );
    Scene00097( player );
  }
  void Scene00097( Entity::Player& player )
  {
    player.sendDebug( "SubSea112:65945 calling [BranchFalse]Scene00097: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 97, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubSea112:65945 calling Scene00005: NpcTrade(Talk, TargetCanMove), id=WAFUFU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00096( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00096( Entity::Player& player )
  {
    player.sendDebug( "SubSea112:65945 calling [BranchTrue]Scene00096: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WAFUFU" );
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
    player.sendDebug( "SubSea112:65945 calling [BranchChain]Scene00095: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 95, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea112 );
