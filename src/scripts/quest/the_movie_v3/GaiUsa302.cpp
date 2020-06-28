// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsa302 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsa302() : Sapphire::ScriptAPI::EventScript( 66270 ){}; 
  ~GaiUsa302() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006193
  //ENEMY0 = 28
  //EOBJECT0 = 2001945
  //ITEM0 = 2000588
  //ITEM1 = 2000589
  //ITEM2 = 2000590

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=TETEROON
        break;
      }
      //seq 1 event item ITEM0 = UI8BL max stack ?
      //seq 1 event item ITEM1 = UI8CH max stack 1
      //seq 1 event item ITEM2 = UI8CL max stack 5
      case 1:
      {
        if( actor == 2001945 || actorId == 2001945 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Inventory), id=unknown
            // +Callback Scene00002: Normal(None), id=unknown
          }
        }
        if( actor == 28 || actorId == 28 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      //seq 255 event item ITEM1 = UI8BL max stack 1
      //seq 255 event item ITEM2 = UI8CH max stack 5
      case 255:
      {
        Scene00003( player ); // Scene00003: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00004: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TETEROON
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
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 5 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.setQuestUI8CL( getId(), 0 );
        player.updateQuest( getId(), 255 );
        player.setQuestUI8BH( getId(), 1 );
        player.setQuestUI8BL( getId(), 1 );
        player.setQuestUI8CH( getId(), 5 );
      }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa302:66270 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=TETEROON" );
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
    player.sendDebug( "GaiUsa302:66270 calling Scene00001: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa302:66270 calling [BranchTrue]Scene00002: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa302:66270 calling Scene00003: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00004( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa302:66270 calling [BranchTrue]Scene00004: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TETEROON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsa302 );
