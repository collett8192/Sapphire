// FFXIVTheMovie.ParserV3.2
// id hint used:
//ACROT0 = LYSE
//SCENE_2 = LYSE
//ACTOR1 = outter_gate_keeper_before_quest
//SCENE_3 = outter_gate_keeper_before_quest
//ACTOR3 = RESISTANCEGATEKEEPER
//SCENE_13 = HOARYBOULDER
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdf105 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdf105() : Sapphire::ScriptAPI::EventScript( 68719 ){}; 
  ~StmBdf105() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 3 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1026823
  //ACTOR1 = 1026958
  //ACTOR2 = 5010000
  //ACTOR3 = 1026804
  //ACTOR4 = 1026825
  //ACTOR5 = 1026845
  //ACTOR6 = 1026808
  //ACTOR7 = 1026846
  //INSTANCEDUNGEON0 = 64
  //LOCBGM01 = 74
  //LOCBINDHIN01 = 7738537
  //LOCENPCYUG01 = 1019096
  //LOCFACE01 = 6253
  //LOCNCUT01 = 1885
  //LOCNCUT02 = 1886
  //LOCNCUT03 = 2122
  //LOCSCREENIMAGE0 = 687
  //POPRANGE0 = 7738452
  //POPRANGE1 = 7738494
  //TERRITORYTYPE0 = 829

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1026823 || param2 == 1026823 ) // ACTOR0 = LYSE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(CutScene, FadeIn, QuestAccept, AutoFadeIn), id=unknown
          // +Callback Scene00002: Normal(FadeIn), id=LYSE
          break;
        }
        if( param1 == 1026958 || param2 == 1026958 ) // ACTOR1 = outter_gate_keeper_before_quest
        {
          Scene00003( player ); // Scene00003: Normal(Talk, YesNo, TargetCanMove), id=outter_gate_keeper_before_quest
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1026804 || param2 == 1026804 ) // ACTOR3 = RESISTANCEGATEKEEPER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER
          break;
        }
        if( param1 == 4302706352 || param2 == 4302706352 ) // ACTOR4 = RAUBAHN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00006( player ); // Scene00006: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1026804 || param2 == 1026804 ) // ACTOR3 = RESISTANCEGATEKEEPER
        {
          Scene00007( player ); // Scene00007: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1026845 || param2 == 1026845 ) // ACTOR5 = RAUBAHN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1026804 || param2 == 1026804 ) // ACTOR3 = RESISTANCEGATEKEEPER
        {
          Scene00009( player ); // Scene00009: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER
          break;
        }
        if( param1 == 1026808 || param2 == 1026808 ) // ACTOR6 = HIEN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1026846 || param2 == 1026846 ) // ACTOR7 = HOARYBOULDER
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HOARYBOULDER
          // +Callback Scene00012: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn), id=HOARYBOULDER
          // +Callback Scene00013: Normal(CutScene, TargetCanMove), id=HOARYBOULDER
          break;
        }
        if( param1 == 1026845 || param2 == 1026845 ) // ACTOR5 = RAUBAHN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=RAUBAHN
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
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdf105:68719 calling Scene00001: Normal(CutScene, FadeIn, QuestAccept, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00002: Normal(FadeIn), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00003: Normal(Talk, YesNo, TargetCanMove), id=outter_gate_keeper_before_quest" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 829 );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00004: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 829 );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00005: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00006: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00007: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 829 );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00009: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 829 );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00010: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00011: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00012: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00013: Normal(CutScene, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdf105:68719 calling Scene00014: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdf105 );
