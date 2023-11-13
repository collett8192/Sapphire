// FFXIVTheMovie.ParserV3.11
// param used:
//ID_ACTOR18 = 2097153
//SCENE_38 REMOVED!!
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda417 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda417() : Sapphire::ScriptAPI::QuestScript( 68052 ){}; 
  ~StmBda417() = default; 

  //SEQ_0, 9 entries
  //SEQ_1, 13 entries
  //SEQ_2, 11 entries
  //SEQ_3, 13 entries
  //SEQ_255, 11 entries

  //ACTOR0 = 1020540
  //ACTOR1 = 1020541
  //ACTOR10 = 1020539
  //ACTOR11 = 1021633
  //ACTOR12 = 1021632
  //ACTOR13 = 1021631
  //ACTOR14 = 1019396
  //ACTOR15 = 1021641
  //ACTOR16 = 1021640
  //ACTOR17 = 1021639
  //ACTOR18 = 5010000
  //ACTOR2 = 1020542
  //ACTOR3 = 1021634
  //ACTOR4 = 1021636
  //ACTOR5 = 1021637
  //ACTOR6 = 1021638
  //ACTOR7 = 1021635
  //ACTOR8 = 1021924
  //ACTOR9 = 1019382
  //BINDDORUBEI001 = 6998811
  //BINDGOUSETSU001 = 6851388
  //BINDGOUSETSU002 = 6871034
  //BINDHIEN001 = 6871032
  //BINDLISE001 = 6851387
  //BINDLISE002 = 6871033
  //BINDSHIRINA001 = 6851362
  //EMOTE0 = 122
  //EOBJECT0 = 2008268
  //EVENTRANGE0 = 6894728
  //LOCACTOR1 = 6871045
  //LOCACTOR2 = 6871046
  //LOCACTOR3 = 6871047
  //LOCACTOR4 = 6871035
  //LOCACTOR6 = 6871037
  //LOCACTOR7 = 6871038
  //LOCACTOR8 = 6871039
  //LOCBASEGROUNFDAMAGE = 4206
  //LOCBATTLEEMOTEEND = 3779
  //LOCLAUGHBIG = 4312

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
        if( param1 == 1020540 ) // ACTOR0 = HIEN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=HIEN
          }
          break;
        }
        if( param1 == 1020541 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020542 ) // ACTOR2 = GOSETSU
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021634 ) // ACTOR3 = MOLA02514
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=MOLA02514
          break;
        }
        if( param1 == 1021636 ) // ACTOR4 = MOLC02514
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 ) // ACTOR5 = MOLD02514
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 ) // ACTOR6 = MOLE02514
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        if( param1 == 1021635 ) // ACTOR7 = MOLB02514
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=MOLB02514
          break;
        }
        if( param1 == 1021924 ) // ACTOR8 = DORBEI
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019382 ) // ACTOR9 = TEMULUN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove, ENpcBind), id=TEMULUN
          }
          break;
        }
        if( param1 == 1020539 ) // ACTOR10 = CIRINA
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021633 ) // ACTOR11 = HIEN
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021632 ) // ACTOR12 = LYSE
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021631 ) // ACTOR13 = GOSETSU
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1019396 ) // ACTOR14 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021634 ) // ACTOR3 = MOLA02514
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=MOLA02514
          break;
        }
        if( param1 == 1021636 ) // ACTOR4 = MOLC02514
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 ) // ACTOR5 = MOLD02514
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 ) // ACTOR6 = MOLE02514
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        if( param1 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1021635 ) // ACTOR7 = MOLB02514
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=MOLB02514
          break;
        }
        if( param1 == 1021924 ) // ACTOR8 = DORBEI
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1021634 ) // ACTOR3 = MOLA02514
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=MOLA02514
          }
          break;
        }
        if( param1 == 1021636 ) // ACTOR4 = MOLC02514
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 ) // ACTOR5 = MOLD02514
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 ) // ACTOR6 = MOLE02514
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        if( param1 == 1021641 ) // ACTOR15 = HIEN
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021640 ) // ACTOR16 = LYSE
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021639 ) // ACTOR17 = GOSETSU
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1020539 ) // ACTOR10 = CIRINA
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021635 ) // ACTOR7 = MOLB02514
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=MOLB02514
          break;
        }
        if( param1 == 1021924 ) // ACTOR8 = DORBEI
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 5010000 || param1 == 2097153 ) // ACTOR18 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00036( quest, player ); // Scene00036: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=unknown
          }
          break;
        }
        if( param1 == 1021634 ) // ACTOR3 = MOLA02514
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=MOLA02514
          break;
        }
        if( param1 == 1021636 ) // ACTOR4 = MOLC02514
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 ) // ACTOR5 = MOLD02514
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 ) // ACTOR6 = MOLE02514
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        if( param1 == 1021641 ) // ACTOR15 = HIEN
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021640 ) // ACTOR16 = LYSE
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021639 ) // ACTOR17 = GOSETSU
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1020539 ) // ACTOR10 = CIRINA
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 2008268 ) // EOBJECT0 = unknown
        {
          Scene00048( quest, player ); // Scene00048: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021635 ) // ACTOR7 = MOLB02514
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, TargetCanMove), id=MOLB02514
          break;
        }
        if( param1 == 1021924 ) // ACTOR8 = DORBEI
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020539 ) // ACTOR10 = CIRINA
        {
          Scene00051( quest, player ); // Scene00051: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00052( quest, player ); // Scene00052: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1021633 ) // ACTOR11 = HIEN
        {
          Scene00053( quest, player ); // Scene00053: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021632 ) // ACTOR12 = LYSE
        {
          Scene00054( quest, player ); // Scene00054: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021631 ) // ACTOR13 = GOSETSU
        {
          Scene00055( quest, player ); // Scene00055: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021634 ) // ACTOR3 = MOLA02514
        {
          Scene00056( quest, player ); // Scene00056: Normal(Talk, TargetCanMove), id=MOLA02514
          break;
        }
        if( param1 == 1021636 ) // ACTOR4 = MOLC02514
        {
          Scene00057( quest, player ); // Scene00057: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 ) // ACTOR5 = MOLD02514
        {
          Scene00058( quest, player ); // Scene00058: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 ) // ACTOR6 = MOLE02514
        {
          Scene00059( quest, player ); // Scene00059: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        if( param1 == 1021635 ) // ACTOR7 = MOLB02514
        {
          Scene00060( quest, player ); // Scene00060: Normal(Talk, TargetCanMove), id=MOLB02514
          break;
        }
        if( param1 == 1021924 ) // ACTOR8 = DORBEI
        {
          Scene00061( quest, player ); // Scene00061: Normal(Talk, TargetCanMove), id=DORBEI
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
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00004: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00005: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00006: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00007: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00008: Normal(Talk, TargetCanMove), id=MOLB02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00009: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00010: Normal(Talk, TargetCanMove, ENpcBind), id=TEMULUN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00011: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00012: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00014: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00016: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00017: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00018: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00019: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00020: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setBitFlag8( 1, true );
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00021: Normal(Talk, TargetCanMove), id=MOLB02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00022: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00023: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00024: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00025: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00026: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00027: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00028: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00029: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00030: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00031: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00032: Normal(Talk, TargetCanMove), id=MOLB02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00033: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR18, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00036: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00039: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, HIDE_HOTBAR, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00040: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, HIDE_HOTBAR, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00041: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, HIDE_HOTBAR, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00042: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00043: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, HIDE_HOTBAR, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00044: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00045: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00046: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, HIDE_HOTBAR, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00047: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, HIDE_HOTBAR, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00048: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00049: Normal(Talk, TargetCanMove), id=MOLB02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 49, HIDE_HOTBAR, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00050: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 50, HIDE_HOTBAR, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00051: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 51, HIDE_HOTBAR, callback );
  }

  void Scene00052( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00052: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 52, HIDE_HOTBAR, callback );
  }

  void Scene00053( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00053: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 53, HIDE_HOTBAR, callback );
  }

  void Scene00054( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00054: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 54, HIDE_HOTBAR, callback );
  }

  void Scene00055( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00055: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 55, HIDE_HOTBAR, callback );
  }

  void Scene00056( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00056: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 56, HIDE_HOTBAR, callback );
  }

  void Scene00057( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00057: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 57, HIDE_HOTBAR, callback );
  }

  void Scene00058( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00058: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 58, HIDE_HOTBAR, callback );
  }

  void Scene00059( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00059: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 59, HIDE_HOTBAR, callback );
  }

  void Scene00060( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00060: Normal(Talk, TargetCanMove), id=MOLB02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 60, HIDE_HOTBAR, callback );
  }

  void Scene00061( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda417:68052 calling Scene00061: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 61, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda417 );
