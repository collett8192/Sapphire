// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc710 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc710() : Sapphire::ScriptAPI::EventScript( 66558 ){}; 
  ~GaiUsc710() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 2 entries
  //SEQ_4, 3 entries
  //SEQ_5, 3 entries
  //SEQ_6, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1004914
  //ACTOR1 = 1006603
  //ACTOR2 = 1007632
  //ACTOR3 = 1006604
  //ACTOR4 = 1007633
  //ACTOR5 = 1006605
  //EOBJECT0 = 2002245
  //ITEM0 = 2000779

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HAB
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=CACTORA
        break;
      }
      case 2:
      {
        if( actor == 1004914 || actorId == 1004914 ) // ACTOR0 = HAB
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=HAB
          }
        }
        if( actor == 1007632 || actorId == 1007632 ) // ACTOR2 = CACTORA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=CACTORA
        }
        break;
      }
      case 3:
      {
        if( actor == 1006604 || actorId == 1006604 ) // ACTOR3 = CACTORB
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=CACTORB
          }
        }
        if( actor == 1007632 || actorId == 1007632 ) // ACTOR2 = CACTORA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CACTORA
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      case 4:
      {
        if( actor == 1004914 || actorId == 1004914 ) // ACTOR0 = HAB
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HAB
          }
        }
        if( actor == 1007632 || actorId == 1007632 ) // ACTOR2 = CACTORA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=CACTORA
        }
        if( actor == 1007633 || actorId == 1007633 ) // ACTOR4 = CACTORA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=CACTORA
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack ?
      case 5:
      {
        if( actor == 2002245 || actorId == 2002245 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Inventory), id=unknown
            // +Callback Scene00011: Normal(QuestGimmickReaction), id=unknown
          }
        }
        if( actor == 1007632 || actorId == 1007632 ) // ACTOR2 = CACTORA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=CACTORA
        }
        if( actor == 1007633 || actorId == 1007633 ) // ACTOR4 = CACTORA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=CACTORA
        }
        break;
      }
      case 6:
      {
        if( actor == 1006605 || actorId == 1006605 ) // ACTOR5 = CACTORC
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=CACTORC
          }
        }
        if( actor == 1007632 || actorId == 1007632 ) // ACTOR2 = CACTORA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=CACTORA
        }
        if( actor == 1007633 || actorId == 1007633 ) // ACTOR4 = CACTORA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=CACTORA
        }
        break;
      }
      case 255:
      {
        Scene00017( player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HAB
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc710:66558 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HAB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=CACTORA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00003: Normal(Talk, TargetCanMove), id=HAB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00004: Normal(Talk, TargetCanMove), id=CACTORA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=CACTORB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00006: Normal(Talk, TargetCanMove), id=CACTORA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00007: Normal(Talk, TargetCanMove), id=HAB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00008: Normal(Talk, TargetCanMove), id=CACTORA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00009: Normal(Talk, TargetCanMove), id=CACTORA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00010: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling [BranchTrue]Scene00011: Normal(QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00012: Normal(Talk, TargetCanMove), id=CACTORA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00013: Normal(Talk, TargetCanMove), id=CACTORA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=CACTORC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00015: Normal(Talk, TargetCanMove), id=CACTORA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00016: Normal(Talk, TargetCanMove), id=CACTORA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc710:66558 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HAB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsc710 );
