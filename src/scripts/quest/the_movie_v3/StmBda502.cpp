// FFXIVTheMovie.ParserV3.11
// param used:
//EOBJECT0 = dummye0
//EOBJECT1 = dummye1
//SCENE_8 = dummye0
//SCENE_13 = dummye1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda502 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda502() : Sapphire::ScriptAPI::QuestScript( 68056 ){}; 
  ~StmBda502() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_4, 4 entries
  //SEQ_5, 7 entries
  //SEQ_6, 10 entries
  //SEQ_7, 4 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1020519
  //ACTOR1 = 1020520
  //ACTOR10 = 1020273
  //ACTOR11 = 1019934
  //ACTOR12 = 1020521
  //ACTOR13 = 1023091
  //ACTOR2 = 1020523
  //ACTOR3 = 1020226
  //ACTOR4 = 1020227
  //ACTOR5 = 1020228
  //ACTOR6 = 1020229
  //ACTOR7 = 1020230
  //ACTOR8 = 1020271
  //ACTOR9 = 1020272
  //BINDALISAIE001 = 6843996
  //BINDALISAIE002 = 6843998
  //BINDEMPIRE001 = 6869169
  //BINDEMPIRE002 = 6869170
  //ENEMY0 = 6848182
  //ENEMY1 = 6869167
  //EOBJECT0 = 2007923
  //EOBJECT1 = 2007924
  //EOBJECT2 = 2007925
  //EVENTACTION0 = 50
  //EVENTRANGE0 = 6869459
  //NCUTEVENT05010 = 1493

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
        if( param1 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020520 ) // ACTOR1 = ALISAIE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2007923 ) // EOBJECT0 = dummye0
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, ENpcBind), id=dummye0
          }
          break;
        }
        if( param1 == 1020226 ) // ACTOR3 = ALISAIE
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2007924 ) // EOBJECT1 = dummye1
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, ENpcBind), id=dummye1
          }
          break;
        }
        if( param1 == 1020227 ) // ACTOR4 = ALISAIE
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020228 ) // ACTOR5 = ALISAIE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove, Menu), id=ALISAIE
          }
          break;
        }
        if( param1 == 1020229 ) // ACTOR6 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1020230 ) // ACTOR7 = HENSO02520
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00021( quest, player ); // Scene00021: Normal(Talk, NpcDespawn, TargetCanMove), id=HENSO02520
          }
          break;
        }
        if( param1 == 1020271 ) // ACTOR8 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020272 ) // ACTOR9 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020228 ) // ACTOR5 = ALISAIE
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020229 ) // ACTOR6 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 6869459 ) // EVENTRANGE0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00028( quest, player ); // Scene00028: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EVENTRANGE0
        if( param1 == 6848182 ) // ENEMY0 = unknown
        {
          Scene00029( quest, player ); // Scene00029: Empty(None), id=unknown
          break;
        }
        if( param1 == 6869167 ) // ENEMY1 = unknown
        {
          Scene00030( quest, player ); // Scene00030: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020271 ) // ACTOR8 = unknown
        {
          Scene00031( quest, player ); // Scene00031: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020272 ) // ACTOR9 = unknown
        {
          Scene00032( quest, player ); // Scene00032: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020228 ) // ACTOR5 = ALISAIE
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020229 ) // ACTOR6 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 2007925 ) // EOBJECT2 = unknown
        {
          Scene00037( quest, player ); // Scene00037: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 1020273 ) // ACTOR10 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00038( quest, player ); // Scene00038: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1019934 ) // ACTOR11 = HENSO02520
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=HENSO02520
          break;
        }
        if( param1 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020521 ) // ACTOR12 = LYSE
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1023091 ) // ACTOR13 = unknown
        {
          Scene00046( quest, player ); // Scene00046: Empty(None), id=unknown
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
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
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
    }
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 6 );
    }
  }
  void checkProgressSeq6( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 2 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 7 );
    }
  }
  void checkProgressSeq7( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00003: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00008: Normal(Talk, ENpcBind), id=dummye0" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00013: Normal(Talk, ENpcBind), id=dummye1" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00017: Normal(Talk, TargetCanMove, Menu), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 1, true );
        eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
        checkProgressSeq4( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00018: Empty(None), id=unknown" );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00021: Normal(Talk, NpcDespawn, TargetCanMove), id=HENSO02520" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00022: Empty(None), id=unknown" );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00023: Empty(None), id=unknown" );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00025: Empty(None), id=unknown" );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00027: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_6: EVENTRANGE0, UI8AL = 2, Flag8(1)=True(Todo:5)
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00028: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 2 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 5, 2, quest.getUI8AL(), 2 );
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_6: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00029: Empty(None), id=unknown" );
    checkProgressSeq6( quest, player );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_6: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00030: Empty(None), id=unknown" );
    checkProgressSeq6( quest, player );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00031: Empty(None), id=unknown" );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00032: Empty(None), id=unknown" );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00033: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00034: Empty(None), id=unknown" );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, HIDE_HOTBAR, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00036: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_6: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00037: Empty(None), id=unknown" );
    checkProgressSeq6( quest, player );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR10, UI8AL = 1, Flag8(1)=True(Todo:6)
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00038: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 6, 0, 0, 0 );
      checkProgressSeq7( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 38, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00039: Normal(Talk, TargetCanMove), id=HENSO02520" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, HIDE_HOTBAR, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00040: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, HIDE_HOTBAR, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00041: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, HIDE_HOTBAR, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, HIDE_HOTBAR, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00044: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00045: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda502:68056 calling Scene00046: Empty(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda502 );
