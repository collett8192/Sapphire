// FFXIVTheMovie.ParserV3
// id table disabled
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea110 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea110() : Sapphire::ScriptAPI::EventScript( 65943 ){}; 
  ~SubSea110() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 11 entries
  //SEQ_2, 11 entries
  //SEQ_3, 11 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002231
  //ACTOR1 = 1002447
  //ACTOR10 = 1003496
  //ACTOR2 = 1002448
  //ACTOR3 = 1002449
  //ACTOR4 = 1002450
  //ACTOR5 = 1002451
  //ACTOR6 = 1002452
  //ACTOR7 = 1003493
  //ACTOR8 = 1003494
  //ACTOR9 = 1003495
  //EOBJECT0 = 2000756
  //EVENTACTIONSEARCH = 1

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=DOESRAEL
        break;
      }
      case 1:
      {
        if( actor == 1002447 || actorId == 1002447 ) // ACTOR1 = WYRSTMAGA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=WYRSTMAGA
          }
        }
        if( actor == 1002448 || actorId == 1002448 ) // ACTOR2 = OROGUARD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=OROGUARD
        }
        if( actor == 1002449 || actorId == 1002449 ) // ACTOR3 = IRATECOACHMANS
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=IRATECOACHMANS
        }
        if( actor == 1002450 || actorId == 1002450 ) // ACTOR4 = IRATECOACHMANN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=IRATECOACHMANN
        }
        if( actor == 1002451 || actorId == 1002451 ) // ACTOR5 = COACHMANN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=COACHMANN
        }
        if( actor == 1002452 || actorId == 1002452 ) // ACTOR6 = COACHMANS
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=COACHMANS
        }
        if( actor == 1003493 || actorId == 1003493 ) // ACTOR7 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( actor == 1003494 || actorId == 1003494 ) // ACTOR8 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( actor == 1003495 || actorId == 1003495 ) // ACTOR9 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1003496 || actorId == 1003496 ) // ACTOR10 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( actor == 2000756 || actorId == 2000756 ) // EOBJECT0 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          // +Callback Scene00012: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 1002449 || actorId == 1002449 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00013( player ); // Scene00013: Normal(None), id=unknown
          }
        }
        if( actor == 1002450 || actorId == 1002450 ) // ACTOR4 = IRATECOACHMANS
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=IRATECOACHMANS
            // +Callback Scene00015: Normal(Talk, TargetCanMove), id=IRATECOACHMANS
          }
        }
        if( actor == 1002447 || actorId == 1002447 ) // ACTOR1 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( actor == 1002448 || actorId == 1002448 ) // ACTOR2 = IRATECOACHMANS
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=IRATECOACHMANS
        }
        if( actor == 1002451 || actorId == 1002451 ) // ACTOR5 = IRATECOACHMANN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=IRATECOACHMANN
        }
        if( actor == 1002452 || actorId == 1002452 ) // ACTOR6 = IRATECOACHMANN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=IRATECOACHMANN
          // +Callback Scene00020: Normal(None), id=unknown
          // +Callback Scene00021: Normal(Talk, TargetCanMove), id=IRATECOACHMANN
        }
        if( actor == 1003493 || actorId == 1003493 ) // ACTOR7 = WYRSTMAGA
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=WYRSTMAGA
        }
        if( actor == 1003494 || actorId == 1003494 ) // ACTOR8 = OROGUARD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=OROGUARD
        }
        if( actor == 1003495 || actorId == 1003495 ) // ACTOR9 = COACHMANN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=COACHMANN
        }
        if( actor == 1003496 || actorId == 1003496 ) // ACTOR10 = COACHMANS
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=COACHMANS
        }
        if( actor == 2000756 || actorId == 2000756 ) // EOBJECT0 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          // +Callback Scene00027: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( actor == 1002447 || actorId == 1002447 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00028( player ); // Scene00028: Normal(None), id=unknown
          }
        }
        if( actor == 1002448 || actorId == 1002448 ) // ACTOR2 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
        }
        if( actor == 1002449 || actorId == 1002449 ) // ACTOR3 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
        }
        if( actor == 1002450 || actorId == 1002450 ) // ACTOR4 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
        }
        if( actor == 1002451 || actorId == 1002451 ) // ACTOR5 = WYRSTMAGA
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          // +Callback Scene00033: Normal(Talk, NpcDespawn, TargetCanMove), id=WYRSTMAGA
        }
        if( actor == 1002452 || actorId == 1002452 ) // ACTOR6 = OROGUARD
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=OROGUARD
        }
        if( actor == 1003493 || actorId == 1003493 ) // ACTOR7 = IRATECOACHMANS
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=IRATECOACHMANS
        }
        if( actor == 1003494 || actorId == 1003494 ) // ACTOR8 = IRATECOACHMANN
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=IRATECOACHMANN
        }
        if( actor == 1003495 || actorId == 1003495 ) // ACTOR9 = COACHMANN
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=COACHMANN
        }
        if( actor == 1003496 || actorId == 1003496 ) // ACTOR10 = COACHMANS
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=COACHMANS
          // +Callback Scene00039: Normal(None), id=unknown
          // +Callback Scene00040: Normal(None), id=unknown
        }
        if( actor == 2000756 || actorId == 2000756 ) // EOBJECT0 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          // +Callback Scene00042: Normal(None), id=unknown
          // +Callback Scene00043: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        Scene00044( player ); // Scene00044: Normal(None), id=unknown
        // +Callback Scene00045: Normal(None), id=unknown
        // +Callback Scene00046: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=DOESRAEL
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
    if( player.getQuestUI8AL( getId() ) == 2 )
      if( player.getQuestUI8AL( getId() ) == 2 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 3 );
      }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=DOESRAEL" );
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
    player.sendDebug( "SubSea110:65943 calling Scene00001: Normal(Talk, TargetCanMove), id=WYRSTMAGA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00002: Normal(Talk, TargetCanMove), id=OROGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00003: Normal(Talk, TargetCanMove), id=IRATECOACHMANS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00004: Normal(Talk, TargetCanMove), id=IRATECOACHMANN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00005: Normal(Talk, TargetCanMove), id=COACHMANN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00006: Normal(Talk, TargetCanMove), id=COACHMANS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling [BranchTrue]Scene00012: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00013: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00014: Normal(Talk, TargetCanMove), id=IRATECOACHMANS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling [BranchTrue]Scene00015: Normal(Talk, TargetCanMove), id=IRATECOACHMANS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00017: Normal(Talk, TargetCanMove), id=IRATECOACHMANS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00018: Normal(Talk, TargetCanMove), id=IRATECOACHMANN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00019: Normal(Talk, TargetCanMove), id=IRATECOACHMANN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling [BranchTrue]Scene00020: Normal(None), id=unknown" );
    Scene00021( player );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling [BranchChain]Scene00021: Normal(Talk, TargetCanMove), id=IRATECOACHMANN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00022: Normal(Talk, TargetCanMove), id=WYRSTMAGA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00023: Normal(Talk, TargetCanMove), id=OROGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00024: Normal(Talk, TargetCanMove), id=COACHMANN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00025: Normal(Talk, TargetCanMove), id=COACHMANS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00026: Normal(None), id=unknown" );
    Scene00027( player );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling [BranchTrue]Scene00027: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00028: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00032: Normal(None), id=unknown" );
    Scene00033( player );
  }
  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling [BranchTrue]Scene00033: Normal(Talk, NpcDespawn, TargetCanMove), id=WYRSTMAGA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00034: Normal(Talk, TargetCanMove), id=OROGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00035: Normal(Talk, TargetCanMove), id=IRATECOACHMANS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00036: Normal(Talk, TargetCanMove), id=IRATECOACHMANN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00037: Normal(Talk, TargetCanMove), id=COACHMANN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00038: Normal(Talk, TargetCanMove), id=COACHMANS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00039( player );
    };
    player.playScene( getId(), 38, NONE, callback );
  }
  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling [BranchTrue]Scene00039: Normal(None), id=unknown" );
    Scene00040( player );
  }
  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling [BranchChain]Scene00040: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00041: Normal(None), id=unknown" );
    Scene00042( player );
  }
  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling [BranchTrue]Scene00042: Normal(None), id=unknown" );
    Scene00043( player );
  }
  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling [BranchChain]Scene00043: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling Scene00044: Normal(None), id=unknown" );
    Scene00045( player );
  }
  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling [BranchTrue]Scene00045: Normal(None), id=unknown" );
    Scene00046( player );
  }
  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "SubSea110:65943 calling [BranchChain]Scene00046: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=DOESRAEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 46, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea110 );
