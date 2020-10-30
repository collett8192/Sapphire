// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda132 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda132() : Sapphire::ScriptAPI::EventScript( 67998 ){}; 
  ~StmBda132() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 6 entries
  //SEQ_255, 8 entries

  //ACTOR0 = 1020332
  //ACTOR1 = 1020342
  //ACTOR10 = 1020526
  //ACTOR11 = 1020525
  //ACTOR2 = 1020324
  //ACTOR3 = 1020325
  //ACTOR4 = 1020395
  //ACTOR5 = 1020343
  //ACTOR6 = 1020304
  //ACTOR7 = 1020392
  //ACTOR8 = 1020393
  //ACTOR9 = 1020354
  //BINDACTOR01 = 6829424
  //BINDACTOR02 = 6841690
  //BINDACTOR03 = 6844562
  //BINDACTOR06 = 6829441
  //BINDACTOR07 = 6829442
  //BINDACTOR08 = 6708349
  //BINDACTOR09 = 6829463
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1017687
  //LOCACTOR03 = 1015903
  //LOCACTOR04 = 1018318
  //LOCACTOR05 = 1019082
  //LOCACTOR06 = 1019716
  //LOCACTOR07 = 1019717
  //LOCACTOR08 = 1018509
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
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=YSHTOLA
        break;
      }
      case 2:
      {
        if( param1 == 1020324 || param2 == 1020324 ) // ACTOR2 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1020325 || param2 == 1020325 ) // ACTOR3 = ALISAIE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020395 || param2 == 1020395 ) // ACTOR4 = MNAAGO
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MNAAGO
        }
        if( param1 == 1020342 || param2 == 1020342 ) // ACTOR1 = YSHTOLA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1020343 || param2 == 1020343 ) // ACTOR5 = KRILE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KRILE
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020304 || param2 == 1020304 ) // ACTOR6 = RAUBAHN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=RAUBAHN
          }
        }
        if( param1 == 1020392 || param2 == 1020392 ) // ACTOR7 = SERPENTOFFICER
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
        }
        if( param1 == 1020393 || param2 == 1020393 ) // ACTOR8 = STORMOFFICER
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=STORMOFFICER
        }
        if( param1 == 1020354 || param2 == 1020354 ) // ACTOR9 = PIPIN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=PIPIN
        }
        if( param1 == 1020342 || param2 == 1020342 ) // ACTOR1 = YSHTOLA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1020343 || param2 == 1020343 ) // ACTOR5 = KRILE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=KRILE
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020526 || param2 == 1020526 ) // ACTOR10 = ALISAIE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020525 || param2 == 1020525 ) // ACTOR11 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020304 || param2 == 1020304 ) // ACTOR6 = RAUBAHN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=RAUBAHN
        }
        if( param1 == 1020392 || param2 == 1020392 ) // ACTOR7 = SERPENTOFFICER
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
        }
        if( param1 == 1020393 || param2 == 1020393 ) // ACTOR8 = STORMOFFICER
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=STORMOFFICER
        }
        if( param1 == 1020354 || param2 == 1020354 ) // ACTOR9 = PIPIN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=PIPIN
        }
        if( param1 == 1020342 || param2 == 1020342 ) // ACTOR1 = YSHTOLA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1020343 || param2 == 1020343 ) // ACTOR5 = KRILE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=KRILE
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda132:67998 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00005: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00007: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00009: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00010: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00011: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00013: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00016: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00017: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00018: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00019: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00020: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda132:67998 calling Scene00021: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda132 );
