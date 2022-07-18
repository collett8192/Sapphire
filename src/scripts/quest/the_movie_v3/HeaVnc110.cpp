// FFXIVTheMovie.ParserV3.10
// param used:
//WARP_SCENE2 = 418|0.758|1.3|110.3|3.1415|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc110 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVnc110() : Sapphire::ScriptAPI::QuestScript( 67776 ){}; 
  ~HeaVnc110() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 1 entries
  //SEQ_2, 17 entries
  //SEQ_255, 16 entries

  //ACTOR0 = 1016074
  //ACTOR1 = 1016587
  //ACTOR10 = 1010385
  //ACTOR11 = 1010386
  //ACTOR12 = 1010387
  //ACTOR13 = 1016568
  //ACTOR14 = 1016569
  //ACTOR15 = 1016570
  //ACTOR16 = 1011231
  //ACTOR17 = 1011232
  //ACTOR18 = 1011233
  //ACTOR19 = 1011236
  //ACTOR2 = 1016588
  //ACTOR20 = 1011238
  //ACTOR21 = 1011240
  //ACTOR22 = 1013709
  //ACTOR3 = 1016075
  //ACTOR4 = 1016076
  //ACTOR5 = 1016589
  //ACTOR6 = 1016565
  //ACTOR7 = 1016590
  //ACTOR8 = 1010383
  //ACTOR9 = 1010384
  //CUTSCENEN01 = 1152
  //CUTSCENEN02 = 1170
  //CUTSCENEN03 = 1153
  //LOCACTOR0 = 6207043
  //LOCACTOR1 = 6207045
  //LOCACTOR10 = 1015909
  //LOCACTOR11 = 1016778
  //LOCACTOR12 = 1015911
  //LOCBGM0 = 313
  //POPRANGE0 = 6197372

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
        if( param1 == 1016074 ) // ACTOR0 = AYMERIC
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn), id=AYMERIC
            // +Callback Scene00002: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1016587 ) // ACTOR1 = EMMANELLAIN
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1016588 ) // ACTOR2 = THANCRED
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1016075 ) // ACTOR3 = LUCIA
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1016076 ) // ACTOR4 = HILDA
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        break;
      }
      case 1:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00007( quest, player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 2:
      {
        if( param1 == 1016565 ) // ACTOR6 = ARTOIREL
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=ARTOIREL
          }
          break;
        }
        if( param1 == 1016590 ) // ACTOR7 = ALPHINAUD
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1010383 ) // ACTOR8 = CITIZENA02240
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=CITIZENA02240
          break;
        }
        if( param1 == 1010384 ) // ACTOR9 = CITIZENB02240
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=CITIZENB02240
          break;
        }
        if( param1 == 1010385 ) // ACTOR10 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Empty(None), id=unknown
          break;
        }
        if( param1 == 1010386 ) // ACTOR11 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Empty(None), id=unknown
          break;
        }
        if( param1 == 1010387 ) // ACTOR12 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016568 ) // ACTOR13 = CITIZENA02233
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1016569 ) // ACTOR14 = CITIZENB02233
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR15 = CITIZENC02233
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        if( param1 == 1011231 ) // ACTOR16 = REDWALD
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=REDWALD
          break;
        }
        if( param1 == 1011232 ) // ACTOR17 = TOURCENET
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=TOURCENET
          break;
        }
        if( param1 == 1011233 ) // ACTOR18 = EMERISSEL
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=EMERISSEL
          break;
        }
        if( param1 == 1011236 ) // ACTOR19 = ROTHE
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ROTHE
          break;
        }
        if( param1 == 1011238 ) // ACTOR20 = NOIRTEREL
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=NOIRTEREL
          break;
        }
        if( param1 == 1011240 ) // ACTOR21 = INGARET
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=INGARET
          break;
        }
        if( param1 == 1013709 ) // ACTOR22 = AURIAUNE
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=AURIAUNE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016590 ) // ACTOR7 = ALPHINAUD
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove, Menu, CanCancel), id=ALPHINAUD
          // +Callback Scene00026: Normal(CutScene, AutoFadeIn), id=unknown
          // +Callback Scene00027: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1010383 ) // ACTOR8 = CITIZENA02240
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=CITIZENA02240
          break;
        }
        if( param1 == 1010384 ) // ACTOR9 = CITIZENB02240
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=CITIZENB02240
          break;
        }
        if( param1 == 1010385 ) // ACTOR10 = unknown
        {
          Scene00030( quest, player ); // Scene00030: Empty(None), id=unknown
          break;
        }
        if( param1 == 1010386 ) // ACTOR11 = unknown
        {
          Scene00031( quest, player ); // Scene00031: Empty(None), id=unknown
          break;
        }
        if( param1 == 1010387 ) // ACTOR12 = unknown
        {
          Scene00032( quest, player ); // Scene00032: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016568 ) // ACTOR13 = CITIZENA02233
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1016569 ) // ACTOR14 = CITIZENB02233
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR15 = CITIZENC02233
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        if( param1 == 1011231 ) // ACTOR16 = REDWALD
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=REDWALD
          break;
        }
        if( param1 == 1011232 ) // ACTOR17 = TOURCENET
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=TOURCENET
          break;
        }
        if( param1 == 1011233 ) // ACTOR18 = EMERISSEL
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=EMERISSEL
          break;
        }
        if( param1 == 1011236 ) // ACTOR19 = ROTHE
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=ROTHE
          break;
        }
        if( param1 == 1011238 ) // ACTOR20 = NOIRTEREL
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=NOIRTEREL
          break;
        }
        if( param1 == 1011240 ) // ACTOR21 = INGARET
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=INGARET
          break;
        }
        if( param1 == 1013709 ) // ACTOR22 = AURIAUNE
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=AURIAUNE
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
    quest.setSeq( 2 );
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

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00002( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }
  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00002: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 418, 0.76f, 1.3f, 110.3f, 3.14f, false );
    };
    eventMgr().playQuestScene( player, getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00004: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00005: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00006: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00010: Normal(Talk, TargetCanMove), id=CITIZENA02240" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00011: Normal(Talk, TargetCanMove), id=CITIZENB02240" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00012: Empty(None), id=unknown" );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00013: Empty(None), id=unknown" );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00014: Empty(None), id=unknown" );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00015: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00016: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00017: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00018: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00019: Normal(Talk, TargetCanMove), id=TOURCENET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00020: Normal(Talk, TargetCanMove), id=EMERISSEL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00021: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00022: Normal(Talk, TargetCanMove), id=NOIRTEREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00023: Normal(Talk, TargetCanMove), id=INGARET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, NONE, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00024: Normal(Talk, TargetCanMove), id=AURIAUNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00025: Normal(Talk, TargetCanMove, Menu, CanCancel), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00026( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }
  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00026: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00027( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00027: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00028: Normal(Talk, TargetCanMove), id=CITIZENA02240" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00029: Normal(Talk, TargetCanMove), id=CITIZENB02240" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00030: Empty(None), id=unknown" );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00031: Empty(None), id=unknown" );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00032: Empty(None), id=unknown" );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00033: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, NONE, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00034: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, NONE, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00035: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, NONE, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00036: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, NONE, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00037: Normal(Talk, TargetCanMove), id=TOURCENET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, NONE, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00038: Normal(Talk, TargetCanMove), id=EMERISSEL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, NONE, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00039: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, NONE, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00040: Normal(Talk, TargetCanMove), id=NOIRTEREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, NONE, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00041: Normal(Talk, TargetCanMove), id=INGARET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, NONE, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc110:67776 calling Scene00042: Normal(Talk, TargetCanMove), id=AURIAUNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnc110 );
