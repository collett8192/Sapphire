// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc711 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc711() : Sapphire::ScriptAPI::EventScript( 66559 ){}; 
  ~GaiUsc711() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1004917
  //ACTOR1 = 1006606
  //ACTOR2 = 1006607
  //ACTOR3 = 1006608
  //ACTOR4 = 1007577
  //ACTOR5 = 1007578
  //ACTOR6 = 1007579
  //ACTOR7 = 1007580
  //ACTOR8 = 1007581
  //ITEM0 = 2000780
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
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=UODHNUN
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( actor == 1006606 || actorId == 1006606 ) // ACTOR1 = UZOKUA
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, Inventory, TargetCanMove), id=UZOKUA
            // +Callback Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=UZOKUA
          }
        }
        if( actor == 1006607 || actorId == 1006607 ) // ACTOR2 = UZOKUB
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, Inventory), id=UZOKUB
            // +Callback Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=UZOKUB
          }
        }
        if( actor == 1006608 || actorId == 1006608 ) // ACTOR3 = UZOKUC
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, Inventory, TargetCanMove), id=UZOKUC
            // +Callback Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=UZOKUC
          }
        }
        if( actor == 1007577 || actorId == 1007577 ) // ACTOR4 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( actor == 1007578 || actorId == 1007578 ) // ACTOR5 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1007579 || actorId == 1007579 ) // ACTOR6 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( actor == 1007580 || actorId == 1007580 ) // ACTOR7 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 1007581 || actorId == 1007581 ) // ACTOR8 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        Scene00013( player ); // Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=UODHNUN
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
          player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc711:66559 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc711:66559 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=UODHNUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc711:66559 calling Scene00002: Normal(Talk, Inventory, TargetCanMove), id=UZOKUA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc711:66559 calling [BranchTrue]Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=UZOKUA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc711:66559 calling Scene00004: Normal(Talk, Inventory), id=UZOKUB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc711:66559 calling [BranchTrue]Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=UZOKUB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc711:66559 calling Scene00006: Normal(Talk, Inventory, TargetCanMove), id=UZOKUC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc711:66559 calling [BranchTrue]Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=UZOKUC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc711:66559 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc711:66559 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc711:66559 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc711:66559 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc711:66559 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc711:66559 calling Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=UODHNUN" );
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

EXPOSE_SCRIPT( GaiUsc711 );
