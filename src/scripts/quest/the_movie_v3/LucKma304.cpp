// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_17 = dummye1
//SCENE_19 = dummye2
//ENEMY1 = dummye1
//ENEMY2 = dummye2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma304 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma304() : Sapphire::ScriptAPI::EventScript( 68830 ){}; 
  ~LucKma304() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 6 entries
  //SEQ_3, 1 entries
  //SEQ_4, 4 entries
  //SEQ_5, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1028977
  //ACTOR1 = 1028976
  //ACTOR2 = 1030871
  //ACTOR3 = 1030606
  //ACTOR4 = 1028978
  //ACTOR5 = 1028980
  //ENEMY0 = 7926404
  //ENEMY1 = 7926411
  //ENEMY2 = 8005227
  //EOBJECT0 = 2009847
  //EOBJECT1 = 2009848
  //EVENTACTION0 = 50
  //EVENTACTION1 = 1
  //EVENTRANGE0 = 7925885
  //LOCACTION0 = 805
  //LOCACTION1 = 824
  //LOCACTION2 = 803
  //LOCACTION3 = 812
  //LOCACTION4 = 4201
  //LOCACTION5 = 804
  //LOCACTOR0 = 1029465
  //LOCACTOR1 = 1029338
  //LOCACTOR10 = 1029460
  //LOCACTOR11 = 1029461
  //LOCACTOR12 = 1029462
  //LOCACTOR13 = 1029463
  //LOCACTOR14 = 1029464
  //LOCACTOR15 = 1029339
  //LOCACTOR2 = 1029452
  //LOCACTOR3 = 1029453
  //LOCACTOR4 = 1029454
  //LOCACTOR5 = 1029455
  //LOCACTOR6 = 1029456
  //LOCACTOR7 = 1029457
  //LOCACTOR8 = 1029458
  //LOCACTOR9 = 1029459
  //LOCPOS0 = 7981560
  //LOCPOS1 = 8051784
  //LOCPOS10 = 8051786
  //LOCPOS11 = 8051787
  //LOCPOS12 = 8051839
  //LOCPOS2 = 8051777
  //LOCPOS3 = 8051774
  //LOCPOS4 = 8051775
  //LOCPOS5 = 8051778
  //LOCPOS6 = 8051780
  //LOCPOS7 = 8051781
  //LOCPOS8 = 8051783
  //LOCPOS9 = 8051785
  //POPRANGE0 = 7926834

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1028977 || param2 == 1028977 ) // ACTOR0 = TESLEEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=TESLEEN
          break;
        }
        if( param1 == 1028976 || param2 == 1028976 ) // ACTOR1 = CASSARD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=CASSARD
          break;
        }
        if( param1 == 1030871 || param2 == 1030871 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1030606 || param2 == 1030606 ) // ACTOR3 = TESLEEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=TESLEEN
          }
          break;
        }
        if( param1 == 1028976 || param2 == 1028976 ) // ACTOR1 = CASSARD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=CASSARD
          break;
        }
        if( param1 == 1030871 || param2 == 1030871 ) // ACTOR2 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 7925885 || param2 == 7925885 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 7926404 || param2 == 7926404 ) // ENEMY0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028978 || param2 == 1028978 ) // ACTOR4 = TESLEEN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, Message, TargetCanMove), id=TESLEEN
          break;
        }
        if( param1 == 1028976 || param2 == 1028976 ) // ACTOR1 = CASSARD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CASSARD
          break;
        }
        if( param1 == 1030871 || param2 == 1030871 ) // ACTOR2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 2009847 || param2 == 2009847 ) // EOBJECT0 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=TESLEEN
        break;
      }
      case 4:
      {
        if( param1 == 2009848 || param2 == 2009848 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00015( player ); // Scene00015: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 7926411 || param2 == 7926411 ) // ENEMY1 = dummye1
        {
          Scene00017( player ); // Scene00017: Normal(Message, PopBNpc), id=dummye1
          break;
        }
        if( param1 == 8005227 || param2 == 8005227 ) // ENEMY2 = dummye2
        {
          Scene00019( player ); // Scene00019: Normal(Message, PopBNpc), id=dummye2
          break;
        }
        if( param1 == 1028978 || param2 == 1028978 ) // ACTOR4 = TESLEEN
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=TESLEEN
          break;
        }
        break;
      }
      case 5:
      {
        Scene00021( player ); // Scene00021: Normal(Talk, NpcDespawn, TargetCanMove), id=TESLEEN
        break;
      }
      case 255:
      {
        Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=TESLEEN
        // +Callback Scene00023: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, AutoFadeIn), id=TESLEEN
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
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKma304:68830 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00002: Normal(Talk, TargetCanMove), id=CASSARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00005: Normal(Talk, TargetCanMove), id=CASSARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00009: Normal(Talk, Message, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00010: Normal(Talk, TargetCanMove), id=CASSARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00013: Normal(Talk, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00015: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00017: Normal(Message, PopBNpc), id=dummye1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00019: Normal(Message, PopBNpc), id=dummye2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00020: Normal(Talk, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00021: Normal(Talk, NpcDespawn, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00022: Normal(Talk, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKma304:68830 calling Scene00023: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, AutoFadeIn), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
          player.eventFinish( getId(), 1 );
          player.forceZoneing();
        }
      }
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( LucKma304 );
