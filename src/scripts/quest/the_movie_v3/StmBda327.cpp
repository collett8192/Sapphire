// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda327 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda327() : Sapphire::ScriptAPI::QuestScript( 68489 ){}; 
  ~StmBda327() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_2, 5 entries
  //SEQ_3, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1021507
  //ACTOR1 = 1023682
  //ENEMY0 = 7011281
  //EOBJECT0 = 2009002
  //EOBJECT1 = 2009003
  //EOBJECT2 = 2009004
  //EOBJECT3 = 2008572
  //EVENTACTION0 = 1
  //EVENTACTION1 = 5
  //EVENTRANGE0 = 7011338
  //ITEM0 = 2002387
  //ITEM1 = 2002388
  //LOGMES01 = 3757

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
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=KAJIKA
        break;
      }
      case 1:
      {
        if( param1 == 7011338 ) // EVENTRANGE0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EVENTRANGE0
        if( param1 == 7011281 ) // ENEMY0 = unknown
        {
          Scene00003( quest, player ); // Scene00003: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023682 ) // ACTOR1 = unknown
        {
          Scene00004( quest, player ); // Scene00004: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2009002 ) // EOBJECT0 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Empty(None), id=unknown
          break;
        }
        if( param1 == 2009003 ) // EOBJECT1 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Empty(None), id=unknown
          break;
        }
        if( param1 == 2009004 ) // EOBJECT2 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008572 ) // EOBJECT3 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021507 ) // ACTOR0 = KAJIKA
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=KAJIKA
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 3
      case 2:
      {
        if( param1 == 1023682 ) // ACTOR1 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2009002 ) // EOBJECT0 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Empty(None), id=unknown
          break;
        }
        if( param1 == 2009003 ) // EOBJECT1 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Empty(None), id=unknown
          break;
        }
        if( param1 == 2009004 ) // EOBJECT2 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021507 ) // ACTOR0 = KAJIKA
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=KAJIKA
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 3
      //seq 3 event item ITEM1 = UI8BL max stack 8
      case 3:
      {
        if( param1 == 1023682 ) // ACTOR1 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00016( quest, player ); // Scene00016: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1021507 ) // ACTOR0 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Normal(NpcDespawn), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      //seq 255 event item ITEM1 = UI8BL max stack 8
      case 255:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00019( quest, player ); // Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KAJIKA
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
      quest.setSeq( 255 );
      quest.setUI8BH( 3 );
      quest.setUI8BL( 8 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=KAJIKA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: EVENTRANGE0, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00003: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00004: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00005: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00006: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00007: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00008: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00009: Normal(Talk, TargetCanMove), id=KAJIKA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00010: Empty(None), id=unknown" );
    quest.setUI8AL( 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
    checkProgressSeq2( quest, player );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00012: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00013: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00014: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00015: Normal(Talk, TargetCanMove), id=KAJIKA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00016: Empty(None), id=unknown" );
    quest.setUI8AL( 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
    checkProgressSeq3( quest, player );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00017: Normal(NpcDespawn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00020( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }
  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda327:68489 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KAJIKA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda327 );
