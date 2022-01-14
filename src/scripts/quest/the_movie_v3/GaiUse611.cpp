// FFXIVTheMovie.ParserV3.6
// id hint used:
//SCENE_5 = SCIENTIST00423_2
//SCENE_14 = SCIENTIST00423_3
//SCENE_16 = SCIENTIST00423_4
//SCENE_25 = SCIENTIST00423_5
//SCENE_27 = SCIENTIST00423_6
//SCENE_40 = SCIENTIST00423_7
//SCENE_42 = SCIENTIST00423_8
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse611 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse611() : Sapphire::ScriptAPI::EventScript( 65959 ){}; 
  ~GaiUse611() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_4, 5 entries
  //SEQ_5, 1 entries
  //SEQ_6, 1 entries
  //SEQ_7, 5 entries
  //SEQ_8, 1 entries
  //SEQ_9, 1 entries
  //SEQ_10, 7 entries
  //SEQ_11, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1010897
  //ACTOR1 = 1011615
  //ACTOR2 = 1011616
  //ACTOR3 = 1010984
  //ACTOR4 = 1010985
  //ACTOR5 = 1010986
  //ACTOR6 = 1010987
  //ENEMY0 = 5607525
  //ENEMY1 = 5607526
  //ENEMY10 = 5607542
  //ENEMY2 = 5607527
  //ENEMY3 = 5607530
  //ENEMY4 = 5607531
  //ENEMY5 = 5607534
  //ENEMY6 = 5607537
  //ENEMY7 = 5607538
  //ENEMY8 = 5607540
  //ENEMY9 = 5607541
  //EOBJECT0 = 2005065
  //EOBJECT1 = 2005066
  //EOBJECT2 = 2005067
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONWATCHGUARDMIDDLE = 56
  //LOCACTOR0 = 5607561

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA
        break;
      }
      case 1:
      {
        if( param1 == 1011615 || param2 == 1011615 ) // ACTOR1 = HOARYBOULDER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=HOARYBOULDER
          }
          break;
        }
        if( param1 == 1011616 || param2 == 1011616 ) // ACTOR2 = COULTENET
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=COULTENET
          break;
        }
        break;
      }
      case 2:
      {
        if( type != 2 ) Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423
        break;
      }
      case 3:
      {
        if( type != 2 ) Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=SCIENTIST00423_2
        break;
      }
      case 4:
      {
        if( param1 == 2005065 || param2 == 2005065 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5607525 || param2 == 5607525 ) // ENEMY0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5607526 || param2 == 5607526 ) // ENEMY1 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5607527 || param2 == 5607527 ) // ENEMY2 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1010985 || param2 == 1010985 ) // ACTOR4 = SCIENTIST00423_3
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=SCIENTIST00423_3
          break;
        }
        break;
      }
      case 5:
      {
        if( type != 2 ) Scene00015( player ); // Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423
        break;
      }
      case 6:
      {
        if( type != 2 ) Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=SCIENTIST00423_4
        break;
      }
      case 7:
      {
        if( param1 == 2005066 || param2 == 2005066 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00018( player ); // Scene00018: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5607530 || param2 == 5607530 ) // ENEMY3 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5607531 || param2 == 5607531 ) // ENEMY4 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5607534 || param2 == 5607534 ) // ENEMY5 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1010986 || param2 == 1010986 ) // ACTOR5 = SCIENTIST00423_5
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=SCIENTIST00423_5
          break;
        }
        break;
      }
      case 8:
      {
        if( type != 2 ) Scene00026( player ); // Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423
        break;
      }
      case 9:
      {
        if( type != 2 ) Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=SCIENTIST00423_6
        break;
      }
      case 10:
      {
        if( param1 == 2005067 || param2 == 2005067 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00029( player ); // Scene00029: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5607537 || param2 == 5607537 ) // ENEMY6 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5607538 || param2 == 5607538 ) // ENEMY7 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5607540 || param2 == 5607540 ) // ENEMY8 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5607541 || param2 == 5607541 ) // ENEMY9 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 5607542 || param2 == 5607542 ) // ENEMY10 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1010987 || param2 == 1010987 ) // ACTOR6 = SCIENTIST00423_7
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=SCIENTIST00423_7
          break;
        }
        break;
      }
      case 11:
      {
        if( type != 2 ) Scene00041( player ); // Scene00041: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00042( player ); // Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SCIENTIST00423_8
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
    player.sendDebug( "emote: {}", emoteId );
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
      player.setQuestBitFlag8( getId(), 1, false );
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 6 );
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    player.updateQuest( getId(), 7 );
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 8 );
    }
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    player.updateQuest( getId(), 9 );
  }
  void checkProgressSeq9( Entity::Player& player )
  {
    player.updateQuest( getId(), 10 );
  }
  void checkProgressSeq10( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 5 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 11 );
    }
  }
  void checkProgressSeq11( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00003: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00005: Normal(Talk, TargetCanMove), id=SCIENTIST00423_2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_4: EOBJECT0, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_4: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_4: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_4: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00014: Normal(Talk, TargetCanMove), id=SCIENTIST00423_3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_5: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_6: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00016: Normal(Talk, TargetCanMove), id=SCIENTIST00423_4" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_7: EOBJECT1, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00018: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_7: ENEMY3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00020: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_7: ENEMY4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00022: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_7: ENEMY5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00024: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_7: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00025: Normal(Talk, TargetCanMove), id=SCIENTIST00423_5" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_8: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_9: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00027: Normal(Talk, TargetCanMove), id=SCIENTIST00423_6" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq9( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00029( Entity::Player& player ) //SEQ_10: EOBJECT2, UI8AL = 5, Flag8(1)=True
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00029: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 5 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq10( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_10: ENEMY6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00031: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq10( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00033( Entity::Player& player ) //SEQ_10: ENEMY7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00033: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq10( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00035( Entity::Player& player ) //SEQ_10: ENEMY8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00035: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq10( player );
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00037( Entity::Player& player ) //SEQ_10: ENEMY9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00037: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq10( player );
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00039( Entity::Player& player ) //SEQ_10: ENEMY10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00039: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq10( player );
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player ) //SEQ_10: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00040: Normal(Talk, TargetCanMove), id=SCIENTIST00423_7" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player ) //SEQ_11: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00041: Normal(Talk, NpcDespawn, TargetCanMove), id=SCIENTIST00423" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq11( player );
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse611:65959 calling Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SCIENTIST00423_8" );
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
    player.playScene( getId(), 42, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse611 );
