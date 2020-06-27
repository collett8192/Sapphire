// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst033 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst033() : Sapphire::ScriptAPI::EventScript( 65663 ){}; 
  ~SubFst033() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000461
  //ENEMY0 = 2114368
  //ENEMY1 = 2114369
  //ENEMY2 = 2114370
  //EOBJECT0 = 2000016
  //EOBJECT1 = 2000017
  //EOBJECT2 = 2000018
  //ITEM0 = 2000061
  //SEQ0ACTOR0 = 0
  //SEQ1EOBJECT0 = 1
  //SEQ1EOBJECT0USEITEMNO = 99
  //SEQ1EOBJECT0USEITEMOK = 100
  //SEQ1EOBJECT1 = 2
  //SEQ1EOBJECT1USEITEMNO = 97
  //SEQ1EOBJECT1USEITEMOK = 98
  //SEQ1EOBJECT2 = 3
  //SEQ1EOBJECT2USEITEMNO = 95
  //SEQ1EOBJECT2USEITEMOK = 96
  //SEQ2ACTOR0 = 4

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=GABINEAUX
        break;
      }
      //seq 1 event item ITEM0 = UI8DL max stack ?
      case 1:
      {
        if( actor == 2000016 || actorId == 2000016 ) // EOBJECT0 = unknown
        {
          // empty entry
        }
        if( actor == 2114368 || actorId == 2114368 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            player.setQuestUI8AL( getId(), 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 2000017 || actorId == 2000017 ) // EOBJECT1 = unknown
        {
          // empty entry
        }
        if( actor == 2114369 || actorId == 2114369 ) // ENEMY1 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            player.setQuestUI8BL( getId(), 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 2000018 || actorId == 2000018 ) // EOBJECT2 = unknown
        {
          // empty entry
        }
        if( actor == 2114370 || actorId == 2114370 ) // ENEMY2 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            player.setQuestUI8CL( getId(), 1 );
            checkProgressSeq1( player );
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        Scene00004( player ); // Scene00004: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GABINEAUX
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
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BL( getId() ) == 1 )
        if( player.getQuestUI8CL( getId() ) == 1 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.setQuestUI8DL( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubFst033:65663 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=GABINEAUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubFst033:65663 calling Scene00004: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GABINEAUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubFst033 );
