// FFXIVTheMovie.ParserV3.9
// param used:
//WARP_SCENE1 = 418|85|24|-6.53|-1.77|false
//TODO_DISABLED = 
//SCENE_34 = ACTOR29
//PRIVATE_SCENE36 = 0
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnb108 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVnb108() : Sapphire::ScriptAPI::QuestScript( 67699 ){}; 
  ~HeaVnb108() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 16 entries
  //SEQ_2, 2 entries
  //SEQ_3, 10 entries
  //SEQ_255, 9 entries

  //ACTOR0 = 1016008
  //ACTOR1 = 1016009
  //ACTOR10 = 1016042
  //ACTOR11 = 1016043
  //ACTOR12 = 1016044
  //ACTOR13 = 1016045
  //ACTOR14 = 1016046
  //ACTOR15 = 1016047
  //ACTOR16 = 1016039
  //ACTOR17 = 1016040
  //ACTOR18 = 1016041
  //ACTOR19 = 1012163
  //ACTOR2 = 1016010
  //ACTOR20 = 1016049
  //ACTOR21 = 1013167
  //ACTOR22 = 1012251
  //ACTOR23 = 1012252
  //ACTOR24 = 1012253
  //ACTOR25 = 1016060
  //ACTOR26 = 1016061
  //ACTOR27 = 1012337
  //ACTOR28 = 1012377
  //ACTOR29 = 1016050
  //ACTOR3 = 1016011
  //ACTOR30 = 1016051
  //ACTOR4 = 1016012
  //ACTOR5 = 1016034
  //ACTOR6 = 1016035
  //ACTOR7 = 1016036
  //ACTOR8 = 1016037
  //ACTOR9 = 1016038
  //CUTSCENEN01 = 1054
  //CUTSCENEN02 = 1055
  //CUTSCENEN03 = 1056
  //CUTSCENEN04 = 1057
  //CUTSCENEN05 = 1058
  //CUTSCENEN06 = 1059
  //CUTSCENEN07 = 1060
  //EOBJECT0 = 2006608
  //LOCACTOR0 = 6093732
  //LOCACTOR1 = 6093733
  //LOCACTOR10 = 6081119
  //LOCACTOR11 = 6081115
  //LOCACTOR12 = 6081116
  //LOCACTOR13 = 6081117
  //POPRANGE0 = 6163372
  //POPRANGE1 = 5827750
  //QUESTBATTLE0 = 150
  //TERRITORYTYPE0 = 513
  //TERRITORYTYPE1 = 419

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
        if( param1 == 1016008 ) // ACTOR0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(CutScene, QuestAccept), id=unknown
          }
          break;
        }
        if( param1 == 1016009 ) // ACTOR1 = HILDA
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1016010 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1016011 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1016012 ) // ACTOR4 = THANCRED
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1016034 ) // ACTOR5 = AYMERIC
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, QuestBattle, YesNo, TargetCanMove, ENpcBind), id=AYMERIC
          }
          break;
        }
        if( param1 == 1016035 ) // ACTOR6 = ALPHINAUD
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1016036 ) // ACTOR7 = YSHTOLA
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1016037 ) // ACTOR8 = THANCRED
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1016038 ) // ACTOR9 = ARTOIREL
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1016042 ) // ACTOR10 = LUCIA
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1016043 ) // ACTOR11 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016044 ) // ACTOR12 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016045 ) // ACTOR13 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016046 ) // ACTOR14 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016047 ) // ACTOR15 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Empty(None), id=unknown
          break;
        }
        if( param1 == 2006608 ) // EOBJECT0 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016039 ) // ACTOR16 = HILDA
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1016040 ) // ACTOR17 = EUDESTAND
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=EUDESTAND
          break;
        }
        if( param1 == 1016041 ) // ACTOR18 = SYMME
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=SYMME
          break;
        }
        if( param1 == 1012163 ) // ACTOR19 = HANDELOUP
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=HANDELOUP
          break;
        }
        break;
      }
      case 2:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00022( quest, player ); // Scene00022: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1012163 ) // ACTOR19 = HANDELOUP
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=HANDELOUP
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1016049 ) // ACTOR20 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00024( quest, player ); // Scene00024: Normal(Talk, FadeIn, TargetCanMove, Menu, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1013167 ) // ACTOR21 = LUCIA
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1012251 ) // ACTOR22 = HILDA
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1012252 ) // ACTOR23 = SYMME
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=SYMME
          break;
        }
        if( param1 == 1012253 ) // ACTOR24 = EUDESTAND
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=EUDESTAND
          break;
        }
        if( param1 == 1016060 ) // ACTOR25 = YSHTOLA
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1016061 ) // ACTOR26 = THANCRED
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1012163 ) // ACTOR19 = HANDELOUP
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=HANDELOUP
          break;
        }
        if( param1 == 1012337 ) // ACTOR27 = BUTLER01580
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=BUTLER01580
          break;
        }
        if( param1 == 1012377 ) // ACTOR28 = STEWARD
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=STEWARD
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016050 ) // ACTOR29 = ACTOR29
        {
          Scene00034( quest, player ); // Scene00034: Normal(CutScene), id=ACTOR29
          // +Callback Scene00035: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
          // +Callback Scene00036: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1016051 ) // ACTOR30 = TATARU
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1013167 ) // ACTOR21 = LUCIA
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1012251 ) // ACTOR22 = HILDA
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1012252 ) // ACTOR23 = SYMME
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=SYMME
          break;
        }
        if( param1 == 1012253 ) // ACTOR24 = EUDESTAND
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=EUDESTAND
          break;
        }
        if( param1 == 1012163 ) // ACTOR19 = HANDELOUP
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=HANDELOUP
          break;
        }
        if( param1 == 1012337 ) // ACTOR27 = BUTLER01580
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=BUTLER01580
          break;
        }
        if( param1 == 1012377 ) // ACTOR28 = STEWARD
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=STEWARD
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
    quest.setSeq( 3 );
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
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
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00001: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 418, 85.0f, 24.0f, -6.53f, -1.77f, false );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00002: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00005: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00006: Normal(Talk, QuestBattle, YesNo, TargetCanMove, ENpcBind), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        //quest battle
        eventMgr().eventFinish( player, result.eventId, 1 );
        teriMgr().createAndJoinQuestBattle( player, 150 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00009: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00010: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00011: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00012: Empty(None), id=unknown" );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00013: Empty(None), id=unknown" );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00014: Empty(None), id=unknown" );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00016: Empty(None), id=unknown" );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00017: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00018: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00019: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00020: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00021: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00022: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00023: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, NONE, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR20, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00024: Normal(Talk, FadeIn, TargetCanMove, Menu, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 1, true );
        checkProgressSeq3( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00025: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00026: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00027: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00028: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR25, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR26, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00030: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00031: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR27, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00032: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, NONE, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR28, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00033: Normal(Talk, TargetCanMove), id=STEWARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, NONE, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR29, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00034: Normal(CutScene), id=ACTOR29" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00035( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 34, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR29, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00035: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00036( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 35, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR29, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00036: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      player.finishQuest( getId(), result.getResult( 1 ) );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.exitInstance();
    };
    eventMgr().playQuestScene( player, getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR30, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00037: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, NONE, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00038: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, NONE, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00039: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, NONE, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00040: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, NONE, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00041: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, NONE, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00042: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, NONE, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR27, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00043: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, NONE, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR28, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb108:67699 calling Scene00044: Normal(Talk, TargetCanMove), id=STEWARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnb108 );
