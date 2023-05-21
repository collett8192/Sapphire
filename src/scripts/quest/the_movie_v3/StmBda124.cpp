// FFXIVTheMovie.ParserV3.11
// param used:
//ENEMY2 = enemy2
//ENEMY3 = enemy3
//ENEMY4 = enemy4
//SCENE_28 = enemy2
//SCENE_29 = enemy3
//SCENE_30 = enemy4
//ACTOR3 = dummy3
//_AGGRESSIVE_BNPC_HACK SET!!
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda124 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda124() : Sapphire::ScriptAPI::QuestScript( 67994 ){}; 
  ~StmBda124() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 5 entries
  //SEQ_2, 15 entries
  //SEQ_3, 15 entries
  //SEQ_4, 7 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1020379
  //ACTOR1 = 1020378
  //ACTOR10 = 1020515
  //ACTOR11 = 1023755
  //ACTOR12 = 1023756
  //ACTOR13 = 1020381
  //ACTOR14 = 1020380
  //ACTOR15 = 1023757
  //ACTOR16 = 1023758
  //ACTOR17 = 1023759
  //ACTOR18 = 1020382
  //ACTOR19 = 1020383
  //ACTOR2 = 1020360
  //ACTOR3 = 1020362
  //ACTOR4 = 1020508
  //ACTOR5 = 1020842
  //ACTOR6 = 1020509
  //ACTOR7 = 1020510
  //ACTOR8 = 1020513
  //ACTOR9 = 1020514
  //BINDACTOR01 = 6836936
  //ENEMY0 = 7021915
  //ENEMY1 = 7021917
  //ENEMY2 = 7022968
  //ENEMY3 = 7005944
  //ENEMY4 = 7022969
  //EOBJECT0 = 2008681
  //EOBJECT1 = 2008065
  //EOBJECT2 = 2008317
  //EVENTACTION0 = 50
  //EVENTRANGE0 = 6840940
  //EVENTRANGE1 = 6875129
  //LOCACTION01 = 1
  //LOCACTOR01 = 1018509
  //LOCACTOR02 = 1019543
  //LOCACTOR03 = 1021691
  //LOCACTOR04 = 1022500
  //LOCIDLE01 = 34

  static constexpr auto EVENT_ON_TALK = 0;
  static constexpr auto EVENT_ON_EMOTE = 1;
  static constexpr auto EVENT_ON_BNPC_KILL = 2;
  static constexpr auto EVENT_ON_WITHIN_RANGE = 3;
  static constexpr auto EVENT_ON_ENTER_TERRITORY = 4;
  static constexpr auto EVENT_ON_EVENT_ITEM = 5;
  static constexpr auto EVENT_ON_EOBJ_HIT = 6;
  static constexpr auto EVENT_ON_SAY = 7;

private:
  void onProgress( World::Quest& quest, Entity::Player& player, uint32_t type, uint64_t param1, uint32_t param2, uint32_t param3 )
  {
    switch( quest.getSeq() )
    {
      case 0:
      {
        if( param1 == 1020379 ) // ACTOR0 = MEFFRID
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=MEFFRID
          }
          break;
        }
        if( param1 == 1020378 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020360 ) // ACTOR2 = WISCAR
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1020362 ) // ACTOR3 = unknown
        {
          Scene00004( quest, player ); // Scene00004: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020508 ) // ACTOR4 = BEWILDEREDWOMEN
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=BEWILDEREDWOMEN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2008681 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00007( quest, player ); // Scene00007: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1020360 ) // ACTOR2 = WISCAR
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1020362 ) // ACTOR3 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020508 ) // ACTOR4 = BEWILDEREDWOMEN
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=BEWILDEREDWOMEN
          break;
        }
        if( param1 == 1020842 ) // ACTOR5 = SHARPEYEDWOMEN
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=SHARPEYEDWOMEN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 6840940 ) // EVENTRANGE0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00012( quest, player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EVENTRANGE0
        if( param1 == 7021915 ) // ENEMY0 = unknown
        {
        // empty entry
          break;
        }
        if( param1 == 7021917 ) // ENEMY1 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020360 ) // ACTOR2 = WISCAR
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1020362 ) // ACTOR3 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020509 ) // ACTOR6 = LYSE
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020510 ) // ACTOR7 = MEFFRID
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=MEFFRID
          break;
        }
        if( param1 == 1020513 ) // ACTOR8 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020514 ) // ACTOR9 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020515 ) // ACTOR10 = unknown
        {
          Scene00021( quest, player ); // Scene00021: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008065 ) // EOBJECT1 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020842 ) // ACTOR5 = SHARPEYEDWOMEN
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=SHARPEYEDWOMEN
          break;
        }
        if( param1 == 1020508 ) // ACTOR4 = BEWILDEREDWOMEN
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=BEWILDEREDWOMEN
          break;
        }
        if( param1 == 1023755 ) // ACTOR11 = unknown
        {
          Scene00027( quest, player ); // Scene00027: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1023756 ) // ACTOR12 = enemy3
        {
          Scene00029( quest, player ); // Scene00029: Empty(None), id=enemy3
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 6875129 ) // EVENTRANGE1 = enemy4
        {
          Scene00030( quest, player ); // Scene00030: Empty(None), id=enemy4
          break;
        }
        if( param1 == 7022968 ) // ENEMY2 = unknown
        {
        // empty entry
          break;
        }
        if( param1 == 7005944 ) // ENEMY3 = unknown
        {
        // empty entry
          break;
        }
        if( param1 == 7022969 ) // ENEMY4 = unknown
        {
        // empty entry
          break;
        }
        if( param1 == 1020509 ) // ACTOR6 = LYSE
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020510 ) // ACTOR7 = MEFFRID
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=MEFFRID
          break;
        }
        if( param1 == 1020513 ) // ACTOR8 = unknown
        {
          Scene00033( quest, player ); // Scene00033: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020514 ) // ACTOR9 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020515 ) // ACTOR10 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020381 ) // ACTOR13 = unknown
        {
          Scene00036( quest, player ); // Scene00036: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020380 ) // ACTOR14 = unknown
        {
          Scene00037( quest, player ); // Scene00037: Normal(Message), id=unknown
          break;
        }
        if( param1 == 2008317 ) // EOBJECT2 = unknown
        {
          Scene00038( quest, player ); // Scene00038: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023757 ) // ACTOR15 = unknown
        {
          Scene00039( quest, player ); // Scene00039: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023758 ) // ACTOR16 = unknown
        {
          Scene00040( quest, player ); // Scene00040: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023759 ) // ACTOR17 = unknown
        {
          Scene00041( quest, player ); // Scene00041: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020380 ) // ACTOR14 = WERCRATA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00042( quest, player ); // Scene00042: Normal(Talk, FadeIn, TargetCanMove), id=WERCRATA
          }
          break;
        }
        if( param1 == 1020381 ) // ACTOR13 = unknown
        {
          Scene00043( quest, player ); // Scene00043: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020509 ) // ACTOR6 = LYSE
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020510 ) // ACTOR7 = MEFFRID
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=MEFFRID
          break;
        }
        if( param1 == 1020513 ) // ACTOR8 = unknown
        {
          Scene00046( quest, player ); // Scene00046: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020514 ) // ACTOR9 = unknown
        {
          Scene00047( quest, player ); // Scene00047: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020515 ) // ACTOR10 = unknown
        {
          Scene00048( quest, player ); // Scene00048: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020382 ) // ACTOR18 = LYSE
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020383 ) // ACTOR19 = MEFFRID
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, TargetCanMove), id=MEFFRID
          break;
        }
        break;
      }
      default:
      {
        playerMgr().sendUrgent( player, "Sequence {} not defined.", quest.getSeq() );
        break;
      }
    }
  }

public:
  void onTalk( World::Quest& quest, Entity::Player& player, uint64_t actorId ) override
  {
    onProgress( quest, player, EVENT_ON_TALK, actorId, 0, 0 );
  }

  void onEmote( World::Quest& quest, uint64_t actorId, uint32_t emoteId, Sapphire::Entity::Player& player ) override
  {
    playerMgr().sendDebug( player, "emote: {}", emoteId );
    onProgress( quest, player, EVENT_ON_EMOTE, actorId, 0, emoteId );
  }

  void onBNpcKill( World::Quest& quest, Entity::BNpc& bnpc, Entity::Player& player ) override
  {
    onProgress( quest, player, EVENT_ON_BNPC_KILL, static_cast< uint64_t >( bnpc.getBNpcNameId() ), bnpc.getLayoutId(), 0 );
  }

  void onWithinRange( World::Quest& quest, Sapphire::Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( quest, player, EVENT_ON_WITHIN_RANGE, static_cast< uint64_t >( param1 ), 0, 0 );
  }

  void onEnterTerritory( World::Quest& quest, Sapphire::Entity::Player& player, uint16_t param1, uint16_t param2 ) override
  {
    onProgress( quest, player, EVENT_ON_ENTER_TERRITORY, static_cast< uint64_t >( param1 ), static_cast< uint32_t >( param2 ), 0 );
  }
  void onEventItem( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId ) override
  {
    onProgress( quest, player, EVENT_ON_EVENT_ITEM, actorId, 0, 0 );
  }
  void onEObjHit( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId, uint32_t actionId ) override
  {
    onProgress( quest, player, EVENT_ON_EOBJ_HIT, actorId, actionId, 0 );
  }
  void onSay( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId, uint32_t sayId ) override
  {
    onProgress( quest, player, EVENT_ON_SAY, actorId, sayId, 0 );
  }

private:
  void checkProgressSeq0( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 1 );
  }
  void checkProgressSeq1( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 2 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 2 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 3 );
    }
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    quest.setBitFlag8( 1, false );
    quest.setSeq( 4 );
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, HIDE_HOTBAR, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=MEFFRID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00003: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00004: Empty(None), id=unknown" );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00005: Normal(Talk, TargetCanMove), id=BEWILDEREDWOMEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00007: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00008: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00009: Empty(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00010: Normal(Talk, TargetCanMove), id=BEWILDEREDWOMEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00011: Normal(Talk, TargetCanMove), id=SHARPEYEDWOMEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: EVENTRANGE0, UI8AL = 2, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 2 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 2 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }


  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00013: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00015: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00016: Empty(None), id=unknown" );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00017: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00018: Normal(Talk, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00019: Empty(None), id=unknown" );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00020: Empty(None), id=unknown" );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00021: Empty(None), id=unknown" );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00022: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00023: Normal(Talk, TargetCanMove), id=SHARPEYEDWOMEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00024: Normal(Talk, TargetCanMove), id=BEWILDEREDWOMEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00027: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00029: Empty(None), id=enemy3" );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_3: EVENTRANGE1, <No Var>, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00030: Empty(None), id=enemy4" );
    quest.setBitFlag8( 1, true );
    checkProgressSeq3( quest, player );
  }




  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00031: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00032: Normal(Talk, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00033: Empty(None), id=unknown" );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00034: Empty(None), id=unknown" );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00035: Empty(None), id=unknown" );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00036: Empty(None), id=unknown" );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00037: Normal(Message), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00038: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00039: Empty(None), id=unknown" );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00040: Empty(None), id=unknown" );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00041: Empty(None), id=unknown" );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR14, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00042: Normal(Talk, FadeIn, TargetCanMove), id=WERCRATA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 42, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00043: Empty(None), id=unknown" );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00044: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00045: Normal(Talk, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00046: Empty(None), id=unknown" );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00047: Empty(None), id=unknown" );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00048: Empty(None), id=unknown" );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00049: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 49, HIDE_HOTBAR, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda124:67994 calling Scene00050: Normal(Talk, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 50, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda124 );
