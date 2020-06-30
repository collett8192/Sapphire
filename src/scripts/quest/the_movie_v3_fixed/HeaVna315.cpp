// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_6 = dummy0
//fix: add code to enter instance, skip dungeon
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna315 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna315() : Sapphire::ScriptAPI::EventScript( 67152 ){}; 
  ~HeaVna315() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 8 entries
  //SEQ_3, 9 entries
  //SEQ_4, 1 entries
  //SEQ_5, 3 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1012638
  //ACTOR1 = 1012645
  //ACTOR10 = 1012650
  //ACTOR11 = 1012651
  //ACTOR12 = 1012652
  //ACTOR13 = 1012653
  //ACTOR14 = 1012654
  //ACTOR15 = 1012655
  //ACTOR16 = 1012656
  //ACTOR17 = 1014544
  //ACTOR18 = 1014545
  //ACTOR2 = 1012646
  //ACTOR3 = 1012647
  //ACTOR4 = 1014380
  //ACTOR5 = 1014381
  //ACTOR6 = 1014382
  //ACTOR7 = 5010000
  //ACTOR8 = 1012648
  //ACTOR9 = 1012649
  //CUTSCENEN01 = 814
  //CUTSCENEN02 = 815
  //CUTSCENEN03 = 816
  //EOBJECT0 = 2005446
  //EVENTRANGE0 = 5857247
  //INSTANCEDUNGEON0 = 20031
  //LOCACTOR0 = 1012456
  //LOCACTOR1 = 1012496
  //LOCACTOR2 = 1012496
  //LOCACTOR3 = 1012496
  //LOCACTOR4 = 1014627
  //LOCACTOR5 = 1014627
  //LOCACTOR6 = 5911058
  //LOCSCREENIMAGE0 = 312
  //POPRANGE0 = 5857232
  //POPRANGE1 = 5857162
  //POPRANGE2 = 5905620
  //POPRANGE3 = 5857271
  //TERRITORYTYPE0 = 462
  //TERRITORYTYPE1 = 398

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ICEHEART
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00002( player ); // Scene00002: Normal(CutScene), id=unknown
        }
        if( actor == 1012638 || actorId == 1012638 ) // ACTOR0 = ICEHEART
        {
          Scene00003( player ); // Scene00003: Normal(Talk, FadeIn), id=unknown
          // +Callback Scene00004: Normal(Talk, TargetCanMove), id=ICEHEART
          // +Callback Scene00005: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 5857247 || actorId == 5857247 ) // EVENTRANGE0 = dummy0
        {
          Scene00006( player ); // Scene00006: Normal(CutScene, Message, FadeIn), id=dummy0
        }
        if( actor == 1012645 || actorId == 1012645 ) // ACTOR1 = ICEHEART
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ICEHEART
        }
        if( actor == 1012646 || actorId == 1012646 ) // ACTOR2 = GNATHSOLDIER01616
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=GNATHSOLDIER01616
        }
        if( actor == 1012647 || actorId == 1012647 ) // ACTOR3 = GNATHSENTRY01616
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=GNATHSENTRY01616
        }
        if( actor == 2005446 || actorId == 2005446 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(YesNo), id=unknown
        }
        if( actor == 1014380 || actorId == 1014380 ) // ACTOR4 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 1014381 || actorId == 1014381 ) // ACTOR5 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( actor == 1014382 || actorId == 1014382 ) // ACTOR6 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( actor == 1012648 || actorId == 1012648 ) // ACTOR8 = ICEHEART
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ICEHEART
        }
        if( actor == 1012649 || actorId == 1012649 ) // ACTOR9 = GNATHPRIEST
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=GNATHPRIEST
        }
        if( actor == 1012650 || actorId == 1012650 ) // ACTOR10 = GNATHSOLDIER01616
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=GNATHSOLDIER01616
        }
        if( actor == 1012651 || actorId == 1012651 ) // ACTOR11 = GNATHSENTRY01616
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=GNATHSENTRY01616
        }
        if( actor == 2005446 || actorId == 2005446 ) // EOBJECT0 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(YesNo), id=unknown
        }
        if( actor == 1012652 || actorId == 1012652 ) // ACTOR12 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( actor == 1012653 || actorId == 1012653 ) // ACTOR13 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        if( actor == 1012654 || actorId == 1012654 ) // ACTOR14 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
        }
        if( actor == 1012655 || actorId == 1012655 ) // ACTOR15 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00023( player ); // Scene00023: Normal(CutScene), id=unknown
        }
        break;
      }
      case 5:
      {
        if( actor == 1012656 || actorId == 1012656 ) // ACTOR16 = ICEHEART
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Talk, NpcDespawn, TargetCanMove), id=ICEHEART
          }
        }
        if( actor == 1014544 || actorId == 1014544 ) // ACTOR17 = ALPHINAUD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1014545 || actorId == 1014545 ) // ACTOR18 = ESTINIEN
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        break;
      }
      case 255:
      {
        if( actor == 1014544 || actorId == 1014544 ) // ACTOR17 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1014545 || actorId == 1014545 ) // ACTOR18 = ESTINIEN
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ESTINIEN
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna315:67152 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 462 );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00003: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling [BranchTrue]Scene00004: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling [BranchChain]Scene00005: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00006: Normal(CutScene, Message, FadeIn), id=dummy0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      //checkProgressSeq2( player );
      Scene00023( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00007: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00008: Normal(Talk, TargetCanMove), id=GNATHSOLDIER01616" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00009: Normal(Talk, TargetCanMove), id=GNATHSENTRY01616" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00010: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00014: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00015: Normal(Talk, TargetCanMove), id=GNATHPRIEST" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00016: Normal(Talk, TargetCanMove), id=GNATHSOLDIER01616" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00017: Normal(Talk, TargetCanMove), id=GNATHSENTRY01616" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00018: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00023: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00024: Normal(Talk, NpcDespawn, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00026: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00027: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVna315:67152 calling Scene00028: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna315 );
