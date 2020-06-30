// FFXIVTheMovie.ParserV3
//fix: black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna402 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna402() : Sapphire::ScriptAPI::EventScript( 67174 ){}; 
  ~HeaVna402() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 4 entries
  //SEQ_2, 5 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1012751
  //ACTOR1 = 1012753
  //ACTOR10 = 1013332
  //ACTOR11 = 1013333
  //ACTOR2 = 1012754
  //ACTOR3 = 1012755
  //ACTOR4 = 1012752
  //ACTOR5 = 1013381
  //ACTOR6 = 1013128
  //ACTOR7 = 1013340
  //ACTOR8 = 1013341
  //ACTOR9 = 1013342
  //LOCACTOR0 = 5864612
  //LOCACTOR1 = 5864600
  //LOCACTOR2 = 5864601
  //LOCACTOR3 = 5864602
  //LOCACTOR4 = 5859640
  //LOCMUSIC0 = 317
  //POPRANGE0 = 5827750

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012751 || actorId == 1012751 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012753 || actorId == 1012753 ) // ACTOR1 = LUCIA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1012754 || actorId == 1012754 ) // ACTOR2 = HAURCHEFANT
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 1012755 || actorId == 1012755 ) // ACTOR3 = EDMONT
        {
          Scene00004( player ); // Scene00004: Normal(Talk), id=EDMONT
        }
        if( actor == 1012752 || actorId == 1012752 ) // ACTOR4 = ESTINIEN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        break;
      }
      case 1:
      {
        if( actor == 1013381 || actorId == 1013381 ) // ACTOR5 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=TATARU
          }
        }
        if( actor == 1013128 || actorId == 1013128 ) // ACTOR6 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012754 || actorId == 1012754 ) // ACTOR2 = HAURCHEFANT
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 1012755 || actorId == 1012755 ) // ACTOR3 = EDMONT
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=EDMONT
        }
        break;
      }
      case 2:
      {
        if( actor == 1013340 || actorId == 1013340 ) // ACTOR7 = THEPOORA01638
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=THEPOORA01638
            // +Callback Scene00011: Normal(Talk, TargetCanMove), id=THEPOORA01638
          }
        }
        if( actor == 1013341 || actorId == 1013341 ) // ACTOR8 = THEPOORB01638
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=THEPOORB01638
            // +Callback Scene00013: Normal(Talk, TargetCanMove), id=THEPOORB01638
          }
        }
        if( actor == 1013342 || actorId == 1013342 ) // ACTOR9 = THEPOORC01638
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=THEPOORC01638
            // +Callback Scene00015: Normal(Talk, TargetCanMove), id=THEPOORC01638
          }
        }
        if( actor == 1013332 || actorId == 1013332 ) // ACTOR10 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013333 || actorId == 1013333 ) // ACTOR11 = TATARU
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 255:
      {
        if( actor == 1013332 || actorId == 1013332 ) // ACTOR10 = ALPHINAUD
        {
          Scene00018( player ); // Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013340 || actorId == 1013340 ) // ACTOR7 = THEPOORA01638
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=THEPOORA01638
        }
        if( actor == 1013341 || actorId == 1013341 ) // ACTOR8 = THEPOORB01638
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=THEPOORB01638
        }
        if( actor == 1013342 || actorId == 1013342 ) // ACTOR9 = THEPOORC01638
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=THEPOORC01638
        }
        if( actor == 1013333 || actorId == 1013333 ) // ACTOR11 = TATARU
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=TATARU
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
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna402:67174 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.exitInstance();
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00002: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00003: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00004: Normal(Talk), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00008: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00009: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00010: Normal(Talk, TargetCanMove), id=THEPOORA01638" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling [BranchTrue]Scene00011: Normal(Talk, TargetCanMove), id=THEPOORA01638" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00012: Normal(Talk, TargetCanMove), id=THEPOORB01638" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling [BranchTrue]Scene00013: Normal(Talk, TargetCanMove), id=THEPOORB01638" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00014: Normal(Talk, TargetCanMove), id=THEPOORC01638" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling [BranchTrue]Scene00015: Normal(Talk, TargetCanMove), id=THEPOORC01638" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00017: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.sendDebug( "HeaVna402:67174 calling Scene00019: Normal(Talk, TargetCanMove), id=THEPOORA01638" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00020: Normal(Talk, TargetCanMove), id=THEPOORB01638" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00021: Normal(Talk, TargetCanMove), id=THEPOORC01638" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna402:67174 calling Scene00022: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna402 );
