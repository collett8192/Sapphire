// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma308 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma308() : Sapphire::ScriptAPI::EventScript( 68834 ){}; 
  ~LucKma308() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 6 entries
  //SEQ_2, 5 entries
  //SEQ_3, 5 entries
  //SEQ_4, 4 entries
  //SEQ_5, 6 entries
  //SEQ_6, 7 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1029001
  //ACTOR1 = 1029176
  //ACTOR10 = 1027906
  //ACTOR11 = 1027911
  //ACTOR2 = 1029008
  //ACTOR3 = 1029009
  //ACTOR4 = 1030605
  //ACTOR5 = 1027909
  //ACTOR6 = 1027910
  //ACTOR7 = 1027939
  //ACTOR8 = 1029010
  //ACTOR9 = 1029012
  //ENEMY0 = 7926435
  //EOBJECT0 = 2009858
  //EOBJECT1 = 2009859
  //EOBJECT2 = 2009860
  //EVENTACTION0 = 50
  //EVENTACTION1 = 1
  //EVENTRANGE0 = 8053308
  //LOCBINDACTOR0 = 7926104
  //LOCBINDACTOR1 = 7929636
  //NCUTEVENTLUCKMA30801 = 1973
  //NCUTEVENTLUCKMA30802 = 1974
  //POPRANGE0 = 7926841
  //POPRANGE1 = 7926843

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029001 || param2 == 1029001 ) // ACTOR0 = TESLEEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TESLEEN
          // +Callback Scene00002: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1029176 || param2 == 1029176 ) // ACTOR1 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029008 || param2 == 1029008 ) // ACTOR2 = TESLEEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=TESLEEN
          }
          break;
        }
        if( param1 == 1029009 || param2 == 1029009 ) // ACTOR3 = ALISAIE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030605 || param2 == 1030605 ) // ACTOR4 = JOURNEYSHEADNURSE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=JOURNEYSHEADNURSE
          break;
        }
        if( param1 == 1027909 || param2 == 1027909 ) // ACTOR5 = PAWNIL
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=PAWNIL
          break;
        }
        if( param1 == 1027910 || param2 == 1027910 ) // ACTOR6 = TODDEN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=TODDEN
          break;
        }
        if( param1 == 1027939 || param2 == 1027939 ) // ACTOR7 = VOYNE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=VOYNE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2009858 || param2 == 2009858 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1030605 || param2 == 1030605 ) // ACTOR4 = JOURNEYSHEADNURSE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=JOURNEYSHEADNURSE
          break;
        }
        if( param1 == 1027909 || param2 == 1027909 ) // ACTOR5 = PAWNIL
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=PAWNIL
          break;
        }
        if( param1 == 1027910 || param2 == 1027910 ) // ACTOR6 = TODDEN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=TODDEN
          break;
        }
        if( param1 == 1027939 || param2 == 1027939 ) // ACTOR7 = VOYNE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=VOYNE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2009859 || param2 == 2009859 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 7926435 || param2 == 7926435 ) // ENEMY0 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1027909 || param2 == 1027909 ) // ACTOR5 = PAWNIL
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=PAWNIL
          break;
        }
        if( param1 == 1027910 || param2 == 1027910 ) // ACTOR6 = TODDEN
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=TODDEN
          break;
        }
        if( param1 == 1027939 || param2 == 1027939 ) // ACTOR7 = VOYNE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=VOYNE
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2009860 || param2 == 2009860 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1027909 || param2 == 1027909 ) // ACTOR5 = PAWNIL
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=PAWNIL
          break;
        }
        if( param1 == 1027910 || param2 == 1027910 ) // ACTOR6 = TODDEN
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=TODDEN
          break;
        }
        if( param1 == 1027939 || param2 == 1027939 ) // ACTOR7 = VOYNE
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=VOYNE
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1029010 || param2 == 1029010 ) // ACTOR8 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1029012 || param2 == 1029012 ) // ACTOR9 = HALRIC
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=HALRIC
          break;
        }
        if( param1 == 1027909 || param2 == 1027909 ) // ACTOR5 = PAWNIL
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=PAWNIL
          break;
        }
        if( param1 == 1027910 || param2 == 1027910 ) // ACTOR6 = TODDEN
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=TODDEN
          break;
        }
        if( param1 == 1027939 || param2 == 1027939 ) // ACTOR7 = VOYNE
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=VOYNE
          break;
        }
        if( param1 == 8053308 || param2 == 8053308 ) // EVENTRANGE0 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1027906 || param2 == 1027906 ) // ACTOR10 = CASSANA
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=CASSANA
            // +Callback Scene00036: Normal(Talk, TargetCanMove), id=CASSANA
          }
          break;
        }
        if( param1 == 1027911 || param2 == 1027911 ) // ACTOR11 = WILLFORT
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=WILLFORT
            // +Callback Scene00038: Normal(Talk, TargetCanMove), id=WILLFORT
          }
          break;
        }
        if( param1 == 1029010 || param2 == 1029010 ) // ACTOR8 = ALISAIE
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1029012 || param2 == 1029012 ) // ACTOR9 = HALRIC
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=HALRIC
          break;
        }
        if( param1 == 1027909 || param2 == 1027909 ) // ACTOR5 = PAWNIL
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=PAWNIL
          break;
        }
        if( param1 == 1027910 || param2 == 1027910 ) // ACTOR6 = TODDEN
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=TODDEN
          break;
        }
        if( param1 == 1027939 || param2 == 1027939 ) // ACTOR7 = VOYNE
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=VOYNE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029012 || param2 == 1029012 ) // ACTOR9 = HALRIC
        {
          Scene00044( player ); // Scene00044: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=HALRIC
          break;
        }
        if( param1 == 1029010 || param2 == 1029010 ) // ACTOR8 = ALISAIE
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1027909 || param2 == 1027909 ) // ACTOR5 = PAWNIL
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=PAWNIL
          break;
        }
        if( param1 == 1027910 || param2 == 1027910 ) // ACTOR6 = TODDEN
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=TODDEN
          break;
        }
        if( param1 == 1027939 || param2 == 1027939 ) // ACTOR7 = VOYNE
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=VOYNE
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
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKma308:68834 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00002: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00006: Normal(Talk, TargetCanMove), id=JOURNEYSHEADNURSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00007: Normal(Talk, TargetCanMove), id=PAWNIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00008: Normal(Talk, TargetCanMove), id=TODDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00009: Normal(Talk, TargetCanMove), id=VOYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00011: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00012: Normal(Talk, TargetCanMove), id=JOURNEYSHEADNURSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00013: Normal(Talk, TargetCanMove), id=PAWNIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00014: Normal(Talk, TargetCanMove), id=TODDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00015: Normal(Talk, TargetCanMove), id=VOYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00017: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00019: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00020: Normal(Talk, TargetCanMove), id=PAWNIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00021: Normal(Talk, TargetCanMove), id=TODDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00022: Normal(Talk, TargetCanMove), id=VOYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00024: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00025: Normal(Talk, TargetCanMove), id=PAWNIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00026: Normal(Talk, TargetCanMove), id=TODDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00027: Normal(Talk, TargetCanMove), id=VOYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00029: Normal(Talk, TargetCanMove), id=HALRIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00030: Normal(Talk, TargetCanMove), id=PAWNIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00031: Normal(Talk, TargetCanMove), id=TODDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00032: Normal(Talk, TargetCanMove), id=VOYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00034: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00035: Normal(Talk, TargetCanMove), id=CASSANA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00036( player );
    };
    player.playScene( getId(), 35, NONE, callback );
  }
  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00036: Normal(Talk, TargetCanMove), id=CASSANA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00037: Normal(Talk, TargetCanMove), id=WILLFORT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00038( player );
    };
    player.playScene( getId(), 37, NONE, callback );
  }
  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00038: Normal(Talk, TargetCanMove), id=WILLFORT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00039: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00040: Normal(Talk, TargetCanMove), id=HALRIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00041: Normal(Talk, TargetCanMove), id=PAWNIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00042: Normal(Talk, TargetCanMove), id=TODDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00043: Normal(Talk, TargetCanMove), id=VOYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00044: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=HALRIC" );
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
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00045: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00046: Normal(Talk, TargetCanMove), id=PAWNIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00047: Normal(Talk, TargetCanMove), id=TODDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "LucKma308:68834 calling Scene00048: Normal(Talk, TargetCanMove), id=VOYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKma308 );
