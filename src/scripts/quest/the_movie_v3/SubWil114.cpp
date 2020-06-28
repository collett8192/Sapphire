// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil114 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil114() : Sapphire::ScriptAPI::EventScript( 66158 ){}; 
  ~SubWil114() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 1 entries
  //SEQ_4, 4 entries
  //SEQ_5, 4 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1003929
  //ACTOR1 = 1003977
  //ACTOR2 = 1004323
  //ACTOR3 = 1003978
  //ACTOR4 = 1004340
  //ACTOR5 = 1004341
  //EOBJECT0 = 2001410
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000390

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ISEMBARD
        break;
      }
      case 1:
      {
        Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=THANCRED
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( actor == 2001410 || actorId == 2001410 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
            // +Callback Scene00003: Normal(None), id=unknown
          }
        }
        if( actor == 1003977 || actorId == 1003977 ) // ACTOR1 = THANCRED
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          // +Callback Scene00005: Normal(Talk, TargetCanMove), id=THANCRED
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        Scene00006( player ); // Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( actor == 1004323 || actorId == 1004323 ) // ACTOR2 = OURCEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=OURCEN
          }
        }
        if( actor == 1003978 || actorId == 1003978 ) // ACTOR3 = THANCRED
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1004340 || actorId == 1004340 ) // ACTOR4 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 1004341 || actorId == 1004341 ) // ACTOR5 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 1
      case 5:
      {
        if( actor == 1003978 || actorId == 1003978 ) // ACTOR3 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED
          }
        }
        if( actor == 1004323 || actorId == 1004323 ) // ACTOR2 = OURCEN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=OURCEN
        }
        if( actor == 1004340 || actorId == 1004340 ) // ACTOR4 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( actor == 1004341 || actorId == 1004341 ) // ACTOR5 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( actor == 1003929 || actorId == 1003929 ) // ACTOR0 = ISEMBARD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ISEMBARD
        }
        if( actor == 1004323 || actorId == 1004323 ) // ACTOR2 = OURCEN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=OURCEN
        }
        if( actor == 1004340 || actorId == 1004340 ) // ACTOR4 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( actor == 1004341 || actorId == 1004341 ) // ACTOR5 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ISEMBARD" );
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
    player.sendDebug( "SubWil114:66158 calling Scene00001: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00002: Normal(None), id=unknown" );
    Scene00003( player );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling [BranchTrue]Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling [BranchTrue]Scene00005: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown" );
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
    player.sendDebug( "SubWil114:66158 calling [BranchTrue]Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00008: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00009( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling [BranchTrue]Scene00009: Normal(Talk, TargetCanMove), id=OURCEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00010: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00014: Normal(Talk, TargetCanMove), id=OURCEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ISEMBARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00018: Normal(Talk, TargetCanMove), id=OURCEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "SubWil114:66158 calling Scene00020: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubWil114 );
