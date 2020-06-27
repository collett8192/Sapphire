// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil128 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil128() : Sapphire::ScriptAPI::EventScript( 66178 ){}; 
  ~SubWil128() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1003936
  //EOBJECT0 = 2001438
  //EOBJECT1 = 2001439
  //EOBJECT2 = 2001440
  //EOBJECT3 = 2001441
  //EOBJECT4 = 2001444
  //EOBJECT5 = 2001445
  //EVENTACTIONPROCESSSHOR = 15
  //ITEM0 = 2000406

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=AIRELL
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 6
      case 1:
      {
        if( actor == 2001438 || actorId == 2001438 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00001( player ); // Scene00001: Normal(None), id=unknown
            // +Callback Scene00002: Normal(None), id=unknown
          }
          else
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
          }
        }
        if( actor == 2001439 || actorId == 2001439 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
            // +Callback Scene00005: Normal(None), id=unknown
          }
          else
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
          }
        }
        if( actor == 2001440 || actorId == 2001440 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
            // +Callback Scene00008: Normal(None), id=unknown
          }
          else
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
          }
        }
        if( actor == 2001441 || actorId == 2001441 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
            // +Callback Scene00011: Normal(None), id=unknown
          }
          else
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
          }
        }
        if( actor == 2001444 || actorId == 2001444 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00013( player ); // Scene00013: Normal(None), id=unknown
            // +Callback Scene00014: Normal(None), id=unknown
          }
          else
          {
            Scene00015( player ); // Scene00015: Normal(None), id=unknown
          }
        }
        if( actor == 2001445 || actorId == 2001445 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00016( player ); // Scene00016: Normal(None), id=unknown
            // +Callback Scene00017: Normal(None), id=unknown
          }
          else
          {
            Scene00018( player ); // Scene00018: Normal(None), id=unknown
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 6
      case 255:
      {
        Scene00019( player ); // Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AIRELL
        // +Callback Scene00021: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 6 )
      if( player.getQuestUI8AL( getId() ) == 6 )
        if( player.getQuestUI8AL( getId() ) == 6 )
          if( player.getQuestUI8AL( getId() ) == 6 )
            if( player.getQuestUI8AL( getId() ) == 6 )
              if( player.getQuestUI8AL( getId() ) == 6 )
              {
                player.setQuestUI8AL( getId(), 0 );
                player.setQuestUI8AL( getId(), 0 );
                player.setQuestUI8AL( getId(), 0 );
                player.setQuestUI8AL( getId(), 0 );
                player.setQuestUI8AL( getId(), 0 );
                player.setQuestUI8AL( getId(), 0 );
                player.updateQuest( getId(), 255 );
                player.setQuestUI8BH( getId(), 6 );
              }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=AIRELL" );
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
    player.sendDebug( "SubWil128:66178 calling Scene00001: Normal(None), id=unknown" );
    Scene00002( player );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling [BranchTrue]Scene00002: Normal(None), id=unknown" );
    Scene00003( player );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling [BranchFalse]Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling [BranchFalse]Scene00006: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling [BranchFalse]Scene00009: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling [BranchTrue]Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling [BranchFalse]Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling Scene00013: Normal(None), id=unknown" );
    Scene00014( player );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling [BranchTrue]Scene00014: Normal(None), id=unknown" );
    Scene00015( player );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling [BranchFalse]Scene00015: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling Scene00016: Normal(None), id=unknown" );
    Scene00017( player );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling [BranchTrue]Scene00017: Normal(None), id=unknown" );
    Scene00018( player );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling [BranchFalse]Scene00018: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown" );
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
    player.sendDebug( "SubWil128:66178 calling [BranchTrue]Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AIRELL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00021( player );
      }
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "SubWil128:66178 calling [BranchChain]Scene00021: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubWil128 );
