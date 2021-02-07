// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBde104 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBde104() : Sapphire::ScriptAPI::EventScript( 68682 ){}; 
  ~StmBde104() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 3 entries
  //SEQ_2, 3 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1025597
  //ACTOR1 = 1025545
  //ACTOR10 = 1026281
  //ACTOR11 = 1026282
  //ACTOR12 = 1020539
  //ACTOR13 = 1026283
  //ACTOR14 = 1026284
  //ACTOR15 = 1019382
  //ACTOR2 = 1026273
  //ACTOR3 = 1026274
  //ACTOR4 = 1026277
  //ACTOR5 = 1026278
  //ACTOR6 = 1025354
  //ACTOR7 = 1026280
  //ACTOR8 = 1026279
  //ACTOR9 = 1020622
  //BGMEX2EVENTSTORMBLOOD02 = 458
  //BINDACTOR0 = 7343652
  //BINDACTOR1 = 7593139
  //BINDACTOR2 = 7593141
  //BINDACTOR3 = 7593145
  //BINDACTOR4 = 7593146
  //BINDACTOR5 = 7593404
  //BINDACTOR6 = 7593407
  //BINDACTOR7 = 6826253
  //CUTSCENE0 = 1811
  //INVISACTOR0 = 1026283
  //INVISACTOR1 = 1026284
  //INVISACTOR2 = 1025712
  //INVISACTOR3 = 1019390
  //LCUTACTIONTIMELINEFACIALMEDITATE = 6227
  //LCUTACTIONTIMELINEFACIALSALUTE = 624
  //LCUTACTIONTIMELINEFACIALSMILEWK = 6215
  //LCUTACTIONTIMELINEFACIALWRYSMILECL = 6229
  //LCUTACTOR0 = 1019544
  //LCUTACTOR1 = 1016758
  //LCUTPOS0 = 7593416
  //LCUTPOS1 = 7593417
  //POPRANGE0 = 7226900
  //POPRANGE1 = 7593409
  //TERRITORYTYPE0 = 744

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1025597 || param2 == 1025597 ) // ACTOR0 = HIEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, Menu), id=HIEN
          break;
        }
        if( param1 == 1025545 || param2 == 1025545 ) // ACTOR1 = YUGIRI
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1026273 || param2 == 1026273 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1026274 || param2 == 1026274 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1026277 || param2 == 1026277 ) // ACTOR4 = HAKURO
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1026278 || param2 == 1026278 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025354 || param2 == 1025354 ) // ACTOR6 = KIENKANGATEKEEPER03028
        {
          Scene00007( player ); // Scene00007: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1026280 || param2 == 1026280 ) // ACTOR7 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove, AutoFadeIn), id=YSHTOLA
            // +Callback Scene00009: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1026279 || param2 == 1026279 ) // ACTOR8 = HIEN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR9 = HANCOCK
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1026281 || param2 == 1026281 ) // ACTOR10 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1026282 || param2 == 1026282 ) // ACTOR11 = YSHTOLA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR9 = HANCOCK
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR12 = CIRINA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1026283 || param2 == 1026283 ) // ACTOR13 = HIEN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1026284 || param2 == 1026284 ) // ACTOR14 = YSHTOLA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR9 = HANCOCK
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR15 = TEMULUN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=TEMULUN
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
    player.sendDebug( "StmBde104:68682 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBde104:68682 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, Menu), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00005: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00007: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00008: Normal(Talk, TargetCanMove, AutoFadeIn), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00009: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00010: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00011: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00012: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00014: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00015: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CIRINA" );
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
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00016: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00017: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00018: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBde104:68682 calling Scene00019: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBde104 );
