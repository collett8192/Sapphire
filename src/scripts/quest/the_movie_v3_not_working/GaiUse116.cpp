// FFXIVTheMovie.ParserV3
//not working: add skip code
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse116 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse116() : Sapphire::ScriptAPI::EventScript( 66726 ){}; 
  ~GaiUse116() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 2 entries
  //SEQ_4, 23 entries
  //SEQ_5, 2 entries
  //SEQ_6, 3 entries
  //SEQ_7, 2 entries
  //SEQ_8, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000692
  //ACTOR1 = 1008275
  //ACTOR2 = 1008279
  //ACTOR3 = 1008280
  //ACTOR4 = 1008281
  //ACTOR5 = 1008318
  //ACTOR6 = 1008276
  //ACTOR7 = 1008277
  //ACTOR9 = 1007862
  //BNPCNAME0 = 2358
  //ENEMY0 = 4515258
  //ENEMY1 = 4515416
  //ENEMY10 = 4515586
  //ENEMY11 = 4515582
  //ENEMY12 = 4515580
  //ENEMY13 = 4515581
  //ENEMY2 = 4515569
  //ENEMY3 = 4515570
  //ENEMY4 = 4515571
  //ENEMY5 = 4515572
  //ENEMY6 = 4515578
  //ENEMY7 = 4515579
  //ENEMY8 = 4515587
  //ENEMY9 = 4515588
  //EOBJECT0 = 2003347
  //EOBJECT1 = 2003057
  //EOBJECT2 = 2003046
  //EVENTRANGE0 = 4500856
  //EVENTRANGE1 = 4500863
  //EVENTRANGE2 = 4500869
  //EVENTRANGE3 = 4500872
  //EVENTRANGE4 = 4500873
  //EVENTRANGE5 = 4500875
  //EVENTRANGE6 = 4500877
  //EVENTACTIONSYMPATHY = 19
  //INSTANCEDUNGEON0 = 20011
  //LOCACTOR0 = 1008362
  //LOCACTOR1 = 1005771
  //LOCACTOR2 = 1005772
  //LOCACTOR3 = 1005773
  //LOCEOBJ0 = 2003434
  //LOCMOTION1 = 938
  //LOCMOTION2 = 945
  //LOGMESSAGE0 = 3703
  //POPRANGE0 = 4504658
  //TERRITORYTYPE0 = 152
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKDUNGEONMOOGLEHARD = 145

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ESUMIYAN
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=KUPLOKOPP
        break;
      }
      case 2:
      {
        if( actor == 1 && actorId == 1 && type == 3 ) // EVENTRANGE0 = unknown
        {
          // empty entry
          player.sendUrgent( "This quest is likely not fixable in Sapphire, skipping to SEQ_255." );
          player.updateQuest( getId(), 255 );
        }
        if( actor == 1008279 || actorId == 1008279 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(Talk, FadeIn), id=unknown
          // +Callback Scene00004: Normal(None), id=unknown
          // +not used Scene00005: Normal(None), id=unknown
        }
        if( actor == 1008280 || actorId == 1008280 ) // ACTOR3 = KUPLOKOPP
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          // +Callback Scene00007: Normal(None), id=unknown
          // +not used Scene00008: Normal(Talk, TargetCanMove), id=KUPLOKOPP
        }
        if( actor == 1008281 || actorId == 1008281 ) // ACTOR4 = KUPLOKOPP
        {
          Scene00009( player ); // Scene00009: Normal(Talk), id=KUPLOKOPP
          // +Callback Scene00010: Normal(None), id=unknown
          // +not used Scene00011: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 1008318 || actorId == 1008318 ) // ACTOR5 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00013: Normal(Message, PopBNpc), id=unknown
          // +not used Scene00014: Normal(Message, PopBNpc), id=unknown
        }
        break;
      }
      case 3:
      {
        if( actor == 1008276 || actorId == 1008276 ) // ACTOR6 = KUPLOKOPP
        {
          Scene00015( player ); // Scene00015: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00016: Normal(Message, PopBNpc), id=unknown
          // +not used Scene00017: Normal(Talk, TargetCanMove), id=KUPLOKOPP
        }
        if( actor == 4515258 || actorId == 4515258 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        break;
      }
      case 4:
      {
        if( actor == 2003347 || actorId == 2003347 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(None), id=unknown
            // +Callback Scene00019: Normal(None), id=unknown
          }
        }
        if( actor == 4500863 || actorId == 4500863 ) // EVENTRANGE1 = unknown
        {
          // empty entry
        }
        if( actor == 4515416 || actorId == 4515416 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 4500869 || actorId == 4500869 ) // EVENTRANGE2 = unknown
        {
          // empty entry
        }
        if( actor == 4515569 || actorId == 4515569 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 4515570 || actorId == 4515570 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( actor == 4515571 || actorId == 4515571 ) // ENEMY4 = unknown
        {
          // empty entry
        }
        if( actor == 4500872 || actorId == 4500872 ) // EVENTRANGE3 = unknown
        {
          // empty entry
        }
        if( actor == 4515572 || actorId == 4515572 ) // ENEMY5 = unknown
        {
          // empty entry
        }
        if( actor == 4500873 || actorId == 4500873 ) // EVENTRANGE4 = unknown
        {
          // empty entry
        }
        if( actor == 4515578 || actorId == 4515578 ) // ENEMY6 = unknown
        {
          // empty entry
        }
        if( actor == 4515579 || actorId == 4515579 ) // ENEMY7 = unknown
        {
          // empty entry
        }
        if( actor == 4500875 || actorId == 4500875 ) // EVENTRANGE5 = unknown
        {
          // empty entry
        }
        if( actor == 4515587 || actorId == 4515587 ) // ENEMY8 = unknown
        {
          // empty entry
        }
        if( actor == 4515588 || actorId == 4515588 ) // ENEMY9 = unknown
        {
          // empty entry
        }
        if( actor == 4515586 || actorId == 4515586 ) // ENEMY10 = unknown
        {
          // empty entry
        }
        if( actor == 4500877 || actorId == 4500877 ) // EVENTRANGE6 = unknown
        {
          // empty entry
        }
        if( actor == 4515582 || actorId == 4515582 ) // ENEMY11 = unknown
        {
          // empty entry
        }
        if( actor == 4515580 || actorId == 4515580 ) // ENEMY12 = unknown
        {
          // empty entry
        }
        if( actor == 4515581 || actorId == 4515581 ) // ENEMY13 = unknown
        {
          // empty entry
        }
        if( actor == 1008276 || actorId == 1008276 ) // ACTOR6 = KUPLOKOPP
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=KUPLOKOPP
        }
        if( actor == 4515258 || actorId == 4515258 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 2003057 || actorId == 2003057 ) // EOBJECT1 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          // +Callback Scene00022: Normal(None), id=unknown
          // +not used Scene00023: Normal(None), id=unknown
        }
        break;
      }
      case 5:
      {
        if( actor == 1008277 || actorId == 1008277 ) // ACTOR7 = KUPLOKOPP
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(None), id=unknown
            // +Callback Scene00025: Normal(Talk, FadeIn), id=unknown
          }
          else
          {
            Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=KUPLOKOPP
          }
        }
        if( actor == 2003057 || actorId == 2003057 ) // EOBJECT1 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
        }
        break;
      }
      case 6:
      {
        if( actor == 2003046 || actorId == 2003046 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00028( player ); // Scene00028: Normal(None), id=unknown
          }
        }
        if( actor == 1008277 || actorId == 1008277 ) // ACTOR7 = KUPLOKOPP
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=KUPLOKOPP
        }
        if( actor == 2003057 || actorId == 2003057 ) // EOBJECT1 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          // +Callback Scene00031: Normal(None), id=unknown
        }
        break;
      }
      case 7:
      {
        if( actor == 1008277 || actorId == 1008277 ) // ACTOR7 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(Talk, FadeIn, TargetCanMove), id=unknown
        }
        if( actor == 2003057 || actorId == 2003057 ) // EOBJECT1 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
        }
        break;
      }
      case 8:
      {
        if( actor == /*UNKNOWN*/1 || actorId == /*UNKNOWN*/1 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          // empty entry
        }
        if( actor == 2003057 || actorId == 2003057 ) // EOBJECT1 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        Scene00035( player ); // Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KUPCHAKUPA
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
    onProgress( player, 1, 1, 3, param1 );
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
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    player.updateQuest( getId(), 8 );
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse116:66726 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ESUMIYAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00003: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchTrue]Scene00004: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchFalse]Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchFalse]Scene00008: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00009: Normal(Talk), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchTrue]Scene00010: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchFalse]Scene00011: Normal(Message, PopBNpc), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchTrue]Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchFalse]Scene00014: Normal(Message, PopBNpc), id=unknown" );
    player.playScene( getId(), 13, NONE, nullptr );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00015: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchTrue]Scene00016: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchFalse]Scene00017: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
    player.playScene( getId(), 16, NONE, nullptr );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00018: Normal(None), id=unknown" );
    Scene00019( player );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchTrue]Scene00019: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00020: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00021: Normal(None), id=unknown" );
    Scene00022( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchTrue]Scene00022: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchFalse]Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00024: Normal(None), id=unknown" );
    Scene00025( player );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchTrue]Scene00025: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchFalse]Scene00026: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
    player.playScene( getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, nullptr );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00027: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00028: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq6( player );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00029: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00030: Normal(None), id=unknown" );
    Scene00031( player );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling [BranchTrue]Scene00031: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00032: Normal(Talk, FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 32, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00033: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00034: Normal(None), id=unknown" );
    checkProgressSeq8( player );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KUPCHAKUPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 35, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse116 );
