// FFXIVTheMovie.ParserV3.9
// missing quest battle
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc109 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVnc109() : Sapphire::ScriptAPI::QuestScript( 67775 ){}; 
  ~HeaVnc109() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 10 entries
  //SEQ_2, 11 entries
  //SEQ_3, 1 entries
  //SEQ_4, 9 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1015978
  //ACTOR1 = 1016583
  //ACTOR10 = 1016586
  //ACTOR11 = 1017096
  //ACTOR12 = 1016072
  //ACTOR13 = 1016073
  //ACTOR2 = 1016587
  //ACTOR3 = 1016588
  //ACTOR4 = 1016074
  //ACTOR5 = 1016075
  //ACTOR6 = 1016076
  //ACTOR7 = 1017095
  //ACTOR8 = 1006455
  //ACTOR9 = 1006456
  //CUTSCENEN01 = 1150
  //CUTSCENEN02 = 1151
  //CUTSCENEN03 = 1169
  //EOBJECT0 = 2006860
  //LOCACTOR0 = 6185296
  //LOCACTOR10 = 6197374
  //LOCMPEQ0ARM = 15
  //LOCMPEQ0BODY = 14
  //LOCMPEQ0FEET = 17
  //LOCMPEQ0HEAD = 18
  //LOCMPEQ0LEG = 16
  //QUESTBATTLE0 = 5001
  //TERRITORYTYPE0 = 533
  //TERRITORYTYPE1 = 155

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
        if( param1 == 1015978 ) // ACTOR0 = LUCIA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LUCIA
          }
          break;
        }
        if( param1 == 1016583 ) // ACTOR1 = THANCRED
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1016587 ) // ACTOR2 = EMMANELLAIN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          }
          break;
        }
        if( param1 == 1016588 ) // ACTOR3 = THANCRED
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1016074 ) // ACTOR4 = AYMERIC
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1016075 ) // ACTOR5 = LUCIA
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1016076 ) // ACTOR6 = HILDA
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1017095 ) // ACTOR7 = MESSENGER02239
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=MESSENGER02239
          break;
        }
        if( param1 == 1006455 ) // ACTOR8 = LOANNE
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=LOANNE
          break;
        }
        if( param1 == 1006456 ) // ACTOR9 = CHAUNOLLET
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=CHAUNOLLET
          break;
        }
        if( param1 == 1016586 ) // ACTOR10 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017096 ) // ACTOR11 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1016587 ) // ACTOR2 = EMMANELLAIN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, QuestBattle, YesNo, TargetCanMove, SystemTalk, CanCancel), id=EMMANELLAIN
            // +Callback Scene00014: Normal(CutScene, AutoFadeIn, ReturnTrue), id=unknown
          }
          break;
        }
        if( param1 == 1016588 ) // ACTOR3 = THANCRED
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1016074 ) // ACTOR4 = AYMERIC
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1016075 ) // ACTOR5 = LUCIA
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1016076 ) // ACTOR6 = HILDA
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1017095 ) // ACTOR7 = MESSENGER02239
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=MESSENGER02239
          break;
        }
        if( param1 == 1006455 ) // ACTOR8 = LOANNE
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=LOANNE
          break;
        }
        if( param1 == 1006456 ) // ACTOR9 = CHAUNOLLET
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=CHAUNOLLET
          break;
        }
        if( param1 == 2006860 ) // EOBJECT0 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016586 ) // ACTOR10 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Empty(None), id=unknown
          break;
        }
        if( param1 == 1017096 ) // ACTOR11 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00025( quest, player ); // Scene00025: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1016072 ) // ACTOR12 = RAUBAHN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove, ENpcBind), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1016073 ) // ACTOR13 = PIPPIN
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=PIPPIN
          break;
        }
        if( param1 == 1016587 ) // ACTOR2 = EMMANELLAIN
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1016588 ) // ACTOR3 = THANCRED
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1016074 ) // ACTOR4 = AYMERIC
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1016075 ) // ACTOR5 = LUCIA
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1016076 ) // ACTOR6 = HILDA
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1006455 ) // ACTOR8 = LOANNE
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=LOANNE
          break;
        }
        if( param1 == 1006456 ) // ACTOR9 = CHAUNOLLET
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=CHAUNOLLET
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016588 ) // ACTOR3 = THANCRED
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=THANCRED
          break;
        }
        if( param1 == 1016587 ) // ACTOR2 = EMMANELLAIN
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1016074 ) // ACTOR4 = AYMERIC
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1016075 ) // ACTOR5 = LUCIA
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1016076 ) // ACTOR6 = HILDA
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1006455 ) // ACTOR8 = LOANNE
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=LOANNE
          break;
        }
        if( param1 == 1006456 ) // ACTOR9 = CHAUNOLLET
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=CHAUNOLLET
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
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00004: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00005: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00006: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00007: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00008: Normal(Talk, TargetCanMove), id=MESSENGER02239" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00009: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00010: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00011: Empty(None), id=unknown" );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00012: Empty(None), id=unknown" );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00013: Normal(Talk, QuestBattle, YesNo, TargetCanMove, SystemTalk, CanCancel), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00014( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }
  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00014: Normal(CutScene, AutoFadeIn, ReturnTrue), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      //quest battle
      //eventMgr().eventFinish( player, result.eventId, 1 );
      //teriMgr().createAndJoinQuestBattle( player, 5001 );
      Scene00025( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00015: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00016: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00017: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00018: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00019: Normal(Talk, TargetCanMove), id=MESSENGER02239" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00020: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00021: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00022: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00023: Empty(None), id=unknown" );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00024: Empty(None), id=unknown" );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00025: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR12, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00026: Normal(Talk, TargetCanMove, ENpcBind), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00027: Normal(Talk, TargetCanMove), id=PIPPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00028: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00029: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00030: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00031: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00032: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, NONE, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00033: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, NONE, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00034: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, NONE, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 35, NONE, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00036: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, NONE, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00037: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, NONE, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00038: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, NONE, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00039: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, NONE, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00040: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, NONE, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc109:67775 calling Scene00041: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnc109 );
