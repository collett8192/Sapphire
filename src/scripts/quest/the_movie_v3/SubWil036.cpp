// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil036 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil036() : Sapphire::ScriptAPI::EventScript( 65764 ){}; 
  ~SubWil036() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 9 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002030
  //ACTOR1 = 1002044
  //ENEMY0 = 3923955
  //ENEMY1 = 3949791
  //ENEMY2 = 3949797
  //EOBJECT0 = 2001276
  //EOBJECT1 = 2001356
  //EOBJECT2 = 2001357
  //EVENTRANGE0 = 4084925
  //EVENTRANGE1 = 4084894
  //EVENTRANGE2 = 4084766
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000153

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=unknown
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 3
      case 1:
      {
        if( actor == 4084925 || actorId == 4084925 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 2001276 || actorId == 2001276 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Message), id=unknown
            // +Callback Scene00004: Normal(None), id=unknown
          }
        }
        if( actor == 3923955 || actorId == 3923955 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4084894 || actorId == 4084894 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 2001356 || actorId == 2001356 ) // EOBJECT1 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(Message), id=unknown
          // +Callback Scene00007: Normal(None), id=unknown
        }
        if( actor == 3949791 || actorId == 3949791 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 4084766 || actorId == 4084766 ) // EVENTRANGE2 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 2001357 || actorId == 2001357 ) // EOBJECT2 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(Message), id=unknown
          // +Callback Scene00010: Normal(None), id=unknown
        }
        if( actor == 3949797 || actorId == 3949797 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        Scene00011( player ); // Scene00011: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown
        // +Callback Scene00013: Normal(None), id=unknown
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
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.updateQuest( getId(), 255 );
          player.setQuestUI8BH( getId(), 3 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil036:65764 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "SubWil036:65764 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil036:65764 calling Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil036:65764 calling Scene00003: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil036:65764 calling [BranchTrue]Scene00004: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil036:65764 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil036:65764 calling Scene00006: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil036:65764 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil036:65764 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil036:65764 calling Scene00009: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil036:65764 calling [BranchTrue]Scene00010: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil036:65764 calling Scene00011: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00012( player );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubWil036:65764 calling [BranchTrue]Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil036:65764 calling [BranchChain]Scene00013: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil036 );
