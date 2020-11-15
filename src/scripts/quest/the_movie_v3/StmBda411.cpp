// FFXIVTheMovie.ParserV3.2
// id hint used:
//ACTOR6 = sheep1
//ACTOR7 = sheep2
//ACTOR8 = sheep3
//ACTOR9 = sheep4
//SCENE_8 = sheep1
//SCENE_10 = sheep2
//SCENE_12 = sheep3
//SCENE_14 = sheep4
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda411 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda411() : Sapphire::ScriptAPI::EventScript( 68046 ){}; 
  ~StmBda411() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 8 entries
  //SEQ_3, 4 entries
  //SEQ_4, 2 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1021730
  //ACTOR1 = 1019426
  //ACTOR10 = 1019417
  //ACTOR11 = 1021732
  //ACTOR12 = 1021731
  //ACTOR2 = 1020689
  //ACTOR3 = 1020690
  //ACTOR4 = 1021603
  //ACTOR5 = 1021604
  //ACTOR6 = 1020691
  //ACTOR7 = 1021601
  //ACTOR8 = 1021600
  //ACTOR9 = 1021602
  //EVENTACTION0 = 1
  //EVENTACTION1 = 16
  //EVENTPICTRUEMAINQUEST411001 = 540
  //LOCAGURA = 4340
  //LOCHIEN001 = 6865255
  //LOCHIEN002 = 1019544
  //LOCHIENAGURA = 1021998
  //LOCMAGUNAI001 = 6840967
  //LOCMAKERSUWARU = 6983430
  //LOCTOHOBGM = 489
  //SHEEPCRY = 148

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN
        break;
        break;
      }
      case 1:
      {
        if( param1 == 1019426 || param2 == 1019426 ) // ACTOR1 = UDUTAI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=UDUTAI
          }
          break;
        }
        if( param1 == 1020689 || param2 == 1020689 ) // ACTOR2 = HIEN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020690 || param2 == 1020690 ) // ACTOR3 = HIEN
        {
          Scene00004( player ); // Scene00004: Normal(Talk), id=HIEN
          break;
        }
        if( param1 == 1021603 || param2 == 1021603 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1021604 || param2 == 1021604 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020691 || param2 == 1020691 ) // ACTOR6 = sheep1
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00008( player ); // Scene00008: Normal(NpcDespawn, TargetCanMove), id=sheep1
          }
          break;
        }
        if( param1 == 1021601 || param2 == 1021601 ) // ACTOR7 = sheep2
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00010( player ); // Scene00010: Normal(NpcDespawn, TargetCanMove), id=sheep2
          }
          break;
        }
        if( param1 == 1021600 || param2 == 1021600 ) // ACTOR8 = sheep3
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00012( player ); // Scene00012: Normal(NpcDespawn, TargetCanMove), id=sheep3
          }
          break;
        }
        if( param1 == 1021602 || param2 == 1021602 ) // ACTOR9 = sheep4
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00014( player ); // Scene00014: Normal(NpcDespawn, TargetCanMove), id=sheep4
          }
          break;
        }
        if( param1 == 1019426 || param2 == 1019426 ) // ACTOR1 = UDUTAI
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=UDUTAI
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1019426 || param2 == 1019426 ) // ACTOR1 = UDUTAI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, FadeIn, TargetCanMove), id=UDUTAI
          }
          break;
        }
        if( param1 == 1020690 || param2 == 1020690 ) // ACTOR3 = HIEN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021603 || param2 == 1021603 ) // ACTOR4 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1021604 || param2 == 1021604 ) // ACTOR5 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020689 || param2 == 1020689 ) // ACTOR2 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1019426 || param2 == 1019426 ) // ACTOR1 = UDUTAI
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=UDUTAI
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR10 = MAGNAI
        {
          Scene00022( player ); // Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MAGNAI
          break;
        }
        if( param1 == 1021732 || param2 == 1021732 ) // ACTOR11 = LYSE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021731 || param2 == 1021731 ) // ACTOR12 = GOSETSU
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021730 || param2 == 1021730 ) // ACTOR0 = HIEN
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1019426 || param2 == 1019426 ) // ACTOR1 = UDUTAI
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=UDUTAI
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
    if( player.getQuestUI8AL( getId() ) == 4 )
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
    player.sendDebug( "StmBda411:68046 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda411:68046 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00002: Normal(Talk, TargetCanMove), id=UDUTAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00003: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00004: Normal(Talk), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00008: Normal(NpcDespawn, TargetCanMove), id=sheep1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00010: Normal(NpcDespawn, TargetCanMove), id=sheep2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00012: Normal(NpcDespawn, TargetCanMove), id=sheep3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00014: Normal(NpcDespawn, TargetCanMove), id=sheep4" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00015: Normal(Talk, TargetCanMove), id=UDUTAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00016: Normal(Talk, FadeIn, TargetCanMove), id=UDUTAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00017: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00020: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00021: Normal(Talk, TargetCanMove), id=UDUTAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MAGNAI" );
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
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00023: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00024: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00025: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda411:68046 calling Scene00026: Normal(Talk, TargetCanMove), id=UDUTAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda411 );
