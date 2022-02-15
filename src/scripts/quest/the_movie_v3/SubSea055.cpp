// FFXIVTheMovie.ParserV3.8
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea055 : public Sapphire::ScriptAPI::QuestScript
{
public:
  SubSea055() : Sapphire::ScriptAPI::QuestScript( 66003 ){}; 
  ~SubSea055() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002627
  //ACTOR1 = 1002629
  //ACTOR2 = 1002631
  //EOBJECT0 = 2001237
  //EOBJECT1 = 2001238
  //EOBJECT2 = 2001239
  //EVENTACTIONPROCESSMIDDLE = 16
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000347
  //QSTACCEPTCHECK = 66000

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove, SystemTalk, CanCancel), id=GURCANT
        break;
      }
      case 1:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00001( quest, player ); // Scene00001: Normal(Talk, TargetCanMove), id=RHOTWYDA
        break;
      }
      //seq 2 event item ITEM0 = UI8CH max stack 3
      case 2:
      {
        if( param1 == 2001237 || param1 == 4298896562 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001238 || param1 == 4298896563 ) // EOBJECT1 = unknown
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00003( quest, player ); // Scene00003: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001239 || param1 == 4298896564 ) // EOBJECT2 = unknown
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00005( quest, player ); // Scene00005: NpcTrade(Talk, TargetCanMove), id=PFREWAHL
        // +Callback Scene00094: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PFREWAHL
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
    quest.setSeq( 2 );
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
      if( quest.getUI8BH() == 1 )
        if( quest.getUI8BL() == 1 )
        {
          quest.setUI8AL( 0 );
          quest.setUI8BH( 0 );
          quest.setUI8BL( 0 );
          quest.setBitFlag8( 1, false );
          quest.setBitFlag8( 2, false );
          quest.setBitFlag8( 3, false );
          quest.setUI8CH( 0 );
          quest.setSeq( 255 );
          quest.setUI8BH( 3 );
        }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea055:66003 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove, SystemTalk, CanCancel), id=GURCANT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        checkProgressSeq0( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }

  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea055:66003 calling Scene00001: Normal(Talk, TargetCanMove), id=RHOTWYDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "SubSea055:66003 calling Scene00002: Normal(None), id=unknown" );
    quest.setUI8AL( 1 );
    quest.setBitFlag8( 1, true );
    checkProgressSeq2( quest, player );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, UI8BH = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "SubSea055:66003 calling Scene00003: Normal(None), id=unknown" );
    quest.setUI8BH( 1 );
    quest.setBitFlag8( 2, true );
    checkProgressSeq2( quest, player );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT2, UI8BL = 1, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "SubSea055:66003 calling Scene00004: Normal(None), id=unknown" );
    quest.setUI8BL( 1 );
    quest.setBitFlag8( 3, true );
    checkProgressSeq2( quest, player );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea055:66003 calling Scene00005: NpcTrade(Talk, TargetCanMove), id=PFREWAHL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00094( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }
  void Scene00094( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubSea055:66003 calling Scene00094: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PFREWAHL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 94, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea055 );
