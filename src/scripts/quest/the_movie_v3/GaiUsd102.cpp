// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsd102 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsd102() : Sapphire::ScriptAPI::EventScript( 66696 ){}; 
  ~GaiUsd102() = default; 

  //SEQ_0, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1007478
  //ACTOR1 = 1007684
  //CUTSCENEQREDO01 = 376
  //CUTSCENEQREDO02 = 377
  //CUTSCENEQREDO03 = 386
  //CUTSCENEQREDO04 = 389
  //CUTSCENEQREDO05 = 390
  //LOCACTOR0 = 1008180
  //LOCBGM1 = 93
  //LOCPOSACTOR0 = 4330030

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1007478 || actorId == 1007478 ) // ACTOR0 = URIANGER
        {
          Scene00000( player ); // Scene00000: Normal(YesNo, QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER
        }
        if( actor == 1007684 || actorId == 1007684 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 255:
      {
        Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
        // +Callback Scene00100: Normal(CutScene, FadeIn, QuestOffer), id=unknown
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd102:66696 calling Scene00000: Normal(YesNo, QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsd102:66696 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd102:66696 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd102:66696 calling Scene00003: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00100( player );
      }
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00100( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd102:66696 calling [BranchTrue]Scene00100: Normal(CutScene, FadeIn, QuestOffer), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 100, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( GaiUsd102 );
