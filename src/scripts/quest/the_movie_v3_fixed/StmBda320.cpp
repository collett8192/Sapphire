// FFXIVTheMovie.ParserV3.1
// id hint used:
//ACTOR4 = BIGSOLDIER02496
//ACTOR5 = SMALLSOLDIER02496
//ACTOR6 = MIDDLESOLDIER02496
//SCENE_16 = BIGSOLDIER02496
//SCENE_19 = SMALLSOLDIER02496
//SCENE_22 = MIDDLESOLDIER02496
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda320 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda320() : Sapphire::ScriptAPI::EventScript( 68032 ){}; 
  ~StmBda320() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_4, 5 entries
  //SEQ_5, 7 entries
  //SEQ_6, 3 entries
  //SEQ_255, 4 entries

  //ACTIONTIMELINEEVENTEMOTELOOKOUTADD = 665
  //ACTIONTIMELINEEVENTEMPIRIALSALUTE = 587
  //ACTOR0 = 1023780
  //ACTOR1 = 1019966
  //ACTOR10 = 1020048
  //ACTOR11 = 1020029
  //ACTOR2 = 1019967
  //ACTOR3 = 1020042
  //ACTOR4 = 1020043
  //ACTOR5 = 1020044
  //ACTOR6 = 1020045
  //ACTOR7 = 1020040
  //ACTOR8 = 1020041
  //ACTOR9 = 1020047
  //BINDACTOR0 = 6782433
  //BINDACTOR1 = 6782434
  //BINDACTOR2 = 6782435
  //BINDACTOR3 = 6782436
  //EOBJECT0 = 2007839
  //EOBJECT1 = 2008909
  //EOBJECT2 = 2008910
  //EVENTACTION0 = 41
  //EVENTACTION1 = 1
  //EVENTACTION2 = 26
  //NCUT01 = 1427
  //RITEM0 = 20597
  //RITEM1 = 20599
  //RITEM2 = 20600
  //RITEM3 = 20596
  //RITEM4 = 20598

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1023780 || param2 == 1023780 ) // ACTOR0 = YUGIRI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1019966 || param2 == 1019966 ) // ACTOR1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(None), id=unknown
        }
        if( param1 == 1019967 || param2 == 1019967 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
        }
        break;
      }
      case 1:
      {
        if( param1 == 2007839 || param2 == 2007839 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(SystemTalk), id=unknown
          }
        }
        if( param1 == 1019966 || param2 == 1019966 ) // ACTOR1 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( param1 == 1019967 || param2 == 1019967 ) // ACTOR2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020042 || param2 == 1020042 ) // ACTOR3 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI
          }
        }
        if( param1 == 1019966 || param2 == 1019966 ) // ACTOR1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( param1 == 1019967 || param2 == 1019967 ) // ACTOR2 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( param1 == 1020043 || param2 == 1020043 ) // ACTOR4 = BIGSOLDIER02496
        {
          Scene00011( player ); // Scene00011: Normal(Talk), id=BIGSOLDIER02496
        }
        if( param1 == 1020044 || param2 == 1020044 ) // ACTOR5 = SMALLSOLDIER02496
        {
          Scene00012( player ); // Scene00012: Normal(Talk), id=SMALLSOLDIER02496
        }
        if( param1 == 1020045 || param2 == 1020045 ) // ACTOR6 = MIDDLESOLDIER02496
        {
          Scene00013( player ); // Scene00013: Normal(Talk), id=MIDDLESOLDIER02496
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020043 || param2 == 1020043 ) // ACTOR4 = BIGSOLDIER02496
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(SystemTalk, CanCancel), id=unknown
            // +Callback Scene00016: Normal(Talk, FadeIn, SystemTalk), id=BIGSOLDIER02496
          }
        }
        if( param1 == 1020044 || param2 == 1020044 ) // ACTOR5 = SMALLSOLDIER02496
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(SystemTalk, CanCancel), id=unknown
            // +Callback Scene00019: Normal(Talk, FadeIn, SystemTalk), id=SMALLSOLDIER02496
          }
        }
        if( param1 == 1020045 || param2 == 1020045 ) // ACTOR6 = MIDDLESOLDIER02496
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(SystemTalk, CanCancel), id=unknown
            // +Callback Scene00022: Normal(Talk, FadeIn, SystemTalk), id=MIDDLESOLDIER02496
          }
        }
        if( param1 == 1020042 || param2 == 1020042 ) // ACTOR3 = YUGIRI
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1019966 || param2 == 1019966 ) // ACTOR1 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
        }
        if( param1 == 1019967 || param2 == 1019967 ) // ACTOR2 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020042 || param2 == 1020042 ) // ACTOR3 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=YUGIRI
          }
        }
        if( param1 == 1019966 || param2 == 1019966 ) // ACTOR1 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
        }
        if( param1 == 1019967 || param2 == 1019967 ) // ACTOR2 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
        }
        if( param1 == 2008909 || param2 == 2008909 ) // EOBJECT1 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(SystemTalk), id=unknown
        }
        if( param1 == 2008910 || param2 == 2008910 ) // EOBJECT2 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(SystemTalk), id=unknown
        }
        break;
      }
      case 5:
      {
        if( param1 == 1020040 || param2 == 1020040 ) // ACTOR7 = SOLDIERC02495
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=SOLDIERC02495
            // +Callback Scene00032: Normal(Talk, NpcDespawn, TargetCanMove), id=SOLDIERC02495
          }
          else
          {
            Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=SOLDIERC02495
          }
        }
        if( param1 == 1020041 || param2 == 1020041 ) // ACTOR8 = SOLDIERD02496
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=SOLDIERD02496
            // +Callback Scene00036: Normal(Talk, NpcDespawn, TargetCanMove), id=SOLDIERD02496
          }
          else
          {
            Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=SOLDIERD02496
          }
        }
        if( param1 == 1019966 || param2 == 1019966 ) // ACTOR1 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
        }
        if( param1 == 1019967 || param2 == 1019967 ) // ACTOR2 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
        }
        if( param1 == 1020042 || param2 == 1020042 ) // ACTOR3 = YUGIRI
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 2008909 || param2 == 2008909 ) // EOBJECT1 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(SystemTalk, CanCancel), id=unknown
          // +Callback Scene00043: Normal(SystemTalk), id=unknown
        }
        if( param1 == 2008910 || param2 == 2008910 ) // EOBJECT2 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(SystemTalk, CanCancel), id=unknown
          // +Callback Scene00045: Normal(SystemTalk), id=unknown
        }
        break;
      }
      case 6:
      {
        if( param1 == 1020042 || param2 == 1020042 ) // ACTOR3 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=YUGIRI
          }
        }
        if( param1 == 1020047 || param2 == 1020047 ) // ACTOR9 = SOLDIERC02495
        {
          Scene00047( player ); // Scene00047: Normal(Talk), id=SOLDIERC02495
        }
        if( param1 == 1020048 || param2 == 1020048 ) // ACTOR10 = SOLDIERD02496
        {
          Scene00048( player ); // Scene00048: Normal(Talk), id=SOLDIERD02496
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020029 || param2 == 1020029 ) // ACTOR11 = unknown
        {
          Scene00050( player ); // Scene00050: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( param1 == 1020042 || param2 == 1020042 ) // ACTOR3 = YUGIRI
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020047 || param2 == 1020047 ) // ACTOR9 = SOLDIERC02495
        {
          Scene00052( player ); // Scene00052: Normal(Talk), id=SOLDIERC02495
        }
        if( param1 == 1020048 || param2 == 1020048 ) // ACTOR10 = SOLDIERD02496
        {
          Scene00053( player ); // Scene00053: Normal(Talk), id=SOLDIERD02496
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
    if( player.getQuestUI8BL( getId() ) == 1 
      || ( player.getQuestUI8AL( getId() ) == 1 )
        || ( player.getQuestUI8BH( getId() ) == 1 ))
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
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
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
      {
        player.setQuestUI8BH( getId(), 0 );
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
    player.sendDebug( "StmBda320:68032 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda320:68032 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00002: Normal(None), id=unknown" );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00005: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00011: Normal(Talk), id=BIGSOLDIER02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00012: Normal(Talk), id=SMALLSOLDIER02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00013: Normal(Talk), id=MIDDLESOLDIER02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00015: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00016( player );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00016: Normal(Talk, FadeIn, SystemTalk), id=BIGSOLDIER02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00018: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00019( player );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00019: Normal(Talk, FadeIn, SystemTalk), id=SMALLSOLDIER02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00021: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00022( player );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00022: Normal(Talk, FadeIn, SystemTalk), id=MIDDLESOLDIER02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00023: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00026: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00029: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00030: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00031: Normal(Talk, TargetCanMove), id=SOLDIERC02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00032( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00032: Normal(Talk, NpcDespawn, TargetCanMove), id=SOLDIERC02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 32, NONE, callback );
  }
  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00033: Normal(Talk, TargetCanMove), id=SOLDIERC02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00035: Normal(Talk, TargetCanMove), id=SOLDIERD02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00036( player );
    };
    player.playScene( getId(), 35, NONE, callback );
  }
  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00036: Normal(Talk, NpcDespawn, TargetCanMove), id=SOLDIERD02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 36, NONE, callback );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00037: Normal(Talk, TargetCanMove), id=SOLDIERD02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00041: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00042: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00043( player );
        player.sendUrgent( "equip not needed to progress." );
      }
    };
    player.playScene( getId(), 42, NONE, callback );
  }
  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00043: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00044: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00045( player );
        player.sendUrgent( "equip not needed to progress." );
      }
    };
    player.playScene( getId(), 44, NONE, callback );
  }
  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00045: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00046: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00047: Normal(Talk), id=SOLDIERC02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00048: Normal(Talk), id=SOLDIERD02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00050: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 50, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00051: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00052: Normal(Talk), id=SOLDIERC02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "StmBda320:68032 calling Scene00053: Normal(Talk), id=SOLDIERD02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 53, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda320 );
