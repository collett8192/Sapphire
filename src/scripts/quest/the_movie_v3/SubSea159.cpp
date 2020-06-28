// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea159 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea159() : Sapphire::ScriptAPI::EventScript( 66962 ){}; 
  ~SubSea159() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 9 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1003505
  //ACTOR1 = 1007960
  //ACTOR2 = 1007961
  //ACTOR3 = 1007962
  //ACTOR4 = 1007797
  //ACTOR5 = 1007959
  //ACTOR6 = 1007976
  //ACTOR7 = 1007975
  //ACTOR8 = 1007977
  //ACTOR9 = 1007796
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001250
  //LOCACTOR0 = 1007978
  //LOCACTOR1 = 1007989
  //LOCACTOR2 = 1007986
  //LOCACTOR3 = 1007987
  //LOCACTOR4 = 1007988
  //LOCBGM = 88
  //LOCFACE0 = 604
  //LOCFACE1 = 608
  //LOCFACE2 = 617
  //LOCMOTION1 = 873
  //LOCMOTION2 = 570
  //LOCPOSACTOR0 = 4660295

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=DODOZAN
        // +Callback Scene00001: Normal(QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        if( actor == 1007960 || actorId == 1007960 ) // ACTOR1 = MERCHANT01426
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MERCHANT01426
            // +Callback Scene00003: Normal(Talk, TargetCanMove), id=MERCHANT01426
          }
        }
        if( actor == 1007961 || actorId == 1007961 ) // ACTOR2 = DELIVERYMAN01426
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=DELIVERYMAN01426
            // +Callback Scene00005: Normal(Talk, TargetCanMove), id=DELIVERYMAN01426
          }
        }
        if( actor == 1007962 || actorId == 1007962 ) // ACTOR3 = FISHWOMAN01426
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=FISHWOMAN01426
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=FISHWOMAN01426
          }
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( actor == 1007797 || actorId == 1007797 ) // ACTOR4 = STAFF01426
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=STAFF01426
          }
        }
        if( actor == 1007959 || actorId == 1007959 ) // ACTOR5 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1007976 || actorId == 1007976 ) // ACTOR6 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( actor == 1007975 || actorId == 1007975 ) // ACTOR7 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 1007977 || actorId == 1007977 ) // ACTOR8 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( actor == 1007796 || actorId == 1007796 ) // ACTOR9 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 1007960 || actorId == 1007960 ) // ACTOR1 = MERCHANT01426
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=MERCHANT01426
        }
        if( actor == 1007961 || actorId == 1007961 ) // ACTOR2 = DELIVERYMAN01426
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=DELIVERYMAN01426
        }
        if( actor == 1007962 || actorId == 1007962 ) // ACTOR3 = FISHWOMAN01426
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=FISHWOMAN01426
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        Scene00017( player ); // Scene00017: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=DODOZAN
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
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
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
    player.sendDebug( "SubSea159:66962 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=DODOZAN" );
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
    player.sendDebug( "SubSea159:66962 calling [BranchTrue]Scene00001: Normal(QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling Scene00002: Normal(Talk, TargetCanMove), id=MERCHANT01426" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling [BranchTrue]Scene00003: Normal(Talk, TargetCanMove), id=MERCHANT01426" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling Scene00004: Normal(Talk, TargetCanMove), id=DELIVERYMAN01426" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling [BranchTrue]Scene00005: Normal(Talk, TargetCanMove), id=DELIVERYMAN01426" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling Scene00006: Normal(Talk, TargetCanMove), id=FISHWOMAN01426" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling [BranchTrue]Scene00007: Normal(Talk, TargetCanMove), id=FISHWOMAN01426" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=STAFF01426" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling Scene00014: Normal(Talk, TargetCanMove), id=MERCHANT01426" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling Scene00015: Normal(Talk, TargetCanMove), id=DELIVERYMAN01426" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling Scene00016: Normal(Talk, TargetCanMove), id=FISHWOMAN01426" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling Scene00017: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00018( player );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubSea159:66962 calling [BranchTrue]Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=DODOZAN" );
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
};

EXPOSE_SCRIPT( SubSea159 );
