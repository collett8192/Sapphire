// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsa207 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsa207() : Sapphire::ScriptAPI::EventScript( 66266 ){}; 
  ~GaiUsa207() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 6 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006191
  //ACTOR1 = 1000438
  //ENEMY0 = 4309478
  //ENEMY1 = 4309481
  //ENEMY2 = 4309485
  //ENEMY3 = 4309486
  //ENEMY4 = 4309487
  //EOBJECT0 = 2002459
  //EVENTACTIONSEARCH = 1

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=YOENNE
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=IRIELLE
        break;
      }
      case 2:
      {
        if( actor == 2002459 || actorId == 2002459 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
            // +Callback Scene00004: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4309478 || actorId == 4309478 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4309481 || actorId == 4309481 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 4309485 || actorId == 4309485 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 4309486 || actorId == 4309486 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( actor == 4309487 || actorId == 4309487 ) // ENEMY4 = unknown
        {
          // empty entry
        }
        break;
      }
      case 3:
      {
        Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=IRIELLE
        break;
      }
      case 255:
      {
        Scene00006( player ); // Scene00006: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YOENNE
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
    if( player.getQuestUI8AL( getId() ) == 5 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa207:66266 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsa207:66266 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=YOENNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa207:66266 calling Scene00002: Normal(Talk, TargetCanMove), id=IRIELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa207:66266 calling Scene00003: Normal(None), id=unknown" );
    Scene00004( player );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa207:66266 calling [BranchTrue]Scene00004: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 5 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa207:66266 calling Scene00005: Normal(Talk, TargetCanMove), id=IRIELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa207:66266 calling Scene00006: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YOENNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsa207 );
