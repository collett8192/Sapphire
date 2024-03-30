// FFXIVTheMovie.ParserV3.12
// param used:
//PRIVATE_SCENE11 = 727
//PRIVATE_SCENE13 = 727
//SCENE_14 REMOVED!!
//_ACTOR8 = B
//_ACTOR8B = 6|2
//_ACTOR10 = B
//_ACTOR10B = 6|2
//_ACTOR19 = B
//_ACTOR19B = 6|2
//_ACTOR15 = B
//_ACTOR15B = 6|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda706 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda706() : Sapphire::ScriptAPI::QuestScript( 68089 ){}; 
  ~StmBda706() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 5 entries
  //SEQ_2, 2 entries
  //SEQ_3, 1 entries
  //SEQ_4, 1 entries
  //SEQ_5, 12 entries
  //SEQ_6, 13 entries
  //SEQ_7, 12 entries
  //SEQ_255, 12 entries

  //ACTOR0 = 1021724
  //ACTOR1 = 1021723
  //ACTOR10 = 1022724
  //ACTOR11 = 1022729
  //ACTOR12 = 1021706
  //ACTOR13 = 1022725
  //ACTOR14 = 1022726
  //ACTOR15 = 1021726
  //ACTOR16 = 1021727
  //ACTOR17 = 1022727
  //ACTOR18 = 1021720
  //ACTOR19 = 1021698
  //ACTOR2 = 1021725
  //ACTOR20 = 1021728
  //ACTOR3 = 1020598
  //ACTOR4 = 1023838
  //ACTOR5 = 5010000
  //ACTOR6 = 1023616
  //ACTOR7 = 1020356
  //ACTOR8 = 1021704
  //ACTOR9 = 1021708
  //BINDACTOR01 = 7031300
  //BINDACTOR02 = 6870672
  //BINDACTOR03 = 6870738
  //BINDACTOR04 = 6925951
  //CUTSCENEN01 = 1483
  //CUTSCENEN02 = 1484
  //CUTSCENEN03 = 1485
  //CUTSCENEN04 = 1486
  //CUTSCENEN06 = 1488
  //CUTSCENEN07 = 1489
  //CUTSCENEN08 = 1490
  //CUTSCENEN09 = 1491
  //CUTSCENEN10 = 1492
  //INSTANCEDUNGEON0 = 56
  //INSTANCEDUNGEON1 = 55
  //INSTANCEDUNGEON2 = 20045
  //POPRANGE0 = 6954778
  //POPRANGE1 = 6998999
  //POPRANGE2 = 6870797
  //POPRANGE3 = 6998989
  //POPRANGE4 = 6870807
  //SCREENIMAGE0 = 496
  //SCREENIMAGE1 = 499
  //TERRITORYTYPE0 = 727
  //TERRITORYTYPE1 = 621

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
        if( param1 == 1021724 ) // ACTOR0 = PIPIN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PIPIN
          }
          break;
        }
        if( param1 == 1021723 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021725 ) // ACTOR2 = AYMERIC
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1020598 ) // ACTOR3 = LUCIA
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1023838 ) // ACTOR4 = RAUBAHN
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1021724 ) // ACTOR0 = PIPIN
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1021723 ) // ACTOR1 = ALPHINAUD
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021725 ) // ACTOR2 = AYMERIC
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1020598 ) // ACTOR3 = LUCIA
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1023838 ) // ACTOR4 = RAUBAHN
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        break;
      }
      case 2:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00011( quest, player ); // Scene00011: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1023616 ) // ACTOR6 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Normal(FadeIn), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1023616 ) // ACTOR6 = FLAMERECRUIT
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=FLAMERECRUIT
          break;
        }
        break;
      }
      case 4:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00015( quest, player ); // Scene00015: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1020356 ) // ACTOR7 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1021704 ) // ACTOR8 = ALPHINAUD
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021708 ) // ACTOR9 = THANCRED
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022724 ) // ACTOR10 = MNAAGO
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022729 ) // ACTOR11 = WISCAR
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1021706 ) // ACTOR12 = ARENVALD
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022725 ) // ACTOR13 = VMAHTIA
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022726 ) // ACTOR14 = JMOLDVA
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1021726 ) // ACTOR15 = YUGIRI
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1021727 ) // ACTOR16 = HIEN
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1022727 ) // ACTOR17 = HAKURO
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1021720 ) // ACTOR18 = URIANGER
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1021704 ) // ACTOR8 = ALPHINAUD, CB=2
        {
          if( quest.getUI8CH() != 1 )
          {
            Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          else
          {
            Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020356 ) // ACTOR7 = LYSE
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021708 ) // ACTOR9 = THANCRED
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022729 ) // ACTOR11 = WISCAR
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1021706 ) // ACTOR12 = ARENVALD
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022725 ) // ACTOR13 = VMAHTIA
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022726 ) // ACTOR14 = JMOLDVA
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1021727 ) // ACTOR16 = HIEN
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1022727 ) // ACTOR17 = HAKURO
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1021720 ) // ACTOR18 = URIANGER
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1022724 ) // ACTOR10 = MNAAGO, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=MNAAGO
          }
          else
          {
            Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=MNAAGO
          }
          break;
        }
        if( param1 == 1021698 ) // ACTOR19 = RAUBAHN, CB=2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove, ENpcBind), id=RAUBAHN
          }
          else
          {
            Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1021726 ) // ACTOR15 = YUGIRI, CB=2
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove, ENpcBind), id=YUGIRI
          }
          else
          {
            Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=YUGIRI
          }
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 1020356 ) // ACTOR7 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00045( quest, player ); // Scene00045: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1021704 ) // ACTOR8 = ALPHINAUD
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021708 ) // ACTOR9 = THANCRED
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022724 ) // ACTOR10 = MNAAGO
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022729 ) // ACTOR11 = WISCAR
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1021706 ) // ACTOR12 = ARENVALD
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022725 ) // ACTOR13 = VMAHTIA
        {
          Scene00051( quest, player ); // Scene00051: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022726 ) // ACTOR14 = JMOLDVA
        {
          Scene00052( quest, player ); // Scene00052: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1021726 ) // ACTOR15 = YUGIRI
        {
          Scene00053( quest, player ); // Scene00053: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1021727 ) // ACTOR16 = HIEN
        {
          Scene00054( quest, player ); // Scene00054: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1022727 ) // ACTOR17 = HAKURO
        {
          Scene00055( quest, player ); // Scene00055: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1021720 ) // ACTOR18 = URIANGER
        {
          Scene00056( quest, player ); // Scene00056: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021728 ) // ACTOR20 = LYSE
        {
          Scene00057( quest, player ); // Scene00057: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn), id=LYSE
          // +Callback Scene00058: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1021704 ) // ACTOR8 = ALPHINAUD
        {
          Scene00059( quest, player ); // Scene00059: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021708 ) // ACTOR9 = THANCRED
        {
          Scene00060( quest, player ); // Scene00060: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022724 ) // ACTOR10 = MNAAGO
        {
          Scene00061( quest, player ); // Scene00061: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022729 ) // ACTOR11 = WISCAR
        {
          Scene00062( quest, player ); // Scene00062: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1021706 ) // ACTOR12 = ARENVALD
        {
          Scene00063( quest, player ); // Scene00063: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022725 ) // ACTOR13 = VMAHTIA
        {
          Scene00064( quest, player ); // Scene00064: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022726 ) // ACTOR14 = JMOLDVA
        {
          Scene00065( quest, player ); // Scene00065: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1021726 ) // ACTOR15 = YUGIRI
        {
          Scene00066( quest, player ); // Scene00066: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1021727 ) // ACTOR16 = HIEN
        {
          Scene00067( quest, player ); // Scene00067: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1022727 ) // ACTOR17 = HAKURO
        {
          Scene00068( quest, player ); // Scene00068: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1021720 ) // ACTOR18 = URIANGER
        {
          Scene00069( quest, player ); // Scene00069: Normal(Talk, TargetCanMove), id=URIANGER
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
    quest.setSeq( 2 );
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 3 );
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 4 );
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
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
    if( quest.getUI8CH() == 1 )
      if( quest.getUI8AL() == 1 )
        if( quest.getUI8BH() == 1 )
          if( quest.getUI8BL() == 1 )
          {
            quest.setUI8CH( 0 );
            quest.setUI8AL( 0 );
            quest.setUI8BH( 0 );
            quest.setUI8BL( 0 );
            quest.setBitFlag8( 1, false );
            quest.setBitFlag8( 2, false );
            quest.setBitFlag8( 3, false );
            quest.setBitFlag8( 4, false );
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
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00003: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00004: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00005: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00006: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00008: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00009: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00010: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00011: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.enterPredefinedPrivateInstance( 727 );
    };
    eventMgr().playQuestScene( player, getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00012: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00013: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=FLAMERECRUIT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 727 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_4: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00015: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00016: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00018: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00019: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00020: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00021: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00022: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00023: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00024: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00025: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00026: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00027: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR8, UI8CH = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00028: Normal(Talk, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8CH( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }
  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR8, UI8CH = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, nullptr );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00030: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00031: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00032: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00033: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00034: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00035: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, HIDE_HOTBAR, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00036: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00037: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00038: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, HIDE_HOTBAR, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR10, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00039: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 39, HIDE_HOTBAR, callback );
  }
  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR10, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00040: Normal(Talk, TargetCanMove), id=MNAAGO" );
    eventMgr().playQuestScene( player, getId(), 40, HIDE_HOTBAR, nullptr );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR19, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00041: Normal(Talk, TargetCanMove, ENpcBind), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 41, HIDE_HOTBAR, callback );
  }
  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR19, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00042: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, nullptr );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR15, UI8BL = 1, Flag8(4)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00043: Normal(Talk, TargetCanMove, ENpcBind), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 4, true );
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 43, HIDE_HOTBAR, callback );
  }
  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR15, UI8BL = 1, Flag8(4)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00044: Normal(Talk, TargetCanMove), id=YUGIRI" );
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, nullptr );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00045: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq7( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, HIDE_HOTBAR, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00047: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, HIDE_HOTBAR, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00048: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, HIDE_HOTBAR, callback );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00049: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 49, HIDE_HOTBAR, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00050: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 50, HIDE_HOTBAR, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00051: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 51, HIDE_HOTBAR, callback );
  }

  void Scene00052( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00052: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 52, HIDE_HOTBAR, callback );
  }

  void Scene00053( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00053: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 53, HIDE_HOTBAR, callback );
  }

  void Scene00054( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00054: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 54, HIDE_HOTBAR, callback );
  }

  void Scene00055( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00055: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 55, HIDE_HOTBAR, callback );
  }

  void Scene00056( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00056: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 56, HIDE_HOTBAR, callback );
  }

  void Scene00057( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00057: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00058( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 57, HIDE_HOTBAR, callback );
  }
  void Scene00058( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00058: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      player.finishQuest( getId(), result.getResult( 1 ) );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 58, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00059( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00059: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 59, HIDE_HOTBAR, callback );
  }

  void Scene00060( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00060: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 60, HIDE_HOTBAR, callback );
  }

  void Scene00061( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00061: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 61, HIDE_HOTBAR, callback );
  }

  void Scene00062( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00062: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 62, HIDE_HOTBAR, callback );
  }

  void Scene00063( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00063: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 63, HIDE_HOTBAR, callback );
  }

  void Scene00064( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00064: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 64, HIDE_HOTBAR, callback );
  }

  void Scene00065( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00065: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 65, HIDE_HOTBAR, callback );
  }

  void Scene00066( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00066: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 66, HIDE_HOTBAR, callback );
  }

  void Scene00067( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00067: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 67, HIDE_HOTBAR, callback );
  }

  void Scene00068( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00068: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 68, HIDE_HOTBAR, callback );
  }

  void Scene00069( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda706:68089 calling Scene00069: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 69, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda706 );
