// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda305 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda305() : Sapphire::ScriptAPI::EventScript( 68017 ){}; 
  ~StmBda305() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 5 entries
  //SEQ_3, 6 entries
  //SEQ_4, 2 entries
  //SEQ_5, 3 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1021511
  //ACTOR1 = 1019946
  //ACTOR2 = 1019944
  //ACTOR3 = 1019939
  //ACTOR4 = 1019938
  //ACTOR5 = 1020363
  //ACTOR6 = 1021505
  //BINDACTOR0 = 6829417
  //BINDACTOR1 = 6829416
  //CUTSCENEN01 = 1411
  //ENEMY0 = 6829455
  //ENEMY1 = 6829456
  //ENEMY2 = 6829464
  //EOBJECT0 = 2007911
  //EOBJECT1 = 2007912
  //EOBJECT2 = 2007913
  //EOBJECT3 = 2008025
  //EVENTACTION0 = 53
  //EVENTACTION1 = 38
  //EVENTRANGE0 = 6829469
  //ITEM0 = 2002093

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HIRASE
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 2007911 || param2 == 2007911 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
          }
        }
        if( param1 == 1021511 || param2 == 1021511 ) // ACTOR0 = HIRASE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=HIRASE
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BL max stack ?
      case 2:
      {
        if( param1 == 2007912 || param2 == 2007912 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Message, Inventory), id=unknown
            // +Callback Scene00006: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 6829455 || param2 == 6829455 ) // ENEMY0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
        }
        if( param1 == 2007913 || param2 == 2007913 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Message, Inventory), id=unknown
            // +Callback Scene00010: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 6829456 || param2 == 6829456 ) // ENEMY1 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
        }
        if( param1 == 1021511 || param2 == 1021511 ) // ACTOR0 = HIRASE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=HIRASE
        }
        break;
      }
      case 3:
      {
        if( param1 == 6829469 || param2 == 6829469 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 6829464 || param2 == 6829464 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( param1 == 1019946 || param2 == 1019946 ) // ACTOR1 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(Message), id=unknown
        }
        if( param1 == 2008025 || param2 == 2008025 ) // EOBJECT3 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        if( param1 == 1019944 || param2 == 1019944 ) // ACTOR2 = HIRASE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=HIRASE
        }
        if( param1 == 1021511 || param2 == 1021511 ) // ACTOR0 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        break;
      }
      case 4:
      {
        if( param1 == 1019946 || param2 == 1019946 ) // ACTOR1 = PIRATE02481
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk, NpcDespawn, TargetCanMove), id=PIRATE02481
          }
        }
        if( param1 == 1021511 || param2 == 1021511 ) // ACTOR0 = HIRASE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=HIRASE
        }
        break;
      }
      case 5:
      {
        if( param1 == 1019939 || param2 == 1019939 ) // ACTOR3 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE
          }
        }
        if( param1 == 1019938 || param2 == 1019938 ) // ACTOR4 = LYSE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020363 || param2 == 1020363 ) // ACTOR5 = TANSUI
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=TANSUI
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR6 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( param1 == 1019939 || param2 == 1019939 ) // ACTOR3 = ALISAIE
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019938 || param2 == 1019938 ) // ACTOR4 = LYSE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020363 || param2 == 1020363 ) // ACTOR5 = TANSUI
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=TANSUI
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda305:68017 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HIRASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00004: Normal(Talk, TargetCanMove), id=HIRASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00005: Normal(Message, Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00009: Normal(Message, Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00013: Normal(Talk, TargetCanMove), id=HIRASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00016: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00019: Normal(Talk, TargetCanMove), id=HIRASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00021: Normal(Talk, NpcDespawn, TargetCanMove), id=PIRATE02481" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00022: Normal(Talk, TargetCanMove), id=HIRASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00024: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00025: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00026: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00027: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00028: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda305:68017 calling Scene00029: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda305 );
