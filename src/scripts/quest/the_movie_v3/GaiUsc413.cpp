// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc413 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc413() : Sapphire::ScriptAPI::EventScript( 66524 ){}; 
  ~GaiUsc413() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006543
  //ENEMY0 = 4302140
  //ENEMY1 = 4302141
  //ENEMY2 = 4302152
  //ENEMY3 = 4302153
  //ENEMY4 = 4302154
  //EOBJECT0 = 2002206
  //EOBJECT1 = 2002207
  //EVENTACTIONSEARCH = 1

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NPAHTAYUUN
        break;
      }
      case 1:
      {
        if( actor == 2002206 || actorId == 2002206 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
            // +Callback Scene00003: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4302140 || actorId == 4302140 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4302141 || actorId == 4302141 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2002207 || actorId == 2002207 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
            // +Callback Scene00005: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4302152 || actorId == 4302152 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 4302153 || actorId == 4302153 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( actor == 4302154 || actorId == 4302154 ) // ENEMY4 = unknown
        {
          // empty entry
        }
        break;
      }
      case 255:
      {
        Scene00006( player ); // Scene00006: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=NPAHTAYUUN
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
      if( player.getQuestUI8BH( getId() ) == 3 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BH( getId(), 0 );
        player.updateQuest( getId(), 255 );
      }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc413:66524 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc413:66524 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NPAHTAYUUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc413:66524 calling Scene00002: Normal(None), id=unknown" );
    Scene00003( player );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc413:66524 calling [BranchTrue]Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc413:66524 calling Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc413:66524 calling [BranchTrue]Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 3 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc413:66524 calling Scene00006: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=NPAHTAYUUN" );
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

EXPOSE_SCRIPT( GaiUsc413 );
