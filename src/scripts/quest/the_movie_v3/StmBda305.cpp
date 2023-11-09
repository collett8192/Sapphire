// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda305 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda305() : Sapphire::ScriptAPI::QuestScript( 68017 ){}; 
  ~StmBda305() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 5 entries
  //SEQ_3, 6 entries
  //SEQ_4, 2 entries
  //SEQ_5, 3 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1021511
  //ACTOR1 = 1019946
  //ACTOR2 = 1019944
  //ACTOR3 = 1019939
  //ACTOR4 = 1019938
  //ACTOR5 = 1020363
  //ACTOR6 = 1021505
  //BINDACTOR0 = 6829417
  //BINDACTOR1 = 6829416
  //CUTSCENEN01 = 1411
  //ENEMY0 = 6829455
  //ENEMY1 = 6829456
  //ENEMY2 = 6829464
  //EOBJECT0 = 2007911
  //EOBJECT1 = 2007912
  //EOBJECT2 = 2007913
  //EOBJECT3 = 2008025
  //EVENTACTION0 = 53
  //EVENTACTION1 = 38
  //EVENTRANGE0 = 6829469
  //ITEM0 = 2002093

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HIRASE
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 2007911 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00003( quest, player ); // Scene00003: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1021511 ) // ACTOR0 = HIRASE
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=HIRASE
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BL max stack ?
      case 2:
      {
        if( param1 == 2007912 ) // EOBJECT1 = unknown
        {
          if( quest.getUI8BH() != 1 )
          {
            if( type == EVENT_ON_TALK ) Scene00005( quest, player ); // Scene00005: Normal(Message, Inventory), id=unknown
            if( type == EVENT_ON_EVENT_ITEM ) Scene00006( quest, player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT1
        if( param1 == 6829455 ) // ENEMY0 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2007913 ) // EOBJECT2 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            if( type == EVENT_ON_TALK ) Scene00009( quest, player ); // Scene00009: Normal(Message, Inventory), id=unknown
            if( type == EVENT_ON_EVENT_ITEM ) Scene00010( quest, player ); // Scene00010: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT2
        if( param1 == 6829456 ) // ENEMY1 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1021511 ) // ACTOR0 = HIRASE
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=HIRASE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 6829469 ) // EVENTRANGE0 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6829464 ) // ENEMY2 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Normal(Message), id=unknown
          break;
        }
        if( param1 == 1019946 ) // ACTOR1 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008025 ) // EOBJECT3 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019944 ) // ACTOR2 = HIRASE
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=HIRASE
          break;
        }
        if( param1 == 1021511 ) // ACTOR0 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1019946 ) // ACTOR1 = PIRATE02481
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00021( quest, player ); // Scene00021: Normal(Talk, NpcDespawn, TargetCanMove), id=PIRATE02481
          }
          break;
        }
        if( param1 == 1021511 ) // ACTOR0 = HIRASE
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=HIRASE
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1019939 ) // ACTOR3 = ALISAIE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1019938 ) // ACTOR4 = LYSE
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020363 ) // ACTOR5 = TANSUI
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021505 ) // ACTOR6 = unknown
        {
          Scene00026( quest, player ); // Scene00026: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1019939 ) // ACTOR3 = ALISAIE
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1019938 ) // ACTOR4 = LYSE
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020363 ) // ACTOR5 = TANSUI
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=TANSUI
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
      quest.setUI8BH( 0 );
      quest.setSeq( 2 );
      quest.setUI8BL( 1 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8BH() == 1 )
      if( quest.getUI8AL() == 1 )
      {
        quest.setUI8BH( 0 );
        quest.setUI8AL( 0 );
        quest.setBitFlag8( 1, false );
        quest.setBitFlag8( 2, false );
        quest.setUI8BL( 0 );
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

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, HIDE_HOTBAR, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HIRASE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00003: Empty(None), id=unknown" );
    quest.setUI8AL( 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
    checkProgressSeq1( quest, player );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00004: Normal(Talk, TargetCanMove), id=HIRASE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, UI8BH = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00005: Normal(Message, Inventory), id=unknown" );
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, nullptr );
  }
  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, UI8BH = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT2, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00009: Normal(Message, Inventory), id=unknown" );
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, nullptr );
  }
  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT2, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00013: Normal(Talk, TargetCanMove), id=HIRASE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: EVENTRANGE0, <No Var>, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00016: Normal(Message), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00017: Empty(None), id=unknown" );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00018: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00019: Normal(Talk, TargetCanMove), id=HIRASE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00020: Empty(None), id=unknown" );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00021: Normal(Talk, NpcDespawn, TargetCanMove), id=PIRATE02481" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00022: Normal(Talk, TargetCanMove), id=HIRASE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00024: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00025: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00026: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00027: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00028: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda305:68017 calling Scene00029: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda305 );
