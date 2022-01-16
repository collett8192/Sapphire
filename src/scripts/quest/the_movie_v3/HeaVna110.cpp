// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna110 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna110() : Sapphire::ScriptAPI::EventScript( 67125 ){}; 
  ~HeaVna110() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 4 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1012348
  //ACTOR1 = 1012345
  //ACTOR2 = 1012346
  //ACTOR3 = 1012347
  //ACTOR4 = 1011231
  //ACTOR5 = 1012328
  //LOCACTOR0 = 1012497

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012348 || param2 == 1012348 ) // ACTOR0 = ARTOIREL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ARTOIREL
          }
          break;
        }
        if( param1 == 1012345 || param2 == 1012345 ) // ACTOR1 = KIGHT01589
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=KIGHT01589
          break;
        }
        if( param1 == 1012346 || param2 == 1012346 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012347 || param2 == 1012347 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1011231 || param2 == 1011231 ) // ACTOR4 = REDWALD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=REDWALD
          }
          break;
        }
        if( param1 == 1012345 || param2 == 1012345 ) // ACTOR1 = KIGHT01589
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=KIGHT01589
          break;
        }
        if( param1 == 1012346 || param2 == 1012346 ) // ACTOR2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012347 || param2 == 1012347 ) // ACTOR3 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012328 || param2 == 1012328 ) // ACTOR5 = ARTOIREL
        {
          Scene00009( player ); // Scene00009: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1011231 || param2 == 1011231 ) // ACTOR4 = REDWALD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=REDWALD
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna110:67125 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna110:67125 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna110:67125 calling Scene00002: Normal(Talk, TargetCanMove), id=KIGHT01589" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna110:67125 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna110:67125 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna110:67125 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna110:67125 calling Scene00006: Normal(Talk, TargetCanMove), id=KIGHT01589" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna110:67125 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna110:67125 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna110:67125 calling Scene00009: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ARTOIREL" );
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
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna110:67125 calling Scene00010: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna110 );
