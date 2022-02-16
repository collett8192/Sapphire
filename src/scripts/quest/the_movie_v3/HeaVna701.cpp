// FFXIVTheMovie.ParserV3.9
// id table disabled
// param used:
//WARP_SCENE17 = 402|-868|-184.2|-660.5|1.21|false
//WARP_SCENE28 = 402|-868|-184.2|-660.5|1.21|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna701 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna701() : Sapphire::ScriptAPI::QuestScript( 67199 ){}; 
  ~HeaVna701() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 8 entries
  //SEQ_2, 10 entries
  //SEQ_3, 11 entries
  //SEQ_4, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1012430
  //ACTOR1 = 1013166
  //ACTOR10 = 1007478
  //ACTOR11 = 1012854
  //ACTOR12 = 1012851
  //ACTOR13 = 1012852
  //ACTOR14 = 1012853
  //ACTOR15 = 1012855
  //ACTOR16 = 1012856
  //ACTOR17 = 1012792
  //ACTOR18 = 1012793
  //ACTOR19 = 1013268
  //ACTOR2 = 1013176
  //ACTOR20 = 1012789
  //ACTOR21 = 1012790
  //ACTOR22 = 1012791
  //ACTOR3 = 1012431
  //ACTOR4 = 1012432
  //ACTOR5 = 1013173
  //ACTOR6 = 1013174
  //ACTOR7 = 1013175
  //ACTOR8 = 1015138
  //ACTOR9 = 1014562
  //CUTSCENEN01 = 888
  //CUTSCENEN02 = 889
  //CUTSCENEN03 = 990
  //CUTSCENEN04 = 890
  //LOCACTOR0 = 5890648
  //LOCACTOR1 = 5890649
  //LOCACTOR2 = 5890650
  //LOCACTOR3 = 5890652
  //LOCACTOR4 = 5890653
  //LOCMUSIC0 = 314
  //LOCMUSIC1 = 316
  //POPRANGE0 = 5873901
  //QSTCHECK01 = 66236
  //QSTCHECK02 = 66237
  //QSTCHECK03 = 66238
  //REWARDMOUNTOPEN = 17
  //TERRITORYTYPE0 = 402

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
        if( param1 == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1013166 ) // ACTOR1 = AYMERIC
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1013176 ) // ACTOR2 = NOTRELCHAMPS
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
          break;
        }
        if( param1 == 1012431 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012432 ) // ACTOR4 = ESTINIEN
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013173 ) // ACTOR5 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013174 ) // ACTOR6 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013175 ) // ACTOR7 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012431 ) // ACTOR3 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00009( quest, player ); // Scene00009: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012432 ) // ACTOR4 = ESTINIEN
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013166 ) // ACTOR1 = AYMERIC
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1013173 ) // ACTOR5 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013174 ) // ACTOR6 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013175 ) // ACTOR7 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013176 ) // ACTOR2 = NOTRELCHAMPS
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1012431 ) // ACTOR3 = YSHTOLA
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1015138 ) // ACTOR8 = ESTINIEN
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013166 ) // ACTOR1 = AYMERIC
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1013173 ) // ACTOR5 = unknown
        {
          Scene00021( quest, player ); // Scene00021: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013174 ) // ACTOR6 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013175 ) // ACTOR7 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013176 ) // ACTOR2 = NOTRELCHAMPS
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
          break;
        }
        if( param1 == 1014562 ) // ACTOR9 = URIANGER
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1007478 ) // ACTOR10 = URIANGER
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 3:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00027( quest, player ); // Scene00027: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove, ReturnTrue), id=ALPHINAUD
          break;
        }
        if( param1 == 1012431 ) // ACTOR3 = YSHTOLA
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1015138 ) // ACTOR8 = ESTINIEN
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013166 ) // ACTOR1 = AYMERIC
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1013173 ) // ACTOR5 = unknown
        {
          Scene00032( quest, player ); // Scene00032: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013174 ) // ACTOR6 = unknown
        {
          Scene00033( quest, player ); // Scene00033: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013175 ) // ACTOR7 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013176 ) // ACTOR2 = NOTRELCHAMPS
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
          break;
        }
        if( param1 == 1014562 ) // ACTOR9 = URIANGER
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1007478 ) // ACTOR10 = URIANGER
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1012854 ) // ACTOR11 = CID
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00038( quest, player ); // Scene00038: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=CID
          }
          break;
        }
        if( param1 == 1012851 ) // ACTOR12 = ALPHINAUD
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012852 ) // ACTOR13 = ESTINIEN
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012853 ) // ACTOR14 = YSHTOLA
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012855 ) // ACTOR15 = BIGGS
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1012856 ) // ACTOR16 = WEDGE
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012792 ) // ACTOR17 = CID
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1012793 ) // ACTOR18 = BIGGS
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1013268 ) // ACTOR19 = WEDGE
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        if( param1 == 1012789 ) // ACTOR20 = ALPHINAUD
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012790 ) // ACTOR21 = ESTINIEN
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012791 ) // ACTOR22 = YSHTOLA
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, TargetCanMove), id=YSHTOLA
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
      quest.setSeq( 3 );
    }
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 4 );
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
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
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00002: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00003: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00006: Empty(None), id=unknown" );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00007: Empty(None), id=unknown" );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00008: Empty(None), id=unknown" );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00009: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00011: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00012: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00013: Empty(None), id=unknown" );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00014: Empty(None), id=unknown" );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00016: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 402, -868.0f, -184.2f, -660.5f, 1.21f, false );
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00019: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00020: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00021: Empty(None), id=unknown" );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00022: Empty(None), id=unknown" );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00023: Empty(None), id=unknown" );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00024: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00025: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00026: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_3: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00027: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00028: Normal(Talk, TargetCanMove, ReturnTrue), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 402, -868.0f, -184.2f, -660.5f, 1.21f, false );
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00030: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00031: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00032: Empty(None), id=unknown" );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00033: Empty(None), id=unknown" );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00034: Empty(None), id=unknown" );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00035: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, NONE, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00036: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, NONE, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00037: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, NONE, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00038: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 38, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00039: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, NONE, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00040: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, NONE, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00041: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, NONE, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00042: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, NONE, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00043: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, NONE, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00044: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 44, NONE, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00045: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, NONE, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00046: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, NONE, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, NONE, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00048: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, NONE, callback );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna701:67199 calling Scene00049: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 49, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna701 );
