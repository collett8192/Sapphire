// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda128 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda128() : Sapphire::ScriptAPI::EventScript( 68491 ){}; 
  ~StmBda128() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1020848
  //ACTOR1 = 1020857
  //EOBJECT0 = 2008679
  //EOBJECT1 = 2008680
  //EVENTACTION0 = 16
  //ITEM0 = 2002393

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ANGRYCOEURL
        break;
      }
      case 1:
      {
        if( param1 == 1020857 || param2 == 1020857 ) // ACTOR1 = FRIGHTENEDCOEURL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=FRIGHTENEDCOEURL
          }
        }
        if( param1 == 2008679 || param2 == 2008679 ) // EOBJECT0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
        }
        if( param1 == 1020848 || param2 == 1020848 ) // ACTOR0 = ANGRYCOEURL
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ANGRYCOEURL
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( param1 == 2008680 || param2 == 2008680 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
          }
        }
        if( param1 == 2008679 || param2 == 2008679 ) // EOBJECT0 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( param1 == 1020848 || param2 == 1020848 ) // ACTOR0 = ANGRYCOEURL
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ANGRYCOEURL
        }
        if( param1 == 1020857 || param2 == 1020857 ) // ACTOR1 = FRIGHTENEDCOEURL
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=FRIGHTENEDCOEURL
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1020848 || param2 == 1020848 ) // ACTOR0 = ANGRYCOEURL
        {
          Scene00010( player ); // Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ANGRYCOEURL
        }
        if( param1 == 1020857 || param2 == 1020857 ) // ACTOR1 = FRIGHTENEDCOEURL
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=FRIGHTENEDCOEURL
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
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda128:68491 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda128:68491 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ANGRYCOEURL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda128:68491 calling Scene00002: Normal(Talk, TargetCanMove), id=FRIGHTENEDCOEURL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda128:68491 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda128:68491 calling Scene00004: Normal(Talk, TargetCanMove), id=ANGRYCOEURL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda128:68491 calling Scene00006: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda128:68491 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda128:68491 calling Scene00008: Normal(Talk, TargetCanMove), id=ANGRYCOEURL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda128:68491 calling Scene00009: Normal(Talk, TargetCanMove), id=FRIGHTENEDCOEURL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda128:68491 calling Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda128:68491 calling [BranchTrue]Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ANGRYCOEURL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda128:68491 calling Scene00012: Normal(Talk, TargetCanMove), id=FRIGHTENEDCOEURL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda128 );
