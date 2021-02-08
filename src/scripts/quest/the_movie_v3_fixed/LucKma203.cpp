// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_15 = dummye0
//ACTOR4 = ALPHINAUD
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma203 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma203() : Sapphire::ScriptAPI::EventScript( 68820 ){}; 
  ~LucKma203() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 4 entries
  //SEQ_3, 5 entries
  //SEQ_4, 1 entries
  //SEQ_5, 2 entries
  //SEQ_6, 3 entries
  //SEQ_7, 4 entries
  //SEQ_255, 3 entries

  //ACTION01 = 1007
  //ACTOR0 = 1029809
  //ACTOR1 = 1029810
  //ACTOR2 = 1029811
  //ACTOR3 = 1029812
  //ACTOR4 = 1029813
  //ACTOR5 = 1029814
  //ACTOR6 = 1029815
  //ACTOR7 = 1029816
  //BINDACTOR01 = 7929523
  //CUTSCENE0 = 1964
  //ENEMY0 = 7929737
  //EOBJECT0 = 2009960
  //EOBJECT1 = 2009961
  //EOBJECT2 = 2009962
  //EVENTACTION0 = 34
  //EVENTACTION1 = 50
  //EVENTRANGE0 = 7929528
  //EVENTRANGE1 = 8036760
  //LOCACTOR01 = 1028361
  //POPRANGE0 = 8042841
  //POPRANGE1 = 7929742
  //QUESTLUCKMA305 = 68831

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 2:
      {
        if( param1 == 7929528 || param2 == 7929528 ) // EVENTRANGE0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 2009960 || param2 == 2009960 ) // EOBJECT0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029811 || param2 == 1029811 ) // ACTOR2 = FEARLADY03284
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=FEARLADY03284
          break;
        }
        if( param1 == 1029812 || param2 == 1029812 ) // ACTOR3 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(Message), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 8036760 || param2 == 8036760 ) // EVENTRANGE1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 7929737 || param2 == 7929737 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            player.setQuestUI8AL( getId(), 1 );
            checkProgressSeq3( player );
          }
          break;
        }
        if( param1 == 2009960 || param2 == 2009960 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(Message), id=unknown
          break;
        }
        if( param1 == 1029811 || param2 == 1029811 ) // ACTOR2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029812 || param2 == 1029812 ) // ACTOR3 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        Scene00013( player ); // Scene00013: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=FEARLADY03284
        break;
      }
      case 5:
      {
        if( param1 == 2009961 || param2 == 2009961 ) // EOBJECT1 = dummye0
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(CutScene, AutoFadeIn), id=dummye0
          }
          break;
        }
        if( param1 == 1029813 || param2 == 1029813 ) // ACTOR4 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1029814 || param2 == 1029814 ) // ACTOR5 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1029815 || param2 == 1029815 ) // ACTOR6 = GATETOWNMIDDLEAGE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=GATETOWNMIDDLEAGE
          break;
        }
        if( param1 == 1029816 || param2 == 1029816 ) // ACTOR7 = DREAMINGLADY03284
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=DREAMINGLADY03284
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 2009962 || param2 == 2009962 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1029815 || param2 == 1029815 ) // ACTOR6 = GATETOWNMIDDLEAGE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=GATETOWNMIDDLEAGE
            // +Callback Scene00022: Normal(Talk, TargetCanMove), id=GATETOWNMIDDLEAGE
          }
          break;
        }
        if( param1 == 1029816 || param2 == 1029816 ) // ACTOR7 = DREAMINGLADY03284
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=DREAMINGLADY03284
            // +Callback Scene00024: Normal(Talk, TargetCanMove), id=DREAMINGLADY03284
          }
          break;
        }
        if( param1 == 1029814 || param2 == 1029814 ) // ACTOR5 = ALPHINAUD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029814 || param2 == 1029814 ) // ACTOR5 = ALPHINAUD
        {
          Scene00026( player ); // Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029815 || param2 == 1029815 ) // ACTOR6 = GATETOWNMIDDLEAGE
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=GATETOWNMIDDLEAGE
          break;
        }
        if( param1 == 1029816 || param2 == 1029816 ) // ACTOR7 = DREAMINGLADY03284
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=DREAMINGLADY03284
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
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKma203:68820 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00003: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00005: Normal(Talk, TargetCanMove), id=FEARLADY03284" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00007: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }


  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00010: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00011: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00013: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=FEARLADY03284" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00015: Normal(CutScene, AutoFadeIn), id=dummye0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00018: Normal(Talk, TargetCanMove), id=GATETOWNMIDDLEAGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00019: Normal(Talk, TargetCanMove), id=DREAMINGLADY03284" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00020: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00021: Normal(Talk, TargetCanMove), id=GATETOWNMIDDLEAGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00022( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00022: Normal(Talk, TargetCanMove), id=GATETOWNMIDDLEAGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00023: Normal(Talk, TargetCanMove), id=DREAMINGLADY03284" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00024( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00024: Normal(Talk, TargetCanMove), id=DREAMINGLADY03284" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00027: Normal(Talk, TargetCanMove), id=GATETOWNMIDDLEAGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKma203:68820 calling Scene00028: Normal(Talk, TargetCanMove), id=DREAMINGLADY03284" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKma203 );
