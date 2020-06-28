// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse207 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse207() : Sapphire::ScriptAPI::EventScript( 66887 ){}; 
  ~GaiUse207() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 3 entries
  //SEQ_4, 3 entries
  //SEQ_5, 3 entries
  //SEQ_255, 3 entries

  //ACTIONTIMELINEEVENTSING = 947
  //ACTIONTIMELINEEVENTTALKBIG = 948
  //ACTOR0 = 1008626
  //ACTOR1 = 1004096
  //ACTOR2 = 1008611
  //ACTOR3 = 1008632
  //ACTOR4 = 1008639
  //ACTOR5 = 1008638
  //ACTORSE0 = 48
  //EVENTACTIONPROCESSUPPERSHORT = 31
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001208
  //ITEM1 = 2001209
  //LEVELIDNPC01 = 4622201

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HOUZAN
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( actor == 1004096 || actorId == 1004096 ) // ACTOR1 = FOLCLIND
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=FOLCLIND
          }
        }
        if( actor == 1008626 || actorId == 1008626 ) // ACTOR0 = HOUZAN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=HOUZAN
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( actor == 1008611 || actorId == 1008611 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Inventory), id=unknown
            // +Callback Scene00005: Normal(TargetCanMove), id=unknown
          }
        }
        if( actor == 1008626 || actorId == 1008626 ) // ACTOR0 = HOUZAN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=HOUZAN
        }
        break;
      }
      case 3:
      {
        if( actor == 1008611 || actorId == 1008611 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
        }
        if( actor == 1008626 || actorId == 1008626 ) // ACTOR0 = HOUZAN
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          // +Callback Scene00009: Normal(Talk, TargetCanMove), id=HOUZAN
        }
        if( actor == 1008632 || actorId == 1008632 ) // ACTOR3 = GYOSHA01348
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=GYOSHA01348
        }
        break;
      }
      //seq 4 event item ITEM1 = UI8BH max stack 1
      case 4:
      {
        if( actor == 1008632 || actorId == 1008632 ) // ACTOR3 = GYOSHA01348
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=GYOSHA01348
          }
        }
        if( actor == 1008626 || actorId == 1008626 ) // ACTOR0 = HOUZAN
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=HOUZAN
        }
        if( actor == 1008611 || actorId == 1008611 ) // ACTOR2 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(TargetCanMove), id=unknown
        }
        break;
      }
      //seq 5 event item ITEM1 = UI8BH max stack 1
      case 5:
      {
        if( actor == 1008626 || actorId == 1008626 ) // ACTOR0 = HOUZAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=HOUZAN
          }
        }
        if( actor == 1008632 || actorId == 1008632 ) // ACTOR3 = GYOSHA01348
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=GYOSHA01348
        }
        if( actor == 1008611 || actorId == 1008611 ) // ACTOR2 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(TargetCanMove), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1008639 || actorId == 1008639 ) // ACTOR4 = HOUZAN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HOUZAN
        }
        if( actor == 1008638 || actorId == 1008638 ) // ACTOR5 = HOUMEI
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=HOUMEI
        }
        if( actor == 1008611 || actorId == 1008611 ) // ACTOR2 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(TargetCanMove), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse207:66887 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00002: Normal(Talk, TargetCanMove), id=FOLCLIND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00003: Normal(Talk, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling [BranchTrue]Scene00005: Normal(TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00006: Normal(Talk, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling [BranchTrue]Scene00009: Normal(Talk, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00010: Normal(Talk, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00011: Normal(Talk, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00012: Normal(Talk, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00013: Normal(TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00015( player );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling [BranchTrue]Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00016: Normal(Talk, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00017: Normal(TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00019: Normal(Talk, TargetCanMove), id=HOUMEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse207:66887 calling Scene00020: Normal(TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse207 );
