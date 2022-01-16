// FFXIVTheMovie.ParserV3.6
// param used:
//WARP_WINDOW01590 = 401|-726.8|-105|470|1|true
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna111 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna111() : Sapphire::ScriptAPI::EventScript( 67126 ){}; 
  ~HeaVna111() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 2 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINEEVENTSIGH = 4229
  //ACTIONTIMELINEEVENTTALKFINGER = 4194
  //ACTIONTIMELINETALKJOKE = 4220
  //ACTOR0 = 1012329
  //ACTOR1 = 1012327
  //ACTOR2 = 1012353
  //ACTOR3 = 1012349
  //ACTOR4 = 1012350
  //ACTOR5 = 1012351
  //ACTOR6 = 1012352
  //ACTOR7 = 1011952
  //CUTSCENEN01 = 793
  //LOCACTOR0 = 5853131
  //LOCACTOR1 = 1013876
  //LOCACTOR2 = 1012438
  //POPRANGE0 = 5858677
  //QSTACTOR1 = 5857448
  //QSTACTOR10 = 5857447
  //TERRITORYTYPE0 = 401

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012329 || param2 == 1012329 ) // ACTOR0 = EMMANELLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=EMMANELLAIN
          }
          break;
        }
        if( param1 == 1012327 || param2 == 1012327 ) // ACTOR1 = HONOROIT
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012353 || param2 == 1012353 ) // ACTOR2 = WINDOW01590
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=WINDOW01590
          }
          break;
        }
        if( param1 == 1012349 || param2 == 1012349 ) // ACTOR3 = EMMANELLAIN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1012350 || param2 == 1012350 ) // ACTOR4 = HONOROIT
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00006( player ); // Scene00006: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1012353 || param2 == 1012353 ) // ACTOR2 = WINDOW01590
        {
          Scene00007( player ); // Scene00007: Normal(Talk, YesNo, TargetCanMove), id=WINDOW01590
          break;
        }
        if( param1 == 1012349 || param2 == 1012349 ) // ACTOR3 = EMMANELLAIN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1012350 || param2 == 1012350 ) // ACTOR4 = HONOROIT
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1012351 || param2 == 1012351 ) // ACTOR5 = EMMANELLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=EMMANELLAIN
          }
          break;
        }
        if( param1 == 1012352 || param2 == 1012352 ) // ACTOR6 = HONOROIT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove, ENpcBind), id=HONOROIT
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00012( player ); // Scene00012: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LANIAITTE
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
    player.sendDebug( "emote: {}", emoteId );
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
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna111:67126 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna111:67126 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna111:67126 calling Scene00002: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna111:67126 calling Scene00003: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=WINDOW01590" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.setQuestUI8AL( getId(), 1 );
        player.setQuestBitFlag8( getId(), 1, true );
        checkProgressSeq1( player );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 401, -726.8f, -105.0f, 470.0f, 1.0f, true );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna111:67126 calling Scene00004: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna111:67126 calling Scene00005: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna111:67126 calling Scene00006: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna111:67126 calling Scene00007: Normal(Talk, YesNo, TargetCanMove), id=WINDOW01590" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 401, -726.8f, -105.0f, 470.0f, 1.0f, true );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna111:67126 calling Scene00008: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna111:67126 calling Scene00009: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna111:67126 calling Scene00010: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna111:67126 calling Scene00011: Normal(Talk, TargetCanMove, ENpcBind), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna111:67126 calling Scene00012: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LANIAITTE" );
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
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( HeaVna111 );
