// FFXIVTheMovie.ParserV3.8
// param used:
//ID_ACTOR1 = 4298942495
//ID_ACTOR2 = 4298942496
//ID_ACTOR3 = 4298942497
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil110 : public Sapphire::ScriptAPI::QuestScript
{
public:
  SubWil110() : Sapphire::ScriptAPI::QuestScript( 66154 ){}; 
  ~SubWil110() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 10 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1003929
  //ACTOR1 = 1003942
  //ACTOR2 = 1003943
  //ACTOR3 = 1003944
  //ENEMY0 = 4100865
  //ENEMY1 = 4100866
  //EOBJECT0 = 2001663
  //EOBJECT1 = 2001664
  //EOBJECT2 = 2001665
  //EOBJECT3 = 2001866
  //EVENTRANGE0 = 4100864
  //EVENTACTIONGATHERSHORT = 6
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000399

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=ISEMBARD
        // +Callback Scene00001: Normal(QuestAccept), id=unknown
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 3
      case 1:
      {
        if( param1 == 1003942 || param1 == 4298942495 ) // ACTOR1 = unknown
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1003943 || param1 == 4298942496 ) // ACTOR2 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00003( quest, player ); // Scene00003: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1003944 || param1 == 4298942497 ) // ACTOR3 = unknown
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 4100864 ) // EVENTRANGE0 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 4100865 ) // ENEMY0 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 4100866 ) // ENEMY1 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001663 ) // EOBJECT0 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001664 ) // EOBJECT1 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2001665 ) // EOBJECT2 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001866 ) // EOBJECT3 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        if( param1 == 1003929 ) // ACTOR0 = ISEMBARD
        {
          Scene00019( quest, player ); // Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ISEMBARD
          break;
        }
        if( param1 == 2001663 ) // EOBJECT0 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001664 ) // EOBJECT1 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001665 ) // EOBJECT2 = unknown
        {
          Scene00027( quest, player ); // Scene00027: Normal(None), id=unknown
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
    if( quest.getUI8BL() == 1 )
      if( quest.getUI8AL() == 1 )
        if( quest.getUI8BH() == 1 )
        {
          quest.setUI8BL( 0 );
          quest.setUI8AL( 0 );
          quest.setUI8BH( 0 );
          quest.setBitFlag8( 1, false );
          quest.setBitFlag8( 2, false );
          quest.setBitFlag8( 3, false );
          quest.setUI8CH( 0 );
          quest.setSeq( 255 );
          quest.setUI8BH( 3 );
        }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=ISEMBARD" );
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
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00001: Normal(QuestAccept), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8BL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00002: Normal(None), id=unknown" );
    quest.setUI8BL( 1 );
    quest.setBitFlag8( 1, true );
    checkProgressSeq1( quest, player );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00003: Normal(None), id=unknown" );
    quest.setUI8AL( 1 );
    quest.setBitFlag8( 2, true );
    checkProgressSeq1( quest, player );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8BH = 1, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00004: Normal(None), id=unknown" );
    quest.setUI8BH( 1 );
    quest.setBitFlag8( 3, true );
    checkProgressSeq1( quest, player );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: EVENTRANGE0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00020( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }
  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ISEMBARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil110:66154 calling Scene00027: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubWil110 );
