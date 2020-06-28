// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsd301 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsd301() : Sapphire::ScriptAPI::EventScript( 66849 ){}; 
  ~GaiUsd301() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1007478
  //ACTOR1 = 1008538
  //ACTOR2 = 1008539
  //LOCACTOR0 = 1004145
  //LOCACTOR1 = 1004146
  //LOCPOSCAM1 = 4666843
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKIMAGEDUNGEON = 190

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, TargetCanMove), id=URIANGER
        // +Callback Scene00002: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=URIANGER
        break;
      }
      case 1:
      {
        Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ANAELLE
        break;
      }
      case 2:
      {
        Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=FOLLOWER01313
        break;
      }
      case 255:
      {
        if( actor == 1008538 || actorId == 1008538 ) // ACTOR1 = ANAELLE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, Message, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ANAELLE
        }
        if( actor == 1008539 || actorId == 1008539 ) // ACTOR2 = FOLLOWER01313
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=FOLLOWER01313
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
    player.sendDebug( "GaiUsd301:66849 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd301:66849 calling [BranchTrue]Scene00001: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd301:66849 calling [BranchChain]Scene00002: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd301:66849 calling Scene00003: Normal(Talk, TargetCanMove), id=ANAELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd301:66849 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=FOLLOWER01313" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd301:66849 calling Scene00005: Normal(Talk, Message, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ANAELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd301:66849 calling Scene00006: Normal(Talk, TargetCanMove), id=FOLLOWER01313" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsd301 );
