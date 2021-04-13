// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmc108 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmc108() : Sapphire::ScriptAPI::EventScript( 68865 ){}; 
  ~LucKmc108() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 6 entries
  //SEQ_2, 8 entries
  //SEQ_3, 4 entries
  //SEQ_4, 5 entries
  //SEQ_5, 5 entries
  //SEQ_6, 4 entries
  //SEQ_7, 5 entries
  //SEQ_8, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1029194
  //ACTOR1 = 1029196
  //ACTOR2 = 1029211
  //ACTOR3 = 1029212
  //ACTOR4 = 1029213
  //ACTOR5 = 1029195
  //ACTOR6 = 1029214
  //ACTOR7 = 1029215
  //ACTOR8 = 1029216
  //ACTOR9 = 1029217
  //ENEMY0 = 8005179
  //ENEMY1 = 8005180
  //ENEMY2 = 8005182
  //ENEMY3 = 8005181
  //EOBJECT0 = 2010504
  //EOBJECT1 = 2010505
  //EOBJECT2 = 2009873
  //EOBJECT3 = 2009874
  //EOBJECT4 = 2009875
  //EOBJECT5 = 2010501
  //EOBJECT6 = 2009876
  //EOBJECT7 = 2010502
  //EVENTACTION0 = 35
  //EVENTACTION1 = 54
  //EVENTRANGE0 = 7944315
  //ITEM0 = 2002547
  //ITEM1 = 2002548
  //ITEM2 = 2002549
  //LOCACTORMINFILIA = 1026572
  //LOCACTORTHANCRED = 1026569
  //LOCACTORURIANGER = 1026570
  //LOCACTORWATCHER = 1029400
  //LOCACTORYSHTOLA = 1026571
  //LOCBINDACTOR0 = 7944305
  //LOCBINDACTOR1 = 7927423
  //LOCBINDACTOR2 = 7926659
  //LOCBINDACTOR3 = 7926662
  //LOCBINDACTOR4 = 7927402
  //LOCEOBJLITHOGRAPH = 2010654
  //LOCVFX01 = 598

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029194 || param2 == 1029194 ) // ACTOR0 = YSHTOLA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029196 || param2 == 1029196 ) // ACTOR1 = RYNE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029211 || param2 == 1029211 ) // ACTOR2 = THANCRED
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 2010504 || param2 == 2010504 ) // EOBJECT0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010505 || param2 == 2010505 ) // EOBJECT1 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029212 || param2 == 1029212 ) // ACTOR3 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=YSHTOLA
          }
          break;
        }
        if( param1 == 1029213 || param2 == 1029213 ) // ACTOR4 = THANCRED
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029195 || param2 == 1029195 ) // ACTOR5 = URIANGER
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029196 || param2 == 1029196 ) // ACTOR1 = RYNE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 2010504 || param2 == 2010504 ) // EOBJECT0 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010505 || param2 == 2010505 ) // EOBJECT1 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(Message), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 7944315 || param2 == 7944315 ) // EVENTRANGE0 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 8005179 || param2 == 8005179 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            player.setQuestUI8AL( getId(), 1 );
            checkProgressSeq2( player );
          }
          break;
        }
        if( param1 == 2009873 || param2 == 2009873 ) // EOBJECT2 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029214 || param2 == 1029214 ) // ACTOR6 = WATCHER03329
        {
          Scene00015( player ); // Scene00015: Normal(Talk, Message, TargetCanMove), id=WATCHER03329
          break;
        }
        if( param1 == 1029195 || param2 == 1029195 ) // ACTOR5 = URIANGER
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029215 || param2 == 1029215 ) // ACTOR7 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010504 || param2 == 2010504 ) // EOBJECT0 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010505 || param2 == 2010505 ) // EOBJECT1 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1029214 || param2 == 1029214 ) // ACTOR6 = WATCHER03329
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk, FadeIn, TargetCanMove), id=WATCHER03329
          }
          break;
        }
        if( param1 == 2010504 || param2 == 2010504 ) // EOBJECT0 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010505 || param2 == 2010505 ) // EOBJECT1 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029195 || param2 == 1029195 ) // ACTOR5 = URIANGER
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      //seq 4 event item ITEM1 = UI8BL max stack ?
      case 4:
      {
        if( param1 == 2009874 || param2 == 2009874 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1029214 || param2 == 1029214 ) // ACTOR6 = WATCHER03329
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=WATCHER03329
          break;
        }
        if( param1 == 1029195 || param2 == 1029195 ) // ACTOR5 = URIANGER
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 2010504 || param2 == 2010504 ) // EOBJECT0 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010505 || param2 == 2010505 ) // EOBJECT1 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(Message, Inventory), id=unknown
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack ?
      //seq 5 event item ITEM1 = UI8BL max stack ?
      case 5:
      {
        if( param1 == 2009875 || param2 == 2009875 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00032( player ); // Scene00032: Normal(Message), id=unknown
          }
          break;
        }
        if( param1 == 8005180 || param2 == 8005180 ) // ENEMY1 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2010504 || param2 == 2010504 ) // EOBJECT0 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010505 || param2 == 2010505 ) // EOBJECT1 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029195 || param2 == 1029195 ) // ACTOR5 = URIANGER
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      //seq 6 event item ITEM0 = UI8BH max stack ?
      //seq 6 event item ITEM1 = UI8BL max stack ?
      //seq 6 event item ITEM2 = UI8CH max stack 2
      case 6:
      {
        if( param1 == 2010501 || param2 == 2010501 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00038( player ); // Scene00038: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2010504 || param2 == 2010504 ) // EOBJECT0 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010505 || param2 == 2010505 ) // EOBJECT1 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029195 || param2 == 1029195 ) // ACTOR5 = URIANGER
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      //seq 7 event item ITEM0 = UI8BH max stack ?
      //seq 7 event item ITEM1 = UI8BL max stack ?
      //seq 7 event item ITEM2 = UI8CH max stack 2
      case 7:
      {
        if( param1 == 2009876 || param2 == 2009876 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00043( player ); // Scene00043: Normal(Message, Inventory), id=unknown
            // +Callback Scene00044: Normal(Message), id=unknown
          }
          break;
        }
        if( param1 == 8005182 || param2 == 8005182 ) // ENEMY2 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 8005181 || param2 == 8005181 ) // ENEMY3 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2010505 || param2 == 2010505 ) // EOBJECT1 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1029195 || param2 == 1029195 ) // ACTOR5 = URIANGER
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      //seq 8 event item ITEM1 = UI8BH max stack ?
      //seq 8 event item ITEM2 = UI8BL max stack 2
      case 8:
      {
        if( param1 == 2010502 || param2 == 2010502 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00051( player ); // Scene00051: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2010505 || param2 == 2010505 ) // EOBJECT1 = unknown
        {
          Scene00053( player ); // Scene00053: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029195 || param2 == 1029195 ) // ACTOR5 = URIANGER
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      //seq 255 event item ITEM2 = UI8BH max stack 2
      case 255:
      {
        if( param1 == 1029216 || param2 == 1029216 ) // ACTOR8 = YSHTOLA
        {
          Scene00055( player ); // Scene00055: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00056: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029217 || param2 == 1029217 ) // ACTOR9 = THANCRED
        {
          Scene00057( player ); // Scene00057: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029195 || param2 == 1029195 ) // ACTOR5 = URIANGER
        {
          Scene00058( player ); // Scene00058: Normal(Talk, TargetCanMove), id=URIANGER
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
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
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
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.setQuestUI8CH( getId(), 0 );
      player.updateQuest( getId(), 8 );
    }
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 2 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmc108:68865 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00002: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00003: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq0( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq0( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00007: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00008: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00009: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00012: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00013: Normal(None), id=unknown" );
    if( player.getQuestUI8AL( getId() ) != 1 )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    }
  }


  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00015: Normal(Talk, Message, TargetCanMove), id=WATCHER03329" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00016: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00021: Normal(Talk, FadeIn, TargetCanMove), id=WATCHER03329" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00023: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00024: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00026: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00027: Normal(Talk, TargetCanMove), id=WATCHER03329" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00028: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00030: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00031: Normal(Message, Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00032: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00034: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00035: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00036: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00037: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00038: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00040: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00041: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00042: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00043: Normal(Message, Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00044( player );
    };
    player.playScene( getId(), 43, NONE, callback );
  }
  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00044: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 44, NONE, callback );
  }


  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00046: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00048: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00050: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00051: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00053: Normal(None), id=unknown" );
    checkProgressSeq8( player );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00054: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00055: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00056( player );
      }
    };
    player.playScene( getId(), 55, NONE, callback );
  }
  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00056: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA" );
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
    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00057: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 57, NONE, callback );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "LucKmc108:68865 calling Scene00058: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 58, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmc108 );
