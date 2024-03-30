// FFXIVTheMovie.ParserV3.12
// param used:
//WARP_SCENE16 = 621|68.5|45.411|770|-1.86|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda702 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda702() : Sapphire::ScriptAPI::QuestScript( 68085 ){}; 
  ~StmBda702() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 9 entries
  //SEQ_2, 1 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1021704
  //ACTOR1 = 1021705
  //ACTOR10 = 1021711
  //ACTOR11 = 1022730
  //ACTOR12 = 1022731
  //ACTOR2 = 1021706
  //ACTOR3 = 1022724
  //ACTOR4 = 1022725
  //ACTOR5 = 1022726
  //ACTOR6 = 1021708
  //ACTOR7 = 1022729
  //ACTOR8 = 1021710
  //ACTOR9 = 1021709
  //BINDACTOR01 = 6870611
  //BINDACTOR02 = 6870612
  //BINDACTOR03 = 6925935
  //BINDACTOR04 = 6925958
  //BINDACTOR05 = 6870672
  //EOBJECT0 = 2008283
  //LOCACTOR01 = 1015842
  //LOCACTOR02 = 1021992
  //LOCACTOR03 = 1022483
  //LOCACTOR04 = 1011887
  //LOCACTOR05 = 1019559
  //LOCIDLE01 = 808
  //LOCSE01 = 39
  //LOCSE02 = 40
  //QUESTBATTLE0 = 158
  //TERRITORYTYPE0 = 686
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
        if( param1 == 1021704 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind, CreateCharacterTalk), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1021705 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021706 ) // ACTOR2 = ARENVALD
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022724 ) // ACTOR3 = MNAAGO
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022725 ) // ACTOR4 = VMAHTIA
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022726 ) // ACTOR5 = JMOLDVA
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1021705 ) // ACTOR1 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00007( quest, player ); // Scene00007: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel, ENpcBind), id=LYSE
          }
          break;
        }
        if( param1 == 2008283 ) // EOBJECT0 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021704 ) // ACTOR0 = ALPHINAUD
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021706 ) // ACTOR2 = ARENVALD
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022724 ) // ACTOR3 = MNAAGO
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022725 ) // ACTOR4 = VMAHTIA
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022726 ) // ACTOR5 = JMOLDVA
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1021708 ) // ACTOR6 = THANCRED
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022729 ) // ACTOR7 = WISCAR
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        break;
      }
      case 2:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, FadeIn, Dismount, CreateCharacterTalk), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021710 ) // ACTOR8 = LYSE
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021709 ) // ACTOR9 = ALPHINAUD
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021711 ) // ACTOR10 = THANCRED
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022730 ) // ACTOR11 = WISCAR
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1022731 ) // ACTOR12 = WATT
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=WATT
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
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind, CreateCharacterTalk), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00003: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00004: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00005: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00006: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00007: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel, ENpcBind), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        //quest battle
        eventMgr().eventFinish( player, result.eventId, 1 );
        teriMgr().createAndJoinQuestBattle( player, 158 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00008: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00010: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00011: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00012: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00013: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00014: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00015: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00016: Normal(Talk, FadeIn, Dismount, CreateCharacterTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 621 )->getGuId(), { 68.5, 45.411, 770 }, -1.86 );
    };
    eventMgr().playQuestScene( player, getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI | INVIS_ENPC, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00019: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00020: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda702:68085 calling Scene00021: Normal(Talk, TargetCanMove), id=WATT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda702 );
