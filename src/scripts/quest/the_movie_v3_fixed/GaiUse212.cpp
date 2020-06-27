// FFXIVTheMovie.ParserV3
//fix: add code to enter instance
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse212 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse212() : Sapphire::ScriptAPI::EventScript( 66892 ){}; 
  ~GaiUse212() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_255, 3 entries

  //ACTIONTIMELINEEVENTTALKBIG = 950
  //ACTOR0 = 1008542
  //ACTOR1 = 1002694
  //ACTOR2 = 1001029
  //ACTOR3 = 1006614
  //ACTOR4 = 1008676
  //EVENTACTIONSEARCH = 1
  //LOCACTOR0 = 1008175
  //LOCACTOR1 = 1008176
  //LOCACTOR2 = 1008177
  //LOCACTOR3 = 1007097
  //LOCFACE0 = 617
  //POPRANGE0 = 4628787
  //TERRITORYTYPE0 = 198

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA
        break;
      }
      case 1:
      {
        if( actor == 1002694 || actorId == 1002694 ) // ACTOR1 = MERLWYB
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=MERLWYB
          }
        }
        if( actor == 1008542 || actorId == 1008542 ) // ACTOR0 = MINFILIA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1001029 || actorId == 1001029 ) // ACTOR2 = ZANTHAEL
        {
          Scene00004( player ); // Scene00004: Normal(Talk, YesNo, TargetCanMove), id=ZANTHAEL
        }
        break;
      }
      case 255:
      {
        if( actor == 1006614 || actorId == 1006614 ) // ACTOR3 = FALKBRYDA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FALKBRYDA
        }
        if( actor == 1002694 || actorId == 1002694 ) // ACTOR1 = MERLWYB
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MERLWYB
        }
        if( actor == 1008676 || actorId == 1008676 ) // ACTOR4 = MINFILIA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=MINFILIA
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse212:66892 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse212:66892 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse212:66892 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse212:66892 calling Scene00003: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse212:66892 calling Scene00004: Normal(Talk, YesNo, TargetCanMove), id=ZANTHAEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 198 );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse212:66892 calling Scene00005: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse212:66892 calling Scene00006: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse212:66892 calling Scene00007: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse212 );
