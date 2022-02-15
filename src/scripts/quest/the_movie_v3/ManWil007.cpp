// FFXIVTheMovie.ParserV3.8
// param used:
//ALTERNATIVE_QUEST_COMPLETE = 
//SCENE_6 REMOVED!!
//SCENE_7 REMOVED!!
//PRIVATE_SULTANSWORMA = 210
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManWil007 : public Sapphire::ScriptAPI::QuestScript
{
public:
  ManWil007() : Sapphire::ScriptAPI::QuestScript( 66087 ){}; 
  ~ManWil007() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 1 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1001353
  //ACTOR1 = 1004005
  //ACTOR2 = 1004002
  //ACTOR3 = 1004003
  //CUTMANWIL00710 = 193
  //CUTMANWIL00745 = 197
  //CUTMANWIL00750 = 143
  //CUTSCENEQIBAFTER01 = 196
  //EOBJECT0 = 2001427
  //EVENTACTIONWAITING3LONG = 13
  //ITEM0 = 2000398
  //POPRANGE0 = 4087066
  //QUESTBATTLE0 = 38
  //TERRITORYTYPE0 = 210
  //TERRITORYTYPE1 = 271
  //TERRITORYTYPE2 = 141

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
      //seq 0 event item ITEM0 = UI8BH max stack 1
      case 0:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=MOMODI
        // +Callback Scene00001: Normal(CutScene), id=unknown
        // +Callback Scene00002: Normal(QuestAccept), id=unknown
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( param1 == 1004005 ) // ACTOR1 = SULTANSWORMA
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, YesNo, TargetCanMove), id=SULTANSWORMA
          break;
        }
        if( param1 == 1004002 ) // ACTOR2 = OWYNE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=OWYNE
          }
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2001427 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(QuestBattle, YesNo), id=unknown
          }
          break;
        }
        if( param1 == 1004002 ) // ACTOR2 = OWYNE
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=OWYNE
          break;
        }
        break;
      }
      case 3:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00010( quest, player ); // Scene00010: Normal(CutScene, AutoFadeIn), id=unknown
        break;
      }
      case 255:
      {
        if( param1 == 1004005 ) // ACTOR1 = SULTANSWORMA
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, YesNo, TargetCanMove), id=SULTANSWORMA
          break;
        }
        if( param1 == 1004003 ) // ACTOR3 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Normal(QuestReward), id=unknown
          // +Callback Scene00013: Normal(CutScene, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1004002 ) // ACTOR2 = OWYNE
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=OWYNE
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
    quest.setUI8BH( 1 );
  }
  void checkProgressSeq1( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 2, false );
      quest.setUI8BH( 0 );
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
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManWil007:66087 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=MOMODI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManWil007:66087 calling Scene00001: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00002( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManWil007:66087 calling Scene00002: Normal(QuestAccept), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManWil007:66087 calling Scene00003: Normal(Talk, YesNo, TargetCanMove), id=SULTANSWORMA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 210 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "ManWil007:66087 calling Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00005( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }
  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "ManWil007:66087 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=OWYNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManWil007:66087 calling Scene00008: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        //quest battle
        eventMgr().eventFinish( player, result.eventId, 1 );
        teriMgr().createAndJoinQuestBattle( player, 38 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManWil007:66087 calling Scene00009: Normal(Talk, TargetCanMove), id=OWYNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManWil007:66087 calling Scene00010: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq3( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManWil007:66087 calling Scene00011: Normal(Talk, YesNo, TargetCanMove), id=SULTANSWORMA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 210 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManWil007:66087 calling Scene00012: Normal(QuestReward), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00013( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }
  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManWil007:66087 calling Scene00013: Normal(CutScene, QuestComplete), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      player.finishQuest( getId(), result.getResult( 1 ) );
    };
    eventMgr().playQuestScene( player, getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManWil007:66087 calling Scene00014: Normal(Talk, TargetCanMove), id=OWYNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }
};

EXPOSE_SCRIPT( ManWil007 );
