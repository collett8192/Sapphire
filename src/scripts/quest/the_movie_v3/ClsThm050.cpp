// FFXIVTheMovie.ParserV3.10
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ClsThm050 : public Sapphire::ScriptAPI::QuestScript
{
public:
  ClsThm050() : Sapphire::ScriptAPI::QuestScript( 65883 ){}; 
  ~ClsThm050() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 3 entries
  //SEQ_4, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1001708
  //ACTOR1 = 1001709
  //ACTOR2 = 1002027
  //ACTOR20 = 1001713
  //CUTCLSTHM05010 = 50
  //ENEMY0 = 4002289
  //EOBJECT0 = 2001468
  //EOBJECT1 = 2001469
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONWAITINGSHOR = 11
  //ITEM0 = 2000414
  //ITEM1 = 2000415

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=COCOBUKI
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00001( quest, player ); // Scene00001: Normal(Talk, TargetCanMove), id=COCOBYGO
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( type == EVENT_ON_TALK ) Scene00002( quest, player ); // Scene00002: Normal(Inventory), id=unknown
        if( type == EVENT_ON_EVENT_ITEM ) Scene00003( quest, player ); // Scene00003: Empty(None), id=unknown
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      //seq 3 event item ITEM1 = UI8BL max stack 1
      case 3:
      {
        if( param1 == 2001469 ) // EOBJECT1 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT1
        if( param1 == 4002289 ) // ENEMY0 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Empty(None), id=unknown
          break;
        }
        if( param1 == 2001468 ) // EOBJECT0 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      //seq 4 event item ITEM1 = UI8BL max stack 1
      case 4:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00008( quest, player ); // Scene00008: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00009: Normal(Talk, FadeIn, TargetCanMove), id=FAFAFONO
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      //seq 255 event item ITEM1 = UI8BL max stack 1
      case 255:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00010( quest, player ); // Scene00010: Normal(CutScene), id=unknown
        // +Callback Scene00011: Normal(QuestReward, QuestComplete), id=unknown
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

  void onBNpcKill( World::Quest& quest, uint16_t nameId, uint32_t entityId, Sapphire::Entity::Player& player ) override
  {
    onProgress( quest, player, EVENT_ON_BNPC_KILL, static_cast< uint64_t >( nameId ), entityId, 0 );
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
    quest.setUI8BH( 1 );
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 3 );
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 4 );
      quest.setUI8BH( 1 );
      quest.setUI8BL( 1 );
    }
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ClsThm050:65883 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=COCOBUKI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        checkProgressSeq0( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, HIDE_HOTBAR, callback );
  }

  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ClsThm050:65883 calling Scene00001: Normal(Talk, TargetCanMove), id=COCOBYGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ClsThm050:65883 calling Scene00002: Normal(Inventory), id=unknown" );
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, nullptr );
  }
  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ClsThm050:65883 calling Scene00003: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "ClsThm050:65883 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_3: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ClsThm050:65883 calling Scene00006: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ClsThm050:65883 calling Scene00007: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_4: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ClsThm050:65883 calling Scene00008: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00009( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }
  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_4: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ClsThm050:65883 calling Scene00009: Normal(Talk, FadeIn, TargetCanMove), id=FAFAFONO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ClsThm050:65883 calling Scene00010: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00011( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ClsThm050:65883 calling Scene00011: Normal(QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( ClsThm050 );
