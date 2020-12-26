// FFXIVTheMovie.ParserV3.2
// id hint used:
//ACTOR4 = actor4
//SCENE_23 = dummyt0
//SCENE_24 = dummyt0
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdc108 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdc108() : Sapphire::ScriptAPI::EventScript( 68565 ){}; 
  ~StmBdc108() = default; 

  //SEQ_0, 10 entries
  //SEQ_1, 10 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1025008
  //ACTOR1 = 1025009
  //ACTOR10 = 1025012
  //ACTOR11 = 1024971
  //ACTOR12 = 1024972
  //ACTOR13 = 1025016
  //ACTOR14 = 1025017
  //ACTOR15 = 1025018
  //ACTOR16 = 1025019
  //ACTOR17 = 1025020
  //ACTOR18 = 1025021
  //ACTOR19 = 1025022
  //ACTOR2 = 1025010
  //ACTOR20 = 1020622
  //ACTOR21 = 1025023
  //ACTOR22 = 1025024
  //ACTOR23 = 1020214
  //ACTOR3 = 1025000
  //ACTOR4 = 1025001
  //ACTOR5 = 1024994
  //ACTOR6 = 1024995
  //ACTOR7 = 1024996
  //ACTOR8 = 1025026
  //ACTOR9 = 1025354
  //LOCENPCALISAIE01 = 1019541
  //LOCENPCALPH01 = 1011887
  //LOCENPCASAHI01 = 1024637
  //LOCENPCYUU01 = 1019096
  //LOCLEVELASAHISTART = 7242167
  //LOCQUESTCHECK01 = 68551
  //LOCSE01 = 171
  //LOCSE02 = 172
  //LOCTOWNALISAIE01 = 7226672
  //LOCTOWNALPH01 = 7226673
  //LOCTOWNASAHI01 = 7226703
  //LOCTOWNMAX01 = 7226707
  //LOCTOWNNONAME01 = 7226708
  //LOCTOWNYUU01 = 7226688
  //NCUT01 = 1686
  //NCUT02 = 1687
  //NCUT03 = 1688
  //NCUT04 = 1689
  //NCUT05 = 1690
  //NCUT06 = 1753
  //NCUT07 = 1691
  //NCUT08 = 1692
  //POPRANGE0 = 7226900
  //POPRANGE1 = 7226649
  //TERRITORYTYPE0 = 744
  //TERRITORYTYPE1 = 614

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1025008 || param2 == 1025008 ) // ACTOR0 = HIEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HIEN
          // +Callback Scene00002: Normal(CutScene, AutoFadeIn), id=unknown
          // +Callback Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1025009 || param2 == 1025009 ) // ACTOR1 = ALISAIE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025010 || param2 == 1025010 ) // ACTOR2 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025000 || param2 == 1025000 ) // ACTOR3 = HAKURO
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1025001 || param2 == 1025001 ) // ACTOR4 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1024994 || param2 == 1024994 ) // ACTOR5 = ASAHI
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ASAHI
          break;
        }
        if( param1 == 1024995 || param2 == 1024995 ) // ACTOR6 = MAXIMA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=MAXIMA
          break;
        }
        if( param1 == 1024996 || param2 == 1024996 ) // ACTOR7 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025026 || param2 == 1025026 ) // ACTOR8 = YUGIRI
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1025354 || param2 == 1025354 ) // ACTOR9 = KIENKANGATEKEEPER03028
        {
          Scene00012( player ); // Scene00012: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=KIENKANGATEKEEPER03028
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1025012 || param2 == 1025012 ) // ACTOR10 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1025012 || param2 == 1025012 ) // ACTOR10 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1024971 || param2 == 1024971 ) // ACTOR11 = ALISAIE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1024972 || param2 == 1024972 ) // ACTOR12 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025026 || param2 == 1025026 ) // ACTOR8 = YUGIRI
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1025016 || param2 == 1025016 ) // ACTOR13 = ASAHI
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ASAHI
          break;
        }
        if( param1 == 1025017 || param2 == 1025017 ) // ACTOR14 = MAXIMA
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=MAXIMA
          break;
        }
        if( param1 == 1025018 || param2 == 1025018 ) // ACTOR15 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025000 || param2 == 1025000 ) // ACTOR3 = HAKURO
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1025001 || param2 == 1025001 ) // ACTOR4 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = dummyt0
        {
          Scene00023( player ); // Scene00023: Normal(CutScene), id=dummyt0
          // +Callback Scene00024: Normal(CutScene, AutoFadeIn), id=dummyt0
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1025019 || param2 == 1025019 ) // ACTOR16 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00025( player ); // Scene00025: Normal(Talk, FadeIn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1025020 || param2 == 1025020 ) // ACTOR17 = ALISAIE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025021 || param2 == 1025021 ) // ACTOR18 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025022 || param2 == 1025022 ) // ACTOR19 = YUGIRI
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR20 = HANCOCK
        {
          Scene00029( player ); // Scene00029: Normal(Talk, CutScene, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1025023 || param2 == 1025023 ) // ACTOR21 = ALPHINAUD
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025024 || param2 == 1025024 ) // ACTOR22 = ALISAIE
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025019 || param2 == 1025019 ) // ACTOR16 = HIEN
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1025022 || param2 == 1025022 ) // ACTOR19 = YUGIRI
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020214 || param2 == 1020214 ) // ACTOR23 = TATARU
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=TATARU
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdc108:68565 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00002: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00006: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00008: Normal(Talk, TargetCanMove), id=ASAHI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00009: Normal(Talk, TargetCanMove), id=MAXIMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00012: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=KIENKANGATEKEEPER03028" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00017: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00018: Normal(Talk, TargetCanMove), id=ASAHI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00019: Normal(Talk, TargetCanMove), id=MAXIMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00021: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00023: Normal(CutScene), id=dummyt0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00024( player );
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00024: Normal(CutScene, AutoFadeIn), id=dummyt0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 614, 368.38, 1.5, 743.7, 0, false );
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00025: Normal(Talk, FadeIn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00026: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00028: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00029: Normal(Talk, CutScene, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HANCOCK" );
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
    player.playScene( getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00031: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00032: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBdc108:68565 calling Scene00034: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdc108 );
