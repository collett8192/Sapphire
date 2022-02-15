// FFXIVTheMovie.ParserV3.8
// param used:
//_BRANCH SET!!
//PRIVATE_SCENE8 = 198
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManSea009 : public Sapphire::ScriptAPI::QuestScript
{
public:
  ManSea009() : Sapphire::ScriptAPI::QuestScript( 66081 ){}; 
  ~ManSea009() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1000972
  //ACTOR1 = 1001029
  //ACTOR2 = 1003355
  //ACTOR3 = 1002694
  //CUTSCENE01 = 137
  //CUTSCENE02 = 63
  //CUTSCENE03 = 223
  //POPRANGE0 = 4146938
  //POPRANGE1 = 4146949
  //RITEM0 = 3760
  //TERRITORYTYPE0 = 198

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=BADERON
        break;
      }
      case 1:
      {
        if( param1 == 1001029 ) // ACTOR1 = ZANTHAEL, CB=1
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ZANTHAEL
            // +Callback Scene00003: Normal(Talk, TargetCanMove), id=ZANTHAEL
            // +Callback Scene00004: Normal(CutScene, AutoFadeIn), id=unknown
          }
          else
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=ZANTHAEL
          }
          break;
        }
        if( param1 == 1003355 ) // ACTOR2 = JNASSHYM
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=JNASSHYM
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1002694 ) // ACTOR3 = MERLWYB
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MERLWYB
          break;
        }
        if( param1 == 1001029 ) // ACTOR1 = ZANTHAEL
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=ZANTHAEL
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
  }
  void checkProgressSeq1( World::Quest& quest, Entity::Player& player )
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
    playerMgr().sendDebug( player, "ManSea009:66081 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=BADERON" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        checkProgressSeq0( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "ManSea009:66081 calling Scene00002: Normal(Talk, TargetCanMove), id=ZANTHAEL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00003( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }
  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "ManSea009:66081 calling Scene00003: Normal(Talk, TargetCanMove), id=ZANTHAEL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00004( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }
  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "ManSea009:66081 calling Scene00004: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "ManSea009:66081 calling Scene00005: Normal(Talk, TargetCanMove), id=ZANTHAEL" );
    eventMgr().playQuestScene( player, getId(), 5, NONE, nullptr );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea009:66081 calling Scene00006: Normal(Talk, TargetCanMove), id=JNASSHYM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea009:66081 calling Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea009:66081 calling Scene00008: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=ZANTHAEL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 198 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }
};

EXPOSE_SCRIPT( ManSea009 );
