// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmc118 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmc118() : Sapphire::ScriptAPI::EventScript( 68875 ){}; 
  ~LucKmc118() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 8 entries
  //SEQ_2, 9 entries
  //SEQ_3, 9 entries
  //SEQ_4, 10 entries
  //SEQ_255, 10 entries

  //ACTOR0 = 1029249
  //ACTOR1 = 1029250
  //ACTOR10 = 5010000
  //ACTOR11 = 1029554
  //ACTOR12 = 1029555
  //ACTOR13 = 1029556
  //ACTOR14 = 1029762
  //ACTOR2 = 1029251
  //ACTOR3 = 1029252
  //ACTOR4 = 1029253
  //ACTOR5 = 1029254
  //ACTOR6 = 1029255
  //ACTOR7 = 1029256
  //ACTOR8 = 1029552
  //ACTOR9 = 1029553
  //EOBJECT0 = 2009892
  //EVENTACTION0 = 30
  //ITEM0 = 2002554
  //LOCBINDACTOR0 = 7927602
  //LOCBINDACTOR1 = 7927607
  //LOCBINDACTOR2 = 7928008
  //LOCBINDACTOR3 = 7928009
  //LOCBINDACTOR4 = 7928435
  //LOCBINDACTOR5 = 8049879
  //NCUTEVENTLUCKMC11801 = 2012
  //NCUTEVENTLUCKMC11802 = 2013
  //POPRANGE0 = 7928432

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029249 || param2 == 1029249 ) // ACTOR0 = URIANGER
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER
          // +Callback Scene00002: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1029250 || param2 == 1029250 ) // ACTOR1 = RUNAR
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=RUNAR
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 1029251 || param2 == 1029251 ) // ACTOR2 = EMETSELCH
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove, SystemTalk), id=EMETSELCH
          }
          break;
        }
        if( param1 == 1029252 || param2 == 1029252 ) // ACTOR3 = THANCRED
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029253 || param2 == 1029253 ) // ACTOR4 = RYNE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029254 || param2 == 1029254 ) // ACTOR5 = URIANGER
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029255 || param2 == 1029255 ) // ACTOR6 = ALMET
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029256 || param2 == 1029256 ) // ACTOR7 = UIMET
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029552 || param2 == 1029552 ) // ACTOR8 = CYMET
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        if( param1 == 1029553 || param2 == 1029553 ) // ACTOR9 = RUNAR
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=RUNAR
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( param1 == 5010000 || param2 == 5010000 ) // ACTOR10 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(SystemTalk, CanCancel), id=unknown
          }
          break;
        }
        if( param1 == 1029251 || param2 == 1029251 ) // ACTOR2 = EMETSELCH
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=EMETSELCH
          break;
        }
        if( param1 == 1029252 || param2 == 1029252 ) // ACTOR3 = THANCRED
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029253 || param2 == 1029253 ) // ACTOR4 = RYNE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029254 || param2 == 1029254 ) // ACTOR5 = URIANGER
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029255 || param2 == 1029255 ) // ACTOR6 = ALMET
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029256 || param2 == 1029256 ) // ACTOR7 = UIMET
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029552 || param2 == 1029552 ) // ACTOR8 = CYMET
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        if( param1 == 1029553 || param2 == 1029553 ) // ACTOR9 = RUNAR
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=RUNAR
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      case 3:
      {
        if( param1 == 2009892 || param2 == 2009892 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1029251 || param2 == 1029251 ) // ACTOR2 = EMETSELCH
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=EMETSELCH
          break;
        }
        if( param1 == 1029252 || param2 == 1029252 ) // ACTOR3 = THANCRED
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029253 || param2 == 1029253 ) // ACTOR4 = RYNE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029254 || param2 == 1029254 ) // ACTOR5 = URIANGER
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029255 || param2 == 1029255 ) // ACTOR6 = ALMET
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029256 || param2 == 1029256 ) // ACTOR7 = UIMET
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029552 || param2 == 1029552 ) // ACTOR8 = CYMET
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        if( param1 == 1029553 || param2 == 1029553 ) // ACTOR9 = RUNAR
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=RUNAR
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      case 4:
      {
        if( param1 == 1029554 || param2 == 1029554 ) // ACTOR11 = EMETSELCH
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00032( player ); // Scene00032: Normal(Talk, NpcDespawn, TargetCanMove, Menu), id=EMETSELCH
          }
          break;
        }
        if( param1 == 1029252 || param2 == 1029252 ) // ACTOR3 = THANCRED
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029253 || param2 == 1029253 ) // ACTOR4 = RYNE
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029254 || param2 == 1029254 ) // ACTOR5 = URIANGER
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029255 || param2 == 1029255 ) // ACTOR6 = ALMET
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029256 || param2 == 1029256 ) // ACTOR7 = UIMET
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029552 || param2 == 1029552 ) // ACTOR8 = CYMET
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        if( param1 == 1029555 || param2 == 1029555 ) // ACTOR12 = YSHTOLA
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029556 || param2 == 1029556 ) // ACTOR13 = RUNAR
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=RUNAR
          break;
        }
        if( param1 == 1029762 || param2 == 1029762 ) // ACTOR14 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( param1 == 1029555 || param2 == 1029555 ) // ACTOR12 = YSHTOLA
        {
          Scene00042( player ); // Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029251 || param2 == 1029251 ) // ACTOR2 = EMETSELCH
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=EMETSELCH
          break;
        }
        if( param1 == 1029252 || param2 == 1029252 ) // ACTOR3 = THANCRED
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029253 || param2 == 1029253 ) // ACTOR4 = RYNE
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029254 || param2 == 1029254 ) // ACTOR5 = URIANGER
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029255 || param2 == 1029255 ) // ACTOR6 = ALMET
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029256 || param2 == 1029256 ) // ACTOR7 = UIMET
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029552 || param2 == 1029552 ) // ACTOR8 = CYMET
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        if( param1 == 1029556 || param2 == 1029556 ) // ACTOR13 = RUNAR
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=RUNAR
          break;
        }
        if( param1 == 1029762 || param2 == 1029762 ) // ACTOR14 = unknown
        {
          Scene00051( player ); // Scene00051: Normal(None), id=unknown
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
      player.updateQuest( getId(), 3 );
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmc118:68875 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00003: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00004: Normal(Talk, TargetCanMove, SystemTalk), id=EMETSELCH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00005: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00006: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00007: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00008: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00009: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00010: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00011: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00012: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00014: Normal(Talk, TargetCanMove), id=EMETSELCH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00015: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00016: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00017: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00018: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00019: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00020: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00021: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00023: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00024: Normal(Talk, TargetCanMove), id=EMETSELCH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00025: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00026: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00027: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00028: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00029: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00030: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00031: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00032: Normal(Talk, NpcDespawn, TargetCanMove, Menu), id=EMETSELCH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq4( player );
      }
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00033: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00034: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00035: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00036: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00037: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00038: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00039: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00040: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA" );
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
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00043: Normal(Talk, TargetCanMove), id=EMETSELCH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00044: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00045: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00046: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00047: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00048: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00049: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00050: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "LucKmc118:68875 calling Scene00051: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( LucKmc118 );
