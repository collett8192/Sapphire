// FFXIVTheMovie.ParserV3.12
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda603 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda603() : Sapphire::ScriptAPI::QuestScript( 68065 ){}; 
  ~StmBda603() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 18 entries
  //SEQ_2, 17 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1020568
  //ACTOR1 = 1020567
  //ACTOR10 = 1023776
  //ACTOR11 = 1020574
  //ACTOR12 = 1020575
  //ACTOR13 = 1020576
  //ACTOR14 = 1023583
  //ACTOR15 = 1023584
  //ACTOR16 = 1023585
  //ACTOR17 = 1023586
  //ACTOR18 = 1023587
  //ACTOR19 = 1023588
  //ACTOR2 = 1020569
  //ACTOR20 = 1020573
  //ACTOR21 = 1022089
  //ACTOR22 = 1022090
  //ACTOR3 = 1020570
  //ACTOR4 = 1020571
  //ACTOR5 = 1020572
  //ACTOR6 = 1022087
  //ACTOR7 = 1022088
  //ACTOR8 = 1023774
  //ACTOR9 = 1023775
  //BINDACTOR01 = 6853849
  //BINDACTOR02 = 6853850
  //ENEMY0 = 7021911
  //ENEMY1 = 7021912
  //ENEMY2 = 7021913
  //EOBJECT0 = 2009005
  //EOBJECT1 = 2009006
  //EVENTRANGE0 = 7021090
  //EVENTRANGE1 = 7021091
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295

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
        if( param1 == 1020568 ) // ACTOR0 = CONRAD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CONRAD
          }
          break;
        }
        if( param1 == 1020567 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020569 ) // ACTOR2 = ARENVALD
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1020570 ) // ACTOR3 = unknown
        {
          Scene00004( quest, player ); // Scene00004: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020571 ) // ACTOR4 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020572 ) // ACTOR5 = ANANTASOLDIER
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=ANANTASOLDIER
          break;
        }
        if( param1 == 1022087 ) // ACTOR6 = MNAAGO
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022088 ) // ACTOR7 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 7021090 ) // EVENTRANGE0 = unknown
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EVENTRANGE0
        if( param1 == 7021911 ) // ENEMY0 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Empty(None), id=unknown
          break;
        }
        if( param1 == 7021091 ) // EVENTRANGE1 = unknown
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00011( quest, player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EVENTRANGE1
        if( param1 == 7021912 ) // ENEMY1 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Empty(None), id=unknown
          break;
        }
        if( param1 == 7021913 ) // ENEMY2 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020567 ) // ACTOR1 = LYSE
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1022087 ) // ACTOR6 = MNAAGO
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022088 ) // ACTOR7 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020569 ) // ACTOR2 = ARENVALD
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1020570 ) // ACTOR3 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020571 ) // ACTOR4 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020572 ) // ACTOR5 = ANANTASOLDIER
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ANANTASOLDIER
          break;
        }
        if( param1 == 2009005 ) // EOBJECT0 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023774 ) // ACTOR8 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Empty(None), id=unknown
          break;
        }
        if( param1 == 2009006 ) // EOBJECT1 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023775 ) // ACTOR9 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023776 ) // ACTOR10 = unknown
        {
          Scene00026( quest, player ); // Scene00026: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020574 ) // ACTOR11 = RAUBAHN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00027( quest, player ); // Scene00027: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1020575 ) // ACTOR12 = ALPHINAUD
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020576 ) // ACTOR13 = ALISAIE
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020567 ) // ACTOR1 = LYSE
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1022087 ) // ACTOR6 = MNAAGO
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022088 ) // ACTOR7 = unknown
        {
          Scene00033( quest, player ); // Scene00033: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020569 ) // ACTOR2 = ARENVALD
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1020570 ) // ACTOR3 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020571 ) // ACTOR4 = unknown
        {
          Scene00036( quest, player ); // Scene00036: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020572 ) // ACTOR5 = ANANTASOLDIER
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=ANANTASOLDIER
          break;
        }
        if( param1 == 1023583 ) // ACTOR14 = unknown
        {
          Scene00038( quest, player ); // Scene00038: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023584 ) // ACTOR15 = unknown
        {
          Scene00039( quest, player ); // Scene00039: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023585 ) // ACTOR16 = unknown
        {
          Scene00040( quest, player ); // Scene00040: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023586 ) // ACTOR17 = unknown
        {
          Scene00041( quest, player ); // Scene00041: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023587 ) // ACTOR18 = unknown
        {
          Scene00042( quest, player ); // Scene00042: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023588 ) // ACTOR19 = unknown
        {
          Scene00043( quest, player ); // Scene00043: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020573 ) // ACTOR20 = RESISTANCEGATEGUARD
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD
          break;
        }
        if( param1 == 1022089 ) // ACTOR21 = ALPHINAUD
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1022090 ) // ACTOR22 = ALISAIE
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020567 ) // ACTOR1 = LYSE
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=LYSE
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
    if( quest.getUI8BH() == 1 )
      if( quest.getUI8AL() == 2 )
      {
        quest.setUI8BH( 0 );
        quest.setUI8AL( 0 );
        quest.setBitFlag8( 1, false );
        quest.setBitFlag8( 2, false );
        quest.setSeq( 2 );
      }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
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
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00003: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00004: Empty(None), id=unknown" );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00005: Empty(None), id=unknown" );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00006: Normal(Talk, TargetCanMove), id=ANANTASOLDIER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00007: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00008: Empty(None), id=unknown" );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: EVENTRANGE0, UI8BH = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00010: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: EVENTRANGE1, UI8AL = 2, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 2 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00012: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00013: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00014: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00015: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00016: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00017: Empty(None), id=unknown" );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00018: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00019: Empty(None), id=unknown" );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00020: Empty(None), id=unknown" );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00021: Normal(Talk, TargetCanMove), id=ANANTASOLDIER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00022: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00023: Empty(None), id=unknown" );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00024: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00025: Empty(None), id=unknown" );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00026: Empty(None), id=unknown" );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00027: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00029: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00030: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00031: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00032: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00033: Empty(None), id=unknown" );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00034: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00035: Empty(None), id=unknown" );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00036: Empty(None), id=unknown" );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00037: Normal(Talk, TargetCanMove), id=ANANTASOLDIER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00038: Empty(None), id=unknown" );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00039: Empty(None), id=unknown" );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00040: Empty(None), id=unknown" );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00041: Empty(None), id=unknown" );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00042: Empty(None), id=unknown" );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00043: Empty(None), id=unknown" );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00044: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00045: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, HIDE_HOTBAR, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, HIDE_HOTBAR, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda603:68065 calling Scene00048: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda603 );
