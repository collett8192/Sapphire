// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil122 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil122() : Sapphire::ScriptAPI::EventScript( 66168 ){}; 
  ~SubWil122() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 6 entries
  //SEQ_3, 5 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1003939
  //ACTOR1 = 1003952
  //ACTOR2 = 1003953
  //ACTOR3 = 1003954
  //ACTOR4 = 1003955
  //ACTOR5 = 1003956
  //EOBJECT0 = 2001423
  //EOBJECT1 = 2001424
  //EOBJECT2 = 2001425
  //EOBJECT3 = 2001453
  //EOBJECT4 = 2001454
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000393
  //ITEM1 = 2000412

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=BENEGER
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( actor == 2001423 || actorId == 2001423 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00001( player ); // Scene00001: Normal(Inventory), id=unknown
          }
        }
        if( actor == 2001424 || actorId == 2001424 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
          }
        }
        if( actor == 2001425 || actorId == 2001425 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
          }
        }
        if( actor == 2001453 || actorId == 2001453 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00004( player ); // Scene00004: Normal(Inventory), id=unknown
          }
        }
        if( actor == 2001454 || actorId == 2001454 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
          }
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      //seq 2 event item ITEM1 = UI8BL max stack 1
      case 2:
      {
        if( actor == 1003939 || actorId == 1003939 ) // ACTOR0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
          }
        }
        if( actor == 2001423 || actorId == 2001423 ) // EOBJECT0 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(Inventory), id=unknown
        }
        if( actor == 2001424 || actorId == 2001424 ) // EOBJECT1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( actor == 2001425 || actorId == 2001425 ) // EOBJECT2 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 2001453 || actorId == 2001453 ) // EOBJECT3 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(Inventory), id=unknown
        }
        if( actor == 2001454 || actorId == 2001454 ) // EOBJECT4 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8DH max stack ?
      //seq 3 event item ITEM1 = UI8DL max stack 1
      case 3:
      {
        if( actor == 1003952 || actorId == 1003952 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
          }
        }
        if( actor == 1003953 || actorId == 1003953 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Inventory), id=unknown
          }
        }
        if( actor == 1003954 || actorId == 1003954 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(None), id=unknown
          }
        }
        if( actor == 1003955 || actorId == 1003955 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(None), id=unknown
          }
        }
        if( actor == 1003956 || actorId == 1003956 ) // ACTOR5 = BENEGER
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=BENEGER
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      //seq 255 event item ITEM1 = UI8BL max stack 1
      case 255:
      {
        if( actor == 1003939 || actorId == 1003939 ) // ACTOR0 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( actor == 1003952 || actorId == 1003952 ) // ACTOR1 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        if( actor == 1003953 || actorId == 1003953 ) // ACTOR2 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( actor == 1003954 || actorId == 1003954 ) // ACTOR3 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        if( actor == 1003955 || actorId == 1003955 ) // ACTOR4 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
        }
        if( actor == 1003956 || actorId == 1003956 ) // ACTOR5 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 5 )
      if( player.getQuestUI8AL( getId() ) == 5 )
        if( player.getQuestUI8AL( getId() ) == 5 )
          if( player.getQuestUI8AL( getId() ) == 5 )
            if( player.getQuestUI8AL( getId() ) == 5 )
            {
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.updateQuest( getId(), 2 );
            }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
            if( player.getQuestUI8CL( getId() ) == 1 )
            {
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8BH( getId(), 0 );
              player.setQuestUI8BL( getId(), 0 );
              player.setQuestUI8CH( getId(), 0 );
              player.setQuestUI8CL( getId(), 0 );
              player.setQuestUI8DH( getId(), 0 );
              player.setQuestUI8DL( getId(), 0 );
              player.updateQuest( getId(), 255 );
            }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=BENEGER" );
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
    player.sendDebug( "SubWil122:66168 calling Scene00001: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00002: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00006: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00007: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00010: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00013: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00014: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00015: Normal(None), id=unknown" );
    player.setQuestUI8CH( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00016: Normal(Talk, TargetCanMove), id=BENEGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "SubWil122:66168 calling Scene00022: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubWil122 );
