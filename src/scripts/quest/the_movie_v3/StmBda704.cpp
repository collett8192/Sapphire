// FFXIVTheMovie.ParserV3.12
// param used:
//_ACTOR15 = B
//_ACTOR15B = 4|2
//_ACTOR19 = B
//_ACTOR19B = 4|2
//_ACTOR20 = B
//_ACTOR20B = 4|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda704 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda704() : Sapphire::ScriptAPI::QuestScript( 68087 ){}; 
  ~StmBda704() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 8 entries
  //SEQ_2, 8 entries
  //SEQ_3, 5 entries
  //SEQ_4, 11 entries
  //SEQ_255, 11 entries

  //ACTOR0 = 1021717
  //ACTOR1 = 1021718
  //ACTOR10 = 1021698
  //ACTOR11 = 1021699
  //ACTOR12 = 1021700
  //ACTOR13 = 1021719
  //ACTOR14 = 1021720
  //ACTOR15 = 1021701
  //ACTOR16 = 1022721
  //ACTOR17 = 1022722
  //ACTOR18 = 1022723
  //ACTOR19 = 1021702
  //ACTOR2 = 1022732
  //ACTOR20 = 1021703
  //ACTOR3 = 1022736
  //ACTOR4 = 1022737
  //ACTOR5 = 1022733
  //ACTOR6 = 1022734
  //ACTOR7 = 1022735
  //ACTOR8 = 1020606
  //ACTOR9 = 1020607
  //BINDACTOR01 = 6925979
  //BINDACTOR02 = 6870689
  //BINDACTOR03 = 6925981
  //BINDACTOR04 = 6925982
  //BINDACTOR05 = 6926030
  //BINDACTOR06 = 6926031
  //BINDACTOR07 = 6870599
  //BINDACTOR08 = 6870600
  //BINDACTOR09 = 6870601
  //CUTSCENEN01 = 1481
  //LOCACTOR01 = 1015915
  //LOCACTOR02 = 1015916
  //LOCBGM01 = 458

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
        if( param1 == 1021717 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1021718 ) // ACTOR1 = KRILE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1022732 ) // ACTOR2 = THANCRED
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022736 ) // ACTOR3 = MNAAGO
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022737 ) // ACTOR4 = WISCAR
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1022733 ) // ACTOR5 = ARENVALD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove, ENpcBind), id=ARENVALD
          }
          break;
        }
        if( param1 == 1022734 ) // ACTOR6 = VMAHTIA
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022735 ) // ACTOR7 = JMOLDVA
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1020606 ) // ACTOR8 = ALPHINAUD
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020607 ) // ACTOR9 = KRILE
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1022732 ) // ACTOR2 = THANCRED
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022736 ) // ACTOR3 = MNAAGO
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022737 ) // ACTOR4 = WISCAR
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1021698 ) // ACTOR10 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00014( quest, player ); // Scene00014: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1021699 ) // ACTOR11 = SERPENTOFFICER
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1021700 ) // ACTOR12 = STORMOFFICER
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1022736 ) // ACTOR3 = MNAAGO
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022737 ) // ACTOR4 = WISCAR
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1022733 ) // ACTOR5 = ARENVALD
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022734 ) // ACTOR6 = VMAHTIA
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022735 ) // ACTOR7 = JMOLDVA
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1021719 ) // ACTOR13 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1021720 ) // ACTOR14 = URIANGER
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1021698 ) // ACTOR10 = RAUBAHN
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1021699 ) // ACTOR11 = SERPENTOFFICER
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1021700 ) // ACTOR12 = STORMOFFICER
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1021701 ) // ACTOR15 = KANESENNA, CB=2
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=KANESENNA
          }
          else
          {
            Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=KANESENNA
          }
          break;
        }
        if( param1 == 1022721 ) // ACTOR16 = BODYGUARD01623
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=BODYGUARD01623
          break;
        }
        if( param1 == 1022722 ) // ACTOR17 = EYNZAHRSLAFYRSYN
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN
          break;
        }
        if( param1 == 1022723 ) // ACTOR18 = LUCIA
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1021698 ) // ACTOR10 = RAUBAHN
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1021699 ) // ACTOR11 = SERPENTOFFICER
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1021700 ) // ACTOR12 = STORMOFFICER
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1021719 ) // ACTOR13 = ALPHINAUD
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021720 ) // ACTOR14 = URIANGER
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1021702 ) // ACTOR19 = MERLWYB, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=MERLWYB
          }
          else
          {
            Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=MERLWYB
          }
          break;
        }
        if( param1 == 1021703 ) // ACTOR20 = AYMERIC, CB=2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=AYMERIC
          }
          else
          {
            Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=AYMERIC
          }
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021698 ) // ACTOR10 = RAUBAHN
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=RAUBAHN
          break;
        }
        if( param1 == 1021699 ) // ACTOR11 = SERPENTOFFICER
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1021700 ) // ACTOR12 = STORMOFFICER
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1021701 ) // ACTOR15 = KANESENNA
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=KANESENNA
          break;
        }
        if( param1 == 1021702 ) // ACTOR19 = MERLWYB
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=MERLWYB
          break;
        }
        if( param1 == 1021703 ) // ACTOR20 = AYMERIC
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1022721 ) // ACTOR16 = BODYGUARD01623
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=BODYGUARD01623
          break;
        }
        if( param1 == 1022722 ) // ACTOR17 = EYNZAHRSLAFYRSYN
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN
          break;
        }
        if( param1 == 1022723 ) // ACTOR18 = LUCIA
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1021719 ) // ACTOR13 = ALPHINAUD
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021720 ) // ACTOR14 = URIANGER
        {
          Scene00051( quest, player ); // Scene00051: Normal(Talk, TargetCanMove), id=URIANGER
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
          quest.setSeq( 255 );
        }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00002: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00003: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00004: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00005: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00006: Normal(Talk, TargetCanMove, ENpcBind), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00007: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00008: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00010: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00011: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00012: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00013: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00014: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00015: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00016: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00017: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00018: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00019: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00020: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00021: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR13, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00022: Normal(Talk, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00023: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00024: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00025: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00026: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR15, UI8BL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00027: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }
  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR15, UI8BL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00028: Normal(Talk, TargetCanMove), id=KANESENNA" );
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, nullptr );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00029: Normal(Talk, TargetCanMove), id=BODYGUARD01623" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00030: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00031: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00032: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00033: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00034: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, HIDE_HOTBAR, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00036: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR19, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00037: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }
  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR19, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00038: Normal(Talk, TargetCanMove), id=MERLWYB" );
    eventMgr().playQuestScene( player, getId(), 38, HIDE_HOTBAR, nullptr );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR20, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00039: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 39, HIDE_HOTBAR, callback );
  }
  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR20, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00040: Normal(Talk, TargetCanMove), id=AYMERIC" );
    eventMgr().playQuestScene( player, getId(), 40, HIDE_HOTBAR, nullptr );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00041: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 41, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00042: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00043: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, HIDE_HOTBAR, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00044: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00045: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00046: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, HIDE_HOTBAR, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00047: Normal(Talk, TargetCanMove), id=BODYGUARD01623" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, HIDE_HOTBAR, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00048: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, HIDE_HOTBAR, callback );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00049: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 49, HIDE_HOTBAR, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00050: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 50, HIDE_HOTBAR, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda704:68087 calling Scene00051: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 51, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda704 );
