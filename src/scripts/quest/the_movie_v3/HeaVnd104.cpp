// FFXIVTheMovie.ParserV3.10
// param used:
//WARP_SCENE1 = 418|0|-2.6|141.3|-3.1415|false
//WARP_SCENE5 = 418|0|-2.6|141.3|-3.1415|false
//SCENE_4 = AYMERIC
//PRIVATE_SCENE3 = 569
//PRIVATE_TEMPLEKNIGHTB02245 = 569
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnd104 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVnd104() : Sapphire::ScriptAPI::QuestScript( 67781 ){}; 
  ~HeaVnd104() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 21 entries
  //SEQ_3, 22 entries
  //SEQ_255, 10 entries

  //ACTOR0 = 1016813
  //ACTOR1 = 1016814
  //ACTOR10 = 1017545
  //ACTOR11 = 1017546
  //ACTOR12 = 1017547
  //ACTOR13 = 1017548
  //ACTOR14 = 1017550
  //ACTOR15 = 1017551
  //ACTOR16 = 1017552
  //ACTOR17 = 1017553
  //ACTOR18 = 1017554
  //ACTOR19 = 1016821
  //ACTOR2 = 5010000
  //ACTOR20 = 1011196
  //ACTOR21 = 1006454
  //ACTOR22 = 1006455
  //ACTOR23 = 1006456
  //ACTOR24 = 1016589
  //ACTOR25 = 1012157
  //ACTOR26 = 1012155
  //ACTOR27 = 1012162
  //ACTOR28 = 1012164
  //ACTOR29 = 1012163
  //ACTOR3 = 1017124
  //ACTOR4 = 1017539
  //ACTOR5 = 1017540
  //ACTOR6 = 1017541
  //ACTOR7 = 1017542
  //ACTOR8 = 1017543
  //ACTOR9 = 1017544
  //CUTSCENEN01 = 1199
  //CUTSCENEN02 = 1177
  //CUTSCENEN03 = 1178
  //CUTSCENEN04 = 1200
  //CUTSCENEN05 = 1201
  //CUTSCENEN06 = 1179
  //CUTSCENEN07 = 1180
  //INSTANCEDUNGEON0 = 20039
  //LOCBGM0 = 382
  //LOCSCREENIMAGE0 = 404
  //POPRANGE0 = 6349138
  //POPRANGE1 = 6351891
  //TERRITORYTYPE0 = 569
  //TERRITORYTYPE1 = 418

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
        if( param1 == 1016813 ) // ACTOR0 = AYMERIC
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AYMERIC
          }
          break;
        }
        if( param1 == 1016814 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 1:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00003( quest, player ); // Scene00003: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1016813 ) // ACTOR0 = AYMERIC
        {
          Scene00004( quest, player ); // Scene00004: Normal(Message, FadeIn), id=AYMERIC
          // +Callback Scene00005: Normal(Talk, TargetCanMove, ReturnTrue), id=AYMERIC
          break;
        }
        if( param1 == 1016814 ) // ACTOR1 = ALPHINAUD
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1017124 ) // ACTOR3 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017539 ) // ACTOR4 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017540 ) // ACTOR5 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017541 ) // ACTOR6 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017542 ) // ACTOR7 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017543 ) // ACTOR8 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017544 ) // ACTOR9 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017545 ) // ACTOR10 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017546 ) // ACTOR11 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017547 ) // ACTOR12 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017548 ) // ACTOR13 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017550 ) // ACTOR14 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017551 ) // ACTOR15 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017552 ) // ACTOR16 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017553 ) // ACTOR17 = unknown
        {
          Scene00021( quest, player ); // Scene00021: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017554 ) // ACTOR18 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016821 ) // ACTOR19 = TEMPLEKNIGHTB02245
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKNIGHTB02245
          break;
        }
        if( param1 == 1011196 ) // ACTOR20 = BELTARDOIS
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=BELTARDOIS
          break;
        }
        if( param1 == 1006454 ) // ACTOR21 = MARCELAIN
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=MARCELAIN
          break;
        }
        if( param1 == 1006455 ) // ACTOR22 = LOANNE
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=LOANNE
          break;
        }
        if( param1 == 1006456 ) // ACTOR23 = CHAUNOLLET
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=CHAUNOLLET
          break;
        }
        break;
      }
      case 3:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00028( quest, player ); // Scene00028: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1017124 ) // ACTOR3 = unknown
        {
          Scene00029( quest, player ); // Scene00029: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017539 ) // ACTOR4 = unknown
        {
          Scene00030( quest, player ); // Scene00030: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017540 ) // ACTOR5 = unknown
        {
          Scene00031( quest, player ); // Scene00031: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017541 ) // ACTOR6 = unknown
        {
          Scene00032( quest, player ); // Scene00032: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017542 ) // ACTOR7 = unknown
        {
          Scene00033( quest, player ); // Scene00033: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017543 ) // ACTOR8 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017544 ) // ACTOR9 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017545 ) // ACTOR10 = unknown
        {
          Scene00036( quest, player ); // Scene00036: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017546 ) // ACTOR11 = unknown
        {
          Scene00037( quest, player ); // Scene00037: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017547 ) // ACTOR12 = unknown
        {
          Scene00038( quest, player ); // Scene00038: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017548 ) // ACTOR13 = unknown
        {
          Scene00039( quest, player ); // Scene00039: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017550 ) // ACTOR14 = unknown
        {
          Scene00040( quest, player ); // Scene00040: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017551 ) // ACTOR15 = unknown
        {
          Scene00041( quest, player ); // Scene00041: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017552 ) // ACTOR16 = unknown
        {
          Scene00042( quest, player ); // Scene00042: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017553 ) // ACTOR17 = unknown
        {
          Scene00043( quest, player ); // Scene00043: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017554 ) // ACTOR18 = unknown
        {
          Scene00044( quest, player ); // Scene00044: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016821 ) // ACTOR19 = TEMPLEKNIGHTB02245
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKNIGHTB02245
          break;
        }
        if( param1 == 1011196 ) // ACTOR20 = BELTARDOIS
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=BELTARDOIS
          break;
        }
        if( param1 == 1006454 ) // ACTOR21 = MARCELAIN
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=MARCELAIN
          break;
        }
        if( param1 == 1006455 ) // ACTOR22 = LOANNE
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=LOANNE
          break;
        }
        if( param1 == 1006456 ) // ACTOR23 = CHAUNOLLET
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, TargetCanMove), id=CHAUNOLLET
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016589 ) // ACTOR24 = ALPHINAUD
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1011196 ) // ACTOR20 = BELTARDOIS
        {
          Scene00051( quest, player ); // Scene00051: Normal(Talk, TargetCanMove), id=BELTARDOIS
          break;
        }
        if( param1 == 1006454 ) // ACTOR21 = MARCELAIN
        {
          Scene00052( quest, player ); // Scene00052: Normal(Talk, TargetCanMove), id=MARCELAIN
          break;
        }
        if( param1 == 1006455 ) // ACTOR22 = LOANNE
        {
          Scene00053( quest, player ); // Scene00053: Normal(Talk, TargetCanMove), id=LOANNE
          break;
        }
        if( param1 == 1006456 ) // ACTOR23 = CHAUNOLLET
        {
          Scene00054( quest, player ); // Scene00054: Normal(Talk, TargetCanMove), id=CHAUNOLLET
          break;
        }
        if( param1 == 1012157 ) // ACTOR25 = QUOMONRENTIN
        {
          Scene00055( quest, player ); // Scene00055: Normal(Talk, TargetCanMove), id=QUOMONRENTIN
          break;
        }
        if( param1 == 1012155 ) // ACTOR26 = GONDELIMBAUD
        {
          Scene00056( quest, player ); // Scene00056: Normal(Talk, TargetCanMove), id=GONDELIMBAUD
          break;
        }
        if( param1 == 1012162 ) // ACTOR27 = VAINCANNET
        {
          Scene00057( quest, player ); // Scene00057: Normal(Talk, TargetCanMove), id=VAINCANNET
          break;
        }
        if( param1 == 1012164 ) // ACTOR28 = TESCELINGEON
        {
          Scene00058( quest, player ); // Scene00058: Normal(Talk, TargetCanMove), id=TESCELINGEON
          break;
        }
        if( param1 == 1012163 ) // ACTOR29 = HANDELOUP
        {
          Scene00059( quest, player ); // Scene00059: Normal(Talk, TargetCanMove), id=HANDELOUP
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
    quest.setSeq( 3 );
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 418, 0.0f, -2.6f, 141.3f, -3.14f, false );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00003: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.enterPredefinedPrivateInstance( 569 );
    };
    eventMgr().playQuestScene( player, getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00004: Normal(Message, FadeIn), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00005( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00005: Normal(Talk, TargetCanMove, ReturnTrue), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 418, 0.0f, -2.6f, 141.3f, -3.14f, false );
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00007: Empty(None), id=unknown" );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00008: Empty(None), id=unknown" );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00009: Empty(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00010: Empty(None), id=unknown" );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00011: Empty(None), id=unknown" );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00012: Empty(None), id=unknown" );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00013: Empty(None), id=unknown" );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00014: Empty(None), id=unknown" );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00016: Empty(None), id=unknown" );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00017: Empty(None), id=unknown" );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00018: Empty(None), id=unknown" );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00019: Empty(None), id=unknown" );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00020: Empty(None), id=unknown" );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00021: Empty(None), id=unknown" );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00022: Empty(None), id=unknown" );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00023: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKNIGHTB02245" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 569 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 23, NONE, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00024: Normal(Talk, TargetCanMove), id=BELTARDOIS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00025: Normal(Talk, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00026: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00027: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_3: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00028: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 28, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00029: Empty(None), id=unknown" );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00030: Empty(None), id=unknown" );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00031: Empty(None), id=unknown" );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00032: Empty(None), id=unknown" );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00033: Empty(None), id=unknown" );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00034: Empty(None), id=unknown" );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00035: Empty(None), id=unknown" );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00036: Empty(None), id=unknown" );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00037: Empty(None), id=unknown" );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00038: Empty(None), id=unknown" );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00039: Empty(None), id=unknown" );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00040: Empty(None), id=unknown" );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00041: Empty(None), id=unknown" );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00042: Empty(None), id=unknown" );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00043: Empty(None), id=unknown" );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00044: Empty(None), id=unknown" );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00045: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKNIGHTB02245" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 569 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 45, NONE, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00046: Normal(Talk, TargetCanMove), id=BELTARDOIS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, NONE, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00047: Normal(Talk, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, NONE, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00048: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, NONE, callback );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00049: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 49, NONE, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00050: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 50, NONE, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00051: Normal(Talk, TargetCanMove), id=BELTARDOIS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 51, NONE, callback );
  }

  void Scene00052( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00052: Normal(Talk, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 52, NONE, callback );
  }

  void Scene00053( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00053: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 53, NONE, callback );
  }

  void Scene00054( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00054: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 54, NONE, callback );
  }

  void Scene00055( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR25, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00055: Normal(Talk, TargetCanMove), id=QUOMONRENTIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 55, NONE, callback );
  }

  void Scene00056( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR26, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00056: Normal(Talk, TargetCanMove), id=GONDELIMBAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 56, NONE, callback );
  }

  void Scene00057( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR27, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00057: Normal(Talk, TargetCanMove), id=VAINCANNET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 57, NONE, callback );
  }

  void Scene00058( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR28, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00058: Normal(Talk, TargetCanMove), id=TESCELINGEON" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 58, NONE, callback );
  }

  void Scene00059( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR29, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd104:67781 calling Scene00059: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 59, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnd104 );
