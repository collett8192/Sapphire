// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda122 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda122() : Sapphire::ScriptAPI::EventScript( 67992 ){}; 
  ~StmBda122() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 1 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1020372
  //ACTOR1 = 1020371
  //ACTOR2 = 1020841
  //ACTOR3 = 1020374
  //ACTOR4 = 1020373
  //BINDACTOR01 = 6830027
  //BINDACTOR02 = 6830045
  //LOCACTOR01 = 1018509
  //LOCACTOR02 = 1019543

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020372 || param2 == 1020372 ) // ACTOR0 = MEFFRID
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MEFFRID
        }
        if( param1 == 1020371 || param2 == 1020371 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 1:
      {
        Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=RAGANFRID
        break;
      }
      case 255:
      {
        if( param1 == 1020374 || param2 == 1020374 ) // ACTOR3 = MEFFRID
        {
          Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=MEFFRID
        }
        if( param1 == 1020373 || param2 == 1020373 ) // ACTOR4 = LYSE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020841 || param2 == 1020841 ) // ACTOR2 = RAGANFRID
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=RAGANFRID
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda122:67992 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda122:67992 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda122:67992 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda122:67992 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=RAGANFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda122:67992 calling Scene00004: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda122:67992 calling Scene00005: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda122:67992 calling Scene00006: Normal(Talk, TargetCanMove), id=RAGANFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda122 );
