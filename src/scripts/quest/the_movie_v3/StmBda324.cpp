// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda324 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda324() : Sapphire::ScriptAPI::EventScript( 68166 ){}; 
  ~StmBda324() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 5 entries
  //SEQ_2, 3 entries
  //SEQ_3, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1020068
  //ACTOR1 = 1020069
  //ACTOR10 = 1020078
  //ACTOR11 = 1020079
  //ACTOR12 = 1020080
  //ACTOR13 = 1020081
  //ACTOR2 = 1020070
  //ACTOR3 = 1020067
  //ACTOR4 = 1020066
  //ACTOR5 = 1020073
  //ACTOR6 = 1020074
  //ACTOR7 = 1020075
  //ACTOR8 = 1020076
  //ACTOR9 = 1020077
  //BINDACTOR0 = 6782991
  //BINDACTOR1 = 6782992
  //BINDACTOR2 = 6782494
  //BINDACTOR3 = 6782495
  //BINDACTOR4 = 6790079
  //BINDACTOR5 = 6790080
  //CUTSCENEN01 = 1435
  //TERRITORYTYPE0 = 622

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020068 || param2 == 1020068 ) // ACTOR0 = YUGIRI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020069 || param2 == 1020069 ) // ACTOR1 = GOSETSU
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1020070 || param2 == 1020070 ) // ACTOR2 = LYSE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020067 || param2 == 1020067 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020066 || param2 == 1020066 ) // ACTOR4 = ALISAIE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020073 || param2 == 1020073 ) // ACTOR5 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI
          }
        }
        if( param1 == 1020074 || param2 == 1020074 ) // ACTOR6 = GOSETSU
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1020075 || param2 == 1020075 ) // ACTOR7 = LYSE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020066 || param2 == 1020066 ) // ACTOR4 = ALISAIE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020067 || param2 == 1020067 ) // ACTOR3 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00011( player ); // Scene00011: Normal(CutScene, Dismount), id=unknown
        }
        if( param1 == 1020074 || param2 == 1020074 ) // ACTOR6 = GOSETSU
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1020075 || param2 == 1020075 ) // ACTOR7 = LYSE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020076 || param2 == 1020076 ) // ACTOR8 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI
          }
        }
        if( param1 == 1020077 || param2 == 1020077 ) // ACTOR9 = LYSE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020078 || param2 == 1020078 ) // ACTOR10 = GOSETSU
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020079 || param2 == 1020079 ) // ACTOR11 = YUGIRI
        {
          Scene00017( player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020080 || param2 == 1020080 ) // ACTOR12 = LYSE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020081 || param2 == 1020081 ) // ACTOR13 = GOSETSU
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=GOSETSU
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda324:68166 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00002: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00007: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00008: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00011: Normal(CutScene, Dismount), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00012: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00015: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00016: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YUGIRI" );
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
    player.sendDebug( "StmBda324:68166 calling Scene00018: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda324:68166 calling Scene00019: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda324 );
