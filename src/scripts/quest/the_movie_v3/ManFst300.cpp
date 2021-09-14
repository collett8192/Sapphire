// FFXIVTheMovie.ParserV3.2
// id hint used:
//EOBJECT0 = dummy1
//EOBJECT1 = dummy2
//ACTOR5 = ZANTHAEL
//SCENE_7 = dummy1
//SCENE_9 = dummy2
//SCENE_11 = ZANTHAEL
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManFst300 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManFst300() : Sapphire::ScriptAPI::EventScript( 66047 ){}; 
  ~ManFst300() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 24 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1005116
  //ACTOR1 = 1003785
  //ACTOR10 = 1004875
  //ACTOR11 = 1004876
  //ACTOR12 = 1006179
  //ACTOR13 = 1004880
  //ACTOR14 = 1004881
  //ACTOR15 = 1004882
  //ACTOR16 = 1006173
  //ACTOR17 = 1006174
  //ACTOR18 = 1006175
  //ACTOR19 = 1006181
  //ACTOR2 = 1004883
  //ACTOR20 = 1006183
  //ACTOR21 = 1006184
  //ACTOR22 = 1006177
  //ACTOR23 = 1006178
  //ACTOR24 = 1005122
  //ACTOR3 = 1004884
  //ACTOR4 = 1004885
  //ACTOR5 = 1001029
  //ACTOR6 = 1004870
  //ACTOR7 = 1004871
  //ACTOR8 = 1004872
  //ACTOR9 = 1004874
  //EOBJECT0 = 2001690
  //EOBJECT1 = 2001691
  //EVENTACTIONWAITING = 10
  //LOCACTION1 = 1002
  //LOCACTOR0 = 1003783
  //LOCSE1 = 42
  //LOCTALKSHAPE1 = 6
  //NCUT0 = 89
  //NCUT1 = 90
  //NCUT2 = 151
  //NCUT3 = 91
  //NCUT4 = 152
  //NCUT5 = 92
  //NCUT6 = 153
  //NCUT7 = 93

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(CutScene, QuestAccept, AutoFadeIn), id=unknown
        break;
      }
      case 1:
      {
        if( param1 == 1003785 || param2 == 1003785 ) // ACTOR1 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=TATARU
          }
          break;
        }
        if( param1 == 1004883 || param2 == 1004883 ) // ACTOR2 = FLAMEOFFICER
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=FLAMEOFFICER
          break;
        }
        if( param1 == 1004884 || param2 == 1004884 ) // ACTOR3 = SERPENTOFFICER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1004885 || param2 == 1004885 ) // ACTOR4 = STORMOFFICER
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2001690 || param2 == 2001690 ) // EOBJECT0 = dummy1
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, CutScene, FadeIn), id=dummy1
          }
          break;
        }
        if( param1 == 2001691 || param2 == 2001691 ) // EOBJECT1 = dummy2
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, CutScene, FadeIn), id=dummy2
          }
          break;
        }
        if( param1 == 1001029 || param2 == 1001029 ) // ACTOR5 = ZANTHAEL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=ZANTHAEL
            // +Callback Scene00011: Normal(Talk, CutScene, FadeIn), id=ZANTHAEL
          }
          break;
        }
        if( param1 == 1004870 || param2 == 1004870 ) // ACTOR6 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004871 || param2 == 1004871 ) // ACTOR7 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004872 || param2 == 1004872 ) // ACTOR8 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004874 || param2 == 1004874 ) // ACTOR9 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004875 || param2 == 1004875 ) // ACTOR10 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004876 || param2 == 1004876 ) // ACTOR11 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006179 || param2 == 1006179 ) // ACTOR12 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004880 || param2 == 1004880 ) // ACTOR13 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004881 || param2 == 1004881 ) // ACTOR14 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004882 || param2 == 1004882 ) // ACTOR15 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006173 || param2 == 1006173 ) // ACTOR16 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006174 || param2 == 1006174 ) // ACTOR17 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006175 || param2 == 1006175 ) // ACTOR18 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006181 || param2 == 1006181 ) // ACTOR19 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006183 || param2 == 1006183 ) // ACTOR20 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006184 || param2 == 1006184 ) // ACTOR21 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006177 || param2 == 1006177 ) // ACTOR22 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006178 || param2 == 1006178 ) // ACTOR23 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 1004883 || param2 == 1004883 ) // ACTOR2 = FLAMEOFFICER
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=FLAMEOFFICER
          break;
        }
        if( param1 == 1004884 || param2 == 1004884 ) // ACTOR3 = SERPENTOFFICER
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1004885 || param2 == 1004885 ) // ACTOR4 = STORMOFFICER
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1005122 || param2 == 1005122 ) // ACTOR24 = MINFILIA
        {
          Scene00033( player ); // Scene00033: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA
          // +Callback Scene00034: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1004883 || param2 == 1004883 ) // ACTOR2 = FLAMEOFFICER
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=FLAMEOFFICER
          break;
        }
        if( param1 == 1004884 || param2 == 1004884 ) // ACTOR3 = SERPENTOFFICER
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1004885 || param2 == 1004885 ) // ACTOR4 = STORMOFFICER
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=STORMOFFICER
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
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8BL( getId() ) == 1 )
        if( player.getQuestUI8AL( getId() ) == 1 )
        {
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "ManFst300:66047 calling Scene00001: Normal(CutScene, QuestAccept, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00002: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00003: Normal(Talk, TargetCanMove), id=FLAMEOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00005: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00007: Normal(Talk, CutScene, FadeIn), id=dummy1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00009: Normal(Talk, CutScene, FadeIn), id=dummy2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00010: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=ZANTHAEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00011: Normal(Talk, CutScene, FadeIn), id=ZANTHAEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00030: Normal(Talk, TargetCanMove), id=FLAMEOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00031: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00032: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00033: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00034( player );
      }
    };
    player.playScene( getId(), 33, NONE, callback );
  }
  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00034: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 34, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00035: Normal(Talk, TargetCanMove), id=FLAMEOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00036: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "ManFst300:66047 calling Scene00037: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }
};

EXPOSE_SCRIPT( ManFst300 );
