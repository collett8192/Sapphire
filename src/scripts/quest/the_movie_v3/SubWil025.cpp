// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil025 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil025() : Sapphire::ScriptAPI::EventScript( 66207 ){}; 
  ~SubWil025() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1003995
  //ACTOR1 = 1004599
  //ACTOR2 = 1004600
  //ACTOR3 = 1004601
  //ITEM0 = 2000463

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack 1
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=PAPASHAN
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 1
      case 1:
      {
        if( actor == 1004599 || actorId == 1004599 ) // ACTOR1 = GINCHUA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: NpcTrade(Talk), id=GINCHUA
            // +Callback Scene00002: Normal(Talk, TargetCanMove), id=GINCHUA
          }
          else
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=GINCHUA
          }
        }
        if( actor == 1004600 || actorId == 1004600 ) // ACTOR2 = GINCHUB
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: NpcTrade(Talk, TargetCanMove), id=GINCHUB
            // +Callback Scene00005: Normal(Talk, TargetCanMove), id=GINCHUB
          }
          else
          {
            Scene00006( player ); // Scene00006: Normal(Talk), id=GINCHUB
          }
        }
        if( actor == 1004601 || actorId == 1004601 ) // ACTOR3 = GINCHUC
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: NpcTrade(Talk, TargetCanMove), id=GINCHUC
            // +Callback Scene00008: Normal(Talk, TargetCanMove), id=GINCHUC
          }
          else
          {
            Scene00009( player ); // Scene00009: Normal(Talk), id=GINCHUC
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8CL max stack 1
      case 255:
      {
        if( actor == 1003995 || actorId == 1003995 ) // ACTOR0 = PAPASHAN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PAPASHAN
        }
        if( actor == 1004599 || actorId == 1004599 ) // ACTOR1 = GINCHUA
        {
          Scene00011( player ); // Scene00011: Normal(Talk), id=GINCHUA
        }
        if( actor == 1004600 || actorId == 1004600 ) // ACTOR2 = GINCHUB
        {
          Scene00012( player ); // Scene00012: Normal(Talk), id=GINCHUB
        }
        if( actor == 1004601 || actorId == 1004601 ) // ACTOR3 = GINCHUC
        {
          Scene00013( player ); // Scene00013: Normal(Talk), id=GINCHUC
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
    onProgress( player, param1, param1, 3, param1 );
  }

  void onEnterTerritory( Sapphire::Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2 ) override
  {
    onProgress( player, param1, param2, 4, 0 );
  }

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
    player.setQuestUI8CH( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling Scene00001: NpcTrade(Talk), id=GINCHUA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00002( player );
      }
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling [BranchTrue]Scene00002: Normal(Talk, TargetCanMove), id=GINCHUA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling [BranchFalse]Scene00003: Normal(Talk, TargetCanMove), id=GINCHUA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling Scene00004: NpcTrade(Talk, TargetCanMove), id=GINCHUB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00005( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling [BranchTrue]Scene00005: Normal(Talk, TargetCanMove), id=GINCHUB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling [BranchFalse]Scene00006: Normal(Talk), id=GINCHUB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling Scene00007: NpcTrade(Talk, TargetCanMove), id=GINCHUC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00008( player );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling [BranchTrue]Scene00008: Normal(Talk, TargetCanMove), id=GINCHUC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling [BranchFalse]Scene00009: Normal(Talk), id=GINCHUC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling Scene00011: Normal(Talk), id=GINCHUA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling Scene00012: Normal(Talk), id=GINCHUB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil025:66207 calling Scene00013: Normal(Talk), id=GINCHUC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil025 );
