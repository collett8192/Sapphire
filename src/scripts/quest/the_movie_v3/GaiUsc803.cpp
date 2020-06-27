// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc803 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc803() : Sapphire::ScriptAPI::EventScript( 66563 ){}; 
  ~GaiUsc803() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 7 entries
  //SEQ_3, 5 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1006618
  //ACTOR1 = 1006621
  //ACTOR2 = 1006619
  //ACTOR3 = 1006624
  //ACTOR4 = 1006632
  //ACTOR5 = 1006631
  //ACTOR6 = 1006614
  //ENEMY0 = 4308997
  //ENEMY1 = 4308998
  //ENEMY2 = 4308999
  //EOBJECT0 = 2002577
  //EOBJECT1 = 2002454
  //EOBJECT2 = 2002632
  //EVENTACTIONSEARCH = 1
  //LOCACTION0 = 961
  //LOCACTOR0 = 1007644

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URURUKOGURURU
        break;
      }
      case 1:
      {
        if( actor == 1006621 || actorId == 1006621 ) // ACTOR1 = DAWSON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=DAWSON
          }
        }
        if( actor == 2002577 || actorId == 2002577 ) // EOBJECT0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          // +Callback Scene00004: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 2002454 || actorId == 2002454 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4308997 || actorId == 4308997 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4308998 || actorId == 4308998 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 4308999 || actorId == 4308999 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 1006621 || actorId == 1006621 ) // ACTOR1 = DAWSON
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=DAWSON
        }
        if( actor == 2002577 || actorId == 2002577 ) // EOBJECT0 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          // +Callback Scene00008: Normal(None), id=unknown
        }
        if( actor == 2002632 || actorId == 2002632 ) // EOBJECT2 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( actor == 1006619 || actorId == 1006619 ) // ACTOR2 = DAWSON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=DAWSON
          }
        }
        if( actor == 1006624 || actorId == 1006624 ) // ACTOR3 = NPCB
        {
          Scene00011( player ); // Scene00011: Normal(Talk), id=NPCB
        }
        if( actor == 1006632 || actorId == 1006632 ) // ACTOR4 = NPCC
        {
          Scene00012( player ); // Scene00012: Normal(Talk), id=NPCC
        }
        if( actor == 1006631 || actorId == 1006631 ) // ACTOR5 = NPCD
        {
          Scene00013( player ); // Scene00013: Normal(Talk), id=NPCD
        }
        if( actor == 2002632 || actorId == 2002632 ) // EOBJECT2 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          // +Callback Scene00015: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1006614 || actorId == 1006614 ) // ACTOR6 = FALKBRYDA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FALKBRYDA
        }
        if( actor == 1006619 || actorId == 1006619 ) // ACTOR2 = DAWSON
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=DAWSON
        }
        if( actor == 1006624 || actorId == 1006624 ) // ACTOR3 = NPCB
        {
          Scene00018( player ); // Scene00018: Normal(Talk), id=NPCB
        }
        if( actor == 1006632 || actorId == 1006632 ) // ACTOR4 = NPCC
        {
          Scene00019( player ); // Scene00019: Normal(Talk), id=NPCC
        }
        if( actor == 1006631 || actorId == 1006631 ) // ACTOR5 = NPCD
        {
          Scene00020( player ); // Scene00020: Normal(Talk), id=NPCD
        }
        if( actor == 2002632 || actorId == 2002632 ) // EOBJECT2 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          // +Callback Scene00022: Normal(None), id=unknown
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc803:66563 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URURUKOGURURU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00003: Normal(None), id=unknown" );
    Scene00004( player );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling [BranchTrue]Scene00004: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00006: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00010: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00011: Normal(Talk), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00012: Normal(Talk), id=NPCC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00013: Normal(Talk), id=NPCD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00014: Normal(None), id=unknown" );
    Scene00015( player );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling [BranchTrue]Scene00015: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00017: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00018: Normal(Talk), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00019: Normal(Talk), id=NPCC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00020: Normal(Talk), id=NPCD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling Scene00021: Normal(None), id=unknown" );
    Scene00022( player );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc803:66563 calling [BranchTrue]Scene00022: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsc803 );
