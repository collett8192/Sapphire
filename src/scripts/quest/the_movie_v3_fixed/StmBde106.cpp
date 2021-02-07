// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBde106 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBde106() : Sapphire::ScriptAPI::EventScript( 68684 ){}; 
  ~StmBde106() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 8 entries
  //SEQ_4, 8 entries
  //SEQ_5, 5 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1026284
  //ACTOR1 = 1026283
  //ACTOR10 = 1025000
  //ACTOR11 = 1020622
  //ACTOR12 = 1025001
  //ACTOR13 = 1024974
  //ACTOR14 = 1026241
  //ACTOR15 = 1026285
  //ACTOR16 = 1024152
  //ACTOR17 = 1025597
  //ACTOR18 = 1024065
  //ACTOR19 = 1026242
  //ACTOR2 = 1025874
  //ACTOR20 = 1026243
  //ACTOR21 = 1026244
  //ACTOR22 = 1026245
  //ACTOR23 = 1026246
  //ACTOR3 = 1025875
  //ACTOR4 = 1026239
  //ACTOR5 = 1026238
  //ACTOR6 = 1026469
  //ACTOR7 = 1025876
  //ACTOR8 = 1025552
  //ACTOR9 = 1025545
  //LOCBINDALSARM01 = 7587628
  //LOCBINDCIROFE01 = 6851362
  //LOCBINDHINKIEN01 = 7350604
  //LOCBINDHINOFE01 = 7593416
  //LOCBINDHKRKIEN01 = 7227012
  //LOCBINDKNSMED01 = 7587634
  //LOCBINDLYSMED01 = 7587636
  //LOCBINDNNSKIEN01 = 7227013
  //LOCBINDWRDMED01 = 7587635
  //LOCBINDYGRKIEN01 = 7343652
  //LOCBINDYSHARM01 = 7074896
  //LOCBINDYSHKIEN01 = 7587604
  //LOCBINDYSHKUSABI01 = 7587558
  //LOCBINDYSHMED01 = 7587638
  //LOCENPCYSH01 = 1025001
  //LOCFACE01 = 6215
  //LOCFACE02 = 624
  //LOCNCUT01 = 1816
  //LOCNCUT02 = 1817
  //LOCNCUT03 = 1818
  //POPRANGE0 = 7226900
  //POPRANGE1 = 7587642
  //SEEVENTLINK = 42
  //TERRITORYTYPE0 = 744

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1026284 || param2 == 1026284 ) // ACTOR0 = YSHTOLA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1026283 || param2 == 1026283 ) // ACTOR1 = HIEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1025874 || param2 == 1025874 ) // ACTOR2 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA
            // +Callback Scene00004: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1025875 || param2 == 1025875 ) // ACTOR3 = HIEN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1026239 || param2 == 1026239 ) // ACTOR4 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1026238 || param2 == 1026238 ) // ACTOR5 = YSHTOLA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1026469 || param2 == 1026469 ) // ACTOR6 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1025876 || param2 == 1025876 ) // ACTOR7 = YSHTOLA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1025552 || param2 == 1025552 ) // ACTOR8 = HIEN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1025545 || param2 == 1025545 ) // ACTOR9 = YUGIRI
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1025000 || param2 == 1025000 ) // ACTOR10 = HAKURO
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR11 = HANCOCK
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1025001 || param2 == 1025001 ) // ACTOR12 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1024974 || param2 == 1024974 ) // ACTOR13 = KIENKANGATEKEEPER03028
        {
          Scene00015( player ); // Scene00015: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1026241 || param2 == 1026241 ) // ACTOR14 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=THANCRED
          }
          break;
        }
        if( param1 == 1026285 || param2 == 1026285 ) // ACTOR15 = ALISAIE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1024152 || param2 == 1024152 ) // ACTOR16 = YSHTOLA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1025597 || param2 == 1025597 ) // ACTOR17 = HIEN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1025545 || param2 == 1025545 ) // ACTOR9 = YUGIRI
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1025000 || param2 == 1025000 ) // ACTOR10 = HAKURO
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR11 = HANCOCK
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1025001 || param2 == 1025001 ) // ACTOR12 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1024065 || param2 == 1024065 ) // ACTOR18 = RESISTANCEGATEGUARD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Talk, YesNo, TargetCanMove, SystemTalk, CanCancel), id=RESISTANCEGATEGUARD
            // +Callback Scene00025: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1024152 || param2 == 1024152 ) // ACTOR16 = YSHTOLA
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1026241 || param2 == 1026241 ) // ACTOR14 = THANCRED
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1026285 || param2 == 1026285 ) // ACTOR15 = ALISAIE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR11 = HANCOCK
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1026242 || param2 == 1026242 ) // ACTOR19 = ALISAIE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=ALISAIE
          break;
        }
        if( param1 == 1026243 || param2 == 1026243 ) // ACTOR20 = KANESENNA
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=KANESENNA
          break;
        }
        if( param1 == 1026244 || param2 == 1026244 ) // ACTOR21 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1026245 || param2 == 1026245 ) // ACTOR22 = LYSE
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1026246 || param2 == 1026246 ) // ACTOR23 = YSHTOLA
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1024065 || param2 == 1024065 ) // ACTOR18 = RESISTANCEGATEGUARD
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR11 = HANCOCK
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=HANCOCK
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBde106:68684 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00002: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00005: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00007: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00010: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00012: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00013: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00015: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 744 );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00016: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00019: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00021: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00022: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00024: Normal(Talk, YesNo, TargetCanMove, SystemTalk, CanCancel), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00025( player );
      }
    };
    player.playScene( getId(), 24, NONE, callback );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00025: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00026: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00027: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00029: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=ALISAIE" );
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
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00031: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00033: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00034: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00035: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBde106:68684 calling Scene00036: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBde106 );
