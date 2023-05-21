// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda102 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda102() : Sapphire::ScriptAPI::QuestScript( 67983 ){}; 
  ~StmBda102() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 5 entries
  //SEQ_4, 6 entries
  //SEQ_255, 8 entries

  //ACTOR0 = 1020527
  //ACTOR1 = 1020525
  //ACTOR10 = 1020316
  //ACTOR11 = 1020314
  //ACTOR12 = 1020315
  //ACTOR13 = 1020317
  //ACTOR14 = 1020318
  //ACTOR15 = 1020321
  //ACTOR16 = 1020319
  //ACTOR17 = 1020320
  //ACTOR18 = 1020322
  //ACTOR19 = 1020323
  //ACTOR2 = 1020526
  //ACTOR20 = 1020329
  //ACTOR21 = 1020324
  //ACTOR22 = 1020325
  //ACTOR23 = 1020326
  //ACTOR24 = 1020327
  //ACTOR25 = 1020328
  //ACTOR26 = 1020330
  //ACTOR27 = 1020331
  //ACTOR3 = 1020308
  //ACTOR4 = 1020495
  //ACTOR5 = 1020311
  //ACTOR6 = 1020309
  //ACTOR7 = 1020310
  //ACTOR8 = 1020312
  //ACTOR9 = 1020313
  //BINDACTOR01 = 6844562
  //BINDACTOR02 = 6844563
  //BINDACTOR03 = 6829372
  //BINDACTOR04 = 6829371
  //BINDACTOR11 = 6829385
  //BINDACTOR12 = 6829386
  //BINDACTOR13 = 6829388
  //BINDACTOR14 = 6829389
  //CUTSCENEN01 = 1382
  //LOCACTION01 = 85
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1017687
  //LOCACTOR03 = 1011889
  //LOCACTOR04 = 1015833
  //LOCBGM01 = 148
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //LOCSE01 = 91
  //POPRANGE0 = 6829433
  //TERRITORYTYPE0 = 635

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
        if( param1 == 1020527 ) // ACTOR0 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=LYSE
          }
          break;
        }
        if( param1 == 1020525 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020526 ) // ACTOR2 = ALISAIE
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020308 ) // ACTOR3 = KRILE
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1020495 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020311 ) // ACTOR5 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove, ENpcBind), id=LYSE
          }
          break;
        }
        if( param1 == 1020309 ) // ACTOR6 = ALPHINAUD
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020310 ) // ACTOR7 = ALISAIE
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020312 ) // ACTOR8 = YSHTOLA
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1020313 ) // ACTOR9 = KRILE
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020316 ) // ACTOR10 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020314 ) // ACTOR11 = ALPHINAUD
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020315 ) // ACTOR12 = ALISAIE
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020317 ) // ACTOR13 = YSHTOLA
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1020318 ) // ACTOR14 = KRILE
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020321 ) // ACTOR15 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00016( quest, player ); // Scene00016: Normal(Talk, FadeIn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020319 ) // ACTOR16 = ALPHINAUD
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020320 ) // ACTOR17 = ALISAIE
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020322 ) // ACTOR18 = YSHTOLA
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1020323 ) // ACTOR19 = KRILE
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        break;
      }
      case 4:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00021( quest, player ); // Scene00021: Normal(CutScene, Dismount, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1020319 ) // ACTOR16 = ALPHINAUD
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020320 ) // ACTOR17 = ALISAIE
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020321 ) // ACTOR15 = LYSE
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020322 ) // ACTOR18 = YSHTOLA
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1020323 ) // ACTOR19 = KRILE
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020329 ) // ACTOR20 = CONRAD
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020324 ) // ACTOR21 = ALPHINAUD
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020325 ) // ACTOR22 = ALISAIE
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020326 ) // ACTOR23 = LYSE
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020327 ) // ACTOR24 = YSHTOLA
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1020328 ) // ACTOR25 = KRILE
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1020330 ) // ACTOR26 = MNAAGO
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020331 ) // ACTOR27 = MEFFRID
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=MEFFRID
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

  void onBNpcKill( World::Quest& quest, Entity::BNpc& bnpc, Entity::Player& player ) override
  {
    onProgress( quest, player, EVENT_ON_BNPC_KILL, static_cast< uint64_t >( bnpc.getBNpcNameId() ), bnpc.getLayoutId(), 0 );
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
      quest.setBitFlag8( 1, false );
      quest.setSeq( 4 );
    }
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, HIDE_HOTBAR, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00004: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00006: Normal(Talk, TargetCanMove, ENpcBind), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00010: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00014: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00015: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR15, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00016: Normal(Talk, FadeIn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00019: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00020: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_4: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00021: Normal(CutScene, Dismount, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00024: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00025: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00026: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00027: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00029: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00030: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00031: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR25, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00032: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR26, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00033: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR27, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda102:67983 calling Scene00034: Normal(Talk, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda102 );
