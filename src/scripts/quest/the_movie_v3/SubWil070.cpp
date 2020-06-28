// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil070 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil070() : Sapphire::ScriptAPI::EventScript( 65860 ){}; 
  ~SubWil070() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1001541
  //ACTOR1 = 1001462
  //ACTOR2 = 1001463
  //ACTOR3 = 1001465
  //ACTOR4 = 1001466
  //ITEM0 = 2000234
  //SEQ0ACTOR0 = 0
  //SEQ1ACTOR1 = 1
  //SEQ1ACTOR2 = 2
  //SEQ1ACTOR3 = 3
  //SEQ1ACTOR4 = 4
  //SEQ2ACTOR0 = 5
  //SEQ2ACTOR0NPCTRADENO = 99
  //SEQ2ACTOR0NPCTRADEOK = 100

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ROGER
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 4
      case 1:
      {
        if( actor == 1001462 || actorId == 1001462 ) // ACTOR1 = ROUNDELPH
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=ROUNDELPH
          }
        }
        if( actor == 1001463 || actorId == 1001463 ) // ACTOR2 = ADALFUNS
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ADALFUNS
          }
        }
        if( actor == 1001465 || actorId == 1001465 ) // ACTOR3 = SOLIDTRUNK
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk), id=SOLIDTRUNK
          }
        }
        if( actor == 1001466 || actorId == 1001466 ) // ACTOR4 = RICARD
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=RICARD
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 4
      case 255:
      {
        Scene00005( player ); // Scene00005: NpcTrade(Talk, TargetCanMove), id=ROGER
        // +Callback Scene00100: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ROGER
        // +Callback Scene00099: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 4 )
      if( player.getQuestUI8AL( getId() ) == 4 )
        if( player.getQuestUI8AL( getId() ) == 4 )
          if( player.getQuestUI8AL( getId() ) == 4 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.updateQuest( getId(), 255 );
            player.setQuestUI8BH( getId(), 4 );
          }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil070:65860 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ROGER" );
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
    player.sendDebug( "SubWil070:65860 calling Scene00001: Normal(Talk, TargetCanMove), id=ROUNDELPH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil070:65860 calling Scene00002: Normal(Talk, TargetCanMove), id=ADALFUNS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil070:65860 calling Scene00003: Normal(Talk), id=SOLIDTRUNK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil070:65860 calling Scene00004: Normal(Talk, TargetCanMove), id=RICARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil070:65860 calling Scene00005: NpcTrade(Talk, TargetCanMove), id=ROGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00100( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00100( Entity::Player& player )
  {
    player.sendDebug( "SubWil070:65860 calling [BranchTrue]Scene00100: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ROGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00099( player );
      }
    };
    player.playScene( getId(), 100, NONE, callback );
  }
  void Scene00099( Entity::Player& player )
  {
    player.sendDebug( "SubWil070:65860 calling [BranchChain]Scene00099: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 99, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil070 );
