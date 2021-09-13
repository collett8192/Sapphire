// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil111 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil111() : Sapphire::ScriptAPI::EventScript( 66155 ){}; 
  ~SubWil111() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 4 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1003929
  //ACTOR1 = 1003964
  //ACTOR2 = 1003965
  //ACTOR3 = 1003966
  //ACTOR4 = 1003967
  //ITEM0 = 2000515

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack 1
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ISEMBARD
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        Scene00001( player ); // Scene00001: NpcTrade(Talk, TargetCanMove), id=UNGUST
        // +Callback Scene00002: Normal(Talk, TargetCanMove), id=UNGUST
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( param1 == 1003965 || param2 == 1003965 ) // ACTOR2 = POVERTY1
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=POVERTY1
          }
          break;
        }
        if( param1 == 1003966 || param2 == 1003966 ) // ACTOR3 = POVERTY2
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=POVERTY2
          }
          break;
        }
        if( param1 == 1003967 || param2 == 1003967 ) // ACTOR4 = POVERTY3
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=POVERTY3
          }
          break;
        }
        if( param1 == 1003964 || param2 == 1003964 ) // ACTOR1 = UNGUST
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=UNGUST
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        Scene00007( player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=UNGUST
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        Scene00008( player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ISEMBARD
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
    player.setQuestUI8BH( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil111:66155 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ISEMBARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "SubWil111:66155 calling Scene00001: NpcTrade(Talk, TargetCanMove), id=UNGUST" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00002( player );
      }
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil111:66155 calling Scene00002: Normal(Talk, TargetCanMove), id=UNGUST" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil111:66155 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=POVERTY1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil111:66155 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=POVERTY2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil111:66155 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=POVERTY3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil111:66155 calling Scene00006: Normal(Talk, TargetCanMove), id=UNGUST" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil111:66155 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=UNGUST" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil111:66155 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ISEMBARD" );
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
    player.playScene( getId(), 8, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil111 );
