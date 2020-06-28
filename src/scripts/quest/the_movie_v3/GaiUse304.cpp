// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse304 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse304() : Sapphire::ScriptAPI::EventScript( 66981 ){}; 
  ~GaiUse304() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 1 entries
  //SEQ_255, 2 entries

  //ACTIONTIMELINEEVENTBASEBADCHAIR = 825
  //ACTOR0 = 1004576
  //ACTOR1 = 1001657
  //ACTOR2 = 1009056
  //ACTOR3 = 1009175
  //CUTSCENEN01 = 572
  //EVENTACTIONSEARCH = 1
  //LOCACTOR0 = 1009692
  //LOCFACE0 = 617
  //LOCPOSACTOR0 = 4893408
  //LOCPOSACTOR1 = 4894197
  //LOCPOSACTOR2 = 4894775

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SWIFT
        break;
      }
      case 1:
      {
        if( actor == 1001657 || actorId == 1001657 ) // ACTOR1 = LANDEBERT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=LANDEBERT
          }
        }
        if( actor == 1004576 || actorId == 1004576 ) // ACTOR0 = SWIFT
        {
          Scene00003( player ); // Scene00003: Normal(TargetCanMove), id=unknown
          // +Callback Scene00004: Normal(Talk, TargetCanMove), id=SWIFT
        }
        break;
      }
      case 2:
      {
        if( actor == 1009056 || actorId == 1009056 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1004576 || actorId == 1004576 ) // ACTOR0 = SWIFT
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=SWIFT
        }
        if( actor == 1001657 || actorId == 1001657 ) // ACTOR1 = LANDEBERT
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LANDEBERT
        }
        break;
      }
      case 3:
      {
        Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=GUARDLEADER01445
        break;
      }
      case 255:
      {
        if( actor == 1004576 || actorId == 1004576 ) // ACTOR0 = SWIFT
        {
          Scene00009( player ); // Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SWIFT
        }
        if( actor == 1009175 || actorId == 1009175 ) // ACTOR3 = GUARDLEADER01445
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=GUARDLEADER01445
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
    if( player.getQuestUI8AL( getId() ) == 1 )
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
    player.sendDebug( "GaiUse304:66981 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse304:66981 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SWIFT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse304:66981 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=LANDEBERT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse304:66981 calling Scene00003: Normal(TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse304:66981 calling [BranchTrue]Scene00004: Normal(Talk, TargetCanMove), id=SWIFT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse304:66981 calling Scene00005: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse304:66981 calling Scene00006: Normal(Talk, TargetCanMove), id=SWIFT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse304:66981 calling Scene00007: Normal(Talk, TargetCanMove), id=LANDEBERT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse304:66981 calling Scene00008: Normal(Talk, TargetCanMove), id=GUARDLEADER01445" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse304:66981 calling Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SWIFT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse304:66981 calling Scene00010: Normal(Talk, TargetCanMove), id=GUARDLEADER01445" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse304 );