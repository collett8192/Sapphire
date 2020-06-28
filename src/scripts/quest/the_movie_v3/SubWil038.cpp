// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil038 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil038() : Sapphire::ScriptAPI::EventScript( 65766 ){}; 
  ~SubWil038() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 13 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002014
  //ACTOR1 = 1003685
  //ACTOR2 = 1001353
  //ENEMY0 = 4086831
  //ENEMY1 = 4086832
  //ENEMY2 = 4086833
  //ENEMY3 = 4086834
  //EOBJECT0 = 2001456
  //EOBJECT1 = 2001457
  //EOBJECT2 = 2001458
  //EOBJECT3 = 2001459
  //EVENTRANGE0 = 4187339
  //EVENTRANGE1 = 4187340
  //EVENTRANGE2 = 4187344
  //EVENTRANGE3 = 4187347
  //EVENTACTIONPROCESSUPPERSHORT = 31
  //ITEM0 = 2000413
  //ITEM1 = 2000165
  //LOCACTOR0 = 1002033
  //LOCACTOR1 = 1002027
  //LOCACTOR2 = 1002044
  //LOCFACE0 = 604
  //LOCFACE1 = 605
  //LOCFACE2 = 617
  //LOCPOSCAM1 = 4072493
  //SEQ0ACTOR0LQ = 90

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00090: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=unknown
        break;
      }
      //seq 1 event item ITEM0 = UI8CL max stack 4
      case 1:
      {
        if( actor == 1003685 || actorId == 1003685 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=unknown
          }
        }
        if( actor == 4187339 || actorId == 4187339 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 2001456 || actorId == 2001456 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Message), id=unknown
            // +Callback Scene00005: Normal(None), id=unknown
          }
        }
        if( actor == 4086831 || actorId == 4086831 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4187340 || actorId == 4187340 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 2001457 || actorId == 2001457 ) // EOBJECT1 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(Message), id=unknown
          // +Callback Scene00008: Normal(None), id=unknown
        }
        if( actor == 4086832 || actorId == 4086832 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 4187344 || actorId == 4187344 ) // EVENTRANGE2 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 2001458 || actorId == 2001458 ) // EOBJECT2 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(Message), id=unknown
          // +Callback Scene00011: Normal(None), id=unknown
        }
        if( actor == 4086833 || actorId == 4086833 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 4187347 || actorId == 4187347 ) // EVENTRANGE3 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 2001459 || actorId == 2001459 ) // EOBJECT3 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(Message), id=unknown
          // +Callback Scene00014: Normal(None), id=unknown
        }
        if( actor == 4086834 || actorId == 4086834 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 4
      case 2:
      {
        Scene00015( player ); // Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=unknown
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack 1
      case 3:
      {
        Scene00017( player ); // Scene00017: Normal(Talk, FadeIn, TargetCanMove), id=unknown
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 1
      case 255:
      {
        Scene00018( player ); // Scene00018: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestUI8CL( getId(), 0 );
            player.updateQuest( getId(), 2 );
            player.setQuestUI8BH( getId(), 4 );
          }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 1 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00090( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00090( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling [BranchTrue]Scene00090: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 90, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling Scene00002: Normal(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling Scene00004: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling Scene00007: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling Scene00010: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling [BranchTrue]Scene00011: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling Scene00013: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling [BranchTrue]Scene00014: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00016( player );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling [BranchTrue]Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling Scene00017: Normal(Talk, FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling Scene00018: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00019( player );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "SubWil038:65766 calling [BranchTrue]Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil038 );
