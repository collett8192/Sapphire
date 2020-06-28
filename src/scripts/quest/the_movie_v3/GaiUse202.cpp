// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse202 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse202() : Sapphire::ScriptAPI::EventScript( 66882 ){}; 
  ~GaiUse202() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 8 entries
  //SEQ_3, 3 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1008597
  //ACTOR1 = 1008702
  //ACTOR2 = 1002058
  //ACTOR3 = 1008598
  //ACTOR4 = 1008599
  //ENEMY0 = 4620255
  //ENEMY1 = 4620256
  //ENEMY2 = 4620257
  //ENEMY3 = 4620258
  //EOBJECT0 = 2003561
  //EOBJECT1 = 2003562
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONSEARCHSHORT = 2
  //EVENTACTIONWATCHGUARDLONG = 28
  //LOCACTION1 = 1002
  //LOCACTIOR0 = 1008176
  //LOCACTIOR1 = 1008177
  //LOCFACE0 = 605
  //LOCFACE1 = 604
  //LOCFACE2 = 619
  //LOCSE1 = 42

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1008597 || actorId == 1008597 ) // ACTOR0 = THANCRED
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=THANCRED
        }
        if( actor == 1008702 || actorId == 1008702 ) // ACTOR1 = YSHTOLA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 1:
      {
        if( actor == 1002058 || actorId == 1002058 ) // ACTOR2 = FUFULUPA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=FUFULUPA
          }
        }
        if( actor == 1008597 || actorId == 1008597 ) // ACTOR0 = THANCRED
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1008702 || actorId == 1008702 ) // ACTOR1 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 2:
      {
        if( actor == 2003561 || actorId == 2003561 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
            // +Callback Scene00007: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4620255 || actorId == 4620255 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4620256 || actorId == 4620256 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 4620257 || actorId == 4620257 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 4620258 || actorId == 4620258 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( actor == 1008598 || actorId == 1008598 ) // ACTOR3 = YSHTOLA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1008599 || actorId == 1008599 ) // ACTOR4 = THANCRED
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 2003562 || actorId == 2003562 ) // EOBJECT1 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( actor == 1008598 || actorId == 1008598 ) // ACTOR3 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=YSHTOLA
          }
        }
        if( actor == 1008599 || actorId == 1008599 ) // ACTOR4 = THANCRED
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 2003562 || actorId == 2003562 ) // EOBJECT1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1002058 || actorId == 1002058 ) // ACTOR2 = FUFULUPA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=FUFULUPA
        }
        if( actor == 1008597 || actorId == 1008597 ) // ACTOR0 = THANCRED
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=THANCRED
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
    if( player.getQuestUI8AL( getId() ) == 4 )
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse202:66882 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=FUFULUPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00004: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling [BranchTrue]Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 4 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00009: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00012: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00014: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=FUFULUPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse202:66882 calling Scene00015: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse202 );
