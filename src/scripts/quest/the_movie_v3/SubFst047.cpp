// FFXIVTheMovie.ParserV3
// simple method used
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
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=KEITHA
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        // empty entry
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( actor == 2001000 || actorId == 2001000 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq2( player );
          }
        }
        if( actor == 2001001 || actorId == 2001001 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq2( player );
          }
        }
        if( actor == 2001002 || actorId == 2001002 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq2( player );
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( actor == 1000470 || actorId == 1000470 ) // ACTOR0 = unknown
        {
          // empty entry
        }
        if( actor == 2001000 || actorId == 2001000 ) // EOBJECT1 = unknown
        {
          // empty entry
        }
        if( actor == 2001001 || actorId == 2001001 ) // EOBJECT2 = unknown
        {
          // empty entry
        }
        if( actor == 2001002 || actorId == 2001002 ) // EOBJECT3 = KEITHA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KEITHA
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubFst047:65910 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=KEITHA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubFst047:65910 calling Scene00005: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KEITHA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubFst047 );
