// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda306 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda306() : Sapphire::ScriptAPI::EventScript( 68018 ){}; 
  ~StmBda306() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 5 entries
  //SEQ_3, 6 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1021505
  //ACTOR1 = 1019936
  //ACTOR10 = 1019958
  //ACTOR2 = 1020363
  //ACTOR3 = 1019951
  //ACTOR4 = 1019952
  //ACTOR5 = 1019953
  //ACTOR6 = 1019954
  //ACTOR7 = 1019955
  //ACTOR8 = 1019956
  //ACTOR9 = 1019957
  //BINDACTOR0 = 6829414
  //BINDACTOR1 = 6904905
  //BINDACTOR2 = 6829499
  //CUTSCENEN01 = 1412
  //EOBJECT0 = 2007914
  //EVENTRANGE0 = 6829506
  //LOCACTOR0 = 1019541
  //POPRANGE0 = 6829508

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR0 = RASHO
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RASHO
        }
        if( param1 == 1019936 || param2 == 1019936 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020363 || param2 == 1020363 ) // ACTOR2 = TANSUI
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TANSUI
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019951 || param2 == 1019951 ) // ACTOR3 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=LYSE
          }
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR0 = RASHO
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=RASHO
        }
        if( param1 == 1020363 || param2 == 1020363 ) // ACTOR2 = TANSUI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=TANSUI
        }
        break;
      }
      case 2:
      {
        if( param1 == 1019952 || param2 == 1019952 ) // ACTOR4 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE
          }
        }
        if( param1 == 1019953 || param2 == 1019953 ) // ACTOR5 = LYSE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 2007914 || param2 == 2007914 ) // EOBJECT0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR0 = RASHO
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=RASHO
        }
        if( param1 == 1020363 || param2 == 1020363 ) // ACTOR2 = TANSUI
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=TANSUI
        }
        break;
      }
      case 3:
      {
        if( param1 == 6829506 || param2 == 6829506 ) // EVENTRANGE0 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(CutScene, Dismount), id=unknown
        }
        if( param1 == 1019954 || param2 == 1019954 ) // ACTOR6 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( param1 == 1019955 || param2 == 1019955 ) // ACTOR7 = LYSE
        {
          Scene00014( player ); // Scene00014: Normal(Talk), id=LYSE
        }
        if( param1 == 2007914 || param2 == 2007914 ) // EOBJECT0 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR0 = RASHO
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=RASHO
        }
        if( param1 == 1020363 || param2 == 1020363 ) // ACTOR2 = TANSUI
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=TANSUI
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019956 || param2 == 1019956 ) // ACTOR8 = ALISAIE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019957 || param2 == 1019957 ) // ACTOR9 = LYSE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019958 || param2 == 1019958 ) // ACTOR10 = SOROBAN
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=SOROBAN
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR0 = RASHO
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=RASHO
        }
        if( param1 == 1020363 || param2 == 1020363 ) // ACTOR2 = TANSUI
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=TANSUI
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
    player.sendDebug( "StmBda306:68018 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda306:68018 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00003: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00005: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00006: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00008: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00010: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00011: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00012: Normal(CutScene, Dismount), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 613, 421.894, -98.99, -224.644, -1.385, false );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00014: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00016: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00017: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00019: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00020: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00021: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda306:68018 calling Scene00022: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda306 );
