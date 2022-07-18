// FFXIVTheMovie.ParserV3.9
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc107 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVnc107() : Sapphire::ScriptAPI::QuestScript( 67773 ){}; 
  ~HeaVnc107() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 6 entries
  //SEQ_2, 5 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1016580
  //ACTOR1 = 1016578
  //ACTOR10 = 1016579
  //ACTOR11 = 1016582
  //ACTOR2 = 1016568
  //ACTOR3 = 1016569
  //ACTOR4 = 1016570
  //ACTOR5 = 1016069
  //ACTOR6 = 1016070
  //ACTOR7 = 1016581
  //ACTOR8 = 1016077
  //ACTOR9 = 1016071
  //CUTSCENEN01 = 1148
  //LOCACTOR0 = 1008193
  //LOCACTOR1 = 1011893
  //LOCACTOR2 = 1013876
  //LOCACTOR3 = 1015842
  //LOCIDLE0 = 804
  //LOCSE0 = 44

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
        if( param1 == 1016580 ) // ACTOR0 = THANCRED
        {
          Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1016578 ) // ACTOR1 = unknown
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1016069 ) // ACTOR5 = LUCIA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=LUCIA
          }
          break;
        }
        if( param1 == 1016578 ) // ACTOR1 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        if( param1 == 1016070 ) // ACTOR6 = ARTOIREL
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1016581 ) // ACTOR7 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00012( quest, player ); // Scene00012: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1016077 ) // ACTOR8 = THANCRED
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1016069 ) // ACTOR5 = LUCIA
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1016070 ) // ACTOR6 = ARTOIREL
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1016071 ) // ACTOR9 = EMMANELLAIN
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016579 ) // ACTOR10 = THANCRED
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1016581 ) // ACTOR7 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1016582 ) // ACTOR11 = EMMANELLAIN
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1016069 ) // ACTOR5 = LUCIA
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1016070 ) // ACTOR6 = ARTOIREL
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ARTOIREL
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
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00002: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00003: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00004: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00005: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00007: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00008: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00009: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00010: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00011: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00012: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00013: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00014: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00015: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00016: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00018: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00019: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00020: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc107:67773 calling Scene00021: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnc107 );
