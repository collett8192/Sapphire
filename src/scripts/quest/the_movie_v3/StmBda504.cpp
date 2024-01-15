// FFXIVTheMovie.ParserV3.12
// param used:
//_ACTOR5 = B
//_ACTOR5B = 1|2
//_ACTOR6 = B
//_ACTOR6B = 1|2
//_ACTOR7 = B
//_ACTOR7B = 1|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda504 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda504() : Sapphire::ScriptAPI::QuestScript( 68058 ){}; 
  ~StmBda504() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 8 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_4, 6 entries
  //SEQ_5, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1020234
  //ACTOR1 = 1020233
  //ACTOR10 = 1020238
  //ACTOR11 = 1020239
  //ACTOR2 = 1020232
  //ACTOR3 = 1020519
  //ACTOR4 = 1020523
  //ACTOR5 = 1019285
  //ACTOR6 = 1019286
  //ACTOR7 = 1019287
  //ACTOR8 = 1023083
  //ACTOR9 = 1020237
  //EOBJECT0 = 2007931
  //EVENTACTION0 = 1
  //ITEM0 = 2002178
  //LOCBGM01 = 489

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
        if( param1 == 1020234 ) // ACTOR0 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020233 ) // ACTOR1 = ISSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1020232 ) // ACTOR2 = TSURANUKI
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019285 ) // ACTOR5 = HANAME, CB=2
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=HANAME
          }
          else
          {
            Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=HANAME
          }
          break;
        }
        if( param1 == 1019286 ) // ACTOR6 = KAIDATE, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=KAIDATE
          }
          else
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=KAIDATE
          }
          break;
        }
        if( param1 == 1019287 ) // ACTOR7 = MOTOJIRO, CB=2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=MOTOJIRO
          }
          else
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=MOTOJIRO
          }
          break;
        }
        if( param1 == 1020232 ) // ACTOR2 = TSURANUKI
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020233 ) // ACTOR1 = ISSE
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1020234 ) // ACTOR0 = LYSE
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1023083 ) // ACTOR8 = HIEN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00017( quest, player ); // Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1019285 ) // ACTOR5 = HANAME
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=HANAME
          break;
        }
        if( param1 == 1019286 ) // ACTOR6 = KAIDATE
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=KAIDATE
          break;
        }
        if( param1 == 1019287 ) // ACTOR7 = MOTOJIRO
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=MOTOJIRO
          break;
        }
        if( param1 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020237 ) // ACTOR9 = HIEN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00023( quest, player ); // Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1019285 ) // ACTOR5 = HANAME
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=HANAME
          break;
        }
        if( param1 == 1019286 ) // ACTOR6 = KAIDATE
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=KAIDATE
          break;
        }
        if( param1 == 1019287 ) // ACTOR7 = MOTOJIRO
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=MOTOJIRO
          break;
        }
        if( param1 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020238 ) // ACTOR10 = HIEN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00029( quest, player ); // Scene00029: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1019285 ) // ACTOR5 = HANAME
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=HANAME
          break;
        }
        if( param1 == 1019286 ) // ACTOR6 = KAIDATE
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=KAIDATE
          break;
        }
        if( param1 == 1019287 ) // ACTOR7 = MOTOJIRO
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=MOTOJIRO
          break;
        }
        if( param1 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 1
      case 5:
      {
        if( param1 == 2007931 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00036( quest, player ); // Scene00036: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1019285 ) // ACTOR5 = HANAME
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=HANAME
          break;
        }
        if( param1 == 1019286 ) // ACTOR6 = KAIDATE
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=KAIDATE
          break;
        }
        if( param1 == 1019287 ) // ACTOR7 = MOTOJIRO
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=MOTOJIRO
          break;
        }
        if( param1 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1020239 ) // ACTOR11 = HIEN
        {
          Scene00042( quest, player ); // Scene00042: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00043: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1019285 ) // ACTOR5 = HANAME
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=HANAME
          break;
        }
        if( param1 == 1019286 ) // ACTOR6 = KAIDATE
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=KAIDATE
          break;
        }
        if( param1 == 1019287 ) // ACTOR7 = MOTOJIRO
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=MOTOJIRO
          break;
        }
        if( param1 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=YUGIRI
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
      quest.setSeq( 255 );
      quest.setUI8BH( 1 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00002: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00003: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8BL = 1, Flag8(1)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00006: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }
  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8BL = 1, Flag8(1)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00007: Normal(Talk, TargetCanMove), id=HANAME" );
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, nullptr );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00008: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }
  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00009: Normal(Talk, TargetCanMove), id=KAIDATE" );
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, nullptr );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00010: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }
  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00011: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, nullptr );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00012: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00013: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00014: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00018: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00019: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00020: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00022: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00024: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00025: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00026: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00028: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00029: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00030: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00031: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00032: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00033: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00034: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00036: Empty(None), id=unknown" );
    quest.setUI8AL( 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
    checkProgressSeq5( quest, player );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00037: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00038: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, HIDE_HOTBAR, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00039: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, HIDE_HOTBAR, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00040: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, HIDE_HOTBAR, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00041: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, HIDE_HOTBAR, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00042: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00043( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }
  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00043: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 43, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00044: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00045: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00046: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, HIDE_HOTBAR, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, HIDE_HOTBAR, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda504:68058 calling Scene00048: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda504 );
