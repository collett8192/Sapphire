// FFXIVTheMovie.ParserV3.9
// param used:
//_ACTOR1 = E
//_ACTOR1E = 1|3,12
//SCENE_15 = SOZAIRARZAI
//_ALLOW_EMPTY_ENTRY SET!!
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea054 : public Sapphire::ScriptAPI::QuestScript
{
public:
  SubSea054() : Sapphire::ScriptAPI::QuestScript( 66002 ){}; 
  ~SubSea054() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 9 entries
  //SEQ_3, 2 entries
  //SEQ_4, 2 entries
  //SEQ_5, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002626
  //ACTOR1 = 1002640
  //ACTOR2 = 1002641
  //ACTOR3 = 1002642
  //ACTOR4 = 1002643
  //ACTOR5 = 1002630
  //ENEMY0 = 3931777
  //ENEMY1 = 3931779
  //EOBJECT0 = 2001279
  //EOBJECT1 = 2000451
  //EOBJECT2 = 2000449
  //EVENTRANGE0 = 3929588
  //EVENTACTION = 35
  //EVENTACTIONPROCESSMIDDLE = 16
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000356
  //ITEM1 = 2000357
  //QSTACCEPTCHECK = 66000

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove, SystemTalk, CanCancel), id=STAELWYRN
        break;
      }
      case 1:
      {
        if( param1 == 1002640 ) // ACTOR1 = SEVRIN, EB=3(emote=12)
        {
          if( quest.getUI8AL() != 1 )
          {
            if( type == EVENT_ON_TALK ) Scene00001( quest, player ); // Scene00001: Normal(Talk, TargetCanMove), id=SEVRIN
            if( type == EVENT_ON_EMOTE )
            {
              if( param3 == 12 ) Scene00002( quest, player ); // Correct Scene00002: Normal(Talk, TargetCanMove), id=SEVRIN
              else Scene00003( quest, player ); // Incorrect Scene00003: Normal(None), id=unknown
            }
          }
          break;
        }
        if( param1 == 2001279 ) // EOBJECT0 = unknown
        {
          Scene00004( quest, player ); // Scene00004: Normal(None), ActionCast, id=unknown
          // +Callback Scene00005: Normal(None), id=unknown
          // +Callback Scene00006: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1002641 ) // ACTOR2 = AYLMER
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00007( quest, player ); // Scene00007: Normal(None), ActionCast, id=unknown
            // +Callback Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=AYLMER
            // +Callback Scene00009: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1002642 ) // ACTOR3 = EYRIMHUS
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00010( quest, player ); // Scene00010: Normal(None), ActionCast, id=unknown
            // +Callback Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=EYRIMHUS
            // +Callback Scene00012: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1002643 ) // ACTOR4 = SOZAIRARZAI
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00013( quest, player ); // Scene00013: Normal(None), ActionCast, id=unknown
            // +Callback Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=SOZAIRARZAI
            // +Callback Scene00015: Normal(None), id=SOZAIRARZAI
          }
          break;
        }
        if( param1 == 3929588 ) // EVENTRANGE0 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 3931777 ) // ENEMY0 = unknown
        {
        // empty entry
          break;
        }
        if( param1 == 3931779 ) // ENEMY1 = unknown
        {
        // empty entry
          break;
        }
        if( param1 == 1002640 ) // ACTOR1 = SEVRIN
        {
          Scene00017( quest, player ); // Scene00017: Normal(None), id=unknown
          // +Callback Scene00018: Normal(Talk, TargetCanMove), id=SEVRIN
          break;
        }
        if( param1 == 2001279 ) // EOBJECT0 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Normal(None), ActionCast, id=unknown
          // +Callback Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 2000451 ) // EOBJECT1 = unknown
        {
          Scene00021( quest, player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1002640 ) // ACTOR1 = SEVRIN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00024( quest, player ); // Scene00024: Normal(Talk, NpcDespawn, TargetCanMove), id=SEVRIN
          }
          break;
        }
        if( param1 == 2001279 ) // EOBJECT0 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Normal(None), ActionCast, id=unknown
          // +Callback Scene00026: Normal(None), id=unknown
          // +Callback Scene00027: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 2001279 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00028( quest, player ); // Scene00028: Normal(None), ActionCast, id=unknown
            // +Callback Scene00029: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2000449 ) // EOBJECT2 = unknown
        {
          Scene00030( quest, player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 1
      //seq 5 event item ITEM1 = UI8BL max stack 1
      case 5:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00033( quest, player ); // Scene00033: NpcTrade(Talk, TargetCanMove), id=OSSINE
        // +Callback Scene00034: Normal(Talk, TargetCanMove), id=OSSINE
        // +Callback Scene00035: Normal(None), id=unknown
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      case 255:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00036( quest, player ); // Scene00036: NpcTrade(Talk, TargetCanMove), id=STAELWYRN
        // +Callback Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=STAELWYRN
        // +Callback Scene00038: Normal(None), id=unknown
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
    if( quest.getUI8AL() == 3 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setBitFlag8( 2, false );
      quest.setBitFlag8( 3, false );
      quest.setSeq( 3 );
    }
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
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
      quest.setSeq( 5 );
      quest.setUI8BH( 1 );
      quest.setUI8BL( 1 );
    }
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove, SystemTalk, CanCancel), id=STAELWYRN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        checkProgressSeq0( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }

  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1(Todo:0), Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00001: Normal(Talk, TargetCanMove), id=SEVRIN" );
    eventMgr().playQuestScene( player, getId(), 1, NONE, nullptr );
  }
  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1(Todo:0), Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00002: Normal(Talk, TargetCanMove), id=SEVRIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }
  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1(Todo:0), Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00003: Normal(None), id=unknown" );
    eventMgr().playQuestScene( player, getId(), 3, NONE, nullptr );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00004: Normal(None), ActionCast, id=unknown" );
    eventMgr().eventActionStart( player, getId(), 16, [ & ]( Entity::Player& player, uint32_t eventId, uint64_t additional )
    {
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00005( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
    }, nullptr, getId() );
  }
  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00005: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00006( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }
  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00006: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 3(Todo:1), Flag8(1)=True
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00007: Normal(None), ActionCast, id=unknown" );
    eventMgr().eventActionStart( player, getId(), 35, [ & ]( Entity::Player& player, uint32_t eventId, uint64_t additional )
    {
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00008( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
    }, nullptr, getId() );
  }
  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 3(Todo:1), Flag8(1)=True
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=AYLMER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00009( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }
  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 3(Todo:1), Flag8(1)=True
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00009: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 3 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 3(Todo:1), Flag8(2)=True
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00010: Normal(None), ActionCast, id=unknown" );
    eventMgr().eventActionStart( player, getId(), 35, [ & ]( Entity::Player& player, uint32_t eventId, uint64_t additional )
    {
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00011( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
    }, nullptr, getId() );
  }
  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 3(Todo:1), Flag8(2)=True
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=EYRIMHUS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00012( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }
  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 3(Todo:1), Flag8(2)=True
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00012: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 3 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 3(Todo:1), Flag8(3)=True
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00013: Normal(None), ActionCast, id=unknown" );
    eventMgr().eventActionStart( player, getId(), 35, [ & ]( Entity::Player& player, uint32_t eventId, uint64_t additional )
    {
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00014( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
    }, nullptr, getId() );
  }
  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 3(Todo:1), Flag8(3)=True
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=SOZAIRARZAI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00015( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }
  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 3(Todo:1), Flag8(3)=True
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00015: Normal(None), id=SOZAIRARZAI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 3 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: EVENTRANGE0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00016: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }



  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00017: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00018( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }
  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00018: Normal(Talk, TargetCanMove), id=SEVRIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00019: Normal(None), ActionCast, id=unknown" );
    eventMgr().eventActionStart( player, getId(), 16, [ & ]( Entity::Player& player, uint32_t eventId, uint64_t additional )
    {
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00020( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
    }, nullptr, getId() );
  }
  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00020: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00021: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR1, UI8AL = 1(Todo:2), Flag8(1)=True
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00024: Normal(Talk, NpcDespawn, TargetCanMove), id=SEVRIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00025: Normal(None), ActionCast, id=unknown" );
    eventMgr().eventActionStart( player, getId(), 16, [ & ]( Entity::Player& player, uint32_t eventId, uint64_t additional )
    {
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00026( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
    }, nullptr, getId() );
  }
  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00026: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00027( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }
  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00027: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT0, UI8AL = 1(Todo:3), Flag8(1)=True
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00028: Normal(None), ActionCast, id=unknown" );
    eventMgr().eventActionStart( player, getId(), 16, [ & ]( Entity::Player& player, uint32_t eventId, uint64_t additional )
    {
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00029( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
    }, nullptr, getId() );
  }
  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT0, UI8AL = 1(Todo:3), Flag8(1)=True
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00029: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00030: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_5: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00033: NpcTrade(Talk, TargetCanMove), id=OSSINE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00034( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 33, NONE, callback );
  }
  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_5: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00034: Normal(Talk, TargetCanMove), id=OSSINE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00035( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 34, NONE, callback );
  }
  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_5: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00035: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 35, NONE, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00036: NpcTrade(Talk, TargetCanMove), id=STAELWYRN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00037( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 36, NONE, callback );
  }
  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=STAELWYRN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00038( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 37, NONE, callback );
  }
  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea054:66002 calling Scene00038: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      player.finishQuest( getId(), result.getResult( 1 ) );
    };
    eventMgr().playQuestScene( player, getId(), 38, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea054 );
