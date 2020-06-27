// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse301 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse301() : Sapphire::ScriptAPI::EventScript( 66978 ){}; 
  ~GaiUse301() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1008579
  //ACTOR1 = 1009239
  //ACTOR2 = 1009240
  //ACTOR3 = 1009241
  //ACTOR4 = 1008623
  //CUTSCENEN01 = 484
  //EVENTACTIONSEARCH = 1
  //LEVELIDNPC01 = 4841541
  //LEVELIDNPC02 = 4841542
  //LOCACTION0 = 613
  //LOCACTION1 = 615
  //LOCACTION2 = 620
  //LOCACTION3 = 605
  //LOCACTION4 = 617
  //LOCACTOR0 = 1008266
  //LOCACTOR1 = 1009240
  //LOCACTOR10 = 4505914
  //LOCACTOR11 = 4550383
  //LOCACTOR2 = 1009241
  //LOCACTOR3 = 1008175
  //LOCACTOR4 = 1008182
  //LOCBGM0 = 97
  //LOCBGM1 = 78
  //LOCPOSACTOR0 = 4881124
  //LOCPOSACTOR1 = 4892117
  //LOCSE0 = 68
  //LOCSE1 = 39

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MINFILIA
        break;
      }
      case 1:
      {
        if( actor == 1009239 || actorId == 1009239 ) // ACTOR1 = REFUGEE01442
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=REFUGEE01442
          }
        }
        if( actor == 1009240 || actorId == 1009240 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
        }
        if( actor == 1009241 || actorId == 1009241 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( actor == 1008579 || actorId == 1008579 ) // ACTOR0 = MINFILIA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        break;
      }
      case 255:
      {
        if( actor == 1008623 || actorId == 1008623 ) // ACTOR4 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(CutScene), id=unknown
          // +Callback Scene00007: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( actor == 1009239 || actorId == 1009239 ) // ACTOR1 = REFUGEE01442
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=REFUGEE01442
        }
        if( actor == 1009240 || actorId == 1009240 ) // ACTOR2 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1009241 || actorId == 1009241 ) // ACTOR3 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
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
    player.sendDebug( "GaiUse301:66978 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse301:66978 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse301:66978 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=REFUGEE01442" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse301:66978 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse301:66978 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse301:66978 calling Scene00005: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse301:66978 calling Scene00006: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse301:66978 calling [BranchTrue]Scene00007: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse301:66978 calling Scene00008: Normal(Talk, TargetCanMove), id=REFUGEE01442" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse301:66978 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse301:66978 calling Scene00010: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUse301 );
