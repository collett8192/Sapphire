// FFXIVTheMovie.ParserV3.11
// param used:
//WARP_SCENE6 = 622|77.57|4|38.21|1.75|false
//WARP_SCENE23 = 622|77.57|4|38.21|1.75|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda410 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda410() : Sapphire::ScriptAPI::QuestScript( 68045 ){}; 
  ~StmBda410() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 9 entries
  //SEQ_4, 1 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1022078
  //ACTOR1 = 1021732
  //ACTOR2 = 1021731
  //ACTOR3 = 1021730
  //ACTOR4 = 1020687
  //ACTOR5 = 1023089
  //ACTOR6 = 1019417
  //EOBJECT0 = 2008250
  //EOBJECT1 = 2008251
  //EOBJECT2 = 2008252
  //EOBJECT3 = 2008253
  //EOBJECT4 = 2008254
  //EOBJECT5 = 2008255
  //EOBJECT6 = 2008256
  //EOBJECT7 = 2008257
  //EVENTACTION0 = 53
  //ITEM0 = 2002207
  //LOCAISHUBGM = 458
  //LOCAURA001 = 1021983
  //LOCAURA002 = 1021984
  //LOCBINDDUID = 6840981
  //LOCBINDGOUSETSU = 6872468
  //LOCBINDHIEN = 6872466
  //LOCBINDLISE = 6872467
  //LOCBINDMAGUNAI = 6840967
  //LOCTOHOBGM = 465
  //POPRANGE0 = 6913795
  //TERRITORYTYPE0 = 622

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
        if( param1 == 1022078 ) // ACTOR0 = BAATU
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=BAATU
          }
          break;
        }
        if( param1 == 1021732 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021731 ) // ACTOR2 = GOSETSU
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021730 ) // ACTOR3 = HIEN
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 1:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00005( quest, player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=BAATU
        break;
      }
      case 2:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00006( quest, player ); // Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=THEDAWNTHRONEUPPERKEEPER
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 8
      case 3:
      {
        if( param1 == 2008250 ) // EOBJECT0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00008( quest, player ); // Scene00008: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008251 ) // EOBJECT1 = unknown
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00010( quest, player ); // Scene00010: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008252 ) // EOBJECT2 = unknown
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00012( quest, player ); // Scene00012: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008253 ) // EOBJECT3 = unknown
        {
          if( !quest.getBitFlag8( 4 ) )
          {
            Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008254 ) // EOBJECT4 = unknown
        {
          if( !quest.getBitFlag8( 5 ) )
          {
            Scene00016( quest, player ); // Scene00016: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008255 ) // EOBJECT5 = unknown
        {
          if( !quest.getBitFlag8( 6 ) )
          {
            Scene00018( quest, player ); // Scene00018: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008256 ) // EOBJECT6 = unknown
        {
          if( !quest.getBitFlag8( 7 ) )
          {
            Scene00020( quest, player ); // Scene00020: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008257 ) // EOBJECT7 = unknown
        {
          if( !quest.getBitFlag8( 8 ) )
          {
            Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1023089 ) // ACTOR5 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Normal(YesNo), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 8
      case 4:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00024( quest, player ); // Scene00024: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=BAATU
        break;
      }
      case 255:
      {
        if( param1 == 1019417 ) // ACTOR6 = MAGNAI
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=MAGNAI
          break;
        }
        if( param1 == 1021730 ) // ACTOR3 = HIEN
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1022078 ) // ACTOR0 = BAATU
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=BAATU
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
    if( quest.getUI8AL() == 8 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setBitFlag8( 2, false );
      quest.setBitFlag8( 3, false );
      quest.setBitFlag8( 4, false );
      quest.setBitFlag8( 5, false );
      quest.setBitFlag8( 6, false );
      quest.setBitFlag8( 7, false );
      quest.setBitFlag8( 8, false );
      quest.setSeq( 4 );
      quest.setUI8BH( 8 );
    }
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    quest.setUI8BH( 0 );
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=BAATU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00004: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=THEDAWNTHRONEUPPERKEEPER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
        checkProgressSeq2( quest, player );
        eventMgr().eventFinish( player, result.eventId, 1 );
        warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 622 )->getGuId(), { 77.57, 4, 38.21 }, 1.75 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, UI8AL = 8, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00008: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 8 );
    checkProgressSeq3( quest, player );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, UI8AL = 8, Flag8(2)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00010: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 2, true );
    eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 8 );
    checkProgressSeq3( quest, player );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT2, UI8AL = 8, Flag8(3)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00012: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 3, true );
    eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 8 );
    checkProgressSeq3( quest, player );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT3, UI8AL = 8, Flag8(4)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00014: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 4, true );
    eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 8 );
    checkProgressSeq3( quest, player );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT4, UI8AL = 8, Flag8(5)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00016: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 5, true );
    eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 8 );
    checkProgressSeq3( quest, player );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT5, UI8AL = 8, Flag8(6)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00018: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 6, true );
    eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 8 );
    checkProgressSeq3( quest, player );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT6, UI8AL = 8, Flag8(7)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00020: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 7, true );
    eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 8 );
    checkProgressSeq3( quest, player );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT7, UI8AL = 8, Flag8(8)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00022: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 8, true );
    eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 8 );
    checkProgressSeq3( quest, player );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00023: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 622 )->getGuId(), { 77.57, 4, 38.21 }, 1.75 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_4: , <No Var>, <No Flag>(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00024: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00025( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }
  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_4: , <No Var>, <No Flag>(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00027: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=MAGNAI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00028: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda410:68045 calling Scene00029: Normal(Talk, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda410 );
