// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea058 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea058() : Sapphire::ScriptAPI::EventScript( 66006 ){}; 
  ~SubSea058() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 9 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002119
  //ENEMY0 = 3929271
  //ENEMY1 = 3929272
  //ENEMY2 = 3929274
  //ENEMY3 = 3929275
  //ENEMY4 = 3929277
  //ENEMY5 = 3929278
  //EOBJECT0 = 2001240
  //EOBJECT1 = 2001241
  //EOBJECT2 = 2001242
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONSEARCHSHORT = 2

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=OSTFYR
        break;
      }
      case 1:
      {
        if( actor == 2001240 || actorId == 2001240 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00001( player ); // Scene00001: Normal(None), id=unknown
            // +Callback Scene00002: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 3929271 || actorId == 3929271 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 3929272 || actorId == 3929272 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2001241 || actorId == 2001241 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
            // +Callback Scene00004: Normal(None), id=unknown
          }
        }
        if( actor == 3929274 || actorId == 3929274 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 3929275 || actorId == 3929275 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( actor == 2001242 || actorId == 2001242 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 2 )
          {
            Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 3929277 || actorId == 3929277 ) // ENEMY4 = unknown
        {
          // empty entry
        }
        if( actor == 3929278 || actorId == 3929278 ) // ENEMY5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          // +Callback Scene00007: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
        // +Callback Scene00009: Normal(None), id=unknown
        // +Callback Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=OSTFYR
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
      if( player.getQuestUI8BH( getId() ) == 2 )
        if( player.getQuestUI8BL( getId() ) == 2 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea058:66006 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=OSTFYR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "SubSea058:66006 calling Scene00001: Normal(None), id=unknown" );
    Scene00002( player );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea058:66006 calling [BranchTrue]Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea058:66006 calling Scene00003: Normal(None), id=unknown" );
    Scene00004( player );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea058:66006 calling [BranchTrue]Scene00004: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 2 );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubSea058:66006 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubSea058:66006 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubSea058:66006 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubSea058:66006 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubSea058:66006 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubSea058:66006 calling [BranchChain]Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=OSTFYR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea058 );
