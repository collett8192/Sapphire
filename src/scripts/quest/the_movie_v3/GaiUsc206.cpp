// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc206 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc206() : Sapphire::ScriptAPI::EventScript( 66501 ){}; 
  ~GaiUsc206() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006505
  //ENEMY0 = 4300168
  //EOBJECT0 = 2002187
  //EOBJECT1 = 2002631
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000746
  //ITEM1 = 2000747

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AHLDUWIL
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      //seq 1 event item ITEM1 = UI8BL max stack 1
      case 1:
      {
        if( actor == 2002187 || actorId == 2002187 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Inventory), id=unknown
            // +Callback Scene00003: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4300168 || actorId == 4300168 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 2002631 || actorId == 2002631 ) // EOBJECT1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          // +Callback Scene00005: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 1
      case 255:
      {
        if( actor == 1006505 || actorId == 1006505 ) // ACTOR0 = AHLDUWIL
        {
          Scene00006( player ); // Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AHLDUWIL
        }
        if( actor == 2002631 || actorId == 2002631 ) // EOBJECT1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          // +Callback Scene00009: Normal(None), id=unknown
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
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc206:66501 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc206:66501 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AHLDUWIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc206:66501 calling Scene00002: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc206:66501 calling [BranchTrue]Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc206:66501 calling Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc206:66501 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc206:66501 calling Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00007( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc206:66501 calling [BranchTrue]Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AHLDUWIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc206:66501 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc206:66501 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsc206 );