// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda131 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda131() : Sapphire::ScriptAPI::EventScript( 67997 ){}; 
  ~StmBda131() = default; 

  //SEQ_0, 1 entries
  //SEQ_255, 11 entries

  //ACTOR0 = 1019466
  //ACTOR1 = 1020390
  //ACTOR10 = 1020338
  //ACTOR2 = 1020348
  //ACTOR3 = 1020388
  //ACTOR4 = 1020333
  //ACTOR5 = 1020391
  //ACTOR6 = 1020332
  //ACTOR7 = 1020334
  //ACTOR8 = 1020342
  //ACTOR9 = 1020343
  //BINDACTOR01 = 6829443
  //BINDACTOR02 = 6829444
  //BINDACTOR03 = 6841686
  //BINDACTOR04 = 6841699
  //BINDACTOR05 = 6841700
  //BINDACTOR06 = 6829445
  //BINDACTOR07 = 6829463
  //CUTSCENEN01 = 1390
  //CUTSCENEN02 = 1610
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1017687
  //LOCACTOR03 = 1018509
  //LOCACTOR04 = 1018318
  //LOCACTOR05 = 1019543
  //LOCACTOR06 = 1019537
  //LOCACTOR07 = 1021958
  //LOCACTOR08 = 1021959
  //LOCBGM01 = 460
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=CONRAD
        // +Callback Scene00002: Normal(CutScene), id=unknown
        break;
      }
      case 255:
      {
        if( param1 == 1020390 || param2 == 1020390 ) // ACTOR1 = MNAAGO
        {
          Scene00003( player ); // Scene00003: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MNAAGO
        }
        if( param1 == 1019466 || param2 == 1019466 ) // ACTOR0 = CONRAD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=CONRAD
        }
        if( param1 == 1020348 || param2 == 1020348 ) // ACTOR2 = VMAHTIA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=VMAHTIA
        }
        if( param1 == 1020388 || param2 == 1020388 ) // ACTOR3 = JMOLDVA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=JMOLDVA
        }
        if( param1 == 1020333 || param2 == 1020333 ) // ACTOR4 = ALISAIE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020391 || param2 == 1020391 ) // ACTOR5 = ARENVALD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ARENVALD
        }
        if( param1 == 1020332 || param2 == 1020332 ) // ACTOR6 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020334 || param2 == 1020334 ) // ACTOR7 = LYSE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020342 || param2 == 1020342 ) // ACTOR8 = YSHTOLA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1020343 || param2 == 1020343 ) // ACTOR9 = KRILE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1020338 || param2 == 1020338 ) // ACTOR10 = MEFFRID
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=MEFFRID
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda131:67997 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda131:67997 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda131:67997 calling [BranchChain]Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda131:67997 calling Scene00003: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda131:67997 calling Scene00004: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda131:67997 calling Scene00005: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda131:67997 calling Scene00006: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda131:67997 calling Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda131:67997 calling Scene00008: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda131:67997 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda131:67997 calling Scene00010: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda131:67997 calling Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda131:67997 calling Scene00012: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda131:67997 calling Scene00013: Normal(Talk, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda131 );
