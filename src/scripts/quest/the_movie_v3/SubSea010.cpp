// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea010 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea010() : Sapphire::ScriptAPI::EventScript( 65656 ){}; 
  ~SubSea010() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002434
  //ACTOR1 = 1000857
  //EOBJECT0 = 2001578
  //EOBJECT1 = 2001572
  //EOBJECT2 = 2001573
  //EOBJECT3 = 2001574
  //EOBJECT4 = 2001575
  //EOBJECT5 = 2001576
  //EOBJECT6 = 2001577
  //ITEM0 = 2000444

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=NTANMO
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 2001578 || param2 == 2001578 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 7 )
          {
            Scene00001( player ); // Scene00001: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001572 || param2 == 2001572 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 7 )
          {
            Scene00002( player ); // Scene00002: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2001573 || param2 == 2001573 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 7 )
          {
            Scene00004( player ); // Scene00004: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2001574 || param2 == 2001574 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 7 )
          {
            Scene00006( player ); // Scene00006: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2001575 || param2 == 2001575 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 7 )
          {
            Scene00008( player ); // Scene00008: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2001576 || param2 == 2001576 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 7 )
          {
            Scene00010( player ); // Scene00010: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2001577 || param2 == 2001577 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 7 )
          {
            Scene00012( player ); // Scene00012: Normal(Inventory), id=unknown
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( type != 2 ) Scene00014( player ); // Scene00014: Normal(Inventory), id=unknown
        // +Callback Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SISIPU
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
    player.sendDebug( "emote: {}", emoteId );
    onProgress( player, actorId, actor, 1, emoteId );
  }

  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
  {
    onProgress( player, npcId, 0, 2, 0 );
  }

  void onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( player, param1, param1, 3, 0 );
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
    if( player.getQuestUI8AL( getId() ) == 7 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.setQuestBitFlag8( getId(), 4, false );
      player.setQuestBitFlag8( getId(), 5, false );
      player.setQuestBitFlag8( getId(), 6, false );
      player.setQuestBitFlag8( getId(), 7, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea010:65656 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=NTANMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 7, Flag8(1)=True
  {
    player.sendDebug( "SubSea010:65656 calling Scene00001: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq1( player );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8AL = 7, Flag8(2)=True
  {
    player.sendDebug( "SubSea010:65656 calling Scene00002: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: EOBJECT2, UI8AL = 7, Flag8(3)=True
  {
    player.sendDebug( "SubSea010:65656 calling Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: EOBJECT3, UI8AL = 7, Flag8(4)=True
  {
    player.sendDebug( "SubSea010:65656 calling Scene00006: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 4, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: EOBJECT4, UI8AL = 7, Flag8(5)=True
  {
    player.sendDebug( "SubSea010:65656 calling Scene00008: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 5, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: EOBJECT5, UI8AL = 7, Flag8(6)=True
  {
    player.sendDebug( "SubSea010:65656 calling Scene00010: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 6, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: EOBJECT6, UI8AL = 7, Flag8(7)=True
  {
    player.sendDebug( "SubSea010:65656 calling Scene00012: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 7, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea010:65656 calling Scene00014: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00016( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea010:65656 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SISIPU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea010 );
