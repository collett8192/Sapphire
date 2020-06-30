// FFXIVTheMovie.ParserV3
//fix: skip quest battle
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna118 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna118() : Sapphire::ScriptAPI::EventScript( 67133 ){}; 
  ~HeaVna118() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 5 entries
  //SEQ_3, 5 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINEEVENTBASECHOCOBOBRUSH = 848
  //ACTIONTIMELINEEVENTBASEHEADDOWN = 849
  //ACTIONTIMELINEEVENTFLAPSING = 948
  //ACTIONTIMELINEEVENTJUMP = 966
  //ACTIONTIMELINEEVENTSIGH = 4229
  //ACTIONTIMELINEEVENTSPECIALJOY = 1059
  //ACTOR0 = 1012377
  //ACTOR1 = 1012378
  //ACTOR2 = 1012380
  //ACTOR3 = 1012379
  //ACTOR4 = 1013167
  //ACTOR5 = 1012381
  //CUTSCENEN01 = 795
  //CUTSCENEN02 = 796
  //EOBJECT0 = 2005421
  //LOCACTOR0 = 5853387
  //LOCACTOR1 = 5860710
  //LOCACTOR10 = 1012439
  //LOCACTOR11 = 1012440
  //LOCBGM0 = 317
  //LOCSE0 = 48
  //QUESTBATTLE0 = 105
  //TERRITORYTYPE0 = 456
  //UNLOCKAETHERCURRENTS = 327

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, TargetCanMove), id=HOUSEFORTEMPSSTEWARD01597
        // +Callback Scene00002: Normal(CutScene, QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        if( actor == 1012378 || actorId == 1012378 ) // ACTOR1 = EDMONT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=EDMONT
          }
        }
        if( actor == 1012377 || actorId == 1012377 ) // ACTOR0 = HOUSEFORTEMPSSTEWARD01597
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSSTEWARD01597
        }
        break;
      }
      case 2:
      {
        if( actor == 1012380 || actorId == 1012380 ) // ACTOR2 = AYMERIC
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=AYMERIC
          }
        }
        if( actor == 1012379 || actorId == 1012379 ) // ACTOR3 = HAURCHEFANT
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 1012378 || actorId == 1012378 ) // ACTOR1 = EDMONT
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=EDMONT
        }
        if( actor == 1013167 || actorId == 1013167 ) // ACTOR4 = LUCIA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1012377 || actorId == 1012377 ) // ACTOR0 = HOUSEFORTEMPSSTEWARD01597
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSSTEWARD01597
        }
        break;
      }
      case 3:
      {
        if( actor == 1012381 || actorId == 1012381 ) // ACTOR5 = HAURCHEFANT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=HAURCHEFANT
            // +Callback Scene00011: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1012380 || actorId == 1012380 ) // ACTOR2 = AYMERIC
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( actor == 2005421 || actorId == 2005421 ) // EOBJECT0 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 1013167 || actorId == 1013167 ) // ACTOR4 = LUCIA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1012377 || actorId == 1012377 ) // ACTOR0 = HOUSEFORTEMPSSTEWARD01597
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSSTEWARD01597
        }
        break;
      }
      case 255:
      {
        Scene00016( player ); // Scene00016: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HAURCHEFANT
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
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
    player.sendDebug( "HeaVna118:67133 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna118:67133 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, TargetCanMove), id=HOUSEFORTEMPSSTEWARD01597" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling [BranchChain]Scene00002: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling Scene00003: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling Scene00004: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSSTEWARD01597" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling Scene00006: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling Scene00007: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling Scene00008: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling Scene00009: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSSTEWARD01597" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling Scene00010: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 != 50 )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling [BranchTrue]Scene00011: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 419, 127.5, 15, -156, -0.84 );
      player.sendUrgent( "need re-login to fix the bgm." );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling Scene00012: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling Scene00014: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling Scene00015: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSSTEWARD01597" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna118:67133 calling Scene00016: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( HeaVna118 );
