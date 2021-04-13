// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmc120 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmc120() : Sapphire::ScriptAPI::EventScript( 68877 ){}; 
  ~LucKmc120() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 3 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1029557
  //ACTOR1 = 1029210
  //ACTOR2 = 1029850
  //ACTOR3 = 1029851
  //ACTOR4 = 1029231
  //ACTOR5 = 1029232
  //ACTOR6 = 1029233
  //ACTOR7 = 1029197
  //LOCACTORALMET = 1028139
  //LOCACTORCYMET = 1028141
  //LOCACTORMINFILIA = 1026572
  //LOCACTORTHANCRED = 1026569
  //LOCACTORUIMET = 1028140
  //LOCACTORURIANGER = 1026570
  //LOCACTORYSHTOLA = 1026571
  //LOCACTSTANDPRAY = 4254
  //LOCBGMMUSICEX3HOPETHEME03 = 648
  //LOCBINDACTOR0 = 7931394
  //LOCBINDACTOR1 = 7931395
  //LOCBINDACTOR2 = 7931396
  //NCUTEVENTLUCKMC12001 = 2015

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029557 || param2 == 1029557 ) // ACTOR0 = YSHTOLA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029210 || param2 == 1029210 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029850 || param2 == 1029850 ) // ACTOR2 = RYNE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029851 || param2 == 1029851 ) // ACTOR3 = URIANGER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029231 || param2 == 1029231 ) // ACTOR4 = ALMET
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029232 || param2 == 1029232 ) // ACTOR5 = UIMET
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029233 || param2 == 1029233 ) // ACTOR6 = CYMET
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029231 || param2 == 1029231 ) // ACTOR4 = ALMET
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=ALMET
          }
          break;
        }
        if( param1 == 1029232 || param2 == 1029232 ) // ACTOR5 = UIMET
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029233 || param2 == 1029233 ) // ACTOR6 = CYMET
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029197 || param2 == 1029197 ) // ACTOR7 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1029231 || param2 == 1029231 ) // ACTOR4 = ALMET
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029232 || param2 == 1029232 ) // ACTOR5 = UIMET
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029233 || param2 == 1029233 ) // ACTOR6 = CYMET
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=CYMET
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "LucKmc120:68877 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00003: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00004: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00005: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00006: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00007: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00009: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00010: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00011: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00012: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00013: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmc120:68877 calling Scene00014: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmc120 );
