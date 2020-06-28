// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil120 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil120() : Sapphire::ScriptAPI::EventScript( 66166 ){}; 
  ~SubWil120() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1003931
  //EOBJECT0 = 2001419
  //EOBJECT1 = 2001428
  //EOBJECT2 = 2001429
  //EVENTACTIONGATHERSHORT = 6
  //ITEM0 = 2000392

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=TUTUSI
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 3
      case 1:
      {
        if( actor == 2001419 || actorId == 2001419 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00001( player ); // Scene00001: Normal(None), id=unknown
            // +Callback Scene00002: Normal(None), id=unknown
          }
          else
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
          }
        }
        if( actor == 2001428 || actorId == 2001428 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
            // +Callback Scene00005: Normal(None), id=unknown
          }
          else
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
          }
        }
        if( actor == 2001429 || actorId == 2001429 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
            // +Callback Scene00008: Normal(None), id=unknown
          }
          else
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        Scene00010( player ); // Scene00010: NpcTrade(Talk, TargetCanMove), id=TUTUSI
        // +Callback Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TUTUSI
        // +Callback Scene00012: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.updateQuest( getId(), 255 );
          player.setQuestUI8BH( getId(), 3 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil120:66166 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=TUTUSI" );
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
    player.sendDebug( "SubWil120:66166 calling Scene00001: Normal(None), id=unknown" );
    Scene00002( player );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil120:66166 calling [BranchTrue]Scene00002: Normal(None), id=unknown" );
    Scene00003( player );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil120:66166 calling [BranchFalse]Scene00003: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil120:66166 calling Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil120:66166 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil120:66166 calling [BranchFalse]Scene00006: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil120:66166 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil120:66166 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil120:66166 calling [BranchFalse]Scene00009: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil120:66166 calling Scene00010: NpcTrade(Talk, TargetCanMove), id=TUTUSI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil120:66166 calling [BranchTrue]Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TUTUSI" );
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
    player.sendDebug( "SubWil120:66166 calling [BranchChain]Scene00012: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil120 );
