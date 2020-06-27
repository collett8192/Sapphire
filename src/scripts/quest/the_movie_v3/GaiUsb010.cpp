// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb010 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb010() : Sapphire::ScriptAPI::EventScript( 66353 ){}; 
  ~GaiUsb010() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1006283
  //ACTOR1 = 1006284
  //ACTOR2 = 1006285
  //ACTOR3 = 1007646
  //ENEMY0 = 4292844
  //ENEMY1 = 4292847
  //EOBJECT0 = 2002289
  //EVENTRANGE0 = 4292885
  //EVENTACTIONRESCUEUNDERMIDDLE = 35
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000639

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=DETOHMOSHROCA
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( actor == 4292885 || actorId == 4292885 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00002( player ); // Scene00002: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 1006284 || actorId == 1006284 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00003( player ); // Scene00003: Normal(Message), id=unknown
          }
        }
        if( actor == 4292844 || actorId == 4292844 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4292847 || actorId == 4292847 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 1006285 || actorId == 1006285 ) // ACTOR2 = MERCHANT
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MERCHANT
        }
        if( actor == 1007646 || actorId == 1007646 ) // ACTOR3 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        if( actor == 2002289 || actorId == 2002289 ) // EOBJECT0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          // +Callback Scene00007: Normal(None), id=unknown
          // +Callback Scene00008: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( actor == 1006283 || actorId == 1006283 ) // ACTOR0 = DETOHMOSHROCA
        {
          Scene00009( player ); // Scene00009: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=DETOHMOSHROCA
        }
        if( actor == 1006284 || actorId == 1006284 ) // ACTOR1 = MERCHANT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=MERCHANT
        }
        if( actor == 1006285 || actorId == 1006285 ) // ACTOR2 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( actor == 1007646 || actorId == 1007646 ) // ACTOR3 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 2 )
      if( player.getQuestUI8AL( getId() ) == 2 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 255 );
        player.setQuestUI8BH( getId(), 1 );
      }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb010:66353 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb010:66353 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=DETOHMOSHROCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb010:66353 calling Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb010:66353 calling Scene00003: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb010:66353 calling Scene00004: Normal(Talk, TargetCanMove), id=MERCHANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb010:66353 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb010:66353 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb010:66353 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb010:66353 calling [BranchChain]Scene00008: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb010:66353 calling Scene00009: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00010( player );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb010:66353 calling [BranchTrue]Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=DETOHMOSHROCA" );
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
    player.sendDebug( "GaiUsb010:66353 calling Scene00011: Normal(Talk, TargetCanMove), id=MERCHANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb010:66353 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb010:66353 calling Scene00013: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb010 );
