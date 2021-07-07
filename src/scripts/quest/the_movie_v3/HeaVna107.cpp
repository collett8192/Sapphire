// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna107 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna107() : Sapphire::ScriptAPI::EventScript( 67122 ){}; 
  ~HeaVna107() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1011241
  //ACTOR1 = 1011903
  //ACTOR2 = 1011231
  //ITEM0 = 2001573

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack 1
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=THIERREMONT
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( actor == 1011903 || actorId == 1011903 ) // ACTOR1 = YSAUDORE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00003: Normal(Talk, TargetCanMove), id=YSAUDORE
          }
        }
        if( actor == 1011241 || actorId == 1011241 ) // ACTOR0 = THIERREMONT
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THIERREMONT
        }
        break;
      }
      case 255:
      {
        if( actor == 1011231 || actorId == 1011231 ) // ACTOR2 = REDWALD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=REDWALD
        }
        if( actor == 1011903 || actorId == 1011903 ) // ACTOR1 = YSAUDORE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YSAUDORE
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

  void onEnterTerritory( Sapphire::Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2 ) override
  {
    onProgress( player, param1, param2, 4, 0 );
  }

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
    player.setQuestUI8BH( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna107:67122 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna107:67122 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=THIERREMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna107:67122 calling Scene00002: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00003( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna107:67122 calling [BranchTrue]Scene00003: Normal(Talk, TargetCanMove), id=YSAUDORE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna107:67122 calling Scene00004: Normal(Talk, TargetCanMove), id=THIERREMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna107:67122 calling Scene00005: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna107:67122 calling Scene00006: Normal(Talk, TargetCanMove), id=YSAUDORE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna107 );