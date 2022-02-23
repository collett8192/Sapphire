// FFXIVTheMovie.ParserV3.9
// param used:
//ENEMY0 = dummy0
//ENEMY1 = dummy1
//ENEMY2 = dummy2
//ENEMY3 = dummy3
//ENEMY4 = dummy4
//ENEMY5 = dummy5
//EOBJECT0 = dummye0
//SCENE_3 = dummy0
//SCENE_4 = dummy1
//SCENE_5 = dummy2
//SCENE_6 = dummy3
//SCENE_7 = dummy4
//SCENE_8 = dummy5
//SCENE_9 = dummye0
//SCENE_16 REMOVED!!
//PRIVATE_SCENE12 = 507
//PRIVATE_SCENE15 = 507
//PRIVATE_SCENE17 = 433
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna707 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna707() : Sapphire::ScriptAPI::QuestScript( 67205 ){}; 
  ~HeaVna707() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_4, 3 entries
  //SEQ_5, 1 entries
  //SEQ_6, 2 entries
  //SEQ_255, 12 entries

  //ACTOR0 = 1012848
  //ACTOR1 = 1012850
  //ACTOR10 = 1012180
  //ACTOR11 = 1012383
  //ACTOR12 = 1012384
  //ACTOR13 = 1012385
  //ACTOR14 = 1011935
  //ACTOR15 = 1012138
  //ACTOR2 = 5010000
  //ACTOR3 = 1013604
  //ACTOR4 = 1012857
  //ACTOR5 = 1012858
  //ACTOR6 = 1012337
  //ACTOR7 = 1013167
  //ACTOR8 = 1011192
  //ACTOR9 = 1012251
  //CUTSCENEN01 = 902
  //CUTSCENEN02 = 977
  //CUTSCENEN03 = 904
  //CUTSCENEN04 = 905
  //CUTSCENEN05 = 906
  //CUTSCENEN06 = 907
  //CUTSCENEN07 = 860
  //CUTSCENEN08 = 910
  //CUTSCENEN09 = 908
  //CUTSCENEN10 = 909
  //CUTSCENEN11 = 970
  //ENEMY0 = 5872412
  //ENEMY1 = 5872413
  //ENEMY2 = 5872415
  //ENEMY3 = 5872416
  //ENEMY4 = 5872417
  //ENEMY5 = 5872419
  //EOBJECT0 = 2006358
  //EOBJECT1 = 2006458
  //INSTANCEDUNGEON0 = 38
  //INSTANCEDUNGEON1 = 20035
  //LOCACTOR0 = 5912494
  //LOCIDLE0 = 794
  //LOCMOTION0 = 791
  //LOCMUSIC0 = 89
  //LOCMUSIC1 = 239
  //LOCSCREENIMAGE0 = 311
  //LOCSCREENIMAGEA = 316
  //POPRANGE0 = 5941504
  //POPRANGE1 = 5873484
  //TERRITORYTYPE0 = 507
  //TERRITORYTYPE1 = 433

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUIDANCESYSTEM
        break;
      }
      case 1:
      {
        if( param1 == 1012850 ) // ACTOR1 = GUIDANCESYSTEM
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Talk, Message, PopBNpc, TargetCanMove), id=GUIDANCESYSTEM
          }
          break;
        }
        // BNpcHack credit moved to ACTOR1
        if( param1 == 5872412 ) // ENEMY0 = dummy0
        {
          Scene00003( quest, player ); // Scene00003: Normal(Message, PopBNpc), id=dummy0
          break;
        }
        if( param1 == 5872413 ) // ENEMY1 = dummy1
        {
          Scene00004( quest, player ); // Scene00004: Normal(Message, PopBNpc), id=dummy1
          break;
        }
        if( param1 == 5872415 ) // ENEMY2 = dummy2
        {
          Scene00005( quest, player ); // Scene00005: Normal(Message, PopBNpc), id=dummy2
          break;
        }
        if( param1 == 5872416 ) // ENEMY3 = dummy3
        {
          Scene00006( quest, player ); // Scene00006: Normal(Message, PopBNpc), id=dummy3
          break;
        }
        if( param1 == 5872417 ) // ENEMY4 = dummy4
        {
          Scene00007( quest, player ); // Scene00007: Normal(Message, PopBNpc), id=dummy4
          break;
        }
        if( param1 == 5872419 ) // ENEMY5 = dummy5
        {
          Scene00008( quest, player ); // Scene00008: Normal(Message, PopBNpc), id=dummy5
          break;
        }
        if( param1 == 2006358 ) // EOBJECT0 = dummye0
        {
          Scene00009( quest, player ); // Scene00009: Empty(None), id=dummye0
          break;
        }
        break;
      }
      case 2:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00010( quest, player ); // Scene00010: Normal(Talk, Message, FadeIn, TargetCanMove), id=GUIDANCESYSTEM
        break;
      }
      case 3:
      {
        if( param1 == 1013604 ) // ACTOR3 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00012( quest, player ); // Scene00012: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1013604 ) // ACTOR3 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Normal(Message, FadeIn, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 2006458 ) // EOBJECT1 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1013604 ) // ACTOR3 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Normal(YesNo), id=unknown
          break;
        }
        break;
      }
      case 6:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00017( quest, player ); // Scene00017: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1013604 ) // ACTOR3 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012857 ) // ACTOR4 = ALPHINAUD
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=ALPHINAUD
          break;
        }
        if( param1 == 1012858 ) // ACTOR5 = TATARUL
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=TATARUL
          break;
        }
        if( param1 == 1012337 ) // ACTOR6 = BUTLER01580
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=BUTLER01580
          break;
        }
        if( param1 == 1013167 ) // ACTOR7 = LUCIA
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1011192 ) // ACTOR8 = GIBRILLONT
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=GIBRILLONT
          break;
        }
        if( param1 == 1012251 ) // ACTOR9 = HILDA
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1012180 ) // ACTOR10 = ELAISSE
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=ELAISSE
          break;
        }
        if( param1 == 1012383 ) // ACTOR11 = ARTOIREL
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1012384 ) // ACTOR12 = EMMANELLAIN
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1012385 ) // ACTOR13 = HONOROIT
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1011935 ) // ACTOR14 = VIDOFNIR
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=VIDOFNIR
          break;
        }
        if( param1 == 1012138 ) // ACTOR15 = MATOYA
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=MATOYA
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
    if( quest.getUI8AL() == 6 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 2 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 3 );
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 4 );
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 5 );
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 6 );
  }
  void checkProgressSeq6( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 6, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00002: Normal(Talk, Message, PopBNpc, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 6 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 6 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00003: Normal(Message, PopBNpc), id=dummy0" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00004: Normal(Message, PopBNpc), id=dummy1" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00005: Normal(Message, PopBNpc), id=dummy2" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00006: Normal(Message, PopBNpc), id=dummy3" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00007: Normal(Message, PopBNpc), id=dummy4" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00008: Normal(Message, PopBNpc), id=dummy5" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00009: Empty(None), id=dummye0" );
    checkProgressSeq1( quest, player );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00010: Normal(Talk, Message, FadeIn, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00011: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_4: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00012: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.enterPredefinedPrivateInstance( 507 );
    };
    eventMgr().playQuestScene( player, getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00013: Normal(Message, FadeIn, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00014: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00015: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 507 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_6: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00017: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq6( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.enterPredefinedPrivateInstance( 433 );
    };
    eventMgr().playQuestScene( player, getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00018: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00020: Normal(Talk, TargetCanMove), id=TATARUL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00021: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00022: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00023: Normal(Talk, TargetCanMove), id=GIBRILLONT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, NONE, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00024: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00025: Normal(Talk, TargetCanMove), id=ELAISSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00026: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00027: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00028: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00029: Normal(Talk, TargetCanMove), id=VIDOFNIR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna707:67205 calling Scene00030: Normal(Talk, TargetCanMove), id=MATOYA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna707 );
