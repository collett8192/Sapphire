// FFXIVTheMovie.ParserV3
// id hint used:
//ENEMY0 = dummy0
//ENEMY1 = dummy1
//ENEMY2 = dummy2
//ENEMY3 = dummy3
//ENEMY4 = dummy4
//ENEMY5 = dummy5
//EOBJECT0 = dummye0
//SCENE_3 = dummy0
//SCENE_4 = dummy1
//SCENE_5 = dummy2
//SCENE_6 = dummy3
//SCENE_7 = dummy4
//SCENE_8 = dummy5
//SCENE_9 = dummye0
//fix: skip dungeon, enter instance
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna707 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna707() : Sapphire::ScriptAPI::EventScript( 67205 ){}; 
  ~HeaVna707() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_4, 3 entries
  //SEQ_5, 1 entries
  //SEQ_6, 2 entries
  //SEQ_255, 12 entries

  //ACTOR0 = 1012848
  //ACTOR1 = 1012850
  //ACTOR10 = 1012180
  //ACTOR11 = 1012383
  //ACTOR12 = 1012384
  //ACTOR13 = 1012385
  //ACTOR14 = 1011935
  //ACTOR15 = 1012138
  //ACTOR2 = 5010000
  //ACTOR3 = 1013604
  //ACTOR4 = 1012857
  //ACTOR5 = 1012858
  //ACTOR6 = 1012337
  //ACTOR7 = 1013167
  //ACTOR8 = 1011192
  //ACTOR9 = 1012251
  //CUTSCENEN01 = 902
  //CUTSCENEN02 = 977
  //CUTSCENEN03 = 904
  //CUTSCENEN04 = 905
  //CUTSCENEN05 = 906
  //CUTSCENEN06 = 907
  //CUTSCENEN07 = 860
  //CUTSCENEN08 = 910
  //CUTSCENEN09 = 908
  //CUTSCENEN10 = 909
  //CUTSCENEN11 = 970
  //ENEMY0 = 5872412
  //ENEMY1 = 5872413
  //ENEMY2 = 5872415
  //ENEMY3 = 5872416
  //ENEMY4 = 5872417
  //ENEMY5 = 5872419
  //EOBJECT0 = 2006358
  //EOBJECT1 = 2006458
  //INSTANCEDUNGEON0 = 38
  //INSTANCEDUNGEON1 = 20035
  //LOCACTOR0 = 5912494
  //LOCIDLE0 = 794
  //LOCMOTION0 = 791
  //LOCMUSIC0 = 89
  //LOCMUSIC1 = 239
  //LOCSCREENIMAGE0 = 311
  //LOCSCREENIMAGEA = 316
  //POPRANGE0 = 5941504
  //POPRANGE1 = 5873484
  //TERRITORYTYPE0 = 507
  //TERRITORYTYPE1 = 433

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUIDANCESYSTEM
        break;
      }
      case 1:
      {
        if( actor == 1012850 || actorId == 1012850 ) // ACTOR1 = GUIDANCESYSTEM
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, Message, PopBNpc, TargetCanMove), id=GUIDANCESYSTEM
          }
        }
        if( actor == 5872412 || actorId == 5872412 ) // ENEMY0 = dummy0
        {
          Scene00003( player ); // Scene00003: Normal(Message, PopBNpc), id=dummy0
        }
        if( actor == 5872413 || actorId == 5872413 ) // ENEMY1 = dummy1
        {
          Scene00004( player ); // Scene00004: Normal(Message, PopBNpc), id=dummy1
        }
        if( actor == 5872415 || actorId == 5872415 ) // ENEMY2 = dummy2
        {
          Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=dummy2
        }
        if( actor == 5872416 || actorId == 5872416 ) // ENEMY3 = dummy3
        {
          Scene00006( player ); // Scene00006: Normal(Message, PopBNpc), id=dummy3
        }
        if( actor == 5872417 || actorId == 5872417 ) // ENEMY4 = dummy4
        {
          Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=dummy4
        }
        if( actor == 5872419 || actorId == 5872419 ) // ENEMY5 = dummy5
        {
          Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=dummy5
        }
        if( actor == 2006358 || actorId == 2006358 ) // EOBJECT0 = dummye0
        {
          Scene00009( player ); // Scene00009: Normal(None), id=dummye0
        }
        break;
      }
      case 2:
      {
        Scene00010( player ); // Scene00010: Normal(Talk, Message, FadeIn, TargetCanMove), id=GUIDANCESYSTEM
        break;
      }
      case 3:
      {
        if( actor == 1013604 || actorId == 1013604 ) // ACTOR3 = unknown
        {
          Scene00012( player );
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00012( player ); // Scene00012: Normal(CutScene), id=unknown
        }
        if( actor == 1013604 || actorId == 1013604 ) // ACTOR3 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(Message, FadeIn), id=unknown
        }
        if( actor == 2006458 || actorId == 2006458 ) // EOBJECT1 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        break;
      }
      case 5:
      {
        if( actor == 1013604 || actorId == 1013604 ) // ACTOR3 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(YesNo), id=unknown
        }
        break;
      }
      case 6:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( actor == 1013604 || actorId == 1013604 ) // ACTOR3 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(CutScene), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1012857 || actorId == 1012857 ) // ACTOR4 = ALPHINAUD
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          // +Callback Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012858 || actorId == 1012858 ) // ACTOR5 = TATARUL
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=TATARUL
        }
        if( actor == 1012337 || actorId == 1012337 ) // ACTOR6 = BUTLER01580
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=BUTLER01580
        }
        if( actor == 1013167 || actorId == 1013167 ) // ACTOR7 = LUCIA
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1011192 || actorId == 1011192 ) // ACTOR8 = GIBRILLONT
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=GIBRILLONT
        }
        if( actor == 1012251 || actorId == 1012251 ) // ACTOR9 = HILDA
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( actor == 1012180 || actorId == 1012180 ) // ACTOR10 = ELAISSE
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ELAISSE
        }
        if( actor == 1012383 || actorId == 1012383 ) // ACTOR11 = ARTOIREL
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ARTOIREL
        }
        if( actor == 1012384 || actorId == 1012384 ) // ACTOR12 = EMMANELLAIN
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( actor == 1012385 || actorId == 1012385 ) // ACTOR13 = HONOROIT
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( actor == 1011935 || actorId == 1011935 ) // ACTOR14 = VIDOFNIR
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=VIDOFNIR
        }
        if( actor == 1012138 || actorId == 1012138 ) // ACTOR15 = MATOYA
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=MATOYA
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
    onProgress( player, param1, param1, 3, param1 );
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
    if( player.getQuestUI8AL( getId() ) == 6 )
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
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 6 );
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna707:67205 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00002: Normal(Talk, Message, PopBNpc, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 6 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00003: Normal(Message, PopBNpc), id=dummy0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00004: Normal(Message, PopBNpc), id=dummy1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00005: Normal(Message, PopBNpc), id=dummy2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00006: Normal(Message, PopBNpc), id=dummy3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00007: Normal(Message, PopBNpc), id=dummy4" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00008: Normal(Message, PopBNpc), id=dummy5" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00009: Normal(None), id=dummye0" );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00010: Normal(Talk, Message, FadeIn, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00012: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      //checkProgressSeq4( player );
      Scene00017( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00013: Normal(Message, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00015: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00017: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 433 );
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00018: Normal(None), id=unknown" );
    Scene00019( player );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling [BranchTrue]Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00020: Normal(Talk, TargetCanMove), id=TATARUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00021: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00022: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00023: Normal(Talk, TargetCanMove), id=GIBRILLONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00024: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00025: Normal(Talk, TargetCanMove), id=ELAISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00026: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00027: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00028: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00029: Normal(Talk, TargetCanMove), id=VIDOFNIR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVna707:67205 calling Scene00030: Normal(Talk, TargetCanMove), id=MATOYA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna707 );
