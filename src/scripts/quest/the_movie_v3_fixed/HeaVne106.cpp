// FFXIVTheMovie.ParserV3
//fix: black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVne106 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVne106() : Sapphire::ScriptAPI::EventScript( 67882 ){}; 
  ~HeaVne106() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 2 entries
  //SEQ_3, 4 entries
  //SEQ_4, 2 entries
  //SEQ_5, 3 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1017744
  //ACTOR1 = 1017745
  //ACTOR10 = 1017750
  //ACTOR2 = 1017746
  //ACTOR3 = 1006325
  //ACTOR4 = 1017728
  //ACTOR5 = 1017747
  //ACTOR6 = 1017748
  //ACTOR7 = 1018368
  //ACTOR8 = 1007478
  //ACTOR9 = 1017751
  //CUTSCENEN01 = 1259
  //CUTSCENEN02 = 1260
  //LOCACTION0 = 1022
  //LOCACTION1 = 1002
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1017687
  //LOCACTOR2 = 1017698
  //LOCACTOR3 = 1008180
  //LOCACTOR4 = 1017689
  //LOCACTOR5 = 1015842
  //LOCBGM0 = 96
  //LOCBGM1 = 66
  //LOCIDLE0 = 4294
  //LOCIDLE1 = 4295
  //LOCIDLE2 = 4199
  //LOCIDLE3 = 1014
  //LOCSE0 = 42
  //LOCSE1 = 78
  //POPRANGE0 = 6433476
  //POPRANGE1 = 6538069
  //POPRANGE2 = 6502174
  //QUEST1 = 65580
  //QUEST2 = 66850
  //TERRITORYTYPE0 = 212

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1017744 || param2 == 1017744 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017745 || param2 == 1017745 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1017746 || param2 == 1017746 ) // ACTOR2 = GABU
        {
          Scene00003( player ); // Scene00003: Normal(Talk), id=GABU
        }
        break;
      }
      case 1:
      {
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR3 = BLOEIDIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=BLOEIDIN
            // +Callback Scene00005: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1017744 || param2 == 1017744 ) // ACTOR0 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017745 || param2 == 1017745 ) // ACTOR1 = ALISAIE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1017746 || param2 == 1017746 ) // ACTOR2 = GABU
        {
          Scene00008( player ); // Scene00008: Normal(Talk), id=GABU
        }
        break;
      }
      case 2:
      {
        if( param1 == 1017728 || param2 == 1017728 ) // ACTOR4 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR3 = BLOEIDIN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=BLOEIDIN
        }
        break;
      }
      case 3:
      {
        if( param1 == 1017747 || param2 == 1017747 ) // ACTOR5 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE
          }
        }
        if( param1 == 1017748 || param2 == 1017748 ) // ACTOR6 = GABU
        {
          Scene00012( player ); // Scene00012: Normal(Talk), id=GABU
        }
        if( param1 == 1017728 || param2 == 1017728 ) // ACTOR4 = ALPHINAUD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR3 = BLOEIDIN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=BLOEIDIN
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00015( player ); // Scene00015: Normal(FadeIn), id=unknown
        }
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR3 = BLOEIDIN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=BLOEIDIN
        }
        break;
      }
      case 5:
      {
        if( param1 == 1018368 || param2 == 1018368 ) // ACTOR7 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR3 = BLOEIDIN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=BLOEIDIN
        }
        if( param1 == 1007478 || param2 == 1007478 ) // ACTOR8 = URIANGER
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=URIANGER
        }
        break;
      }
      case 255:
      {
        if( param1 == 1017751 || param2 == 1017751 ) // ACTOR9 = ALISAIE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1017750 || param2 == 1017750 ) // ACTOR10 = ALPHINAUD
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR3 = BLOEIDIN
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=BLOEIDIN
        }
        if( param1 == 1007478 || param2 == 1007478 ) // ACTOR8 = URIANGER
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=URIANGER
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
    player.sendDebug( "HeaVne106:67882 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVne106:67882 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00003: Normal(Talk), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00004: Normal(Talk, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling [BranchTrue]Scene00005: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00008: Normal(Talk), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00010: Normal(Talk, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00012: Normal(Talk), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00014: Normal(Talk, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00015: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00016: Normal(Talk, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00018: Normal(Talk, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00019: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00022: Normal(Talk, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVne106:67882 calling Scene00023: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVne106 );
