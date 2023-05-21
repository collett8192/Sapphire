// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBdz002 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBdz002() : Sapphire::ScriptAPI::QuestScript( 68172 ){}; 
  ~StmBdz002() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1019476
  //ACTOR1 = 1019471
  //EOBJECT0 = 2007951
  //EOBJECT1 = 2007952
  //EOBJECT2 = 2007953
  //EOBJECT3 = 2007954
  //EVENTACTION0 = 7
  //ITEM0 = 2002077

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
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AHELISSA
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 6
      case 1:
      {
        if( param1 == 1019471 ) // ACTOR1 = TEBBE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=TEBBE
          }
          break;
        }
        if( param1 == 1019476 ) // ACTOR0 = AHELISSA
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=AHELISSA
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 6
      case 2:
      {
        if( param1 == 2007951 ) // EOBJECT0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00005( quest, player ); // Scene00005: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2007952 ) // EOBJECT1 = unknown
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2007953 ) // EOBJECT2 = unknown
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00009( quest, player ); // Scene00009: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2007954 ) // EOBJECT3 = unknown
        {
          if( !quest.getBitFlag8( 4 ) )
          {
            Scene00011( quest, player ); // Scene00011: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1019476 ) // ACTOR0 = AHELISSA
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=AHELISSA
          break;
        }
        if( param1 == 1019471 ) // ACTOR1 = TEBBE
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=TEBBE
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 6
      case 255:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00014( quest, player ); // Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AHELISSA
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
    if( quest.getUI8AL() == 4 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setBitFlag8( 2, false );
      quest.setBitFlag8( 3, false );
      quest.setBitFlag8( 4, false );
      quest.setSeq( 255 );
      quest.setUI8BH( 6 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdz002:68172 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBdz002:68172 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AHELISSA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdz002:68172 calling Scene00002: Normal(Talk, TargetCanMove), id=TEBBE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdz002:68172 calling Scene00003: Normal(Talk, TargetCanMove), id=AHELISSA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 4, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBdz002:68172 calling Scene00005: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 4 );
    checkProgressSeq2( quest, player );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, UI8AL = 4, Flag8(2)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBdz002:68172 calling Scene00007: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 2, true );
    eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 4 );
    checkProgressSeq2( quest, player );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT2, UI8AL = 4, Flag8(3)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBdz002:68172 calling Scene00009: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 3, true );
    eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 4 );
    checkProgressSeq2( quest, player );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT3, UI8AL = 4, Flag8(4)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBdz002:68172 calling Scene00011: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 4, true );
    eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 4 );
    checkProgressSeq2( quest, player );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdz002:68172 calling Scene00012: Normal(Talk, TargetCanMove), id=AHELISSA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdz002:68172 calling Scene00013: Normal(Talk, TargetCanMove), id=TEBBE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdz002:68172 calling Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00015( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }
  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdz002:68172 calling Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AHELISSA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBdz002 );
