// FFXIVTheMovie.ParserV3.6
// param used:
//ACTOR5 = ICEHEART
//ACTOR6 = null
//ACTOR7 = null
//ACTOR8 = null
//ACTOR9 = null
//ACTOR10 = null
//ACTOR11 = null
//ID_EOBJECT2 = 4300909001
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna314 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna314() : Sapphire::ScriptAPI::EventScript( 67151 ){}; 
  ~HeaVna314() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 9 entries
  //SEQ_2, 1 entries
  //SEQ_3, 15 entries
  //SEQ_255, 8 entries

  //ACTOR0 = 1013582
  //ACTOR1 = 1013583
  //ACTOR10 = 1012642
  //ACTOR11 = 1012643
  //ACTOR2 = 1012672
  //ACTOR3 = 1012639
  //ACTOR4 = 1013192
  //ACTOR5 = 1014847
  //ACTOR6 = 1014848
  //ACTOR7 = 1014849
  //ACTOR8 = 1012640
  //ACTOR9 = 1012641
  //ENEMY0 = 5864397
  //ENEMY1 = 5864398
  //ENEMY2 = 5864402
  //ENEMY3 = 5864403
  //ENEMY4 = 5864404
  //ENEMY5 = 5864405
  //ENEMY6 = 5864406
  //ENEMY7 = 5864407
  //ENEMY8 = 5864408
  //ENEMY9 = 5864409
  //EOBJECT0 = 2005444
  //EOBJECT1 = 2005443
  //EOBJECT2 = 2006423
  //EVENTRANGE0 = 5864410
  //EVENTACTIONWAITINGSHOR = 11
  //LOCACTOR0 = 5887780
  //LOCACTOR1 = 5887793
  //LOCACTOR10 = 1012456

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1013582 || param2 == 1013582 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1013583 || param2 == 1013583 ) // ACTOR1 = ESTINIEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012672 || param2 == 1012672 ) // ACTOR2 = ICEHEART
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012639 || param2 == 1012639 ) // ACTOR3 = GNATHGUARD01615
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, Message, PopBNpc, TargetCanMove), id=GNATHGUARD01615
          }
          break;
        }
        if( param1 == 5864397 || param2 == 5864397 ) // ENEMY0 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5864398 || param2 == 5864398 ) // ENEMY1 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5864402 || param2 == 5864402 ) // ENEMY2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5864403 || param2 == 5864403 ) // ENEMY3 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1013582 || param2 == 1013582 ) // ACTOR0 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013583 || param2 == 1013583 ) // ACTOR1 = ESTINIEN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013192 || param2 == 1013192 ) // ACTOR4 = ICEHEART
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        if( param1 == 2005444 || param2 == 2005444 ) // EOBJECT0 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( type != 2 ) Scene00013( player ); // Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=ICEHEART
        break;
      }
      case 3:
      {
        if( param1 == 5864410 || param2 == 5864410 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00014( player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5864404 || param2 == 5864404 ) // ENEMY4 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864405 || param2 == 5864405 ) // ENEMY5 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864406 || param2 == 5864406 ) // ENEMY6 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864407 || param2 == 5864407 ) // ENEMY7 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864408 || param2 == 5864408 ) // ENEMY8 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 5864409 || param2 == 5864409 ) // ENEMY9 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005443 || param2 == 2005443 ) // EOBJECT1 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1014847 || param2 == 1014847 ) // ACTOR5 = ICEHEART
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        if( param1 == 1014848 || param2 == 1014848 ) // ACTOR6 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1014849 || param2 == 1014849 ) // ACTOR7 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012640 || param2 == 1012640 ) // ACTOR8 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012641 || param2 == 1012641 ) // ACTOR9 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012642 || param2 == 1012642 ) // ACTOR10 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012643 || param2 == 1012643 ) // ACTOR11 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 4300909001 || param2 == 2006423 ) // EOBJECT2 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(Talk, FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1014847 || param2 == 1014847 ) // ACTOR5 = ICEHEART
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        if( param1 == 1014848 || param2 == 1014848 ) // ACTOR6 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1014849 || param2 == 1014849 ) // ACTOR7 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012640 || param2 == 1012640 ) // ACTOR8 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012641 || param2 == 1012641 ) // ACTOR9 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012642 || param2 == 1012642 ) // ACTOR10 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012643 || param2 == 1012643 ) // ACTOR11 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 4 )
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
    if( player.getQuestUI8AL( getId() ) == 6 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna314:67151 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00003: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 4, Flag8(1)=True
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00004: Normal(Talk, Message, PopBNpc, TargetCanMove), id=GNATHGUARD01615" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 4 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ENEMY3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00010: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00011: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_3: EVENTRANGE0, UI8AL = 6, Flag8(1)=True
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 6 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: ENEMY4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: ENEMY5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: ENEMY6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00018( Entity::Player& player ) //SEQ_3: ENEMY7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_3: ENEMY8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00020( Entity::Player& player ) //SEQ_3: ENEMY9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00021( Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00022( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00022: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player ) //SEQ_255: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00030: Normal(Talk, FadeIn, QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00031: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna314:67151 calling Scene00037: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( HeaVna314 );
