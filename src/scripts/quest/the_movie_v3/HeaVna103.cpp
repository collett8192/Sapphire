// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna103 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna103() : Sapphire::ScriptAPI::EventScript( 67118 ){}; 
  ~HeaVna103() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 7 entries
  //SEQ_2, 5 entries
  //SEQ_255, 4 entries

  //ACTIONTIMELINEEVENTBASEBADSTAND = 827
  //ACTIONTIMELINEEVENTBASEROOKIE = 855
  //ACTIONTIMELINETALKJOKE = 4220
  //ACTOR0 = 1012323
  //ACTOR1 = 1012324
  //ACTOR10 = 1013383
  //ACTOR11 = 1013036
  //ACTOR12 = 1012328
  //ACTOR13 = 1012329
  //ACTOR14 = 1012327
  //ACTOR2 = 1012325
  //ACTOR3 = 1013033
  //ACTOR4 = 1013034
  //ACTOR5 = 1013035
  //ACTOR6 = 1011192
  //ACTOR7 = 1013039
  //ACTOR8 = 1013040
  //ACTOR9 = 1013041
  //CUTSCENEN01 = 790
  //LOCACTOR0 = 5853040
  //LOCACTOR1 = 5853041
  //LOCACTOR2 = 1012433
  //LOCACTOR3 = 5853047
  //LOCACTOR4 = 5853048
  //LOCACTOR5 = 5853049
  //LOCPOSCAM0 = 5899376
  //LOCPOSCAM1 = 5899377

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012323 || actorId == 1012323 ) // ACTOR0 = BUTLER01582
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=BUTLER01582
        }
        if( actor == 1012324 || actorId == 1012324 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012325 || actorId == 1012325 ) // ACTOR2 = TATARU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1013033 || actorId == 1013033 ) // ACTOR3 = EDMONT
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=EDMONT
        }
        if( actor == 1013034 || actorId == 1013034 ) // ACTOR4 = ARTOIREL
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ARTOIREL
        }
        if( actor == 1013035 || actorId == 1013035 ) // ACTOR5 = EMMANELLAIN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        break;
      }
      case 1:
      {
        if( actor == 1011192 || actorId == 1011192 ) // ACTOR6 = GIBRILLONT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=GIBRILLONT
          }
        }
        if( actor == 1013039 || actorId == 1013039 ) // ACTOR7 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013040 || actorId == 1013040 ) // ACTOR8 = TATARU
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1013041 || actorId == 1013041 ) // ACTOR9 = BUTLER01582
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=BUTLER01582
        }
        if( actor == 1013033 || actorId == 1013033 ) // ACTOR3 = EDMONT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=EDMONT
        }
        if( actor == 1013034 || actorId == 1013034 ) // ACTOR4 = ARTOIREL
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ARTOIREL
        }
        if( actor == 1013035 || actorId == 1013035 ) // ACTOR5 = EMMANELLAIN
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        break;
      }
      case 2:
      {
        if( actor == 1013033 || actorId == 1013033 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1013034 || actorId == 1013034 ) // ACTOR4 = ARTOIREL
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ARTOIREL
        }
        if( actor == 1013035 || actorId == 1013035 ) // ACTOR5 = EMMANELLAIN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( actor == 1013383 || actorId == 1013383 ) // ACTOR10 = HONOROIT
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( actor == 1013040 || actorId == 1013040 ) // ACTOR8 = TATARU
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 255:
      {
        if( actor == 1013036 || actorId == 1013036 ) // ACTOR11 = ALPHINAUD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012328 || actorId == 1012328 ) // ACTOR12 = ARTOIREL
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ARTOIREL
        }
        if( actor == 1012329 || actorId == 1012329 ) // ACTOR13 = EMMANELLAIN
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( actor == 1012327 || actorId == 1012327 ) // ACTOR14 = HONOROIT
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=HONOROIT
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna103:67118 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=BUTLER01582" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00004: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00005: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00006: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=GIBRILLONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00009: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00010: Normal(Talk, TargetCanMove), id=BUTLER01582" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00011: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00012: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00013: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00014: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00015: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00016: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00017: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00018: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00019: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00020: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00021: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00022: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna103 );
