// FFXIVTheMovie.ParserV3.8
// param used:
//SCENE_100 REMOVED!!
//SCENE_99 REMOVED!!
//SCENE_98 REMOVED!!
//SCENE_97 REMOVED!!
//SCENE_96 REMOVED!!
//SCENE_95 REMOVED!!
//SCENE_94 REMOVED!!
//SCENE_93 REMOVED!!
//SCENE_92 REMOVED!!
//SCENE_91 REMOVED!!
//SCENE_89 REMOVED!!
//SCENE_88 REMOVED!!
//SCENE_87 REMOVED!!
//SCENE_86 REMOVED!!
//SCENE_85 REMOVED!!
//SCENE_84 REMOVED!!
//SCENE_83 REMOVED!!
//SCENE_82 REMOVED!!
//SCENE_81 REMOVED!!
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea105 : public Sapphire::ScriptAPI::QuestScript
{
public:
  SubSea105() : Sapphire::ScriptAPI::QuestScript( 65938 ){}; 
  ~SubSea105() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1003239
  //ACTOR1 = 1003244
  //ENEMY0 = 3927183
  //ENEMY1 = 3927184
  //EOBJECT0 = 2001255
  //EOBJECT1 = 2001256
  //EOBJECT2 = 2001257
  //EOBJECT3 = 2001258
  //EOBJECT4 = 2001259
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000342
  //QSTACCEPTCHECK = 65934

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove, SystemTalk, CanCancel), id=WYRKRHIT
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( param1 == 2001255 ) // EOBJECT0 = unknown
        {
          Scene00001( quest, player ); // Scene00001: Normal(None), id=unknown
          break;
        }
        if( param1 == 3927183 ) // ENEMY0 = unknown
        {
        // empty entry
          break;
        }
        if( param1 == 3927184 ) // ENEMY1 = unknown
        {
        // empty entry
          break;
        }
        if( param1 == 2001256 ) // EOBJECT1 = unknown
        {
          Scene00002( quest, player ); // Scene00002: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001257 ) // EOBJECT2 = unknown
        {
          Scene00003( quest, player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001258 ) // EOBJECT3 = unknown
        {
          Scene00004( quest, player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001259 ) // EOBJECT4 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1003244 ) // ACTOR1 = LYULF
        {
          Scene00006( quest, player ); // Scene00006: NpcTrade(Talk, TargetCanMove), id=LYULF
          // +Callback Scene00090: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYULF
          break;
        }
        if( param1 == 2001256 ) // EOBJECT1 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001257 ) // EOBJECT2 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001258 ) // EOBJECT3 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001259 ) // EOBJECT4 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Normal(None), id=unknown
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
    quest.setBitFlag8( 1, false );
    quest.setSeq( 255 );
    quest.setUI8BH( 1 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea105:65938 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove, SystemTalk, CanCancel), id=WYRKRHIT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        checkProgressSeq0( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }

  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "SubSea105:65938 calling Scene00001: Normal(None), id=unknown" );
    quest.setBitFlag8( 1, true );
    checkProgressSeq1( quest, player );
  }



  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea105:65938 calling Scene00002: Normal(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea105:65938 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea105:65938 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea105:65938 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea105:65938 calling Scene00006: NpcTrade(Talk, TargetCanMove), id=LYULF" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00090( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }
  void Scene00090( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea105:65938 calling Scene00090: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYULF" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 90, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea105:65938 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea105:65938 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea105:65938 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea105:65938 calling Scene00010: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubSea105 );
