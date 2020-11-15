// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda413 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda413() : Sapphire::ScriptAPI::EventScript( 68048 ){}; 
  ~StmBda413() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 1 entries
  //SEQ_3, 5 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1021625
  //ACTOR1 = 1021608
  //ACTOR10 = 1021615
  //ACTOR2 = 1022085
  //ACTOR3 = 1021611
  //ACTOR4 = 1021612
  //ACTOR5 = 1021613
  //ACTOR6 = 1019321
  //ACTOR7 = 1019320
  //ACTOR8 = 1019322
  //ACTOR9 = 1021626
  //JPOZIGI = 5481
  //NCUTEVENT04070 = 1442
  //QSTACTOR1 = 6866108
  //STANDLISTEN = 801

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1021625 || param2 == 1021625 ) // ACTOR0 = GOSETSU
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021608 || param2 == 1021608 ) // ACTOR1 = DOTHARL02511
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=DOTHARL02511
          break;
        }
        if( param1 == 1022085 || param2 == 1022085 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1021611 || param2 == 1021611 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1021612 || param2 == 1021612 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1021608 || param2 == 1021608 ) // ACTOR1 = DOTHARL02511
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=DOTHARL02511
          break;
        }
        if( param1 == 1022085 || param2 == 1022085 ) // ACTOR2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        Scene00008( player ); // Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=GOSETSU
        break;
        break;
      }
      case 3:
      {
        if( param1 == 1019321 || param2 == 1019321 ) // ACTOR6 = MERGEN
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=MERGEN
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=MERGEN
          }
          break;
        }
        if( param1 == 1019320 || param2 == 1019320 ) // ACTOR7 = KOKO
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=KOKO
            // +Callback Scene00012: Normal(Talk, TargetCanMove), id=KOKO
          }
          break;
        }
        if( param1 == 1019322 || param2 == 1019322 ) // ACTOR8 = QOYAR
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=QOYAR
            // +Callback Scene00014: Normal(Talk, TargetCanMove), id=QOYAR
          }
          break;
        }
        if( param1 == 1021626 || param2 == 1021626 ) // ACTOR9 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1021615 || param2 == 1021615 ) // ACTOR10 = GOSETSU
        {
          Scene00016( player ); // Scene00016: Normal(Talk), id=GOSETSU
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021615 || param2 == 1021615 ) // ACTOR10 = GOSETSU
        {
          Scene00017( player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021626 || param2 == 1021626 ) // ACTOR9 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1019321 || param2 == 1019321 ) // ACTOR6 = MERGEN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=MERGEN
          break;
        }
        if( param1 == 1019320 || param2 == 1019320 ) // ACTOR7 = KOKO
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=KOKO
          break;
        }
        if( param1 == 1019322 || param2 == 1019322 ) // ACTOR8 = QOYAR
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=QOYAR
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda413:68048 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00002: Normal(Talk, TargetCanMove), id=DOTHARL02511" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00006: Normal(Talk, TargetCanMove), id=DOTHARL02511" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00009: Normal(Talk, TargetCanMove), id=MERGEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00010: Normal(Talk, TargetCanMove), id=MERGEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00011: Normal(Talk, TargetCanMove), id=KOKO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00012: Normal(Talk, TargetCanMove), id=KOKO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00013: Normal(Talk, TargetCanMove), id=QOYAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00014: Normal(Talk, TargetCanMove), id=QOYAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00016: Normal(Talk), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GOSETSU" );
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
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00019: Normal(Talk, TargetCanMove), id=MERGEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00020: Normal(Talk, TargetCanMove), id=KOKO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda413:68048 calling Scene00021: Normal(Talk, TargetCanMove), id=QOYAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda413 );
