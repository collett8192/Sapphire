// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb803 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb803() : Sapphire::ScriptAPI::EventScript( 66448 ){}; 
  ~GaiUsb803() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 13 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006384
  //ACTOR1 = 1006415
  //ACTOR10 = 1006424
  //ACTOR11 = 1006425
  //ACTOR2 = 1006416
  //ACTOR3 = 1006417
  //ACTOR4 = 1006418
  //ACTOR5 = 1006419
  //ACTOR6 = 1006420
  //ACTOR7 = 1006421
  //ACTOR8 = 1006422
  //ACTOR9 = 1006423
  //EOBJECT0 = 2002588
  //EOBJECT1 = 2002615
  //EVENTRANGE0 = 4333660
  //EVENTACTIONSEARCH = 1
  //QUESTBATTLE0 = 60
  //TERRITORYTYPE0 = 301

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HAURCHEFANT
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=BRIGIE
        break;
      }
      case 2:
      {
        Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        break;
      }
      case 3:
      {
        if( actor == 1006416 || actorId == 1006416 ) // ACTOR2 = HOURLINET
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=HOURLINET
          }
        }
        if( actor == 2002588 || actorId == 2002588 ) // EOBJECT0 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          // +Callback Scene00006: Normal(None), id=unknown
        }
        if( actor == 2002615 || actorId == 2002615 ) // EOBJECT1 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          // +Callback Scene00008: Normal(None), id=unknown
        }
        if( actor == 1006417 || actorId == 1006417 ) // ACTOR3 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1006418 || actorId == 1006418 ) // ACTOR4 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( actor == 1006419 || actorId == 1006419 ) // ACTOR5 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 1006420 || actorId == 1006420 ) // ACTOR6 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( actor == 1006421 || actorId == 1006421 ) // ACTOR7 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 1006422 || actorId == 1006422 ) // ACTOR8 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( actor == 1006423 || actorId == 1006423 ) // ACTOR9 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( actor == 1006424 || actorId == 1006424 ) // ACTOR10 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( actor == 1006425 || actorId == 1006425 ) // ACTOR11 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( actor == 4333660 || actorId == 4333660 ) // EVENTRANGE0 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(QuestBattle, YesNo), id=unknown
        }
        break;
      }
      case 255:
      {
        Scene00019( player ); // Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HAURCHEFANT
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb803:66448 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00002: Normal(Talk, TargetCanMove), id=BRIGIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00003: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00004: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=HOURLINET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling [BranchTrue]Scene00006: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00018: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb803:66448 calling Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb803 );
