// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmd114 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmd114() : Sapphire::ScriptAPI::EventScript( 69155 ){}; 
  ~LucKmd114() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 8 entries
  //SEQ_2, 9 entries
  //SEQ_3, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1029765
  //ACTOR1 = 1031252
  //ACTOR10 = 1029771
  //ACTOR11 = 1029772
  //ACTOR12 = 1029773
  //ACTOR13 = 1029774
  //ACTOR14 = 1029775
  //ACTOR2 = 1029766
  //ACTOR3 = 1029767
  //ACTOR4 = 1031250
  //ACTOR5 = 1031251
  //ACTOR6 = 1029638
  //ACTOR7 = 1029768
  //ACTOR8 = 1029769
  //ACTOR9 = 1029770
  //EOBJECT0 = 2009920
  //EOBJECT1 = 2009919
  //EVENTWARPLEVELERROR = 3744
  //LOCACTIONBOXCOUNT2 = 5607
  //LOCACTIONRACKCHECK = 811
  //LOCACTORJERICK = 1028871
  //LOCACTORMAGNUS = 1028147
  //LOCACTORMINFILIA = 1026572
  //LOCACTORTALOS = 1028872
  //LOCACTORTHAFFE = 1028146
  //LOCACTORTHANCRED = 1026569
  //LOCACTORURIANGER = 1026570
  //LOCBGM0 = 647
  //LOCBINDACTOR0 = 7935146
  //LOCBINDACTOR1 = 7935147
  //LOCBINDACTOR10 = 7935167
  //LOCBINDACTOR2 = 8034893
  //LOCBINDACTOR3 = 7935149
  //LOCBINDACTOR4 = 7935160
  //LOCBINDACTOR5 = 7935162
  //LOCBINDACTOR6 = 7935163
  //LOCBINDACTOR7 = 7935164
  //LOCBINDACTOR8 = 7935165
  //LOCBINDACTOR9 = 7935166
  //NCUTEVENTLUCKMD11401 = 2029
  //NCUTEVENTLUCKMD11402 = 2030
  //POPRANGE0 = 7935193
  //QUESTBATTLE0 = 5031
  //TERRITORYTYPE0 = 860
  //TERRITORYTYPE1 = 815

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029765 || param2 == 1029765 ) // ACTOR0 = MAGNUS
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1031252 || param2 == 1031252 ) // ACTOR1 = JERYK
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1029766 || param2 == 1029766 ) // ACTOR2 = THAFFE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1029767 || param2 == 1029767 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1031250 || param2 == 1031250 ) // ACTOR4 = THANCRED
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1031251 || param2 == 1031251 ) // ACTOR5 = RYNE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029638 || param2 == 1029638 ) // ACTOR6 = URIANGER
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029768 || param2 == 1029768 ) // ACTOR7 = RYNE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=RYNE
          }
          break;
        }
        if( param1 == 1029769 || param2 == 1029769 ) // ACTOR8 = THANCRED
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029770 || param2 == 1029770 ) // ACTOR9 = URIANGER
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029771 || param2 == 1029771 ) // ACTOR10 = MAGNUS
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029772 || param2 == 1029772 ) // ACTOR11 = THAFFE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1029773 || param2 == 1029773 ) // ACTOR12 = JERYK
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1029774 || param2 == 1029774 ) // ACTOR13 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 2009920 || param2 == 2009920 ) // EOBJECT0 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1029771 || param2 == 1029771 ) // ACTOR10 = MAGNUS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, QuestBattle, YesNo, Message, TargetCanMove, CanCancel), id=MAGNUS
            // +Callback Scene00017: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1029768 || param2 == 1029768 ) // ACTOR7 = RYNE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029769 || param2 == 1029769 ) // ACTOR8 = THANCRED
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029770 || param2 == 1029770 ) // ACTOR9 = URIANGER
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029772 || param2 == 1029772 ) // ACTOR11 = THAFFE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1029773 || param2 == 1029773 ) // ACTOR12 = JERYK
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1029774 || param2 == 1029774 ) // ACTOR13 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 2009919 || param2 == 2009919 ) // EOBJECT1 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 2009920 || param2 == 2009920 ) // EOBJECT0 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00026( player ); // Scene00026: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029775 || param2 == 1029775 ) // ACTOR14 = RYNE
        {
          Scene00027( player ); // Scene00027: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=RYNE
          break;
        }
        if( param1 == 1029771 || param2 == 1029771 ) // ACTOR10 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(YesNo), id=unknown
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmd114:69155 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00002: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00003: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00005: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00006: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00007: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00008: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00009: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00010: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00011: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00012: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00013: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00016: Normal(Talk, QuestBattle, YesNo, Message, TargetCanMove, CanCancel), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00017( player );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00017: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      //checkProgressSeq2( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      //player.eventFinish( getId(), 1 );
      //player.forceZoneing();
      Scene00026( player );
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00018: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00019: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00020: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00021: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00022: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00024: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00025: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00026: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 815, 17.313, -91.09, 509.306, 1.58, false );
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00027: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=RYNE" );
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
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmd114:69155 calling Scene00028: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 815, 17.313, -91.09, 509.306, 1.58, false );
      }
    };
    player.playScene( getId(), 28, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmd114 );
