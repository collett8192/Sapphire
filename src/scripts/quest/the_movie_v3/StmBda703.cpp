// FFXIVTheMovie.ParserV3.12
// param used:
//WARP_SCENE16 = 621|757.462|70|443.541|0.57|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda703 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda703() : Sapphire::ScriptAPI::QuestScript( 68086 ){}; 
  ~StmBda703() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 3 entries
  //SEQ_2, 2 entries
  //SEQ_3, 2 entries
  //SEQ_4, 3 entries
  //SEQ_5, 1 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1021710
  //ACTOR1 = 1021709
  //ACTOR10 = 1021717
  //ACTOR11 = 1021718
  //ACTOR12 = 1022732
  //ACTOR13 = 1022736
  //ACTOR14 = 1022737
  //ACTOR2 = 1021711
  //ACTOR3 = 1022730
  //ACTOR4 = 1022731
  //ACTOR5 = 1021712
  //ACTOR6 = 1021713
  //ACTOR7 = 1021714
  //ACTOR8 = 1021715
  //ACTOR9 = 1021716
  //BINDACTOR01 = 6870676
  //BINDACTOR02 = 6870679
  //BINDACTOR03 = 6925976
  //BINDACTOR04 = 6925977
  //BINDACTOR05 = 6870683
  //BINDACTOR06 = 6870686
  //CUTSCENEN01 = 1480
  //EOBJECT0 = 2008284
  //LOCACTION01 = 1064
  //LOCACTOR01 = 1008180
  //LOCACTOR02 = 1022006
  //QUESTBATTLE0 = 5017
  //TERRITORYTYPE0 = 684
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
        if( param1 == 1021710 ) // ACTOR0 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=LYSE
          }
          break;
        }
        if( param1 == 1021709 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021711 ) // ACTOR2 = THANCRED
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022730 ) // ACTOR3 = WISCAR
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1022731 ) // ACTOR4 = WATT
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=WATT
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1021712 ) // ACTOR5 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove, ENpcBind, CreateCharacterTalk), id=LYSE
          }
          break;
        }
        if( param1 == 1021713 ) // ACTOR6 = THANCRED
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022731 ) // ACTOR4 = WATT
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=WATT
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1021714 ) // ACTOR7 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1021715 ) // ACTOR8 = THANCRED
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1021716 ) // ACTOR9 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove, ENpcBind), id=LYSE
          }
          break;
        }
        if( param1 == 1021715 ) // ACTOR8 = THANCRED
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1021716 ) // ACTOR9 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel, ReturnTrue), id=LYSE
          }
          break;
        }
        if( param1 == 1021715 ) // ACTOR8 = THANCRED
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 2008284 ) // EOBJECT0 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00016( quest, player ); // Scene00016: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021717 ) // ACTOR10 = ALPHINAUD
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021718 ) // ACTOR11 = KRILE
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1022732 ) // ACTOR12 = THANCRED
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022736 ) // ACTOR13 = MNAAGO
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022737 ) // ACTOR14 = WISCAR
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=WISCAR
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
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00003: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00004: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00005: Normal(Talk, TargetCanMove), id=WATT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove, ENpcBind, CreateCharacterTalk), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00007: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00008: Normal(Talk, TargetCanMove), id=WATT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00010: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00011: Normal(Talk, TargetCanMove, ENpcBind), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00012: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00013: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel, ReturnTrue), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        //quest battle
        eventMgr().eventFinish( player, result.eventId, 1 );
        teriMgr().createAndJoinQuestBattle( player, 5017 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00014: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00015: Empty(None), id=unknown" );
    checkProgressSeq4( quest, player );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_5: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00016: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 621 )->getGuId(), { 757.462, 70, 443.541 }, 0.57 );
    };
    eventMgr().playQuestScene( player, getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00018: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00019: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00020: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda703:68086 calling Scene00021: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda703 );
