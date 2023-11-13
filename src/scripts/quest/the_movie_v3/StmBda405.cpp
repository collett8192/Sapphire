// FFXIVTheMovie.ParserV3.11
// param used:
//ENEMY10 = dummye10
//ENEMY11 = dummye11
//SCENE_40 = dummye10
//SCENE_42 = dummye11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda405 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda405() : Sapphire::ScriptAPI::QuestScript( 68040 ){}; 
  ~StmBda405() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 3 entries
  //SEQ_2, 18 entries
  //SEQ_3, 1 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1020501
  //ACTOR1 = 1020545
  //ACTOR2 = 1020544
  //ACTOR3 = 1020546
  //ACTOR4 = 1020548
  //ACTOR5 = 1020547
  //ENEMY0 = 6873256
  //ENEMY1 = 6873257
  //ENEMY10 = 6907331
  //ENEMY11 = 6907332
  //ENEMY2 = 6873263
  //ENEMY3 = 6873264
  //ENEMY4 = 6905012
  //ENEMY5 = 6905013
  //ENEMY6 = 6907208
  //ENEMY7 = 6907206
  //ENEMY8 = 6907344
  //ENEMY9 = 6907346
  //EOBJECT0 = 2008128
  //EOBJECT1 = 2008129
  //EOBJECT2 = 2008131
  //EOBJECT3 = 2008456
  //EOBJECT4 = 2008457
  //ITEM0 = 2002199
  //ITEM1 = 2002196
  //ITEM2 = 2002197
  //LOCGOSETSU001 = 6851401
  //LOCHIEN001 = 6851400
  //LOCHIEN002 = 1019544
  //LOCLAUGHBIG = 4312
  //LOCLISE001 = 6851397

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
        if( param1 == 1020501 ) // ACTOR0 = CIRINA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=CIRINA
          }
          break;
        }
        if( param1 == 1020545 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020544 ) // ACTOR2 = HIEN
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020546 ) // ACTOR3 = GOSETSU
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 1020548 ) // ACTOR4 = HIEN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1020547 ) // ACTOR5 = GOSETSU
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        break;
      }
      //seq 2 event item ITEM1 = UI8DH max stack ?
      //seq 2 event item ITEM0 = UI8DL max stack ?
      case 2:
      {
        if( param1 == 2008128 ) // EOBJECT0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            if( type == EVENT_ON_TALK ) Scene00008( quest, player ); // Scene00008: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown
            if( type == EVENT_ON_EVENT_ITEM ) Scene00009( quest, player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT0
        if( param1 == 6873256 ) // ENEMY0 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6873257 ) // ENEMY1 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6873263 ) // ENEMY2 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1020547 ) // ACTOR5 = GOSETSU
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 2008129 ) // EOBJECT1 = unknown
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            if( type == EVENT_ON_TALK ) Scene00017( quest, player ); // Scene00017: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown
            if( type == EVENT_ON_EVENT_ITEM ) Scene00018( quest, player ); // Scene00018: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT1
        if( param1 == 6873264 ) // ENEMY3 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6905012 ) // ENEMY4 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6905013 ) // ENEMY5 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2008131 ) // EOBJECT2 = unknown
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            if( type == EVENT_ON_TALK ) Scene00025( quest, player ); // Scene00025: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown
            if( type == EVENT_ON_EVENT_ITEM ) Scene00026( quest, player ); // Scene00026: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT2
        if( param1 == 6907208 ) // ENEMY6 = unknown
        {
          Scene00028( quest, player ); // Scene00028: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6907206 ) // ENEMY7 = unknown
        {
          Scene00030( quest, player ); // Scene00030: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2008456 ) // EOBJECT3 = unknown
        {
          if( !quest.getBitFlag8( 4 ) )
          {
            if( type == EVENT_ON_TALK ) Scene00031( quest, player ); // Scene00031: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown
            if( type == EVENT_ON_EVENT_ITEM ) Scene00032( quest, player ); // Scene00032: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT3
        if( param1 == 6907344 ) // ENEMY8 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6907346 ) // ENEMY9 = unknown
        {
          Scene00036( quest, player ); // Scene00036: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2008457 ) // EOBJECT4 = unknown
        {
          if( !quest.getBitFlag8( 5 ) )
          {
            if( type == EVENT_ON_TALK ) Scene00037( quest, player ); // Scene00037: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown
            if( type == EVENT_ON_EVENT_ITEM ) Scene00038( quest, player ); // Scene00038: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT4
        if( param1 == 6907331 ) // ENEMY10 = dummye10
        {
          Scene00040( quest, player ); // Scene00040: Normal(Message, PopBNpc), id=dummye10
          break;
        }
        if( param1 == 6907332 ) // ENEMY11 = dummye11
        {
          Scene00042( quest, player ); // Scene00042: Normal(Message, PopBNpc), id=dummye11
          break;
        }
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack ?
      //seq 3 event item ITEM2 = UI8BL max stack 1
      case 3:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=GOSETSU
        // +Callback Scene00044: Normal(Talk, FadeIn, TargetCanMove), id=GOSETSU
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack ?
      //seq 255 event item ITEM2 = UI8BL max stack 1
      case 255:
      {
        if( param1 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00045( quest, player ); // Scene00045: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00046: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1020546 ) // ACTOR3 = GOSETSU
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020544 ) // ACTOR2 = HIEN
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=HIEN
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
      quest.setUI8BH( 0 );
      quest.setSeq( 2 );
      quest.setUI8DH( 1 );
      quest.setUI8DL( 1 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8CL() == 3 )
      if( quest.getUI8BH() == 3 )
        if( quest.getUI8BL() == 2 )
          if( quest.getUI8CH() == 2 )
            if( quest.getUI8AL() == 2 )
            {
              quest.setUI8CL( 0 );
              quest.setUI8BH( 0 );
              quest.setUI8BL( 0 );
              quest.setUI8CH( 0 );
              quest.setUI8AL( 0 );
              quest.setBitFlag8( 1, false );
              quest.setBitFlag8( 2, false );
              quest.setBitFlag8( 3, false );
              quest.setBitFlag8( 4, false );
              quest.setBitFlag8( 5, false );
              quest.setUI8DH( 0 );
              quest.setUI8DL( 0 );
              quest.setSeq( 3 );
            }
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
    quest.setUI8BH( 1 );
    quest.setUI8BL( 1 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00003: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00007: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, UI8CL = 3, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00008: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown" );
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, nullptr );
  }
  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, UI8CL = 3, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8CL( 3 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8CL(), 3 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00015: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00016: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, UI8BH = 3, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00017: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown" );
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, nullptr );
  }
  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, UI8BH = 3, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00018: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 3 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00020: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00022: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00024: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT2, UI8BL = 2, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00025: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown" );
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, nullptr );
  }
  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT2, UI8BL = 2, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00026: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 2 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00028: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00030: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT3, UI8CH = 2, Flag8(4)=True
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00031: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown" );
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, nullptr );
  }
  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT3, UI8CH = 2, Flag8(4)=True
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00032: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8CH( 2 );
      quest.setBitFlag8( 4, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00034: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00036: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT4, UI8AL = 2, Flag8(5)=True
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00037: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown" );
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, nullptr );
  }
  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT4, UI8AL = 2, Flag8(5)=True
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00038: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 2 );
      quest.setBitFlag8( 5, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 38, HIDE_HOTBAR, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00040: Normal(Message, PopBNpc), id=dummye10" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 40, HIDE_HOTBAR, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00042: Normal(Message, PopBNpc), id=dummye11" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00043: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00044( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 43, HIDE_HOTBAR, callback );
  }
  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00044: Normal(Talk, FadeIn, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 44, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00045: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00046( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }
  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00046: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 46, HIDE_HOTBAR, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00047: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, HIDE_HOTBAR, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda405:68040 calling Scene00048: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda405 );
