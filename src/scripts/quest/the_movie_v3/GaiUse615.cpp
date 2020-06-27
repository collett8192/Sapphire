// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse615 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse615() : Sapphire::ScriptAPI::EventScript( 65963 ){}; 
  ~GaiUse615() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 2 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1001353
  //ACTOR1 = 1010997
  //ACTOR2 = 1001821
  //ACTOR3 = 1010998
  //ACTOR4 = 1011622
  //ACTOR5 = 1006384
  //ACTOR6 = 1010928
  //ACTOR7 = 1006401
  //CUTSCENEN01 = 713
  //CUTSCENEN02 = 714
  //CUTSCENEN03 = 715
  //CUTSCENEN04 = 716
  //CUTSCENEN05 = 717
  //CUTSCENEN06 = 718
  //CUTSCENEN07 = 719
  //CUTSCENEN08 = 720
  //CUTSCENEN09 = 721
  //CUTSCENEN10 = 722
  //CUTSCENEN11 = 723
  //CUTSCENEN12 = 724
  //CUTSCENEN13 = 783
  //CUTSCENEN14 = 725
  //CUTSCENEN15 = 726
  //CUTSCENEN16 = 727
  //CUTSCENEN17 = 728
  //CUTSCENEN18 = 729
  //CUTSCENEN19 = 750
  //CUTSCENEN20 = 751
  //CUTSCENEN21 = 752
  //CUTSCENEN22 = 784
  //LOCACTOR0 = 5608520
  //LOCACTOR1 = 1003855
  //LOCBGM0 = 211
  //POPRANGE0 = 5608625
  //POPRANGE1 = 5608535

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MOMODI
        // +Callback Scene00002: Normal(CutScene), id=unknown
        break;
      }
      case 1:
      {
        if( actor == 1010997 || actorId == 1010997 ) // ACTOR1 = LADYINWAITING00427
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, YesNo, TargetCanMove), id=LADYINWAITING00427
            // +Callback Scene00004: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1001353 || actorId == 1001353 ) // ACTOR0 = MOMODI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MOMODI
        }
        if( actor == 1001821 || actorId == 1001821 ) // ACTOR2 = BARTHOLOMEW
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=BARTHOLOMEW
        }
        break;
      }
      case 2:
      {
        if( actor == 1010998 || actorId == 1010998 ) // ACTOR3 = PIPPIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=PIPPIN
            // +Callback Scene00008: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1011622 || actorId == 1011622 ) // ACTOR4 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 255:
      {
        if( actor == 1006384 || actorId == 1006384 ) // ACTOR5 = HAURCHEFANT
        {
          Scene00010( player ); // Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 1010928 || actorId == 1010928 ) // ACTOR6 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1006401 || actorId == 1006401 ) // ACTOR7 = YAELLE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YAELLE
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse615:65963 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse615:65963 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MOMODI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse615:65963 calling [BranchChain]Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse615:65963 calling Scene00003: Normal(Talk, YesNo, TargetCanMove), id=LADYINWAITING00427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 != 50 )
      {
        Scene00004( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse615:65963 calling [BranchTrue]Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse615:65963 calling Scene00005: Normal(Talk, TargetCanMove), id=MOMODI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse615:65963 calling Scene00006: Normal(Talk, TargetCanMove), id=BARTHOLOMEW" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse615:65963 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=PIPPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse615:65963 calling [BranchTrue]Scene00008: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse615:65963 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse615:65963 calling Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse615:65963 calling Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse615:65963 calling Scene00012: Normal(Talk, TargetCanMove), id=YAELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse615 );
