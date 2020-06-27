// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse502 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse502() : Sapphire::ScriptAPI::EventScript( 65900 ){}; 
  ~GaiUse502() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 1 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1010845
  //ACTOR1 = 1010923
  //ACTOR2 = 1010846
  //ACTOR3 = 1010847
  //ACTOR4 = 1010849
  //ACTOR5 = 1010848
  //ENEMY0 = 5589283
  //ENEMY1 = 5589284
  //ENEMY2 = 5589285
  //ENEMY3 = 5589286
  //EOBJECT0 = 2005112
  //EOBJECT1 = 2005107
  //EVENTACTIONWAITING2MIDDLE = 12
  //LOCACTOR0 = 5580509
  //LOCACTOR1 = 1010849
  //LOCACTOR2 = 1010848
  //LOCACTOR3 = 5580514
  //LOCEOBJECT0 = 2005125
  //LOCMOTION0 = 1045

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1010845 || actorId == 1010845 ) // ACTOR0 = ILBERD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ILBERD
        }
        if( actor == 1010923 || actorId == 1010923 ) // ACTOR1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(None), id=unknown
        }
        break;
      }
      case 1:
      {
        Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=ILBERD
        break;
      }
      case 2:
      {
        if( actor == 1010847 || actorId == 1010847 ) // ACTOR3 = SENTRY00364
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=SENTRY00364
          }
        }
        if( actor == 5589283 || actorId == 5589283 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 5589284 || actorId == 5589284 ) // ENEMY1 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 5589285 || actorId == 5589285 ) // ENEMY2 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 5589286 || actorId == 5589286 ) // ENEMY3 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
        }
        break;
      }
      case 3:
      {
        Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
        // +Callback Scene00009: Normal(Message, PopBNpc), id=unknown
        // +Callback Scene00010: Normal(None), id=unknown
        break;
      }
      case 255:
      {
        if( actor == 1010849 || actorId == 1010849 ) // ACTOR4 = ILBERD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, FadeIn, QuestGimmickReaction), id=unknown
          // +Callback Scene00012: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ILBERD
        }
        if( actor == 2005107 || actorId == 2005107 ) // EOBJECT1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 1010848 || actorId == 1010848 ) // ACTOR5 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 4 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse502:65900 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling Scene00002: Normal(None), id=unknown" );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling Scene00004: Normal(Talk, TargetCanMove), id=SENTRY00364" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 4 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling [BranchTrue]Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling [BranchChain]Scene00010: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling Scene00011: Normal(Talk, FadeIn, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling [BranchTrue]Scene00012: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse502:65900 calling Scene00014: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUse502 );
