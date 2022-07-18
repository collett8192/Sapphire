// FFXIVTheMovie.ParserV3.10
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc105 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVnc105() : Sapphire::ScriptAPI::QuestScript( 67771 ){}; 
  ~HeaVnc105() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 12 entries
  //SEQ_2, 7 entries
  //SEQ_3, 12 entries
  //SEQ_255, 10 entries

  //ACTOR0 = 1016566
  //ACTOR1 = 1016567
  //ACTOR10 = 1016576
  //ACTOR11 = 1016577
  //ACTOR12 = 1016077
  //ACTOR2 = 1016568
  //ACTOR3 = 1016569
  //ACTOR4 = 1016570
  //ACTOR5 = 1016571
  //ACTOR6 = 1016572
  //ACTOR7 = 1016573
  //ACTOR8 = 1016574
  //ACTOR9 = 1016575
  //ENEMY0 = 6185517
  //ENEMY1 = 6185518
  //ENEMY2 = 6185519
  //ENEMY3 = 6200474
  //ENEMY4 = 6200475
  //EOBJECT0 = 2006869
  //EOBJECT1 = 2006870
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONWATCHGUARDMIDDLE = 56
  //LOCACTOR0 = 6184576
  //LOCACTOR10 = 6184664
  //LOCACTOR11 = 6184665

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
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=EMMANELLAIN
          }
          break;
        }
        if( param1 == 1016567 ) // ACTOR1 = HONOROIT
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        if( param1 == 1016571 ) // ACTOR5 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016572 ) // ACTOR6 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2006869 ) // EOBJECT0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT0
        if( param1 == 6185517 ) // ENEMY0 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6185518 ) // ENEMY1 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6185519 ) // ENEMY2 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        if( param1 == 1016571 ) // ACTOR5 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016572 ) // ACTOR6 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Empty(None), id=unknown
          break;
        }
        if( param1 == 2006870 ) // EOBJECT1 = unknown
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00022( quest, player ); // Scene00022: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT1
        if( param1 == 6200474 ) // ENEMY3 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6200475 ) // ENEMY4 = unknown
        {
          Scene00026( quest, player ); // Scene00026: Normal(Message, PopBNpc), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1016566 ) // ACTOR0 = EMMANELLAIN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          }
          break;
        }
        if( param1 == 1016567 ) // ACTOR1 = HONOROIT
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        if( param1 == 1016571 ) // ACTOR5 = unknown
        {
          Scene00032( quest, player ); // Scene00032: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016572 ) // ACTOR6 = unknown
        {
          Scene00033( quest, player ); // Scene00033: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1016573 ) // ACTOR7 = THANCRED
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=THANCRED
          }
          break;
        }
        if( param1 == 1016574 ) // ACTOR8 = HERETIC02235
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=HERETIC02235
          break;
        }
        if( param1 == 1016566 ) // ACTOR0 = EMMANELLAIN
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1016567 ) // ACTOR1 = HONOROIT
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=CITIZENA02233
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
        if( param1 == 1016575 ) // ACTOR9 = unknown
        {
          Scene00041( quest, player ); // Scene00041: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016576 ) // ACTOR10 = unknown
        {
          Scene00042( quest, player ); // Scene00042: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016577 ) // ACTOR11 = unknown
        {
          Scene00043( quest, player ); // Scene00043: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016571 ) // ACTOR5 = unknown
        {
          Scene00044( quest, player ); // Scene00044: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016572 ) // ACTOR6 = unknown
        {
          Scene00045( quest, player ); // Scene00045: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016566 ) // ACTOR0 = EMMANELLAIN
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=EMMANELLAIN
          break;
        }
        if( param1 == 1016567 ) // ACTOR1 = HONOROIT
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        if( param1 == 1016077 ) // ACTOR12 = THANCRED
        {
          Scene00051( quest, player ); // Scene00051: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1016571 ) // ACTOR5 = unknown
        {
          Scene00052( quest, player ); // Scene00052: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016572 ) // ACTOR6 = unknown
        {
          Scene00053( quest, player ); // Scene00053: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016576 ) // ACTOR10 = unknown
        {
          Scene00054( quest, player ); // Scene00054: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016577 ) // ACTOR11 = unknown
        {
          Scene00055( quest, player ); // Scene00055: Empty(None), id=unknown
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
    if( quest.getUI8BH() == 3 )
      if( quest.getUI8AL() == 2 )
      {
        quest.setUI8BH( 0 );
        quest.setUI8AL( 0 );
        quest.setBitFlag8( 1, false );
        quest.setBitFlag8( 2, false );
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
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00002: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00003: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00004: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00005: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00006: Empty(None), id=unknown" );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00007: Empty(None), id=unknown" );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8BH = 3, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 3 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00015: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00016: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00017: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00018: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00019: Empty(None), id=unknown" );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00020: Empty(None), id=unknown" );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT1, UI8AL = 2, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00022: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 2 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00024: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00026: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00027: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00028: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00029: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00030: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00031: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00032: Empty(None), id=unknown" );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00033: Empty(None), id=unknown" );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00034: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 34, NONE, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00035: Normal(Talk, TargetCanMove), id=HERETIC02235" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, NONE, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00036: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, NONE, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00037: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, NONE, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00038: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, NONE, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00039: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, NONE, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00040: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, NONE, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00041: Empty(None), id=unknown" );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00042: Empty(None), id=unknown" );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00043: Empty(None), id=unknown" );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00044: Empty(None), id=unknown" );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00045: Empty(None), id=unknown" );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00046: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 46, NONE, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00047: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, NONE, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00048: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, NONE, callback );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00049: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 49, NONE, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00050: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 50, NONE, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00051: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 51, NONE, callback );
  }

  void Scene00052( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00052: Empty(None), id=unknown" );
  }

  void Scene00053( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00053: Empty(None), id=unknown" );
  }

  void Scene00054( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00054: Empty(None), id=unknown" );
  }

  void Scene00055( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc105:67771 calling Scene00055: Empty(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( HeaVnc105 );
