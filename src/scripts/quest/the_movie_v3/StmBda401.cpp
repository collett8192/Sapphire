// FFXIVTheMovie.ParserV3.11
// param used:
//_ACTOR3 = B
//_ACTOR3B = 1|2
//_ACTOR4 = B
//_ACTOR4B = 1|2
//_ACTOR5 = B
//_ACTOR5B = 1|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda401 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda401() : Sapphire::ScriptAPI::QuestScript( 68036 ){}; 
  ~StmBda401() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 6 entries
  //SEQ_2, 8 entries
  //SEQ_3, 5 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1020079
  //ACTOR1 = 1020080
  //ACTOR10 = 1020506
  //ACTOR2 = 1020081
  //ACTOR3 = 1019355
  //ACTOR4 = 1019353
  //ACTOR5 = 1019349
  //ACTOR6 = 1019376
  //ACTOR7 = 1020281
  //ACTOR8 = 1019360
  //ACTOR9 = 1020275
  //LOCACTOR1 = 6790085
  //LOCACTOR2 = 6790084
  //LOCACTORYASAI = 6665305

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
        if( param1 == 1020079 ) // ACTOR0 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=YUGIRI
          }
          break;
        }
        if( param1 == 1020080 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020081 ) // ACTOR2 = GOSETSU
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019355 ) // ACTOR3 = CHAMBUI, CB=2
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=CHAMBUI
          }
          else
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=CHAMBUI
          }
          break;
        }
        if( param1 == 1019353 ) // ACTOR4 = YESUI, CB=2
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=YESUI
          }
          else
          {
            Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=YESUI
          }
          break;
        }
        if( param1 == 1019349 ) // ACTOR5 = BAIDUR, CB=2
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=BAIDUR
          }
          else
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=BAIDUR
          }
          break;
        }
        if( param1 == 1019376 ) // ACTOR6 = UCUGEN
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=UCUGEN
          break;
        }
        if( param1 == 1020281 ) // ACTOR7 = CIRINA
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1019360 ) // ACTOR8 = NARENGAWA
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=NARENGAWA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020275 ) // ACTOR9 = GORO02500
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove, SystemTalk), id=GORO02500
          }
          break;
        }
        if( param1 == 1019376 ) // ACTOR6 = UCUGEN
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=UCUGEN
          break;
        }
        if( param1 == 1019360 ) // ACTOR8 = NARENGAWA
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=NARENGAWA
          break;
        }
        if( param1 == 1020281 ) // ACTOR7 = CIRINA
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1020506 ) // ACTOR10 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019355 ) // ACTOR3 = CHAMBUI
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=CHAMBUI
          break;
        }
        if( param1 == 1019353 ) // ACTOR4 = YESUI
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=YESUI
          break;
        }
        if( param1 == 1019349 ) // ACTOR5 = BAIDUR
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=BAIDUR
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020281 ) // ACTOR7 = CIRINA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=CIRINA
            // +Callback Scene00022: Normal(Talk, TargetCanMove), id=CIRINA
            // +Callback Scene00023: Normal(Talk, TargetCanMove), id=CIRINA
          }
          break;
        }
        if( param1 == 1019360 ) // ACTOR8 = NARENGAWA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=NARENGAWA
            // +Callback Scene00025: Normal(Talk, TargetCanMove, CanCancel), id=NARENGAWA
            // +Callback Scene00026: Normal(Talk, TargetCanMove), id=NARENGAWA
          }
          break;
        }
        if( param1 == 1019376 ) // ACTOR6 = UCUGEN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=UCUGEN
            // +Callback Scene00028: Normal(Talk, TargetCanMove, CanCancel), id=UCUGEN
            // +Callback Scene00029: Normal(Talk, TargetCanMove), id=UCUGEN
          }
          break;
        }
        if( param1 == 1020275 ) // ACTOR9 = GORO02500
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=GORO02500
          break;
        }
        if( param1 == 1020506 ) // ACTOR10 = unknown
        {
          Scene00031( quest, player ); // Scene00031: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020281 ) // ACTOR7 = CIRINA
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=CIRINA
          break;
        }
        if( param1 == 1019360 ) // ACTOR8 = NARENGAWA
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=NARENGAWA
          break;
        }
        if( param1 == 1019376 ) // ACTOR6 = UCUGEN
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=UCUGEN
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
    if( quest.getUI8AL() == 3 )
    {
      quest.setUI8AL( 0 );
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
      quest.setBitFlag8( 2, false );
      quest.setBitFlag8( 3, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 3, Flag8(1)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00004: Normal(Talk, TargetCanMove), id=CHAMBUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 3 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }
  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 3, Flag8(1)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00005: Normal(Talk, TargetCanMove), id=CHAMBUI" );
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, nullptr );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 3, Flag8(2)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00006: Normal(Talk, TargetCanMove), id=YESUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 2, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 3 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }
  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 3, Flag8(2)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00007: Normal(Talk, TargetCanMove), id=YESUI" );
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, nullptr );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 3, Flag8(3)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00008: Normal(Talk, TargetCanMove), id=BAIDUR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 3, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 3 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }
  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 3, Flag8(3)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00009: Normal(Talk, TargetCanMove), id=BAIDUR" );
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, nullptr );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00010: Normal(Talk, TargetCanMove), id=UCUGEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00011: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00012: Normal(Talk, TargetCanMove), id=NARENGAWA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00013: Normal(Talk, TargetCanMove, SystemTalk), id=GORO02500" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00014: Normal(Talk, TargetCanMove), id=UCUGEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00015: Normal(Talk, TargetCanMove), id=NARENGAWA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00016: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00017: Empty(None), id=unknown" );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00018: Normal(Talk, TargetCanMove), id=CHAMBUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00019: Normal(Talk, TargetCanMove), id=YESUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00020: Normal(Talk, TargetCanMove), id=BAIDUR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00021: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00022( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }
  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00022: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00023( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }
  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00023: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(2)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00024: Normal(Talk, TargetCanMove), id=NARENGAWA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00025( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }
  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(2)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00025: Normal(Talk, TargetCanMove, CanCancel), id=NARENGAWA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00026( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }
  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(2)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00026: Normal(Talk, TargetCanMove), id=NARENGAWA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, UI8AL = 1, Flag8(3)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00027: Normal(Talk, TargetCanMove), id=UCUGEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00028( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }
  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, UI8AL = 1, Flag8(3)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00028: Normal(Talk, TargetCanMove, CanCancel), id=UCUGEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00029( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }
  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, UI8AL = 1, Flag8(3)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00029: Normal(Talk, TargetCanMove), id=UCUGEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 3, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00030: Normal(Talk, TargetCanMove), id=GORO02500" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00031: Empty(None), id=unknown" );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00032: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 32, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00033: Normal(Talk, TargetCanMove), id=NARENGAWA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda401:68036 calling Scene00034: Normal(Talk, TargetCanMove), id=UCUGEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda401 );
