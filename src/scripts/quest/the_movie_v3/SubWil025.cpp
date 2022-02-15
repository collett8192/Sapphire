// FFXIVTheMovie.ParserV3.8
// param used:
//_ACTOR1 = B
//_ACTOR1B = 1|2
//_ACTOR2 = B
//_ACTOR2B = 1|2
//_ACTOR3 = B
//_ACTOR3B = 1|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil025 : public Sapphire::ScriptAPI::QuestScript
{
public:
  SubWil025() : Sapphire::ScriptAPI::QuestScript( 66207 ){}; 
  ~SubWil025() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1003995
  //ACTOR1 = 1004599
  //ACTOR2 = 1004600
  //ACTOR3 = 1004601
  //ITEM0 = 2000463

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
      //seq 0 event item ITEM0 = UI8BH max stack 1
      case 0:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=PAPASHAN
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 1
      case 1:
      {
        if( param1 == 1004599 ) // ACTOR1 = GINCHUA, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00001( quest, player ); // Scene00001: NpcTrade(Talk, TargetCanMove), id=GINCHUA
            // +Callback Scene00002: Normal(Talk, TargetCanMove), id=GINCHUA
          }
          else
          {
            Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=GINCHUA
          }
          break;
        }
        if( param1 == 1004600 ) // ACTOR2 = GINCHUB, CB=2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: NpcTrade(Talk, TargetCanMove), id=GINCHUB
            // +Callback Scene00005: Normal(Talk, TargetCanMove), id=GINCHUB
          }
          else
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=GINCHUB
          }
          break;
        }
        if( param1 == 1004601 ) // ACTOR3 = GINCHUC, CB=2
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00007( quest, player ); // Scene00007: NpcTrade(Talk, TargetCanMove), id=GINCHUC
            // +Callback Scene00008: Normal(Talk, TargetCanMove), id=GINCHUC
          }
          else
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=GINCHUC
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8CL max stack 1
      case 255:
      {
        if( param1 == 1003995 ) // ACTOR0 = PAPASHAN
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PAPASHAN
          break;
        }
        if( param1 == 1004599 ) // ACTOR1 = GINCHUA
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=GINCHUA
          break;
        }
        if( param1 == 1004600 ) // ACTOR2 = GINCHUB
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=GINCHUB
          break;
        }
        if( param1 == 1004601 ) // ACTOR3 = GINCHUC
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=GINCHUC
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
    quest.setUI8CH( 1 );
  }
  void checkProgressSeq1( World::Quest& quest, Entity::Player& player )
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
        }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        checkProgressSeq0( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }

  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00001: NpcTrade(Talk, TargetCanMove), id=GINCHUA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00002( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }
  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00002: Normal(Talk, TargetCanMove), id=GINCHUA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }
  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00003: Normal(Talk, TargetCanMove), id=GINCHUA" );
    eventMgr().playQuestScene( player, getId(), 3, NONE, nullptr );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8BH = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00004: NpcTrade(Talk, TargetCanMove), id=GINCHUB" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00005( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }
  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8BH = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00005: Normal(Talk, TargetCanMove), id=GINCHUB" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }
  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8BH = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00006: Normal(Talk, TargetCanMove), id=GINCHUB" );
    eventMgr().playQuestScene( player, getId(), 6, NONE, nullptr );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8BL = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00007: NpcTrade(Talk, TargetCanMove), id=GINCHUC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00008( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }
  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8BL = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00008: Normal(Talk, TargetCanMove), id=GINCHUC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }
  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8BL = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00009: Normal(Talk, TargetCanMove), id=GINCHUC" );
    eventMgr().playQuestScene( player, getId(), 9, NONE, nullptr );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00011: Normal(Talk, TargetCanMove), id=GINCHUA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00012: Normal(Talk, TargetCanMove), id=GINCHUB" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil025:66207 calling Scene00013: Normal(Talk, TargetCanMove), id=GINCHUC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil025 );
