// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna331 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna331() : Sapphire::ScriptAPI::EventScript( 67168 ){}; 
  ~HeaVna331() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1012731
  //ACTOR1 = 1012733
  //ACTOR2 = 1012734
  //ACTOR3 = 1012735
  //ACTOR4 = 1012736
  //CUTSCENEN01 = 1038
  //LOCACTOR0 = 1011896
  //LOCACTOR10 = 1011887
  //LOCACTOR11 = 1011896
  //LOCACTOR20 = 1012477
  //LOCACTOR21 = 1012478
  //LOCACTOR22 = 1012479
  //LOCACTOR23 = 1012480
  //LOCACTOR24 = 1012481
  //LOCACTOR30 = 5860488
  //LOCMOTION0 = 924
  //LOCSE0 = 44
  //POPRANGE0 = 5912071
  //TERRITORYTYPE0 = 351

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00002( player ); // Scene00002: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012733 || param2 == 1012733 ) // ACTOR1 = ALPHINAUD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012734 || param2 == 1012734 ) // ACTOR2 = YUGIRI
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1012735 || param2 == 1012735 ) // ACTOR3 = ALIANNE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALIANNE
          break;
        }
        if( param1 == 1012736 || param2 == 1012736 ) // ACTOR4 = RIOL
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=RIOL
          break;
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
    player.sendDebug( "emote: {}", emoteId );
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

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna331:67168 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna331:67168 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna331:67168 calling Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna331:67168 calling Scene00003: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna331:67168 calling Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna331:67168 calling Scene00005: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna331:67168 calling Scene00006: Normal(Talk, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna331 );
