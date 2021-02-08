// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma101 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma101() : Sapphire::ScriptAPI::EventScript( 68815 ){}; 
  ~LucKma101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 12 entries
  //SEQ_3, 5 entries
  //SEQ_4, 6 entries
  //SEQ_5, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1026990
  //ACTOR1 = 1029791
  //ACTOR10 = 1029799
  //ACTOR11 = 1029801
  //ACTOR12 = 1029802
  //ACTOR13 = 1029803
  //ACTOR14 = 1030321
  //ACTOR15 = 1028924
  //ACTOR2 = 1029792
  //ACTOR3 = 1029793
  //ACTOR4 = 1029794
  //ACTOR5 = 1029795
  //ACTOR6 = 1029796
  //ACTOR7 = 1029797
  //ACTOR8 = 1029800
  //ACTOR9 = 1029798
  //CUTSCENE0 = 1943
  //CUTSCENE1 = 1954
  //CUTSCENE2 = 1956
  //CUTSCENE3 = 1957
  //EVENTRANGE0 = 7931870
  //LCUTBGM0 = 190
  //LCUTBGM1 = 239
  //POPRANGE0 = 8026738
  //POPRANGE1 = 7928434
  //POPRANGE2 = 7931857
  //POPRANGE3 = 7996041
  //POPRANGE4 = 7996142
  //POPRANGE5 = 7919036
  //POPRANGE6 = 8036159
  //TERRITORYTYPE0 = 842
  //TERRITORYTYPE1 = 877
  //TERRITORYTYPE2 = 819
  //TERRITORYTYPE3 = 813

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu, AutoFadeIn), id=TATARU
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=COINACHBOATMAN
        break;
      }
      case 2:
      {
        if( param1 == 1029792 || param2 == 1029792 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1029793 || param2 == 1029793 ) // ACTOR3 = HOARYBOULDER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=HOARYBOULDER
          break;
        }
        if( param1 == 1029794 || param2 == 1029794 ) // ACTOR4 = COULTENET
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=COULTENET
          break;
        }
        if( param1 == 1029795 || param2 == 1029795 ) // ACTOR5 = AENOR
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=AENOR
          break;
        }
        if( param1 == 1029796 || param2 == 1029796 ) // ACTOR6 = CLEMENCE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=CLEMENCE
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR7 = GARLONDMAN03279
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=GARLONDMAN03279
          break;
        }
        if( param1 == 1029800 || param2 == 1029800 ) // ACTOR8 = COINACHINVESTIGATOR03279
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=COINACHINVESTIGATOR03279
          break;
        }
        if( param1 == 1029798 || param2 == 1029798 ) // ACTOR9 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029799 || param2 == 1029799 ) // ACTOR10 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029801 || param2 == 1029801 ) // ACTOR11 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029802 || param2 == 1029802 ) // ACTOR12 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029791 || param2 == 1029791 ) // ACTOR1 = COINACHBOATMAN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, YesNo, TargetCanMove), id=COINACHBOATMAN
          break;
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00015( player ); // Scene00015: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1029792 || param2 == 1029792 ) // ACTOR2 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(YesNo), id=unknown
          break;
        }
        if( param1 == 1029791 || param2 == 1029791 ) // ACTOR1 = COINACHBOATMAN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, YesNo, TargetCanMove), id=COINACHBOATMAN
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR7 = GARLONDMAN03279
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=GARLONDMAN03279
          break;
        }
        if( param1 == 1029800 || param2 == 1029800 ) // ACTOR8 = COINACHINVESTIGATOR03279
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=COINACHINVESTIGATOR03279
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 7931870 || param2 == 7931870 ) // EVENTRANGE0 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1029803 || param2 == 1029803 ) // ACTOR13 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(YesNo), id=unknown
          break;
        }
        if( param1 == 1029791 || param2 == 1029791 ) // ACTOR1 = COINACHBOATMAN
        {
          Scene00022( player ); // Scene00022: Normal(Talk, YesNo, TargetCanMove), id=COINACHBOATMAN
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR7 = GARLONDMAN03279
        {
          Scene00023( player ); // Scene00023: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279
          break;
        }
        if( param1 == 1029800 || param2 == 1029800 ) // ACTOR8 = COINACHINVESTIGATOR03279
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=COINACHINVESTIGATOR03279
          break;
        }
        if( param1 == 1030321 || param2 == 1030321 ) // ACTOR14 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00026( player ); // Scene00026: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1029800 || param2 == 1029800 ) // ACTOR8 = COINACHINVESTIGATOR03279
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=COINACHINVESTIGATOR03279
          break;
        }
        if( param1 == 1030321 || param2 == 1030321 ) // ACTOR14 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029791 || param2 == 1029791 ) // ACTOR1 = COINACHBOATMAN
        {
          Scene00029( player ); // Scene00029: Normal(Talk, YesNo, TargetCanMove), id=COINACHBOATMAN
          break;
        }
        if( param1 == 1029803 || param2 == 1029803 ) // ACTOR13 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(YesNo), id=unknown
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR7 = GARLONDMAN03279
        {
          Scene00031( player ); // Scene00031: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1028924 || param2 == 1028924 ) // ACTOR15 = MYSTERYVOICE
        {
          Scene00032( player ); // Scene00032: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1029800 || param2 == 1029800 ) // ACTOR8 = COINACHINVESTIGATOR03279
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=COINACHINVESTIGATOR03279
          break;
        }
        if( param1 == 1030321 || param2 == 1030321 ) // ACTOR14 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029791 || param2 == 1029791 ) // ACTOR1 = COINACHBOATMAN
        {
          Scene00035( player ); // Scene00035: Normal(Talk, YesNo, TargetCanMove), id=COINACHBOATMAN
          break;
        }
        if( param1 == 1029803 || param2 == 1029803 ) // ACTOR13 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(YesNo), id=unknown
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR7 = GARLONDMAN03279
        {
          Scene00037( player ); // Scene00037: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "LucKma101:68815 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu, AutoFadeIn), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq0( player );
        player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
        player.eventFinish( getId(), 1 );
        player.forceZoneing();
      }
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00002: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=COINACHBOATMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        checkProgressSeq1( player );
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 842 );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00003: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 877 );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00004: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00005: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00006: Normal(Talk, TargetCanMove), id=AENOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00007: Normal(Talk, TargetCanMove), id=CLEMENCE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00008: Normal(Talk, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00009: Normal(Talk, TargetCanMove), id=COINACHINVESTIGATOR03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00014: Normal(Talk, YesNo, TargetCanMove), id=COINACHBOATMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 842 );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00015: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00016: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 877 );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00017: Normal(Talk, YesNo, TargetCanMove), id=COINACHBOATMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 842 );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00018: Normal(Talk, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00019: Normal(Talk, TargetCanMove), id=COINACHINVESTIGATOR03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00020: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 819, -179.6, 0, 0, 1.56, false );
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00021: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00022: Normal(Talk, YesNo, TargetCanMove), id=COINACHBOATMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 842 );
      }
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00023: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00024: Normal(Talk, TargetCanMove), id=COINACHINVESTIGATOR03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00026: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00027: Normal(Talk, TargetCanMove), id=COINACHINVESTIGATOR03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00029: Normal(Talk, YesNo, TargetCanMove), id=COINACHBOATMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 842 );
      }
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00030: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 819, -179.6, 0, 0, 1.56, false );
      }
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00031: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00032: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MYSTERYVOICE" );
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
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00033: Normal(Talk, TargetCanMove), id=COINACHINVESTIGATOR03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00035: Normal(Talk, YesNo, TargetCanMove), id=COINACHBOATMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00036: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKma101:68815 calling Scene00037: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 37, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKma101 );
