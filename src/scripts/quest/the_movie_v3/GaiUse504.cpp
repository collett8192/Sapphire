// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse504 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse504() : Sapphire::ScriptAPI::EventScript( 65902 ){}; 
  ~GaiUse504() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 5 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_4, 1 entries
  //SEQ_5, 4 entries
  //SEQ_6, 6 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1010891
  //ACTOR1 = 1010855
  //ACTOR10 = 1010856
  //ACTOR11 = 1010858
  //ACTOR2 = 1011122
  //ACTOR3 = 1011123
  //ACTOR4 = 1008969
  //ACTOR5 = 1010854
  //ACTOR6 = 1010881
  //ACTOR7 = 5010000
  //ACTOR8 = 1010857
  //ACTOR9 = 1011124
  //COMPANION0 = 119
  //CUTSCENEN01 = 695
  //CUTSCENEN02 = 697
  //CUTSCENEN03 = 698
  //CUTSCENEN04 = 699
  //INSTANCEDUNGEON0 = 32
  //LOCACTOR0 = 4725177
  //LOCACTOR1 = 5578843
  //LOCACTOR2 = 5578845
  //LOCACTOR3 = 5578846
  //LOCACTOR4 = 5578574
  //LOCEOBJECT0 = 2005157
  //LOCMOTION0 = 731
  //LOCMOTION1 = 707
  //LOCMOTION2 = 719
  //POPRANGE0 = 5582034
  //POPRANGE1 = 5589530
  //TERRITORYTYPE0 = 156
  //UNLOCKDUNGEONTOWEROFSECRET = 266

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1010891 || actorId == 1010891 ) // ACTOR0 = TATARU
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=TATARU
        }
        if( actor == 1010855 || actorId == 1010855 ) // ACTOR1 = LUCIA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1011122 || actorId == 1011122 ) // ACTOR2 = MOENBRYDA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MOENBRYDA
        }
        if( actor == 1011123 || actorId == 1011123 ) // ACTOR3 = URIANGER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=URIANGER
        }
        break;
      }
      case 1:
      {
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1010855 || actorId == 1010855 ) // ACTOR1 = LUCIA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=unknown
          // +Callback Scene00007: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1011122 || actorId == 1011122 ) // ACTOR2 = MOENBRYDA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MOENBRYDA
        }
        if( actor == 1011123 || actorId == 1011123 ) // ACTOR3 = URIANGER
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=URIANGER
        }
        if( actor == 1010854 || actorId == 1010854 ) // ACTOR5 = TATARU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 2:
      {
        if( actor == 1010881 || actorId == 1010881 ) // ACTOR6 = DOMANPEOPLE00366
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, Message, FadeIn, TargetCanMove), id=DOMANPEOPLE00366
          }
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR4 = MINFILIA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1010855 || actorId == 1010855 ) // ACTOR1 = LUCIA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1010891 || actorId == 1010891 ) // ACTOR0 = TATARU
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 3:
      {
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR4 = MINFILIA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1010855 || actorId == 1010855 ) // ACTOR1 = LUCIA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1010891 || actorId == 1010891 ) // ACTOR0 = TATARU
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1010881 || actorId == 1010881 ) // ACTOR6 = DOMANPEOPLE00366
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=DOMANPEOPLE00366
        }
        break;
      }
      case 4:
      {
        if( actor == /*UNKNOWN*/1 || actorId == /*UNKNOWN*/1 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00019( player ); // Scene00019: Normal(CutScene), id=unknown
        }
        break;
      }
      case 5:
      {
        if( actor == 1010881 || actorId == 1010881 ) // ACTOR6 = DOMANPEOPLE00366
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(FadeIn), id=unknown
            // +Callback Scene00021: Normal(Talk, TargetCanMove), id=DOMANPEOPLE00366
          }
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR4 = MINFILIA
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1010855 || actorId == 1010855 ) // ACTOR1 = LUCIA
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1010891 || actorId == 1010891 ) // ACTOR0 = TATARU
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 6:
      {
        if( actor == 1010857 || actorId == 1010857 ) // ACTOR8 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00026: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR4 = MINFILIA
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1010891 || actorId == 1010891 ) // ACTOR0 = TATARU
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1011124 || actorId == 1011124 ) // ACTOR9 = URIANGER
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=URIANGER
        }
        if( actor == 1010856 || actorId == 1010856 ) // ACTOR10 = LUCIA
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1010881 || actorId == 1010881 ) // ACTOR6 = DOMANPEOPLE00366
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=DOMANPEOPLE00366
        }
        break;
      }
      case 255:
      {
        if( actor == 1010858 || actorId == 1010858 ) // ACTOR11 = ALPHINAUD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR4 = MINFILIA
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1010891 || actorId == 1010891 ) // ACTOR0 = TATARU
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=TATARU
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
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse504:65902 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00002: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00003: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00004: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00005: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling [BranchTrue]Scene00007: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00008: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00009: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00010: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00011: Normal(Talk, Message, FadeIn, TargetCanMove), id=DOMANPEOPLE00366" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00012: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00013: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00014: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00015: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00016: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00017: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00018: Normal(Talk, TargetCanMove), id=DOMANPEOPLE00366" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00019: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00020: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling [BranchTrue]Scene00021: Normal(Talk, TargetCanMove), id=DOMANPEOPLE00366" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00022: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00023: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00024: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00026( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling [BranchTrue]Scene00026: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00027: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00028: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00029: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00030: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00031: Normal(Talk, TargetCanMove), id=DOMANPEOPLE00366" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00032: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00033: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00034: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse504 );
