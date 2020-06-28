// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil093 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil093() : Sapphire::ScriptAPI::EventScript( 65878 ){}; 
  ~SubWil093() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002069
  //EOBJECT0 = 2001382
  //EOBJECT1 = 2001383
  //EOBJECT2 = 2001384
  //EOBJECT3 = 2001475
  //EOBJECT4 = 2001476
  //EOBJECT5 = 2001477
  //EOBJECT6 = 2001478
  //EOBJECT7 = 2001479
  //EVENTACTIONPROCESSSHOR = 15

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=unknown
        break;
      }
      case 1:
      {
        if( actor == 2001382 || actorId == 2001382 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00001( player ); // Scene00001: Normal(None), id=unknown
            // +Callback Scene00002: Normal(None), id=unknown
          }
        }
        if( actor == 2001383 || actorId == 2001383 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
            // +Callback Scene00004: Normal(None), id=unknown
          }
        }
        if( actor == 2001384 || actorId == 2001384 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
            // +Callback Scene00006: Normal(None), id=unknown
          }
        }
        if( actor == 2001475 || actorId == 2001475 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
            // +Callback Scene00008: Normal(None), id=unknown
          }
        }
        if( actor == 2001476 || actorId == 2001476 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
            // +Callback Scene00010: Normal(None), id=unknown
          }
        }
        if( actor == 2001477 || actorId == 2001477 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00011( player ); // Scene00011: Normal(None), id=unknown
            // +Callback Scene00012: Normal(None), id=unknown
          }
        }
        if( actor == 2001478 || actorId == 2001478 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00013( player ); // Scene00013: Normal(None), id=unknown
            // +Callback Scene00014: Normal(None), id=unknown
          }
        }
        if( actor == 2001479 || actorId == 2001479 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00015( player ); // Scene00015: Normal(None), id=unknown
            // +Callback Scene00016: Normal(None), id=unknown
          }
          else
          {
            Scene00017( player ); // Scene00017: Normal(None), id=unknown
          }
        }
        break;
      }
      case 255:
      {
        Scene00018( player ); // Scene00018: Normal(None), id=unknown
        // +Callback Scene00019: Normal(None), id=unknown
        // +Callback Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 8 )
      if( player.getQuestUI8AL( getId() ) == 8 )
        if( player.getQuestUI8AL( getId() ) == 8 )
          if( player.getQuestUI8AL( getId() ) == 8 )
            if( player.getQuestUI8AL( getId() ) == 8 )
              if( player.getQuestUI8AL( getId() ) == 8 )
                if( player.getQuestUI8AL( getId() ) == 8 )
                  if( player.getQuestUI8AL( getId() ) == 8 )
                  {
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.updateQuest( getId(), 255 );
                  }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=unknown" );
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
    player.sendDebug( "SubWil093:65878 calling Scene00001: Normal(None), id=unknown" );
    Scene00002( player );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling [BranchTrue]Scene00002: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling Scene00003: Normal(None), id=unknown" );
    Scene00004( player );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling [BranchTrue]Scene00004: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling [BranchTrue]Scene00006: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling [BranchTrue]Scene00010: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling [BranchTrue]Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling Scene00013: Normal(None), id=unknown" );
    Scene00014( player );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling [BranchTrue]Scene00014: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling Scene00015: Normal(None), id=unknown" );
    Scene00016( player );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling [BranchTrue]Scene00016: Normal(None), id=unknown" );
    Scene00017( player );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling [BranchFalse]Scene00017: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling Scene00018: Normal(None), id=unknown" );
    Scene00019( player );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling [BranchTrue]Scene00019: Normal(None), id=unknown" );
    Scene00020( player );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "SubWil093:65878 calling [BranchChain]Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 20, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil093 );
