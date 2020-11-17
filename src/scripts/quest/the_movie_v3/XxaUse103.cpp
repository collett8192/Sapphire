// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class XxaUse103 : public Sapphire::ScriptAPI::EventScript
{
public:
  XxaUse103() : Sapphire::ScriptAPI::EventScript( 69410 ){}; 
  ~XxaUse103() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 2 entries
  //SEQ_4, 1 entries
  //SEQ_5, 5 entries
  //SEQ_6, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006693
  //ACTOR1 = 1007722
  //ACTOR2 = 1006273
  //ACTOR3 = 1032973
  //ACTOR4 = 1006309
  //ACTOR5 = 1006306
  //ACTOR6 = 1006305
  //ACTOR7 = 1007738
  //ACTOR8 = 1007752
  //ACTOR9 = 1007739
  //BINDACTOR0 = 8308401
  //ENEMY0 = 4500980
  //EOBJECT0 = 2002841
  //EVENTRANGE0 = 8308399
  //LOCACTOR0 = 1007768
  //LOCPOSACTOR0 = 4520606
  //LOCPOSACTOR1 = 4520834
  //QSTACCEPTCHECK01 = 66712
  //QSTACCEPTCHECK02 = 66713

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 2:
      {
        if( param1 == 1006273 || param2 == 1006273 ) // ACTOR2 = GEGERUJU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=GEGERUJU
          }
          break;
        }
        if( param1 == 1032973 || param2 == 1032973 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1006309 || param2 == 1006309 ) // ACTOR4 = JUNGHBHAR
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=JUNGHBHAR
          }
          break;
        }
        if( param1 == 1006306 || param2 == 1006306 ) // ACTOR5 = BYRGLAENT
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=BYRGLAENT
          }
          break;
        }
        break;
      }
      case 4:
      {
        Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
        break;
      }
      case 5:
      {
        if( param1 == 8308399 || param2 == 8308399 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4500980 || param2 == 4500980 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 1007738 || param2 == 1007738 ) // ACTOR7 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(Message), id=unknown
          break;
        }
        if( param1 == 2002841 || param2 == 2002841 ) // EOBJECT0 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006305 || param2 == 1006305 ) // ACTOR6 = SHAMANILOHMANI
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
          break;
        }
        break;
      }
      case 6:
      {
        Scene00013( player ); // Scene00013: Normal(Talk, FadeIn, TargetCanMove), id=FLHAMINN
        break;
      }
      case 255:
      {
        if( param1 == 1007752 || param2 == 1007752 ) // ACTOR8 = ALPHINAUD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1007739 || param2 == 1007739 ) // ACTOR9 = FLHAMINN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=FLHAMINN
          break;
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
    onProgress( player, param1, param1, 3, 0 );
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
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown" );
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
    player.sendDebug( "XxaUse103:69410 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00003: Normal(Talk, TargetCanMove), id=GEGERUJU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00005: Normal(Talk, TargetCanMove), id=JUNGHBHAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00006: Normal(Talk, TargetCanMove), id=BYRGLAENT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00007: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00010: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00012: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00013: Normal(Talk, FadeIn, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "XxaUse103:69410 calling Scene00015: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( XxaUse103 );
