// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_3 = RAUBAHN
//EOBJECT0 = dummye0
//SCENE_6 = dummyt0
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdg102 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdg102() : Sapphire::ScriptAPI::EventScript( 68721 ){}; 
  ~StmBdg102() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 3 entries
  //SEQ_3, 8 entries
  //SEQ_255, 8 entries

  //ACTIONTIMELINEFACIALSALUTE = 624
  //ACTIONTIMELINEFACIALSMILEWK = 6215
  //ACTOR0 = 1026804
  //ACTOR1 = 1026845
  //ACTOR2 = 1026787
  //ACTOR3 = 1012163
  //ACTOR4 = 1012337
  //ACTOR5 = 1017026
  //ACTOR6 = 1018138
  //ACTOR7 = 1018139
  //ACTOR8 = 1020622
  //ACTOR9 = 1026990
  //BGMEVENTODAYAKA01 = 400
  //CUTSCENE0 = 1887
  //CUTSCENE1 = 1889
  //CUTSCENE2 = 1890
  //CUTSCENE3 = 1891
  //CUTSCENE4 = 1892
  //CUTSCENE5 = 1893
  //CUTSCENE6 = 1894
  //CUTSCENE7 = 1895
  //CUTSCENE8 = 2123
  //EOBJECT0 = 2009668
  //LCUTACTOR0 = 1017682
  //LCUTPOS0 = 7741252
  //LCUTPOS1 = 7741251
  //POPRANGE0 = 7738452
  //POPRANGE1 = 7741250
  //POPRANGE2 = 7765187
  //QSTCHECK01 = 66735
  //QSTCHECK02 = 67245
  //QUEST0 = 66738
  //QUEST1 = 66031
  //QUESTBATTLE0 = 5028
  //TERRITORYTYPE0 = 830
  //TERRITORYTYPE1 = 829
  //TERRITORYTYPE2 = 418
  //TERRITORYTYPE3 = 351

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=unknown
        break;
      }
      case 1:
      {
        if( param1 == 1026845 || param2 == 1026845 ) // ACTOR1 = RAUBAHN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, QuestBattle, YesNo, TargetCanMove, SystemTalk, CanCancel), id=RAUBAHN
            // +Callback Scene00003: Normal(CutScene, AutoFadeIn), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1026804 || param2 == 1026804 ) // ACTOR0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(Talk, YesNo, TargetCanMove), id=unknown
          break;
        }
        if( param1 == 2009668 || param2 == 2009668 ) // EOBJECT0 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = dummyt0
        {
          Scene00006( player ); // Scene00006: Normal(CutScene), id=dummyt0
          break;
        }
        if( param1 == 1026845 || param2 == 1026845 ) // ACTOR1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(YesNo, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1026804 || param2 == 1026804 ) // ACTOR0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(Talk, YesNo, TargetCanMove), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00010( player ); // Scene00010: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1026787 || param2 == 1026787 ) // ACTOR2 = EDMONT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=EDMONT
          break;
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR3 = HANDELOUP
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=HANDELOUP
          break;
        }
        if( param1 == 1012337 || param2 == 1012337 ) // ACTOR4 = BUTLER02246
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=BUTLER02246
          break;
        }
        if( param1 == 1017026 || param2 == 1017026 ) // ACTOR5 = SAULETTE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=SAULETTE
          break;
        }
        if( param1 == 1018138 || param2 == 1018138 ) // ACTOR6 = EMMANELLAIN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1018139 || param2 == 1018139 ) // ACTOR7 = HONOROIT
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR8 = HANCOCK
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1026990 || param2 == 1026990 ) // ACTOR9 = RAUBAHN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn), id=RAUBAHN
          // +Callback Scene00019: Normal(CutScene, FadeIn, SystemTalk), id=unknown
          break;
        }
        if( param1 == 1026787 || param2 == 1026787 ) // ACTOR2 = EDMONT
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=EDMONT
          break;
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR3 = HANDELOUP
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=HANDELOUP
          break;
        }
        if( param1 == 1012337 || param2 == 1012337 ) // ACTOR4 = BUTLER02246
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=BUTLER02246
          break;
        }
        if( param1 == 1017026 || param2 == 1017026 ) // ACTOR5 = SAULETTE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=SAULETTE
          break;
        }
        if( param1 == 1018138 || param2 == 1018138 ) // ACTOR6 = EMMANELLAIN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1018139 || param2 == 1018139 ) // ACTOR7 = HONOROIT
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR8 = HANCOCK
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=HANCOCK
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdg102:68721 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 829 );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00002: Normal(Talk, QuestBattle, YesNo, TargetCanMove, SystemTalk, CanCancel), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00003( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00003: Normal(CutScene, AutoFadeIn), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      Scene00006( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00004: Normal(Talk, YesNo, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdg102:68721 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00006: Normal(CutScene), id=dummyt0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 351 );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00007: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00008: Normal(YesNo, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00006( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00009: Normal(Talk, YesNo, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdg102:68721 calling Scene00010: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00011: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00012: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00013: Normal(Talk, TargetCanMove), id=BUTLER02246" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00014: Normal(Talk, TargetCanMove), id=SAULETTE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00015: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00016: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00017: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00019( player );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00019: Normal(CutScene, FadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00020: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00021: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00022: Normal(Talk, TargetCanMove), id=BUTLER02246" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00023: Normal(Talk, TargetCanMove), id=SAULETTE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00024: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00025: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBdg102:68721 calling Scene00026: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdg102 );
