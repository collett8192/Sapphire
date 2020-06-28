// FFXIVTheMovie.ParserV3
//fix: weird lua structure, manual rewrite
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil073 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil073() : Sapphire::ScriptAPI::EventScript( 65863 ){}; 
  ~SubWil073() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1001447
  //ENEMY0 = 3742257
  //ENEMY1 = 3742258
  //ENEMY2 = 3742259
  //ENEMY3 = 3742261
  //EOBJECT0 = 2000377
  //EOBJECT1 = 2000378
  //EOBJECT2 = 2000379
  //EOBJECT3 = 2000380
  //EVENTACTIONSEARCH = 1
  //SEQ0ACTOR0 = 0
  //SEQ1EOBJECT0 = 1
  //SEQ1EOBJECT0EVENTACTIONNO = 99
  //SEQ1EOBJECT0EVENTACTIONOK = 100
  //SEQ1EOBJECT1 = 2
  //SEQ1EOBJECT1EVENTACTIONNO = 97
  //SEQ1EOBJECT1EVENTACTIONOK = 98
  //SEQ1EOBJECT2 = 3
  //SEQ1EOBJECT2EVENTACTIONNO = 95
  //SEQ1EOBJECT2EVENTACTIONOK = 96
  //SEQ1EOBJECT3 = 4
  //SEQ1EOBJECT3EVENTACTIONNO = 93
  //SEQ1EOBJECT3EVENTACTIONOK = 94
  //SEQ2ACTOR0 = 5

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WARIN
        break;
      }
      case 1:
      {
        if( actor == 2000377 || actorId == 2000377 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            player.setQuestUI8AL( getId(), 1 );
            player.setQuestBitFlag8( getId(), 1, true );
            player.setQuestUI8AH( getId(), player.getQuestUI8AH( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 3742257 || actorId == 3742257 ) // ENEMY0 = unknown
        {

        }
        if( actor == 2000378 || actorId == 2000378 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            player.setQuestUI8BL( getId(), 1 );
            player.setQuestBitFlag8( getId(), 2, true );
            player.setQuestUI8AH( getId(), player.getQuestUI8AH( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 3742258 || actorId == 3742258 ) // ENEMY1 = unknown
        {

        }
        if( actor == 2000379 || actorId == 2000379 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            player.setQuestUI8CL( getId(), 1 );
            player.setQuestBitFlag8( getId(), 3, true );
            player.setQuestUI8AH( getId(), player.getQuestUI8AH( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 3742259 || actorId == 3742259 ) // ENEMY2 = unknown
        {

        }
        if( actor == 2000380 || actorId == 2000380 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8DL( getId() ) != 1 )
          {
            player.setQuestUI8DL( getId(), 1 );
            player.setQuestBitFlag8( getId(), 4, true );
            player.setQuestUI8AH( getId(), player.getQuestUI8AH( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 3742261 || actorId == 3742261 ) // ENEMY3 = unknown
        {

        }
        break;
      }
      case 255:
      {
        Scene00005( player ); // Scene00005: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WARIN
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
          if( player.getQuestUI8DL( getId() ) == 1 )
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
    player.sendDebug( "SubWil073:65863 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WARIN" );
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
    player.sendDebug( "SubWil073:65863 calling Scene00005: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WARIN" );
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

EXPOSE_SCRIPT( SubWil073 );
