// FFXIVTheMovie.ParserV3.6
// param used:
//ENEMY0 = dummy0
//ENEMY1 = dummy1
//SCENE_13 = dummy0
//SCENE_14 = dummy1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna303 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna303() : Sapphire::ScriptAPI::EventScript( 67140 ){}; 
  ~HeaVna303() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 1 entries
  //SEQ_4, 3 entries
  //SEQ_5, 9 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1012588
  //ACTOR1 = 1012589
  //ACTOR10 = 1012596
  //ACTOR11 = 1012597
  //ACTOR12 = 1012598
  //ACTOR13 = 1012594
  //ACTOR2 = 1013197
  //ACTOR3 = 1013422
  //ACTOR4 = 1013423
  //ACTOR5 = 1011231
  //ACTOR6 = 1012592
  //ACTOR7 = 1012593
  //ACTOR8 = 1012591
  //ACTOR9 = 1012595
  //ENEMY0 = 5887477
  //ENEMY1 = 5887478
  //EOBJECT0 = 2005431
  //EVENTRANGE0 = 5853266
  //LOCACTOR0 = 1008181
  //LOCACTOR1 = 1011887
  //LOCACTOR2 = 1012443
  //LOCACTOR3 = 5852736
  //LOCACTOR4 = 5879027
  //LOCACTOR5 = 5853383
  //LOCACTOR6 = 1008182
  //LOCMUSIC0 = 86
  //LOCSE0 = 78
  //TERRITORYTYPE0 = 433

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012588 || param2 == 1012588 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1012589 || param2 == 1012589 ) // ACTOR1 = ESTINIEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013197 || param2 == 1013197 ) // ACTOR2 = TATARU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00004( player ); // Scene00004: Normal(Talk, FadeIn), id=unknown
          break;
        }
        if( param1 == 1013422 || param2 == 1013422 ) // ACTOR3 = ESTINIEN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1013422 || param2 == 1013422 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=unknown
          }
          break;
        }
        if( param1 == 1013423 || param2 == 1013423 ) // ACTOR4 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 3:
      {
        if( type != 2 ) Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=REDWALD
        break;
      }
      case 4:
      {
        if( param1 == 1012592 || param2 == 1012592 ) // ACTOR6 = KIGHTLEADER01604
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove, ENpcBind), id=KIGHTLEADER01604
          }
          break;
        }
        if( param1 == 1012593 || param2 == 1012593 ) // ACTOR7 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012591 || param2 == 1012591 ) // ACTOR8 = ESTINIEN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 5853266 || param2 == 5853266 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00012( player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5887477 || param2 == 5887477 ) // ENEMY0 = dummy0
        {
          Scene00013( player ); // Scene00013: Normal(None), id=dummy0
          break;
        }
        if( param1 == 5887478 || param2 == 5887478 ) // ENEMY1 = dummy1
        {
          Scene00014( player ); // Scene00014: Normal(None), id=dummy1
          break;
        }
        if( param1 == 1012595 || param2 == 1012595 ) // ACTOR9 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012596 || param2 == 1012596 ) // ACTOR10 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005431 || param2 == 2005431 ) // EOBJECT0 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012597 || param2 == 1012597 ) // ACTOR11 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012598 || param2 == 1012598 ) // ACTOR12 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012592 || param2 == 1012592 ) // ACTOR6 = KIGHTLEADER01604
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=KIGHTLEADER01604
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012592 || param2 == 1012592 ) // ACTOR6 = KIGHTLEADER01604
        {
          Scene00021( player ); // Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KIGHTLEADER01604
          break;
        }
        if( param1 == 1012594 || param2 == 1012594 ) // ACTOR13 = ESTINIEN
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012595 || param2 == 1012595 ) // ACTOR9 = ALPHINAUD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012596 || param2 == 1012596 ) // ACTOR10 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 3 );
    }
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
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
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
    player.sendDebug( "HeaVna303:67140 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna303:67140 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00004: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_4: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00009: Normal(Talk, TargetCanMove, ENpcBind), id=KIGHTLEADER01604" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00011: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_5: EVENTRANGE0, UI8AL = 2, Flag8(1)=True
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_5: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00013: Normal(None), id=dummy0" );
    checkProgressSeq5( player );
  }

  void Scene00014( Entity::Player& player ) //SEQ_5: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00014: Normal(None), id=dummy1" );
    checkProgressSeq5( player );
  }

  void Scene00015( Entity::Player& player ) //SEQ_5: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_5: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player ) //SEQ_5: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00018( Entity::Player& player ) //SEQ_5: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player ) //SEQ_5: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player ) //SEQ_5: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00020: Normal(Talk, TargetCanMove), id=KIGHTLEADER01604" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KIGHTLEADER01604" );
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
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00022: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna303:67140 calling Scene00024: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( HeaVna303 );
