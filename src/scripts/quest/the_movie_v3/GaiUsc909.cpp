// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc909 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc909() : Sapphire::ScriptAPI::EventScript( 66580 ){}; 
  ~GaiUsc909() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006643
  //ACTOR1 = 1006653
  //ACTOR2 = 1006654
  //ACTOR3 = 1006655
  //ACTOR4 = 1006656
  //ITEM0 = 2000789
  //VFXREACTION = 177

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MEMEZOFU
        break;
      }
      //seq 1 event item ITEM0 = UI8CL max stack ?
      case 1:
      {
        if( actor == 1006653 || actorId == 1006653 ) // ACTOR1 = ENPC1
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, Inventory), id=ENPC1
            // +Callback Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC1
          }
        }
        if( actor == 1006654 || actorId == 1006654 ) // ACTOR2 = ENPC2
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, Inventory), id=ENPC2
            // +Callback Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC2
          }
        }
        if( actor == 1006655 || actorId == 1006655 ) // ACTOR3 = ENPC3
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, Inventory), id=ENPC3
            // +Callback Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC3
          }
        }
        if( actor == 1006656 || actorId == 1006656 ) // ACTOR4 = ENPC4
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, Inventory), id=ENPC4
            // +Callback Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC4
          }
        }
        break;
      }
      case 255:
      {
        Scene00010( player ); // Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MEMEZOFU
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
          if( player.getQuestUI8CH( getId() ) == 1 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestUI8CL( getId(), 0 );
            player.updateQuest( getId(), 255 );
          }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc909:66580 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc909:66580 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MEMEZOFU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc909:66580 calling Scene00002: Normal(Talk, Inventory), id=ENPC1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc909:66580 calling [BranchTrue]Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc909:66580 calling Scene00004: Normal(Talk, Inventory), id=ENPC2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc909:66580 calling [BranchTrue]Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc909:66580 calling Scene00006: Normal(Talk, Inventory), id=ENPC3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc909:66580 calling [BranchTrue]Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc909:66580 calling Scene00008: Normal(Talk, Inventory), id=ENPC4" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc909:66580 calling [BranchTrue]Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC4" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc909:66580 calling Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MEMEZOFU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsc909 );
