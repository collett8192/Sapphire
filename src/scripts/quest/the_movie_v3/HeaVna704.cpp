// FFXIVTheMovie.ParserV3.9
// param used:
//SCENE_35 = dummy
//SCENE_36 = dummy
//SCENE_38 = GUIDANCESYSTEM
//SCENE_42 = dummye3
//SCENE_43 = dummye3
//WARP_SCENE43 = 402|633.6|10.62|73.6|1|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna704 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna704() : Sapphire::ScriptAPI::QuestScript( 67202 ){}; 
  ~HeaVna704() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 4 entries
  //SEQ_2, 18 entries
  //SEQ_3, 4 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1012802
  //ACTOR1 = 1012803
  //ACTOR10 = 1012816
  //ACTOR11 = 1012817
  //ACTOR12 = 1012818
  //ACTOR13 = 1012819
  //ACTOR14 = 1012820
  //ACTOR2 = 1012804
  //ACTOR3 = 1012805
  //ACTOR4 = 1012807
  //ACTOR5 = 1012808
  //ACTOR6 = 1012809
  //ACTOR7 = 1012810
  //ACTOR8 = 1012814
  //ACTOR9 = 1012815
  //CUTSCENEN01 = 893
  //CUTSCENEN02 = 1020
  //CUTSCENEN03 = 1020
  //ENEMY0 = 5868108
  //ENEMY1 = 5868109
  //ENEMY2 = 5868110
  //ENEMY3 = 5868111
  //ENEMY4 = 5868112
  //ENEMY5 = 5868113
  //ENEMY6 = 5868114
  //EOBJECT0 = 2005567
  //EOBJECT1 = 2005568
  //EOBJECT2 = 2005569
  //EOBJECT3 = 2006364
  //EVENTACTIONLOOKOUTMIDDLE = 50
  //EVENTACTIONSEARCH = 1
  //LOCACTOR0 = 5867516
  //LOCACTOR1 = 5867517
  //LOCACTOR10 = 5867543
  //LOCACTOR11 = 5867544
  //LOCACTOR12 = 5867545
  //LOCACTOR2 = 5867518
  //POPRANGE0 = 5918521

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
        if( param1 == 1012802 ) // ACTOR0 = GUIDANCESYSTEM
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=GUIDANCESYSTEM
          }
          break;
        }
        if( param1 == 1012803 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012804 ) // ACTOR2 = ESTINIEN
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012805 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012807 ) // ACTOR4 = GUIDANCESYSTEM
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=GUIDANCESYSTEM
          }
          break;
        }
        if( param1 == 1012808 ) // ACTOR5 = ALPHINAUD
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012809 ) // ACTOR6 = ESTINIEN
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012810 ) // ACTOR7 = YSHTOLA
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2005567 ) // EOBJECT0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT0
        if( param1 == 5868108 ) // ENEMY0 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5868109 ) // ENEMY1 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2005568 ) // EOBJECT1 = unknown
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00016( quest, player ); // Scene00016: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT1
        if( param1 == 5868110 ) // ENEMY2 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5868111 ) // ENEMY3 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2005569 ) // EOBJECT2 = unknown
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00022( quest, player ); // Scene00022: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT2
        if( param1 == 5868112 ) // ENEMY4 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5868113 ) // ENEMY5 = unknown
        {
          Scene00026( quest, player ); // Scene00026: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5868114 ) // ENEMY6 = unknown
        {
          Scene00028( quest, player ); // Scene00028: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1012807 ) // ACTOR4 = GUIDANCESYSTEM
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM
          break;
        }
        if( param1 == 1012814 ) // ACTOR8 = ALPHINAUD
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012815 ) // ACTOR9 = ESTINIEN
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012816 ) // ACTOR10 = YSHTOLA
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012817 ) // ACTOR11 = unknown
        {
          Scene00033( quest, player ); // Scene00033: Empty(None), id=unknown
          break;
        }
        if( param1 == 1012818 ) // ACTOR12 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Empty(None), id=unknown
          break;
        }
        if( param1 == 1012819 ) // ACTOR13 = dummy
        {
          Scene00036( quest, player ); // Scene00036: Empty(None), id=dummy
          break;
        }
        if( param1 == 1012820 ) // ACTOR14 = GUIDANCESYSTEM
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1012807 ) // ACTOR4 = GUIDANCESYSTEM
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00038( quest, player ); // Scene00038: Normal(CutScene), id=GUIDANCESYSTEM
          }
          break;
        }
        if( param1 == 1012808 ) // ACTOR5 = ALPHINAUD
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012809 ) // ACTOR6 = ESTINIEN
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012810 ) // ACTOR7 = YSHTOLA
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 2006364 ) // EOBJECT3 = dummye3
        {
          Scene00042( quest, player ); // Scene00042: Normal(CutScene), id=dummye3
          // +Callback Scene00043: Normal(FadeIn, QuestReward, QuestComplete), id=dummye3
          break;
        }
        if( param1 == 1012807 ) // ACTOR4 = GUIDANCESYSTEM
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM
          break;
        }
        if( param1 == 1012808 ) // ACTOR5 = ALPHINAUD
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012809 ) // ACTOR6 = ESTINIEN
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012810 ) // ACTOR7 = YSHTOLA
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=YSHTOLA
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
    if( quest.getUI8BL() == 2 )
      if( quest.getUI8AL() == 2 )
        if( quest.getUI8BH() == 3 )
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
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00007: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, UI8BL = 2, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 2 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, UI8AL = 2, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00016: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 2 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00018: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00020: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT2, UI8BH = 3, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00022: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 3 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00024: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00026: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00028: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00029: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00031: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00032: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, NONE, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00033: Empty(None), id=unknown" );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00034: Empty(None), id=unknown" );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00036: Empty(None), id=dummy" );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00037: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, NONE, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00038: Normal(CutScene), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 38, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00039: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, NONE, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00040: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, NONE, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00041: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, NONE, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00042: Normal(CutScene), id=dummye3" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00043( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 42, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00043: Normal(FadeIn, QuestReward, QuestComplete), id=dummye3" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.forceZoneing( 402, 633.6f, 10.62f, 73.6f, 1.0f, false );
      }
    };
    eventMgr().playQuestScene( player, getId(), 43, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00044: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, NONE, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00045: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, NONE, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00046: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, NONE, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna704:67202 calling Scene00047: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna704 );
