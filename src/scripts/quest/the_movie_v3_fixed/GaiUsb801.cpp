// FFXIVTheMovie.ParserV3
//fix: failed to move enemy credit to npc, no pop message
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb801 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb801() : Sapphire::ScriptAPI::EventScript( 66446 ){}; 
  ~GaiUsb801() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 4 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006384
  //ACTOR1 = 1006407
  //ACTOR2 = 1006408
  //ACTOR3 = 1006409
  //ACTOR4 = 1006410
  //ENEMY0 = 4293113
  //EVENTACTIONRESCUEUNDERMIDDLE = 35
  //EVENTACTIONRESCUEUNDERSHORT = 34

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HAURCHEFANT
        break;
      }
      case 1:
      {
        if( actor == 1006407 || actorId == 1006407 ) // ACTOR1 = FRANCEL
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=FRANCEL
        }
        if( actor == 4293113 || actorId == 4293113 ) // ENEMY0 = unknown
        {
        }
        if( actor == 1006408 || actorId == 1006408 ) // ACTOR2 = NPCA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=NPCA
        }
        if( actor == 1006409 || actorId == 1006409 ) // ACTOR3 = NPCB
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=NPCB
        }
        if( actor == 1006410 || actorId == 1006410 ) // ACTOR4 = NPCC
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=NPCC
        }
        break;
      }
      case 2:
      {
        if( actor == 1006408 || actorId == 1006408 ) // ACTOR2 = NPCA
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
            // +Callback Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCA
          }
        }
        if( actor == 1006409 || actorId == 1006409 ) // ACTOR3 = NPCB
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
            // +Callback Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCB
          }
        }
        if( actor == 1006410 || actorId == 1006410 ) // ACTOR4 = NPCC
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
            // +Callback Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCC
          }
        }
        if( actor == 1006407 || actorId == 1006407 ) // ACTOR1 = FRANCEL
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=FRANCEL
        }
        break;
      }
      case 3:
      {
        Scene00013( player ); // Scene00013: Normal(None), id=unknown
        // +Callback Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=FRANCEL
        break;
      }
      case 255:
      {
        Scene00015( player ); // Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HAURCHEFANT
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
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
    player.sendDebug( "GaiUsb801:66446 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb801:66446 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling Scene00002: Normal(Talk, TargetCanMove), id=FRANCEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.getQuestUI8AL( getId() ) != 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling Scene00003: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling Scene00004: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling Scene00005: Normal(Talk, TargetCanMove), id=NPCC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling [BranchTrue]Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling [BranchTrue]Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling [BranchTrue]Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling Scene00012: Normal(Talk, TargetCanMove), id=FRANCEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling Scene00013: Normal(None), id=unknown" );
    Scene00014( player );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling [BranchTrue]Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=FRANCEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb801:66446 calling Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb801 );
