// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmh109 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmh109() : Sapphire::ScriptAPI::EventScript( 69305 ){}; 
  ~LucKmh109() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_3, 2 entries
  //SEQ_255, 7 entries

  //ACTIONTIMELINETOUCHACTIONLOOP = 173
  //ACTIONTIMELINETOUCHTOUCHEND = 174
  //ACTOR0 = 1032555
  //ACTOR1 = 1032554
  //ACTOR10 = 1032546
  //ACTOR11 = 1032547
  //ACTOR12 = 1032548
  //ACTOR13 = 1032545
  //ACTOR14 = 1032550
  //ACTOR2 = 1032539
  //ACTOR3 = 1032540
  //ACTOR4 = 1032541
  //ACTOR5 = 1032542
  //ACTOR6 = 1032543
  //ACTOR7 = 1032544
  //ACTOR8 = 5010000
  //ACTOR9 = 1032549
  //EOBJECT0 = 2010953
  //INSTANCEDUNGEON0 = 74
  //LOCACTORALISAIE = 1026567
  //LOCACTORALPHINAUD = 1026568
  //LOCACTORRYNE = 1027137
  //LOCACTORTHANCRED = 1026569
  //LOCACTORURIANGER = 1026570
  //LOCACTORYSHTOLA = 1026571
  //LOCBINDTHANCRED = 8262663
  //LOCBINDURIANGER = 8262664
  //NCUTLUCKMH00130 = 2244
  //NCUTLUCKMH00140 = 2245
  //POPRANGE0 = 8270127
  //POPRANGE1 = 8270124
  //POPRANGE2 = 8260773
  //SCREENIMAGE0 = 861
  //TERRITORYTYPE0 = 918

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1032555 || param2 == 1032555 ) // ACTOR0 = URIANGER
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032554 || param2 == 1032554 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1032539 || param2 == 1032539 ) // ACTOR2 = URIANGER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=URIANGER
            // +Callback Scene00004: Normal(CutScene, AutoFadeIn), id=unknown
            // +Callback Scene00005: Normal(FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1032540 || param2 == 1032540 ) // ACTOR3 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032541 || param2 == 1032541 ) // ACTOR4 = ALISAIE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032542 || param2 == 1032542 ) // ACTOR5 = THANCRED
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1032543 || param2 == 1032543 ) // ACTOR6 = YSHTOLA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032544 || param2 == 1032544 ) // ACTOR7 = RYNE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1032539 || param2 == 1032539 ) // ACTOR2 = URIANGER
        {
          Scene00011( player ); // Scene00011: MsqDungeon(Talk, TargetCanMove, Menu), id=URIANGER
          break;
        }
        if( param1 == 1032540 || param2 == 1032540 ) // ACTOR3 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: MsqDungeon(Talk, TargetCanMove, Menu), id=ALPHINAUD
          break;
        }
        if( param1 == 1032541 || param2 == 1032541 ) // ACTOR4 = ALISAIE
        {
          Scene00013( player ); // Scene00013: MsqDungeon(Talk, TargetCanMove, Menu), id=ALISAIE
          break;
        }
        if( param1 == 1032542 || param2 == 1032542 ) // ACTOR5 = THANCRED
        {
          Scene00014( player ); // Scene00014: MsqDungeon(Talk, TargetCanMove, Menu), id=THANCRED
          break;
        }
        if( param1 == 1032543 || param2 == 1032543 ) // ACTOR6 = YSHTOLA
        {
          Scene00015( player ); // Scene00015: MsqDungeon(Talk, TargetCanMove, Menu), id=YSHTOLA
          break;
        }
        if( param1 == 1032544 || param2 == 1032544 ) // ACTOR7 = RYNE
        {
          Scene00016( player ); // Scene00016: MsqDungeon(Talk, TargetCanMove, Menu), id=RYNE
          break;
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00017( player ); // Scene00017: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 2010953 || param2 == 2010953 ) // EOBJECT0 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(YesNo), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1032549 || param2 == 1032549 ) // ACTOR9 = YSHTOLA
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=YSHTOLA
          // +Callback Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn, SystemTalk), id=unknown
          break;
        }
        if( param1 == 2010953 || param2 == 2010953 ) // EOBJECT0 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(YesNo), id=unknown
          break;
        }
        if( param1 == 1032546 || param2 == 1032546 ) // ACTOR10 = ALPHINAUD
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032547 || param2 == 1032547 ) // ACTOR11 = ALISAIE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032548 || param2 == 1032548 ) // ACTOR12 = THANCRED
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1032545 || param2 == 1032545 ) // ACTOR13 = URIANGER
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032550 || param2 == 1032550 ) // ACTOR14 = RYNE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=RYNE
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmh109:69305 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00003: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00004: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00005: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00008: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00010: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00011: MsqDungeon(Talk, TargetCanMove, Menu), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00017( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00012: MsqDungeon(Talk, TargetCanMove, Menu), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00017( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00013: MsqDungeon(Talk, TargetCanMove, Menu), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00017( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00014: MsqDungeon(Talk, TargetCanMove, Menu), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00017( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00015: MsqDungeon(Talk, TargetCanMove, Menu), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00017( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00016: MsqDungeon(Talk, TargetCanMove, Menu), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00017( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00017: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 918 );
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00018: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 918 );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00019: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.eventFinish( getId(), 1 );
          player.exitInstance();
        }
      }
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00021: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 918 );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00024: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00025: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmh109:69305 calling Scene00026: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmh109 );
