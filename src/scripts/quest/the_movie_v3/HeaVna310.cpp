// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna310 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna310() : Sapphire::ScriptAPI::EventScript( 67147 ){}; 
  ~HeaVna310() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1012619
  //ACTOR1 = 1012617
  //ACTOR2 = 1012618
  //ACTOR3 = 1012622
  //ACTOR4 = 1012620
  //ACTOR5 = 1012621
  //ACTOR6 = 1012625
  //ACTOR7 = 1012623
  //ACTOR8 = 1012624
  //CUTSCENEN01 = 813
  //ENEMY0 = 5864387
  //ENEMY1 = 5864388
  //ENEMY2 = 5864389
  //ENEMY3 = 5930379
  //ENEMY4 = 5864390
  //ENEMY5 = 5864391
  //ENEMY6 = 5864392
  //ENEMY7 = 5864393
  //EOBJECT0 = 2005440
  //EOBJECT1 = 2005441
  //EVENTRANGE0 = 5864385
  //EVENTRANGE1 = 5864386
  //LOCACTOR0 = 5856247
  //LOCACTOR1 = 5856248
  //LOCACTOR10 = 5856250
  //LOCACTOR11 = 5856251
  //LOCACTOR20 = 5856253
  //LOCACTOR21 = 5856254
  //POPRANGE0 = 5856307

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012619 || param2 == 1012619 ) // ACTOR0 = ICEHEART
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ICEHEART
          }
          break;
        }
        if( param1 == 1012617 || param2 == 1012617 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012618 || param2 == 1012618 ) // ACTOR2 = ESTINIEN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012622 || param2 == 1012622 ) // ACTOR3 = ICEHEART
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove, ENpcBind), id=ICEHEART
          }
          break;
        }
        if( param1 == 1012620 || param2 == 1012620 ) // ACTOR4 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012621 || param2 == 1012621 ) // ACTOR5 = ESTINIEN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 5864385 || param2 == 5864385 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5864387 || param2 == 5864387 ) // ENEMY0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864388 || param2 == 5864388 ) // ENEMY1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864389 || param2 == 5864389 ) // ENEMY2 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 5930379 || param2 == 5930379 ) // ENEMY3 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005440 || param2 == 2005440 ) // EOBJECT0 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 5864386 || param2 == 5864386 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00013( player ); // Scene00013: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5864390 || param2 == 5864390 ) // ENEMY4 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864391 || param2 == 5864391 ) // ENEMY5 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864392 || param2 == 5864392 ) // ENEMY6 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864393 || param2 == 5864393 ) // ENEMY7 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005441 || param2 == 2005441 ) // EOBJECT1 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012625 || param2 == 1012625 ) // ACTOR6 = ICEHEART
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove, AutoFadeIn, ENpcBind), id=ICEHEART
          // +Callback Scene00020: Normal(CutScene, AutoFadeIn), id=unknown
          // +Callback Scene00021: Normal(FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1012623 || param2 == 1012623 ) // ACTOR7 = ALPHINAUD
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012624 || param2 == 1012624 ) // ACTOR8 = ESTINIEN
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ESTINIEN
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
    if( player.getQuestUI8AL( getId() ) == 4 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 4 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna310:67147 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00004: Normal(Talk, TargetCanMove, ENpcBind), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00006: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: EVENTRANGE0, UI8AL = 4, Flag8(1)=True
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 4 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ENEMY3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: EVENTRANGE1, UI8AL = 4, Flag8(1)=True
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 4 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_3: ENEMY4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: ENEMY5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: ENEMY6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: ENEMY7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00018( Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00019: Normal(Talk, TargetCanMove, AutoFadeIn, ENpcBind), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00020: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00021( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00021: Normal(FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown" );
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
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna310:67147 calling Scene00023: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna310 );
