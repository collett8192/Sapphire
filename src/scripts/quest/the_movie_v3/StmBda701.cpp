// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda701 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda701() : Sapphire::ScriptAPI::EventScript( 68084 ){}; 
  ~StmBda701() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 2 entries
  //SEQ_3, 1 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1020665
  //ACTOR1 = 1020419
  //ACTOR2 = 1020412
  //ACTOR3 = 1020649
  //ACTOR4 = 1021704
  //ACTOR5 = 1021705
  //ACTOR6 = 1021706
  //ACTOR7 = 1022724
  //ACTOR8 = 1022725
  //ACTOR9 = 1022726
  //BINDACTOR01 = 7021655
  //CUTSCENEN01 = 1479
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019559
  //LOCBGM01 = 458
  //LOCSE01 = 152
  //POPRANGE0 = 6875111
  //TERRITORYTYPE0 = 621

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020665 || param2 == 1020665 ) // ACTOR0 = LYSE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020419 || param2 == 1020419 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020412 || param2 == 1020412 ) // ACTOR2 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020419 || param2 == 1020419 ) // ACTOR1 = ALISAIE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020665 || param2 == 1020665 ) // ACTOR0 = LYSE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020649 || param2 == 1020649 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=unknown
          }
          break;
        }
        if( param1 == 1020419 || param2 == 1020419 ) // ACTOR1 = ALISAIE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00008( player ); // Scene00008: Normal(CutScene, Dismount, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021704 || param2 == 1021704 ) // ACTOR4 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021705 || param2 == 1021705 ) // ACTOR5 = LYSE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021706 || param2 == 1021706 ) // ACTOR6 = ARENVALD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022724 || param2 == 1022724 ) // ACTOR7 = MNAAGO
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022725 || param2 == 1022725 ) // ACTOR8 = VMAHTIA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022726 || param2 == 1022726 ) // ACTOR9 = JMOLDVA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1020419 || param2 == 1020419 ) // ACTOR1 = ALISAIE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda701:68084 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00005: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00008: Normal(CutScene, Dismount, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00010: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00011: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00012: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00013: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00014: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda701:68084 calling Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda701 );
