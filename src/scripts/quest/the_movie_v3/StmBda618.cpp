// FFXIVTheMovie.ParserV3.12
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda618 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda618() : Sapphire::ScriptAPI::QuestScript( 68080 ){}; 
  ~StmBda618() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 8 entries
  //SEQ_2, 8 entries
  //SEQ_3, 5 entries
  //SEQ_4, 8 entries
  //SEQ_5, 6 entries
  //SEQ_6, 2 entries
  //SEQ_7, 1 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1023606
  //ACTOR1 = 1020604
  //ACTOR10 = 1021622
  //ACTOR11 = 1021623
  //ACTOR12 = 1020646
  //ACTOR13 = 5010000
  //ACTOR14 = 1023608
  //ACTOR15 = 1023609
  //ACTOR16 = 1020647
  //ACTOR17 = 1020648
  //ACTOR18 = 1020650
  //ACTOR19 = 1020651
  //ACTOR2 = 1020632
  //ACTOR20 = 1020652
  //ACTOR3 = 1020437
  //ACTOR4 = 1020638
  //ACTOR5 = 1020639
  //ACTOR6 = 1023607
  //ACTOR7 = 1022346
  //ACTOR8 = 1021620
  //ACTOR9 = 1021621
  //BINDACTOR01 = 6905897
  //BINDACTOR02 = 6992969
  //BINDACTOR03 = 6905400
  //CUTSCENEN01 = 1475
  //CUTSCENEN02 = 1476
  //ENEMY0 = 7021931
  //ENEMY1 = 7021932
  //ENEMY2 = 7021933
  //ENEMY3 = 7021934
  //ENEMY4 = 7021935
  //ENEMY5 = 7021936
  //EOBJECT0 = 2009011
  //EOBJECT1 = 2009012
  //EOBJECT2 = 2009013
  //EOBJECT3 = 2008212
  //EVENTACTION0 = 50
  //EVENTACTION1 = 1
  //INSTANCEDUNGEON0 = 55
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019541
  //LOCACTOR03 = 1018509
  //LOCACTOR04 = 1021989
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //POPRANGE0 = 6870953
  //SCREENIMAGE0 = 495
  //TERRITORYTYPE0 = 620

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
        if( param1 == 1023606 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020604 ) // ACTOR1 = RAUBAHN
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020632 ) // ACTOR2 = PIPIN
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020437 ) // ACTOR3 = STARKWOAD
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=STARKWOAD
          break;
        }
        if( param1 == 1020638 ) // ACTOR4 = SERPENTOFFICER
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 ) // ACTOR5 = STORMOFFICER
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1023607 ) // ACTOR6 = ALISAIE
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1022346 ) // ACTOR7 = LYSE
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2009011 ) // EOBJECT0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT0
        if( param1 == 7021931 ) // ENEMY0 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7021932 ) // ENEMY1 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1021620 ) // ACTOR8 = ALPHINAUD
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021621 ) // ACTOR9 = ALISAIE
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1021622 ) // ACTOR10 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021623 ) // ACTOR11 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020646 ) // ACTOR12 = STARKWOAD
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=STARKWOAD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2009012 ) // EOBJECT1 = unknown
        {
          Scene00021( quest, player ); // Scene00021: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7021933 ) // ENEMY2 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7021934 ) // ENEMY3 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1021620 ) // ACTOR8 = ALPHINAUD
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021621 ) // ACTOR9 = ALISAIE
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1021622 ) // ACTOR10 = unknown
        {
          Scene00028( quest, player ); // Scene00028: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021623 ) // ACTOR11 = unknown
        {
          Scene00029( quest, player ); // Scene00029: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020646 ) // ACTOR12 = STARKWOAD
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=STARKWOAD
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020646 ) // ACTOR12 = STARKWOAD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=STARKWOAD
          }
          break;
        }
        if( param1 == 1021620 ) // ACTOR8 = ALPHINAUD
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021621 ) // ACTOR9 = ALISAIE
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1021622 ) // ACTOR10 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021623 ) // ACTOR11 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2009013 ) // EOBJECT2 = unknown
        {
          Scene00037( quest, player ); // Scene00037: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7021935 ) // ENEMY4 = unknown
        {
          Scene00039( quest, player ); // Scene00039: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7021936 ) // ENEMY5 = unknown
        {
          Scene00041( quest, player ); // Scene00041: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1020646 ) // ACTOR12 = STARKWOAD
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=STARKWOAD
          break;
        }
        if( param1 == 1021620 ) // ACTOR8 = ALPHINAUD
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021621 ) // ACTOR9 = ALISAIE
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1021622 ) // ACTOR10 = unknown
        {
          Scene00045( quest, player ); // Scene00045: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021623 ) // ACTOR11 = unknown
        {
          Scene00046( quest, player ); // Scene00046: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 2008212 ) // EOBJECT3 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00048( quest, player ); // Scene00048: Normal(Talk, FadeIn, CreateCharacterTalk), id=unknown
          }
          break;
        }
        if( param1 == 1020646 ) // ACTOR12 = STARKWOAD
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, TargetCanMove), id=STARKWOAD
          break;
        }
        if( param1 == 1021620 ) // ACTOR8 = ALPHINAUD
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021621 ) // ACTOR9 = ALISAIE
        {
          Scene00051( quest, player ); // Scene00051: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1021622 ) // ACTOR10 = unknown
        {
          Scene00052( quest, player ); // Scene00052: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021623 ) // ACTOR11 = unknown
        {
          Scene00053( quest, player ); // Scene00053: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1023608 ) // ACTOR14 = ALPHINAUD
        {
          Scene00054( quest, player ); // Scene00054: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1023609 ) // ACTOR15 = ALISAIE
        {
          Scene00055( quest, player ); // Scene00055: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 7:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00056( quest, player ); // Scene00056: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020647 ) // ACTOR16 = LYSE
        {
          Scene00057( quest, player ); // Scene00057: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020648 ) // ACTOR17 = RAUBAHN
        {
          Scene00058( quest, player ); // Scene00058: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020650 ) // ACTOR18 = SERPENTOFFICER
        {
          Scene00059( quest, player ); // Scene00059: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020651 ) // ACTOR19 = unknown
        {
          Scene00060( quest, player ); // Scene00060: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020652 ) // ACTOR20 = unknown
        {
          Scene00061( quest, player ); // Scene00061: Empty(None), id=unknown
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
    if( quest.getUI8AL() == 2 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 2 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    quest.setBitFlag8( 1, false );
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
    quest.setBitFlag8( 1, false );
    quest.setSeq( 5 );
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 6 );
    }
  }
  void checkProgressSeq6( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 7 );
  }
  void checkProgressSeq7( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00002: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00003: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00004: Normal(Talk, TargetCanMove), id=STARKWOAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00005: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00006: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00008: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 2, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 2 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 2 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00017: Empty(None), id=unknown" );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00018: Empty(None), id=unknown" );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00019: Normal(Talk, TargetCanMove), id=STARKWOAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00021: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00023: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00025: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00027: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00028: Empty(None), id=unknown" );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00029: Empty(None), id=unknown" );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00030: Normal(Talk, TargetCanMove), id=STARKWOAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00031: Normal(Talk, TargetCanMove), id=STARKWOAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00033: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00034: Empty(None), id=unknown" );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00035: Empty(None), id=unknown" );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00037: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setBitFlag8( 1, true );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_4: ENEMY4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00039: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 39, HIDE_HOTBAR, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_4: ENEMY5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00041: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 41, HIDE_HOTBAR, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00042: Normal(Talk, TargetCanMove), id=STARKWOAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, HIDE_HOTBAR, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00044: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00045: Empty(None), id=unknown" );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00046: Empty(None), id=unknown" );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT3, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00048: Normal(Talk, FadeIn, CreateCharacterTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 48, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI | INVIS_ENPC, callback );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00049: Normal(Talk, TargetCanMove), id=STARKWOAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 49, HIDE_HOTBAR, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00050: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 50, HIDE_HOTBAR, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00051: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 51, HIDE_HOTBAR, callback );
  }

  void Scene00052( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00052: Empty(None), id=unknown" );
  }

  void Scene00053( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00053: Empty(None), id=unknown" );
  }

  void Scene00054( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00054: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 54, HIDE_HOTBAR, callback );
  }

  void Scene00055( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00055: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 55, HIDE_HOTBAR, callback );
  }

  void Scene00056( World::Quest& quest, Entity::Player& player ) //SEQ_7: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:6)
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00056: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 6, 0, 0, 0 );
      checkProgressSeq7( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 56, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00057( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00057: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 57, HIDE_HOTBAR, callback );
  }

  void Scene00058( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00058: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 58, HIDE_HOTBAR, callback );
  }

  void Scene00059( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00059: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 59, HIDE_HOTBAR, callback );
  }

  void Scene00060( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00060: Empty(None), id=unknown" );
  }

  void Scene00061( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda618:68080 calling Scene00061: Empty(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda618 );
