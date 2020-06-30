// FFXIVTheMovie.ParserV3
//fix: skip quest battle
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna109 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna109() : Sapphire::ScriptAPI::EventScript( 67124 ){}; 
  ~HeaVna109() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 5 entries
  //SEQ_2, 1 entries
  //SEQ_255, 4 entries

  //ACTIONTIMELINEEVENTBASEGUARDLOOKAWAY = 845
  //ACTIONTIMELINEEVENTBASEGUARDSTAND = 808
  //ACTOR0 = 1012344
  //ACTOR1 = 1012340
  //ACTOR2 = 1012330
  //ACTOR3 = 1012348
  //ACTOR4 = 1012345
  //ACTOR5 = 1012346
  //ACTOR6 = 1012347
  //CUTSCENEN01 = 792
  //EOBJECT0 = 2005408
  //EOBJECT1 = 2005407
  //LOCACTOR0 = 1012497
  //LOCACTOR1 = 1012473
  //LOCACTOR2 = 1012474
  //LOCACTOR3 = 1012475
  //LOCPOSACTOR1 = 5957957
  //LOCPOSACTOR2 = 5957958
  //LOCPOSACTOR3 = 5957959
  //LOCPOSACTOR4 = 5957961
  //LOCPOSACTOR5 = 5957962
  //QUESTBATTLE0 = 111
  //TERRITORYTYPE0 = 479
  //TERRITORYTYPE1 = 397

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012344 || actorId == 1012344 ) // ACTOR0 = ARTOIREL
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ARTOIREL
        }
        if( actor == 1012340 || actorId == 1012340 ) // ACTOR1 = KIGHTA01588
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=KIGHTA01588
        }
        break;
      }
      case 1:
      {
        if( actor == 2005408 || actorId == 2005408 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(QuestBattle, YesNo), id=unknown
          }
        }
        if( actor == 2005407 || actorId == 2005407 ) // EOBJECT1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( actor == 1012344 || actorId == 1012344 ) // ACTOR0 = ARTOIREL
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ARTOIREL
        }
        if( actor == 1012340 || actorId == 1012340 ) // ACTOR1 = KIGHTA01588
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=KIGHTA01588
        }
        if( actor == 1012330 || actorId == 1012330 ) // ACTOR2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == /*UNKNOWN*/1 || actorId == /*UNKNOWN*/1 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00008( player ); // Scene00008: Normal(CutScene), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1012348 || actorId == 1012348 ) // ACTOR3 = ARTOIREL
        {
          Scene00009( player ); // Scene00009: Normal(FadeIn), id=unknown
          // +Callback Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ARTOIREL
        }
        if( actor == 1012345 || actorId == 1012345 ) // ACTOR4 = KIGHTB01588
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=KIGHTB01588
        }
        if( actor == 1012346 || actorId == 1012346 ) // ACTOR5 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( actor == 1012347 || actorId == 1012347 ) // ACTOR6 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
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
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna109:67124 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna109:67124 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna109:67124 calling Scene00002: Normal(Talk, TargetCanMove), id=KIGHTA01588" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna109:67124 calling Scene00003: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00008( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna109:67124 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna109:67124 calling Scene00005: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna109:67124 calling Scene00006: Normal(Talk, TargetCanMove), id=KIGHTA01588" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna109:67124 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna109:67124 calling Scene00008: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 397, 456, 157.5, -549.3, 3.1415 );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna109:67124 calling Scene00009: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna109:67124 calling [BranchTrue]Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna109:67124 calling Scene00011: Normal(Talk, TargetCanMove), id=KIGHTB01588" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna109:67124 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna109:67124 calling Scene00013: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( HeaVna109 );
