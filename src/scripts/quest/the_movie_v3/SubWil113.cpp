// FFXIVTheMovie.ParserV3.8
// param used:
//_AGGRESSIVE_BNPC_HACK SET!!
//IGNORE_BNPCHACK_EVENTRANGE0 SET!!
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil113 : public Sapphire::ScriptAPI::QuestScript
{
public:
  SubWil113() : Sapphire::ScriptAPI::QuestScript( 66157 ){}; 
  ~SubWil113() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 10 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1003929
  //ACTOR1 = 1003976
  //ACTOR2 = 1003971
  //ACTOR3 = 1003972
  //ACTOR4 = 1003973
  //ACTOR5 = 1003974
  //ACTOR6 = 1003975
  //ENEMY0 = 4102012
  //ENEMY1 = 4102013
  //EOBJECT0 = 2001868
  //EVENTRANGE0 = 4102016
  //EVENTACTIONRESCUEUNDERMIDDLE = 35
  //EVENTACTIONSEARCH = 1

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
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ISEMBARD
        break;
      }
      case 1:
      {
        if( param1 == 1003976 ) // ACTOR1 = CHILD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=CHILD
          }
          break;
        }
        if( param1 == 1003971 ) // ACTOR2 = unknown
        {
          Scene00003( quest, player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003972 ) // ACTOR3 = unknown
        {
          Scene00004( quest, player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003973 ) // ACTOR4 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003974 ) // ACTOR5 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 4102016 ) // EVENTRANGE0 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Normal(Message), id=unknown
          break;
        }
        if( param1 == 1003975 ) // ACTOR6 = OURCEN
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=OURCEN
          }
          break;
        }
        // BNpcHack credit moved to ACTOR6
        if( param1 == 4102012 ) // ENEMY0 = unknown
        {
        // empty entry
          break;
        }
        if( param1 == 4102013 ) // ENEMY1 = unknown
        {
        // empty entry
          break;
        }
        if( param1 == 1003976 ) // ACTOR1 = CHILD
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=CHILD
          break;
        }
        if( param1 == 1003971 ) // ACTOR2 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003972 ) // ACTOR3 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003973 ) // ACTOR4 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003974 ) // ACTOR5 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001868 ) // EOBJECT0 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00017( quest, player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ISEMBARD
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
      quest.setSeq( 2 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 2 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ISEMBARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00002: Normal(Talk, TargetCanMove), id=CHILD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: EVENTRANGE0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00008: Normal(Message), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 2, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=OURCEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 2 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }



  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00010: Normal(Talk, TargetCanMove), id=CHILD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil113:66157 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ISEMBARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil113 );
