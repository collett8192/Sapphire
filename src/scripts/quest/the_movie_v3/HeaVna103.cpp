// FFXIVTheMovie.ParserV3.6
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
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012323 || param2 == 1012323 ) // ACTOR0 = BUTLER01582
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=BUTLER01582
          }
          break;
        }
        if( param1 == 1012324 || param2 == 1012324 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012325 || param2 == 1012325 ) // ACTOR2 = TATARU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1013033 || param2 == 1013033 ) // ACTOR3 = EDMONT
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=EDMONT
          break;
        }
        if( param1 == 1013034 || param2 == 1013034 ) // ACTOR4 = ARTOIREL
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1013035 || param2 == 1013035 ) // ACTOR5 = EMMANELLAIN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1011192 || param2 == 1011192 ) // ACTOR6 = GIBRILLONT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=GIBRILLONT
          }
          break;
        }
        if( param1 == 1013039 || param2 == 1013039 ) // ACTOR7 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013040 || param2 == 1013040 ) // ACTOR8 = TATARU
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1013041 || param2 == 1013041 ) // ACTOR9 = BUTLER01582
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=BUTLER01582
          break;
        }
        if( param1 == 1013033 || param2 == 1013033 ) // ACTOR3 = EDMONT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=EDMONT
          break;
        }
        if( param1 == 1013034 || param2 == 1013034 ) // ACTOR4 = ARTOIREL
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1013035 || param2 == 1013035 ) // ACTOR5 = EMMANELLAIN
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1013033 || param2 == 1013033 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1013034 || param2 == 1013034 ) // ACTOR4 = ARTOIREL
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1013035 || param2 == 1013035 ) // ACTOR5 = EMMANELLAIN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1013383 || param2 == 1013383 ) // ACTOR10 = HONOROIT
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1013040 || param2 == 1013040 ) // ACTOR8 = TATARU
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1013036 || param2 == 1013036 ) // ACTOR11 = ALPHINAUD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012328 || param2 == 1012328 ) // ACTOR12 = ARTOIREL
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1012329 || param2 == 1012329 ) // ACTOR13 = EMMANELLAIN
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1012327 || param2 == 1012327 ) // ACTOR14 = HONOROIT
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
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
    player.sendDebug( "emote: {}", emoteId );
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
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
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
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=BUTLER01582" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00004: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00005: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00006: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=GIBRILLONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00009: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00010: Normal(Talk, TargetCanMove), id=BUTLER01582" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00011: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00012: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00013: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00014: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00015: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00016: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00017: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00018: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00019: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00020: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00021: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna103:67118 calling Scene00022: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna103 );
