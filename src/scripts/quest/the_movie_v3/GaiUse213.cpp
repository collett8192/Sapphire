// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse213 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse213() : Sapphire::ScriptAPI::EventScript( 66893 ){}; 
  ~GaiUse213() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 10 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006614
  //ACTOR1 = 1006616
  //ENEMY0 = 4628559
  //ENEMY1 = 4628560
  //ENEMY2 = 4628566
  //ENEMY3 = 4628567
  //ENEMY4 = 4628568
  //EOBJECT0 = 2003588
  //EOBJECT1 = 2003589
  //EOBJECT2 = 2003585
  //EOBJECT3 = 2003586
  //EOBJECT4 = 2003587
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001213

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FALKBRYDA
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( actor == 1006616 || actorId == 1006616 ) // ACTOR1 = UJUGHAL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=UJUGHAL
          }
        }
        if( actor == 1006614 || actorId == 1006614 ) // ACTOR0 = FALKBRYDA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=FALKBRYDA
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8DH max stack ?
      case 2:
      {
        if( actor == 2003588 || actorId == 2003588 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Inventory), id=unknown
            // +Callback Scene00005: Normal(QuestGimmickReaction), id=unknown
          }
        }
        if( actor == 2003589 || actorId == 2003589 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Inventory), id=unknown
            // +Callback Scene00007: Normal(QuestGimmickReaction), id=unknown
          }
        }
        if( actor == 2003585 || actorId == 2003585 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 2 )
          {
            Scene00008( player ); // Scene00008: Normal(Inventory), id=unknown
            // +Callback Scene00009: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown
          }
        }
        if( actor == 4628559 || actorId == 4628559 ) // ENEMY0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          // +Callback Scene00011: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 4628560 || actorId == 4628560 ) // ENEMY1 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          // +Callback Scene00013: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 2003586 || actorId == 2003586 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Inventory), id=unknown
            // +Callback Scene00015: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown
          }
        }
        if( actor == 4628566 || actorId == 4628566 ) // ENEMY2 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          // +Callback Scene00017: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 2003587 || actorId == 2003587 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 2 )
          {
            Scene00018( player ); // Scene00018: Normal(Inventory), id=unknown
            // +Callback Scene00019: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown
          }
        }
        if( actor == 4628567 || actorId == 4628567 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( actor == 4628568 || actorId == 4628568 ) // ENEMY4 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          // +Callback Scene00021: Normal(Message, PopBNpc), id=unknown
        }
        break;
      }
      case 255:
      {
        Scene00022( player ); // Scene00022: Normal(None), id=unknown
        // +Callback Scene00023: Normal(Message, PopBNpc), id=unknown
        // +Callback Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FALKBRYDA
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
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8CH( getId() ) == 2 )
          if( player.getQuestUI8BL( getId() ) == 1 )
            if( player.getQuestUI8CL( getId() ) == 2 )
            {
              player.setQuestUI8BH( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8CH( getId(), 0 );
              player.setQuestUI8BL( getId(), 0 );
              player.setQuestUI8CL( getId(), 0 );
              player.setQuestUI8DH( getId(), 0 );
              player.updateQuest( getId(), 255 );
            }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse213:66893 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling Scene00002: Normal(Talk, TargetCanMove), id=UJUGHAL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling Scene00003: Normal(Talk, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling [BranchTrue]Scene00005: Normal(QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling Scene00006: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling [BranchTrue]Scene00007: Normal(QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling Scene00008: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling [BranchTrue]Scene00009: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling [BranchTrue]Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling [BranchTrue]Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling Scene00014: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling [BranchTrue]Scene00015: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling Scene00016: Normal(None), id=unknown" );
    Scene00017( player );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling [BranchTrue]Scene00017: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling Scene00018: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling [BranchTrue]Scene00019: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling Scene00020: Normal(None), id=unknown" );
    Scene00021( player );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling [BranchTrue]Scene00021: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling Scene00022: Normal(None), id=unknown" );
    Scene00023( player );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling [BranchTrue]Scene00023: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00024( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse213:66893 calling [BranchChain]Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 24, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse213 );
