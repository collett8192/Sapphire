// FFXIVTheMovie.ParserV3.11
// param used:
//WARP_SCENE26 = 628|-130.2|-7|-59|1.57|false
//PRIVATE_SCENE8 = 680
//PRIVATE_SCENE14 = 680
//PRIVATE_SCENE18 = 680
//PRIVATE_SCENE27 = 680
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda139 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda139() : Sapphire::ScriptAPI::QuestScript( 68005 ){}; 
  ~StmBda139() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 6 entries
  //SEQ_3, 5 entries
  //SEQ_4, 8 entries
  //SEQ_5, 3 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1020436
  //ACTOR1 = 1020439
  //ACTOR10 = 5010000
  //ACTOR11 = 1020443
  //ACTOR12 = 1020444
  //ACTOR13 = 1020445
  //ACTOR14 = 1020454
  //ACTOR15 = 1020450
  //ACTOR16 = 1020451
  //ACTOR17 = 1020452
  //ACTOR18 = 1020453
  //ACTOR19 = 1021740
  //ACTOR2 = 1020396
  //ACTOR3 = 1020014
  //ACTOR4 = 1020441
  //ACTOR5 = 1020442
  //ACTOR6 = 1020447
  //ACTOR7 = 1020448
  //ACTOR8 = 1020449
  //ACTOR9 = 1023076
  //CUTSCENEN01 = 1398
  //CUTSCENEN02 = 1399
  //CUTSCENEN03 = 1400
  //CUTSCENEN04 = 1401
  //INSTANCEDUNGEON0 = 52
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019541
  //LOCACTOR03 = 1018509
  //LOCACTOR04 = 1003785
  //LOCACTOR05 = 1019542
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //POPRANGE0 = 6848086
  //POPRANGE1 = 6848154
  //SCREENIMAGE0 = 491
  //TERRITORYTYPE0 = 680
  //TERRITORYTYPE1 = 628

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LYSE
        break;
      }
      case 1:
      {
        if( param1 == 1020439 ) // ACTOR1 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020396 ) // ACTOR2 = TATARU
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1020014 ) // ACTOR3 = ALISAIE
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020441 ) // ACTOR4 = LYSE
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020442 ) // ACTOR5 = KRAKENSDECKHAND
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND
          break;
        }
        break;
      }
      case 2:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00007( quest, player ); // Scene00007: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1020442 ) // ACTOR5 = KRAKENSDECKHAND
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND
          break;
        }
        if( param1 == 1020396 ) // ACTOR2 = TATARU
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1020439 ) // ACTOR1 = ALPHINAUD
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020014 ) // ACTOR3 = ALISAIE
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020441 ) // ACTOR4 = LYSE
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020447 ) // ACTOR6 = CARVALLAIN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, FadeIn, TargetCanMove), id=CARVALLAIN
          }
          break;
        }
        if( param1 == 1020442 ) // ACTOR5 = KRAKENSDECKHAND
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND
          break;
        }
        if( param1 == 1020448 ) // ACTOR7 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020449 ) // ACTOR8 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023076 ) // ACTOR9 = KRAKENSDECKHAND
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020442 ) // ACTOR5 = KRAKENSDECKHAND
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND
          break;
        }
        if( param1 == 1020443 ) // ACTOR11 = ALPHINAUD
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020444 ) // ACTOR12 = ALISAIE
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020445 ) // ACTOR13 = LYSE
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020447 ) // ACTOR6 = CARVALLAIN
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=CARVALLAIN
          break;
        }
        if( param1 == 1023076 ) // ACTOR9 = KRAKENSDECKHAND
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND
          break;
        }
        if( param1 == 1020448 ) // ACTOR7 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020449 ) // ACTOR8 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00026( quest, player ); // Scene00026: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1020442 ) // ACTOR5 = KRAKENSDECKHAND
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND
          break;
        }
        if( param1 == 1023076 ) // ACTOR9 = KRAKENSDECKHAND
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove, ReturnTrue), id=KRAKENSDECKHAND
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020454 ) // ACTOR14 = CARVALLAIN
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CARVALLAIN
          break;
        }
        if( param1 == 1020450 ) // ACTOR15 = ALPHINAUD
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020451 ) // ACTOR16 = ALISAIE
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020452 ) // ACTOR17 = LYSE
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020453 ) // ACTOR18 = TATARU
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1021740 ) // ACTOR19 = KRAKENSDECKHAND
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND
          break;
        }
        if( param1 == 1020442 ) // ACTOR5 = KRAKENSDECKHAND
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND
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
    quest.setSeq( 3 );
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 4 );
    }
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 5 );
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, HIDE_HOTBAR, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00005: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00006: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00007: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00008: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 680 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00009: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00012: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00013: Normal(Talk, FadeIn, TargetCanMove), id=CARVALLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00014: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 680 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00016: Empty(None), id=unknown" );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00017: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00018: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 680 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00021: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00022: Normal(Talk, TargetCanMove), id=CARVALLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00023: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00024: Empty(None), id=unknown" );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00025: Empty(None), id=unknown" );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_5: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00026: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 628 )->getGuId(), { -130.2, -7, -59 }, 1.57 );
    };
    eventMgr().playQuestScene( player, getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00027: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 680 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00028: Normal(Talk, TargetCanMove, ReturnTrue), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CARVALLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00031: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00032: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00033: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00034: Normal(Talk, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda139:68005 calling Scene00035: Normal(Talk, YesNo, TargetCanMove), id=KRAKENSDECKHAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
      }
    };
    eventMgr().playQuestScene( player, getId(), 35, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda139 );
