// FFXIVTheMovie.ParserV3.6
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
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1007478 || param2 == 1007478 ) // ACTOR0 = URIANGER
        {
          Scene00000( player ); // Scene00000: Normal(YesNo, QuestOffer, TargetCanMove, SystemTalk), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1007684 || param2 == 1007684 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
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
    player.sendDebug( "emote: {}", emoteId );
    onProgress( player, actorId, actor, 1, emoteId );
  }

  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
  {
    onProgress( player, npcId, 0, 2, 0 );
  }

  void onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( player, param1, param1, 3, 0 );
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

  //Key functions found in scene 0
  //A0_0.SystemTalk(A0_0.TEXT_GAIUSD102_01160_SYSTEM_000_100, true)
  //A0_0.YesNo(A0_0.TEXT_GAIUSD102_01160_Q1_000_000)
  //A0_0.QuestOffer(A2_2, A1_1)
  //=======================
  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsd102:66696 calling Scene00000: Normal(YesNo, QuestOffer, TargetCanMove, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  //Key functions found in scene 1
  //A0_3.QuestAccepted()
  //=======================
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsd102:66696 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  //Key functions found in scene 2
  //=======================
  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd102:66696 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  //Key functions found in scene 3
  //A0_9.FadeIn(A0_9, A0_9.FADE_DEFAULT)
  //A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0).Talk(A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0)
  //A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0).Talk(A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0)
  //A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0).Talk(A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0)
  //A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0).Talk(A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0)
  //A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0).Talk(A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0)
  //A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0).Talk(A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0)
  //A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0).Talk(A0_9.CreateCharacter(A0_9, A0_9.LOC_ACTOR0, A0_9.LOC_POS_ACTOR0)
  //A0_9.QuestReward(A0_9, A2_11, A1_10)
  //A0_9.QuestCompleted()
  //=======================
  void Scene00003( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
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
  //Key functions found in scene 100
  //A0_15.PlayCutScene(A0_15.CUTSCENE_QREDO_01)
  //A0_15.PlayCutScene(A0_15.CUTSCENE_QREDO_02)
  //A0_15.PlayCutScene(A0_15.CUTSCENE_QREDO_03)
  //A0_15.PlayCutScene(A0_15.CUTSCENE_QREDO_04)
  //A0_15.PlayCutScene(A0_15.CUTSCENE_QREDO_05)
  //A0_15.FadeIn(A0_15.FADE_SHORT, A0_15.FADE_LAYER_MIDDLE)
  //A0_15.QuestOffer(A2_17, A1_16)
  //=======================
  void Scene00100( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd102:66696 calling Scene00100: Normal(CutScene, FadeIn, QuestOffer), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };
    player.playScene( getId(), 100, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( GaiUsd102 );
