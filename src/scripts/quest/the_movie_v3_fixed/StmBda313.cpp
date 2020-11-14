// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda313 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda313() : Sapphire::ScriptAPI::EventScript( 68025 ){}; 
  ~StmBda313() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_4, 4 entries
  //SEQ_255, 5 entries

  //ACTIONTIMELINEEVENTHIPPOSE = 4295
  //ACTIONTIMELINEEVENTSPIRIT = 1071
  //ACTIONTIMELINEEVENTWEDDINGHUG = 3754
  //ACTOR0 = 1019985
  //ACTOR1 = 1019986
  //ACTOR2 = 5010000
  //ACTOR3 = 1019987
  //ACTOR4 = 1019990
  //ACTOR5 = 1019991
  //ACTOR6 = 1019992
  //ACTOR7 = 1019988
  //ACTOR8 = 1019989
  //BINDACTOR0 = 6836817
  //CUTSCENEN01 = 1418
  //CUTSCENEN02 = 1419
  //CUTSCENEN03 = 1420
  //EOBJECT0 = 2007853
  //EVENTACTION0 = 53
  //INSTANCEDUNGEON0 = 20004
  //INSTANCEDUNGEON1 = 20046
  //LOCACTOR0 = 1019541
  //POPRANGE0 = 6836869
  //POPRANGE1 = 7018352
  //SCREENIMAGE0 = 500
  //TERRITORYTYPE0 = 613

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1019985 || param2 == 1019985 ) // ACTOR0 = ALISAIE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019986 || param2 == 1019986 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 1:
      {
        Scene00003( player ); // Scene00003: Normal(None), id=unknown
        break;
      }
      case 2:
      {
        Scene00004( player ); // Scene00004: Normal(None), id=unknown
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00005( player ); // Scene00005: Normal(CutScene, Skip), id=unknown
        }
        break;
      }
      case 4:
      {
        if( param1 == 1019987 || param2 == 1019987 ) // ACTOR3 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove, Menu, Skip), id=LYSE
          }
        }
        if( param1 == 1019990 || param2 == 1019990 ) // ACTOR4 = VILLAGERA02489
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=VILLAGERA02489
        }
        if( param1 == 1019991 || param2 == 1019991 ) // ACTOR5 = VILLAGERB02489
        {
          Scene00008( player ); // Scene00008: Normal(Talk), id=VILLAGERB02489
        }
        if( param1 == 1019992 || param2 == 1019992 ) // ACTOR6 = PIRATE02481
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=PIRATE02481
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019988 || param2 == 1019988 ) // ACTOR7 = LYSE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
        }
        if( param1 == 1019989 || param2 == 1019989 ) // ACTOR8 = ALISAIE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019990 || param2 == 1019990 ) // ACTOR4 = VILLAGERA02489
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=VILLAGERA02489
        }
        if( param1 == 1019991 || param2 == 1019991 ) // ACTOR5 = VILLAGERB02489
        {
          Scene00013( player ); // Scene00013: Normal(Talk), id=VILLAGERB02489
        }
        if( param1 == 1019992 || param2 == 1019992 ) // ACTOR6 = PIRATE02481
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=PIRATE02481
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda313:68025 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00003: Normal(None), id=unknown" );
    //checkProgressSeq1( player );
    Scene00005( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00005: Normal(CutScene, Skip), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      //player.sendUrgent( "Calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 613, -725.7, 0.206, -314.75, -2.386, false );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove, Menu, Skip), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq4( player );
        player.sendUrgent( "Calling forceZoneing..." );
        player.eventFinish( getId(), 1 );
        player.forceZoneing();
      }
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00007: Normal(Talk, TargetCanMove), id=VILLAGERA02489" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00008: Normal(Talk), id=VILLAGERB02489" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00009: Normal(Talk, TargetCanMove), id=PIRATE02481" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00012: Normal(Talk, TargetCanMove), id=VILLAGERA02489" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00013: Normal(Talk), id=VILLAGERB02489" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda313:68025 calling Scene00014: Normal(Talk, TargetCanMove), id=PIRATE02481" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda313 );
