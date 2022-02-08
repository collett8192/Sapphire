// FFXIVTheMovie.ParserV3.8
// param used:
//SCENE_35 = EDMONT
//_ACTOR8 = B
//_ACTOR8B = 2|2
//_ACTOR9 = B
//_ACTOR9B = 2|2
//_ACTOR10 = B
//_ACTOR10B = 2|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna613 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna613() : Sapphire::ScriptAPI::QuestScript( 67198 ){}; 
  ~HeaVna613() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 8 entries
  //SEQ_2, 14 entries
  //SEQ_3, 15 entries
  //SEQ_255, 15 entries

  //ACTOR0 = 1012430
  //ACTOR1 = 1012431
  //ACTOR10 = 1012251
  //ACTOR11 = 1012377
  //ACTOR12 = 1012252
  //ACTOR13 = 1012253
  //ACTOR14 = 1012397
  //ACTOR15 = 1013173
  //ACTOR16 = 1013174
  //ACTOR17 = 1013175
  //ACTOR2 = 1012432
  //ACTOR3 = 1013166
  //ACTOR4 = 1012407
  //ACTOR5 = 1013104
  //ACTOR6 = 1013105
  //ACTOR7 = 1013176
  //ACTOR8 = 1013167
  //ACTOR9 = 1013161
  //CUTSCENEN01 = 1039

  static constexpr auto EVENT_ON_TALK = 0;
  static constexpr auto EVENT_ON_EMOTE = 1;
  static constexpr auto EVENT_ON_BNPC_KILL = 2;
  static constexpr auto EVENT_ON_WITHIN_RANGE = 3;
  static constexpr auto EVENT_ON_ENTER_TERRITORY = 4;
  static constexpr auto EVENT_ON_EVENT_ITEM = 5;
  static constexpr auto EVENT_ON_EOBJ_HIT = 6;

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
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1012431 ) // ACTOR1 = YSHTOLA
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012432 ) // ACTOR2 = ESTINIEN
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013166 ) // ACTOR3 = AYMERIC
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1012407 ) // ACTOR4 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013104 ) // ACTOR5 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013105 ) // ACTOR6 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013176 ) // ACTOR7 = NOTRELCHAMPS
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1013166 ) // ACTOR3 = AYMERIC
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=AYMERIC
          }
          break;
        }
        if( param1 == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012431 ) // ACTOR1 = YSHTOLA
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012432 ) // ACTOR2 = ESTINIEN
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012407 ) // ACTOR4 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013104 ) // ACTOR5 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013105 ) // ACTOR6 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013176 ) // ACTOR7 = NOTRELCHAMPS
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1013167 ) // ACTOR8 = LUCIA, CB=2
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=LUCIA
          }
          else
          {
            Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=LUCIA
          }
          break;
        }
        if( param1 == 1013161 ) // ACTOR9 = TATARU, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=TATARU
          }
          else
          {
            Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=TATARU
          }
          break;
        }
        if( param1 == 1012251 ) // ACTOR10 = HILDA, CB=2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=HILDA
          }
          else
          {
            Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=HILDA
          }
          break;
        }
        if( param1 == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012431 ) // ACTOR1 = YSHTOLA
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012432 ) // ACTOR2 = ESTINIEN
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013166 ) // ACTOR3 = AYMERIC
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1012407 ) // ACTOR4 = unknown
        {
          Scene00027( quest, player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013104 ) // ACTOR5 = unknown
        {
          Scene00028( quest, player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013105 ) // ACTOR6 = unknown
        {
          Scene00029( quest, player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013176 ) // ACTOR7 = NOTRELCHAMPS
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
          break;
        }
        if( param1 == 1012377 ) // ACTOR11 = BUTLER01580
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=BUTLER01580
          break;
        }
        if( param1 == 1012252 ) // ACTOR12 = SYMME
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=SYMME
          break;
        }
        if( param1 == 1012253 ) // ACTOR13 = EUDESTAND
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=EUDESTAND
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1012397 ) // ACTOR14 = EDMONT
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=EDMONT
            // +Callback Scene00035: Normal(CutScene), id=EDMONT
          }
          break;
        }
        if( param1 == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012431 ) // ACTOR1 = YSHTOLA
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012432 ) // ACTOR2 = ESTINIEN
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013166 ) // ACTOR3 = AYMERIC
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1012407 ) // ACTOR4 = unknown
        {
          Scene00040( quest, player ); // Scene00040: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013104 ) // ACTOR5 = unknown
        {
          Scene00041( quest, player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013105 ) // ACTOR6 = unknown
        {
          Scene00042( quest, player ); // Scene00042: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013176 ) // ACTOR7 = NOTRELCHAMPS
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
          break;
        }
        if( param1 == 1012377 ) // ACTOR11 = BUTLER01580
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=BUTLER01580
          break;
        }
        if( param1 == 1012252 ) // ACTOR12 = SYMME
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=SYMME
          break;
        }
        if( param1 == 1012253 ) // ACTOR13 = EUDESTAND
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=EUDESTAND
          break;
        }
        if( param1 == 1013167 ) // ACTOR8 = LUCIA
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1013161 ) // ACTOR9 = TATARU
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1012251 ) // ACTOR10 = HILDA
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012431 ) // ACTOR1 = YSHTOLA
        {
          Scene00051( quest, player ); // Scene00051: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012432 ) // ACTOR2 = ESTINIEN
        {
          Scene00052( quest, player ); // Scene00052: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013166 ) // ACTOR3 = AYMERIC
        {
          Scene00053( quest, player ); // Scene00053: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1013173 ) // ACTOR15 = unknown
        {
          Scene00054( quest, player ); // Scene00054: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013174 ) // ACTOR16 = unknown
        {
          Scene00055( quest, player ); // Scene00055: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013175 ) // ACTOR17 = unknown
        {
          Scene00056( quest, player ); // Scene00056: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013176 ) // ACTOR7 = NOTRELCHAMPS
        {
          Scene00057( quest, player ); // Scene00057: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
          break;
        }
        if( param1 == 1012397 ) // ACTOR14 = EDMONT
        {
          Scene00058( quest, player ); // Scene00058: Normal(Talk, TargetCanMove), id=EDMONT
          break;
        }
        if( param1 == 1013167 ) // ACTOR8 = LUCIA
        {
          Scene00059( quest, player ); // Scene00059: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1013161 ) // ACTOR9 = TATARU
        {
          Scene00060( quest, player ); // Scene00060: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1012251 ) // ACTOR10 = HILDA
        {
          Scene00061( quest, player ); // Scene00061: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1012377 ) // ACTOR11 = BUTLER01580
        {
          Scene00062( quest, player ); // Scene00062: Normal(Talk, TargetCanMove), id=BUTLER01580
          break;
        }
        if( param1 == 1012252 ) // ACTOR12 = SYMME
        {
          Scene00063( quest, player ); // Scene00063: Normal(Talk, TargetCanMove), id=SYMME
          break;
        }
        if( param1 == 1012253 ) // ACTOR13 = EUDESTAND
        {
          Scene00064( quest, player ); // Scene00064: Normal(Talk, TargetCanMove), id=EUDESTAND
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
          quest.setSeq( 3 );
        }
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
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00004: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00008: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00009: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00012: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00016: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, UI8BL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00017: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }
  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, UI8BL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00018: Normal(Talk, TargetCanMove), id=LUCIA" );
    eventMgr().playQuestScene( player, getId(), 18, NONE, nullptr );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00019: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }
  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00020: Normal(Talk, TargetCanMove), id=TATARU" );
    eventMgr().playQuestScene( player, getId(), 20, NONE, nullptr );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00021: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }
  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00022: Normal(Talk, TargetCanMove), id=HILDA" );
    eventMgr().playQuestScene( player, getId(), 22, NONE, nullptr );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, NONE, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00025: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00026: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00030: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00031: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00032: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, NONE, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00033: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, NONE, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR14, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00034: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00035( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 34, NONE, callback );
  }
  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR14, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00035: Normal(CutScene), id=EDMONT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 35, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, NONE, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00037: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, NONE, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00038: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, NONE, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00039: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, NONE, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00043: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, NONE, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00044: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, NONE, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00045: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, NONE, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00046: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, NONE, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00047: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, NONE, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00048: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, NONE, callback );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00049: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 49, NONE, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00050: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 50, NONE, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00051: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 51, NONE, callback );
  }

  void Scene00052( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00052: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 52, NONE, callback );
  }

  void Scene00053( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00053: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 53, NONE, callback );
  }

  void Scene00054( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00054: Normal(None), id=unknown" );
  }

  void Scene00055( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00055: Normal(None), id=unknown" );
  }

  void Scene00056( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00056: Normal(None), id=unknown" );
  }

  void Scene00057( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00057: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 57, NONE, callback );
  }

  void Scene00058( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00058: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 58, NONE, callback );
  }

  void Scene00059( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00059: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 59, NONE, callback );
  }

  void Scene00060( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00060: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 60, NONE, callback );
  }

  void Scene00061( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00061: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 61, NONE, callback );
  }

  void Scene00062( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00062: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 62, NONE, callback );
  }

  void Scene00063( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00063: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 63, NONE, callback );
  }

  void Scene00064( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna613:67198 calling Scene00064: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 64, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna613 );
