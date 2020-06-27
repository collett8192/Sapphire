// FFXIVTheMovie.ParserV3
//fix: quest accept workaround
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse501 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse501() : Sapphire::ScriptAPI::EventScript( 65899 ){}; 
  ~GaiUse501() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1008969
  //ACTOR1 = 1011279
  //ACTOR2 = 1010844
  //ACTOR3 = 1011127
  //ACTOR4 = 1010845
  //ACTOR5 = 1010923
  //CUTSCENEN01 = 694
  //LOCACTOR0 = 5580799
  //LOCACTOR1 = 5580789
  //LOCMOTION0 = 730

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR0 = unknown
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(CutScene, QuestAccept), id=unknown
        }
        if( actor == 1011279 || actorId == 1011279 ) // ACTOR1 = RIOL
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=RIOL
        }
        break;
      }
      case 1:
      {
        if( actor == 1010844 || actorId == 1010844 ) // ACTOR2 = RIOL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=RIOL
          }
        }
        if( actor == 1011127 || actorId == 1011127 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR0 = MINFILIA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        break;
      }
      case 255:
      {
        if( actor == 1010845 || actorId == 1010845 ) // ACTOR4 = ILBERD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ILBERD
        }
        if( actor == 1011279 || actorId == 1011279 ) // ACTOR1 = RIOL
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=RIOL
        }
        if( actor == 1010923 || actorId == 1010923 ) // ACTOR5 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR0 = MINFILIA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=MINFILIA
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
    player.sendDebug( "GaiUse501:65899 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      //if( result.param1 > 0 && result.param2 == 1 )
      //{
        Scene00001( player );
      //}
    };
    player.sendUrgent( "Either \"Accept\" or \"Cancel\" will accept this quest as a workaround." );
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "GaiUse501:65899 calling [BranchTrue]Scene00001: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse501:65899 calling Scene00002: Normal(Talk, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse501:65899 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse501:65899 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse501:65899 calling Scene00005: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse501:65899 calling Scene00006: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ILBERD" );
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

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse501:65899 calling Scene00007: Normal(Talk, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse501:65899 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse501:65899 calling Scene00009: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse501 );
