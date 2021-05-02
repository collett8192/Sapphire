// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmd108 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmd108() : Sapphire::ScriptAPI::EventScript( 69149 ){}; 
  ~LucKmd108() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_4, 9 entries
  //SEQ_5, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1029637
  //ACTOR1 = 1029640
  //ACTOR2 = 1029636
  //ACTOR3 = 1029638
  //ACTOR4 = 1029639
  //ACTOR5 = 1029635
  //ACTOR6 = 5010000
  //ACTOR7 = 1029641
  //ACTOR8 = 1029642
  //ACTOR9 = 1029643
  //ENEMY0 = 8005268
  //ENEMY1 = 8005269
  //ENEMY2 = 8005270
  //EOBJECT0 = 2009910
  //EOBJECT1 = 2009911
  //EOBJECT2 = 2009912
  //EVENTACTION0 = 3
  //EVENTACTION1 = 1
  //EVENTRANGE0 = 8030748
  //EVENTRANGE1 = 8030753
  //ITEM0 = 2002559
  //LOCACTORJERICK = 1028871
  //LOCBINDACTOR0 = 7934689
  //LOCBINDACTOR1 = 7934688
  //LOCBINDACTOR2 = 7934700
  //LOCBINDACTOR3 = 7934736
  //LOCEOBJTOOLBOX = 2010670
  //LOCPOSLCUTDIY1START = 8034358
  //LOCPOSLCUTDIY2START = 8034359
  //LOCSESCRAPEFILETOWOOD = 225
  //LOCSETIGHTENBOLT = 224
  //LOCSEVULTURECRY = 223

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029637 || param2 == 1029637 ) // ACTOR0 = RYNE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029640 || param2 == 1029640 ) // ACTOR1 = JERYK
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1029636 || param2 == 1029636 ) // ACTOR2 = THANCRED
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029638 || param2 == 1029638 ) // ACTOR3 = URIANGER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029639 || param2 == 1029639 ) // ACTOR4 = THAFFE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1029635 || param2 == 1029635 ) // ACTOR5 = MAGNUS
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 1029640 || param2 == 1029640 ) // ACTOR1 = JERYK
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=JERYK
          }
          break;
        }
        if( param1 == 1029635 || param2 == 1029635 ) // ACTOR5 = MAGNUS
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029639 || param2 == 1029639 ) // ACTOR4 = THAFFE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( param1 == 5010000 || param2 == 5010000 ) // ACTOR6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, FadeIn, Dismount, Menu, SystemTalk), id=unknown
            // +Callback Scene00011: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1029641 || param2 == 1029641 ) // ACTOR7 = JERYK
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1029635 || param2 == 1029635 ) // ACTOR5 = MAGNUS
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029639 || param2 == 1029639 ) // ACTOR4 = THAFFE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      case 3:
      {
        if( param1 == 5010000 || param2 == 5010000 ) // ACTOR6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, FadeIn, Dismount, Menu, SystemTalk), id=unknown
            // +Callback Scene00016: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1029642 || param2 == 1029642 ) // ACTOR8 = JERYK
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1029635 || param2 == 1029635 ) // ACTOR5 = MAGNUS
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029639 || param2 == 1029639 ) // ACTOR4 = THAFFE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8CH max stack ?
      case 4:
      {
        if( param1 == 2009910 || param2 == 2009910 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 8005268 || param2 == 8005268 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 2009911 || param2 == 2009911 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 8005269 || param2 == 8005269 ) // ENEMY1 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2009912 || param2 == 2009912 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 8005270 || param2 == 8005270 ) // ENEMY2 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00031: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1029642 || param2 == 1029642 ) // ACTOR8 = JERYK
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1029635 || param2 == 1029635 ) // ACTOR5 = MAGNUS
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029639 || param2 == 1029639 ) // ACTOR4 = THAFFE
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack ?
      case 5:
      {
        if( param1 == 1029642 || param2 == 1029642 ) // ACTOR8 = JERYK
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00035( player ); // Scene00035: Normal(Talk, NpcDespawn, TargetCanMove), id=JERYK
          }
          break;
        }
        if( param1 == 1029635 || param2 == 1029635 ) // ACTOR5 = MAGNUS
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029639 || param2 == 1029639 ) // ACTOR4 = THAFFE
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( param1 == 1029643 || param2 == 1029643 ) // ACTOR9 = JERYK
        {
          Scene00038( player ); // Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1029635 || param2 == 1029635 ) // ACTOR5 = MAGNUS
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029639 || param2 == 1029639 ) // ACTOR4 = THAFFE
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=THAFFE
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.updateQuest( getId(), 5 );
        }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmd108:69149 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00002: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00003: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00004: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00005: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00006: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00008: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00009: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00010: Normal(Talk, FadeIn, Dismount, Menu, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI | SET_INVIS_BASE | DISABLE_SKIP, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00011: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00012: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00013: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00014: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00015: Normal(Talk, FadeIn, Dismount, Menu, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI | SET_INVIS_BASE | DISABLE_SKIP, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00016: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00017: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00018: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00019: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00021: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }


  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00023: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00025: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00027: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00029: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00031( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00031: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00032: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00033: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00034: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00035: Normal(Talk, NpcDespawn, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00036: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00037: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=JERYK" );
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
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00039: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmd108:69149 calling Scene00040: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmd108 );
