// FFXIVTheMovie.ParserV3
//fix: skip terri trigger and dungeon
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse507 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse507() : Sapphire::ScriptAPI::EventScript( 65905 ){}; 
  ~GaiUse507() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 3 entries
  //SEQ_4, 6 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1006646
  //ACTOR1 = 1010879
  //ACTOR10 = 1010900
  //ACTOR11 = 1010901
  //ACTOR2 = 1010870
  //ACTOR3 = 5010000
  //ACTOR4 = 1010880
  //ACTOR5 = 1008278
  //ACTOR6 = 1006950
  //ACTOR7 = 1011000
  //ACTOR8 = 1010898
  //ACTOR9 = 1010899
  //CUTSCENEN01 = 701
  //CUTSCENEN02 = 702
  //CUTSCENEN03 = 703
  //CUTSCENEN04 = 704
  //INSTANCEDUNGEON0 = 20029
  //LOCACTOR1 = 1011654
  //LOCACTOR2 = 5580859
  //LOCACTOR3 = 5580857
  //LOCACTOR4 = 5580858
  //LOCACTOR5 = 5580860
  //LOCMUSIC0 = 94
  //LOCSE0 = 44
  //POPRANGE0 = 5585579
  //TERRITORYTYPE0 = 351
  //UNLOCKDUNGEONASIENBATTLE0 = 270

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EDELSTEIN
        break;
      }
      case 1:
      {
        if( actor == 1010879 || actorId == 1010879 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1006646 || actorId == 1006646 ) // ACTOR0 = EDELSTEIN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=EDELSTEIN
        }
        break;
      }
      case 2:
      {
        if( actor == /*UNKNOWN*/1 || actorId == /*UNKNOWN*/1 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          //Scene00004( player ); // Scene00004: Normal(Talk, FadeIn), id=unknown
        }
        if( actor == 1010870 || actorId == 1010870 ) // ACTOR2 = unknown
        {
          Scene00008( player );
        }
        break;
      }
      case 3:
      {
        if( actor == 1010880 || actorId == 1010880 ) // ACTOR4 = MOENBRYDA
        {
          Scene00009( player );
        }
        if( actor == 1008278 || actorId == 1008278 ) // ACTOR5 = WANDERINGMINSTREL
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=WANDERINGMINSTREL
        }
        if( actor == 1006950 || actorId == 1006950 ) // ACTOR6 = ALYS
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALYS
        }
        break;
      }
      case 4:
      {
        if( actor == /*UNKNOWN*/1 || actorId == /*UNKNOWN*/1 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00012( player ); // Scene00012: Normal(CutScene), id=unknown
        }
        if( actor == 1011000 || actorId == 1011000 ) // ACTOR7 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 1010898 || actorId == 1010898 ) // ACTOR8 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( actor == 1010899 || actorId == 1010899 ) // ACTOR9 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( actor == 1010900 || actorId == 1010900 ) // ACTOR10 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( actor == 1010901 || actorId == 1010901 ) // ACTOR11 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1011000 || actorId == 1011000 ) // ACTOR7 = MINFILIA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA
        }
        if( actor == 1010898 || actorId == 1010898 ) // ACTOR8 = THANCRED
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1010899 || actorId == 1010899 ) // ACTOR9 = YDA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1010900 || actorId == 1010900 ) // ACTOR10 = PAPALYMO
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1010901 || actorId == 1010901 ) // ACTOR11 = YSHTOLA
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse507:65905 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00003: Normal(Talk, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00004: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00005: Normal(None), id=unknown" );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00006: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00007: Normal(Message, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00008: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling [BranchChain]Scene00009: Normal(Talk), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00010: Normal(Talk, TargetCanMove), id=WANDERINGMINSTREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00011: Normal(Talk, TargetCanMove), id=ALYS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00012: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 351 );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00018: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00019: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00020: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00021: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse507 );
