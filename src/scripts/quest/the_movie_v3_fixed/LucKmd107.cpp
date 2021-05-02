// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmd107 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmd107() : Sapphire::ScriptAPI::EventScript( 69148 ){}; 
  ~LucKmd107() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 7 entries
  //SEQ_4, 1 entries
  //SEQ_5, 4 entries
  //SEQ_6, 2 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1029629
  //ACTOR1 = 1029624
  //ACTOR10 = 1029634
  //ACTOR11 = 1029636
  //ACTOR12 = 1029637
  //ACTOR13 = 1029638
  //ACTOR14 = 1029635
  //ACTOR15 = 1029639
  //ACTOR16 = 1029640
  //ACTOR2 = 1029625
  //ACTOR3 = 1029626
  //ACTOR4 = 1029630
  //ACTOR5 = 1029631
  //ACTOR6 = 1029632
  //ACTOR7 = 1029633
  //ACTOR8 = 1030372
  //ACTOR9 = 1030373
  //ENEMY0 = 8009712
  //ENEMY1 = 8009714
  //ENEMY2 = 8009716
  //EOBJECT0 = 2009907
  //EVENTRANGE0 = 7934675
  //LOCACTIONBASEBADDRINK = 826
  //LOCACTORMAGNUS = 1028147
  //LOCACTORMINFILIA = 1026572
  //LOCACTORTHAFFE = 1028146
  //LOCACTORTHANCRED = 1026569
  //LOCACTORURIANGER = 1026570
  //LOCBGM0 = 649
  //LOCBINDACTOR0 = 7934589
  //LOCBINDACTOR1 = 7934590
  //LOCBINDACTOR2 = 7934591
  //LOCBINDACTOR3 = 7934660
  //LOCBINDACTOR4 = 7934689
  //LOCBINDACTOR5 = 7934688
  //LOCBINDACTOR6 = 7934686
  //LOCSEEVENTDOORCLOSE = 40
  //LOCSEEVENTDOOROPEN = 39

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029629 || param2 == 1029629 ) // ACTOR0 = THAFFE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1029624 || param2 == 1029624 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029625 || param2 == 1029625 ) // ACTOR2 = RYNE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029626 || param2 == 1029626 ) // ACTOR3 = URIANGER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029630 || param2 == 1029630 ) // ACTOR4 = JERYK
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029631 || param2 == 1029631 ) // ACTOR5 = THAFFE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=THAFFE
          }
          break;
        }
        if( param1 == 1029630 || param2 == 1029630 ) // ACTOR4 = JERYK
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1029632 || param2 == 1029632 ) // ACTOR6 = THAFFE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, Message, NpcDespawn, PopBNpc, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 8009712 || param2 == 8009712 ) // ENEMY0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00010: Normal(Message, PopBNpc), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 7934675 || param2 == 7934675 ) // EVENTRANGE0 = unknown
        {
          //Scene00011( player ); // Scene00011: Normal(None), id=unknown
          checkProgressSeq3( player );
          break;
        }
        if( param1 == 8009714 || param2 == 8009714 ) // ENEMY1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq3( player );
          }
          break;
        }
        if( param1 == 8009716 || param2 == 8009716 ) // ENEMY2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1029633 || param2 == 1029633 ) // ACTOR7 = THAFFE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, Message, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 2009907 || param2 == 2009907 ) // EOBJECT0 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030372 || param2 == 1030372 ) // ACTOR8 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030373 || param2 == 1030373 ) // ACTOR9 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        Scene00017( player ); // Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=THAFFE
        break;
      }
      case 5:
      {
        if( param1 == 1029634 || param2 == 1029634 ) // ACTOR10 = THAFFE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, NpcDespawn, TargetCanMove), id=THAFFE
          }
          break;
        }
        if( param1 == 1029636 || param2 == 1029636 ) // ACTOR11 = THANCRED
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029637 || param2 == 1029637 ) // ACTOR12 = RYNE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029638 || param2 == 1029638 ) // ACTOR13 = URIANGER
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1029635 || param2 == 1029635 ) // ACTOR14 = MAGNUS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, FadeIn, TargetCanMove), id=MAGNUS
          }
          break;
        }
        if( param1 == 1029639 || param2 == 1029639 ) // ACTOR15 = THAFFE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029637 || param2 == 1029637 ) // ACTOR12 = RYNE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029636 || param2 == 1029636 ) // ACTOR11 = THANCRED
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029638 || param2 == 1029638 ) // ACTOR13 = URIANGER
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029635 || param2 == 1029635 ) // ACTOR14 = MAGNUS
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029639 || param2 == 1029639 ) // ACTOR15 = THAFFE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1029640 || param2 == 1029640 ) // ACTOR16 = JERYK
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=JERYK
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
    //if( player.getQuestUI8AL( getId() ) == 2 )
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmd107:69148 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00003: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00004: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00005: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00007: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00008: Normal(Talk, Message, NpcDespawn, PopBNpc, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }


  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00013: Normal(Talk, Message, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00018: Normal(Talk, NpcDespawn, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00019: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00020: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00021: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00022: Normal(Talk, FadeIn, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00023: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RYNE" );
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
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00025: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00026: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00027: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00028: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmd107:69148 calling Scene00029: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmd107 );
