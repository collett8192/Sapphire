// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsa706 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsa706() : Sapphire::ScriptAPI::EventScript( 66315 ){}; 
  ~GaiUsa706() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 11 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1006226
  //ACTOR1 = 1007710
  //ENEMY0 = 4284061
  //ENEMY1 = 4284063
  //ENEMY2 = 4284064
  //ENEMY3 = 4284065
  //ENEMY4 = 4284066
  //ENEMY5 = 4284067
  //EOBJECT0 = 2002460
  //EOBJECT1 = 2002640
  //EOBJECT2 = 2002641
  //EVENTRANGE0 = 4283978
  //EVENTACTIONSEARCH = 1

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=HREMFING
        break;
      }
      case 1:
      {
        if( param1 == 4283978 || param2 == 4283978 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00002( player ); // Scene00002: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4284061 || param2 == 4284061 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4284063 || param2 == 4284063 ) // ENEMY1 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4284064 || param2 == 4284064 ) // ENEMY2 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4284065 || param2 == 4284065 ) // ENEMY3 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4284066 || param2 == 4284066 ) // ENEMY4 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4284067 || param2 == 4284067 ) // ENEMY5 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 2002460 || param2 == 2002460 ) // EOBJECT0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002640 || param2 == 2002640 ) // EOBJECT1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002641 || param2 == 2002641 ) // EOBJECT2 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007710 || param2 == 1007710 ) // ACTOR1 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006226 || param2 == 1006226 ) // ACTOR0 = HREMFING
        {
          Scene00007( player ); // Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HREMFING
          break;
        }
        if( param1 == 2002640 || param2 == 2002640 ) // EOBJECT1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002641 || param2 == 2002641 ) // EOBJECT2 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007710 || param2 == 1007710 ) // ACTOR1 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa706:66315 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=HREMFING" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: EVENTRANGE0, UI8AL = 6, Flag8(1)=True
  {
    player.sendDebug( "GaiUsa706:66315 calling Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 6 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }







  void Scene00003( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa706:66315 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa706:66315 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa706:66315 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa706:66315 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa706:66315 calling Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HREMFING" );
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
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_255: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa706:66315 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player ) //SEQ_255: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa706:66315 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa706:66315 calling Scene00010: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsa706 );
