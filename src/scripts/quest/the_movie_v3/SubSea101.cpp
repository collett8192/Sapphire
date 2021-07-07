// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea101 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea101() : Sapphire::ScriptAPI::EventScript( 65934 ){}; 
  ~SubSea101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1003239
  //ACTOR1 = 1003240
  //ACTOR2 = 1003241
  //ITEM0 = 2000338
  //ITEM1 = 2000339

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack 1
      //seq 0 event item ITEM1 = UI8BL max stack 1
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WYRKRHIT
        break;
      }
      //seq 1 event item ITEM0 = UI8BL max stack 1
      //seq 1 event item ITEM1 = UI8CH max stack 1
      case 1:
      {
        if( actor == 1003240 || actorId == 1003240 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            player.setQuestUI8AL( getId(), 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 1003241 || actorId == 1003241 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            player.setQuestUI8BH( getId(), 1 );
            checkProgressSeq1( player );
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      case 255:
      {
        Scene00003( player ); // Scene00003: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WYRKRHIT
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
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.updateQuest( getId(), 255 );
      }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea101:65934 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WYRKRHIT" );
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
    player.sendDebug( "SubSea101:65934 calling Scene00003: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WYRKRHIT" );
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

EXPOSE_SCRIPT( SubSea101 );