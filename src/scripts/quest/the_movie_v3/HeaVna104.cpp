// FFXIVTheMovie.ParserV3.6
// param used:
//WARP_STABLEHAND01583 = 397|475|225|794|3.1415|true
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna104 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna104() : Sapphire::ScriptAPI::EventScript( 67119 ){}; 
  ~HeaVna104() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1012328
  //ACTOR1 = 1012331
  //ACTOR2 = 1012332
  //ACTOR3 = 1012333
  //ACTOR4 = 1011231
  //CUTSCENEN01 = 791
  //LOCACTOR0 = 1012497
  //LOCBGM0 = 318
  //POPRANGE0 = 5856605
  //TERRITORYTYPE0 = 397

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ARTOIREL
        break;
      }
      case 1:
      {
        if( param1 == 1012331 || param2 == 1012331 ) // ACTOR1 = STABLEHAND01583
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=STABLEHAND01583
          }
          break;
        }
        if( param1 == 1012332 || param2 == 1012332 ) // ACTOR2 = ARTOIREL
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00004( player ); // Scene00004: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1012331 || param2 == 1012331 ) // ACTOR1 = STABLEHAND01583
        {
          Scene00005( player ); // Scene00005: Normal(Talk, YesNo, TargetCanMove), id=STABLEHAND01583
          break;
        }
        if( param1 == 1012332 || param2 == 1012332 ) // ACTOR2 = ARTOIREL
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        break;
      }
      case 3:
      {
        if( type != 2 ) Scene00007( player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=ARTOIREL
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=REDWALD
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna104:67119 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna104:67119 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna104:67119 calling Scene00002: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=STABLEHAND01583" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.setQuestUI8AL( getId(), 1 );
        player.setQuestBitFlag8( getId(), 1, true );
        checkProgressSeq1( player );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 397, 475.0f, 225.0f, 794.0f, 3.14f, true );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna104:67119 calling Scene00003: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna104:67119 calling Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna104:67119 calling Scene00005: Normal(Talk, YesNo, TargetCanMove), id=STABLEHAND01583" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 397, 475.0f, 225.0f, 794.0f, 3.14f, true );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna104:67119 calling Scene00006: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna104:67119 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna104:67119 calling Scene00008: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=REDWALD" );
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
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( HeaVna104 );
