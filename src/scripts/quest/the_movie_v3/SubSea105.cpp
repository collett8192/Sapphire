// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea105 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea105() : Sapphire::ScriptAPI::EventScript( 65938 ){}; 
  ~SubSea105() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1003239
  //ACTOR1 = 1003244
  //ENEMY0 = 3927183
  //ENEMY1 = 3927184
  //EOBJECT0 = 2001255
  //EOBJECT1 = 2001256
  //EOBJECT2 = 2001257
  //EOBJECT3 = 2001258
  //EOBJECT4 = 2001259
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000342

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WYRKRHIT
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( actor == 2001255 || actorId == 2001255 ) // EOBJECT0 = unknown
        {
          Scene00001( player ); // Scene00001: Normal(None), id=unknown
        }
        if( actor == 3927183 || actorId == 3927183 ) // ENEMY0 = unknown
        {
          Scene00100( player ); // Scene00100: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 3927184 || actorId == 3927184 ) // ENEMY1 = unknown
        {
          Scene00099( player ); // Scene00099: Normal(None), id=unknown
        }
        if( actor == 2001256 || actorId == 2001256 ) // EOBJECT1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(None), id=unknown
        }
        if( actor == 2001257 || actorId == 2001257 ) // EOBJECT2 = unknown
        {
          Scene00098( player ); // Scene00098: Normal(None), id=unknown
        }
        if( actor == 2001258 || actorId == 2001258 ) // EOBJECT3 = unknown
        {
          Scene00097( player ); // Scene00097: Normal(None), id=unknown
        }
        if( actor == 2001259 || actorId == 2001259 ) // EOBJECT4 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( actor == 1003244 || actorId == 1003244 ) // ACTOR1 = unknown
        {
          Scene00096( player ); // Scene00096: Normal(None), id=unknown
        }
        if( actor == 2001256 || actorId == 2001256 ) // EOBJECT1 = unknown
        {
          Scene00095( player ); // Scene00095: Normal(None), id=unknown
        }
        if( actor == 2001257 || actorId == 2001257 ) // EOBJECT2 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( actor == 2001258 || actorId == 2001258 ) // EOBJECT3 = unknown
        {
          Scene00094( player ); // Scene00094: Normal(None), id=unknown
        }
        if( actor == 2001259 || actorId == 2001259 ) // EOBJECT4 = unknown
        {
          Scene00093( player ); // Scene00093: Normal(None), id=unknown
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

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea105:65938 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WYRKRHIT" );
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
    player.sendDebug( "SubSea105:65938 calling Scene00001: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00100( Entity::Player& player )
  {
    player.sendDebug( "SubSea105:65938 calling Scene00100: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 100, NONE, callback );
  }

  void Scene00099( Entity::Player& player )
  {
    player.sendDebug( "SubSea105:65938 calling Scene00099: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea105:65938 calling Scene00002: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00098( Entity::Player& player )
  {
    player.sendDebug( "SubSea105:65938 calling Scene00098: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00097( Entity::Player& player )
  {
    player.sendDebug( "SubSea105:65938 calling Scene00097: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea105:65938 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00096( Entity::Player& player )
  {
    player.sendDebug( "SubSea105:65938 calling Scene00096: Normal(None), id=unknown" );
  }

  void Scene00095( Entity::Player& player )
  {
    player.sendDebug( "SubSea105:65938 calling Scene00095: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea105:65938 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00094( Entity::Player& player )
  {
    player.sendDebug( "SubSea105:65938 calling Scene00094: Normal(None), id=unknown" );
  }

  void Scene00093( Entity::Player& player )
  {
    player.sendDebug( "SubSea105:65938 calling Scene00093: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubSea105 );
