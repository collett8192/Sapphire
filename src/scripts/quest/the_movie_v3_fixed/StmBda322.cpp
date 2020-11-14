// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda322 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda322() : Sapphire::ScriptAPI::EventScript( 68034 ){}; 
  ~StmBda322() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 1 entries
  //SEQ_255, 9 entries

  //ACTIONTIMELINEEVENTLOOKAROUNDHEAD = 665
  //ACTOR0 = 1020055
  //ACTOR1 = 1020052
  //ACTOR10 = 1023078
  //ACTOR11 = 1023079
  //ACTOR2 = 1020056
  //ACTOR3 = 1020057
  //ACTOR4 = 1020058
  //ACTOR5 = 1020059
  //ACTOR6 = 1020189
  //ACTOR7 = 1020060
  //ACTOR8 = 1020061
  //ACTOR9 = 1023077
  //BINDACTOR0 = 6782483
  //EOBJECT0 = 2007842
  //EOBJECT1 = 2007843
  //EVENTACTION0 = 50
  //LOCACTOR0 = 1019096
  //NCUT01 = 1430
  //NCUT02 = 1431
  //QUESTBATTLE0 = 163
  //TERRITORYTYPE0 = 685
  //TERRITORYTYPE1 = 614

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020055 || param2 == 1020055 ) // ACTOR0 = YUGIRI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020052 || param2 == 1020052 ) // ACTOR1 = GOSETSU
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        break;
      }
      case 1:
      {
        if( param1 == 2007842 || param2 == 2007842 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(SystemTalk), id=unknown
            // +Callback Scene00005: Normal(Talk, FadeIn), id=unknown
          }
        }
        if( param1 == 1020052 || param2 == 1020052 ) // ACTOR1 = GOSETSU
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020056 || param2 == 1020056 ) // ACTOR2 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, QuestBattle, YesNo, TargetCanMove, CanCancel), id=YUGIRI
          }
        }
        if( param1 == 2007843 || param2 == 2007843 ) // EOBJECT1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(CutScene, AutoFadeIn), id=unknown
        }
        if( param1 == 1020052 || param2 == 1020052 ) // ACTOR1 = GOSETSU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00011( player ); // Scene00011: Normal(CutScene, FadeIn, AutoFadeIn), id=unknown
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020057 || param2 == 1020057 ) // ACTOR3 = ALISAIE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020058 || param2 == 1020058 ) // ACTOR4 = GOSETSU
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1020059 || param2 == 1020059 ) // ACTOR5 = ISSE
        {
          Scene00014( player ); // Scene00014: Normal(Talk), id=ISSE
        }
        if( param1 == 1020189 || param2 == 1020189 ) // ACTOR6 = YUGIRI
        {
          Scene00015( player ); // Scene00015: Normal(Talk), id=YUGIRI
        }
        if( param1 == 1020060 || param2 == 1020060 ) // ACTOR7 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( param1 == 1020061 || param2 == 1020061 ) // ACTOR8 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( param1 == 1023077 || param2 == 1023077 ) // ACTOR9 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        if( param1 == 1023078 || param2 == 1023078 ) // ACTOR10 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( param1 == 1023079 || param2 == 1023079 ) // ACTOR11 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda322:68034 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00002: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00004: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00005: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00007: Normal(Talk, QuestBattle, YesNo, TargetCanMove, CanCancel), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        //player.setQuestUI8AL( getId(), 1 );
        //checkProgressSeq2( player );
        Scene00011( player );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00008: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00011: Normal(CutScene, FadeIn, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 614, 484.87, 6.346, 376.551, 2, false );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
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
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00014: Normal(Talk), id=ISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00015: Normal(Talk), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda322:68034 calling Scene00020: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda322 );
