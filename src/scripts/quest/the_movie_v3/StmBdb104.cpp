// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_4 = LYSE
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdb104 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdb104() : Sapphire::ScriptAPI::EventScript( 68501 ){}; 
  ~StmBdb104() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 6 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1024103
  //ACTOR1 = 1024104
  //ACTOR10 = 1020516
  //ACTOR2 = 1024105
  //ACTOR3 = 1024106
  //ACTOR4 = 1024107
  //ACTOR5 = 1024108
  //ACTOR6 = 1024109
  //ACTOR7 = 1024110
  //ACTOR8 = 1024111
  //ACTOR9 = 1024112
  //BINDACTOR0 = 7074634
  //BINDACTOR1 = 7074636
  //BINDACTOR2 = 7074641
  //BINDACTOR3 = 7074651
  //BINDACTOR4 = 7074644
  //BINDACTOR5 = 7074643
  //CUTSCENE00 = 1620
  //CUTSCENE01 = 1621
  //CUTSCENE02 = 1622
  //CUTSCENE03 = 1623
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1019537
  //LOCACTOR2 = 1024619
  //LOCBGM001 = 459
  //POPRANGE0 = 7074648
  //POPRANGE1 = 7074650

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1024103 || param2 == 1024103 ) // ACTOR0 = ARENVALD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024104 || param2 == 1024104 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1024105 || param2 == 1024105 ) // ACTOR2 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=LYSE
            // +Callback Scene00004: Normal(CutScene, AutoFadeIn), id=LYSE
          }
          break;
        }
        if( param1 == 1024106 || param2 == 1024106 ) // ACTOR3 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1024107 || param2 == 1024107 ) // ACTOR4 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1024108 || param2 == 1024108 ) // ACTOR5 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024109 || param2 == 1024109 ) // ACTOR6 = ARENVALD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024110 || param2 == 1024110 ) // ACTOR7 = RAUBAHN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1024111 || param2 == 1024111 ) // ACTOR8 = MNAAGO
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1024112 || param2 == 1024112 ) // ACTOR9 = CAMPGUARD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=CAMPGUARD
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1024112 || param2 == 1024112 ) // ACTOR9 = CAMPGUARD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CAMPGUARD
          // +Callback Scene00013: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1020516 || param2 == 1020516 ) // ACTOR10 = LYSE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1024108 || param2 == 1024108 ) // ACTOR5 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024109 || param2 == 1024109 ) // ACTOR6 = ARENVALD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024111 || param2 == 1024111 ) // ACTOR8 = MNAAGO
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MNAAGO
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
    player.sendDebug( "StmBdb104:68501 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdb104:68501 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00004: Normal(CutScene, AutoFadeIn), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00008: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00009: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00010: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00011: Normal(Talk, TargetCanMove), id=CAMPGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00012: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CAMPGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00013: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown" );
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
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00014: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00016: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdb104:68501 calling Scene00017: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdb104 );
