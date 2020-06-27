// FFXIVTheMovie.ParserV3
//fix: skip dungeon
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse607 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse607() : Sapphire::ScriptAPI::EventScript( 65955 ){}; 
  ~GaiUse607() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1006454
  //ACTOR1 = 5010000
  //ACTOR2 = 1010978
  //ACTOR3 = 1006456
  //ACTOR4 = 1006455
  //ACTOR5 = 1010897
  //CUTSCENEN01 = 710
  //INSTANCEDUNGEON0 = 20028
  //LOCACTOR0 = 1009751
  //LOCACTOR1 = 1011788
  //LOCBGM0 = 77
  //POPRANGE0 = 5607422
  //TERRITORYTYPE0 = 155
  //UNLOCKBATTLEISHGARDDEFENCE = 267

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, Message, FadeIn, QuestAccept, TargetCanMove), id=MARCELAIN
        break;
      }
      case 1:
      {
        if( actor == 1006454 || actorId == 1006454 ) // ACTOR0 = MARCELAIN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MARCELAIN
        }
        break;
      }
      case 2:
      {
        if( actor == /*UNKNOWN*/1 || actorId == /*UNKNOWN*/1 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00003( player ); // Scene00003: Normal(CutScene), id=unknown
        }
        break;
      }
      case 3:
      {
        if( actor == 1010978 || actorId == 1010978 ) // ACTOR2 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( actor == 1006454 || actorId == 1006454 ) // ACTOR0 = MARCELAIN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MARCELAIN
        }
        if( actor == 1006456 || actorId == 1006456 ) // ACTOR3 = CHAUNOLLET
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CHAUNOLLET
        }
        if( actor == 1006455 || actorId == 1006455 ) // ACTOR4 = LOANNE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LOANNE
        }
        break;
      }
      case 255:
      {
        if( actor == 1010897 || actorId == 1010897 ) // ACTOR5 = MINFILIA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA
        }
        if( actor == 1006454 || actorId == 1006454 ) // ACTOR0 = MARCELAIN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=MARCELAIN
        }
        if( actor == 1006456 || actorId == 1006456 ) // ACTOR3 = CHAUNOLLET
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CHAUNOLLET
        }
        if( actor == 1006455 || actorId == 1006455 ) // ACTOR4 = LOANNE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=LOANNE
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
    player.sendDebug( "GaiUse607:65955 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse607:65955 calling [BranchTrue]Scene00001: Normal(Talk, Message, FadeIn, QuestAccept, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse607:65955 calling Scene00002: Normal(Talk, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse607:65955 calling Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse607:65955 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse607:65955 calling Scene00005: Normal(Talk, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse607:65955 calling Scene00006: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse607:65955 calling Scene00007: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse607:65955 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse607:65955 calling Scene00009: Normal(Talk, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse607:65955 calling Scene00010: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse607:65955 calling Scene00011: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse607 );
