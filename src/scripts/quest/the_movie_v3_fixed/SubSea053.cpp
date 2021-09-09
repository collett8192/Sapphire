// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea053 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea053() : Sapphire::ScriptAPI::EventScript( 66001 ){}; 
  ~SubSea053() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002626
  //ACTOR1 = 1002635
  //ACTOR2 = 1002636
  //ACTOR3 = 1002637
  //ACTOR4 = 1002638
  //ACTOR5 = 1002639

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=STAELWYRN
        break;
      }
      case 1:
      {
        if( actor == 1002635 || actorId == 4298896548 ) // ACTOR1 = SEVRIN
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00001( player ); // Scene00001: Normal(Talk, NpcDespawn, TargetCanMove), id=SEVRIN
          }
        }
        if( actor == 1002636 || actorId == 4298896549 ) // ACTOR2 = AYLMER
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=AYLMER
          }
        }
        if( actor == 1002637 || actorId == 4298896550 ) // ACTOR3 = EYRIMHUS
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=EYRIMHUS
          }
        }
        if( actor == 1002638 || actorId == 4298896551 ) // ACTOR4 = SOZAIRARZAI
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=SOZAIRARZAI
          }
        }
        if( actor == 1002639 || actorId == 4298896552 ) // ACTOR5 = WAUTER
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=WAUTER
          }
        }
        break;
      }
      case 255:
      {
        Scene00006( player ); // Scene00006: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=STAELWYRN
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
    if( player.getQuestUI8AL( getId() ) == 5 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea053:66001 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=STAELWYRN" );
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
    player.sendDebug( "SubSea053:66001 calling Scene00001: Normal(Talk, NpcDespawn, TargetCanMove), id=SEVRIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea053:66001 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=AYLMER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea053:66001 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=EYRIMHUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea053:66001 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=SOZAIRARZAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubSea053:66001 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=WAUTER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubSea053:66001 calling Scene00006: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=STAELWYRN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea053 );
