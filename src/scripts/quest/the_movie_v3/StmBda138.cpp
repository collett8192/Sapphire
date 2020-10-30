// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda138 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda138() : Sapphire::ScriptAPI::EventScript( 68004 ){}; 
  ~StmBda138() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 1 entries
  //SEQ_2, 3 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1020434
  //ACTOR1 = 1020394
  //ACTOR2 = 1020435
  //ACTOR3 = 1020530
  //ACTOR4 = 1020436
  //ACTOR5 = 1020499
  //ACTOR6 = 1020528
  //ACTOR7 = 1020529
  //BINDACTOR01 = 6847817
  //BINDACTOR02 = 6844567
  //BINDACTOR03 = 6881458

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020434 || param2 == 1020434 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020394 || param2 == 1020394 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020435 || param2 == 1020435 ) // ACTOR2 = LYSE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020530 || param2 == 1020530 ) // ACTOR3 = TATARU
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 1:
      {
        Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE
        break;
      }
      case 2:
      {
        if( param1 == 1020499 || param2 == 1020499 ) // ACTOR5 = HOMEI
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=HOMEI
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=HOMEI
          }
        }
        if( param1 == 1020528 || param2 == 1020528 ) // ACTOR6 = HOZAN
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=HOZAN
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=HOZAN
          }
        }
        if( param1 == 1020529 || param2 == 1020529 ) // ACTOR7 = HIGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HIGIRI
            // +Callback Scene00011: Normal(Talk, TargetCanMove), id=HIGIRI
          }
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020436 || param2 == 1020436 ) // ACTOR4 = LYSE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
        }
        if( param1 == 1020499 || param2 == 1020499 ) // ACTOR5 = HOMEI
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=HOMEI
        }
        if( param1 == 1020528 || param2 == 1020528 ) // ACTOR6 = HOZAN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=HOZAN
        }
        if( param1 == 1020529 || param2 == 1020529 ) // ACTOR7 = HIGIRI
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=HIGIRI
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda138:68004 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling Scene00004: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling Scene00006: Normal(Talk, TargetCanMove), id=HOMEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling [BranchTrue]Scene00007: Normal(Talk, TargetCanMove), id=HOMEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling Scene00008: Normal(Talk, TargetCanMove), id=HOZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling [BranchTrue]Scene00009: Normal(Talk, TargetCanMove), id=HOZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling Scene00010: Normal(Talk, TargetCanMove), id=HIGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling [BranchTrue]Scene00011: Normal(Talk, TargetCanMove), id=HIGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling Scene00013: Normal(Talk, TargetCanMove), id=HOMEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling Scene00014: Normal(Talk, TargetCanMove), id=HOZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda138:68004 calling Scene00015: Normal(Talk, TargetCanMove), id=HIGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda138 );
