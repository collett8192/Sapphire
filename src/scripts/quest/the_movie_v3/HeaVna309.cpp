// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna309 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna309() : Sapphire::ScriptAPI::EventScript( 67146 ){}; 
  ~HeaVna309() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 4 entries
  //SEQ_2, 6 entries
  //SEQ_3, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1011916
  //ACTOR1 = 1012613
  //ACTOR2 = 1012614
  //ACTOR3 = 1012615
  //ENEMY0 = 5864380
  //ENEMY1 = 5864381
  //ENEMY2 = 5864382
  //ENEMY3 = 5864383
  //ENEMY4 = 5864384
  //EOBJECT0 = 2005436
  //EOBJECT1 = 2005437
  //EOBJECT2 = 2005489
  //EVENTRANGE0 = 5864375
  //EVENTRANGE1 = 5864376
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1012443
  //LOCACTOR2 = 1012456
  //LOCACTOR3 = 5856210
  //LOCACTOR4 = 5856211
  //LOCMUSIC0 = 96
  //LOCMUSIC1 = 313

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1011916 || param2 == 1011916 ) // ACTOR0 = MARCECHAMP
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MARCECHAMP
          }
          break;
        }
        if( param1 == 1012613 || param2 == 1012613 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012614 || param2 == 1012614 ) // ACTOR2 = ESTINIEN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012615 || param2 == 1012615 ) // ACTOR3 = ICEHEART
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012615 || param2 == 1012615 ) // ACTOR3 = ICEHEART
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ICEHEART
          }
          break;
        }
        if( param1 == 1012613 || param2 == 1012613 ) // ACTOR1 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012614 || param2 == 1012614 ) // ACTOR2 = ESTINIEN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1011916 || param2 == 1011916 ) // ACTOR0 = MARCECHAMP
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MARCECHAMP
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 5864375 || param2 == 5864375 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00009( player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5864380 || param2 == 5864380 ) // ENEMY0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864381 || param2 == 5864381 ) // ENEMY1 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864382 || param2 == 5864382 ) // ENEMY2 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1011916 || param2 == 1011916 ) // ACTOR0 = MARCECHAMP
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=MARCECHAMP
          break;
        }
        if( param1 == 2005436 || param2 == 2005436 ) // EOBJECT0 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 5864376 || param2 == 5864376 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00015( player ); // Scene00015: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5864383 || param2 == 5864383 ) // ENEMY3 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864384 || param2 == 5864384 ) // ENEMY4 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005437 || param2 == 2005437 ) // EOBJECT1 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00019( player ); // Scene00019: Normal(Talk, FadeIn, QuestReward, QuestComplete, Menu), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna309:67146 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MARCECHAMP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00004: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00007: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00008: Normal(Talk, TargetCanMove), id=MARCECHAMP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: EVENTRANGE0, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00013: Normal(Talk, TargetCanMove), id=MARCECHAMP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: EVENTRANGE1, UI8AL = 2, Flag8(1)=True
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00015: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: ENEMY3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: ENEMY4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00018( Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna309:67146 calling Scene00019: Normal(Talk, FadeIn, QuestReward, QuestComplete, Menu), id=unknown" );
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
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( HeaVna309 );
