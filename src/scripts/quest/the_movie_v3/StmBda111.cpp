// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda111 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda111() : Sapphire::ScriptAPI::EventScript( 67987 ){}; 
  ~StmBda111() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 3 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1020337
  //ACTOR1 = 1020395
  //ACTOR2 = 1020325
  //ACTOR3 = 1020498
  //ACTOR4 = 1020497
  //ACTOR5 = 1020351
  //ACTOR6 = 1020350
  //BINDACTOR01 = 6829424
  //BINDACTOR02 = 6829515
  //ENEMY0 = 7021907
  //ENEMY1 = 7005734
  //EOBJECT0 = 2008157
  //EVENTACTION0 = 50
  //EVENTACTION1 = 1
  //LOCACTOR01 = 1017687

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MNAAGO
        break;
      }
      case 1:
      {
        if( param1 == 1020395 || param2 == 1020395 ) // ACTOR1 = MNAAGO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MNAAGO
          }
        }
        if( param1 == 1020325 || param2 == 1020325 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020498 || param2 == 1020498 ) // ACTOR3 = MNAAGO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MNAAGO
          }
        }
        if( param1 == 1020497 || param2 == 1020497 ) // ACTOR4 = ALISAIE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 3:
      {
        if( param1 == 2008157 || param2 == 2008157 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 7021907 || param2 == 7021907 ) // ENEMY0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( param1 == 7005734 || param2 == 7005734 ) // ENEMY1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00011: Normal(Message, PopBNpc), id=unknown
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020351 || param2 == 1020351 ) // ACTOR5 = MNAAGO
        {
          Scene00012( player ); // Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MNAAGO
        }
        if( param1 == 1020350 || param2 == 1020350 ) // ACTOR6 = ALISAIE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE
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
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda111:67987 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda111:67987 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda111:67987 calling Scene00002: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda111:67987 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda111:67987 calling Scene00004: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda111:67987 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda111:67987 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda111:67987 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda111:67987 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda111:67987 calling [BranchTrue]Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda111:67987 calling Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MNAAGO" );
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
    player.sendDebug( "StmBda111:67987 calling Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda111 );
