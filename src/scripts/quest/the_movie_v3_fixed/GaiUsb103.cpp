// FFXIVTheMovie.ParserV3.3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb103 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb103() : Sapphire::ScriptAPI::EventScript( 66358 ){}; 
  ~GaiUsb103() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1004917
  //ACTOR1 = 1007626
  //ENEMY0 = 356
  //ENEMY1 = 4293190
  //EOBJECT0 = 2002046
  //EOBJECT1 = 2002576
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONWAITING = 10
  //ITEM0 = 2000645
  //ITEM1 = 2000833

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 )
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=UODHNUN
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( type == 2 && param1 == 307 )
        {
          checkProgressSeq1( player );
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( type != 2 )
          Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 2002576 || param2 == 2002576 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            player.setQuestUI8AL( getId(), 1 );
            checkProgressSeq3( player );
          }
          break;
        }
        if( param1 == 4293190 || param2 == 4293190 ) // ENEMY1 = unknown
        {
          break;
        }
        if( param1 == 1007626 || param2 == 1007626 ) // ACTOR1 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 1
      case 255:
      {
        if( type != 2 )
          Scene00008( player ); // Scene00008: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=UODHNUN
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb103:66358 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb103:66358 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=UODHNUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb103:66358 calling Scene00002: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb103:66358 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb103:66358 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }


  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb103:66358 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb103:66358 calling Scene00008: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00009( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb103:66358 calling Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=UODHNUN" );
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
    player.playScene( getId(), 9, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb103 );
