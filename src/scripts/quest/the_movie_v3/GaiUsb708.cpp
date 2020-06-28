// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb708 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb708() : Sapphire::ScriptAPI::EventScript( 66439 ){}; 
  ~GaiUsb708() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 9 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1006403
  //ACTOR1 = 1007701
  //ACTOR2 = 1007702
  //ENEMY0 = 4292758
  //ENEMY1 = 4293100
  //EOBJECT0 = 2002131
  //EOBJECT1 = 2002509
  //EOBJECT2 = 2002626
  //EOBJECT3 = 2002627
  //EVENTRANGE0 = 4292757
  //EVENTACTIONSEARCH = 1

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=BELMONT
        break;
      }
      case 1:
      {
        if( actor == 4292757 || actorId == 4292757 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00002( player ); // Scene00002: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4292758 || actorId == 4292758 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4293100 || actorId == 4293100 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2002131 || actorId == 2002131 ) // EOBJECT0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          // +Callback Scene00004: Normal(None), id=unknown
        }
        if( actor == 2002509 || actorId == 2002509 ) // EOBJECT1 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          // +Callback Scene00006: Normal(None), id=unknown
        }
        if( actor == 2002626 || actorId == 2002626 ) // EOBJECT2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          // +Callback Scene00008: Normal(None), id=unknown
        }
        if( actor == 2002627 || actorId == 2002627 ) // EOBJECT3 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          // +Callback Scene00010: Normal(None), id=unknown
        }
        if( actor == 1007701 || actorId == 1007701 ) // ACTOR1 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 1007702 || actorId == 1007702 ) // ACTOR2 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1006403 || actorId == 1006403 ) // ACTOR0 = BELMONT
        {
          Scene00013( player ); // Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BELMONT
        }
        if( actor == 2002131 || actorId == 2002131 ) // EOBJECT0 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          // +Callback Scene00015: Normal(None), id=unknown
        }
        if( actor == 2002626 || actorId == 2002626 ) // EOBJECT2 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          // +Callback Scene00017: Normal(None), id=unknown
        }
        if( actor == 2002627 || actorId == 2002627 ) // EOBJECT3 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          // +Callback Scene00019: Normal(None), id=unknown
        }
        if( actor == 1007701 || actorId == 1007701 ) // ACTOR1 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        if( actor == 1007702 || actorId == 1007702 ) // ACTOR2 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb708:66439 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=BELMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00003: Normal(None), id=unknown" );
    Scene00004( player );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling [BranchTrue]Scene00004: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling [BranchTrue]Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling [BranchTrue]Scene00010: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BELMONT" );
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

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00014: Normal(None), id=unknown" );
    Scene00015( player );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling [BranchTrue]Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00016: Normal(None), id=unknown" );
    Scene00017( player );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling [BranchTrue]Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00018: Normal(None), id=unknown" );
    Scene00019( player );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling [BranchTrue]Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb708:66439 calling Scene00021: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb708 );
