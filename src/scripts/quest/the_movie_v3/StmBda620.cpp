// FFXIVTheMovie.ParserV3.12
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda620 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda620() : Sapphire::ScriptAPI::QuestScript( 68082 ){}; 
  ~StmBda620() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 5 entries
  //SEQ_4, 10 entries
  //SEQ_5, 7 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1020656
  //ACTOR1 = 1020655
  //ACTOR10 = 1022360
  //ACTOR11 = 1022361
  //ACTOR12 = 1020658
  //ACTOR13 = 1020659
  //ACTOR14 = 1022362
  //ACTOR15 = 1020660
  //ACTOR2 = 1020650
  //ACTOR3 = 1020651
  //ACTOR4 = 1020652
  //ACTOR5 = 1022370
  //ACTOR6 = 1022371
  //ACTOR7 = 1020662
  //ACTOR8 = 1020653
  //ACTOR9 = 1020657
  //BINDACTOR01 = 6859092
  //CUTSCENEN01 = 1477
  //ENEMY0 = 7005952
  //ENEMY1 = 7021942
  //ENEMY2 = 7005954
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1018509
  //LOCACTOR03 = 1021989

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
        if( param1 == 1020656 ) // ACTOR0 = RAUBAHN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn), id=RAUBAHN
            // +Callback Scene00002: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1020655 ) // ACTOR1 = LYSE
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020650 ) // ACTOR2 = SERPENTOFFICER
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020651 ) // ACTOR3 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020652 ) // ACTOR4 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1022370 ) // ACTOR5 = RAUBAHN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00007( quest, player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1020650 ) // ACTOR2 = SERPENTOFFICER
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020651 ) // ACTOR3 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020652 ) // ACTOR4 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022371 ) // ACTOR6 = LYSE
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1022371 ) // ACTOR6 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00012( quest, player ); // Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020650 ) // ACTOR2 = SERPENTOFFICER
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020651 ) // ACTOR3 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020652 ) // ACTOR4 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020662 ) // ACTOR7 = RAUBAHN
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020653 ) // ACTOR8 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00017( quest, player ); // Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020650 ) // ACTOR2 = SERPENTOFFICER
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020651 ) // ACTOR3 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020652 ) // ACTOR4 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020662 ) // ACTOR7 = RAUBAHN
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020657 ) // ACTOR9 = HIGHLANDER
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00022( quest, player ); // Scene00022: Normal(Talk, Message, PopBNpc, TargetCanMove), id=HIGHLANDER
          }
          break;
        }
        // BNpcHack credit moved to ACTOR9
        if( param1 == 7005952 ) // ENEMY0 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7021942 ) // ENEMY1 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7005954 ) // ENEMY2 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1020650 ) // ACTOR2 = SERPENTOFFICER
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020651 ) // ACTOR3 = unknown
        {
          Scene00027( quest, player ); // Scene00027: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020652 ) // ACTOR4 = unknown
        {
          Scene00028( quest, player ); // Scene00028: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022360 ) // ACTOR10 = unknown
        {
          Scene00029( quest, player ); // Scene00029: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022361 ) // ACTOR11 = unknown
        {
          Scene00030( quest, player ); // Scene00030: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020662 ) // ACTOR7 = RAUBAHN
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1020658 ) // ACTOR12 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00032( quest, player ); // Scene00032: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020650 ) // ACTOR2 = SERPENTOFFICER
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020651 ) // ACTOR3 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020652 ) // ACTOR4 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020659 ) // ACTOR13 = unknown
        {
          Scene00036( quest, player ); // Scene00036: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022362 ) // ACTOR14 = unknown
        {
          Scene00037( quest, player ); // Scene00037: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020662 ) // ACTOR7 = RAUBAHN
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020660 ) // ACTOR15 = MNAAGO
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020651 ) // ACTOR3 = unknown
        {
          Scene00040( quest, player ); // Scene00040: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020652 ) // ACTOR4 = unknown
        {
          Scene00041( quest, player ); // Scene00041: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020659 ) // ACTOR13 = unknown
        {
          Scene00042( quest, player ); // Scene00042: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022362 ) // ACTOR14 = unknown
        {
          Scene00043( quest, player ); // Scene00043: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020662 ) // ACTOR7 = RAUBAHN
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=RAUBAHN
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
    if( quest.getUI8AL() == 3 )
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
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00002( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }
  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00005: Empty(None), id=unknown" );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00006: Empty(None), id=unknown" );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00008: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00009: Empty(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00010: Empty(None), id=unknown" );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00011: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00013: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00014: Empty(None), id=unknown" );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00016: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00018: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00019: Empty(None), id=unknown" );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00020: Empty(None), id=unknown" );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00021: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, UI8AL = 3, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00022: Normal(Talk, Message, PopBNpc, TargetCanMove), id=HIGHLANDER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 3 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 2, quest.getUI8AL(), 3 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_4: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00023: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_4: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00024: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_4: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00025: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00026: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00027: Empty(None), id=unknown" );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00028: Empty(None), id=unknown" );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00029: Empty(None), id=unknown" );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00030: Empty(None), id=unknown" );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00031: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR12, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00032: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00033: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00034: Empty(None), id=unknown" );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00035: Empty(None), id=unknown" );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00036: Empty(None), id=unknown" );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00037: Empty(None), id=unknown" );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00038: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, HIDE_HOTBAR, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00039: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 39, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00040: Empty(None), id=unknown" );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00041: Empty(None), id=unknown" );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00042: Empty(None), id=unknown" );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00043: Empty(None), id=unknown" );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda620:68082 calling Scene00044: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda620 );
