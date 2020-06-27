// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsa203 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsa203() : Sapphire::ScriptAPI::EventScript( 66262 ){}; 
  ~GaiUsa203() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_4, 1 entries
  //SEQ_5, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1000590
  //ACTOR1 = 1002934
  //ACTOR2 = 1002935
  //EOBJECT0 = 2001925
  //EOBJECT1 = 2001926
  //EOBJECT2 = 2001927
  //EOBJECT3 = 2001928
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000580
  //ITEM1 = 2000581

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=BUSCARRON
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(None), id=unknown
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        Scene00003( player ); // Scene00003: Normal(None), id=unknown
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      case 3:
      {
        Scene00004( player ); // Scene00004: Normal(Inventory), id=unknown
        // +Callback Scene00005: Normal(None), id=unknown
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      //seq 4 event item ITEM1 = UI8BL max stack ?
      case 4:
      {
        Scene00006( player ); // Scene00006: Normal(None), id=unknown
        // +Callback Scene00007: Normal(None), id=unknown
        // +Callback Scene00008: Normal(None), id=unknown
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack ?
      //seq 5 event item ITEM1 = UI8BL max stack ?
      case 5:
      {
        if( actor == 1002934 || actorId == 1002934 ) // ACTOR1 = NPCA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
            // +Callback Scene00010: Normal(Talk, Inventory, TargetCanMove), id=NPCA
          }
          else
          {
            Scene00011( player ); // Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCA
          }
        }
        if( actor == 1002935 || actorId == 1002935 ) // ACTOR2 = NPCB
        {
          Scene00012( player ); // Scene00012: Normal(Talk), id=NPCB
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      //seq 255 event item ITEM1 = UI8BL max stack ?
      case 255:
      {
        if( actor == 1000590 || actorId == 1000590 ) // ACTOR0 = BUSCARRON
        {
          Scene00013( player ); // Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BUSCARRON
        }
        if( actor == 1002935 || actorId == 1002935 ) // ACTOR2 = NPCB
        {
          Scene00014( player ); // Scene00014: Normal(Talk), id=NPCB
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
    onProgress( player, param1, param1, 3, param1 );
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsa203:66262 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=BUSCARRON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling Scene00002: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling [BranchChain]Scene00008: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling [BranchTrue]Scene00010: Normal(Talk, Inventory, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling [BranchFalse]Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling Scene00012: Normal(Talk), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BUSCARRON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa203:66262 calling Scene00014: Normal(Talk), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsa203 );
