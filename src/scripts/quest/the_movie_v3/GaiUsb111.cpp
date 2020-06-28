// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb111 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb111() : Sapphire::ScriptAPI::EventScript( 66366 ){}; 
  ~GaiUsb111() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 2 entries
  //SEQ_4, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006288
  //ACTOR1 = 1006287
  //ACTOR2 = 1006737
  //ENEMY0 = 2268
  //ITEM0 = 2000647
  //ITEM1 = 2000648

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=UKHUBATIA
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=UTYKHATIA
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=UKAHZUNA
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      //seq 3 event item ITEM1 = UI8BL max stack 3
      case 3:
      {
        if( actor == 2268 || actorId == 2268 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 3 )
          {
            player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
            checkProgressSeq3( player );
          }
        }
        if( actor == 1006737 || actorId == 1006737 ) // ACTOR2 = UKAHZUNA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=UKAHZUNA
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      //seq 4 event item ITEM1 = UI8BL max stack 3
      case 4:
      {
        Scene00005( player ); // Scene00005: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00006: Normal(Talk, TargetCanMove), id=UKAHZUNA
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( actor == 1006287 || actorId == 1006287 ) // ACTOR1 = UTYKHATIA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=UTYKHATIA
        }
        if( actor == 1006737 || actorId == 1006737 ) // ACTOR2 = UKAHZUNA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=UKAHZUNA
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
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 3 )
    {
      player.updateQuest( getId(), 4 );
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestUI8BL( getId(), 3 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.setQuestUI8BL( getId(), 0 );
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb111:66366 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb111:66366 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=UKHUBATIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb111:66366 calling Scene00002: Normal(Talk, TargetCanMove), id=UTYKHATIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb111:66366 calling Scene00003: Normal(Talk, TargetCanMove), id=UKAHZUNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb111:66366 calling Scene00004: Normal(Talk, TargetCanMove), id=UKAHZUNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb111:66366 calling Scene00005: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00006( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb111:66366 calling [BranchTrue]Scene00006: Normal(Talk, TargetCanMove), id=UKAHZUNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb111:66366 calling Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=UTYKHATIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb111:66366 calling Scene00008: Normal(Talk, TargetCanMove), id=UKAHZUNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb111 );
