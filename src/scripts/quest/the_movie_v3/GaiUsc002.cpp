// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc002 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc002() : Sapphire::ScriptAPI::EventScript( 66475 ){}; 
  ~GaiUsc002() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_2, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006467
  //ACTOR1 = 1007631
  //ENEMY0 = 4297103
  //ENEMY1 = 4297104
  //ENEMY2 = 4297106
  //EOBJECT0 = 2002170
  //EOBJECT1 = 2002322
  //EOBJECT2 = 2002590
  //EVENTRANGE0 = 4297079
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000733

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( actor == 4297079 || actorId == 4297079 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00002( player ); // Scene00002: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 2002170 || actorId == 2002170 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00003( player ); // Scene00003: Normal(Message), id=unknown
            // +Callback Scene00004: Normal(None), id=unknown
          }
        }
        if( actor == 4297103 || actorId == 4297103 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4297104 || actorId == 4297104 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 4297106 || actorId == 4297106 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 2002322 || actorId == 2002322 ) // EOBJECT1 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          // +Callback Scene00006: Normal(None), id=unknown
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( actor == 2002590 || actorId == 2002590 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
            // +Callback Scene00008: Normal(None), id=unknown
          }
        }
        if( actor == 1007631 || actorId == 1007631 ) // ACTOR1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( actor == 1006467 || actorId == 1006467 ) // ACTOR0 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1007631 || actorId == 1007631 ) // ACTOR1 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
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
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
      {
        player.setQuestUI8AL( getId(), 0 );
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
    player.sendDebug( "GaiUsc002:66475 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc002:66475 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc002:66475 calling Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc002:66475 calling Scene00003: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc002:66475 calling [BranchTrue]Scene00004: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 3 );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc002:66475 calling Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc002:66475 calling [BranchTrue]Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc002:66475 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc002:66475 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc002:66475 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc002:66475 calling Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc002:66475 calling [BranchTrue]Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.sendDebug( "GaiUsc002:66475 calling Scene00012: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsc002 );
