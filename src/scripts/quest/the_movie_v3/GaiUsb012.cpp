// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb012 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb012() : Sapphire::ScriptAPI::EventScript( 66355 ){}; 
  ~GaiUsb012() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 2 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006279
  //ACTOR1 = 1004917
  //ENEMY0 = 4292977
  //EOBJECT0 = 2002646
  //EOBJECT1 = 2002043
  //EOBJECT2 = 2002574
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000641

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LANDENEL
        break;
      }
      case 1:
      {
        if( param1 == 2002646 || param2 == 2002646 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4292977 || param2 == 4292977 ) // ENEMY0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002043 || param2 == 2002043 ) // EOBJECT1 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( param1 == 2002574 || param2 == 2002574 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002043 || param2 == 2002043 ) // EOBJECT1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( type != 2 ) Scene00010( player ); // Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00011: Normal(Talk, TargetCanMove), id=LANDENEL
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00012( player ); // Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=UODHNUN
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 3 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb012:66355 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb012:66355 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LANDENEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsb012:66355 calling Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb012:66355 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb012:66355 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: EOBJECT2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsb012:66355 calling Scene00008: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb012:66355 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb012:66355 calling Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb012:66355 calling Scene00011: Normal(Talk, TargetCanMove), id=LANDENEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb012:66355 calling Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=UODHNUN" );
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
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb012 );
