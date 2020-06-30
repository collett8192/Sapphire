// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna505 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna505() : Sapphire::ScriptAPI::EventScript( 67182 ){}; 
  ~HeaVna505() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 5 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1013096
  //ACTOR1 = 1013123
  //ACTOR2 = 1013124
  //ACTOR3 = 1013084
  //ACTOR4 = 1012064
  //ACTOR5 = 1012070
  //ACTOR6 = 1014570
  //ACTOR7 = 1014571
  //BINDCIDO = 5927823

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1013096 || actorId == 1013096 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013123 || actorId == 1013123 ) // ACTOR1 = LONUVANU
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LONUVANU
        }
        if( actor == 1013124 || actorId == 1013124 ) // ACTOR2 = CID
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=CID
        }
        break;
      }
      case 1:
      {
        if( actor == 1013123 || actorId == 1013123 ) // ACTOR1 = LONUVANU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LONUVANU
          }
        }
        if( actor == 1013084 || actorId == 1013084 ) // ACTOR3 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013124 || actorId == 1013124 ) // ACTOR2 = CID
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1012064 || actorId == 1012064 ) // ACTOR4 = SONUVANU
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=SONUVANU
        }
        break;
      }
      case 2:
      {
        if( actor == 1012070 || actorId == 1012070 ) // ACTOR5 = KUNUVALI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=KUNUVALI
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=KUNUVALI
          }
          else
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=KUNUVALI
          }
        }
        if( actor == 1013123 || actorId == 1013123 ) // ACTOR1 = LONUVANU
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=LONUVANU
        }
        if( actor == 1013084 || actorId == 1013084 ) // ACTOR3 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013124 || actorId == 1013124 ) // ACTOR2 = CID
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1012064 || actorId == 1012064 ) // ACTOR4 = SONUVANU
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=SONUVANU
        }
        break;
      }
      case 255:
      {
        if( actor == 1014570 || actorId == 1014570 ) // ACTOR6 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1014571 || actorId == 1014571 ) // ACTOR7 = CID
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1012070 || actorId == 1012070 ) // ACTOR5 = KUNUVALI
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=KUNUVALI
        }
        if( actor == 1012064 || actorId == 1012064 ) // ACTOR4 = SONUVANU
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=SONUVANU
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna505:67182 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00002: Normal(Talk, TargetCanMove), id=LONUVANU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00003: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00004: Normal(Talk, TargetCanMove), id=LONUVANU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00006: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00007: Normal(Talk, TargetCanMove), id=SONUVANU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00008: Normal(Talk, TargetCanMove), id=KUNUVALI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling [BranchTrue]Scene00009: Normal(Talk, TargetCanMove), id=KUNUVALI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling [BranchFalse]Scene00010: Normal(Talk, TargetCanMove), id=KUNUVALI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00011: Normal(Talk, TargetCanMove), id=LONUVANU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00013: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00014: Normal(Talk, TargetCanMove), id=SONUVANU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00015: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00016: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00017: Normal(Talk, TargetCanMove), id=KUNUVALI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna505:67182 calling Scene00018: Normal(Talk, TargetCanMove), id=SONUVANU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna505 );
