// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda201 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda201() : Sapphire::ScriptAPI::EventScript( 68006 ){}; 
  ~StmBda201() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1020450
  //ACTOR1 = 1020451
  //ACTOR10 = 1020458
  //ACTOR11 = 1020459
  //ACTOR12 = 1020460
  //ACTOR13 = 1022347
  //ACTOR14 = 1022348
  //ACTOR15 = 1022349
  //ACTOR16 = 1022350
  //ACTOR2 = 1020452
  //ACTOR3 = 1020453
  //ACTOR4 = 1020454
  //ACTOR5 = 1021740
  //ACTOR6 = 1020463
  //ACTOR7 = 1020455
  //ACTOR8 = 1020456
  //ACTOR9 = 1020457
  //BINDACTOR0 = 6848151
  //BINDACTOR1 = 6848150
  //BINDACTOR10 = 6905628
  //BINDACTOR11 = 6905629
  //BINDACTOR12 = 6905630
  //BINDACTOR2 = 6880137
  //BINDACTOR3 = 6848152
  //BINDACTOR4 = 6880112
  //BINDACTOR5 = 6842855
  //BINDACTOR6 = 6842856
  //BINDACTOR7 = 6842857
  //BINDACTOR8 = 6842858
  //BINDACTOR9 = 6905627
  //CUTSCENEN01 = 1402
  //LOCCAMERASAKABA = 6934965
  //POPRANGE0 = 6842860

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020450 || param2 == 1020450 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          // +Callback Scene00002: Normal(CutScene, QuestAccept), id=unknown
        }
        if( param1 == 1020451 || param2 == 1020451 ) // ACTOR1 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020452 || param2 == 1020452 ) // ACTOR2 = LYSE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020453 || param2 == 1020453 ) // ACTOR3 = TATARU
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1020454 || param2 == 1020454 ) // ACTOR4 = CARVALLAIN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CARVALLAIN
        }
        if( param1 == 1021740 || param2 == 1021740 ) // ACTOR5 = KRAKENSDECKHAND
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND
        }
        if( param1 == 1020463 || param2 == 1020463 ) // ACTOR6 = EATCASSISTANT
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=EATCASSISTANT
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020455 || param2 == 1020455 ) // ACTOR7 = HANCOCK
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=HANCOCK
          }
        }
        if( param1 == 1020456 || param2 == 1020456 ) // ACTOR8 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020457 || param2 == 1020457 ) // ACTOR9 = TATARU
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1020458 || param2 == 1020458 ) // ACTOR10 = ALISAIE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020459 || param2 == 1020459 ) // ACTOR11 = LYSE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020463 || param2 == 1020463 ) // ACTOR6 = EATCASSISTANT
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=EATCASSISTANT
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020460 || param2 == 1020460 ) // ACTOR12 = HANCOCK
        {
          Scene00015( player ); // Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HANCOCK
        }
        if( param1 == 1022347 || param2 == 1022347 ) // ACTOR13 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1022348 || param2 == 1022348 ) // ACTOR14 = ALISAIE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1022349 || param2 == 1022349 ) // ACTOR15 = LYSE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1022350 || param2 == 1022350 ) // ACTOR16 = TATARU
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1020463 || param2 == 1020463 ) // ACTOR6 = EATCASSISTANT
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=EATCASSISTANT
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
    player.sendDebug( "StmBda201:68006 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda201:68006 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling [BranchChain]Scene00002: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 628, -65.5, -2.71, -59, 1.55, false );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00005: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00006: Normal(Talk, TargetCanMove), id=CARVALLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00007: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00008: Normal(Talk, TargetCanMove), id=EATCASSISTANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00011: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00014: Normal(Talk, TargetCanMove), id=EATCASSISTANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00018: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00019: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda201:68006 calling Scene00020: Normal(Talk, TargetCanMove), id=EATCASSISTANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda201 );
