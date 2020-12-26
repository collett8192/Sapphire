// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdc102 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdc102() : Sapphire::ScriptAPI::EventScript( 68559 ){}; 
  ~StmBdc102() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 6 entries
  //SEQ_255, 4 entries

  //ACTIONTIMELINEEVENTFSORRY = 613
  //ACTOR0 = 1024727
  //ACTOR1 = 1024728
  //ACTOR10 = 1024738
  //ACTOR11 = 1025093
  //ACTOR2 = 1024731
  //ACTOR3 = 1024734
  //ACTOR4 = 1024735
  //ACTOR5 = 1024736
  //ACTOR6 = 1024732
  //ACTOR7 = 1024733
  //ACTOR8 = 1019061
  //ACTOR9 = 1024737
  //BINDACTOR01 = 7178502
  //BINDACTOR02 = 7178526
  //BINDACTOR03 = 7178525
  //BINDACTOR04 = 7178515
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019096
  //LOCBGM01 = 465
  //LOCEOBJ01 = 2009226

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1024727 || param2 == 1024727 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024728 || param2 == 1024728 ) // ACTOR1 = YUGIRI
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1024731 || param2 == 1024731 ) // ACTOR2 = PAWNBROKER03023
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=PAWNBROKER03023
            // +Callback Scene00004: Normal(Talk, FadeIn, TargetCanMove, Menu), id=PAWNBROKER03023
          }
          break;
        }
        if( param1 == 1024734 || param2 == 1024734 ) // ACTOR3 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024735 || param2 == 1024735 ) // ACTOR4 = YUGIRI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024736 || param2 == 1024736 ) // ACTOR5 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1024732 || param2 == 1024732 ) // ACTOR6 = SMILEPAWNBROKER03023
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove, SystemTalk, CanCancel), id=SMILEPAWNBROKER03023
          }
          break;
        }
        if( param1 == 1024733 || param2 == 1024733 ) // ACTOR7 = ROUGHPAWNBROKER03023
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove, SystemTalk, CanCancel), id=ROUGHPAWNBROKER03023
          }
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019061 || param2 == 1019061 ) // ACTOR8 = UME
        {
          Scene00010( player ); // Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=UME
          break;
        }
        if( param1 == 1024737 || param2 == 1024737 ) // ACTOR9 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024738 || param2 == 1024738 ) // ACTOR10 = YUGIRI
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1025093 || param2 == 1025093 ) // ACTOR11 = PAWNBROKER03023
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=PAWNBROKER03023
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
    if( player.getQuestUI8BL( getId() ) == 1 )
      //if( player.getQuestUI8AL( getId() ) == 1 )
        //if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          //player.setQuestUI8AL( getId(), 0 );
          //player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdc102:68559 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdc102:68559 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdc102:68559 calling Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdc102:68559 calling Scene00003: Normal(Talk, TargetCanMove), id=PAWNBROKER03023" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdc102:68559 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove, Menu), id=PAWNBROKER03023" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8BL( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdc102:68559 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdc102:68559 calling Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdc102:68559 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdc102:68559 calling Scene00008: Normal(Talk, TargetCanMove, SystemTalk, CanCancel), id=SMILEPAWNBROKER03023" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        //player.setQuestUI8AL( getId(), 1 );
        //checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdc102:68559 calling Scene00009: Normal(Talk, TargetCanMove, SystemTalk, CanCancel), id=ROUGHPAWNBROKER03023" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        //player.setQuestUI8BH( getId(), 1 );
        //checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdc102:68559 calling Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=UME" );
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
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdc102:68559 calling Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdc102:68559 calling Scene00012: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdc102:68559 calling Scene00013: Normal(Talk, TargetCanMove), id=PAWNBROKER03023" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdc102 );
