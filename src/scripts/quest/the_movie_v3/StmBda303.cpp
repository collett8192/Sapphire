// FFXIVTheMovie.ParserV3.11
// id table disabled
// param used:
//WARP_SCENE12 = 613|-708.77|-0.099|-302.91|-1.65|false
//WARP_SCENE18 = 613|-740.88|1.86|-310.57|-2.08|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda303 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda303() : Sapphire::ScriptAPI::QuestScript( 68015 ){}; 
  ~StmBda303() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 5 entries
  //SEQ_4, 2 entries
  //SEQ_5, 6 entries
  //SEQ_6, 10 entries
  //SEQ_7, 8 entries
  //SEQ_255, 8 entries

  //ACTOR0 = 1023650
  //ACTOR1 = 1023647
  //ACTOR10 = 1019920
  //ACTOR11 = 1019921
  //ACTOR12 = 1019922
  //ACTOR13 = 1019923
  //ACTOR14 = 1019924
  //ACTOR15 = 1019925
  //ACTOR16 = 1019926
  //ACTOR17 = 1020220
  //ACTOR18 = 1023697
  //ACTOR19 = 1023698
  //ACTOR2 = 1023648
  //ACTOR20 = 1019928
  //ACTOR21 = 1019927
  //ACTOR22 = 1019942
  //ACTOR23 = 1019943
  //ACTOR24 = 1019930
  //ACTOR25 = 1019929
  //ACTOR3 = 1023649
  //ACTOR4 = 1023683
  //ACTOR5 = 1019915
  //ACTOR6 = 1019916
  //ACTOR7 = 1019917
  //ACTOR8 = 1019918
  //ACTOR9 = 1019919
  //BINDACTOR0 = 7010342
  //BINDACTOR1 = 7010343
  //BINDACTOR10 = 6829384
  //BINDACTOR2 = 7010344
  //BINDACTOR4 = 6829392
  //BINDACTOR6 = 6829378
  //CUTSCENEN01 = 1410
  //CUTSCENEN02 = 1611
  //ENEMY0 = 6829390
  //ENEMY1 = 6829391
  //EOBJECT0 = 2007851
  //EOBJECT1 = 2008753
  //EOBJECT2 = 2008754
  //EOBJECT3 = 2008765
  //EOBJECT4 = 2008207
  //EVENTRANGE0 = 6841399
  //LCUTSE0 = 149
  //LOCACTOR1 = 1021967
  //LOCACTOR2 = 1019541
  //LOCACTOR3 = 1018509
  //LOCACTOR4 = 1019710
  //POPRANGE0 = 6829379
  //POPRANGE1 = 6829380
  //POPRANGE2 = 6841396

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
        if( param1 == 1023650 ) // ACTOR0 = SOROBAN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SOROBAN
          }
          break;
        }
        if( param1 == 1023647 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1023648 ) // ACTOR2 = ALISAIE
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1023649 ) // ACTOR3 = GOSETSU
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1023683 ) // ACTOR4 = TESHITAPIRATE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=TESHITAPIRATE
          }
          break;
        }
        if( param1 == 1019915 ) // ACTOR5 = GOSETSU
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1019916 ) // ACTOR6 = LYSE
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1019917 ) // ACTOR7 = ALISAIE
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1019918 ) // ACTOR8 = GOSETSU
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1019915 ) // ACTOR5 = SOROBAN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove, Menu, CanCancel), id=SOROBAN
            // +Callback Scene00011: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=SOROBAN
            // +Callback Scene00012: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1019916 ) // ACTOR6 = LYSE
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1019917 ) // ACTOR7 = ALISAIE
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1019918 ) // ACTOR8 = GOSETSU
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1023683 ) // ACTOR4 = TESHITAPIRATE
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=TESHITAPIRATE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1019919 ) // ACTOR9 = SOROBAN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00017( quest, player ); // Scene00017: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=SOROBAN
            // +Callback Scene00018: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1019920 ) // ACTOR10 = LYSE
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1019921 ) // ACTOR11 = ALISAIE
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1019922 ) // ACTOR12 = GOSETSU
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 2007851 ) // EOBJECT0 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1019923 ) // ACTOR13 = ALISAIE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1019924 ) // ACTOR14 = LYSE
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1019925 ) // ACTOR15 = ALISAIE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00025( quest, player ); // Scene00025: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind), id=ALISAIE
          }
          break;
        }
        if( param1 == 1019926 ) // ACTOR16 = LYSE
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020220 ) // ACTOR17 = unknown
        {
          Scene00027( quest, player ); // Scene00027: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008753 ) // EOBJECT1 = unknown
        {
          Scene00028( quest, player ); // Scene00028: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008754 ) // EOBJECT2 = unknown
        {
          Scene00029( quest, player ); // Scene00029: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008765 ) // EOBJECT3 = unknown
        {
          Scene00030( quest, player ); // Scene00030: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 6841399 ) // EVENTRANGE0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00031( quest, player ); // Scene00031: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EVENTRANGE0
        if( param1 == 6829390 ) // ENEMY0 = unknown
        {
          Scene00032( quest, player ); // Scene00032: Empty(None), id=unknown
          break;
        }
        if( param1 == 6829391 ) // ENEMY1 = unknown
        {
          Scene00033( quest, player ); // Scene00033: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008207 ) // EOBJECT4 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020220 ) // ACTOR17 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008753 ) // EOBJECT1 = unknown
        {
          Scene00036( quest, player ); // Scene00036: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008754 ) // EOBJECT2 = unknown
        {
          Scene00037( quest, player ); // Scene00037: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008765 ) // EOBJECT3 = unknown
        {
          Scene00038( quest, player ); // Scene00038: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023697 ) // ACTOR18 = unknown
        {
          Scene00039( quest, player ); // Scene00039: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023698 ) // ACTOR19 = unknown
        {
          Scene00040( quest, player ); // Scene00040: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 1019928 ) // ACTOR20 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1019927 ) // ACTOR21 = ALISAIE
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1019942 ) // ACTOR22 = unknown
        {
          Scene00043( quest, player ); // Scene00043: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019943 ) // ACTOR23 = unknown
        {
          Scene00044( quest, player ); // Scene00044: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020220 ) // ACTOR17 = unknown
        {
          Scene00045( quest, player ); // Scene00045: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008753 ) // EOBJECT1 = unknown
        {
          Scene00046( quest, player ); // Scene00046: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008754 ) // EOBJECT2 = unknown
        {
          Scene00047( quest, player ); // Scene00047: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008765 ) // EOBJECT3 = unknown
        {
          Scene00048( quest, player ); // Scene00048: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019930 ) // ACTOR24 = LYSE
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1019929 ) // ACTOR25 = ALISAIE
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1019942 ) // ACTOR22 = unknown
        {
          Scene00051( quest, player ); // Scene00051: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019943 ) // ACTOR23 = unknown
        {
          Scene00052( quest, player ); // Scene00052: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020220 ) // ACTOR17 = unknown
        {
          Scene00053( quest, player ); // Scene00053: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008753 ) // EOBJECT1 = unknown
        {
          Scene00054( quest, player ); // Scene00054: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008754 ) // EOBJECT2 = unknown
        {
          Scene00055( quest, player ); // Scene00055: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008765 ) // EOBJECT3 = unknown
        {
          Scene00056( quest, player ); // Scene00056: Empty(None), id=unknown
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
      quest.setSeq( 5 );
    }
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
    if( quest.getUI8AL() == 2 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 7 );
    }
  }
  void checkProgressSeq7( World::Quest& quest, Entity::Player& player )
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
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00005: Normal(Talk, TargetCanMove), id=TESHITAPIRATE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00007: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00009: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00010: Normal(Talk, TargetCanMove, Menu, CanCancel), id=SOROBAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00011( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }
  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00011: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=SOROBAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00012( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00012: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 613 )->getGuId(), { -708.77, -0.099, -302.91 }, -1.65 );
    };
    eventMgr().playQuestScene( player, getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00015: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00016: Normal(Talk, TargetCanMove), id=TESHITAPIRATE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00017: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=SOROBAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00018( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00018: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 613 )->getGuId(), { -740.88, 1.86, -310.57 }, -2.08 );
    };
    eventMgr().playQuestScene( player, getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00019: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00021: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00022: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR13, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00024: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR15, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00025: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00026: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00027: Empty(None), id=unknown" );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00028: Empty(None), id=unknown" );
    checkProgressSeq5( quest, player );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00029: Empty(None), id=unknown" );
    checkProgressSeq5( quest, player );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00030: Empty(None), id=unknown" );
    checkProgressSeq5( quest, player );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_6: EVENTRANGE0, UI8AL = 2, Flag8(1)=True(Todo:5)
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00031: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 2 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 5, 2, quest.getUI8AL(), 2 );
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_6: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00032: Empty(None), id=unknown" );
    checkProgressSeq6( quest, player );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_6: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00033: Empty(None), id=unknown" );
    checkProgressSeq6( quest, player );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_6: EOBJECT4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00034: Empty(None), id=unknown" );
    checkProgressSeq6( quest, player );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00035: Empty(None), id=unknown" );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_6: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00036: Empty(None), id=unknown" );
    checkProgressSeq6( quest, player );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_6: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00037: Empty(None), id=unknown" );
    checkProgressSeq6( quest, player );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_6: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00038: Empty(None), id=unknown" );
    checkProgressSeq6( quest, player );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00039: Empty(None), id=unknown" );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00040: Empty(None), id=unknown" );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR20, UI8AL = 1, Flag8(1)=True(Todo:6)
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00041: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 6, 0, 0, 0 );
      checkProgressSeq7( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 41, HIDE_HOTBAR, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00042: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00043: Empty(None), id=unknown" );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00044: Empty(None), id=unknown" );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00045: Empty(None), id=unknown" );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_7: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00046: Empty(None), id=unknown" );
    checkProgressSeq7( quest, player );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_7: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00047: Empty(None), id=unknown" );
    checkProgressSeq7( quest, player );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_7: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00048: Empty(None), id=unknown" );
    checkProgressSeq7( quest, player );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00049: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 49, HIDE_HOTBAR, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR25, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00050: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 50, HIDE_HOTBAR, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00051: Empty(None), id=unknown" );
  }

  void Scene00052( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00052: Empty(None), id=unknown" );
  }

  void Scene00053( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00053: Empty(None), id=unknown" );
  }

  void Scene00054( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00054: Empty(None), id=unknown" );
  }

  void Scene00055( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00055: Empty(None), id=unknown" );
  }

  void Scene00056( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda303:68015 calling Scene00056: Empty(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda303 );
