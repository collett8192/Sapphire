// FFXIVTheMovie.ParserV3
//fix: black screen, skip quest battle
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna403 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna403() : Sapphire::ScriptAPI::EventScript( 67175 ){}; 
  ~HeaVna403() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 5 entries
  //SEQ_4, 6 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1013260
  //ACTOR1 = 1013228
  //ACTOR10 = 1012775
  //ACTOR11 = 1012774
  //ACTOR12 = 1012780
  //ACTOR13 = 1012781
  //ACTOR14 = 1012782
  //ACTOR15 = 1012776
  //ACTOR16 = 1012777
  //ACTOR17 = 1012778
  //ACTOR18 = 1012779
  //ACTOR2 = 1012768
  //ACTOR3 = 1012769
  //ACTOR4 = 1012770
  //ACTOR5 = 1014653
  //ACTOR6 = 1014654
  //ACTOR7 = 1012773
  //ACTOR8 = 1012771
  //ACTOR9 = 1012772
  //CUTSCENEN01 = 853
  //CUTSCENEN02 = 854
  //CUTSCENEN03 = 855
  //EOBJECT0 = 2005551
  //EOBJECT1 = 2005550
  //EOBJECT2 = 2005763
  //EVENTACTIONLOOKOUTMIDDLE = 50
  //LOCACTOR0 = 5913112
  //LOCACTOR1 = 5913113
  //LOCACTOR10 = 5864726
  //LOCACTOR11 = 5864729
  //LOCACTOR12 = 5864731
  //LOCACTOR13 = 5864732
  //LOCACTOR14 = 5864735
  //LOCACTOR15 = 5864736
  //LOCACTOR2 = 5913110
  //LOCACTOR20 = 1012453
  //LOCACTOR21 = 1012434
  //LOCACTOR22 = 1012433
  //LOCACTOR23 = 5865258
  //LOCACTOR24 = 1011887
  //LOCACTOR3 = 5913111
  //LOCMUSIC0 = 117
  //LOCMUSIC1 = 313
  //LOCQUEST0 = 67232
  //POPRANGE0 = 5913118
  //QUESTBATTLE0 = 109
  //TERRITORYTYPE0 = 458

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( actor == 2005551 || actorId == 2005551 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
            // +Callback Scene00003: Normal(None), id=unknown
          }
        }
        if( actor == 1013228 || actorId == 1013228 ) // ACTOR1 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 2:
      {
        if( actor == 2005550 || actorId == 2005550 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
            // +Callback Scene00006: Normal(Talk, CutScene, FadeIn, QuestGimmickReaction), id=unknown
          }
        }
        if( actor == 1013228 || actorId == 1013228 ) // ACTOR1 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          // +Callback Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 3:
      {
        if( actor == 1012768 || actorId == 1012768 ) // ACTOR2 = HILDA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=HILDA
          }
        }
        if( actor == 1012769 || actorId == 1012769 ) // ACTOR3 = REVOLUTIONARY1
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1
        }
        if( actor == 1012770 || actorId == 1012770 ) // ACTOR4 = REVOLUTIONARY2
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2
        }
        if( actor == 1014653 || actorId == 1014653 ) // ACTOR5 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1014654 || actorId == 1014654 ) // ACTOR6 = TATARU
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 4:
      {
        if( actor == 1012773 || actorId == 1012773 ) // ACTOR7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(QuestBattle, YesNo), id=unknown
          }
        }
        if( actor == 1012771 || actorId == 1012771 ) // ACTOR8 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012772 || actorId == 1012772 ) // ACTOR9 = TATARU
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1012775 || actorId == 1012775 ) // ACTOR10 = REVOLUTIONARY2
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2
        }
        if( actor == 1012774 || actorId == 1012774 ) // ACTOR11 = REVOLUTIONARY1
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1
        }
        if( actor == 2005763 || actorId == 2005763 ) // EOBJECT2 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1012780 || actorId == 1012780 ) // ACTOR12 = HILDA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HILDA
        }
        if( actor == 1012781 || actorId == 1012781 ) // ACTOR13 = REVOLUTIONARY1
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1
        }
        if( actor == 1012782 || actorId == 1012782 ) // ACTOR14 = REVOLUTIONARY2
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2
        }
        if( actor == 1012776 || actorId == 1012776 ) // ACTOR15 = ALPHINAUD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012777 || actorId == 1012777 ) // ACTOR16 = TATARU
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1012778 || actorId == 1012778 ) // ACTOR17 = LUCIA
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1012779 || actorId == 1012779 ) // ACTOR18 = HAURCHEFANT
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=HAURCHEFANT
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna403:67175 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00002: Normal(None), id=unknown" );
    Scene00003( player );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling [BranchTrue]Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling [BranchTrue]Scene00006: Normal(Talk, CutScene, FadeIn, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 418, 20.75, -12, 46.5, 0.34 );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling [BranchTrue]Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00009: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00010: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00011: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00013: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00014: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq4( player );
      }
    };
    //player.playScene( getId(), 14, NONE, callback );
    player.updateQuest( getId(), 255 );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00016: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00017: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00018: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00021: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00022: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00024: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00025: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVna403:67175 calling Scene00026: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna403 );
