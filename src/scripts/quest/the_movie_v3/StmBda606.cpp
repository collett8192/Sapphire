// FFXIVTheMovie.ParserV3.12
// param used:
//PRIVATE_SCENE10 = 683
//PRIVATE_SCENE13 = 683
//PRIVATE_SCENE19 = 683
//PRIVATE_SCENE24 = 683
//WARP_SCENE25 = 612|511.83|122.46|-241.57|-1.294|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda606 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda606() : Sapphire::ScriptAPI::QuestScript( 68068 ){}; 
  ~StmBda606() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 4 entries
  //SEQ_2, 2 entries
  //SEQ_3, 3 entries
  //SEQ_4, 5 entries
  //SEQ_5, 5 entries
  //SEQ_6, 1 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1020827
  //ACTOR1 = 1020586
  //ACTOR10 = 1020595
  //ACTOR11 = 5010000
  //ACTOR2 = 1020587
  //ACTOR3 = 1020588
  //ACTOR4 = 1020589
  //ACTOR5 = 1020590
  //ACTOR6 = 1020591
  //ACTOR7 = 1020592
  //ACTOR8 = 1020593
  //ACTOR9 = 1020594
  //BINDACTOR01 = 6853903
  //BINDACTOR02 = 6853905
  //BINDACTOR03 = 6853906
  //BINDACTOR04 = 6853912
  //BINDACTOR05 = 6853914
  //BINDACTOR06 = 6853915
  //CUTSCENEN01 = 1465
  //CUTSCENEN02 = 1466
  //CUTSCENEN03 = 1467
  //EOBJECT0 = 2008200
  //EVENTACTION0 = 19
  //INSTANCEDUNGEON0 = 20048
  //INSTANCEDUNGEON1 = 20046
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //POPRANGE0 = 6854482
  //POPRANGE1 = 6866095
  //SCREENIMAGE0 = 502
  //TERRITORYTYPE0 = 683
  //TERRITORYTYPE1 = 612

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
        if( param1 == 1020827 ) // ACTOR0 = VAJRA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=VAJRA
          }
          break;
        }
        if( param1 == 1020586 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020587 ) // ACTOR2 = ALISAIE
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020588 ) // ACTOR3 = LYSE
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020589 ) // ACTOR4 = VAJRA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=VAJRA
          }
          break;
        }
        if( param1 == 1020590 ) // ACTOR5 = ALPHINAUD
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020591 ) // ACTOR6 = ALISAIE
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020592 ) // ACTOR7 = LYSE
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2008200 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1020589 ) // ACTOR4 = VAJRA
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=VAJRA
          break;
        }
        break;
      }
      case 3:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00012( quest, player ); // Scene00012: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 2008200 ) // EOBJECT0 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Normal(YesNo, CanCancel), id=unknown
          break;
        }
        if( param1 == 1020589 ) // ACTOR4 = VAJRA
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=VAJRA
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020593 ) // ACTOR8 = ALISAIE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove, Menu), id=ALISAIE
          }
          break;
        }
        if( param1 == 1020594 ) // ACTOR9 = ALPHINAUD
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020595 ) // ACTOR10 = LYSE
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020589 ) // ACTOR4 = VAJRA
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=VAJRA
          break;
        }
        if( param1 == 2008200 ) // EOBJECT0 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Normal(YesNo, CanCancel), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1020593 ) // ACTOR8 = ALISAIE
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020594 ) // ACTOR9 = ALPHINAUD
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020595 ) // ACTOR10 = LYSE
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020589 ) // ACTOR4 = VAJRA
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=VAJRA
          break;
        }
        if( param1 == 2008200 ) // EOBJECT0 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Normal(YesNo, CanCancel), id=unknown
          break;
        }
        break;
      }
      case 6:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00025( quest, player ); // Scene00025: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020592 ) // ACTOR7 = LYSE
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020590 ) // ACTOR5 = ALPHINAUD
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020591 ) // ACTOR6 = ALISAIE
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020589 ) // ACTOR4 = VAJRA
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=VAJRA
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
    quest.setSeq( 4 );
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
    quest.setSeq( 6 );
  }
  void checkProgressSeq6( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=VAJRA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=VAJRA" );
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
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00008: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00010: Empty(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.enterPredefinedPrivateInstance( 683 );
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00011: Normal(Talk, TargetCanMove), id=VAJRA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00012: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00013: Normal(YesNo, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        checkProgressSeq3( quest, player );
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 683 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00014: Normal(Talk, TargetCanMove), id=VAJRA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00015: Normal(Talk, TargetCanMove, Menu), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 1, true );
        eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
        checkProgressSeq4( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00017: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00018: Normal(Talk, TargetCanMove), id=VAJRA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00019: Normal(YesNo, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        checkProgressSeq4( quest, player );
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 683 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00022: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00023: Normal(Talk, TargetCanMove), id=VAJRA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00024: Normal(YesNo, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        checkProgressSeq5( quest, player );
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 683 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_6: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:5)
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00025: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 5, 0, 0, 0 );
      checkProgressSeq6( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 612 )->getGuId(), { 511.83, 122.46, -241.57 }, -1.294 );
    };
    eventMgr().playQuestScene( player, getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda606:68068 calling Scene00029: Normal(Talk, TargetCanMove), id=VAJRA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda606 );
