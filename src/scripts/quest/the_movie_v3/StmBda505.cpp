// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda505 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda505() : Sapphire::ScriptAPI::EventScript( 68059 ){}; 
  ~StmBda505() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 4 entries
  //SEQ_2, 10 entries
  //SEQ_255, 9 entries

  //ACTOR0 = 1020239
  //ACTOR1 = 1020519
  //ACTOR10 = 1019288
  //ACTOR2 = 1020520
  //ACTOR3 = 1020523
  //ACTOR4 = 1020521
  //ACTOR5 = 1020240
  //ACTOR6 = 1020524
  //ACTOR7 = 1019285
  //ACTOR8 = 1019286
  //ACTOR9 = 1019287
  //NCUTEVENT05020 = 1450
  //NCUTEVENT05030 = 1451
  //POPRANGE0 = 6850091

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020239 || param2 == 1020239 ) // ACTOR0 = HIEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR3 = YUGIRI
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00006: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1020239 || param2 == 1020239 ) // ACTOR0 = HIEN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR2 = ALISAIE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR3 = YUGIRI
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR3 = YUGIRI
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=YUGIRI
            // +Callback Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1020521 || param2 == 1020521 ) // ACTOR4 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020240 || param2 == 1020240 ) // ACTOR5 = GOSETSU
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU
            // +Callback Scene00014: Normal(Talk, TargetCanMove), id=GOSETSU
          }
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR1 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR2 = ALISAIE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020524 || param2 == 1020524 ) // ACTOR6 = HIEN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1019285 || param2 == 1019285 ) // ACTOR7 = HANAME
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=HANAME
          break;
        }
        if( param1 == 1019286 || param2 == 1019286 ) // ACTOR8 = KAIDATE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=KAIDATE
          break;
        }
        if( param1 == 1019287 || param2 == 1019287 ) // ACTOR9 = MOTOJIRO
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=MOTOJIRO
          break;
        }
        if( param1 == 1019288 || param2 == 1019288 ) // ACTOR10 = YAGORO
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=YAGORO
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR1 = ALPHINAUD
        {
          Scene00022( player ); // Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, Menu, CanCancel), id=ALPHINAUD
          // +Callback Scene00023: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR2 = ALISAIE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020240 || param2 == 1020240 ) // ACTOR5 = GOSETSU
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR3 = YUGIRI
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020524 || param2 == 1020524 ) // ACTOR6 = HIEN
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1019285 || param2 == 1019285 ) // ACTOR7 = HANAME
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=HANAME
          break;
        }
        if( param1 == 1019286 || param2 == 1019286 ) // ACTOR8 = KAIDATE
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=KAIDATE
          break;
        }
        if( param1 == 1019287 || param2 == 1019287 ) // ACTOR9 = MOTOJIRO
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=MOTOJIRO
          break;
        }
        if( param1 == 1019288 || param2 == 1019288 ) // ACTOR10 = YAGORO
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=YAGORO
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
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda505:68059 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00006: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00007: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00010: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00014: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00017: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00018: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00019: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00020: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00021: Normal(Talk, TargetCanMove), id=YAGORO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, Menu, CanCancel), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00023( player );
      }
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00023: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
        player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
        player.eventFinish( getId(), 1 );
        player.forceZoneing();
      }
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00025: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00026: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00027: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00028: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00029: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00030: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda505:68059 calling Scene00031: Normal(Talk, TargetCanMove), id=YAGORO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda505 );
