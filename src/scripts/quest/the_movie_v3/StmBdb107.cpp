// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdb107 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdb107() : Sapphire::ScriptAPI::EventScript( 68504 ){}; 
  ~StmBdb107() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1024102
  //ACTOR1 = 1024040
  //ACTOR2 = 1024041
  //ACTOR3 = 1024585
  //ACTOR4 = 1024042
  //ACTOR5 = 1024043
  //LOCALQUEST0 = 68135
  //LOCALQUEST1 = 66853
  //LOCENPCGODBERT01 = 1024501
  //LOCLEVELCHAIRMY = 7099581
  //LOCLEVELCHAIRNANA = 7099570
  //LOCLEVELCHAIRPAPA = 7099575
  //LOCLEVELSTANDNANA = 7074652
  //QSTACCEPTCHK00 = 65970

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=NANAMOULNAMO
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove, Menu, SystemTalk), id=NANAMOULNAMO
        break;
      }
      case 2:
      {
        if( param1 == 1024041 || param2 == 1024041 ) // ACTOR2 = NANAMOULNAMO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove, SystemTalk), id=NANAMOULNAMO
          }
          break;
        }
        if( param1 == 1024585 || param2 == 1024585 ) // ACTOR3 = ULDAHNCITIZEN02968
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ULDAHNCITIZEN02968
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1024042 || param2 == 1024042 ) // ACTOR4 = NANAMOULNAMO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=NANAMOULNAMO
          }
          break;
        }
        if( param1 == 1024585 || param2 == 1024585 ) // ACTOR3 = ULDAHNCITIZEN02968
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove, SystemTalk), id=ULDAHNCITIZEN02968
          break;
        }
        break;
      }
      case 255:
      {
        Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=NANAMOULNAMO
        // +Callback Scene00008: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=NANAMOULNAMO
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
    player.updateQuest( getId(), 2 );
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdb107:68504 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdb107:68504 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdb107:68504 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove, Menu, SystemTalk), id=NANAMOULNAMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdb107:68504 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove, SystemTalk), id=NANAMOULNAMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdb107:68504 calling Scene00004: Normal(Talk, TargetCanMove), id=ULDAHNCITIZEN02968" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdb107:68504 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdb107:68504 calling Scene00006: Normal(Talk, TargetCanMove, SystemTalk), id=ULDAHNCITIZEN02968" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdb107:68504 calling Scene00007: Normal(Talk, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdb107:68504 calling Scene00008: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=NANAMOULNAMO" );
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
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( StmBdb107 );
