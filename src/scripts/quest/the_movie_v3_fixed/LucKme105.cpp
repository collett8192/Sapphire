// FFXIVTheMovie.ParserV3.2
// id hint used:
//EOBJECT0 = dummye0
//SCENE_11 = dummye0
//SCENE_12 = dummye0
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKme105 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKme105() : Sapphire::ScriptAPI::EventScript( 69170 ){}; 
  ~LucKme105() = default; 

  //SEQ_0, 10 entries
  //SEQ_1, 11 entries
  //SEQ_2, 7 entries
  //SEQ_3, 7 entries
  //SEQ_4, 8 entries
  //SEQ_5, 10 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1030197
  //ACTOR1 = 1030198
  //ACTOR10 = 1030207
  //ACTOR11 = 1030208
  //ACTOR12 = 1030866
  //ACTOR13 = 1030867
  //ACTOR14 = 1030868
  //ACTOR15 = 1030869
  //ACTOR16 = 1030870
  //ACTOR17 = 1030209
  //ACTOR18 = 1030210
  //ACTOR19 = 1030211
  //ACTOR2 = 1030199
  //ACTOR3 = 1030200
  //ACTOR4 = 1030201
  //ACTOR5 = 1030202
  //ACTOR6 = 1030203
  //ACTOR7 = 1030204
  //ACTOR8 = 1030205
  //ACTOR9 = 1030206
  //BINDACTOR01 = 7935037
  //BINDACTOR02 = 7935040
  //CUTSCENE0 = 2044
  //EOBJECT0 = 2010124
  //EOBJECT1 = 2010090
  //EOBJECT2 = 2010091
  //EOBJECT3 = 2010092
  //EOBJECT4 = 2010093
  //EVENTACTION0 = 12
  //EVENTACTION1 = 53
  //EVENTACTION2 = 68
  //LOCACTOR01 = 1026567
  //LOCACTOR02 = 1028118
  //LOCBGM01 = 651
  //LOCSE01 = 220
  //LOCSE02 = 39
  //LOCSE03 = 40
  //POPRANGE0 = 7947060
  //POPRANGE1 = 7964000
  //SNIPE0 = 33

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030197 || param2 == 1030197 ) // ACTOR0 = URIANGER
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030198 || param2 == 1030198 ) // ACTOR1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030199 || param2 == 1030199 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030200 || param2 == 1030200 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030201 || param2 == 1030201 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030202 || param2 == 1030202 ) // ACTOR5 = DULIACHAI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1030203 || param2 == 1030203 ) // ACTOR6 = CHAINUZZ
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030204 || param2 == 1030204 ) // ACTOR7 = ALISAIE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030205 || param2 == 1030205 ) // ACTOR8 = THANCRED
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030206 || param2 == 1030206 ) // ACTOR9 = RYNE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2010124 || param2 == 2010124 ) // EOBJECT0 = dummye0
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(CutScene, AutoFadeIn), id=dummye0
          }
          break;
        }
        if( param1 == 1030197 || param2 == 1030197 ) // ACTOR0 = URIANGER
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030198 || param2 == 1030198 ) // ACTOR1 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030199 || param2 == 1030199 ) // ACTOR2 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030200 || param2 == 1030200 ) // ACTOR3 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030201 || param2 == 1030201 ) // ACTOR4 = YSHTOLA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030202 || param2 == 1030202 ) // ACTOR5 = DULIACHAI
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1030203 || param2 == 1030203 ) // ACTOR6 = CHAINUZZ
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030204 || param2 == 1030204 ) // ACTOR7 = ALISAIE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030205 || param2 == 1030205 ) // ACTOR8 = THANCRED
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030206 || param2 == 1030206 ) // ACTOR9 = RYNE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1030207 || param2 == 1030207 ) // ACTOR10 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1030208 || param2 == 1030208 ) // ACTOR11 = ALISAIE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030866 || param2 == 1030866 ) // ACTOR12 = EULMOREMAN03634
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=EULMOREMAN03634
          break;
        }
        if( param1 == 1030867 || param2 == 1030867 ) // ACTOR13 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030868 || param2 == 1030868 ) // ACTOR14 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030869 || param2 == 1030869 ) // ACTOR15 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030870 || param2 == 1030870 ) // ACTOR16 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1030208 || param2 == 1030208 ) // ACTOR11 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1030209 || param2 == 1030209 ) // ACTOR17 = ALPHINAUD
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030866 || param2 == 1030866 ) // ACTOR12 = EULMOREMAN03634
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=EULMOREMAN03634
          break;
        }
        if( param1 == 1030867 || param2 == 1030867 ) // ACTOR13 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030868 || param2 == 1030868 ) // ACTOR14 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030869 || param2 == 1030869 ) // ACTOR15 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030870 || param2 == 1030870 ) // ACTOR16 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2010090 || param2 == 2010090 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00038( player ); // Scene00038: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00039: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1030208 || param2 == 1030208 ) // ACTOR11 = ALISAIE
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030209 || param2 == 1030209 ) // ACTOR17 = ALPHINAUD
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030866 || param2 == 1030866 ) // ACTOR12 = EULMOREMAN03634
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=EULMOREMAN03634
          break;
        }
        if( param1 == 1030867 || param2 == 1030867 ) // ACTOR13 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030868 || param2 == 1030868 ) // ACTOR14 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030869 || param2 == 1030869 ) // ACTOR15 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030870 || param2 == 1030870 ) // ACTOR16 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 2010091 || param2 == 2010091 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00048( player ); // Scene00048: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2010092 || param2 == 2010092 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00050( player ); // Scene00050: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2010093 || param2 == 2010093 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00052( player ); // Scene00052: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1030210 || param2 == 1030210 ) // ACTOR18 = ALISAIE
        {
          Scene00053( player ); // Scene00053: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030211 || param2 == 1030211 ) // ACTOR19 = ALPHINAUD
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030866 || param2 == 1030866 ) // ACTOR12 = EULMOREMAN03634
        {
          Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=EULMOREMAN03634
          break;
        }
        if( param1 == 1030867 || param2 == 1030867 ) // ACTOR13 = unknown
        {
          Scene00056( player ); // Scene00056: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030868 || param2 == 1030868 ) // ACTOR14 = unknown
        {
          Scene00057( player ); // Scene00057: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030869 || param2 == 1030869 ) // ACTOR15 = unknown
        {
          Scene00058( player ); // Scene00058: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030870 || param2 == 1030870 ) // ACTOR16 = unknown
        {
          Scene00059( player ); // Scene00059: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030211 || param2 == 1030211 ) // ACTOR19 = ALPHINAUD
        {
          Scene00060( player ); // Scene00060: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, AutoFadeIn), id=ALPHINAUD
          break;
        }
        if( param1 == 1030210 || param2 == 1030210 ) // ACTOR18 = ALISAIE
        {
          Scene00061( player ); // Scene00061: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030866 || param2 == 1030866 ) // ACTOR12 = EULMOREMAN03634
        {
          Scene00062( player ); // Scene00062: Normal(Talk, TargetCanMove), id=EULMOREMAN03634
          break;
        }
        if( param1 == 1030867 || param2 == 1030867 ) // ACTOR13 = unknown
        {
          Scene00063( player ); // Scene00063: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030868 || param2 == 1030868 ) // ACTOR14 = unknown
        {
          Scene00064( player ); // Scene00064: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030869 || param2 == 1030869 ) // ACTOR15 = unknown
        {
          Scene00065( player ); // Scene00065: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030870 || param2 == 1030870 ) // ACTOR16 = unknown
        {
          Scene00066( player ); // Scene00066: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKme105:69170 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00002: Normal(None), id=unknown" );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00006: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00007: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00009: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00010: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00012: Normal(CutScene, AutoFadeIn), id=dummye0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 814, -464, 361.72, 14.84, -3.14, false );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00013: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00017: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00018: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00019: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00021: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00022: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00025: Normal(Talk, TargetCanMove), id=EULMOREMAN03634" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00030: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00032: Normal(Talk, TargetCanMove), id=EULMOREMAN03634" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00037: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00038: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00039( player );
      }
    };
    player.playScene( getId(), 38, INVIS_ENPC, callback );
  }
  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00039: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 39, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00040: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00041: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00042: Normal(Talk, TargetCanMove), id=EULMOREMAN03634" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00044: Normal(None), id=unknown" );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00045: Normal(None), id=unknown" );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00046: Normal(None), id=unknown" );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00048: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00050: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00052: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00053: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00054: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00055: Normal(Talk, TargetCanMove), id=EULMOREMAN03634" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00056: Normal(None), id=unknown" );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00057: Normal(None), id=unknown" );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00058: Normal(None), id=unknown" );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00059: Normal(None), id=unknown" );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00060: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, AutoFadeIn), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
          player.eventFinish( getId(), 1 );
          player.forceZoneing();
        }
      }
    };
    player.playScene( getId(), 60, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00061: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 61, NONE, callback );
  }

  void Scene00062( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00062: Normal(Talk, TargetCanMove), id=EULMOREMAN03634" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 62, NONE, callback );
  }

  void Scene00063( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00063: Normal(None), id=unknown" );
  }

  void Scene00064( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00064: Normal(None), id=unknown" );
  }

  void Scene00065( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00065: Normal(None), id=unknown" );
  }

  void Scene00066( Entity::Player& player )
  {
    player.sendDebug( "LucKme105:69170 calling Scene00066: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( LucKme105 );
