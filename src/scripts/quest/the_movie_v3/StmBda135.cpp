// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda135 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda135() : Sapphire::ScriptAPI::QuestScript( 68001 ){}; 
  ~StmBda135() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 12 entries
  //SEQ_2, 15 entries
  //SEQ_255, 11 entries

  //ACTOR0 = 1020420
  //ACTOR1 = 1020414
  //ACTOR10 = 1020425
  //ACTOR11 = 1020412
  //ACTOR12 = 1020419
  //ACTOR2 = 1020415
  //ACTOR3 = 1020416
  //ACTOR4 = 1020417
  //ACTOR5 = 1019965
  //ACTOR6 = 1019486
  //ACTOR7 = 1020422
  //ACTOR8 = 1020423
  //ACTOR9 = 1020424
  //EOBJECT0 = 2008158
  //EOBJECT1 = 2008159
  //EOBJECT2 = 2008160
  //EVENTACTION0 = 23
  //ITEM0 = 2002110
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1017687
  //LOCACTOR03 = 1018509
  //LOCACTOR04 = 1015903
  //LOCACTOR05 = 1019082
  //LOCACTOR06 = 1015833
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //LOCSE01 = 151

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
        if( param1 == 1020420 ) // ACTOR0 = PIPIN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=PIPIN
          }
          break;
        }
        if( param1 == 1020414 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020415 ) // ACTOR2 = unknown
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1020416 ) // ACTOR3 = CONRAD
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020417 ) // ACTOR4 = KRILE
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1019965 ) // ACTOR5 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019486 ) // ACTOR6 = ORELLA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ORELLA
          }
          break;
        }
        if( param1 == 1020422 ) // ACTOR7 = FLAMECOURIER
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=FLAMECOURIER
          break;
        }
        if( param1 == 1020423 ) // ACTOR8 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020424 ) // ACTOR9 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020425 ) // ACTOR10 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020412 ) // ACTOR11 = ALPHINAUD
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020414 ) // ACTOR1 = LYSE
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020415 ) // ACTOR2 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1020416 ) // ACTOR3 = CONRAD
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020417 ) // ACTOR4 = KRILE
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1020419 ) // ACTOR12 = ALISAIE
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1019965 ) // ACTOR5 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 3
      case 2:
      {
        if( param1 == 2008158 ) // EOBJECT0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00020( quest, player ); // Scene00020: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008159 ) // EOBJECT1 = unknown
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008160 ) // EOBJECT2 = unknown
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00024( quest, player ); // Scene00024: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1020422 ) // ACTOR7 = FLAMECOURIER
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=FLAMECOURIER
          break;
        }
        if( param1 == 1020423 ) // ACTOR8 = unknown
        {
          Scene00026( quest, player ); // Scene00026: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020424 ) // ACTOR9 = unknown
        {
          Scene00027( quest, player ); // Scene00027: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020425 ) // ACTOR10 = unknown
        {
          Scene00028( quest, player ); // Scene00028: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020412 ) // ACTOR11 = ALPHINAUD
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020414 ) // ACTOR1 = LYSE
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020415 ) // ACTOR2 = unknown
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1020416 ) // ACTOR3 = CONRAD
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020417 ) // ACTOR4 = KRILE
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1020419 ) // ACTOR12 = ALISAIE
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1019965 ) // ACTOR5 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019486 ) // ACTOR6 = ORELLA
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=ORELLA
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        if( param1 == 1020422 ) // ACTOR7 = unknown
        {
          Scene00037( quest, player ); // Scene00037: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00038: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown
          break;
        }
        if( param1 == 1020423 ) // ACTOR8 = unknown
        {
          Scene00039( quest, player ); // Scene00039: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020424 ) // ACTOR9 = unknown
        {
          Scene00040( quest, player ); // Scene00040: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020425 ) // ACTOR10 = unknown
        {
          Scene00041( quest, player ); // Scene00041: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020412 ) // ACTOR11 = ALPHINAUD
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020414 ) // ACTOR1 = LYSE
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020415 ) // ACTOR2 = unknown
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1020416 ) // ACTOR3 = CONRAD
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020417 ) // ACTOR4 = KRILE
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1020419 ) // ACTOR12 = ALISAIE
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1019965 ) // ACTOR5 = unknown
        {
          Scene00048( quest, player ); // Scene00048: Empty(None), id=unknown
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
    if( quest.getUI8AL() == 3 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setBitFlag8( 2, false );
      quest.setBitFlag8( 3, false );
      quest.setSeq( 255 );
      quest.setUI8BH( 3 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00003: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00004: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00005: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00006: Empty(None), id=unknown" );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00007: Normal(Talk, TargetCanMove), id=ORELLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00008: Normal(Talk, TargetCanMove), id=FLAMECOURIER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00009: Empty(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00010: Empty(None), id=unknown" );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00011: Empty(None), id=unknown" );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00014: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00015: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00016: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00018: Empty(None), id=unknown" );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 3, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00020: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 3 );
    checkProgressSeq2( quest, player );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, UI8AL = 3, Flag8(2)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00022: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 2, true );
    eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 3 );
    checkProgressSeq2( quest, player );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT2, UI8AL = 3, Flag8(3)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00024: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 3, true );
    eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 3 );
    checkProgressSeq2( quest, player );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00025: Normal(Talk, TargetCanMove), id=FLAMECOURIER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00026: Empty(None), id=unknown" );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00027: Empty(None), id=unknown" );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00028: Empty(None), id=unknown" );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00030: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00031: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00032: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00033: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00034: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00035: Empty(None), id=unknown" );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00036: Normal(Talk, TargetCanMove), id=ORELLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00037: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00038( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }
  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00038: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 38, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00039: Empty(None), id=unknown" );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00040: Empty(None), id=unknown" );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00041: Empty(None), id=unknown" );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00042: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00043: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, HIDE_HOTBAR, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00044: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00045: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00046: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, HIDE_HOTBAR, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, HIDE_HOTBAR, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda135:68001 calling Scene00048: Empty(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda135 );
