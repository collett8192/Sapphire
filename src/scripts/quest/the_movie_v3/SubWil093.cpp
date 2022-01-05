// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil093 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil093() : Sapphire::ScriptAPI::EventScript( 65878 ){}; 
  ~SubWil093() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002069
  //EOBJECT0 = 2001382
  //EOBJECT1 = 2001383
  //EOBJECT2 = 2001384
  //EOBJECT3 = 2001475
  //EOBJECT4 = 2001476
  //EOBJECT5 = 2001477
  //EOBJECT6 = 2001478
  //EOBJECT7 = 2001479
  //EVENTACTIONPROCESSSHOR = 15

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=unknown
        break;
      }
      case 1:
      {
        if( param1 == 2001382 || param2 == 2001382 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001383 || param2 == 2001383 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001384 || param2 == 2001384 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001475 || param2 == 2001475 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001476 || param2 == 2001476 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001477 || param2 == 2001477 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001478 || param2 == 2001478 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00014( player ); // Scene00014: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001479 || param2 == 2001479 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00017( player ); // Scene00017: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00020( player ); // Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 8 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.setQuestBitFlag8( getId(), 4, false );
      player.setQuestBitFlag8( getId(), 5, false );
      player.setQuestBitFlag8( getId(), 6, false );
      player.setQuestBitFlag8( getId(), 7, false );
      player.setQuestBitFlag8( getId(), 8, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil093:65878 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 8, Flag8(1)=True
  {
    player.sendDebug( "SubWil093:65878 calling Scene00002: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8AL = 8, Flag8(2)=True
  {
    player.sendDebug( "SubWil093:65878 calling Scene00004: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: EOBJECT2, UI8AL = 8, Flag8(3)=True
  {
    player.sendDebug( "SubWil093:65878 calling Scene00006: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: EOBJECT3, UI8AL = 8, Flag8(4)=True
  {
    player.sendDebug( "SubWil093:65878 calling Scene00008: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 4, true );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: EOBJECT4, UI8AL = 8, Flag8(5)=True
  {
    player.sendDebug( "SubWil093:65878 calling Scene00010: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 5, true );
    checkProgressSeq1( player );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: EOBJECT5, UI8AL = 8, Flag8(6)=True
  {
    player.sendDebug( "SubWil093:65878 calling Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 6, true );
    checkProgressSeq1( player );
  }

  void Scene00014( Entity::Player& player ) //SEQ_1: EOBJECT6, UI8AL = 8, Flag8(7)=True
  {
    player.sendDebug( "SubWil093:65878 calling Scene00014: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 7, true );
    checkProgressSeq1( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_1: EOBJECT7, UI8AL = 8, Flag8(8)=True
  {
    player.sendDebug( "SubWil093:65878 calling Scene00017: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 8, true );
    checkProgressSeq1( player );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil093:65878 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
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
    player.playScene( getId(), 20, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil093 );
