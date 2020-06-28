// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst070 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst070() : Sapphire::ScriptAPI::EventScript( 65756 ){}; 
  ~SubFst070() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000101
  //ACTOR1 = 1000105
  //GLASSIGNMENT = 393217
  //LEVE = 546
  //SEQ0ACTOR0 = 0
  //SEQ1ACTOR01 = 5
  //SEQ1ACTOR02 = 6
  //SEQ1ACTOR11 = 1
  //SEQ1ACTOR12 = 2
  //SEQ1ACTOR13 = 7
  //SEQ3ACTOR0 = 8
  //SEQ3ACTOR2 = 3
  //SEQ4ACTOR0 = 9
  //SEQ4ACTOR1 = 4
  //UNLOCKIMAGEGUILDORDER = 21
  //UNLOCKIMAGELEVE = 30

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=GONTRANT
        break;
      }
      case 1:
      {
        if( actor == 1000105 || actorId == 1000105 ) // ACTOR1 = TIERNEY
        {
          Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=TIERNEY
        }
        break;
      }
      case 2:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=TIERNEY
        break;
      }
      case 255:
      {
        Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TIERNEY
        // +Callback Scene00004: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TIERNEY
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubFst070:65756 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=GONTRANT" );
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
    player.sendDebug( "SubFst070:65756 calling Scene00001: Normal(Talk, TargetCanMove), id=TIERNEY" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubFst070:65756 calling Scene00002: Normal(Talk, TargetCanMove), id=TIERNEY" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubFst070:65756 calling Scene00003: Normal(Talk, TargetCanMove), id=TIERNEY" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubFst070:65756 calling [BranchTrue]Scene00004: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TIERNEY" );
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

EXPOSE_SCRIPT( SubFst070 );
