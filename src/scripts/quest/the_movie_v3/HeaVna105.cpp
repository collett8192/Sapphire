// FFXIVTheMovie.ParserV3.6
// param used:
//SCENE_25 = ROTHE_2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna105 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna105() : Sapphire::ScriptAPI::EventScript( 67120 ){}; 
  ~HeaVna105() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 11 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1011231
  //ACTOR1 = 1011236
  //ENEMY0 = 5856610
  //ENEMY1 = 5856611
  //ENEMY2 = 5856612
  //ENEMY3 = 5856613
  //ENEMY4 = 5856614
  //ENEMY5 = 5856615
  //ENEMY6 = 5856616
  //EOBJECT0 = 2005403
  //EOBJECT1 = 2005404
  //EOBJECT2 = 2005405
  //EVENTACTIONLOOKOUTMIDDLE = 50
  //EVENTACTIONSEARCH = 1

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=REDWALD
        break;
      }
      case 1:
      {
        if( param1 == 1011236 || param2 == 1011236 ) // ACTOR1 = ROTHE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ROTHE
          }
          break;
        }
        if( param1 == 1011231 || param2 == 1011231 ) // ACTOR0 = REDWALD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=REDWALD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2005403 || param2 == 2005403 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 2 )
          {
            Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5856610 || param2 == 5856610 ) // ENEMY0 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5856611 || param2 == 5856611 ) // ENEMY1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2005404 || param2 == 2005404 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00011( player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5856612 || param2 == 5856612 ) // ENEMY2 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5856613 || param2 == 5856613 ) // ENEMY3 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5856614 || param2 == 5856614 ) // ENEMY4 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2005405 || param2 == 2005405 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00019( player ); // Scene00019: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5856615 || param2 == 5856615 ) // ENEMY5 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5856616 || param2 == 5856616 ) // ENEMY6 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1011236 || param2 == 1011236 ) // ACTOR1 = ROTHE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ROTHE
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00025( player ); // Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ROTHE_2
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
    if( player.getQuestUI8BL( getId() ) == 2 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8BH( getId() ) == 2 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestBitFlag8( getId(), 1, false );
          player.setQuestBitFlag8( getId(), 2, false );
          player.setQuestBitFlag8( getId(), 3, false );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna105:67120 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00002: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00003: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: EOBJECT0, UI8BL = 2, Flag8(1)=True
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 2 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: EOBJECT1, UI8AL = 3, Flag8(2)=True
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: ENEMY3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00015: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_2: ENEMY4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00017: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_2: EOBJECT2, UI8BH = 2, Flag8(3)=True
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00019: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 2 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_2: ENEMY5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00021: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_2: ENEMY6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00023: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00024: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna105:67120 calling Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ROTHE_2" );
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
    player.playScene( getId(), 25, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna105 );
