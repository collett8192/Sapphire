// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdb109 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdb109() : Sapphire::ScriptAPI::EventScript( 68506 ){}; 
  ~StmBdb109() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 3 entries
  //SEQ_4, 3 entries
  //SEQ_5, 3 entries
  //SEQ_6, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1024045
  //ACTOR1 = 1024046
  //ACTOR10 = 1024053
  //ACTOR11 = 1024341
  //ACTOR12 = 1024054
  //ACTOR2 = 1024047
  //ACTOR3 = 1024048
  //ACTOR4 = 1024049
  //ACTOR5 = 1023036
  //ACTOR6 = 1024050
  //ACTOR7 = 1024051
  //ACTOR8 = 1024052
  //ACTOR9 = 1024340
  //LOCACTSUFFERING = 961
  //LOCBGM01 = 459
  //LOCBGMBATTLE = 113
  //LOCBGMWINCHEAP = 23
  //LOCBINDALPH01 = 7074699
  //LOCBINDWIS01 = 7074698
  //LOCBINDWIS02 = 7074709
  //LOCENPCALPH01 = 1011887
  //LOCENPCAREN01 = 1019537
  //LOCENPCENEMY01 = 1024346
  //LOCENPCENEMY02 = 1024347
  //LOCENPCWIS01 = 1021992
  //LOCLEVELALPH01 = 7074675
  //LOCLEVELAREN01 = 7074677
  //LOCLEVELENEMYVS01 = 7154151
  //LOCLEVELENEMYVS02 = 7154152
  //LOCLEVELWIS01 = 7074678
  //LOCSEATK = 85
  //LOCSEWIN = 111
  //POPRANGE0 = 7091522
  //POPRANGE1 = 7091527
  //SNP0 = 17
  //SNP1 = 18

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NANAMOULNAMO
        break;
      }
      case 1:
      {
        if( param1 == 1024046 || param2 == 1024046 ) // ACTOR1 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1024045 || param2 == 1024045 ) // ACTOR0 = NANAMOULNAMO
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=NANAMOULNAMO
          break;
        }
        if( param1 == 1024047 || param2 == 1024047 ) // ACTOR2 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024048 || param2 == 1024048 ) // ACTOR3 = ARENVALD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024049 || param2 == 1024049 ) // ACTOR4 = WISCAR
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1023036 || param2 == 1023036 ) // ACTOR5 = WATT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=WATT
          }
          break;
        }
        if( param1 == 1024050 || param2 == 1024050 ) // ACTOR6 = WISCAR
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1024051 || param2 == 1024051 ) // ACTOR7 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024046 || param2 == 1024046 ) // ACTOR1 = LYSE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1024048 || param2 == 1024048 ) // ACTOR3 = ARENVALD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1024052 || param2 == 1024052 ) // ACTOR8 = WISCAR
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove, SystemTalk), id=WISCAR
            // +Callback Scene00013: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00014: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn, SystemTalk), id=WISCAR
          }
          break;
        }
        if( param1 == 1023036 || param2 == 1023036 ) // ACTOR5 = WATT
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=WATT
          break;
        }
        if( param1 == 1024051 || param2 == 1024051 ) // ACTOR7 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1024340 || param2 == 1024340 ) // ACTOR9 = WISCAR
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=WISCAR
          }
          break;
        }
        if( param1 == 1023036 || param2 == 1023036 ) // ACTOR5 = WATT
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=WATT
          break;
        }
        if( param1 == 1024051 || param2 == 1024051 ) // ACTOR7 = ALPHINAUD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1024053 || param2 == 1024053 ) // ACTOR10 = WISCAR
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove, SystemTalk), id=WISCAR
            // +Callback Scene00021: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00022: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn, SystemTalk), id=WISCAR
          }
          break;
        }
        if( param1 == 1023036 || param2 == 1023036 ) // ACTOR5 = WATT
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=WATT
          break;
        }
        if( param1 == 1024051 || param2 == 1024051 ) // ACTOR7 = ALPHINAUD
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1024341 || param2 == 1024341 ) // ACTOR11 = WISCAR
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00025( player ); // Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=WISCAR
          }
          break;
        }
        if( param1 == 1023036 || param2 == 1023036 ) // ACTOR5 = WATT
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=WATT
          break;
        }
        if( param1 == 1024051 || param2 == 1024051 ) // ACTOR7 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1023036 || param2 == 1023036 ) // ACTOR5 = WATT
        {
          Scene00028( player ); // Scene00028: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WATT
          break;
        }
        if( param1 == 1024054 || param2 == 1024054 ) // ACTOR12 = WISCAR
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1024051 || param2 == 1024051 ) // ACTOR7 = ALPHINAUD
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdb109:68506 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00003: Normal(Talk, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00005: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00006: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00007: Normal(Talk, TargetCanMove), id=WATT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00008: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00010: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00011: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00012: Normal(Talk, TargetCanMove, SystemTalk), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00013: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00014( player );
      }
    };
    player.playScene( getId(), 13, INVIS_ENPC, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00014: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn, SystemTalk), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq3( player );
        player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
        player.eventFinish( getId(), 1 );
        player.forceZoneing();
      }
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00015: Normal(Talk, TargetCanMove), id=WATT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00018: Normal(Talk, TargetCanMove), id=WATT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00020: Normal(Talk, TargetCanMove, SystemTalk), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00021: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00022( player );
      }
    };
    player.playScene( getId(), 21, INVIS_ENPC, callback );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00022: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn, SystemTalk), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq5( player );
        player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
        player.eventFinish( getId(), 1 );
        player.forceZoneing();
      }
    };
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00023: Normal(Talk, TargetCanMove), id=WATT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00026: Normal(Talk, TargetCanMove), id=WATT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00028: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WATT" );
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
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00029: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBdb109:68506 calling Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdb109 );
