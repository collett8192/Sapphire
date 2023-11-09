// FFXIVTheMovie.ParserV3.11
// param used:
//SCENE_10 = SOLDIERC02495
//SCENE_19 = SOLDIERD02496
//PRIVATE_SCENE26 = 681
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda321 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda321() : Sapphire::ScriptAPI::QuestScript( 68033 ){}; 
  ~StmBda321() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 2 entries
  //SEQ_4, 2 entries
  //SEQ_5, 2 entries
  //SEQ_6, 2 entries
  //SEQ_7, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1020046
  //ACTOR1 = 1020047
  //ACTOR2 = 1020048
  //ACTOR3 = 1020049
  //ACTOR4 = 1020050
  //ACTOR5 = 1020051
  //ACTOR6 = 1023787
  //EOBJECT0 = 2007840
  //EOBJECT1 = 2007841
  //EVENTACTION0 = 3
  //ITEM0 = 2002070
  //ITEM1 = 2002072
  //ITEM2 = 2002073
  //NCUT01 = 1428
  //NCUT02 = 1429
  //POPRANGE0 = 6791456

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
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( param1 == 1020046 ) // ACTOR0 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1020047 ) // ACTOR1 = SOLDIERC02495
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=SOLDIERC02495
          break;
        }
        if( param1 == 1020048 ) // ACTOR2 = SOLDIERD02496
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=SOLDIERD02496
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      //seq 1 event item ITEM1 = UI8BL max stack ?
      case 1:
      {
        if( param1 == 1020047 ) // ACTOR1 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1020048 ) // ACTOR2 = SOLDIERD02496
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=SOLDIERD02496
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      //seq 2 event item ITEM1 = UI8BL max stack ?
      case 2:
      {
        if( param1 == 2007840 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1020048 ) // ACTOR2 = SOLDIERD02496
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=SOLDIERD02496
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      //seq 3 event item ITEM1 = UI8BL max stack ?
      case 3:
      {
        if( param1 == 1020049 ) // ACTOR3 = SOLDIERC02495
        {
          if( quest.getUI8AL() != 1 )
          {
            if( type == EVENT_ON_TALK ) Scene00010( quest, player ); // Scene00010: Normal(Inventory), id=SOLDIERC02495
            if( type == EVENT_ON_EVENT_ITEM ) Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=SOLDIERC02495
          }
          break;
        }
        if( param1 == 1020048 ) // ACTOR2 = SOLDIERD02496
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=SOLDIERD02496
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      //seq 4 event item ITEM1 = UI8BL max stack ?
      //seq 4 event item ITEM2 = UI8CH max stack ?
      case 4:
      {
        if( param1 == 1020048 ) // ACTOR2 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00013( quest, player ); // Scene00013: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1020049 ) // ACTOR3 = SOLDIERC02495
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=SOLDIERC02495
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack ?
      //seq 5 event item ITEM1 = UI8BL max stack ?
      //seq 5 event item ITEM2 = UI8CH max stack ?
      case 5:
      {
        if( param1 == 2007841 ) // EOBJECT1 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1020049 ) // ACTOR3 = SOLDIERC02495
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=SOLDIERC02495
          break;
        }
        break;
      }
      //seq 6 event item ITEM0 = UI8BH max stack ?
      //seq 6 event item ITEM1 = UI8BL max stack ?
      //seq 6 event item ITEM2 = UI8CH max stack ?
      case 6:
      {
        if( param1 == 1020050 ) // ACTOR4 = SOLDIERD02496
        {
          if( quest.getUI8AL() != 1 )
          {
            if( type == EVENT_ON_TALK ) Scene00019( quest, player ); // Scene00019: Normal(Inventory), id=SOLDIERD02496
            if( type == EVENT_ON_EVENT_ITEM ) Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=SOLDIERD02496
          }
          break;
        }
        if( param1 == 1020049 ) // ACTOR3 = SOLDIERC02495
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=SOLDIERC02495
          break;
        }
        break;
      }
      //seq 7 event item ITEM1 = UI8BH max stack ?
      //seq 7 event item ITEM2 = UI8BL max stack ?
      case 7:
      {
        if( param1 == 1020051 ) // ACTOR5 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00022( quest, player ); // Scene00022: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1020049 ) // ACTOR3 = SOLDIERC02495
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=SOLDIERC02495
          break;
        }
        if( param1 == 1020050 ) // ACTOR4 = SOLDIERD02496
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=SOLDIERD02496
          break;
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack ?
      //seq 255 event item ITEM2 = UI8BL max stack ?
      case 255:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI
        // +Callback Scene00026: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown
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
      quest.setUI8BH( 1 );
      quest.setUI8BL( 1 );
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
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 6 );
      quest.setUI8BH( 1 );
      quest.setUI8BL( 1 );
      quest.setUI8CH( 1 );
    }
  }
  void checkProgressSeq6( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setUI8BH( 0 );
      quest.setUI8BL( 0 );
      quest.setUI8CH( 0 );
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
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00002: Normal(Talk, TargetCanMove), id=SOLDIERC02495" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00003: Normal(Talk, TargetCanMove), id=SOLDIERD02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00004: Empty(None), id=unknown" );
    quest.setUI8AL( 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
    checkProgressSeq1( quest, player );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00006: Normal(Talk, TargetCanMove), id=SOLDIERD02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00008: Empty(None), id=unknown" );
    quest.setUI8AL( 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
    checkProgressSeq2( quest, player );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00009: Normal(Talk, TargetCanMove), id=SOLDIERD02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00010: Normal(Inventory), id=SOLDIERC02495" );
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, nullptr );
  }
  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00011: Normal(Talk, TargetCanMove), id=SOLDIERC02495" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00012: Normal(Talk, TargetCanMove), id=SOLDIERD02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR2, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00013: Empty(None), id=unknown" );
    quest.setUI8AL( 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
    checkProgressSeq4( quest, player );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00015: Normal(Talk, TargetCanMove), id=SOLDIERC02495" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT1, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00017: Empty(None), id=unknown" );
    quest.setUI8AL( 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
    checkProgressSeq5( quest, player );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00018: Normal(Talk, TargetCanMove), id=SOLDIERC02495" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:5)
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00019: Normal(Inventory), id=SOLDIERD02496" );
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, nullptr );
  }
  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:5)
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00020: Normal(Talk, TargetCanMove), id=SOLDIERD02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 5, 0, 0, 0 );
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00021: Normal(Talk, TargetCanMove), id=SOLDIERC02495" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:6)
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00022: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 6, 0, 0, 0 );
      checkProgressSeq7( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00023: Normal(Talk, TargetCanMove), id=SOLDIERC02495" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00024: Normal(Talk, TargetCanMove), id=SOLDIERD02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00026( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }
  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda321:68033 calling Scene00026: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 681 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( StmBda321 );
