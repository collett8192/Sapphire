// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdf104 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdf104() : Sapphire::ScriptAPI::EventScript( 68718 ){}; 
  ~StmBdf104() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 5 entries
  //SEQ_2, 2 entries
  //SEQ_3, 5 entries
  //SEQ_4, 10 entries
  //SEQ_5, 10 entries
  //SEQ_6, 10 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1025597
  //ACTOR1 = 1026259
  //ACTOR10 = 1026808
  //ACTOR11 = 1026806
  //ACTOR12 = 1026807
  //ACTOR13 = 1026815
  //ACTOR14 = 1026818
  //ACTOR15 = 1026820
  //ACTOR16 = 1026819
  //ACTOR17 = 1026821
  //ACTOR18 = 1026822
  //ACTOR19 = 1026816
  //ACTOR2 = 1025545
  //ACTOR20 = 1026817
  //ACTOR21 = 1026984
  //ACTOR22 = 1026823
  //ACTOR3 = 1025000
  //ACTOR4 = 1025001
  //ACTOR5 = 1025354
  //ACTOR6 = 1026804
  //ACTOR7 = 1027000
  //ACTOR8 = 1027001
  //ACTOR9 = 1026805
  //LOCBGM01 = 77
  //LOCBINDALS01 = 7592104
  //LOCBINDAYM01 = 7738667
  //LOCBINDHAK01 = 7227012
  //LOCBINDKNS01 = 7738669
  //LOCBINDLIS01 = 7738672
  //LOCBINDNON01 = 7227013
  //LOCBINDRAU01 = 7738671
  //LOCBINDYUG01 = 7343652
  //LOCNCUT01 = 1883
  //LOCNCUT02 = 1884
  //LOCNCUT03 = 1913
  //POPRANGE0 = 7226900
  //POPRANGE1 = 7738494
  //POPRANGE2 = 7738452
  //POPRANGE3 = 7738679
  //POPRANGE4 = 7738681
  //POPRANGE5 = 7739058
  //TERRITORYTYPE0 = 744
  //TERRITORYTYPE1 = 829

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1025597 || param2 == 1025597 ) // ACTOR0 = HIEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1026259 || param2 == 1026259 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025545 || param2 == 1025545 ) // ACTOR2 = YUGIRI
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1025000 || param2 == 1025000 ) // ACTOR3 = HAKUROU
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=HAKUROU
          break;
        }
        if( param1 == 1025001 || param2 == 1025001 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025354 || param2 == 1025354 ) // ACTOR5 = KIENKANGATEKEEPER03028
        {
          Scene00006( player ); // Scene00006: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1026804 || param2 == 1026804 ) // ACTOR6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=unknown
          }
          break;
        }
        if( param1 == 1025000 || param2 == 1025000 ) // ACTOR3 = HAKUROU
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=HAKUROU
          break;
        }
        if( param1 == 1025001 || param2 == 1025001 ) // ACTOR4 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1027000 || param2 == 1027000 ) // ACTOR7 = HIEN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1027001 || param2 == 1027001 ) // ACTOR8 = ALISAIE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00012( player ); // Scene00012: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1026804 || param2 == 1026804 ) // ACTOR6 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(Talk, YesNo, TargetCanMove), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1026805 || param2 == 1026805 ) // ACTOR9 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LYSE
            //+ 15
          }
          break;
        }
        if( param1 == 1026804 || param2 == 1026804 ) // ACTOR6 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(Talk, YesNo, TargetCanMove), id=unknown
          break;
        }
        if( param1 == 1026808 || param2 == 1026808 ) // ACTOR10 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1026806 || param2 == 1026806 ) // ACTOR11 = HIEN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1026807 || param2 == 1026807 ) // ACTOR12 = RAUBAHN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1026815 || param2 == 1026815 ) // ACTOR13 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1026804 || param2 == 1026804 ) // ACTOR6 = RESISTANCEGATEKEEPER03182
        {
          Scene00021( player ); // Scene00021: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER03182
          break;
        }
        if( param1 == 1026818 || param2 == 1026818 ) // ACTOR14 = NANAMOULNAMO
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=NANAMOULNAMO
          break;
        }
        if( param1 == 1026820 || param2 == 1026820 ) // ACTOR15 = LYSE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1026819 || param2 == 1026819 ) // ACTOR16 = RAUBAHN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1026821 || param2 == 1026821 ) // ACTOR17 = HIEN
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1026822 || param2 == 1026822 ) // ACTOR18 = AYMERIC
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1026816 || param2 == 1026816 ) // ACTOR19 = KANESENNA
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=KANESENNA
          break;
        }
        if( param1 == 1026817 || param2 == 1026817 ) // ACTOR20 = MERLWYB
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=MERLWYB
          break;
        }
        if( param1 == 1026984 || param2 == 1026984 ) // ACTOR21 = RESISTANCEGATEKEEPER
        {
          Scene00029( player ); // Scene00029: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1026818 || param2 == 1026818 ) // ACTOR14 = NANAMOULNAMO
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove, Menu), id=NANAMOULNAMO
            // +Callback Scene00031: Normal(Talk, TargetCanMove), id=NANAMOULNAMO
          }
          break;
        }
        if( param1 == 1026821 || param2 == 1026821 ) // ACTOR17 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove, Menu), id=HIEN
            // +Callback Scene00033: Normal(Talk, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1026817 || param2 == 1026817 ) // ACTOR20 = MERLWYB
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=MERLWYB
            // +Callback Scene00035: Normal(Talk, TargetCanMove), id=MERLWYB
          }
          break;
        }
        if( param1 == 1026804 || param2 == 1026804 ) // ACTOR6 = RESISTANCEGATEKEEPER03182
        {
          Scene00036( player ); // Scene00036: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER03182
          break;
        }
        if( param1 == 1026815 || param2 == 1026815 ) // ACTOR13 = ALISAIE
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1026820 || param2 == 1026820 ) // ACTOR15 = LYSE
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1026819 || param2 == 1026819 ) // ACTOR16 = RAUBAHN
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1026822 || param2 == 1026822 ) // ACTOR18 = AYMERIC
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1026816 || param2 == 1026816 ) // ACTOR19 = KANESENNA
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=KANESENNA
          break;
        }
        if( param1 == 1026984 || param2 == 1026984 ) // ACTOR21 = RESISTANCEGATEKEEPER
        {
          Scene00042( player ); // Scene00042: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1026815 || param2 == 1026815 ) // ACTOR13 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=ALISAIE
            // +Callback Scene00044: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1026804 || param2 == 1026804 ) // ACTOR6 = RESISTANCEGATEKEEPER03182
        {
          Scene00045( player ); // Scene00045: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER03182
          break;
        }
        if( param1 == 1026818 || param2 == 1026818 ) // ACTOR14 = NANAMOULNAMO
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=NANAMOULNAMO
          break;
        }
        if( param1 == 1026820 || param2 == 1026820 ) // ACTOR15 = LYSE
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1026819 || param2 == 1026819 ) // ACTOR16 = RAUBAHN
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1026821 || param2 == 1026821 ) // ACTOR17 = HIEN
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1026822 || param2 == 1026822 ) // ACTOR18 = AYMERIC
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1026816 || param2 == 1026816 ) // ACTOR19 = KANESENNA
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=KANESENNA
          break;
        }
        if( param1 == 1026817 || param2 == 1026817 ) // ACTOR20 = MERLWYB
        {
          Scene00052( player ); // Scene00052: Normal(Talk, TargetCanMove), id=MERLWYB
          break;
        }
        if( param1 == 1026984 || param2 == 1026984 ) // ACTOR21 = RESISTANCEGATEKEEPER
        {
          Scene00053( player ); // Scene00053: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1026823 || param2 == 1026823 ) // ACTOR22 = LYSE
        {
          Scene00054( player ); // Scene00054: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1026804 || param2 == 1026804 ) // ACTOR6 = unknown
        {
          Scene00055( player ); // Scene00055: Normal(Talk, YesNo, TargetCanMove), id=unknown
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
    player.sendDebug( "StmBdf104:68718 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdf104:68718 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00003: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00004: Normal(Talk, TargetCanMove), id=HAKUROU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00006: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 744 );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00007: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 829 );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00008: Normal(Talk, TargetCanMove), id=HAKUROU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00010: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00012: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00013: Normal(Talk, YesNo, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 829 );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00014: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00015( player );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00015: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.setPosAndSendActorMove( 0, 0, 5, -3.14 );
      player.forceZoneing();
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00016: Normal(Talk, YesNo, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 829 );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00017: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00018: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00021: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER03182" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 829 );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00022: Normal(Talk, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00023: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00024: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00025: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00026: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00027: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00028: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00029: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.setPosAndSendActorMove( 0, 0, 5, -3.14 );
      }
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00030: Normal(Talk, TargetCanMove, Menu), id=NANAMOULNAMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00031( player );
      }
    };
    player.playScene( getId(), 30, NONE, callback );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00031: Normal(Talk, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00032: Normal(Talk, TargetCanMove, Menu), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00033( player );
      }
    };
    player.playScene( getId(), 32, NONE, callback );
  }
  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00033: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00034: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00035( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00035: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00036: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER03182" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 829 );
      }
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00037: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00038: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00039: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00040: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00041: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00042: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.setPosAndSendActorMove( 0, 0, 5, -3.14 );
      }
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00043: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00044( player );
    };
    player.playScene( getId(), 43, NONE, callback );
  }
  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00044: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.setPosAndSendActorMove( -466, 107.7, 107.7, -2 );
      player.forceZoneing();
    };
    player.playScene( getId(), 44, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00045: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER03182" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 829 );
      }
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00046: Normal(Talk, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00047: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00048: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00049: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00050: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00051: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00052: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00053: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.setPosAndSendActorMove( 0, 0, 5, -3.14 );
      }
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00054: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
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
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "StmBdf104:68718 calling Scene00055: Normal(Talk, YesNo, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 829 );
      }
    };
    player.playScene( getId(), 55, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdf104 );
