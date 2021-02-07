// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_15 = HIEN
//ACTOR11 = TANSUI2
//SCENE_12 = TANSUI2
//SCENE_28 = TANSUI2
//SCENE_36 = TANSUI2
//ACTOR12 = CIRINA2
//SCENE_13 = CIRINA2
//SCENE_29 = CIRINA2
//SCENE_37 = CIRINA2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdf103 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdf103() : Sapphire::ScriptAPI::EventScript( 68717 ){}; 
  ~StmBdf103() = default; 

  //SEQ_0, 13 entries
  //SEQ_1, 15 entries
  //SEQ_255, 8 entries

  //ACTOR0 = 1026784
  //ACTOR1 = 1026785
  //ACTOR10 = 1025354
  //ACTOR11 = 1019935
  //ACTOR12 = 1020539
  //ACTOR13 = 1026261
  //ACTOR14 = 1026803
  //ACTOR15 = 1026265
  //ACTOR16 = 1026266
  //ACTOR17 = 1026267
  //ACTOR18 = 1025597
  //ACTOR19 = 1024974
  //ACTOR2 = 1026786
  //ACTOR20 = 1025545
  //ACTOR21 = 1025000
  //ACTOR22 = 1025001
  //ACTOR23 = 1021505
  //ACTOR3 = 1026788
  //ACTOR4 = 1026789
  //ACTOR5 = 1026790
  //ACTOR6 = 1026791
  //ACTOR7 = 1026792
  //ACTOR8 = 1026793
  //ACTOR9 = 1026259
  //LOCBINDALS01 = 7592104
  //LOCBINDALS02 = 7722002
  //LOCBINDHAK01 = 7732673
  //LOCBINDHAK02 = 7227012
  //LOCBINDNON01 = 7227013
  //LOCBINDYUG01 = 7732672
  //LOCBINDYUG02 = 7343652
  //LOCENPCALS01 = 1019541
  //LOCFACE01 = 625
  //LOCNCUT01 = 1881
  //LOCNCUT02 = 1882
  //LOCSE01 = 171
  //LOCSE02 = 172
  //POPRANGE0 = 7226900
  //POPRANGE1 = 7737246
  //TERRITORYTYPE0 = 744

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1026784 || param2 == 1026784 ) // ACTOR0 = HIEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1026785 || param2 == 1026785 ) // ACTOR1 = YUGIRI
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1026786 || param2 == 1026786 ) // ACTOR2 = HAKUROU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=HAKUROU
          break;
        }
        if( param1 == 1026788 || param2 == 1026788 ) // ACTOR3 = TANSUI
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1026789 || param2 == 1026789 ) // ACTOR4 = CIRINA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1026790 || param2 == 1026790 ) // ACTOR5 = AOKORAHERALD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=AOKORAHERALD
          break;
        }
        if( param1 == 1026791 || param2 == 1026791 ) // ACTOR6 = NAGUSAHERALD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=NAGUSAHERALD
          break;
        }
        if( param1 == 1026792 || param2 == 1026792 ) // ACTOR7 = DALMASCAHERALD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=DALMASCAHERALD
          break;
        }
        if( param1 == 1026793 || param2 == 1026793 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1026259 || param2 == 1026259 ) // ACTOR9 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025354 || param2 == 1025354 ) // ACTOR10 = KIENKANGATEKEEPER03028
        {
          Scene00011( player ); // Scene00011: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028
          break;
        }
        if( param1 == 1019935 || param2 == 1019935 ) // ACTOR11 = TANSUI2
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=TANSUI2
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR12 = CIRINA2
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=CIRINA2
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1026261 || param2 == 1026261 ) // ACTOR13 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=HIEN
            // +Callback Scene00015: Normal(CutScene, AutoFadeIn), id=HIEN
          }
          break;
        }
        if( param1 == 1026803 || param2 == 1026803 ) // ACTOR14 = ALISAIE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1026265 || param2 == 1026265 ) // ACTOR15 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1026266 || param2 == 1026266 ) // ACTOR16 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1026267 || param2 == 1026267 ) // ACTOR17 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1026785 || param2 == 1026785 ) // ACTOR1 = YUGIRI
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1026786 || param2 == 1026786 ) // ACTOR2 = HAKUROU
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=HAKUROU
          break;
        }
        if( param1 == 1026788 || param2 == 1026788 ) // ACTOR3 = TANSUI
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1026789 || param2 == 1026789 ) // ACTOR4 = CIRINA
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1026790 || param2 == 1026790 ) // ACTOR5 = AOKORAHERALD
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=AOKORAHERALD
          break;
        }
        if( param1 == 1026791 || param2 == 1026791 ) // ACTOR6 = NAGUSAHERALD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=NAGUSAHERALD
          break;
        }
        if( param1 == 1026792 || param2 == 1026792 ) // ACTOR7 = DALMASCAHERALD
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=DALMASCAHERALD
          break;
        }
        if( param1 == 1026793 || param2 == 1026793 ) // ACTOR8 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1019935 || param2 == 1019935 ) // ACTOR11 = TANSUI2
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=TANSUI2
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR12 = CIRINA2
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=CIRINA2
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1025597 || param2 == 1025597 ) // ACTOR18 = HIEN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=HIEN
          // +Callback Scene00031: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1024974 || param2 == 1024974 ) // ACTOR19 = KIENKANGATEKEEPER03028
        {
          Scene00032( player ); // Scene00032: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028
          break;
        }
        if( param1 == 1025545 || param2 == 1025545 ) // ACTOR20 = YUGIRI
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1025000 || param2 == 1025000 ) // ACTOR21 = HAKUROU
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=HAKUROU
          break;
        }
        if( param1 == 1025001 || param2 == 1025001 ) // ACTOR22 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 1019935 || param2 == 1019935 ) // ACTOR11 = TANSUI2
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=TANSUI2
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR12 = CIRINA2
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=CIRINA2
          break;
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR23 = RASHO
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=RASHO
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdf103:68717 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00003: Normal(Talk, TargetCanMove), id=HAKUROU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00004: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00005: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00006: Normal(Talk, TargetCanMove), id=AOKORAHERALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00007: Normal(Talk, TargetCanMove), id=NAGUSAHERALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00008: Normal(Talk, TargetCanMove), id=DALMASCAHERALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00011: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 744 );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00012: Normal(Talk, TargetCanMove), id=TANSUI2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00013: Normal(Talk, TargetCanMove), id=CIRINA2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00014: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00015( player );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00015: Normal(CutScene, AutoFadeIn), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 759, -4.2, 0, 15.6, -1.57, false );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00021: Normal(Talk, TargetCanMove), id=HAKUROU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00022: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00023: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00024: Normal(Talk, TargetCanMove), id=AOKORAHERALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00025: Normal(Talk, TargetCanMove), id=NAGUSAHERALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00026: Normal(Talk, TargetCanMove), id=DALMASCAHERALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00028: Normal(Talk, TargetCanMove), id=TANSUI2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00029: Normal(Talk, TargetCanMove), id=CIRINA2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00030: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00031( player );
    };
    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00031: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 31, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00032: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 744 );
      }
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00034: Normal(Talk, TargetCanMove), id=HAKUROU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00036: Normal(Talk, TargetCanMove), id=TANSUI2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00037: Normal(Talk, TargetCanMove), id=CIRINA2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBdf103:68717 calling Scene00038: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdf103 );
