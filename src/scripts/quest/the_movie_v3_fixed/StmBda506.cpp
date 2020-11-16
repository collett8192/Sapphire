// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda506 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda506() : Sapphire::ScriptAPI::EventScript( 68060 ){}; 
  ~StmBda506() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 4 entries
  //SEQ_2, 3 entries
  //SEQ_3, 5 entries
  //SEQ_4, 5 entries
  //SEQ_5, 1 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1020524
  //ACTOR1 = 1019975
  //ACTOR10 = 1021695
  //ACTOR11 = 1021696
  //ACTOR12 = 5010000
  //ACTOR13 = 1020248
  //ACTOR14 = 1020249
  //ACTOR15 = 1020250
  //ACTOR16 = 1020251
  //ACTOR17 = 1020252
  //ACTOR18 = 1020253
  //ACTOR19 = 1019976
  //ACTOR2 = 1020241
  //ACTOR3 = 1020242
  //ACTOR4 = 1020243
  //ACTOR5 = 1020244
  //ACTOR6 = 1020245
  //ACTOR7 = 1020246
  //ACTOR8 = 1020247
  //ACTOR9 = 1021694
  //BINDALPHINAUD001 = 6851108
  //BINDGOSETSU001 = 6870450
  //BINDGOSETSU002 = 6851118
  //BINDHIEN001 = 6870448
  //BINDYUGIRI001 = 6870449
  //BINDYUGIRI002 = 6851117
  //EOBJECT0 = 2007932
  //EOBJECT1 = 2007893
  //EVENTACTION0 = 10
  //INSTANCEDUNGEON0 = 54
  //NCUTEVENT05040 = 1452
  //NCUTEVENT05050 = 1453
  //NCUTEVENT05060 = 1454
  //NCUTEVENT05070 = 1455
  //NCUTEVENT05080 = 1456
  //NCUTEVENT05090 = 1457
  //POPRANGE0 = 6851133
  //POPRANGE1 = 6851134
  //SCREENIMAGE0 = 494
  //TERRITORYTYPE0 = 614

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020524 || param2 == 1020524 ) // ACTOR0 = HIEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1019975 || param2 == 1019975 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2007932 || param2 == 2007932 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1020241 || param2 == 1020241 ) // ACTOR2 = HIEN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020242 || param2 == 1020242 ) // ACTOR3 = YUGIRI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020243 || param2 == 1020243 ) // ACTOR4 = GOSETSU
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020244 || param2 == 1020244 ) // ACTOR5 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1020245 || param2 == 1020245 ) // ACTOR6 = YUGIRI
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020246 || param2 == 1020246 ) // ACTOR7 = GOSETSU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020247 || param2 == 1020247 ) // ACTOR8 = AOKORA02524
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=AOKORA02524
          }
          break;
        }
        if( param1 == 2007893 || param2 == 2007893 ) // EOBJECT1 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1021694 || param2 == 1021694 ) // ACTOR9 = HIEN
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021695 || param2 == 1021695 ) // ACTOR10 = YUGIRI
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1021696 || param2 == 1021696 ) // ACTOR11 = GOSETSU
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020247 || param2 == 1020247 ) // ACTOR8 = AOKORA02524
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=AOKORA02524
          break;
        }
        if( param1 == 1021694 || param2 == 1021694 ) // ACTOR9 = HIEN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021695 || param2 == 1021695 ) // ACTOR10 = YUGIRI
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1021696 || param2 == 1021696 ) // ACTOR11 = GOSETSU
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 2007893 || param2 == 2007893 ) // EOBJECT1 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00021( player ); // Scene00021: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020248 || param2 == 1020248 ) // ACTOR13 = ALPHINAUD
        {
          Scene00022( player ); // Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020249 || param2 == 1020249 ) // ACTOR14 = ALISAIE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020250 || param2 == 1020250 ) // ACTOR15 = LYSE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020251 || param2 == 1020251 ) // ACTOR16 = HIEN
        {
          Scene00025( player ); // Scene00025: Normal(Talk), id=HIEN
          break;
        }
        if( param1 == 1020252 || param2 == 1020252 ) // ACTOR17 = YUGIRI
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020253 || param2 == 1020253 ) // ACTOR18 = CIRINA
        {
          Scene00027( player ); // Scene00027: Normal(Talk), id=CIRINA
          break;
        }
        if( param1 == 1019976 || param2 == 1019976 ) // ACTOR19 = SOROBAN
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=SOROBAN
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda506:68060 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00004: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00005: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00007: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00011: Normal(Talk, TargetCanMove), id=AOKORA02524" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00013: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00015: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00016: Normal(Talk, TargetCanMove), id=AOKORA02524" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00017: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00018: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00019: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00021: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00024: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00025: Normal(Talk), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00026: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00027: Normal(Talk), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda506:68060 calling Scene00028: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda506 );
