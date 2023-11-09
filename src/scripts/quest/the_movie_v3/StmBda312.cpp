// FFXIVTheMovie.ParserV3.11
// param used:
//EVENTRANGE1 = range1
//SCENE_10 = range1
//ACTOR5 = LYSE
//ACTOR6 = dummy6
//ACTOR7 = dummy7
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda312 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda312() : Sapphire::ScriptAPI::QuestScript( 68024 ){}; 
  ~StmBda312() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 6 entries
  //SEQ_4, 3 entries
  //SEQ_5, 4 entries
  //SEQ_255, 2 entries

  //ACTIONTIMELINEEVENTSPIRIT = 1071
  //ACTOR0 = 1019961
  //ACTOR1 = 1019962
  //ACTOR10 = 1019985
  //ACTOR11 = 1019986
  //ACTOR2 = 1019981
  //ACTOR3 = 1019982
  //ACTOR4 = 1019178
  //ACTOR5 = 1020624
  //ACTOR6 = 1023093
  //ACTOR7 = 1020207
  //ACTOR8 = 1019983
  //ACTOR9 = 1019984
  //BINDACTOR0 = 6830024
  //BINDACTOR1 = 6836813
  //CUTSCENEN01 = 1417
  //ENEMY0 = 6913091
  //ENEMY1 = 6836836
  //ENEMY2 = 6836839
  //ENEMY3 = 6836841
  //ENEMY4 = 6913092
  //ENEMY5 = 6913377
  //EOBJECT0 = 2007922
  //EOBJECT1 = 2007921
  //EVENTRANGE0 = 6836822
  //EVENTRANGE1 = 6836824
  //POPRANGE0 = 6842986

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
        if( param1 == 1019961 ) // ACTOR0 = ALISAIE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, Menu, ENpcBind), id=ALISAIE
          }
          break;
        }
        if( param1 == 1019962 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019981 ) // ACTOR2 = ALISAIE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00003( quest, player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ALISAIE
          }
          break;
        }
        if( param1 == 1019982 ) // ACTOR3 = LYSE
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1019178 ) // ACTOR4 = BUNCHIN
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=BUNCHIN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 6836822 ) // EVENTRANGE0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EVENTRANGE0
        if( param1 == 6913091 ) // ENEMY0 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          break;
        }
        if( param1 == 6836836 ) // ENEMY1 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Empty(None), id=unknown
          break;
        }
        if( param1 == 2007922 ) // EOBJECT0 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 6836824 ) // EVENTRANGE1 = range1
        {
          Scene00010( quest, player ); // Scene00010: Normal(Message, PopBNpc), id=range1
          break;
        }
        if( param1 == 6836839 ) // ENEMY2 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Empty(None), id=unknown
          break;
        }
        if( param1 == 6836841 ) // ENEMY3 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Empty(None), id=unknown
          break;
        }
        if( param1 == 6913092 ) // ENEMY4 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Empty(None), id=unknown
          break;
        }
        if( param1 == 6913377 ) // ENEMY5 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          break;
        }
        if( param1 == 2007921 ) // EOBJECT1 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020624 ) // ACTOR5 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00016( quest, player ); // Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1023093 ) // ACTOR6 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020207 ) // ACTOR7 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1019983 ) // ACTOR8 = ALISAIE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE
            // +Callback Scene00020: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1019984 ) // ACTOR9 = LYSE
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1023093 ) // ACTOR6 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020207 ) // ACTOR7 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019985 ) // ACTOR10 = ALISAIE
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1019986 ) // ACTOR11 = LYSE
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=LYSE
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
    if( quest.getUI8AL() == 2 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 3 );
    }
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    quest.setBitFlag8( 1, false );
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
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, Menu, ENpcBind), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        checkProgressSeq0( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00005: Normal(Talk, TargetCanMove), id=BUNCHIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: EVENTRANGE0, UI8AL = 2, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 2 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 2 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00007: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00008: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00009: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_3: EVENTRANGE1, <No Var>, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00010: Normal(Message, PopBNpc), id=range1" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_3: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00011: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: ENEMY3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00012: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: ENEMY4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00013: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ENEMY5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00014: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00015: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00017: Empty(None), id=unknown" );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00018: Empty(None), id=unknown" );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR8, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00020( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }
  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR8, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00020: Normal(CutScene, AutoFadeIn), id=unknown" );
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
    eventMgr().playQuestScene( player, getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00021: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00022: Empty(None), id=unknown" );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00023: Empty(None), id=unknown" );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda312:68024 calling Scene00025: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda312 );
