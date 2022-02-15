// FFXIVTheMovie.ParserV3.8
// param used:
//SCENE_7 REMOVED!!
//WARP_ADALA = 146|-53.45|-24.09|-567.49|-0.55|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManFst209 : public Sapphire::ScriptAPI::QuestScript
{
public:
  ManFst209() : Sapphire::ScriptAPI::QuestScript( 65879 ){}; 
  ~ManFst209() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 6 entries
  //SEQ_3, 13 entries
  //SEQ_4, 13 entries
  //SEQ_5, 11 entries
  //SEQ_255, 11 entries

  //ACTOR0 = 1005116
  //ACTOR1 = 1004584
  //ACTOR10 = 1004610
  //ACTOR11 = 1004611
  //ACTOR12 = 1005140
  //ACTOR13 = 1005141
  //ACTOR14 = 1005142
  //ACTOR15 = 1005143
  //ACTOR16 = 1005144
  //ACTOR17 = 1005145
  //ACTOR18 = 1005018
  //ACTOR2 = 1004585
  //ACTOR20 = 1005156
  //ACTOR21 = 1005146
  //ACTOR22 = 1005147
  //ACTOR23 = 1005148
  //ACTOR24 = 1005149
  //ACTOR25 = 1005150
  //ACTOR26 = 1005151
  //ACTOR27 = 1005152
  //ACTOR28 = 1005153
  //ACTOR29 = 1005154
  //ACTOR3 = 1004586
  //ACTOR30 = 1005155
  //ACTOR31 = 1005012
  //ACTOR4 = 1004587
  //ACTOR5 = 1005161
  //ACTOR6 = 1005017
  //ACTOR7 = 1004605
  //ACTOR8 = 1004606
  //ACTOR9 = 1004608
  //CUTMANFST20950 = 88
  //EOBJECT0 = 2001592
  //EVENTACTIONWAITINGSHOR = 11
  //INSTANCEDUNGEON0 = 20001
  //POPRANGE0 = 4165046
  //POPRANGE1 = 4156164
  //POPRANGE2 = 4148347
  //QUESTBATTLE0 = 45
  //TERRITORYTYPE0 = 275
  //TERRITORYTYPE1 = 146
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKIMAGEDUNGEON = 77

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
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA
        break;
      }
      case 1:
      {
        if( param1 == 1004584 ) // ACTOR1 = FLAMESGT
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=FLAMESGT
          }
          break;
        }
        if( param1 == 1004585 ) // ACTOR2 = unknown
        {
          Scene00003( quest, player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004586 ) // ACTOR3 = unknown
        {
          Scene00004( quest, player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004587 ) // ACTOR4 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005161 ) // ACTOR5 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2001592 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(QuestBattle, YesNo), id=unknown
          }
          break;
        }
        if( param1 == 1004584 ) // ACTOR1 = FLAMESGT
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=FLAMESGT
          break;
        }
        if( param1 == 1004585 ) // ACTOR2 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004586 ) // ACTOR3 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004587 ) // ACTOR4 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005161 ) // ACTOR5 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1005017 ) // ACTOR6 = FLAMESGT
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00014( quest, player ); // Scene00014: Normal(Talk, Message, TargetCanMove), id=FLAMESGT
          }
          break;
        }
        if( param1 == 1004605 ) // ACTOR7 = FLAMEPRIVATE2
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=FLAMEPRIVATE2
          break;
        }
        if( param1 == 1004606 ) // ACTOR8 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004608 ) // ACTOR9 = FLAMEPRIVATE
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=FLAMEPRIVATE
          break;
        }
        if( param1 == 1004610 ) // ACTOR10 = AMALJA
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=AMALJA
          break;
        }
        if( param1 == 1004611 ) // ACTOR11 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005140 ) // ACTOR12 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005141 ) // ACTOR13 = unknown
        {
          Scene00021( quest, player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005142 ) // ACTOR14 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005143 ) // ACTOR15 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005144 ) // ACTOR16 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005145 ) // ACTOR17 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005018 ) // ACTOR18 = ADALA
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, YesNo, TargetCanMove), id=ADALA
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1004605 ) // ACTOR7 = FLAMEPRIVATE2
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=FLAMEPRIVATE2
          break;
        }
        if( param1 == 1004606 ) // ACTOR8 = unknown
        {
          Scene00028( quest, player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004608 ) // ACTOR9 = FLAMEPRIVATE
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=FLAMEPRIVATE
          break;
        }
        if( param1 == 1004610 ) // ACTOR10 = AMALJA
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=AMALJA
          break;
        }
        if( param1 == 1004611 ) // ACTOR11 = unknown
        {
          Scene00031( quest, player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005017 ) // ACTOR6 = FLAMESGT
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=FLAMESGT
          break;
        }
        if( param1 == 1005140 ) // ACTOR12 = unknown
        {
          Scene00033( quest, player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005141 ) // ACTOR13 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005142 ) // ACTOR14 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005143 ) // ACTOR15 = unknown
        {
          Scene00036( quest, player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005144 ) // ACTOR16 = unknown
        {
          Scene00037( quest, player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005145 ) // ACTOR17 = unknown
        {
          Scene00038( quest, player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005018 ) // ACTOR18 = ADALA
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, YesNo, TargetCanMove), id=ADALA
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1005156 ) // ACTOR20 = THANCRED
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00040( quest, player ); // Scene00040: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED
          }
          break;
        }
        if( param1 == 1005146 ) // ACTOR21 = unknown
        {
          Scene00041( quest, player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005147 ) // ACTOR22 = unknown
        {
          Scene00042( quest, player ); // Scene00042: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005148 ) // ACTOR23 = unknown
        {
          Scene00043( quest, player ); // Scene00043: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005149 ) // ACTOR24 = unknown
        {
          Scene00044( quest, player ); // Scene00044: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005150 ) // ACTOR25 = unknown
        {
          Scene00045( quest, player ); // Scene00045: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005151 ) // ACTOR26 = unknown
        {
          Scene00046( quest, player ); // Scene00046: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005152 ) // ACTOR27 = unknown
        {
          Scene00047( quest, player ); // Scene00047: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005153 ) // ACTOR28 = unknown
        {
          Scene00048( quest, player ); // Scene00048: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005154 ) // ACTOR29 = unknown
        {
          Scene00049( quest, player ); // Scene00049: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005155 ) // ACTOR30 = unknown
        {
          Scene00050( quest, player ); // Scene00050: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1005012 ) // ACTOR31 = GUIDE
        {
          Scene00051( quest, player ); // Scene00051: Normal(Talk, QuestReward, TargetCanMove), id=GUIDE
          // +Callback Scene00052: Normal(CutScene, QuestComplete, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1005146 ) // ACTOR21 = unknown
        {
          Scene00053( quest, player ); // Scene00053: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005147 ) // ACTOR22 = unknown
        {
          Scene00054( quest, player ); // Scene00054: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005148 ) // ACTOR23 = unknown
        {
          Scene00055( quest, player ); // Scene00055: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005149 ) // ACTOR24 = unknown
        {
          Scene00056( quest, player ); // Scene00056: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005150 ) // ACTOR25 = unknown
        {
          Scene00057( quest, player ); // Scene00057: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005151 ) // ACTOR26 = unknown
        {
          Scene00058( quest, player ); // Scene00058: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005152 ) // ACTOR27 = unknown
        {
          Scene00059( quest, player ); // Scene00059: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005153 ) // ACTOR28 = unknown
        {
          Scene00060( quest, player ); // Scene00060: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005154 ) // ACTOR29 = unknown
        {
          Scene00061( quest, player ); // Scene00061: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005155 ) // ACTOR30 = unknown
        {
          Scene00062( quest, player ); // Scene00062: Normal(None), id=unknown
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
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag16( 1, false );
      quest.setSeq( 4 );
    }
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 5 );
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag16( 1, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00002: Normal(Talk, TargetCanMove), id=FLAMESGT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00008: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        //quest battle
        eventMgr().eventFinish( player, result.eventId, 1 );
        teriMgr().createAndJoinQuestBattle( player, 45 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00009: Normal(Talk, TargetCanMove), id=FLAMESGT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, UI8AL = 1, Flag16(1)=True
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00014: Normal(Talk, Message, TargetCanMove), id=FLAMESGT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag16( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00015: Normal(Talk, TargetCanMove), id=FLAMEPRIVATE2" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00017: Normal(Talk, TargetCanMove), id=FLAMEPRIVATE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00018: Normal(Talk, TargetCanMove), id=AMALJA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00026: Normal(Talk, YesNo, TargetCanMove), id=ADALA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.forceZoneing( 146, -53.45f, -24.09f, -567.49f, -0.55f, false );
      }
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00027: Normal(Talk, TargetCanMove), id=FLAMEPRIVATE2" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00029: Normal(Talk, TargetCanMove), id=FLAMEPRIVATE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00030: Normal(Talk, TargetCanMove), id=AMALJA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00032: Normal(Talk, TargetCanMove), id=FLAMESGT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, NONE, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00037: Normal(None), id=unknown" );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00038: Normal(None), id=unknown" );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00039: Normal(Talk, YesNo, TargetCanMove), id=ADALA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.forceZoneing( 146, -53.45f, -24.09f, -567.49f, -0.55f, false );
      }
    };
    eventMgr().playQuestScene( player, getId(), 39, NONE, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR20, UI8AL = 1, Flag16(1)=True
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00040: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag16( 1, true );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 40, NONE, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00044: Normal(None), id=unknown" );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR25, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00045: Normal(None), id=unknown" );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR26, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00046: Normal(None), id=unknown" );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR27, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00047: Normal(None), id=unknown" );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR28, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00048: Normal(None), id=unknown" );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR29, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00049: Normal(None), id=unknown" );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR30, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00050: Normal(None), id=unknown" );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR31, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00051: Normal(Talk, QuestReward, TargetCanMove), id=GUIDE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00052( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 51, NONE, callback );
  }
  void Scene00052( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR31, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00052: Normal(CutScene, QuestComplete, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      player.finishQuest( getId(), result.getResult( 1 ) );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 52, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00053( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00053: Normal(None), id=unknown" );
  }

  void Scene00054( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00054: Normal(None), id=unknown" );
  }

  void Scene00055( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00055: Normal(None), id=unknown" );
  }

  void Scene00056( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00056: Normal(None), id=unknown" );
  }

  void Scene00057( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR25, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00057: Normal(None), id=unknown" );
  }

  void Scene00058( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR26, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00058: Normal(None), id=unknown" );
  }

  void Scene00059( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR27, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00059: Normal(None), id=unknown" );
  }

  void Scene00060( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR28, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00060: Normal(None), id=unknown" );
  }

  void Scene00061( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR29, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00061: Normal(None), id=unknown" );
  }

  void Scene00062( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR30, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManFst209:65879 calling Scene00062: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( ManFst209 );
