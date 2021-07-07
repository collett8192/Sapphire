// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdb111 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdb111() : Sapphire::ScriptAPI::EventScript( 68508 ){}; 
  ~StmBdb111() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 3 entries
  //SEQ_4, 2 entries
  //SEQ_5, 2 entries
  //SEQ_6, 3 entries
  //SEQ_7, 6 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1024063
  //ACTOR1 = 1024064
  //ACTOR10 = 1024069
  //ACTOR11 = 1024070
  //ACTOR12 = 1024071
  //ACTOR13 = 1024072
  //ACTOR14 = 1024073
  //ACTOR15 = 1019468
  //ACTOR2 = 1024065
  //ACTOR3 = 1024150
  //ACTOR4 = 1024151
  //ACTOR5 = 1024152
  //ACTOR6 = 1024153
  //ACTOR7 = 1024066
  //ACTOR8 = 1024206
  //ACTOR9 = 1024068
  //EOBJECT0 = 2009048
  //EOBJECT1 = 2009072
  //EVENTACTION0 = 11
  //EVENTACTION1 = 1
  //LOCBGM01 = 459
  //LOCBINDALPH02 = 7074877
  //LOCBINDALPHEVENTZONE = 7081698
  //LOCBINDAREN01 = 7074873
  //LOCBINDAREN03 = 7074876
  //LOCBINDARENEVENTZONE = 7081696
  //LOCBINDRAUEVENTZONE = 7081693
  //LOCBINDTHAN01 = 7074897
  //LOCBINDYSHTEVENTZONE = 7081695
  //LOCENPCALISAIE01 = 1019541
  //LOCENPCALPH01 = 1011887
  //LOCENPCAREN01 = 1019537
  //LOCENPCMNAAGO01 = 1018318
  //LOCENPCTHAN01 = 1015842
  //LOCENPCYSHT01 = 1011889
  //NCUT01 = 1628
  //NCUT02 = 1630
  //NCUT03 = 1631
  //NCUT04 = 1632
  //NCUT05 = 1633
  //NCUT06 = 1634
  //NCUT07 = 1635
  //NCUT08 = 1636
  //POPRANGE0 = 7081686
  //POPRANGE1 = 7081797
  //POPRANGE2 = 7081687
  //POPRANGE3 = 7074883
  //QUESTBATTLE0 = 5024
  //TERRITORYTYPE0 = 403
  //TERRITORYTYPE1 = 737

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1024063 || param2 == 1024063 ) // ACTOR0 = RAUBAHN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, Menu), id=RAUBAHN
          break;
        }
        if( param1 == 1024064 || param2 == 1024064 ) // ACTOR1 = ARENVALD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 1:
      {
        Scene00004( player ); // Scene00004: Normal(Talk, FadeIn), id=unknown
        break;
      }
      case 2:
      {
        if( param1 == 1024065 || param2 == 1024065 ) // ACTOR2 = RESISTANCEGATEGUARD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD
            // +Callback Scene00006: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1024150 || param2 == 1024150 ) // ACTOR3 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024151 || param2 == 1024151 ) // ACTOR4 = ARENVALD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024152 || param2 == 1024152 ) // ACTOR5 = YSHTOLA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1024153 || param2 == 1024153 ) // ACTOR6 = THANCRED
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1024066 || param2 == 1024066 ) // ACTOR7 = ARENVALD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, SystemTalk), id=ARENVALD
          }
          break;
        }
        if( param1 == 2009072 || param2 == 2009072 ) // EOBJECT1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1024065 || param2 == 1024065 ) // ACTOR2 = RESISTANCEGATEGUARD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEGUARD
          break;
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00015( player ); // Scene00015: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1024065 || param2 == 1024065 ) // ACTOR2 = RESISTANCEGATEGUARD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEGUARD
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1024206 || param2 == 1024206 ) // ACTOR8 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, CutScene, FadeIn, TargetCanMove, AutoFadeIn), id=LYSE
          }
          break;
        }
        if( param1 == 1024065 || param2 == 1024065 ) // ACTOR2 = RESISTANCEGATEGUARD
        {
          Scene00018( player ); // Scene00018: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEGUARD
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1024068 || param2 == 1024068 ) // ACTOR9 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1024069 || param2 == 1024069 ) // ACTOR10 = ARENVALD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024070 || param2 == 1024070 ) // ACTOR11 = ALPHINAUD
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 1024068 || param2 == 1024068 ) // ACTOR9 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, NpcDespawn, TargetCanMove, SystemTalk), id=LYSE
          }
          break;
        }
        if( param1 == 1024069 || param2 == 1024069 ) // ACTOR10 = ARENVALD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024070 || param2 == 1024070 ) // ACTOR11 = ALPHINAUD
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024071 || param2 == 1024071 ) // ACTOR12 = NANAMOULNAMO
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=NANAMOULNAMO
          break;
        }
        if( param1 == 1024072 || param2 == 1024072 ) // ACTOR13 = RAUBAHN
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1024073 || param2 == 1024073 ) // ACTOR14 = PIPIN
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019468 || param2 == 1019468 ) // ACTOR15 = LYSE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, CutScene, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1024071 || param2 == 1024071 ) // ACTOR12 = NANAMOULNAMO
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=NANAMOULNAMO
          break;
        }
        if( param1 == 1024072 || param2 == 1024072 ) // ACTOR13 = RAUBAHN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1024073 || param2 == 1024073 ) // ACTOR14 = PIPIN
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=PIPIN
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
    player.updateQuest( getId(), 2 );
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
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdb111:68508 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, Menu), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00002: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00004: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00005: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00006( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00006: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 737 );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00008: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00010: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00011: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, SystemTalk), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00015( player );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00014: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 737 );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00015: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00016: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 737 );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00017: Normal(Talk, CutScene, FadeIn, TargetCanMove, AutoFadeIn), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.exitInstance();
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00018: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 737 );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00019: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00020: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00022: Normal(Talk, NpcDespawn, TargetCanMove, SystemTalk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00023: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00025: Normal(Talk, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00026: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00027: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00028: Normal(Talk, CutScene, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
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
    player.playScene( getId(), 28, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00029: Normal(Talk, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00030: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBdb111:68508 calling Scene00031: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdb111 );