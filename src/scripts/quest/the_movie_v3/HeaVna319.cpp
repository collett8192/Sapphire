// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna319 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna319() : Sapphire::ScriptAPI::EventScript( 67156 ){}; 
  ~HeaVna319() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1012078
  //EOBJECT0 = 2005455
  //EOBJECT1 = 2005454
  //EOBJECT2 = 2005453
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001581
  //LOCMOTION0 = 958
  //LOCQUESTHEAVNA320 = 67157
  //LOCQUESTHEAVNA321 = 67158

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MOGHAN
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 3
      case 1:
      {
        if( param1 == 2005455 || param2 == 2005455 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2005454 || param2 == 2005454 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2005453 || param2 == 2005453 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1012078 || param2 == 1012078 ) // ACTOR0 = MOGHAN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MOGHAN
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        if( type != 2 ) Scene00009( player ); // Scene00009: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=MOGHAN
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 3 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna319:67156 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna319:67156 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MOGHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "HeaVna319:67156 calling Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8AL = 3, Flag8(2)=True
  {
    player.sendDebug( "HeaVna319:67156 calling Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: EOBJECT2, UI8AL = 3, Flag8(3)=True
  {
    player.sendDebug( "HeaVna319:67156 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna319:67156 calling Scene00008: Normal(Talk, TargetCanMove), id=MOGHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna319:67156 calling Scene00009: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00010( player );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna319:67156 calling Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=MOGHAN" );
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
    player.playScene( getId(), 10, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna319 );
