// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil110 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil110() : Sapphire::ScriptAPI::EventScript( 66154 ){}; 
  ~SubWil110() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 10 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1003929
  //ACTOR1 = 1003942
  //ACTOR2 = 1003943
  //ACTOR3 = 1003944
  //ENEMY0 = 4100865
  //ENEMY1 = 4100866
  //EOBJECT0 = 2001663
  //EOBJECT1 = 2001664
  //EOBJECT2 = 2001665
  //EOBJECT3 = 2001866
  //EVENTRANGE0 = 4100864
  //EVENTACTIONGATHERSHORT = 6
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000399

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=ISEMBARD
        // +Callback Scene00001: Normal(QuestAccept), id=unknown
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 3
      case 1:
      {
        if( param1 == 4298942495 || param2 == 1003942 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 4298942496 || param2 == 1003943 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 4298942497 || param2 == 1003944 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 4100864 || param2 == 4100864 ) // EVENTRANGE0 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 4100865 || param2 == 4100865 ) // ENEMY0 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 4100866 || param2 == 4100866 ) // ENEMY1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001663 || param2 == 2001663 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2001664 || param2 == 2001664 ) // EOBJECT1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001665 || param2 == 2001665 ) // EOBJECT2 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001866 || param2 == 2001866 ) // EOBJECT3 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        if( param1 == 1003929 || param2 == 1003929 ) // ACTOR0 = ISEMBARD
        {
          Scene00019( player ); // Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ISEMBARD
          break;
        }
        if( param1 == 2001663 || param2 == 2001663 ) // EOBJECT0 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001664 || param2 == 2001664 ) // EOBJECT1 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001665 || param2 == 2001665 ) // EOBJECT2 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        break;
      }
      default:
      {
        player.sendUrgent( "Sequence {} not defined.", player.getQuestSeq( getId() ) );
        break;
      }
    }
  }

public:
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    onProgress( player, actorId, actor, 0, 0 );
  }

  void onEmote( uint64_t actorId, uint32_t eventId, uint32_t emoteId, Entity::Player& player ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    onProgress( player, actorId, actor, 1, emoteId );
  }

  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
  {
    onProgress( player, npcId, 0, 2, 0 );
  }

  void onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( player, param1, param1, 3, 0 );
  }

  void onEnterTerritory( Sapphire::Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2 ) override
  {
    onProgress( player, param1, param2, 4, 0 );
  }

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.updateQuest( getId(), 255 );
          player.setQuestUI8BH( getId(), 3 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=ISEMBARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00001: Normal(QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00002: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00004: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00020( player );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ISEMBARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "SubWil110:66154 calling Scene00027: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubWil110 );
