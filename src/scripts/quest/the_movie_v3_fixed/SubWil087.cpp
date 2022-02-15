// FFXIVTheMovie.ParserV3.8
// edit: bnpc id
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil087 : public Sapphire::ScriptAPI::QuestScript
{
public:
  SubWil087() : Sapphire::ScriptAPI::QuestScript( 65871 ){}; 
  ~SubWil087() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002071
  //ENEMY0 = 12
  //ENEMY1 = 382
  //ENEMY2 = 389
  //ITEM0 = 2000382
  //ITEM1 = 2000383
  //ITEM2 = 2000384

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=unknown
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 2
      //seq 1 event item ITEM1 = UI8CL max stack 2
      //seq 1 event item ITEM2 = UI8DH max stack 2
      case 1:
      {
        if( param1 == 12 || param1 == 13 ) // ENEMY0 = unknown
        {
          if( quest.getUI8AL() != 2 )
          {
            quest.setUI8AL( quest.getUI8AL() + 1 );
            checkProgressSeq1( quest, player );
          }
          break;
        }
        if( param1 == 382 || param1 == 636 ) // ENEMY1 = unknown
        {
          if( quest.getUI8BH() != 2 )
          {
            quest.setUI8BH( quest.getUI8BH() + 1 );
            checkProgressSeq1( quest, player );
          }
          break;
        }
        if( param1 == 389 || param1 == 635 ) // ENEMY2 = unknown
        {
          if( quest.getUI8BL() != 2 )
          {
            quest.setUI8BL( quest.getUI8BL() + 1 );
            checkProgressSeq1( quest, player );
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 2
      //seq 255 event item ITEM1 = UI8BL max stack 2
      //seq 255 event item ITEM2 = UI8CH max stack 2
      case 255:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00001( quest, player ); // Scene00001: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00002: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown
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
    if( quest.getUI8AL() == 2 )
      if( quest.getUI8BH() == 2 )
        if( quest.getUI8BL() == 2 )
        {
          quest.setUI8AL( 0 );
          quest.setUI8BH( 0 );
          quest.setUI8BL( 0 );
          quest.setUI8CH( 0 );
          quest.setUI8CL( 0 );
          quest.setUI8DH( 0 );
          quest.setSeq( 255 );
          quest.setUI8BH( 2 );
          quest.setUI8BL( 2 );
          quest.setUI8CH( 2 );
        }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil087:65871 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        checkProgressSeq0( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }




  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil087:65871 calling Scene00001: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00002( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }
  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "SubWil087:65871 calling Scene00002: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil087 );
