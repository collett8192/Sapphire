// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda318 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda318() : Sapphire::ScriptAPI::QuestScript( 68030 ){}; 
  ~StmBda318() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 7 entries
  //SEQ_2, 1 entries
  //SEQ_3, 3 entries
  //SEQ_4, 1 entries
  //SEQ_5, 1 entries
  //SEQ_255, 3 entries

  //ACTIONTIMELINEEVENTSTANDPRAY = 4254
  //ACTOR0 = 1020012
  //ACTOR1 = 1020013
  //ACTOR2 = 1020018
  //ACTOR3 = 1020071
  //ACTOR4 = 1020072
  //ACTOR5 = 1020019
  //ACTOR6 = 1020020
  //ACTOR7 = 1020021
  //BINDACTOR0 = 6782229
  //ENEMY0 = 6791550
  //ENEMY1 = 6791551
  //ENEMY2 = 6791564
  //EOBJECT0 = 2007844
  //EOBJECT1 = 2007836
  //EOBJECT2 = 2007837
  //EVENTACTION0 = 1
  //EVENTACTION1 = 26
  //EVENTRANGE0 = 6793562
  //ITEM0 = 2002067
  //LOCACTOR0 = 1018977
  //LOCEOBJ01 = 2008780

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
        if( param1 == 1020012 ) // ACTOR0 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1020013 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 6793562 ) // EVENTRANGE0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00003( quest, player ); // Scene00003: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EVENTRANGE0
        if( param1 == 6791550 ) // ENEMY0 = unknown
        {
          Scene00004( quest, player ); // Scene00004: Empty(None), id=unknown
          break;
        }
        if( param1 == 6791551 ) // ENEMY1 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020018 ) // ACTOR2 = AZAMI
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, Message, TargetCanMove), id=AZAMI
          break;
        }
        if( param1 == 1020071 ) // ACTOR3 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020072 ) // ACTOR4 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Empty(None), id=unknown
          break;
        }
        if( param1 == 2007844 ) // EOBJECT0 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=AZAMI
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 2007836 ) // EOBJECT1 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6791564 ) // ENEMY2 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1020018 ) // ACTOR2 = AZAMI
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=AZAMI
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00018( quest, player ); // Scene00018: NpcTrade(Talk), id=unknown
        // +Callback Scene00019: Normal(Talk, NpcDespawn, TargetCanMove), id=AZAMI
        break;
      }
      case 5:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=AZAMI
        // +Callback Scene00021: Normal(Talk, FadeIn, TargetCanMove, Menu), id=AZAMI
        break;
      }
      case 255:
      {
        if( param1 == 1020020 ) // ACTOR6 = YUGIRI
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020021 ) // ACTOR7 = LYSE
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 2007837 ) // EOBJECT2 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Empty(None), id=unknown
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
    if( quest.getUI8AL() == 2 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 2 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 3 );
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    quest.setBitFlag8( 1, false );
    quest.setSeq( 4 );
    quest.setUI8BH( 1 );
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    quest.setUI8BH( 0 );
    quest.setSeq( 5 );
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: EVENTRANGE0, UI8AL = 2, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 2 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00004: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00005: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00006: Normal(Talk, Message, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00007: Empty(None), id=unknown" );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00008: Empty(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00010: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00012: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00016: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00017: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_4: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00018: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00019( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }
  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_4: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00019: Normal(Talk, NpcDespawn, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_5: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00020: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00021( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }
  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_5: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00021: Normal(Talk, FadeIn, TargetCanMove, Menu), id=AZAMI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        checkProgressSeq5( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00023: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda318:68030 calling Scene00024: Empty(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda318 );
