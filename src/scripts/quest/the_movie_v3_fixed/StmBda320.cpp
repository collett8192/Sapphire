// FFXIVTheMovie.ParserV3.11
// param used:
//ACTOR4 = BIGSOLDIER02496
//ACTOR5 = SMALLSOLDIER02496
//ACTOR6 = MIDDLESOLDIER02496
//SCENE_16 = BIGSOLDIER02496
//SCENE_19 = SMALLSOLDIER02496
//SCENE_22 = MIDDLESOLDIER02496
//_ACTOR7 = E
//_ACTOR7E = 5|4,59
//_ACTOR8 = E
//_ACTOR8E = 5|4,59
// fix seq3 progress condition
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda320 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda320() : Sapphire::ScriptAPI::QuestScript( 68032 ){}; 
  ~StmBda320() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_4, 5 entries
  //SEQ_5, 7 entries
  //SEQ_6, 3 entries
  //SEQ_255, 4 entries

  //ACTIONTIMELINEEVENTEMOTELOOKOUTADD = 665
  //ACTIONTIMELINEEVENTEMPIRIALSALUTE = 587
  //ACTOR0 = 1023780
  //ACTOR1 = 1019966
  //ACTOR10 = 1020048
  //ACTOR11 = 1020029
  //ACTOR2 = 1019967
  //ACTOR3 = 1020042
  //ACTOR4 = 1020043
  //ACTOR5 = 1020044
  //ACTOR6 = 1020045
  //ACTOR7 = 1020040
  //ACTOR8 = 1020041
  //ACTOR9 = 1020047
  //BINDACTOR0 = 6782433
  //BINDACTOR1 = 6782434
  //BINDACTOR2 = 6782435
  //BINDACTOR3 = 6782436
  //EOBJECT0 = 2007839
  //EOBJECT1 = 2008909
  //EOBJECT2 = 2008910
  //EVENTACTION0 = 41
  //EVENTACTION1 = 1
  //EVENTACTION2 = 26
  //NCUT01 = 1427
  //RITEM0 = 20597
  //RITEM1 = 20599
  //RITEM2 = 20600
  //RITEM3 = 20596
  //RITEM4 = 20598

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
        if( param1 == 1023780 ) // ACTOR0 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1019966 ) // ACTOR1 = unknown
        {
          Scene00002( quest, player ); // Scene00002: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019967 ) // ACTOR2 = unknown
        {
          Scene00003( quest, player ); // Scene00003: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2007839 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1019966 ) // ACTOR1 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019967 ) // ACTOR2 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020042 ) // ACTOR3 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1019966 ) // ACTOR1 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019967 ) // ACTOR2 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020043 ) // ACTOR4 = BIGSOLDIER02496
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=BIGSOLDIER02496
          break;
        }
        if( param1 == 1020044 ) // ACTOR5 = SMALLSOLDIER02496
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=SMALLSOLDIER02496
          break;
        }
        if( param1 == 1020045 ) // ACTOR6 = MIDDLESOLDIER02496
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=MIDDLESOLDIER02496
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020043 ) // ACTOR4 = BIGSOLDIER02496
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00015( quest, player ); // Scene00015: Normal(SystemTalk, CanCancel), id=unknown
            // +Callback Scene00016: Normal(Talk, FadeIn, SystemTalk, ENpcBind), id=BIGSOLDIER02496
          }
          break;
        }
        if( param1 == 1020044 ) // ACTOR5 = SMALLSOLDIER02496
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00018( quest, player ); // Scene00018: Normal(SystemTalk, CanCancel), id=unknown
            // +Callback Scene00019: Normal(Talk, FadeIn, SystemTalk, ENpcBind), id=SMALLSOLDIER02496
          }
          break;
        }
        if( param1 == 1020045 ) // ACTOR6 = MIDDLESOLDIER02496
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00021( quest, player ); // Scene00021: Normal(SystemTalk, CanCancel), id=unknown
            // +Callback Scene00022: Normal(Talk, FadeIn, SystemTalk, ENpcBind), id=MIDDLESOLDIER02496
          }
          break;
        }
        if( param1 == 1020042 ) // ACTOR3 = YUGIRI
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1019966 ) // ACTOR1 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019967 ) // ACTOR2 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020042 ) // ACTOR3 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1019966 ) // ACTOR1 = unknown
        {
          Scene00027( quest, player ); // Scene00027: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019967 ) // ACTOR2 = unknown
        {
          Scene00028( quest, player ); // Scene00028: Empty(None), id=unknown
          break;
        }
        if( param1 == 2008909 ) // EOBJECT1 = unknown
        {
          Scene00029( quest, player ); // Scene00029: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2008910 ) // EOBJECT2 = unknown
        {
          Scene00030( quest, player ); // Scene00030: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1020040 ) // ACTOR7 = SOLDIERC02495, EB=4(emote=59)
        {
          if( quest.getUI8BH() != 1 )
          {
            if( type == EVENT_ON_TALK ) Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=SOLDIERC02495
            if( type == EVENT_ON_EMOTE )
            {
              if( param3 == 59 ) Scene00032( quest, player ); // Correct Scene00032: Normal(Talk, NpcDespawn, TargetCanMove), id=SOLDIERC02495
              else Scene00033( quest, player ); // Incorrect Scene00033: Normal(Talk, TargetCanMove), id=SOLDIERC02495
            }
            // Extra scene for not meeting requirement, most likely wearing specific gear: Scene00034: Normal(Talk, TargetCanMove), id=SOLDIERC02495
          }
          break;
        }
        if( param1 == 1020041 ) // ACTOR8 = SOLDIERD02496, EB=4(emote=59)
        {
          if( quest.getUI8AL() != 1 )
          {
            if( type == EVENT_ON_TALK ) Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=SOLDIERD02496
            if( type == EVENT_ON_EMOTE )
            {
              if( param3 == 59 ) Scene00036( quest, player ); // Correct Scene00036: Normal(Talk, NpcDespawn, TargetCanMove), id=SOLDIERD02496
              else Scene00037( quest, player ); // Incorrect Scene00037: Normal(Talk, TargetCanMove), id=SOLDIERD02496
            }
            // Extra scene for not meeting requirement, most likely wearing specific gear: Scene00038: Normal(Talk, TargetCanMove), id=SOLDIERD02496
          }
          break;
        }
        if( param1 == 1019966 ) // ACTOR1 = unknown
        {
          Scene00039( quest, player ); // Scene00039: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019967 ) // ACTOR2 = unknown
        {
          Scene00040( quest, player ); // Scene00040: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020042 ) // ACTOR3 = YUGIRI
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 2008909 ) // EOBJECT1 = unknown
        {
          Scene00042( quest, player ); // Scene00042: Normal(SystemTalk, CanCancel), id=unknown
          // +Callback Scene00043: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2008910 ) // EOBJECT2 = unknown
        {
          Scene00044( quest, player ); // Scene00044: Normal(SystemTalk, CanCancel), id=unknown
          // +Callback Scene00045: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1020042 ) // ACTOR3 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1020047 ) // ACTOR9 = SOLDIERC02495
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=SOLDIERC02495
          break;
        }
        if( param1 == 1020048 ) // ACTOR10 = SOLDIERD02496
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=SOLDIERD02496
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020029 ) // ACTOR11 = unknown
        {
          Scene00050( quest, player ); // Scene00050: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1020042 ) // ACTOR3 = YUGIRI
        {
          Scene00051( quest, player ); // Scene00051: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020047 ) // ACTOR9 = SOLDIERC02495
        {
          Scene00052( quest, player ); // Scene00052: Normal(Talk, TargetCanMove), id=SOLDIERC02495
          break;
        }
        if( param1 == 1020048 ) // ACTOR10 = SOLDIERD02496
        {
          Scene00053( quest, player ); // Scene00053: Normal(Talk, TargetCanMove), id=SOLDIERD02496
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
    //if( quest.getUI8BL() == 1 )
    //  if( quest.getUI8AL() == 1 )
    //    if( quest.getUI8BH() == 1 )
    if( quest.getUI8BL() == 1 || quest.getUI8AL() == 1 || quest.getUI8BH() == 1 )
        {
          quest.setUI8BL( 0 );
          quest.setUI8AL( 0 );
          quest.setUI8BH( 0 );
          quest.setBitFlag8( 1, false );
          quest.setBitFlag8( 2, false );
          quest.setBitFlag8( 3, false );
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
    if( quest.getUI8BH() == 1 )
      if( quest.getUI8AL() == 1 )
      {
        quest.setUI8BH( 0 );
        quest.setUI8AL( 0 );
        quest.setBitFlag8( 1, false );
        quest.setBitFlag8( 2, false );
        quest.setSeq( 6 );
      }
  }
  void checkProgressSeq6( World::Quest& quest, Entity::Player& player )
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
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00002: Empty(None), id=unknown" );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00003: Empty(None), id=unknown" );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00005: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00006: Empty(None), id=unknown" );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00007: Empty(None), id=unknown" );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00009: Empty(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00010: Empty(None), id=unknown" );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00011: Normal(Talk, TargetCanMove), id=BIGSOLDIER02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00012: Normal(Talk, TargetCanMove), id=SMALLSOLDIER02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00013: Normal(Talk, TargetCanMove), id=MIDDLESOLDIER02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, UI8BL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00015: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00016( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }
  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, UI8BL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00016: Normal(Talk, FadeIn, SystemTalk, ENpcBind), id=BIGSOLDIER02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00018: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00019( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }
  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00019: Normal(Talk, FadeIn, SystemTalk, ENpcBind), id=SMALLSOLDIER02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, UI8BH = 1, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00021: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00022( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }
  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, UI8BH = 1, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00022: Normal(Talk, FadeIn, SystemTalk, ENpcBind), id=MIDDLESOLDIER02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00023: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00024: Empty(None), id=unknown" );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00025: Empty(None), id=unknown" );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00026: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00027: Empty(None), id=unknown" );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00028: Empty(None), id=unknown" );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00029: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00030: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR7, UI8BH = 1, Flag8(1)=True, Branch(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00031: Normal(Talk, TargetCanMove), id=SOLDIERC02495" );
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, nullptr );
  }
  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR7, UI8BH = 1, Flag8(1)=True, Branch(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00032: Normal(Talk, NpcDespawn, TargetCanMove), id=SOLDIERC02495" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }
  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR7, UI8BH = 1, Flag8(1)=True, Branch(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00033: Normal(Talk, TargetCanMove), id=SOLDIERC02495" );
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, nullptr );
  }
  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR7, UI8BH = 1, Flag8(1)=True, Branch(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00034: Normal(Talk, TargetCanMove), id=SOLDIERC02495" );
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, nullptr );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR8, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00035: Normal(Talk, TargetCanMove), id=SOLDIERD02496" );
    eventMgr().playQuestScene( player, getId(), 35, HIDE_HOTBAR, nullptr );
  }
  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR8, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00036: Normal(Talk, NpcDespawn, TargetCanMove), id=SOLDIERD02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }
  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR8, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00037: Normal(Talk, TargetCanMove), id=SOLDIERD02496" );
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, nullptr );
  }
  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR8, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00038: Normal(Talk, TargetCanMove), id=SOLDIERD02496" );
    eventMgr().playQuestScene( player, getId(), 38, HIDE_HOTBAR, nullptr );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00039: Empty(None), id=unknown" );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00040: Empty(None), id=unknown" );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00041: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, HIDE_HOTBAR, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00042: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00043( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }
  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00043: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 43, HIDE_HOTBAR, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00044: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00045( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }
  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00045: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:5)
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00046: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 5, 0, 0, 0 );
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 46, HIDE_HOTBAR, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00047: Normal(Talk, TargetCanMove), id=SOLDIERC02495" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, HIDE_HOTBAR, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00048: Normal(Talk, TargetCanMove), id=SOLDIERD02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, HIDE_HOTBAR, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00050: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 50, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00051: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 51, HIDE_HOTBAR, callback );
  }

  void Scene00052( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00052: Normal(Talk, TargetCanMove), id=SOLDIERC02495" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 52, HIDE_HOTBAR, callback );
  }

  void Scene00053( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda320:68032 calling Scene00053: Normal(Talk, TargetCanMove), id=SOLDIERD02496" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 53, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda320 );
