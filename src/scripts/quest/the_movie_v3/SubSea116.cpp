// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea116 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea116() : Sapphire::ScriptAPI::EventScript( 65949 ){}; 
  ~SubSea116() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 5 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002238
  //ACTOR1 = 1002237
  //ACTOR2 = 1002240
  //ACTOR3 = 1002463
  //ACTOR4 = 1002464
  //ACTOR5 = 1002465
  //EOBJECT0 = 2000766
  //EOBJECT1 = 2000767
  //EVENTACTIONSEARCH = 1
  //LOCACTOR1 = 1002534
  //LOCACTOR2 = 1002535
  //LOCEOBJ1 = 2000768

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=AHTBYRM
        break;
      }
      case 1:
      {
        Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=GHIMTHOTA
        break;
      }
      case 2:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=CNANGHO
        break;
      }
      case 3:
      {
        if( actor == 1002463 || actorId == 1002463 ) // ACTOR3 = CORSAIR
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=CORSAIR
          }
        }
        if( actor == 1002464 || actorId == 1002464 ) // ACTOR4 = CORSAIRFOLLOWA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=CORSAIRFOLLOWA
        }
        if( actor == 1002465 || actorId == 1002465 ) // ACTOR5 = CORSAIRFOLLOWB
        {
          Scene00005( player ); // Scene00005: Normal(Talk), id=CORSAIRFOLLOWB
        }
        if( actor == 2000766 || actorId == 2000766 ) // EOBJECT0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          // +Callback Scene00007: Normal(None), id=unknown
        }
        if( actor == 2000767 || actorId == 2000767 ) // EOBJECT1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          // +Callback Scene00009: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        Scene00010( player ); // Scene00010: Normal(None), id=unknown
        // +Callback Scene00011: Normal(None), id=unknown
        // +Callback Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GHIMTHOTA
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea116:65949 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=AHTBYRM" );
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
    player.sendDebug( "SubSea116:65949 calling Scene00001: Normal(Talk, TargetCanMove), id=GHIMTHOTA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea116:65949 calling Scene00002: Normal(Talk, TargetCanMove), id=CNANGHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea116:65949 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=CORSAIR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea116:65949 calling Scene00004: Normal(Talk, TargetCanMove), id=CORSAIRFOLLOWA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubSea116:65949 calling Scene00005: Normal(Talk), id=CORSAIRFOLLOWB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubSea116:65949 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubSea116:65949 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubSea116:65949 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubSea116:65949 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubSea116:65949 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubSea116:65949 calling [BranchTrue]Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubSea116:65949 calling [BranchChain]Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GHIMTHOTA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea116 );
