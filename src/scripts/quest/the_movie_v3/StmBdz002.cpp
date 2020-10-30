// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdz002 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdz002() : Sapphire::ScriptAPI::EventScript( 68172 ){}; 
  ~StmBdz002() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1019476
  //ACTOR1 = 1019471
  //EOBJECT0 = 2007951
  //EOBJECT1 = 2007952
  //EOBJECT2 = 2007953
  //EOBJECT3 = 2007954
  //EVENTACTION0 = 7
  //ITEM0 = 2002077

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AHELISSA
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 6
      case 1:
      {
        if( param1 == 1019471 || param2 == 1019471 ) // ACTOR1 = TEBBE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=TEBBE
          }
        }
        if( param1 == 1019476 || param2 == 1019476 ) // ACTOR0 = AHELISSA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=AHELISSA
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 6
      case 2:
      {
        if( param1 == 2007951 || param2 == 2007951 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
          }
        }
        if( param1 == 2007952 || param2 == 2007952 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
        }
        if( param1 == 2007953 || param2 == 2007953 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
          }
        }
        if( param1 == 2007954 || param2 == 2007954 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00011( player ); // Scene00011: Normal(None), id=unknown
          }
        }
        if( param1 == 1019476 || param2 == 1019476 ) // ACTOR0 = AHELISSA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=AHELISSA
        }
        if( param1 == 1019471 || param2 == 1019471 ) // ACTOR1 = TEBBE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=TEBBE
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 6
      case 255:
      {
        Scene00014( player ); // Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AHELISSA
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
    if( player.getQuestUI8AL( getId() ) == 4 )
      if( player.getQuestUI8AL( getId() ) == 4 )
        if( player.getQuestUI8AL( getId() ) == 4 )
          if( player.getQuestUI8AL( getId() ) == 4 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.updateQuest( getId(), 255 );
            player.setQuestUI8BH( getId(), 6 );
          }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdz002:68172 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdz002:68172 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AHELISSA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdz002:68172 calling Scene00002: Normal(Talk, TargetCanMove), id=TEBBE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdz002:68172 calling Scene00003: Normal(Talk, TargetCanMove), id=AHELISSA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdz002:68172 calling Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdz002:68172 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdz002:68172 calling Scene00009: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdz002:68172 calling Scene00011: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdz002:68172 calling Scene00012: Normal(Talk, TargetCanMove), id=AHELISSA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdz002:68172 calling Scene00013: Normal(Talk, TargetCanMove), id=TEBBE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdz002:68172 calling Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00015( player );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdz002:68172 calling [BranchTrue]Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AHELISSA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdz002 );
