// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda101 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda101() : Sapphire::ScriptAPI::EventScript( 67982 ){}; 
  ~StmBda101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 9 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_4, 2 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1018330
  //ACTOR1 = 1020284
  //ACTOR10 = 1020300
  //ACTOR11 = 1018329
  //ACTOR12 = 1012813
  //ACTOR13 = 1020301
  //ACTOR14 = 1020302
  //ACTOR15 = 1020303
  //ACTOR16 = 1020304
  //ACTOR17 = 1020525
  //ACTOR18 = 1020526
  //ACTOR19 = 1020527
  //ACTOR2 = 1020285
  //ACTOR20 = 1020308
  //ACTOR21 = 1020495
  //ACTOR3 = 1020286
  //ACTOR4 = 1020287
  //ACTOR5 = 1020288
  //ACTOR6 = 1020289
  //ACTOR7 = 1020290
  //ACTOR8 = 1020291
  //ACTOR9 = 1020518
  //CUTSCENEN01 = 1379
  //CUTSCENEN02 = 1380
  //CUTSCENEN03 = 1381
  //LOCACTION01 = 112
  //LOCACTION02 = 113
  //LOCACTION03 = 114
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1017687
  //LOCACTOR03 = 1018384
  //LOCACTOR04 = 1018509
  //LOCACTOR05 = 1011889
  //LOCACTOR06 = 1015833
  //LOCACTOR07 = 1015903
  //LOCACTOR08 = 1011900
  //LOCACTOR09 = 1011891
  //LOCBGM01 = 77
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //LOCIDLE03 = 34
  //LOCSE01 = 78
  //POPRANGE0 = 6829336
  //POPRANGE1 = 6829350
  //POPRANGE2 = 6843192
  //TERRITORYTYPE0 = 612

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(CutScene, QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        if( param1 == 1020284 || param2 == 1020284 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(CutScene), id=unknown
            // +Callback Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1020285 || param2 == 1020285 ) // ACTOR2 = ALISAIE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020286 || param2 == 1020286 ) // ACTOR3 = LYSE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020287 || param2 == 1020287 ) // ACTOR4 = YSHTOLA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1020288 || param2 == 1020288 ) // ACTOR5 = KRILE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1020289 || param2 == 1020289 ) // ACTOR6 = YUGIRI
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020290 || param2 == 1020290 ) // ACTOR7 = GOSETSU
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1020291 || param2 == 1020291 ) // ACTOR8 = TATARU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1020518 || param2 == 1020518 ) // ACTOR9 = RIOL
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=RIOL
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020300 || param2 == 1020300 ) // ACTOR10 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1018329 || param2 == 1018329 ) // ACTOR11 = YSHTOLA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1012813 || param2 == 1012813 ) // ACTOR12 = KRILE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1020301 || param2 == 1020301 ) // ACTOR13 = ALISAIE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020302 || param2 == 1020302 ) // ACTOR14 = LYSE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020303 || param2 == 1020303 ) // ACTOR15 = SERPENTOFFICER
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020303 || param2 == 1020303 ) // ACTOR15 = SERPENTOFFICER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, YesNo, TargetCanMove), id=SERPENTOFFICER
          }
        }
        if( param1 == 1018329 || param2 == 1018329 ) // ACTOR11 = YSHTOLA
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1012813 || param2 == 1012813 ) // ACTOR12 = KRILE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1020301 || param2 == 1020301 ) // ACTOR13 = ALISAIE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020302 || param2 == 1020302 ) // ACTOR14 = LYSE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020300 || param2 == 1020300 ) // ACTOR10 = ALPHINAUD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00024( player ); // Scene00024: Normal(CutScene), id=unknown
        }
        if( param1 == 1020303 || param2 == 1020303 ) // ACTOR15 = SERPENTOFFICER
        {
          Scene00025( player ); // Scene00025: Normal(Talk, YesNo, TargetCanMove), id=SERPENTOFFICER
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020304 || param2 == 1020304 ) // ACTOR16 = RAUBAHN
        {
          Scene00026( player ); // Scene00026: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN
        }
        if( param1 == 1020525 || param2 == 1020525 ) // ACTOR17 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020526 || param2 == 1020526 ) // ACTOR18 = ALISAIE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020527 || param2 == 1020527 ) // ACTOR19 = LYSE
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020308 || param2 == 1020308 ) // ACTOR20 = KRILE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1020303 || param2 == 1020303 ) // ACTOR15 = SERPENTOFFICER
        {
          Scene00031( player ); // Scene00031: Normal(Talk, YesNo, TargetCanMove), id=SERPENTOFFICER
        }
        if( param1 == 1020495 || param2 == 1020495 ) // ACTOR21 = YSHTOLA
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=YSHTOLA
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "StmBda101:67982 calling [BranchTrue]Scene00001: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling [BranchTrue]Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.exitInstance();
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00005: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00007: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00009: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00010: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00011: Normal(Talk, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00014: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00016: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00017: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00018: Normal(Talk, YesNo, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 != 50 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq3( player );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 612, -660, 130, -533.333, 0.96, false );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00019: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00020: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00022: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00024: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00025: Normal(Talk, YesNo, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00026: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00029: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00030: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda101:67982 calling Scene00031: Normal(Talk, YesNo, TargetCanMove), id=SERPENTOFFICER" );
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
    player.sendDebug( "StmBda101:67982 calling Scene00032: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda101 );
