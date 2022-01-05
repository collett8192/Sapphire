// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil128 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil128() : Sapphire::ScriptAPI::EventScript( 66178 ){}; 
  ~SubWil128() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1003936
  //EOBJECT0 = 2001438
  //EOBJECT1 = 2001439
  //EOBJECT2 = 2001440
  //EOBJECT3 = 2001441
  //EOBJECT4 = 2001444
  //EOBJECT5 = 2001445
  //EVENTACTIONPROCESSSHOR = 15
  //ITEM0 = 2000406

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=AIRELL
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 6
      case 1:
      {
        if( param1 == 2001438 || param2 == 2001438 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001439 || param2 == 2001439 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001440 || param2 == 2001440 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001441 || param2 == 2001441 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001444 || param2 == 2001444 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00015( player ); // Scene00015: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001445 || param2 == 2001445 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00018( player ); // Scene00018: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 6
      case 255:
      {
        if( type != 2 ) Scene00019( player ); // Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AIRELL
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
    if( player.getQuestUI8AL( getId() ) == 6 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.setQuestBitFlag8( getId(), 4, false );
      player.setQuestBitFlag8( getId(), 5, false );
      player.setQuestBitFlag8( getId(), 6, false );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 6 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil128:66178 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=AIRELL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 6, Flag8(1)=True
  {
    player.sendDebug( "SubWil128:66178 calling Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8AL = 6, Flag8(2)=True
  {
    player.sendDebug( "SubWil128:66178 calling Scene00006: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: EOBJECT2, UI8AL = 6, Flag8(3)=True
  {
    player.sendDebug( "SubWil128:66178 calling Scene00009: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq1( player );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: EOBJECT3, UI8AL = 6, Flag8(4)=True
  {
    player.sendDebug( "SubWil128:66178 calling Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 4, true );
    checkProgressSeq1( player );
  }

  void Scene00015( Entity::Player& player ) //SEQ_1: EOBJECT4, UI8AL = 6, Flag8(5)=True
  {
    player.sendDebug( "SubWil128:66178 calling Scene00015: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 5, true );
    checkProgressSeq1( player );
  }

  void Scene00018( Entity::Player& player ) //SEQ_1: EOBJECT5, UI8AL = 6, Flag8(6)=True
  {
    player.sendDebug( "SubWil128:66178 calling Scene00018: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 6, true );
    checkProgressSeq1( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil128:66178 calling Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00020( player );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil128:66178 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AIRELL" );
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

EXPOSE_SCRIPT( SubWil128 );
