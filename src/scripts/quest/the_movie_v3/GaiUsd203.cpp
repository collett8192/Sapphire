// FFXIVTheMovie.ParserV3.11
// param used:
//SCENE_4 = dummye0
//EOBJECT0 = dummye0
//_EOBJECT0 = S
//SCENE_8 = dummye1
//EOBJECT1 = dummye1
//_EOBJECT1 = S
//SCENE_13 = dummye4
//EOBJECT4 = dummye4
//_EOBJECT4 = S
//SCENE_7 REMOVED!!
//SCENE_18 REMOVED!!
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class GaiUsd203 : public Sapphire::ScriptAPI::QuestScript
{
public:
  GaiUsd203() : Sapphire::ScriptAPI::QuestScript( 66737 ){}; 
  ~GaiUsd203() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 8 entries
  //SEQ_4, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006725
  //ACTOR1 = 1000768
  //ACTOR2 = 1007760
  //ENEMY0 = 4502639
  //ENEMY1 = 4502640
  //ENEMY2 = 4502641
  //EOBJECT0 = 2002893
  //EOBJECT1 = 2002894
  //EOBJECT2 = 2002895
  //EOBJECT3 = 2002898
  //EOBJECT4 = 2002896
  //EVENTRANGE0 = 4499387
  //EVENTACTIONPROCESSUPPERLONG = 33
  //EVENTACTIONPROCESSUPPERMIDDLE = 32
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001100
  //ITEM1 = 2001101
  //LOCACTION0 = 81
  //LOCACTION1 = 82
  //LOCEOBJ1 = 2003014
  //LOCFACE0 = 604
  //LOCFACE1 = 617
  //LOCPOSACTOR0 = 4513214
  //LOCPOSCAM1 = 4513638
  //LOCPOSEOBJ1 = 4499380
  //LOCTALKSHAPE1 = 6
  //NCUTEVENTGAIUSD2031 = 444

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
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RAMMBROES
        break;
      }
      case 1:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=PARSEMONTRET
        break;
      }
      case 2:
      {
        if( param1 == 2002893 ) // EOBJECT0 = dummye0
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=dummye0
          }
          break;
        }
        if( param1 == 1007760 ) // ACTOR2 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 4499387 ) // EVENTRANGE0 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2002894 ) // EOBJECT1 = dummye1
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=dummye1
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT1
        if( param1 == 4502639 ) // ENEMY0 = unknown
        {
        // empty entry
          break;
        }
        if( param1 == 4502640 ) // ENEMY1 = unknown
        {
        // empty entry
          break;
        }
        if( param1 == 4502641 ) // ENEMY2 = unknown
        {
        // empty entry
          break;
        }
        if( param1 == 1007760 ) // ACTOR2 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Empty(None), id=unknown
          break;
        }
        if( param1 == 2002895 ) // EOBJECT2 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Empty(None), id=unknown
          break;
        }
        if( param1 == 2002898 ) // EOBJECT3 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      //seq 4 event item ITEM1 = UI8BL max stack 1
      case 4:
      {
        if( param1 == 2002896 ) // EOBJECT4 = dummye4
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, FadeIn, TargetCanMove), id=dummye4
          }
          break;
        }
        if( param1 == 2002898 ) // EOBJECT3 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      case 255:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00015( quest, player ); // Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAMMBROES
        // +Callback Scene00017: Normal(CutScene), id=unknown
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
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 3 );
    }
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 3 )
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
      quest.setSeq( 255 );
      quest.setUI8BH( 1 );
      quest.setUI8BL( 1 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00002: Normal(Talk, TargetCanMove), id=PARSEMONTRET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=dummye0" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00005: Empty(None), id=unknown" );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_3: EVENTRANGE0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, UI8AL = 3, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=dummye1" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 3 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }




  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00009: Empty(None), id=unknown" );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00011: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00012: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT4, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00013: Normal(Talk, FadeIn, TargetCanMove), id=dummye4" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00014: Empty(None), id=unknown" );
    checkProgressSeq4( quest, player );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00016( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }
  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00017( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }
  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd203:66737 calling Scene00017: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      player.finishQuest( getId(), result.getResult( 1 ) );
    };
    eventMgr().playQuestScene( player, getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( GaiUsd203 );
