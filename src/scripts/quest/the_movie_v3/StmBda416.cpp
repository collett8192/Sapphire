// FFXIVTheMovie.ParserV3.11
// param used:
//_ACTOR4 = B
//_ACTOR4B = 1|2
//_ACTOR8 = B
//_ACTOR8B = 1|2
//_ACTOR10 = B
//_ACTOR10B = 1|2
//_ACTOR11 = B
//_ACTOR11B = 1|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda416 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda416() : Sapphire::ScriptAPI::QuestScript( 68051 ){}; 
  ~StmBda416() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 12 entries
  //SEQ_2, 13 entries
  //SEQ_3, 13 entries
  //SEQ_4, 1 entries
  //SEQ_255, 16 entries

  //ACTOR0 = 1020539
  //ACTOR1 = 1021633
  //ACTOR10 = 1019388
  //ACTOR11 = 1019396
  //ACTOR12 = 1020540
  //ACTOR13 = 1020541
  //ACTOR14 = 1020542
  //ACTOR15 = 1019417
  //ACTOR16 = 1020280
  //ACTOR17 = 1021635
  //ACTOR18 = 1021924
  //ACTOR2 = 1021631
  //ACTOR3 = 1021632
  //ACTOR4 = 1021634
  //ACTOR5 = 1021636
  //ACTOR6 = 1021637
  //ACTOR7 = 1021638
  //ACTOR8 = 1019386
  //ACTOR9 = 1019382
  //BINDCHIRINA001 = 6851362
  //BINDGOSETSU001 = 6871034
  //BINDHIEN001 = 6871032
  //BINDLYSE001 = 6871033
  //BINDTEMURUN001 = 6719188
  //EOBJECT0 = 2008267
  //JPBOW2 = 5481
  //LOCBGMAISHU = 458
  //LOCBINDNEKKETSU = 6871037
  //LOCBINDONKO = 6871039
  //LOCBINDRESEI = 6871038
  //NCUTEVENT04100 = 1445
  //NCUTEVENT04120 = 1447
  //POPRANGE0 = 6789080
  //QUESTBATTLE0 = 5008
  //TERRITORYTYPE0 = 688
  //TERRITORYTYPE1 = 622

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
        if( param1 == 1020539 ) // ACTOR0 = CIRINA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=CIRINA
          }
          break;
        }
        if( param1 == 1021633 ) // ACTOR1 = HIEN
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021631 ) // ACTOR2 = GOSETSU
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021632 ) // ACTOR3 = LYSE
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021634 ) // ACTOR4 = MOLA02514
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=MOLA02514
          break;
        }
        if( param1 == 1021636 ) // ACTOR5 = MOLC02514
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 ) // ACTOR6 = MOLD02514
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 ) // ACTOR7 = MOLE02514
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019386 ) // ACTOR8 = BUJEG, CB=2
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=BUJEG
          }
          else
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=BUJEG
          }
          break;
        }
        if( param1 == 1021633 ) // ACTOR1 = HIEN
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021631 ) // ACTOR2 = GOSETSU
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021632 ) // ACTOR3 = LYSE
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020539 ) // ACTOR0 = CIRINA
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021636 ) // ACTOR5 = MOLC02514
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 ) // ACTOR6 = MOLD02514
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 ) // ACTOR7 = MOLE02514
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        if( param1 == 1021634 ) // ACTOR4 = MOLA02514, CB=2
        {
          if( quest.getUI8CH() != 1 )
          {
            Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove, Menu, CanCancel, ENpcBind), id=MOLA02514
          }
          else
          {
            Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=MOLA02514
          }
          break;
        }
        if( param1 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1019388 ) // ACTOR10 = COTAN, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove, Menu), id=COTAN
          }
          else
          {
            Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=COTAN
          }
          break;
        }
        if( param1 == 1019396 ) // ACTOR11 = DORBEI, CB=2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=DORBEI
          }
          else
          {
            Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=DORBEI
          }
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1019382 ) // ACTOR9 = TEMULUN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00025( quest, player ); // Scene00025: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=TEMULUN
          }
          break;
        }
        if( param1 == 1020539 ) // ACTOR0 = CIRINA
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021631 ) // ACTOR2 = GOSETSU
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021632 ) // ACTOR3 = LYSE
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020539 ) // ACTOR0 = CIRINA
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021633 ) // ACTOR1 = HIEN
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1019386 ) // ACTOR8 = BUJEG
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=BUJEG
          break;
        }
        if( param1 == 1019396 ) // ACTOR11 = DORBEI
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        if( param1 == 1019388 ) // ACTOR10 = COTAN
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=COTAN
          break;
        }
        if( param1 == 1021634 ) // ACTOR4 = MOLA02514
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=MOLA02514
          break;
        }
        if( param1 == 1021636 ) // ACTOR5 = MOLC02514
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 ) // ACTOR6 = MOLD02514
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 ) // ACTOR7 = MOLE02514
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020539 ) // ACTOR0 = CIRINA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00038( quest, player ); // Scene00038: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=CIRINA
            // +Callback Scene00039: Normal(CutScene, AutoFadeIn, ReturnTrue), id=unknown
          }
          break;
        }
        if( param1 == 1021633 ) // ACTOR1 = HIEN
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021631 ) // ACTOR2 = GOSETSU
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021632 ) // ACTOR3 = LYSE
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 2008267 ) // EOBJECT0 = unknown
        {
          Scene00043( quest, player ); // Scene00043: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019388 ) // ACTOR10 = COTAN
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=COTAN
          break;
        }
        if( param1 == 1019396 ) // ACTOR11 = DORBEI
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        if( param1 == 1019386 ) // ACTOR8 = BUJEG
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=BUJEG
          break;
        }
        if( param1 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1021634 ) // ACTOR4 = MOLA02514
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=MOLA02514
          break;
        }
        if( param1 == 1021636 ) // ACTOR5 = MOLC02514
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 ) // ACTOR6 = MOLD02514
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 ) // ACTOR7 = MOLE02514
        {
          Scene00051( quest, player ); // Scene00051: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        break;
      }
      case 4:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00052( quest, player ); // Scene00052: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020540 ) // ACTOR12 = HIEN
        {
          Scene00053( quest, player ); // Scene00053: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020541 ) // ACTOR13 = LYSE
        {
          Scene00054( quest, player ); // Scene00054: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020542 ) // ACTOR14 = GOSETSU
        {
          Scene00055( quest, player ); // Scene00055: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00056( quest, player ); // Scene00056: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1020539 ) // ACTOR0 = CIRINA
        {
          Scene00057( quest, player ); // Scene00057: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021634 ) // ACTOR4 = MOLA02514
        {
          Scene00058( quest, player ); // Scene00058: Normal(Talk, TargetCanMove), id=MOLA02514
          break;
        }
        if( param1 == 1021636 ) // ACTOR5 = MOLC02514
        {
          Scene00059( quest, player ); // Scene00059: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 ) // ACTOR6 = MOLD02514
        {
          Scene00060( quest, player ); // Scene00060: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 ) // ACTOR7 = MOLE02514
        {
          Scene00061( quest, player ); // Scene00061: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        if( param1 == 1019388 ) // ACTOR10 = COTAN
        {
          Scene00062( quest, player ); // Scene00062: Normal(Talk, TargetCanMove), id=COTAN
          break;
        }
        if( param1 == 1019396 ) // ACTOR11 = DORBEI
        {
          Scene00063( quest, player ); // Scene00063: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        if( param1 == 1019386 ) // ACTOR8 = BUJEG
        {
          Scene00064( quest, player ); // Scene00064: Normal(Talk, TargetCanMove), id=BUJEG
          break;
        }
        if( param1 == 1019417 ) // ACTOR15 = unknown
        {
          Scene00065( quest, player ); // Scene00065: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1020280 ) // ACTOR16 = SADU
        {
          Scene00066( quest, player ); // Scene00066: Normal(Talk, TargetCanMove), id=SADU
          break;
        }
        if( param1 == 1021635 ) // ACTOR17 = MOLB02514
        {
          Scene00067( quest, player ); // Scene00067: Normal(Talk, TargetCanMove), id=MOLB02514
          break;
        }
        if( param1 == 1021924 ) // ACTOR18 = DORBEI
        {
          Scene00068( quest, player ); // Scene00068: Normal(Talk, TargetCanMove), id=DORBEI
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
    if( quest.getUI8BL() == 1 )
      if( quest.getUI8CH() == 1 )
        if( quest.getUI8AL() == 1 )
          if( quest.getUI8BH() == 1 )
          {
            quest.setUI8BL( 0 );
            quest.setUI8CH( 0 );
            quest.setUI8AL( 0 );
            quest.setUI8BH( 0 );
            quest.setBitFlag8( 1, false );
            quest.setBitFlag8( 2, false );
            quest.setBitFlag8( 3, false );
            quest.setBitFlag8( 4, false );
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
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00002: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00005: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00006: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00007: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00008: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, UI8BL = 1, Flag8(1)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00009: Normal(Talk, TargetCanMove), id=BUJEG" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }
  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, UI8BL = 1, Flag8(1)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00010: Normal(Talk, TargetCanMove), id=BUJEG" );
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, nullptr );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00011: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00012: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00014: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00015: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00016: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00017: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8CH = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00018: Normal(Talk, TargetCanMove, Menu, CanCancel, ENpcBind), id=MOLA02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        quest.setUI8CH( 1 );
        quest.setBitFlag8( 2, true );
        checkProgressSeq1( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }
  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8CH = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00019: Normal(Talk, TargetCanMove), id=MOLA02514" );
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, nullptr );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00020: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, UI8AL = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00021: Normal(Talk, TargetCanMove, Menu), id=COTAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 3, true );
        checkProgressSeq1( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }
  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, UI8AL = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00022: Normal(Talk, TargetCanMove), id=COTAN" );
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, nullptr );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR11, UI8BH = 1, Flag8(4)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00023: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 4, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }
  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR11, UI8BH = 1, Flag8(4)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00024: Normal(Talk, TargetCanMove), id=DORBEI" );
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, nullptr );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00025: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=TEMULUN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00026: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00027: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00028: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00029: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00030: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00031: Normal(Talk, TargetCanMove), id=BUJEG" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00032: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00033: Normal(Talk, TargetCanMove), id=COTAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00034: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00035: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, HIDE_HOTBAR, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00036: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00037: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR0, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00038: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00039( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 38, HIDE_HOTBAR, callback );
  }
  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR0, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00039: Normal(CutScene, AutoFadeIn, ReturnTrue), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      //quest battle
      eventMgr().eventFinish( player, result.eventId, 1 );
      teriMgr().createAndJoinQuestBattle( player, 5008 );
    };
    eventMgr().playQuestScene( player, getId(), 39, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00040: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, HIDE_HOTBAR, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00041: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, HIDE_HOTBAR, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00042: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00043: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00044: Normal(Talk, TargetCanMove), id=COTAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00045: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00046: Normal(Talk, TargetCanMove), id=BUJEG" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, HIDE_HOTBAR, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00047: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, HIDE_HOTBAR, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00048: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, HIDE_HOTBAR, callback );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00049: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 49, HIDE_HOTBAR, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00050: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 50, HIDE_HOTBAR, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00051: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 51, HIDE_HOTBAR, callback );
  }

  void Scene00052( World::Quest& quest, Entity::Player& player ) //SEQ_4: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00052: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 52, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00053( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00053: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 53, HIDE_HOTBAR, callback );
  }

  void Scene00054( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00054: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 54, HIDE_HOTBAR, callback );
  }

  void Scene00055( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00055: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 55, HIDE_HOTBAR, callback );
  }

  void Scene00056( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00056: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 56, HIDE_HOTBAR, callback );
  }

  void Scene00057( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00057: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 57, HIDE_HOTBAR, callback );
  }

  void Scene00058( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00058: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 58, HIDE_HOTBAR, callback );
  }

  void Scene00059( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00059: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 59, HIDE_HOTBAR, callback );
  }

  void Scene00060( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00060: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 60, HIDE_HOTBAR, callback );
  }

  void Scene00061( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00061: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 61, HIDE_HOTBAR, callback );
  }

  void Scene00062( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00062: Normal(Talk, TargetCanMove), id=COTAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 62, HIDE_HOTBAR, callback );
  }

  void Scene00063( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00063: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 63, HIDE_HOTBAR, callback );
  }

  void Scene00064( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00064: Normal(Talk, TargetCanMove), id=BUJEG" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 64, HIDE_HOTBAR, callback );
  }

  void Scene00065( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00065: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 65, HIDE_HOTBAR, callback );
  }

  void Scene00066( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00066: Normal(Talk, TargetCanMove), id=SADU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 66, HIDE_HOTBAR, callback );
  }

  void Scene00067( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00067: Normal(Talk, TargetCanMove), id=MOLB02514" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 67, HIDE_HOTBAR, callback );
  }

  void Scene00068( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda416:68051 calling Scene00068: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 68, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda416 );
