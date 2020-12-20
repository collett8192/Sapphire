// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdb102 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdb102() : Sapphire::ScriptAPI::EventScript( 68499 ){}; 
  ~StmBdb102() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1024137
  //ACTOR1 = 1024138
  //ACTOR2 = 1024130
  //ACTOR3 = 1024131
  //ACTOR4 = 1024132
  //ACTOR5 = 1024133
  //ACTOR6 = 1024103
  //ACTOR7 = 1024104
  //BINDACTOR01 = 7074886
  //EVENTPICTRUESTMBDB10201 = 561
  //EVENTPICTRUESTMBDB10202 = 562
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019537
  //LOCBGM01 = 459
  //LOCBGM02 = 92

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1024137 || param2 == 1024137 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024138 || param2 == 1024138 ) // ACTOR1 = ARENVALD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1024130 || param2 == 1024130 ) // ACTOR2 = MIDDLEAGEMAN
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MIDDLEAGEMAN
            // +Callback Scene00004: Normal(Talk, TargetCanMove), id=MIDDLEAGEMAN
          }
          break;
        }
        if( param1 == 1024131 || param2 == 1024131 ) // ACTOR3 = MIDDLEAGEWOMAN
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MIDDLEAGEWOMAN
            // +Callback Scene00006: Normal(Talk, TargetCanMove), id=MIDDLEAGEWOMAN
          }
          break;
        }
        if( param1 == 1024132 || param2 == 1024132 ) // ACTOR4 = MIDDLEAGEHELLSGUARD
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=MIDDLEAGEHELLSGUARD
            // +Callback Scene00008: Normal(Talk, TargetCanMove), id=MIDDLEAGEHELLSGUARD
          }
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1024133 || param2 == 1024133 ) // ACTOR5 = ERNOLD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ERNOLD
          }
          break;
        }
        if( param1 == 1024130 || param2 == 1024130 ) // ACTOR2 = MIDDLEAGEMAN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MIDDLEAGEMAN
          break;
        }
        if( param1 == 1024131 || param2 == 1024131 ) // ACTOR3 = MIDDLEAGEWOMAN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=MIDDLEAGEWOMAN
          break;
        }
        if( param1 == 1024132 || param2 == 1024132 ) // ACTOR4 = MIDDLEAGEHELLSGUARD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MIDDLEAGEHELLSGUARD
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1024103 || param2 == 1024103 ) // ACTOR6 = ARENVALD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=ARENVALD
          break;
        }
        if( param1 == 1024133 || param2 == 1024133 ) // ACTOR5 = ERNOLD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ERNOLD
          break;
        }
        if( param1 == 1024104 || param2 == 1024104 ) // ACTOR7 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
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
    if( player.getQuestUI8AL( getId() ) == 3 )
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdb102:68499 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00002: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00003: Normal(Talk, TargetCanMove), id=MIDDLEAGEMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00004: Normal(Talk, TargetCanMove), id=MIDDLEAGEMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00005: Normal(Talk, TargetCanMove), id=MIDDLEAGEWOMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00006: Normal(Talk, TargetCanMove), id=MIDDLEAGEWOMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00007: Normal(Talk, TargetCanMove), id=MIDDLEAGEHELLSGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00008: Normal(Talk, TargetCanMove), id=MIDDLEAGEHELLSGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00009: Normal(Talk, TargetCanMove), id=ERNOLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00010: Normal(Talk, TargetCanMove), id=MIDDLEAGEMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00011: Normal(Talk, TargetCanMove), id=MIDDLEAGEWOMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00012: Normal(Talk, TargetCanMove), id=MIDDLEAGEHELLSGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=ARENVALD" );
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
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00014: Normal(Talk, TargetCanMove), id=ERNOLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdb102:68499 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdb102 );
