// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_5 = RAUBAHN
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda112 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda112() : Sapphire::ScriptAPI::EventScript( 67988 ){}; 
  ~StmBda112() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1020351
  //ACTOR1 = 1020350
  //ACTOR2 = 1020353
  //ACTOR3 = 1020352
  //ACTOR4 = 1020304
  //ACTOR5 = 1020354
  //BINDACTOR01 = 6829566
  //BINDACTOR02 = 6829571
  //CUTSCENEN01 = 1385
  //LOCACTOR01 = 1017687
  //LOCACTOR02 = 1018318
  //LOCACTOR03 = 1015903

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020351 || param2 == 1020351 ) // ACTOR0 = MNAAGO
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MNAAGO
        }
        if( param1 == 1020350 || param2 == 1020350 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020353 || param2 == 1020353 ) // ACTOR2 = MNAAGO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MNAAGO
          }
        }
        if( param1 == 1020352 || param2 == 1020352 ) // ACTOR3 = ALISAIE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020304 || param2 == 1020304 ) // ACTOR4 = RAUBAHN
        {
          Scene00005( player ); // Scene00005: Normal(CutScene), id=RAUBAHN
          // +Callback Scene00006: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN
        }
        if( param1 == 1020354 || param2 == 1020354 ) // ACTOR5 = PIPIN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=PIPIN
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
    onProgress( player, param1, param1, 3, 0 );
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda112:67988 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda112:67988 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda112:67988 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda112:67988 calling Scene00003: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda112:67988 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda112:67988 calling Scene00005: Normal(CutScene), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda112:67988 calling [BranchTrue]Scene00006: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda112:67988 calling Scene00007: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda112 );
