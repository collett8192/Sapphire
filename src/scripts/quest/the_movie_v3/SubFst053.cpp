// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst053 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst053() : Sapphire::ScriptAPI::EventScript( 65695 ){}; 
  ~SubFst053() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000503
  //ENEMY0 = 1943223
  //ENEMY1 = 1943224
  //ENEMY2 = 1943225
  //EOBJECT0 = 2000042
  //ITEM0 = 2000095
  //SEQ0ACTOR0 = 0
  //SEQ1EOBJECT0 = 1
  //SEQ1EOBJECT0USEITEMNO = 99
  //SEQ1EOBJECT0USEITEMOK = 100
  //SEQ2ACTOR0 = 2

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ARMELLE
        break;
      }
      //seq 1 event item ITEM0 = UI8BL max stack ?
      case 1:
      {
        if( actor == 2000042 || actorId == 2000042 ) // EOBJECT0 = unknown
        {
          // empty entry
        }
        if( actor == 1943223 || actorId == 1943223 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 1943224 || actorId == 1943224 ) // ENEMY1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 1943225 || actorId == 1943225 ) // ENEMY2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ARMELLE
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
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubFst053:65695 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ARMELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubFst053:65695 calling Scene00002: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ARMELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubFst053 );
