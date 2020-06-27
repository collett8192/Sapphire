// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst057 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst057() : Sapphire::ScriptAPI::EventScript( 65914 ){}; 
  ~SubFst057() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000748
  //ENEMY0 = 3812252
  //ENEMY1 = 3856501
  //EOBJECT0 = 2001083
  //EOBJECT1 = 2001084
  //EVENTACTIONSEARCH = 1
  //SEQ0ACTOR0 = 0
  //SEQ1EOBJECT0 = 1
  //SEQ1EOBJECT0EVENTACTIONNO = 99
  //SEQ1EOBJECT0EVENTACTIONOK = 100
  //SEQ1EOBJECT1 = 2
  //SEQ1EOBJECT1EVENTACTIONNO = 97
  //SEQ1EOBJECT1EVENTACTIONOK = 98
  //SEQ2ACTOR0 = 3

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ROSELINE
        break;
      }
      case 1:
      {
        if( actor == 2001083 || actorId == 2001083 ) // EOBJECT0 = unknown
        {
          // empty entry
        }
        if( actor == 3812252 || actorId == 3812252 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            player.setQuestUI8AL( getId(), 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 2001084 || actorId == 2001084 ) // EOBJECT1 = unknown
        {
          // empty entry
        }
        if( actor == 3856501 || actorId == 3856501 ) // ENEMY1 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            player.setQuestUI8BL( getId(), 1 );
            checkProgressSeq1( player );
          }
        }
        break;
      }
      case 255:
      {
        Scene00003( player ); // Scene00003: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ROSELINE
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
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.updateQuest( getId(), 255 );
      }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubFst057:65914 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ROSELINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubFst057:65914 calling Scene00003: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ROSELINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubFst057 );
