// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda604 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda604() : Sapphire::ScriptAPI::EventScript( 68066 ){}; 
  ~StmBda604() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 2 entries
  //SEQ_2, 14 entries
  //SEQ_255, 15 entries

  //ACTOR0 = 1020568
  //ACTOR1 = 1020573
  //ACTOR10 = 1022322
  //ACTOR11 = 1022323
  //ACTOR12 = 1022324
  //ACTOR13 = 1022325
  //ACTOR14 = 1022326
  //ACTOR15 = 1020620
  //ACTOR16 = 1020621
  //ACTOR17 = 1020578
  //ACTOR18 = 1020579
  //ACTOR19 = 1022363
  //ACTOR2 = 1022089
  //ACTOR20 = 1022364
  //ACTOR3 = 1022090
  //ACTOR4 = 1020567
  //ACTOR5 = 1022327
  //ACTOR6 = 1022328
  //ACTOR7 = 1022329
  //ACTOR8 = 1022330
  //ACTOR9 = 1022331
  //BINDACTOR01 = 6912876
  //BINDACTOR02 = 6912877
  //CUTSCENEN01 = 1464
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019541
  //LOCACTOR03 = 1018509
  //LOCACTOR04 = 1021982
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //POPRANGE0 = 7021955
  //POPRANGE1 = 6865939
  //POPRANGE2 = 6853889
  //TERRITORYTYPE0 = 612

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020568 || param2 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, AutoFadeIn), id=CONRAD
          break;
        }
        if( param1 == 1020573 || param2 == 1020573 ) // ACTOR1 = RESISTANCEGATEGUARD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD
          break;
        }
        if( param1 == 1022089 || param2 == 1022089 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1022090 || param2 == 1022090 ) // ACTOR3 = ALISAIE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020567 || param2 == 1020567 ) // ACTOR4 = LYSE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020573 || param2 == 1020573 ) // ACTOR1 = RESISTANCEGATEGUARD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD
          }
          break;
        }
        if( param1 == 1020568 || param2 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1022327 || param2 == 1022327 ) // ACTOR5 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020573 || param2 == 1020573 ) // ACTOR1 = RESISTANCEGATEGUARD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD
          break;
        }
        if( param1 == 1022328 || param2 == 1022328 ) // ACTOR6 = PIPIN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1022329 || param2 == 1022329 ) // ACTOR7 = ARENVALD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022330 || param2 == 1022330 ) // ACTOR8 = VMAHTIA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022331 || param2 == 1022331 ) // ACTOR9 = JMOLDVA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1022322 || param2 == 1022322 ) // ACTOR10 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1022323 || param2 == 1022323 ) // ACTOR11 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1022324 || param2 == 1022324 ) // ACTOR12 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1022325 || param2 == 1022325 ) // ACTOR13 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1022326 || param2 == 1022326 ) // ACTOR14 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020568 || param2 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020620 || param2 == 1020620 ) // ACTOR15 = ALPHINAUD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020621 || param2 == 1020621 ) // ACTOR16 = ALISAIE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020578 || param2 == 1020578 ) // ACTOR17 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(CutScene, AutoFadeIn), id=unknown
          // +Callback Scene00023: Normal(FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1020573 || param2 == 1020573 ) // ACTOR1 = RESISTANCEGATEGUARD
        {
          Scene00024( player ); // Scene00024: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD
          break;
        }
        if( param1 == 1022322 || param2 == 1022322 ) // ACTOR10 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1022323 || param2 == 1022323 ) // ACTOR11 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1022324 || param2 == 1022324 ) // ACTOR12 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1022325 || param2 == 1022325 ) // ACTOR13 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1022326 || param2 == 1022326 ) // ACTOR14 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020568 || param2 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1022328 || param2 == 1022328 ) // ACTOR6 = PIPIN
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1022329 || param2 == 1022329 ) // ACTOR7 = ARENVALD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022330 || param2 == 1022330 ) // ACTOR8 = VMAHTIA
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022331 || param2 == 1022331 ) // ACTOR9 = JMOLDVA
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1020579 || param2 == 1020579 ) // ACTOR18 = LYSE
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1022363 || param2 == 1022363 ) // ACTOR19 = ALPHINAUD
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1022364 || param2 == 1022364 ) // ACTOR20 = ALISAIE
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=ALISAIE
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda604:68066 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, AutoFadeIn), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00002: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00005: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00007: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00008: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00009: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00010: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00011: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00012: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00013: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00019: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00022: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00023: Normal(FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
          player.eventFinish( getId(), 1 );
          player.forceZoneing();
        }
      }
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00024: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
      }
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00030: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00031: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00032: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00033: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00034: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00035: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda604:68066 calling Scene00037: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda604 );
