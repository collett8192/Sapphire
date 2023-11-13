// FFXIVTheMovie.ParserV3.11
// param used:
//ID_ACTOR7 = 2097153
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda412 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda412() : Sapphire::ScriptAPI::QuestScript( 68047 ){}; 
  ~StmBda412() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 4 entries
  //SEQ_2, 6 entries
  //SEQ_3, 14 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1019417
  //ACTOR1 = 1021730
  //ACTOR10 = 1021606
  //ACTOR11 = 1021607
  //ACTOR12 = 1021609
  //ACTOR13 = 1021610
  //ACTOR14 = 1021625
  //ACTOR15 = 1022085
  //ACTOR2 = 1021732
  //ACTOR3 = 1021731
  //ACTOR4 = 1021605
  //ACTOR5 = 1022078
  //ACTOR6 = 1019431
  //ACTOR7 = 5010000
  //ACTOR8 = 1021624
  //ACTOR9 = 1021608
  //ENEMY0 = 6875162
  //ENEMY1 = 6875163
  //ENEMY2 = 6875164
  //EOBJECT0 = 2008264
  //EOBJECT1 = 2008265
  //EVENTACTION0 = 1
  //EVENTACTION1 = 36
  //EVENTRANGE0 = 6888119
  //EVENTRANGE1 = 6875161
  //LOCAOKI = 1022002
  //LOCAURA001 = 1021983
  //LOCAURA002 = 1021984
  //LOCBINDBAATU = 6887824
  //LOCBINDDUID = 6840981
  //LOCBINDGOSETSUDOTA = 6865911
  //LOCBINDGOUSETSU = 6872468
  //LOCBINDGOUSETSU002 = 6865882
  //LOCBINDHIEN = 6872466
  //LOCBINDIET001 = 6865903
  //LOCBINDIET002 = 6865905
  //LOCBINDLISE = 6872467
  //LOCBINDMAGUNAI = 6840967
  //LOCCAMERAHUKEI = 6983463
  //LOCGESERU = 1019579
  //LOCGESERU002 = 6865929
  //LOCGOKAI = 4312
  //LOCIET = 1022001
  //LOCPOSEWINK = 621
  //LOCPOSAOKI = 6983461
  //LOCPOSGESERU = 6983462
  //LOCSADO = 1018980
  //LOCSEAKU = 44
  //LOCSESHIMARU = 45

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
        if( param1 == 1019417 ) // ACTOR0 = MAGNAI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu, ENpcBind), id=MAGNAI
          }
          break;
        }
        if( param1 == 1021730 ) // ACTOR1 = HIEN
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021732 ) // ACTOR2 = LYSE
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021731 ) // ACTOR3 = GOSETSU
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1021605 ) // ACTOR4 = GOSETSU
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=GOSETSU
          }
          break;
        }
        if( param1 == 1019417 ) // ACTOR0 = MAGNAI
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=MAGNAI
          break;
        }
        if( param1 == 1022078 ) // ACTOR5 = BAATU
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=BAATU
          break;
        }
        if( param1 == 1019431 ) // ACTOR6 = DAIDUKUL
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=DAIDUKUL
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 5010000 || param1 == 2097153 ) // ACTOR7 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=unknown
          }
          break;
        }
        if( param1 == 1021624 ) // ACTOR8 = GOSETSU
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 2008264 ) // EOBJECT0 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022078 ) // ACTOR5 = BAATU
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=BAATU
          break;
        }
        if( param1 == 1019431 ) // ACTOR6 = DAIDUKUL
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=DAIDUKUL
          break;
        }
        if( param1 == 1019417 ) // ACTOR0 = MAGNAI
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=MAGNAI
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 6875161 ) // EVENTRANGE1 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00019: Normal(Message), id=unknown
          break;
        }
        if( param1 == 1021608 ) // ACTOR9 = DOTHARL02511
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00020( quest, player ); // Scene00020: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=DOTHARL02511
          }
          break;
        }
        // BNpcHack credit moved to ACTOR9
        if( param1 == 6875162 ) // ENEMY0 = unknown
        {
          Scene00021( quest, player ); // Scene00021: Empty(None), id=unknown
          break;
        }
        if( param1 == 6875163 ) // ENEMY1 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          break;
        }
        if( param1 == 6875164 ) // ENEMY2 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021608 ) // ACTOR9 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008265 ) // EOBJECT1 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021606 ) // ACTOR10 = GOSETSU
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021607 ) // ACTOR11 = unknown
        {
          Scene00027( quest, player ); // Scene00027: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021609 ) // ACTOR12 = unknown
        {
          Scene00028( quest, player ); // Scene00028: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021610 ) // ACTOR13 = unknown
        {
          Scene00029( quest, player ); // Scene00029: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019431 ) // ACTOR6 = DAIDUKUL
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=DAIDUKUL
          break;
        }
        if( param1 == 1019417 ) // ACTOR0 = MAGNAI
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=MAGNAI
          break;
        }
        if( param1 == 1022078 ) // ACTOR5 = BAATU
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=BAATU
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021625 ) // ACTOR14 = GOSETSU
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021608 ) // ACTOR9 = DOTHARL02511
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=DOTHARL02511
          break;
        }
        if( param1 == 1022085 ) // ACTOR15 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019431 ) // ACTOR6 = DAIDUKUL
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=DAIDUKUL
          break;
        }
        if( param1 == 1022078 ) // ACTOR5 = BAATU
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=BAATU
          break;
        }
        if( param1 == 1019417 ) // ACTOR0 = MAGNAI
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=MAGNAI
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
    if( quest.getUI8AL() == 3 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu, ENpcBind), id=MAGNAI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        checkProgressSeq0( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00002: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00006: Normal(Talk, TargetCanMove), id=MAGNAI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00007: Normal(Talk, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00008: Normal(Talk, TargetCanMove), id=DAIDUKUL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00011: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00014: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00015: Normal(Talk, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00016: Normal(Talk, TargetCanMove), id=DAIDUKUL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00017: Normal(Talk, TargetCanMove), id=MAGNAI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: EVENTRANGE1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00018: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00019( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }
  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: EVENTRANGE1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00019: Normal(Message), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, UI8AL = 3, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00020: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=DOTHARL02511" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 3 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00021: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00022: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00023: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00024: Empty(None), id=unknown" );
    quest.setBitFlag8( 1, true );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00025: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00026: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00027: Empty(None), id=unknown" );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00028: Empty(None), id=unknown" );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00029: Empty(None), id=unknown" );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00030: Normal(Talk, TargetCanMove), id=DAIDUKUL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00031: Normal(Talk, TargetCanMove), id=MAGNAI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00032: Normal(Talk, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00033: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00034: Normal(Talk, TargetCanMove), id=DOTHARL02511" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00035: Empty(None), id=unknown" );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00036: Normal(Talk, TargetCanMove), id=DAIDUKUL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00037: Normal(Talk, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda412:68047 calling Scene00038: Normal(Talk, TargetCanMove), id=MAGNAI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda412 );
