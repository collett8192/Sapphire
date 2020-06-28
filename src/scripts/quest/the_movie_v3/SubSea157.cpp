// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea157 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea157() : Sapphire::ScriptAPI::EventScript( 66826 ){}; 
  ~SubSea157() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1005394
  //ACTOR1 = 1005392
  //ACTOR2 = 1005395
  //ITEM0 = 2001083
  //ITEM1 = 2001084
  //LOCACTOR0 = 1005399
  //LOCSE1 = 54
  //VFXREACTION = 177

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SKRIBYLD
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( actor == 1005392 || actorId == 1005392 ) // ACTOR1 = RKONTAI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=RKONTAI
          }
        }
        if( actor == 1005394 || actorId == 1005394 ) // ACTOR0 = SKRIBYLD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=SKRIBYLD
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BL max stack ?
      case 2:
      {
        if( actor == 1005395 || actorId == 1005395 ) // ACTOR2 = WOLF
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, Inventory), id=WOLF
            // +Callback Scene00005: Normal(Talk, TargetCanMove), id=WOLF
          }
        }
        if( actor == 1005392 || actorId == 1005392 ) // ACTOR1 = RKONTAI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=RKONTAI
        }
        if( actor == 1005394 || actorId == 1005394 ) // ACTOR0 = SKRIBYLD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=SKRIBYLD
        }
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack 1
      case 3:
      {
        if( actor == 1005395 || actorId == 1005395 ) // ACTOR2 = WOLF
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk), id=WOLF
            // +Callback Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=WOLF
          }
        }
        if( actor == 1005394 || actorId == 1005394 ) // ACTOR0 = SKRIBYLD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=SKRIBYLD
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 1
      case 255:
      {
        Scene00011( player ); // Scene00011: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00012: Normal(Talk, FadeIn, TargetCanMove), id=SKRIBYLD
        // +Callback Scene00013: Normal(QuestReward, QuestComplete), id=unknown
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
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 1 )
    {
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
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
    player.sendDebug( "SubSea157:66826 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "SubSea157:66826 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SKRIBYLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea157:66826 calling Scene00002: Normal(Talk, TargetCanMove), id=RKONTAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea157:66826 calling Scene00003: Normal(Talk, TargetCanMove), id=SKRIBYLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea157:66826 calling Scene00004: Normal(Talk, Inventory), id=WOLF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubSea157:66826 calling [BranchTrue]Scene00005: Normal(Talk, TargetCanMove), id=WOLF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubSea157:66826 calling Scene00006: Normal(Talk, TargetCanMove), id=RKONTAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubSea157:66826 calling Scene00007: Normal(Talk, TargetCanMove), id=SKRIBYLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubSea157:66826 calling Scene00008: Normal(Talk), id=WOLF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubSea157:66826 calling [BranchTrue]Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=WOLF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubSea157:66826 calling Scene00010: Normal(Talk, TargetCanMove), id=SKRIBYLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubSea157:66826 calling Scene00011: NpcTrade(Talk, TargetCanMove), id=unknown" );
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
    player.sendDebug( "SubSea157:66826 calling [BranchTrue]Scene00012: Normal(Talk, FadeIn, TargetCanMove), id=SKRIBYLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubSea157:66826 calling [BranchChain]Scene00013: Normal(QuestReward, QuestComplete), id=unknown" );
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

EXPOSE_SCRIPT( SubSea157 );
