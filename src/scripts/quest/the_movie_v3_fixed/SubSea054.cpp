// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea054 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea054() : Sapphire::ScriptAPI::EventScript( 66002 ){}; 
  ~SubSea054() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 9 entries
  //SEQ_3, 2 entries
  //SEQ_4, 2 entries
  //SEQ_5, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002626
  //ACTOR1 = 1002640
  //ACTOR2 = 1002641
  //ACTOR3 = 1002642
  //ACTOR4 = 1002643
  //ACTOR5 = 1002630
  //ENEMY0 = 3931777
  //ENEMY1 = 3931779
  //EOBJECT0 = 2001279
  //EOBJECT1 = 2000451
  //EOBJECT2 = 2000449
  //EVENTRANGE0 = 3929588
  //EVENTACTION = 35
  //EVENTACTIONPROCESSMIDDLE = 16
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000356
  //ITEM1 = 2000357

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=STAELWYRN
        break;
      }
      case 1:
      {
        if( actor == 1002640 || actorId == 1002640 ) // ACTOR1 = SEVRIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=SEVRIN
            // +Callback Scene00002: Normal(Talk, TargetCanMove), id=SEVRIN
          }
        }
        if( actor == 2001279 || actorId == 2001279 ) // EOBJECT0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          // +Callback Scene00004: Normal(None), id=unknown
          // +Callback Scene00005: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 1002641 || actorId == 1002641 ) // ACTOR2 = AYLMER
        {
          Scene00008( player ); // Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=AYLMER
        }
        if( actor == 1002642 || actorId == 1002642 ) // ACTOR3 = EYRIMHUS
        {
          Scene00011( player ); // Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=EYRIMHUS
        }
        if( actor == 1002643 || actorId == 1002643 ) // ACTOR4 = SOZAIRARZAI
        {
          Scene00014( player ); // Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=SOZAIRARZAI
        }
        if( actor == 3929588 || actorId == 3929588 ) // EVENTRANGE0 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( actor == 3931777 || actorId == 3931777 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 3931779 || actorId == 3931779 ) // ENEMY1 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 1002640 || actorId == 1002640 ) // ACTOR1 = SEVRIN
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          // +Callback Scene00018: Normal(Talk, TargetCanMove), id=SEVRIN
        }
        if( actor == 2001279 || actorId == 2001279 ) // EOBJECT0 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          // +Callback Scene00020: Normal(None), id=unknown
        }
        if( actor == 2000451 || actorId == 2000451 ) // EOBJECT1 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          // +Callback Scene00022: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( actor == 1002640 || actorId == 1002640 ) // ACTOR1 = SEVRIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(None), id=unknown
            // +Callback Scene00024: Normal(Talk, NpcDespawn, TargetCanMove), id=SEVRIN
          }
        }
        if( actor == 2001279 || actorId == 2001279 ) // EOBJECT0 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          // +Callback Scene00026: Normal(None), id=unknown
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( actor == 2001279 || actorId == 2001279 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(None), id=unknown
            // +Callback Scene00028: Normal(None), id=unknown
          }
          else
          {
            Scene00029( player ); // Scene00029: Normal(None), id=unknown
          }
        }
        if( actor == 2000449 || actorId == 2000449 ) // EOBJECT2 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          // +Callback Scene00031: Normal(None), id=unknown
          // +Callback Scene00032: Normal(None), id=unknown
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 1
      //seq 5 event item ITEM1 = UI8BL max stack 1
      case 5:
      {
        Scene00033( player ); // Scene00033: NpcTrade(Talk, TargetCanMove), id=OSSINE
        // +Callback Scene00034: Normal(Talk, TargetCanMove), id=OSSINE
        // +Callback Scene00035: Normal(None), id=unknown
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      case 255:
      {
        Scene00036( player ); // Scene00036: NpcTrade(Talk, TargetCanMove), id=STAELWYRN
        // +Callback Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=STAELWYRN
        // +Callback Scene00038: Normal(None), id=unknown
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
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
    player.setQuestUI8BH( getId(), 1 );
    player.setQuestUI8BL( getId(), 1 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=STAELWYRN" );
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
    player.sendDebug( "SubSea054:66002 calling Scene00001: Normal(Talk, TargetCanMove), id=SEVRIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchTrue]Scene00002: Normal(Talk, TargetCanMove), id=SEVRIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00003: Normal(None), id=unknown" );
    Scene00004( player );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchTrue]Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchChain]Scene00005: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=AYLMER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=EYRIMHUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00013: Normal(None), id=unknown" );
    Scene00014( player );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=SOZAIRARZAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00016: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00017: Normal(None), id=unknown" );
    Scene00018( player );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchTrue]Scene00018: Normal(Talk, TargetCanMove), id=SEVRIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00019: Normal(None), id=unknown" );
    Scene00020( player );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchTrue]Scene00020: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00021: Normal(None), id=unknown" );
    Scene00022( player );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchTrue]Scene00022: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00023: Normal(None), id=unknown" );
    Scene00024( player );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchTrue]Scene00024: Normal(Talk, NpcDespawn, TargetCanMove), id=SEVRIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00025: Normal(None), id=unknown" );
    Scene00026( player );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchTrue]Scene00026: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00027: Normal(None), id=unknown" );
    Scene00028( player );
  }
  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchTrue]Scene00028: Normal(None), id=unknown" );
    Scene00029( player );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchFalse]Scene00029: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00030: Normal(None), id=unknown" );
    Scene00031( player );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchTrue]Scene00031: Normal(None), id=unknown" );
    Scene00032( player );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchChain]Scene00032: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00033: NpcTrade(Talk, TargetCanMove), id=OSSINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00034( player );
      }
    };
    player.playScene( getId(), 33, NONE, callback );
  }
  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchTrue]Scene00034: Normal(Talk, TargetCanMove), id=OSSINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00035( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchChain]Scene00035: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling Scene00036: NpcTrade(Talk, TargetCanMove), id=STAELWYRN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00037( player );
      }
    };
    player.playScene( getId(), 36, NONE, callback );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchTrue]Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=STAELWYRN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00038( player );
      }
    };
    player.playScene( getId(), 37, NONE, callback );
  }
  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "SubSea054:66002 calling [BranchChain]Scene00038: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 38, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea054 );
