// FFXIVTheMovie.ParserV3.11
// param used:
//ID_ACTOR6 = 2097153
//FORCEITEM_SEQ2 = 
//_ACTOR6 = B
//_ACTOR6B = 2|2
//_ACTOR9 = B
//_ACTOR9B = 5|2
//_ACTOR10 = B
//_ACTOR10B = 5|2
//_ACTOR11 = B
//_ACTOR11B = 5|2
//TODO_DISABLED = 
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda204 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda204() : Sapphire::ScriptAPI::QuestScript( 68009 ){}; 
  ~StmBda204() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_4, 3 entries
  //SEQ_5, 5 entries
  //SEQ_255, 5 entries

  //ACTIONTIMELINEEMOTEWELCOMEUPPER = 591
  //ACTOR0 = 1020465
  //ACTOR1 = 1020464
  //ACTOR10 = 1020470
  //ACTOR11 = 1020471
  //ACTOR12 = 1020472
  //ACTOR2 = 1020466
  //ACTOR3 = 1020467
  //ACTOR4 = 1020468
  //ACTOR5 = 1022086
  //ACTOR6 = 5010000
  //ACTOR7 = 1018982
  //ACTOR8 = 1019002
  //ACTOR9 = 1020469
  //BINDACTOR0 = 6843430
  //BINDACTOR1 = 6843431
  //BINDACTOR2 = 6843427
  //BINDACTOR3 = 6843429
  //BINDACTOR4 = 6654180
  //BINDACTOR5 = 6654205
  //BINDACTOR6 = 7005898
  //EVENTRANGE0 = 7005899
  //EVENTPICTRUEMAINQUEST4002 = 531
  //ITEM0 = 2002099
  //LOCACTOR0 = 1018509
  //LOCBGMTOHO = 465
  //POPRANGE0 = 6958867

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
        if( param1 == 1020465 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, AutoFadeIn, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020464 ) // ACTOR1 = HANCOCK
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1020466 ) // ACTOR2 = TATARU
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1020467 ) // ACTOR3 = LYSE
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020468 ) // ACTOR4 = ALISAIE
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( param1 == 1022086 ) // ACTOR5 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove, SystemTalk), id=LYSE
          }
          break;
        }
        if( param1 == 1020466 ) // ACTOR2 = TATARU
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1020464 ) // ACTOR1 = HANCOCK
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( param1 == 5010000 || param1 == 2097153 ) // ACTOR6 = unknown, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, ENpcBind), id=unknown
          }
          else
          {
            Scene00010( quest, player ); // Scene00010: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1020466 ) // ACTOR2 = TATARU
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1020464 ) // ACTOR1 = HANCOCK
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1022086 ) // ACTOR5 = LYSE
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove, SystemTalk), id=LYSE
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 1018982 ) // ACTOR7 = KARAKU
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00014( quest, player ); // Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00015: Normal(Talk, FadeIn, TargetCanMove), id=KARAKU
          }
          break;
        }
        if( param1 == 1020466 ) // ACTOR2 = TATARU
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1020464 ) // ACTOR1 = HANCOCK
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 5010000 || param1 == 2097153 ) // ACTOR6 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 1019002 ) // ACTOR8 = KOTOKAZE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00020( quest, player ); // Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00021: Normal(Talk, FadeIn, TargetCanMove), id=KOTOKAZE
          }
          break;
        }
        if( param1 == 1018982 ) // ACTOR7 = KARAKU
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=KARAKU
          break;
        }
        if( param1 == 5010000 || param1 == 2097153 ) // ACTOR6 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8CH max stack 1
      case 5:
      {
        if( param1 == 1020469 ) // ACTOR9 = KUGANEFERRYMAN, CB=2
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00025( quest, player ); // Scene00025: NpcTrade(TargetCanMove), id=unknown
            // +Callback Scene00026: Normal(Talk, TargetCanMove), id=KUGANEFERRYMAN
          }
          else
          {
            Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=KUGANEFERRYMAN
          }
          break;
        }
        if( param1 == 1020470 ) // ACTOR10 = KUGANECAPTAIN, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00028( quest, player ); // Scene00028: NpcTrade(TargetCanMove), id=unknown
            // +Callback Scene00029: Normal(Talk, TargetCanMove), id=KUGANECAPTAIN
          }
          else
          {
            Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=KUGANECAPTAIN
          }
          break;
        }
        if( param1 == 1020471 ) // ACTOR11 = RADZATHANMERCHANT, CB=2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00031( quest, player ); // Scene00031: NpcTrade(TargetCanMove), id=unknown
            // +Callback Scene00032: Normal(Talk, TargetCanMove), id=RADZATHANMERCHANT
          }
          else
          {
            Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=RADZATHANMERCHANT
          }
          break;
        }
        if( param1 == 1019002 ) // ACTOR8 = KOTOKAZE
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=KOTOKAZE
          break;
        }
        if( param1 == 5010000 || param1 == 2097153 ) // ACTOR6 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1020472 ) // ACTOR12 = LYSE
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020469 ) // ACTOR9 = KUGANEFERRYMAN
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=KUGANEFERRYMAN
          break;
        }
        if( param1 == 1020470 ) // ACTOR10 = KUGANECAPTAIN
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=KUGANECAPTAIN
          break;
        }
        if( param1 == 1020471 ) // ACTOR11 = RADZATHANMERCHANT
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=RADZATHANMERCHANT
          break;
        }
        if( param1 == 5010000 || param1 == 2097153 ) // ACTOR6 = unknown
        {
          Scene00041( quest, player ); // Scene00041: Normal(None), id=unknown
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
      quest.setUI8BH( 1 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 3 );
    }
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
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setUI8BH( 0 );
      quest.setSeq( 5 );
      quest.setUI8CH( 1 );
    }
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8BL() == 1 )
      if( quest.getUI8AL() == 1 )
        if( quest.getUI8BH() == 1 )
        {
          quest.setUI8BL( 0 );
          quest.setUI8AL( 0 );
          quest.setUI8BH( 0 );
          quest.setBitFlag8( 1, false );
          quest.setBitFlag8( 2, false );
          quest.setBitFlag8( 3, false );
          quest.setUI8CH( 0 );
          quest.setSeq( 255 );
        }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, AutoFadeIn, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00002: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00006: Normal(Talk, TargetCanMove, SystemTalk), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00007: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00008: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00009: Normal(Talk, ENpcBind), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }
  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00010: Normal(SystemTalk), id=unknown" );
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, nullptr );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00011: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00012: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00013: Normal(Talk, TargetCanMove, SystemTalk), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00015( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }
  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00015: Normal(Talk, FadeIn, TargetCanMove), id=KARAKU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00016: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00017: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00018: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00021( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }
  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00021: Normal(Talk, FadeIn, TargetCanMove), id=KOTOKAZE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00022: Normal(Talk, TargetCanMove), id=KARAKU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00023: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR9, UI8BL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00025: NpcTrade(TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00026( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }
  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR9, UI8BL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00026: Normal(Talk, TargetCanMove), id=KUGANEFERRYMAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }
  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR9, UI8BL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00027: Normal(Talk, TargetCanMove), id=KUGANEFERRYMAN" );
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, nullptr );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR10, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00028: NpcTrade(TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00029( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }
  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR10, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00029: Normal(Talk, TargetCanMove), id=KUGANECAPTAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }
  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR10, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00030: Normal(Talk, TargetCanMove), id=KUGANECAPTAIN" );
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, nullptr );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR11, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00031: NpcTrade(TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00032( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }
  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR11, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00032: Normal(Talk, TargetCanMove), id=RADZATHANMERCHANT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }
  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR11, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00033: Normal(Talk, TargetCanMove), id=RADZATHANMERCHANT" );
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, nullptr );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00034: Normal(Talk, TargetCanMove), id=KOTOKAZE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00035: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, HIDE_HOTBAR, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00038: Normal(Talk, TargetCanMove), id=KUGANEFERRYMAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, HIDE_HOTBAR, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00039: Normal(Talk, TargetCanMove), id=KUGANECAPTAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, HIDE_HOTBAR, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00040: Normal(Talk, TargetCanMove), id=RADZATHANMERCHANT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, HIDE_HOTBAR, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda204:68009 calling Scene00041: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda204 );
