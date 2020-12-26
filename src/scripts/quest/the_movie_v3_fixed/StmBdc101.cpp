// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_5 = dummyr0
//SCENE_6 = dummyr0
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdc101 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdc101() : Sapphire::ScriptAPI::EventScript( 68558 ){}; 
  ~StmBdc101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_255, 6 entries

  //ACTIONTIMELINEEVENTFSORRY = 613
  //ACTIONTIMELINEEVENTJOY = 953
  //ACTIONTIMELINEEVENTSAD = 954
  //ACTOR0 = 1019468
  //ACTOR1 = 1020463
  //ACTOR2 = 1020337
  //ACTOR3 = 1024726
  //ACTOR4 = 1020622
  //ACTOR5 = 1024727
  //ACTOR6 = 1024728
  //BINDACTOR01 = 7021290
  //BINDACTOR02 = 7021294
  //BINDACTOR03 = 7178501
  //BINDACTOR04 = 7178502
  //BINDACTOR05 = 6829441
  //CUTSCENEN01 = 1675
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019541
  //LOCACTOR03 = 1019096
  //LOCACTOR04 = 1019085
  //LOCACTOR05 = 1019548
  //LOCBGM01 = 484
  //LOCBGM02 = 459
  //LOCSE01 = 39
  //LOCSE02 = 40
  //POPRANGE0 = 7178334
  //POPRANGE1 = 7178499
  //TERRITORYTYPE0 = 639

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=LYSE
        break;
      }
      case 1:
      {
        if( param1 == 1020463 || param2 == 1020463 ) // ACTOR1 = EATCASSISTANT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=EATCASSISTANT
          }
          break;
        }
        if( param1 == 1019468 || param2 == 1019468 ) // ACTOR0 = LYSE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020337 || param2 == 1020337 ) // ACTOR2 = MNAAGO
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = dummyr0
        {
          Scene00005( player ); // Scene00005: Normal(CutScene, AutoFadeIn), id=dummyr0
          // +Callback Scene00006: Normal(Talk, FadeIn, AutoFadeIn), id=dummyr0
          break;
        }
        if( param1 == 1020463 || param2 == 1020463 ) // ACTOR1 = EATCASSISTANT
        {
          Scene00007( player ); // Scene00007: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=EATCASSISTANT
          break;
        }
        if( param1 == 1019468 || param2 == 1019468 ) // ACTOR0 = LYSE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020337 || param2 == 1020337 ) // ACTOR2 = MNAAGO
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1024726 || param2 == 1024726 ) // ACTOR3 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, SystemTalk), id=ALISAIE
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR4 = HANCOCK
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1024727 || param2 == 1024727 ) // ACTOR5 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024728 || param2 == 1024728 ) // ACTOR6 = YUGIRI
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1019468 || param2 == 1019468 ) // ACTOR0 = LYSE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020337 || param2 == 1020337 ) // ACTOR2 = MNAAGO
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=MNAAGO
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdc101:68558 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00002: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=EATCASSISTANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00004: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00005: Normal(CutScene, AutoFadeIn), id=dummyr0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00006: Normal(Talk, FadeIn, AutoFadeIn), id=dummyr0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00007: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=EATCASSISTANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 639 );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00008: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00009: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00010: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, SystemTalk), id=ALISAIE" );
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
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00011: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00013: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00014: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdc101:68558 calling Scene00015: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdc101 );
