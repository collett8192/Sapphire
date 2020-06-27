// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil072 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil072() : Sapphire::ScriptAPI::EventScript( 65862 ){}; 
  ~SubWil072() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1001439
  //ACTOR1 = 1001436
  //ENEMY0 = 431
  //ITEM0 = 2000177
  //SEQ0ACTOR0 = 0
  //SEQ2ACTOR1 = 1
  //SEQ2ACTOR1NPCTRADENO = 99
  //SEQ2ACTOR1NPCTRADEOK = 100

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ZEZEDA
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 8
      case 1:
      {
        Scene00001( player ); // Scene00001: NpcTrade(Talk), id=BERINGAER
        // +Callback Scene00100: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BERINGAER
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 8
      case 255:
      {
        Scene00099( player ); // Scene00099: Normal(None), id=unknown
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
    player.setQuestUI8BH( getId(), 8 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil072:65862 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ZEZEDA" );
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
    player.sendDebug( "SubWil072:65862 calling Scene00001: NpcTrade(Talk), id=BERINGAER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00100( player );
      }
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00100( Entity::Player& player )
  {
    player.sendDebug( "SubWil072:65862 calling [BranchTrue]Scene00100: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BERINGAER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 100, NONE, callback );
  }

  void Scene00099( Entity::Player& player )
  {
    player.sendDebug( "SubWil072:65862 calling Scene00099: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubWil072 );
