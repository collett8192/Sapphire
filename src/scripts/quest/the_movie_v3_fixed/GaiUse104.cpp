// FFXIVTheMovie.ParserV3
//fix: bnpc id only
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse104 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse104() : Sapphire::ScriptAPI::EventScript( 66714 ){}; 
  ~GaiUse104() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 3 entries
  //SEQ_3, 5 entries
  //SEQ_4, 2 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1007739
  //ACTOR1 = 1007752
  //ACTOR2 = 1007764
  //ACTOR3 = 1006693
  //BNPCNAME0 = 688
  //CUTSCENEN01 = 435
  //ENEMY0 = 383
  //ENEMY1 = 4504670
  //EOBJECT0 = 2002842
  //EOBJECT1 = 2002843
  //EVENTACTIONPROCESSLONG = 17
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONWAITING3LONG = 13
  //ITEM0 = 2001072
  //ITEM1 = 2001073

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1007739 || actorId == 1007739 ) // ACTOR0 = FLHAMINN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FLHAMINN
        }
        if( actor == 1007752 || actorId == 1007752 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 3
      case 1:
      {
        if( actor == 383 || actorId == 642 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 1007752 || actorId == 1007752 ) // ACTOR1 = ALPHINAUD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1007739 || actorId == 1007739 ) // ACTOR0 = FLHAMINN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=FLHAMINN
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( actor == 2002842 || actorId == 2002842 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
            // +Callback Scene00006: Normal(None), id=unknown
          }
        }
        if( actor == 1007752 || actorId == 1007752 ) // ACTOR1 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1007739 || actorId == 1007739 ) // ACTOR0 = FLHAMINN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=FLHAMINN
        }
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack ?
      case 3:
      {
        if( actor == 2002843 || actorId == 2002843 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
            // +Callback Scene00010: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4504670 || actorId == 4504670 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 1007764 || actorId == 1007764 ) // ACTOR2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 1007752 || actorId == 1007752 ) // ACTOR1 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          // +Callback Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1007739 || actorId == 1007739 ) // ACTOR0 = FLHAMINN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=FLHAMINN
        }
        break;
      }
      //seq 4 event item ITEM1 = UI8BH max stack ?
      case 4:
      {
        if( actor == 1007739 || actorId == 1007739 ) // ACTOR0 = FLHAMINN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00016: Normal(Talk, TargetCanMove), id=FLHAMINN
          }
        }
        if( actor == 1007752 || actorId == 1007752 ) // ACTOR1 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 255:
      {
        if( actor == 1006693 || actorId == 1006693 ) // ACTOR3 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(CutScene), id=unknown
          // +Callback Scene00019: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( actor == 1007752 || actorId == 1007752 ) // ACTOR1 = ALPHINAUD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1007739 || actorId == 1007739 ) // ACTOR0 = FLHAMINN
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=FLHAMINN
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
    onProgress( player, 1, 1, 3, param1 );
  }

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 3 )
    {
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
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
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
    player.sendDebug( "GaiUse104:66714 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse104:66714 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00004: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00006: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00008: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00014: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse104:66714 calling Scene00016: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00018: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00019: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse104:66714 calling Scene00021: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse104 );
