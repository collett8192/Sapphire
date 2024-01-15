// FFXIVTheMovie.ParserV3.12
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda614 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda614() : Sapphire::ScriptAPI::QuestScript( 68076 ){}; 
  ~StmBda614() = default; 

  //SEQ_0, 11 entries
  //SEQ_1, 12 entries
  //SEQ_2, 11 entries
  //SEQ_255, 11 entries

  //ACTOR0 = 1020631
  //ACTOR1 = 1020604
  //ACTOR10 = 1022341
  //ACTOR11 = 1020633
  //ACTOR2 = 1020632
  //ACTOR3 = 1020629
  //ACTOR4 = 1020630
  //ACTOR5 = 1020628
  //ACTOR6 = 1020638
  //ACTOR7 = 1020639
  //ACTOR8 = 1022339
  //ACTOR9 = 1022340
  //BINDACTOR01 = 6858247
  //CUTSCENEN01 = 1612
  //ENEMY0 = 7005957
  //EOBJECT0 = 2009007
  //EOBJECT1 = 2008211
  //EVENTACTION0 = 11
  //EVENTACTION1 = 1
  //LOCACTOR01 = 1018509
  //POPRANGE0 = 6858788

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
        if( param1 == 1020631 ) // ACTOR0 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=LYSE
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
        if( param1 == 1020629 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020630 ) // ACTOR4 = ALISAIE
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020628 ) // ACTOR5 = MNAAGO
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020638 ) // ACTOR6 = SERPENTOFFICER
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 ) // ACTOR7 = STORMOFFICER
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1022339 ) // ACTOR8 = ARENVALD
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022340 ) // ACTOR9 = VMAHTIA
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022341 ) // ACTOR10 = JMOLDVA
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2009007 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00013( quest, player ); // Scene00013: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT0
        if( param1 == 7005957 ) // ENEMY0 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1020604 ) // ACTOR1 = RAUBAHN
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020632 ) // ACTOR2 = PIPIN
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020629 ) // ACTOR3 = ALPHINAUD
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020630 ) // ACTOR4 = ALISAIE
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020628 ) // ACTOR5 = MNAAGO
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020638 ) // ACTOR6 = SERPENTOFFICER
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 ) // ACTOR7 = STORMOFFICER
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1022339 ) // ACTOR8 = ARENVALD
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022340 ) // ACTOR9 = VMAHTIA
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022341 ) // ACTOR10 = JMOLDVA
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2008211 ) // EOBJECT1 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00027( quest, player ); // Scene00027: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1020604 ) // ACTOR1 = RAUBAHN
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020632 ) // ACTOR2 = PIPIN
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020629 ) // ACTOR3 = ALPHINAUD
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020630 ) // ACTOR4 = ALISAIE
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020628 ) // ACTOR5 = MNAAGO
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020638 ) // ACTOR6 = SERPENTOFFICER
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 ) // ACTOR7 = STORMOFFICER
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1022339 ) // ACTOR8 = ARENVALD
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022340 ) // ACTOR9 = VMAHTIA
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022341 ) // ACTOR10 = JMOLDVA
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020633 ) // ACTOR11 = LYSE
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020604 ) // ACTOR1 = RAUBAHN
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020632 ) // ACTOR2 = PIPIN
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020629 ) // ACTOR3 = ALPHINAUD
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020630 ) // ACTOR4 = ALISAIE
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020628 ) // ACTOR5 = MNAAGO
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020638 ) // ACTOR6 = SERPENTOFFICER
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 ) // ACTOR7 = STORMOFFICER
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1022339 ) // ACTOR8 = ARENVALD
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022340 ) // ACTOR9 = VMAHTIA
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022341 ) // ACTOR10 = JMOLDVA
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=JMOLDVA
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
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00002: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00003: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00006: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00007: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00008: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00009: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00010: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00011: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00015: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00016: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00017: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00020: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00021: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00022: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00023: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00024: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00025: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00027: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00028: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00029: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00031: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00032: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00033: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00034: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00035: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, HIDE_HOTBAR, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00036: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00037: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 38, HIDE_HOTBAR, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00039: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, HIDE_HOTBAR, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00040: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, HIDE_HOTBAR, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00041: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, HIDE_HOTBAR, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00042: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00043: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, HIDE_HOTBAR, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00044: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00045: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00046: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, HIDE_HOTBAR, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00047: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, HIDE_HOTBAR, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda614:68076 calling Scene00048: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda614 );
