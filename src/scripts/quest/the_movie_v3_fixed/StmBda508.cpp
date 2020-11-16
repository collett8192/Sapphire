// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda508 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda508() : Sapphire::ScriptAPI::EventScript( 68062 ){}; 
  ~StmBda508() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 3 entries
  //SEQ_2, 3 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1020267
  //ACTOR1 = 1020268
  //ACTOR10 = 1020439
  //ACTOR11 = 1020274
  //ACTOR2 = 1020269
  //ACTOR3 = 1020265
  //ACTOR4 = 1020266
  //ACTOR5 = 1020270
  //ACTOR6 = 1020465
  //ACTOR7 = 1020622
  //ACTOR8 = 1020441
  //ACTOR9 = 1020440
  //BGMSWITCHREWARD = 371
  //BINDALISAIE001 = 6851417
  //BINDLYSE001 = 6851419
  //BINDRASHOU001 = 6851413
  //BINDTANSUI001 = 6851415
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1019541
  //LOCACTOR2 = 1018509
  //LOCACTOR3 = 1022484
  //LOCACTOR4 = 1019084
  //LOCSE01 = 39
  //LOCSE02 = 40
  //NCUTEVENT05110 = 1459
  //NCUTEVENT05120 = 1460
  //POPRANGE0 = 6851604
  //POPRANGE1 = 6851592
  //TERRITORYTYPE0 = 639

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020267 || param2 == 1020267 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020268 || param2 == 1020268 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020269 || param2 == 1020269 ) // ACTOR2 = LYSE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020265 || param2 == 1020265 ) // ACTOR3 = RASHO
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=RASHO
          break;
        }
        if( param1 == 1020266 || param2 == 1020266 ) // ACTOR4 = TANSUI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00006( player ); // Scene00006: Normal(Talk, FadeIn), id=unknown
          break;
        }
        if( param1 == 1020265 || param2 == 1020265 ) // ACTOR3 = RASHO
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=RASHO
          break;
        }
        if( param1 == 1020266 || param2 == 1020266 ) // ACTOR4 = TANSUI
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020270 || param2 == 1020270 ) // ACTOR5 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=TATARU
            // +Callback Scene00010: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1020465 || param2 == 1020465 ) // ACTOR6 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR7 = HANCOCK
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020441 || param2 == 1020441 ) // ACTOR8 = LYSE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020440 || param2 == 1020440 ) // ACTOR9 = ALISAIE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020439 || param2 == 1020439 ) // ACTOR10 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020274 || param2 == 1020274 ) // ACTOR11 = YUGIRI
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR7 = HANCOCK
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HANCOCK
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda508:68062 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00004: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00005: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00006: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00007: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00008: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00009: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00010: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 129, -357.177, 8, 42.83, 1.57, true );
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00012: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
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
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda508:68062 calling Scene00017: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda508 );
