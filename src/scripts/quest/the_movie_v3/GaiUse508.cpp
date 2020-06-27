// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse508 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse508() : Sapphire::ScriptAPI::EventScript( 65965 ){}; 
  ~GaiUse508() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 6 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1011000
  //ACTOR1 = 1010898
  //ACTOR2 = 1010899
  //ACTOR3 = 1010900
  //ACTOR4 = 1010901
  //ACTOR5 = 1010897
  //ACTOR6 = 1010902
  //ACTOR7 = 1010903
  //ACTOR8 = 1010904
  //ACTOR9 = 1010905
  //CUTSCENEN01 = 734
  //CUTSCENEN02 = 749
  //EOBJECT0 = 2005045
  //LOCACTORDUMMY0 = 1011654

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1011000 || actorId == 1011000 ) // ACTOR0 = MINFILIA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA
        }
        if( actor == 1010898 || actorId == 1010898 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1010899 || actorId == 1010899 ) // ACTOR2 = YDA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1010900 || actorId == 1010900 ) // ACTOR3 = PAPALYMO
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1010901 || actorId == 1010901 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 1:
      {
        if( actor == 2005045 || actorId == 2005045 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(FadeIn, QuestGimmickReaction), id=unknown
            // +Callback Scene00007: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1011000 || actorId == 1011000 ) // ACTOR0 = MINFILIA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1010898 || actorId == 1010898 ) // ACTOR1 = THANCRED
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1010899 || actorId == 1010899 ) // ACTOR2 = YDA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1010900 || actorId == 1010900 ) // ACTOR3 = PAPALYMO
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1010901 || actorId == 1010901 ) // ACTOR4 = YSHTOLA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 255:
      {
        if( actor == 1010897 || actorId == 1010897 ) // ACTOR5 = MINFILIA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA
          // +Callback Scene00014: Normal(Talk, CutScene, FadeIn, TargetCanMove), id=MINFILIA
        }
        if( actor == 1010902 || actorId == 1010902 ) // ACTOR6 = THANCRED
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1010903 || actorId == 1010903 ) // ACTOR7 = YDA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1010904 || actorId == 1010904 ) // ACTOR8 = PAPALYMO
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1010905 || actorId == 1010905 ) // ACTOR9 = YSHTOLA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse508:65965 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00003: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00004: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00006: Normal(FadeIn, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling [BranchTrue]Scene00007: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00008: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00009: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00010: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00011: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00014( player );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling [BranchTrue]Scene00014: Normal(Talk, CutScene, FadeIn, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00015: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00016: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00017: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse508:65965 calling Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse508 );
