// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc208 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc208() : Sapphire::ScriptAPI::EventScript( 66503 ){}; 
  ~GaiUsc208() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 3 entries
  //SEQ_3, 4 entries
  //SEQ_4, 1 entries
  //SEQ_5, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006503
  //ACTOR1 = 1006507
  //ACTOR2 = 1007716
  //ACTOR3 = 1006497
  //EOBJECT0 = 2002299
  //EOBJECT1 = 2002189
  //EOBJECT2 = 2002328
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONWAITING2MIDDLE = 12
  //ITEM0 = 2000849
  //ITEM1 = 2000841
  //QUESTBATTLE0 = 86
  //TERRITORYTYPE0 = 330

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=DAVYD
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=MIMIDOA
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( actor == 1007716 || actorId == 1007716 ) // ACTOR2 = MIMIDOA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MIMIDOA
          }
        }
        if( actor == 2002299 || actorId == 2002299 ) // EOBJECT0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          // +Callback Scene00005: Normal(None), id=unknown
        }
        if( actor == 2002189 || actorId == 2002189 ) // EOBJECT1 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          // +Callback Scene00007: Normal(None), id=unknown
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      case 3:
      {
        if( actor == 2002189 || actorId == 2002189 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
          }
        }
        if( actor == 2002299 || actorId == 2002299 ) // EOBJECT0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(QuestBattle, YesNo), id=unknown
          // +Callback Scene00010: Normal(None), id=unknown
        }
        if( actor == 2002328 || actorId == 2002328 ) // EOBJECT2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          // +Callback Scene00012: Normal(None), id=unknown
        }
        if( actor == 1007716 || actorId == 1007716 ) // ACTOR2 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        break;
      }
      case 4:
      {
        Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=MIMIDOA
        // +Callback Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=MIMIDOA
        break;
      }
      //seq 5 event item ITEM1 = UI8BH max stack 1
      case 5:
      {
        Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=DAVYD
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 1
      case 255:
      {
        Scene00017( player ); // Scene00017: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CEANA
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 1 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc208:66503 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=DAVYD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=MIMIDOA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling Scene00003: Normal(Talk, TargetCanMove), id=MIMIDOA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling Scene00008: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling Scene00009: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00010( player );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling [BranchTrue]Scene00010: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling [BranchTrue]Scene00012: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling Scene00014: Normal(Talk, TargetCanMove), id=MIMIDOA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling [BranchTrue]Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=MIMIDOA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling Scene00016: Normal(Talk, TargetCanMove), id=DAVYD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling Scene00017: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00018( player );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc208:66503 calling [BranchTrue]Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CEANA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsc208 );
