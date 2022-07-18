// FFXIVTheMovie.ParserV3.10
// param used:
//_ACTOR3 = B
//_ACTOR3B = 2|2
//_ACTOR4 = B
//_ACTOR4B = 2|2
//_ACTOR17 = B
//_ACTOR17B = 2|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc106 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVnc106() : Sapphire::ScriptAPI::QuestScript( 67772 ){}; 
  ~HeaVnc106() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 12 entries
  //SEQ_2, 13 entries
  //SEQ_255, 13 entries

  //ACTOR0 = 1016566
  //ACTOR1 = 1016567
  //ACTOR10 = 1011231
  //ACTOR11 = 1011232
  //ACTOR12 = 1011233
  //ACTOR13 = 1011236
  //ACTOR14 = 1011238
  //ACTOR15 = 1011240
  //ACTOR16 = 1013709
  //ACTOR17 = 1011235
  //ACTOR18 = 1016580
  //ACTOR2 = 1016568
  //ACTOR3 = 1016569
  //ACTOR4 = 1016570
  //ACTOR5 = 1016077
  //ACTOR6 = 1016571
  //ACTOR7 = 1016572
  //ACTOR8 = 1016579
  //ACTOR9 = 1016578
  //CUTSCENEN01 = 1145
  //CUTSCENEN02 = 1146
  //CUTSCENEN03 = 1147
  //LOCACTOR0 = 6184576
  //LOCACTOR1 = 6200079
  //POPRANGE0 = 6184802

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
        if( param1 == 1016566 ) // ACTOR0 = EMMANELLAIN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn, ENpcBind), id=EMMANELLAIN
            // +Callback Scene00002: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1016567 ) // ACTOR1 = HONOROIT
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        if( param1 == 1016077 ) // ACTOR5 = THANCRED
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1016571 ) // ACTOR6 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016572 ) // ACTOR7 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1016579 ) // ACTOR8 = THANCRED
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED
          }
          break;
        }
        if( param1 == 1016578 ) // ACTOR9 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        if( param1 == 1011231 ) // ACTOR10 = REDWALD
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=REDWALD
          break;
        }
        if( param1 == 1011232 ) // ACTOR11 = TOURCENET
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=TOURCENET
          break;
        }
        if( param1 == 1011233 ) // ACTOR12 = EMERISSEL
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=EMERISSEL
          break;
        }
        if( param1 == 1011236 ) // ACTOR13 = ROTHE
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=ROTHE
          break;
        }
        if( param1 == 1011238 ) // ACTOR14 = NOIRTEREL
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=NOIRTEREL
          break;
        }
        if( param1 == 1011240 ) // ACTOR15 = INGARET
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=INGARET
          break;
        }
        if( param1 == 1013709 ) // ACTOR16 = AURIAUNE
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=AURIAUNE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1016569 ) // ACTOR3 = CITIZENB02233, CB=2
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=CITIZENB02233
          }
          else
          {
            Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=CITIZENB02233
          }
          break;
        }
        if( param1 == 1016570 ) // ACTOR4 = CITIZENC02233, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=CITIZENC02233
          }
          else
          {
            Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=CITIZENC02233
          }
          break;
        }
        if( param1 == 1011235 ) // ACTOR17 = JOSSELOUX, CB=2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=JOSSELOUX
          }
          else
          {
            Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=JOSSELOUX
          }
          break;
        }
        if( param1 == 1016580 ) // ACTOR18 = THANCRED
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1016578 ) // ACTOR9 = unknown
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1011231 ) // ACTOR10 = REDWALD
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=REDWALD
          break;
        }
        if( param1 == 1011232 ) // ACTOR11 = TOURCENET
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=TOURCENET
          break;
        }
        if( param1 == 1011233 ) // ACTOR12 = EMERISSEL
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=EMERISSEL
          break;
        }
        if( param1 == 1011236 ) // ACTOR13 = ROTHE
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=ROTHE
          break;
        }
        if( param1 == 1011238 ) // ACTOR14 = NOIRTEREL
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=NOIRTEREL
          break;
        }
        if( param1 == 1011240 ) // ACTOR15 = INGARET
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=INGARET
          break;
        }
        if( param1 == 1013709 ) // ACTOR16 = AURIAUNE
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=AURIAUNE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016580 ) // ACTOR18 = THANCRED
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        if( param1 == 1011235 ) // ACTOR17 = JOSSELOUX
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=JOSSELOUX
          break;
        }
        if( param1 == 1016578 ) // ACTOR9 = unknown
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1011231 ) // ACTOR10 = REDWALD
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=REDWALD
          break;
        }
        if( param1 == 1011232 ) // ACTOR11 = TOURCENET
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=TOURCENET
          break;
        }
        if( param1 == 1011233 ) // ACTOR12 = EMERISSEL
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=EMERISSEL
          break;
        }
        if( param1 == 1011236 ) // ACTOR13 = ROTHE
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=ROTHE
          break;
        }
        if( param1 == 1011238 ) // ACTOR14 = NOIRTEREL
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=NOIRTEREL
          break;
        }
        if( param1 == 1011240 ) // ACTOR15 = INGARET
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, TargetCanMove), id=INGARET
          break;
        }
        if( param1 == 1013709 ) // ACTOR16 = AURIAUNE
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, TargetCanMove), id=AURIAUNE
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
          quest.setSeq( 255 );
        }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn, ENpcBind), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00002( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }
  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00002: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00003: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00004: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00005: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00006: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00007: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00008: Empty(None), id=unknown" );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00009: Empty(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00011: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00012: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00013: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00014: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00015: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00016: Normal(Talk, TargetCanMove), id=TOURCENET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00017: Normal(Talk, TargetCanMove), id=EMERISSEL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00018: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00019: Normal(Talk, TargetCanMove), id=NOIRTEREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00020: Normal(Talk, TargetCanMove), id=INGARET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00021: Normal(Talk, TargetCanMove), id=AURIAUNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, UI8BL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00022: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }
  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, UI8BL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00023: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    eventMgr().playQuestScene( player, getId(), 23, NONE, nullptr );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00024: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }
  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00025: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    eventMgr().playQuestScene( player, getId(), 25, NONE, nullptr );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR17, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00026: Normal(Talk, TargetCanMove), id=JOSSELOUX" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }
  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR17, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00027: Normal(Talk, TargetCanMove), id=JOSSELOUX" );
    eventMgr().playQuestScene( player, getId(), 27, NONE, nullptr );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00028: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00029: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00030: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00031: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00032: Normal(Talk, TargetCanMove), id=TOURCENET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, NONE, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00033: Normal(Talk, TargetCanMove), id=EMERISSEL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, NONE, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00034: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, NONE, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00035: Normal(Talk, TargetCanMove), id=NOIRTEREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, NONE, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00036: Normal(Talk, TargetCanMove), id=INGARET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, NONE, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00037: Normal(Talk, TargetCanMove), id=AURIAUNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, NONE, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 38, NONE, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00039: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, NONE, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00040: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, NONE, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00041: Normal(Talk, TargetCanMove), id=JOSSELOUX" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, NONE, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00042: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, NONE, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00043: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, NONE, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00044: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, NONE, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00045: Normal(Talk, TargetCanMove), id=TOURCENET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, NONE, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00046: Normal(Talk, TargetCanMove), id=EMERISSEL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, NONE, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00047: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, NONE, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00048: Normal(Talk, TargetCanMove), id=NOIRTEREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, NONE, callback );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00049: Normal(Talk, TargetCanMove), id=INGARET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 49, NONE, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc106:67772 calling Scene00050: Normal(Talk, TargetCanMove), id=AURIAUNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 50, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnc106 );
