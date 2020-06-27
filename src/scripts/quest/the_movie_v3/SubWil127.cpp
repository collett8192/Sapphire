// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil127 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil127() : Sapphire::ScriptAPI::EventScript( 66173 ){}; 
  ~SubWil127() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_4, 1 entries
  //SEQ_5, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1003941
  //ENEMY0 = 4097176
  //ENEMY1 = 4097181
  //ENEMY2 = 3986940
  //EOBJECT0 = 2001422
  //EOBJECT1 = 2001446
  //EOBJECT2 = 2001447
  //EOBJECT3 = 2001448
  //EOBJECT4 = 2001449
  //EOBJECT5 = 2001450
  //EOBJECT6 = 2001451
  //EOBJECT7 = 2001452
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000395
  //ITEM1 = 2000407

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=JOSPAIRE
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        Scene00001( player ); // Scene00001: Normal(None), id=unknown
        // +Callback Scene00002: Normal(None), id=unknown
        // +Callback Scene00003: Normal(None), id=unknown
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        Scene00004( player ); // Scene00004: NpcTrade(Talk, TargetCanMove), id=JOSPAIRE
        // +Callback Scene00005: Normal(Talk, TargetCanMove), id=JOSPAIRE
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( actor == 2001446 || actorId == 2001446 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
            // +Callback Scene00007: Normal(None), id=unknown
          }
        }
        if( actor == 2001447 || actorId == 2001447 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
            // +Callback Scene00009: Normal(None), id=unknown
          }
          else
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
          }
        }
        if( actor == 2001448 || actorId == 2001448 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00011( player ); // Scene00011: Normal(None), id=unknown
            // +Callback Scene00012: Normal(None), id=unknown
          }
          else
          {
            Scene00013( player ); // Scene00013: Normal(None), id=unknown
          }
        }
        if( actor == 2001449 || actorId == 2001449 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00014( player ); // Scene00014: Normal(None), id=unknown
            // +Callback Scene00015: Normal(None), id=unknown
          }
          else
          {
            Scene00016( player ); // Scene00016: Normal(None), id=unknown
          }
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      //seq 4 event item ITEM1 = UI8BL max stack ?
      case 4:
      {
        Scene00017( player ); // Scene00017: Normal(None), id=unknown
        // +Callback Scene00018: Normal(None), id=unknown
        // +Callback Scene00019: Normal(Talk, TargetCanMove), id=JOSPAIRE
        break;
      }
      //seq 5 event item ITEM0 = UI8CH max stack 1
      //seq 5 event item ITEM1 = UI8CL max stack ?
      case 5:
      {
        if( actor == 2001450 || actorId == 2001450 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Inventory), id=unknown
            // +Callback Scene00021: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4097176 || actorId == 4097176 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 2001451 || actorId == 2001451 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Inventory), id=unknown
            // +Callback Scene00023: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4097181 || actorId == 4097181 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2001452 || actorId == 2001452 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Inventory), id=unknown
            // +Callback Scene00025: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 3986940 || actorId == 3986940 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack ?
      case 255:
      {
        Scene00026( player ); // Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=JOSPAIRE
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
    player.updateQuest( getId(), 2 );
    player.setQuestUI8BH( getId(), 1 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
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
            player.updateQuest( getId(), 4 );
          }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.setQuestUI8BL( getId(), 0 );
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=JOSPAIRE" );
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
    player.sendDebug( "SubWil127:66173 calling Scene00001: Normal(None), id=unknown" );
    Scene00002( player );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchTrue]Scene00002: Normal(None), id=unknown" );
    Scene00003( player );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchChain]Scene00003: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling Scene00004: NpcTrade(Talk, TargetCanMove), id=JOSPAIRE" );
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
    player.sendDebug( "SubWil127:66173 calling [BranchTrue]Scene00005: Normal(Talk, TargetCanMove), id=JOSPAIRE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchFalse]Scene00010: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchTrue]Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchFalse]Scene00013: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling Scene00014: Normal(None), id=unknown" );
    Scene00015( player );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchTrue]Scene00015: Normal(None), id=unknown" );
    Scene00016( player );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchFalse]Scene00016: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling Scene00017: Normal(None), id=unknown" );
    Scene00018( player );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchTrue]Scene00018: Normal(None), id=unknown" );
    Scene00019( player );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchChain]Scene00019: Normal(Talk, TargetCanMove), id=JOSPAIRE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling Scene00020: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchTrue]Scene00021: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling Scene00022: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchTrue]Scene00023: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling Scene00024: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00025( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling [BranchTrue]Scene00025: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "SubWil127:66173 calling Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=JOSPAIRE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 26, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil127 );
