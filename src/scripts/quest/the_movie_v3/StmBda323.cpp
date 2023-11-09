// FFXIVTheMovie.ParserV3.11
// param used:
//_ACTOR10 = B
//_ACTOR10B = 2|2
//_ACTOR11 = B
//_ACTOR11B = 2|2
//_ACTOR12 = B
//_ACTOR12B = 2|2
//_ACTOR13 = B
//_ACTOR13B = 2|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda323 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda323() : Sapphire::ScriptAPI::QuestScript( 68035 ){}; 
  ~StmBda323() = default; 

  //SEQ_0, 9 entries
  //SEQ_1, 9 entries
  //SEQ_2, 7 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1020059
  //ACTOR1 = 1020057
  //ACTOR10 = 1020063
  //ACTOR11 = 1020064
  //ACTOR12 = 1020065
  //ACTOR13 = 1020066
  //ACTOR14 = 1020067
  //ACTOR15 = 1023080
  //ACTOR16 = 1023081
  //ACTOR2 = 1020058
  //ACTOR3 = 1020189
  //ACTOR4 = 1020060
  //ACTOR5 = 1020061
  //ACTOR6 = 1023077
  //ACTOR7 = 1023078
  //ACTOR8 = 1023079
  //ACTOR9 = 1020062
  //BINDACTOR0 = 6782495
  //BINDACTOR1 = 6782494
  //LOCACTOR0 = 1018509
  //LOCACTOR1 = 1019096
  //LOCACTOR2 = 1019710
  //LOCACTOR3 = 1018977
  //NCUT01 = 1432
  //NCUT02 = 1433
  //NCUT03 = 1434

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
        if( param1 == 1020059 ) // ACTOR0 = ISSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ISSE
          }
          break;
        }
        if( param1 == 1020057 ) // ACTOR1 = ALISAIE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020058 ) // ACTOR2 = GOSETSU
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020189 ) // ACTOR3 = YUGIRI
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020060 ) // ACTOR4 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020061 ) // ACTOR5 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023077 ) // ACTOR6 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023078 ) // ACTOR7 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023079 ) // ACTOR8 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020062 ) // ACTOR9 = ISSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=ISSE
            // +Callback Scene00011: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1020057 ) // ACTOR1 = ALISAIE
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020058 ) // ACTOR2 = GOSETSU
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020189 ) // ACTOR3 = YUGIRI
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020060 ) // ACTOR4 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020061 ) // ACTOR5 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023077 ) // ACTOR6 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023078 ) // ACTOR7 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023079 ) // ACTOR8 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020063 ) // ACTOR10 = YUGIRI, CB=2
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI
          }
          else
          {
            Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1020064 ) // ACTOR11 = GOSETSU, CB=2
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=GOSETSU
          }
          else
          {
            Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=GOSETSU
          }
          break;
        }
        if( param1 == 1020065 ) // ACTOR12 = LYSE, CB=2
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=LYSE
          }
          else
          {
            Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020066 ) // ACTOR13 = ALISAIE, CB=2
        {
          if( !quest.getBitFlag8( 4 ) )
          {
            Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove, ENpcBind), id=ALISAIE
          }
          else
          {
            Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1020067 ) // ACTOR14 = ALPHINAUD
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1023080 ) // ACTOR15 = unknown
        {
          Scene00029( quest, player ); // Scene00029: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023081 ) // ACTOR16 = unknown
        {
          Scene00030( quest, player ); // Scene00030: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020067 ) // ACTOR14 = ALPHINAUD
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=ALPHINAUD
          // +Callback Scene00032: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1020063 ) // ACTOR10 = YUGIRI
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020064 ) // ACTOR11 = GOSETSU
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020065 ) // ACTOR12 = LYSE
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020066 ) // ACTOR13 = ALISAIE
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1023080 ) // ACTOR15 = unknown
        {
          Scene00037( quest, player ); // Scene00037: Empty(None), id=unknown
          break;
        }
        if( param1 == 1023081 ) // ACTOR16 = unknown
        {
          Scene00038( quest, player ); // Scene00038: Empty(None), id=unknown
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
    if( quest.getUI8AL() == 4 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setBitFlag8( 2, false );
      quest.setBitFlag8( 3, false );
      quest.setBitFlag8( 4, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00005: Empty(None), id=unknown" );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00006: Empty(None), id=unknown" );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00007: Empty(None), id=unknown" );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00008: Empty(None), id=unknown" );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00009: Empty(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00010: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00011( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }
  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00011: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00016: Empty(None), id=unknown" );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00017: Empty(None), id=unknown" );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00018: Empty(None), id=unknown" );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00019: Empty(None), id=unknown" );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, UI8AL = 4, Flag8(1)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 4 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }
  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, UI8AL = 4, Flag8(1)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00021: Normal(Talk, TargetCanMove), id=YUGIRI" );
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, nullptr );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, UI8AL = 4, Flag8(2)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00022: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 2, true );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 4 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }
  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, UI8AL = 4, Flag8(2)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00023: Normal(Talk, TargetCanMove), id=GOSETSU" );
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, nullptr );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, UI8AL = 4, Flag8(3)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00024: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 3, true );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 4 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }
  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, UI8AL = 4, Flag8(3)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00025: Normal(Talk, TargetCanMove), id=LYSE" );
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, nullptr );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, UI8AL = 4, Flag8(4)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00026: Normal(Talk, TargetCanMove, ENpcBind), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 4, true );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 4 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }
  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, UI8AL = 4, Flag8(4)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00027: Normal(Talk, TargetCanMove), id=ALISAIE" );
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, nullptr );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00029: Empty(None), id=unknown" );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00030: Empty(None), id=unknown" );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00031: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00032( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 31, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00032: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      player.finishQuest( getId(), result.getResult( 1 ) );
    };
    eventMgr().playQuestScene( player, getId(), 32, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00034: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00035: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, HIDE_HOTBAR, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00036: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00037: Empty(None), id=unknown" );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda323:68035 calling Scene00038: Empty(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda323 );
