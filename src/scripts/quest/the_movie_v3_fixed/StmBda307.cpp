// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda307 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda307() : Sapphire::ScriptAPI::EventScript( 68019 ){}; 
  ~StmBda307() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 4 entries
  //SEQ_3, 5 entries
  //SEQ_255, 3 entries

  //ACTIONTIMELINEEVENTJOY = 953
  //ACTOR0 = 1019958
  //ACTOR1 = 1019956
  //ACTOR2 = 1019957
  //ACTOR3 = 1019178
  //ACTOR4 = 1019960
  //ACTOR5 = 1019961
  //ACTOR6 = 1019962
  //ACTOR7 = 1019963
  //ACTOR8 = 1019964
  //BINDACTOR0 = 6830023
  //BINDACTOR1 = 6830024
  //CUTSCENEN01 = 1413
  //ENEMY0 = 6638
  //ITEM0 = 2002094
  //LOCACTOR0 = 1019541
  //LOCACTOR1 = 1018509

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1019958 || param2 == 1019958 ) // ACTOR0 = SOROBAN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=SOROBAN
        }
        if( param1 == 1019956 || param2 == 1019956 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019957 || param2 == 1019957 ) // ACTOR2 = LYSE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019178 || param2 == 1019178 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1019960 || param2 == 1019960 ) // ACTOR4 = SOROBAN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=SOROBAN
        }
        if( param1 == 1019956 || param2 == 1019956 ) // ACTOR1 = ALISAIE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019957 || param2 == 1019957 ) // ACTOR2 = LYSE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 2:
      {
        if( param1 == 1019960 || param2 == 1019960 ) // ACTOR4 = SOROBAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=SOROBAN
          }
        }
        if( param1 == 1019961 || param2 == 1019961 ) // ACTOR5 = ALISAIE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019962 || param2 == 1019962 ) // ACTOR6 = LYSE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019178 || param2 == 1019178 ) // ACTOR3 = BUNCHIN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=BUNCHIN
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 6638 || param2 == 6638 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            player.setQuestUI8BH( getId(), 1 );
            checkProgressSeq3( player );
          }
        }
        if( param1 == 1019963 || param2 == 1019963 ) // ACTOR7 = ALISAIE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019964 || param2 == 1019964 ) // ACTOR8 = LYSE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019960 || param2 == 1019960 ) // ACTOR4 = SOROBAN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=SOROBAN
        }
        if( param1 == 1019178 || param2 == 1019178 ) // ACTOR3 = BUNCHIN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=BUNCHIN
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1019958 || param2 == 1019958 ) // ACTOR0 = SOROBAN
        {
          Scene00016( player ); // Scene00016: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00017: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=SOROBAN
        }
        if( param1 == 1019963 || param2 == 1019963 ) // ACTOR7 = ALISAIE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019964 || param2 == 1019964 ) // ACTOR8 = LYSE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=LYSE
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
    if( player.getQuestUI8BH( getId() ) == 1 )
    {
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda307:68019 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00005: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00007: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00008: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      //checkProgressSeq2( player );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00010: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00011: Normal(Talk, TargetCanMove), id=BUNCHIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00014: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00015: Normal(Talk, TargetCanMove), id=BUNCHIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00016: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00017( player );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling [BranchTrue]Scene00017: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda307:68019 calling Scene00019: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda307 );
