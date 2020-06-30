// FFXIVTheMovie.ParserV3
//fix: fix black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna119 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna119() : Sapphire::ScriptAPI::EventScript( 67134 ){}; 
  ~HeaVna119() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 6 entries
  //SEQ_255, 2 entries

  //ACTIONTIMELINETALKJOKE = 4220
  //ACTOR0 = 1012381
  //ACTOR1 = 1013033
  //ACTOR2 = 1013034
  //ACTOR3 = 1013035
  //ACTOR4 = 1013383
  //ACTOR5 = 1012386
  //ACTOR6 = 1012377
  //ACTOR7 = 1012387
  //ACTOR8 = 1013197
  //CUTSCENEN01 = 797
  //CUTSCENEN02 = 798
  //LOCACTOR0 = 5852948
  //LOCACTOR1 = 5852949
  //LOCACTOR2 = 5876300
  //LOCACTOR3 = 1012441
  //LOCSE0 = 68
  //LOCSE1 = 39
  //LOCSE2 = 40
  //POPRANGE0 = 5935943

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HAURCHEFANT
        break;
      }
      case 1:
      {
        if( actor == 1013033 || actorId == 1013033 ) // ACTOR1 = EDMONT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=EDMONT
          }
        }
        if( actor == 1012381 || actorId == 1012381 ) // ACTOR0 = HAURCHEFANT
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 1013034 || actorId == 1013034 ) // ACTOR2 = ARTOIREL
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ARTOIREL
        }
        if( actor == 1013035 || actorId == 1013035 ) // ACTOR3 = EMMANELLAIN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( actor == 1013383 || actorId == 1013383 ) // ACTOR4 = HONOROIT
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        break;
      }
      case 2:
      {
        if( actor == 1012386 || actorId == 1012386 ) // ACTOR5 = PRIEST01598
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=PRIEST01598
            // +Callback Scene00008: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1013033 || actorId == 1013033 ) // ACTOR1 = EDMONT
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=EDMONT
        }
        if( actor == 1013034 || actorId == 1013034 ) // ACTOR2 = ARTOIREL
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ARTOIREL
        }
        if( actor == 1013035 || actorId == 1013035 ) // ACTOR3 = EMMANELLAIN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( actor == 1013383 || actorId == 1013383 ) // ACTOR4 = HONOROIT
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( actor == 1012377 || actorId == 1012377 ) // ACTOR6 = HOUSEFORTEMPSSTEWARD01598
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSSTEWARD01598
        }
        break;
      }
      case 255:
      {
        if( actor == 1012387 || actorId == 1012387 ) // ACTOR7 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( actor == 1013197 || actorId == 1013197 ) // ACTOR8 = PRIEST01598
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=PRIEST01598
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna119:67134 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00003: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00004: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00005: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00006: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00007: Normal(Talk, TargetCanMove), id=PRIEST01598" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling [BranchTrue]Scene00008: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 419, 0, 28, -170.5, 0 );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00009: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00010: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00011: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00012: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00013: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSSTEWARD01598" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00014: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna119:67134 calling Scene00015: Normal(Talk, TargetCanMove), id=PRIEST01598" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna119 );
