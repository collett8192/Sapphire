// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsd020 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsd020() : Sapphire::ScriptAPI::EventScript( 65626 ){}; 
  ~GaiUsd020() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 3 entries
  //SEQ_4, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1007478
  //ACTOR1 = 1006444
  //ACTOR2 = 1010054
  //ACTOR3 = 5010000
  //INSTANCEDUNGEON0 = 20025
  //LOCQUESTURICHECK01 = 66548
  //LOCQUESTURICHECK02 = 66734
  //LOCQUESTURICHECK03 = 66948
  //LOCQUESTURICHECK04 = 66949
  //LOCQUESTURICHECK05 = 67066
  //LOCQUESTURICHECK06 = 65579
  //LOCQUESTURICHECK07 = 68684
  //SCREENIMAGE0 = 256
  //UNLOCKADDNEWCONTENTTOCF = 3702

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER
        break;
      }
      case 1:
      {
        if( actor == 1006444 || actorId == 1006444 ) // ACTOR1 = DRILLEMONT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=DRILLEMONT
          }
        }
        if( actor == 1007478 || actorId == 1007478 ) // ACTOR0 = URIANGER
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=URIANGER
        }
        break;
      }
      case 2:
      {
        if( actor == 1010054 || actorId == 1010054 ) // ACTOR2 = TEMPLER00075
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, Message, TargetCanMove), id=TEMPLER00075
          }
        }
        if( actor == 1007478 || actorId == 1007478 ) // ACTOR0 = URIANGER
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=URIANGER
        }
        if( actor == 1006444 || actorId == 1006444 ) // ACTOR1 = DRILLEMONT
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=DRILLEMONT
        }
        break;
      }
      case 3:
      {
        if( actor == 1007478 || actorId == 1007478 ) // ACTOR0 = URIANGER
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=URIANGER
        }
        if( actor == 1006444 || actorId == 1006444 ) // ACTOR1 = DRILLEMONT
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=DRILLEMONT
        }
        if( actor == 1010054 || actorId == 1010054 ) // ACTOR2 = TEMPLER00075
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=TEMPLER00075
        }
        break;
      }
      case 4:
      {
        if( actor == 1006444 || actorId == 1006444 ) // ACTOR1 = DRILLEMONT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=DRILLEMONT
          }
        }
        if( actor == 1007478 || actorId == 1007478 ) // ACTOR0 = URIANGER
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=URIANGER
        }
        if( actor == 1010054 || actorId == 1010054 ) // ACTOR2 = TEMPLER00075
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=TEMPLER00075
        }
        break;
      }
      case 255:
      {
        if( actor == 1007478 || actorId == 1007478 ) // ACTOR0 = URIANGER
        {
          Scene00013( player ); // Scene00013: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=URIANGER
        }
        if( actor == 1006444 || actorId == 1006444 ) // ACTOR1 = DRILLEMONT
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=DRILLEMONT
        }
        if( actor == 1010054 || actorId == 1010054 ) // ACTOR2 = TEMPLER00075
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=TEMPLER00075
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
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsd020:65626 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00003: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00004: Normal(Talk, Message, TargetCanMove), id=TEMPLER00075" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00005: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00006: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00007: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00008: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00009: Normal(Talk, TargetCanMove), id=TEMPLER00075" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00010: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00011: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00012: Normal(Talk, TargetCanMove), id=TEMPLER00075" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00013: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00014: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd020:65626 calling Scene00015: Normal(Talk, TargetCanMove), id=TEMPLER00075" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsd020 );
