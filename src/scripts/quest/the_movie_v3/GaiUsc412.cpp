// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc412 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc412() : Sapphire::ScriptAPI::EventScript( 66523 ){}; 
  ~GaiUsc412() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 3 entries
  //SEQ_3, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006542
  //ENEMY0 = 46
  //ENEMY1 = 4302030
  //EOBJECT0 = 2002203
  //EOBJECT1 = 2002204
  //EOBJECT2 = 2002205
  //EOBJECT3 = 2002451
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000757
  //ITEM1 = 2000756

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AGANBOLD
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Inventory), id=unknown
        // +Callback Scene00003: Normal(None), id=unknown
        break;
      }
      //seq 2 event item ITEM0 = UI8CH max stack ?
      case 2:
      {
        if( actor == 2002203 || actorId == 2002203 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Inventory), id=unknown
            // +Callback Scene00005: Normal(None), id=unknown
          }
        }
        if( actor == 2002204 || actorId == 2002204 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Inventory), id=unknown
            // +Callback Scene00007: Normal(None), id=unknown
          }
        }
        if( actor == 2002205 || actorId == 2002205 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
          }
        }
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack 1
      case 3:
      {
        if( actor == 2002451 || actorId == 2002451 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4302030 || actorId == 4302030 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 1
      case 255:
      {
        Scene00010( player ); // Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AGANBOLD
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
    onProgress( player, param1, param1, 3, param1 );
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
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.updateQuest( getId(), 3 );
        }
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
    player.sendDebug( "GaiUsc412:66523 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "GaiUsc412:66523 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AGANBOLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc412:66523 calling Scene00002: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc412:66523 calling [BranchTrue]Scene00003: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc412:66523 calling Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc412:66523 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc412:66523 calling Scene00006: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc412:66523 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc412:66523 calling Scene00008: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc412:66523 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc412:66523 calling Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc412:66523 calling [BranchTrue]Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AGANBOLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsc412 );
