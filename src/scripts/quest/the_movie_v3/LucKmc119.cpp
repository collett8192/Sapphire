// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmc119 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmc119() : Sapphire::ScriptAPI::EventScript( 68876 ){}; 
  ~LucKmc119() = default; 

  //SEQ_0, 10 entries
  //SEQ_1, 10 entries
  //SEQ_2, 7 entries
  //SEQ_3, 1 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1029255
  //ACTOR1 = 1029251
  //ACTOR10 = 1029557
  //ACTOR11 = 1029210
  //ACTOR12 = 1029850
  //ACTOR13 = 1029851
  //ACTOR14 = 5010000
  //ACTOR15 = 1029231
  //ACTOR16 = 1029232
  //ACTOR17 = 1029233
  //ACTOR2 = 1029252
  //ACTOR3 = 1029253
  //ACTOR4 = 1029254
  //ACTOR5 = 1029256
  //ACTOR6 = 1029552
  //ACTOR7 = 1029556
  //ACTOR8 = 1029555
  //ACTOR9 = 1029762
  //EOBJECT0 = 2009893
  //EVENTACTION0 = 54
  //INSTANCEDUNGEON0 = 66
  //LOCACTORALMET = 1028139
  //LOCACTORCYMET = 1028141
  //LOCACTOREMETSELCH = 1028112
  //LOCACTORMINFILIA = 1026572
  //LOCACTORRUNAR = 1028142
  //LOCACTORTHANCRED = 1026569
  //LOCACTORUIMET = 1028140
  //LOCACTORURIANGER = 1026570
  //LOCACTORYSHTOLA = 1026571
  //LOCBGMMUSICEX3EVENTBATTLE01 = 651
  //LOCBINDACTOR0 = 7931394
  //LOCBINDACTOR1 = 7931395
  //LOCBINDACTOR2 = 7931396
  //LOCBINDACTOR3 = 7928436
  //LOCBINDACTOR4 = 8049879
  //LOCBINDALMET = 7928011
  //LOCBINDCYMET = 7928413
  //LOCBINDEMETSELCH = 7927607
  //LOCBINDMINFILIA = 7928009
  //LOCBINDRUNAR = 7928435
  //LOCBINDTHANCRED = 7928008
  //LOCBINDUIMET = 7928412
  //LOCBINDURIANGER = 7928010
  //LOCBINDYSHTOLA = 7928433
  //NCUTEVENTLUCKMC11901 = 2014
  //POPRANGE0 = 7928705
  //SCREENIMAGE0 = 744
  //TERRITORYTYPE0 = 817

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029255 || param2 == 1029255 ) // ACTOR0 = ALMET
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029251 || param2 == 1029251 ) // ACTOR1 = EMETSELCH
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=EMETSELCH
          break;
        }
        if( param1 == 1029252 || param2 == 1029252 ) // ACTOR2 = THANCRED
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029253 || param2 == 1029253 ) // ACTOR3 = RYNE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029254 || param2 == 1029254 ) // ACTOR4 = URIANGER
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029256 || param2 == 1029256 ) // ACTOR5 = UIMET
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029552 || param2 == 1029552 ) // ACTOR6 = CYMET
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        if( param1 == 1029556 || param2 == 1029556 ) // ACTOR7 = RUNAR
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=RUNAR
          break;
        }
        if( param1 == 1029555 || param2 == 1029555 ) // ACTOR8 = YSHTOLA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029762 || param2 == 1029762 ) // ACTOR9 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2009893 || param2 == 2009893 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1029557 || param2 == 1029557 ) // ACTOR10 = YSHTOLA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029210 || param2 == 1029210 ) // ACTOR11 = THANCRED
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029850 || param2 == 1029850 ) // ACTOR12 = RYNE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029851 || param2 == 1029851 ) // ACTOR13 = URIANGER
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029251 || param2 == 1029251 ) // ACTOR1 = EMETSELCH
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove, Menu), id=EMETSELCH
          break;
        }
        if( param1 == 1029556 || param2 == 1029556 ) // ACTOR7 = RUNAR
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=RUNAR
          break;
        }
        if( param1 == 1029255 || param2 == 1029255 ) // ACTOR0 = ALMET
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029256 || param2 == 1029256 ) // ACTOR5 = UIMET
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029552 || param2 == 1029552 ) // ACTOR6 = CYMET
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1029210 || param2 == 1029210 ) // ACTOR11 = THANCRED
        {
          Scene00022( player ); // Scene00022: MsqDungeon(Talk, TargetCanMove, Menu), id=THANCRED
          break;
        }
        if( param1 == 1029850 || param2 == 1029850 ) // ACTOR12 = RYNE
        {
          Scene00023( player ); // Scene00023: MsqDungeon(Talk, TargetCanMove, Menu), id=RYNE
          break;
        }
        if( param1 == 1029851 || param2 == 1029851 ) // ACTOR13 = URIANGER
        {
          Scene00024( player ); // Scene00024: MsqDungeon(Talk, TargetCanMove, Menu), id=URIANGER
          break;
        }
        if( param1 == 1029557 || param2 == 1029557 ) // ACTOR10 = YSHTOLA
        {
          Scene00025( player ); // Scene00025: MsqDungeon(Talk, TargetCanMove, Menu), id=YSHTOLA
          break;
        }
        if( param1 == 1029231 || param2 == 1029231 ) // ACTOR15 = ALMET
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029232 || param2 == 1029232 ) // ACTOR16 = UIMET
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029233 || param2 == 1029233 ) // ACTOR17 = CYMET
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00029( player ); // Scene00029: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029557 || param2 == 1029557 ) // ACTOR10 = YSHTOLA
        {
          Scene00030( player ); // Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029210 || param2 == 1029210 ) // ACTOR11 = THANCRED
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029850 || param2 == 1029850 ) // ACTOR12 = RYNE
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029851 || param2 == 1029851 ) // ACTOR13 = URIANGER
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029231 || param2 == 1029231 ) // ACTOR15 = ALMET
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029232 || param2 == 1029232 ) // ACTOR16 = UIMET
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029233 || param2 == 1029233 ) // ACTOR17 = CYMET
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=CYMET
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmc119:68876 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00002: Normal(Talk, TargetCanMove), id=EMETSELCH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00003: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00004: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00005: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00006: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00007: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00008: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00012: Normal(Talk, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00014: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00015: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00016: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00017: Normal(Talk, TargetCanMove, Menu), id=EMETSELCH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00018: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00019: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00020: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00021: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00022: MsqDungeon(Talk, TargetCanMove, Menu), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00029( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00023: MsqDungeon(Talk, TargetCanMove, Menu), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00029( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00024: MsqDungeon(Talk, TargetCanMove, Menu), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00029( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00025: MsqDungeon(Talk, TargetCanMove, Menu), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00029( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00026: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00027: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00028: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00029: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA" );
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
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00031: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00032: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00033: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00034: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00035: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmc119:68876 calling Scene00036: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmc119 );
