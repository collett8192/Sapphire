// FFXIVTheMovie.ParserV3.12
// param used:
//_ACTOR7 = B
//_ACTOR7B = 2|2
//_ACTOR8 = B
//_ACTOR8B = 2|2
//_ACTOR9 = B
//_ACTOR9B = 2|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda612 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda612() : Sapphire::ScriptAPI::QuestScript( 68074 ){}; 
  ~StmBda612() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 7 entries
  //SEQ_2, 5 entries
  //SEQ_255, 13 entries

  //ACTOR0 = 1020611
  //ACTOR1 = 1020613
  //ACTOR10 = 1023836
  //ACTOR11 = 1023837
  //ACTOR12 = 1020601
  //ACTOR13 = 1020600
  //ACTOR14 = 1020602
  //ACTOR15 = 1020603
  //ACTOR16 = 1020604
  //ACTOR17 = 1020632
  //ACTOR18 = 1020638
  //ACTOR19 = 1020639
  //ACTOR2 = 1022338
  //ACTOR3 = 1020616
  //ACTOR4 = 1019945
  //ACTOR5 = 1022336
  //ACTOR6 = 1022337
  //ACTOR7 = 1020623
  //ACTOR8 = 1023834
  //ACTOR9 = 1023835
  //BINDACTOR01 = 6904984
  //BINDACTOR02 = 6904985
  //EVENTACTION0 = 35

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
        if( param1 == 1020611 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020613 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1022338 ) // ACTOR2 = MNAAGO
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020616 ) // ACTOR3 = unknown
        {
          Scene00004( quest, player ); // Scene00004: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019945 ) // ACTOR4 = ALISAIE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=ALISAIE
          }
          break;
        }
        if( param1 == 1022336 ) // ACTOR5 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Empty(None), id=unknown
          break;
        }
        if( param1 == 1022337 ) // ACTOR6 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020611 ) // ACTOR0 = ALPHINAUD
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020613 ) // ACTOR1 = LYSE
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1022338 ) // ACTOR2 = MNAAGO
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020616 ) // ACTOR3 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020623 ) // ACTOR7 = WOUNDEDRESISTANCESOLDIER, CB=2
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIER
          }
          else
          {
            Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIER
          }
          break;
        }
        if( param1 == 1023834 ) // ACTOR8 = WOUNDEDRESISTANCESOLDIERB, CB=2
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERB
          }
          else
          {
            Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERB
          }
          break;
        }
        if( param1 == 1023835 ) // ACTOR9 = WOUNDEDIMPERIALSOLDIER, CB=2
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=WOUNDEDIMPERIALSOLDIER
          }
          else
          {
            Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=WOUNDEDIMPERIALSOLDIER
          }
          break;
        }
        if( param1 == 1023836 ) // ACTOR10 = WOUNDEDRESISTANCESOLDIERC
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERC
          break;
        }
        if( param1 == 1023837 ) // ACTOR11 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020601 ) // ACTOR12 = ALPHINAUD
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020600 ) // ACTOR13 = MNAAGO
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020602 ) // ACTOR14 = ALISAIE
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020603 ) // ACTOR15 = LYSE
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020604 ) // ACTOR16 = RAUBAHN
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020632 ) // ACTOR17 = PIPIN
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020638 ) // ACTOR18 = SERPENTOFFICER
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 ) // ACTOR19 = STORMOFFICER
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1020623 ) // ACTOR7 = WOUNDEDRESISTANCESOLDIER
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIER
          break;
        }
        if( param1 == 1023834 ) // ACTOR8 = WOUNDEDRESISTANCESOLDIERB
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERB
          break;
        }
        if( param1 == 1023835 ) // ACTOR9 = WOUNDEDIMPERIALSOLDIER
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=WOUNDEDIMPERIALSOLDIER
          break;
        }
        if( param1 == 1023836 ) // ACTOR10 = WOUNDEDRESISTANCESOLDIERC
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERC
          break;
        }
        if( param1 == 1023837 ) // ACTOR11 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Empty(None), id=unknown
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
    if( quest.getUI8AL() == 3 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setBitFlag8( 2, false );
      quest.setBitFlag8( 3, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00003: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00004: Empty(None), id=unknown" );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=ALISAIE" );
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
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00006: Empty(None), id=unknown" );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00007: Empty(None), id=unknown" );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00009: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00010: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00011: Empty(None), id=unknown" );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, UI8AL = 3, Flag8(1)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00013: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 3 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }
  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, UI8AL = 3, Flag8(1)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00014: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIER" );
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, nullptr );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, UI8AL = 3, Flag8(2)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00016: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERB" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 2, true );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 3 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }
  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, UI8AL = 3, Flag8(2)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00017: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERB" );
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, nullptr );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, UI8AL = 3, Flag8(3)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00019: Normal(Talk, TargetCanMove), id=WOUNDEDIMPERIALSOLDIER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 3, true );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 3 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }
  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, UI8AL = 3, Flag8(3)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00020: Normal(Talk, TargetCanMove), id=WOUNDEDIMPERIALSOLDIER" );
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, nullptr );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00021: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00022: Empty(None), id=unknown" );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00023: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00024: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00026: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00027: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00028: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00029: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00030: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00031: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00032: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERB" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00033: Normal(Talk, TargetCanMove), id=WOUNDEDIMPERIALSOLDIER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00034: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda612:68074 calling Scene00035: Empty(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda612 );
