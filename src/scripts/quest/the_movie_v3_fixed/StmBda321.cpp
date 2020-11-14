// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda321 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda321() : Sapphire::ScriptAPI::EventScript( 68033 ){}; 
  ~StmBda321() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 2 entries
  //SEQ_4, 2 entries
  //SEQ_5, 2 entries
  //SEQ_6, 2 entries
  //SEQ_7, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1020046
  //ACTOR1 = 1020047
  //ACTOR2 = 1020048
  //ACTOR3 = 1020049
  //ACTOR4 = 1020050
  //ACTOR5 = 1020051
  //ACTOR6 = 1023787
  //EOBJECT0 = 2007840
  //EOBJECT1 = 2007841
  //EVENTACTION0 = 3
  //ITEM0 = 2002070
  //ITEM1 = 2002072
  //ITEM2 = 2002073
  //NCUT01 = 1428
  //NCUT02 = 1429
  //POPRANGE0 = 6791456

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( param1 == 1020046 || param2 == 1020046 ) // ACTOR0 = YUGIRI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020047 || param2 == 1020047 ) // ACTOR1 = SOLDIERC02495
        {
          Scene00002( player ); // Scene00002: Normal(Talk), id=SOLDIERC02495
        }
        if( param1 == 1020048 || param2 == 1020048 ) // ACTOR2 = SOLDIERD02496
        {
          Scene00003( player ); // Scene00003: Normal(Talk), id=SOLDIERD02496
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      //seq 1 event item ITEM1 = UI8BL max stack ?
      case 1:
      {
        if( param1 == 1020047 || param2 == 1020047 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
          }
        }
        if( param1 == 1020048 || param2 == 1020048 ) // ACTOR2 = SOLDIERD02496
        {
          Scene00006( player ); // Scene00006: Normal(Talk), id=SOLDIERD02496
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      //seq 2 event item ITEM1 = UI8BL max stack ?
      case 2:
      {
        if( param1 == 2007840 || param2 == 2007840 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
          }
        }
        if( param1 == 1020048 || param2 == 1020048 ) // ACTOR2 = SOLDIERD02496
        {
          Scene00009( player ); // Scene00009: Normal(Talk), id=SOLDIERD02496
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      //seq 3 event item ITEM1 = UI8BL max stack ?
      case 3:
      {
        if( param1 == 1020049 || param2 == 1020049 ) // ACTOR3 = SOLDIERC02495
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Inventory), id=unknown
            // +Callback Scene00011: Normal(Talk), id=SOLDIERC02495
          }
        }
        if( param1 == 1020048 || param2 == 1020048 ) // ACTOR2 = SOLDIERD02496
        {
          Scene00012( player ); // Scene00012: Normal(Talk), id=SOLDIERD02496
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      //seq 4 event item ITEM1 = UI8BL max stack ?
      //seq 4 event item ITEM2 = UI8CH max stack ?
      case 4:
      {
        if( param1 == 1020048 || param2 == 1020048 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(None), id=unknown
          }
        }
        if( param1 == 1020049 || param2 == 1020049 ) // ACTOR3 = SOLDIERC02495
        {
          Scene00015( player ); // Scene00015: Normal(Talk), id=SOLDIERC02495
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack ?
      //seq 5 event item ITEM1 = UI8BL max stack ?
      //seq 5 event item ITEM2 = UI8CH max stack ?
      case 5:
      {
        if( param1 == 2007841 || param2 == 2007841 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(None), id=unknown
          }
        }
        if( param1 == 1020049 || param2 == 1020049 ) // ACTOR3 = SOLDIERC02495
        {
          Scene00018( player ); // Scene00018: Normal(Talk), id=SOLDIERC02495
        }
        break;
      }
      //seq 6 event item ITEM0 = UI8BH max stack ?
      //seq 6 event item ITEM1 = UI8BL max stack ?
      //seq 6 event item ITEM2 = UI8CH max stack ?
      case 6:
      {
        if( param1 == 1020050 || param2 == 1020050 ) // ACTOR4 = SOLDIERD02496
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Inventory), id=unknown
            // +Callback Scene00020: Normal(Talk), id=SOLDIERD02496
          }
        }
        if( param1 == 1020049 || param2 == 1020049 ) // ACTOR3 = SOLDIERC02495
        {
          Scene00021( player ); // Scene00021: Normal(Talk), id=SOLDIERC02495
        }
        break;
      }
      //seq 7 event item ITEM1 = UI8BH max stack ?
      //seq 7 event item ITEM2 = UI8BL max stack ?
      case 7:
      {
        if( param1 == 1020051 || param2 == 1020051 ) // ACTOR5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1020049 || param2 == 1020049 ) // ACTOR3 = SOLDIERC02495
        {
          Scene00023( player ); // Scene00023: Normal(Talk), id=SOLDIERC02495
        }
        if( param1 == 1020050 || param2 == 1020050 ) // ACTOR4 = SOLDIERD02496
        {
          Scene00024( player ); // Scene00024: Normal(Talk), id=SOLDIERD02496
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack ?
      //seq 255 event item ITEM2 = UI8BL max stack ?
      case 255:
      {
        Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI
        // +Callback Scene00026: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown
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
      player.updateQuest( getId(), 5 );
    }
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.setQuestUI8CH( getId(), 0 );
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "StmBda321:68033 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00002: Normal(Talk), id=SOLDIERC02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00003: Normal(Talk), id=SOLDIERD02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00004: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00006: Normal(Talk), id=SOLDIERD02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00008: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00009: Normal(Talk), id=SOLDIERD02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00010: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00011: Normal(Talk), id=SOLDIERC02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00012: Normal(Talk), id=SOLDIERD02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00013: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00015: Normal(Talk), id=SOLDIERC02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00017: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq5( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00018: Normal(Talk), id=SOLDIERC02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00019: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00020: Normal(Talk), id=SOLDIERD02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00021: Normal(Talk), id=SOLDIERC02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00022: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00023: Normal(Talk), id=SOLDIERC02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00024: Normal(Talk), id=SOLDIERD02496" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00026( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda321:68033 calling Scene00026: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.eventFinish( getId(), 1 );
          player.enterPredefinedPrivateInstance( 681 );
        }
      }
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( StmBda321 );
