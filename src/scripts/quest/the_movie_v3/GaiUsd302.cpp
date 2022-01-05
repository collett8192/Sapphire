// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsd302 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsd302() : Sapphire::ScriptAPI::EventScript( 66850 ){}; 
  ~GaiUsd302() = default; 

  //SEQ_0, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1008540
  //ACTOR1 = 1007478
  //CUTSCENEFOREST1 = 491
  //CUTSCENEFOREST2 = 492
  //CUTSCENEQREDO01 = 477
  //CUTSCENEQREDO02 = 480
  //CUTSCENEQREDO03 = 485
  //CUTSCENEQREDO04 = 489
  //LOCACTOR0 = 1004145
  //LOCACTOR1 = 1004146
  //LOCBGM1 = 93
  //LOCPOSACTOR0 = 4667120
  //LOCPOSACTOR1 = 4667123

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(YesNo, QuestOffer, TargetCanMove, SystemTalk), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALISAIE
        break;
      }
      case 255:
      {
        if( param1 == 1007478 || param2 == 1007478 ) // ACTOR1 = URIANGER
        {
          Scene00002( player ); // Scene00002: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER
          // +Callback Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1008540 || param2 == 1008540 ) // ACTOR0 = ALISAIE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
          // +Callback Scene00100: Normal(CutScene, FadeIn, QuestOffer), id=unknown
          break;
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
  //A0_0.SystemTalk(A0_0.TEXT_GAIUSD302_01314_SYSTEM_000_100, true)
  //A0_0.YesNo(A0_0.TEXT_GAIUSD302_01314_Q1_000_000)
  //A0_0.QuestOffer(A2_2, A1_1)
  //=======================
  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd302:66850 calling Scene00000: Normal(YesNo, QuestOffer, TargetCanMove, SystemTalk), id=unknown" );
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
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd302:66850 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  //Key functions found in scene 2
  //A0_6.QuestReward(A0_6, A2_8, A1_7)
  //A0_6.QuestCompleted()
  //=======================
  void Scene00002( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd302:66850 calling Scene00002: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00003( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  //Key functions found in scene 3
  //A0_11.FadeIn(A0_11.FADE_DEFAULT)
  //A0_11.CreateCharacter(A0_11, A0_11.LOC_ACTOR1, A2_13, A0_11.ARRANGE_TYPE_RIGHT, 1).Talk(A1_12, A0_11, A0_11.TEXT_GAIUSD302_01314_ALISAIE_000_026, true, nil, nil, nil, A0_11.LIP_TYPE_NONE)
  //A0_11.CreateCharacter(A0_11, A0_11.LOC_ACTOR1, A2_13, A0_11.ARRANGE_TYPE_RIGHT, 1).Talk(A1_12, A0_11, A0_11.TEXT_GAIUSD302_01314_ALISAIE_000_028, true, nil, nil, nil, A0_11.SPEAK_NORMAL_MIDDLE)
  //A0_11.CreateCharacter(A0_11, A0_11.LOC_ACTOR1, A2_13, A0_11.ARRANGE_TYPE_RIGHT, 1).Talk(A1_12, A0_11, A0_11.TEXT_GAIUSD302_01314_ALISAIE_000_037, false, nil, nil, nil, A0_11.SPEAK_NORMAL_MIDDLE)
  //A0_11.CreateCharacter(A0_11, A0_11.LOC_ACTOR1, A2_13, A0_11.ARRANGE_TYPE_RIGHT, 1).Talk(A1_12, A0_11, A0_11.TEXT_GAIUSD302_01314_ALISAIE_000_038, true, nil, nil, nil, A0_11.SPEAK_NORMAL_MIDDLE)
  //A0_11.CreateCharacter(A0_11, A0_11.LOC_ACTOR1, A2_13, A0_11.ARRANGE_TYPE_RIGHT, 1).Talk(A1_12, A0_11, A0_11.TEXT_GAIUSD302_01314_ALISAIE_000_039, false, nil, nil, nil, A0_11.SPEAK_NORMAL_MIDDLE)
  //A0_11.CreateCharacter(A0_11, A0_11.LOC_ACTOR1, A2_13, A0_11.ARRANGE_TYPE_RIGHT, 1).Talk(A1_12, A0_11, A0_11.TEXT_GAIUSD302_01314_ALISAIE_000_040, true, nil, nil, nil, A0_11.SPEAK_NORMAL_MIDDLE)
  //A0_11.CreateCharacter(A0_11, A0_11.LOC_ACTOR1, A2_13, A0_11.ARRANGE_TYPE_RIGHT, 1).Talk(A1_12, A0_11, A0_11.TEXT_GAIUSD302_01314_ALISAIE_000_041, true, nil, nil, nil, A0_11.SPEAK_NORMAL_MIDDLE)
  //A0_11.CreateCharacter(A0_11, A0_11.LOC_ACTOR1, A2_13, A0_11.ARRANGE_TYPE_RIGHT, 1).Talk(A1_12, A0_11, A0_11.TEXT_GAIUSD302_01314_ALISAIE_000_043, true, nil, nil, nil, A0_11.SPEAK_NORMAL_MIDDLE)
  //A0_11.CreateCharacter(A0_11, A0_11.LOC_ACTOR1, A2_13, A0_11.ARRANGE_TYPE_RIGHT, 1).Talk(A1_12, A0_11, A0_11.TEXT_GAIUSD302_01314_ALISAIE_000_044, false, nil, nil, nil, A0_11.SPEAK_NORMAL_MIDDLE)
  //A0_11.CreateCharacter(A0_11, A0_11.LOC_ACTOR1, A2_13, A0_11.ARRANGE_TYPE_RIGHT, 1).Talk(A1_12, A0_11, A0_11.TEXT_GAIUSD302_01314_ALISAIE_000_045, true, nil, nil, nil, A0_11.SPEAK_NORMAL_MIDDLE)
  //A0_11.FadeIn(A0_11.FADE_SHORT, A0_11.FADE_LAYER_BACK)
  //A0_11.CreateCharacter(A0_11, A0_11.LOC_ACTOR0, A0_11.LOC_POS_ACTOR0).Talk(A1_12, A0_11, A0_11.TEXT_GAIUSD302_01314_ALPHINAUD_000_050, false, nil, nil, nil, A0_11.SPEAK_NORMAL_MIDDLE)
  //A0_11.CreateCharacter(A0_11, A0_11.LOC_ACTOR0, A0_11.LOC_POS_ACTOR0).Talk(A1_12, A0_11, A0_11.TEXT_GAIUSD302_01314_ALPHINAUD_000_051, true, nil, nil, nil, A0_11.SPEAK_NORMAL_MIDDLE)
  //A0_11.CreateCharacter(A0_11, A0_11.LOC_ACTOR0, A0_11.LOC_POS_ACTOR0).Talk(A1_12, A0_11, A0_11.TEXT_GAIUSD302_01314_ALPHINAUD_000_052, true, nil, nil, nil, A0_11.SPEAK_NORMAL_MIDDLE)
  //=======================
  void Scene00003( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd302:66850 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  //Key functions found in scene 4
  //=======================
  void Scene00004( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd302:66850 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00100( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  //Key functions found in scene 100
  //A0_20.PlayCutScene(A0_20.CUTSCENE_QREDO_01)
  //A0_20.PlayCutScene(A0_20.CUTSCENE_QREDO_02)
  //A0_20.PlayCutScene(A0_20.CUTSCENE_QREDO_03)
  //A0_20.PlayCutScene(A0_20.CUTSCENE_QREDO_04)
  //A0_20.PlayCutScene(A0_20.CUTSCENE_FOREST_1)
  //A0_20.PlayCutScene(A0_20.CUTSCENE_FOREST_2)
  //A0_20.FadeIn(A0_20.FADE_SHORT, A0_20.FADE_LAYER_MIDDLE)
  //A0_20.QuestOffer(A2_22, A1_21)
  //=======================
  void Scene00100( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd302:66850 calling Scene00100: Normal(CutScene, FadeIn, QuestOffer), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 100, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( GaiUsd302 );
