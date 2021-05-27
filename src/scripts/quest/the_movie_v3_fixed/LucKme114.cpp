// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKme114 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKme114() : Sapphire::ScriptAPI::EventScript( 69179 ){}; 
  ~LucKme114() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 9 entries
  //SEQ_3, 9 entries
  //SEQ_4, 2 entries
  //SEQ_5, 1 entries
  //SEQ_255, 9 entries

  //ACTOR0 = 1030295
  //ACTOR1 = 1030294
  //ACTOR10 = 1030320
  //ACTOR11 = 1030303
  //ACTOR12 = 1030304
  //ACTOR13 = 1030305
  //ACTOR14 = 1030306
  //ACTOR15 = 1030307
  //ACTOR16 = 1030308
  //ACTOR17 = 1030589
  //ACTOR2 = 1030296
  //ACTOR3 = 1030302
  //ACTOR4 = 1030297
  //ACTOR5 = 1030298
  //ACTOR6 = 1030299
  //ACTOR7 = 1030300
  //ACTOR8 = 1030301
  //ACTOR9 = 5010000
  //BINDACTOR01 = 7935271
  //BINDACTOR02 = 7936234
  //BINDACTOR03 = 7936235
  //BINDACTOR04 = 7936236
  //BINDACTOR05 = 7936237
  //BINDACTOR06 = 7936238
  //CUTSCENE0 = 2049
  //CUTSCENE1 = 2050
  //CUTSCENE2 = 2051
  //CUTSCENE3 = 2052
  //CUTSCENE4 = 2053
  //CUTSCENE5 = 2054
  //INSTANCEDUNGEON0 = 70
  //INSTANCEDUNGEON1 = 20064
  //LOCACTION01 = 4259
  //LOCBGM01 = 650
  //POPRANGE0 = 8047226
  //POPRANGE1 = 7955847
  //POPRANGE2 = 7955855
  //POPRANGE3 = 8048793
  //POPRANGE4 = 7936284
  //QUEST01 = 66031
  //SCREENIMAGE0 = 746
  //SCREENIMAGE1 = 753
  //TERRITORYTYPE0 = 880

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030295 || param2 == 1030295 ) // ACTOR0 = CHAINUZZ
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030294 || param2 == 1030294 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1030296 || param2 == 1030296 ) // ACTOR2 = DULIACHAI
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1030294 || param2 == 1030294 ) // ACTOR1 = MYSTERYVOICE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove, Menu, CanCancel), id=MYSTERYVOICE
            // +Callback Scene00005: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1030295 || param2 == 1030295 ) // ACTOR0 = CHAINUZZ
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030296 || param2 == 1030296 ) // ACTOR2 = DULIACHAI
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1030302 || param2 == 1030302 ) // ACTOR3 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, TargetCanMove, Menu), id=YSHTOLA
          }
          break;
        }
        if( param1 == 1030297 || param2 == 1030297 ) // ACTOR4 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030298 || param2 == 1030298 ) // ACTOR5 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030299 || param2 == 1030299 ) // ACTOR6 = URIANGER
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030300 || param2 == 1030300 ) // ACTOR7 = THANCRED
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030301 || param2 == 1030301 ) // ACTOR8 = RYNE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030294 || param2 == 1030294 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1030295 || param2 == 1030295 ) // ACTOR0 = CHAINUZZ
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030296 || param2 == 1030296 ) // ACTOR2 = DULIACHAI
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1030297 || param2 == 1030297 ) // ACTOR4 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: MsqDungeon(Talk, TargetCanMove, Menu), id=ALPHINAUD
          break;
        }
        if( param1 == 1030298 || param2 == 1030298 ) // ACTOR5 = ALISAIE
        {
          Scene00018( player ); // Scene00018: MsqDungeon(Talk, TargetCanMove, Menu), id=ALISAIE
          break;
        }
        if( param1 == 1030299 || param2 == 1030299 ) // ACTOR6 = URIANGER
        {
          Scene00019( player ); // Scene00019: MsqDungeon(Talk, TargetCanMove, Menu), id=URIANGER
          break;
        }
        if( param1 == 1030300 || param2 == 1030300 ) // ACTOR7 = THANCRED
        {
          Scene00020( player ); // Scene00020: MsqDungeon(Talk, TargetCanMove, Menu), id=THANCRED
          break;
        }
        if( param1 == 1030301 || param2 == 1030301 ) // ACTOR8 = RYNE
        {
          Scene00021( player ); // Scene00021: MsqDungeon(Talk, TargetCanMove, Menu), id=RYNE
          break;
        }
        if( param1 == 1030302 || param2 == 1030302 ) // ACTOR3 = YSHTOLA
        {
          Scene00022( player ); // Scene00022: MsqDungeon(Talk, TargetCanMove, Menu), id=YSHTOLA
          break;
        }
        if( param1 == 1030294 || param2 == 1030294 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1030295 || param2 == 1030295 ) // ACTOR0 = CHAINUZZ
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030296 || param2 == 1030296 ) // ACTOR2 = DULIACHAI
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00026( player ); // Scene00026: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1030320 || param2 == 1030320 ) // ACTOR10 = unknown
        {
          Scene00028( player );
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1030320 || param2 == 1030320 ) // ACTOR10 = GUIDESOLDIER03643
        {
          Scene00029( player );
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030303 || param2 == 1030303 ) // ACTOR11 = RYNE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=RYNE
          break;
        }
        if( param1 == 1030304 || param2 == 1030304 ) // ACTOR12 = unknown
        {
          break;
        }
        if( param1 == 4302923145 || param2 == 4302923145 ) // ACTOR12 = ALPHINAUD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030305 || param2 == 1030305 ) // ACTOR13 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 4302923146 || param2 == 4302923146 ) // ACTOR14 = ALISAIE
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 4302923147 || param2 == 4302923147 ) // ACTOR15 = THANCRED
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 4302923148 || param2 == 4302923148 ) // ACTOR16 = URIANGER
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 4302923149 || param2 == 4302923149 ) // ACTOR17 = YSHTOLA
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030320 || param2 == 1030320 ) // ACTOR10 = GUIDESOLDIER03643
        {
          Scene00039( player ); // Scene00039: Normal(Talk, YesNo, TargetCanMove), id=GUIDESOLDIER03643
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
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKme114:69179 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00002: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00003: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00004: Normal(Talk, TargetCanMove, Menu, CanCancel), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00005( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00005: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00006: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00007: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00008: Normal(Talk, FadeIn, TargetCanMove, Menu), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00011: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00012: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00013: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00014: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00015: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00016: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00017: MsqDungeon(Talk, TargetCanMove, Menu), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00026( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00018: MsqDungeon(Talk, TargetCanMove, Menu), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00026( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00019: MsqDungeon(Talk, TargetCanMove, Menu), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00026( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00020: MsqDungeon(Talk, TargetCanMove, Menu), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00026( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00021: MsqDungeon(Talk, TargetCanMove, Menu), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00026( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00022: MsqDungeon(Talk, TargetCanMove, Menu), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00026( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00023: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00024: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00025: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00026: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 880 );
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00027: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00028: Normal(Talk, YesNo, TargetCanMove), id=GUIDESOLDIER03643" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 880 );
      }
    };
    player.playScene( getId(), 28, NONE, callback );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00029: Normal(Talk, YesNo, TargetCanMove), id=GUIDESOLDIER03643" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 880 );
      }
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00031( player );
      }
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00031: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
        //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 819, 61.5, 1.716, 248.8, 1.3222, false );
      }
    };
    player.playScene( getId(), 31, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00034: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00035: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00036: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00037: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKme114:69179 calling Scene00039: Normal(Talk, YesNo, TargetCanMove), id=GUIDESOLDIER03643" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 880 );
      }
    };
    player.playScene( getId(), 39, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKme114 );
