// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst047 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst047() : Sapphire::ScriptAPI::EventScript( 65910 ){}; 
  ~SubFst047() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 3 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1000470
  //EOBJECT0 = 2000999
  //EOBJECT1 = 2001000
  //EOBJECT2 = 2001001
  //EOBJECT3 = 2001002
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000242
  //SEQ0ACTOR0 = 0
  //SEQ1EOBJECT0 = 1
  //SEQ1EOBJECT0EVENTACTIONNO = 99
  //SEQ1EOBJECT0EVENTACTIONOK = 100
  //SEQ2EOBJECT1 = 2
  //SEQ2EOBJECT1USEITEMNO = 97
  //SEQ2EOBJECT1USEITEMOK = 98
  //SEQ2EOBJECT2 = 3
  //SEQ2EOBJECT2USEITEMNO = 95
  //SEQ2EOBJECT2USEITEMOK = 96
  //SEQ2EOBJECT3 = 4
  //SEQ2EOBJECT3USEITEMNO = 93
  //SEQ2EOBJECT3USEITEMOK = 94
  //SEQ3ACTOR0 = 5
  //SEQ3EOBJECT1 = 6
  //SEQ3EOBJECT1EVENTACTIONNO = 91
  //SEQ3EOBJECT1EVENTACTIONOK = 92
  //SEQ3EOBJECT2 = 7
  //SEQ3EOBJECT2EVENTACTIONNO = 89
  //SEQ3EOBJECT2EVENTACTIONOK = 90
  //SEQ3EOBJECT3 = 8
  //SEQ3EOBJECT3EVENTACTIONNO = 87
  //SEQ3EOBJECT3EVENTACTIONOK = 88

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=KEITHA
        // +Callback Scene00005: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KEITHA
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( type != 2 ) Scene00099( player ); // Scene00099: Normal(None), id=unknown
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( param1 == 2001000 || param2 == 2001000 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00092( player ); // Scene00092: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001001 || param2 == 2001001 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001002 || param2 == 2001002 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00089( player ); // Scene00089: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( param1 == 1000470 || param2 == 1000470 ) // ACTOR0 = unknown
        {
          Scene00087( player ); // Scene00087: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001000 || param2 == 2001000 ) // EOBJECT1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(Inventory), id=unknown
          break;
        }
        if( param1 == 2001001 || param2 == 2001001 ) // EOBJECT2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(Inventory), id=unknown
          break;
        }
        if( param1 == 2001002 || param2 == 2001002 ) // EOBJECT3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(Inventory), id=unknown
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst047:65910 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=KEITHA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00005( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00005( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst047:65910 calling Scene00005: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KEITHA" );
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
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00099( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst047:65910 calling Scene00099: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00092( Entity::Player& player ) //SEQ_2: EOBJECT1, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "SubFst047:65910 calling Scene00092: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq2( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: EOBJECT2, UI8AL = 3, Flag8(2)=True
  {
    player.sendDebug( "SubFst047:65910 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq2( player );
  }

  void Scene00089( Entity::Player& player ) //SEQ_2: EOBJECT3, UI8AL = 3, Flag8(3)=True
  {
    player.sendDebug( "SubFst047:65910 calling Scene00089: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq2( player );
  }

  void Scene00087( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst047:65910 calling Scene00087: Normal(None), id=unknown" );
  }

  void Scene00002( Entity::Player& player ) //SEQ_255: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst047:65910 calling Scene00002: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_255: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst047:65910 calling Scene00003: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_255: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst047:65910 calling Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubFst047 );
