// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna320 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna320() : Sapphire::ScriptAPI::EventScript( 67157 ){}; 
  ~HeaVna320() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1012080
  //ACTOR1 = 1013200
  //ACTOR2 = 1013201
  //ENEMY0 = 5864425
  //ENEMY1 = 5864426
  //ENEMY2 = 5937954
  //EOBJECT0 = 2005547
  //EVENTRANGE0 = 5864420
  //LOCMOTION0 = 958
  //LOCQUESTHEAVNA319 = 67156
  //LOCQUESTHEAVNA321 = 67158

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MOGMUG
        break;
      }
      case 1:
      {
        if( param1 == 5864420 || param2 == 5864420 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00002( player ); // Scene00002: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5864425 || param2 == 5864425 ) // ENEMY0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864426 || param2 == 5864426 ) // ENEMY1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 5937954 || param2 == 5937954 ) // ENEMY2 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012080 || param2 == 1012080 ) // ACTOR0 = MOGMUG
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MOGMUG
          break;
        }
        if( param1 == 1013200 || param2 == 1013200 ) // ACTOR1 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013201 || param2 == 1013201 ) // ACTOR2 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005547 || param2 == 2005547 ) // EOBJECT0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00010( player ); // Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=MOGMUG
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna320:67157 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna320:67157 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MOGMUG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: EVENTRANGE0, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "HeaVna320:67157 calling Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna320:67157 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna320:67157 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna320:67157 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna320:67157 calling Scene00006: Normal(Talk, TargetCanMove), id=MOGMUG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna320:67157 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna320:67157 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna320:67157 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna320:67157 calling Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=MOGMUG" );
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

EXPOSE_SCRIPT( HeaVna320 );
