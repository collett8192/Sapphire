// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna102 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna102() : Sapphire::ScriptAPI::EventScript( 67117 ){}; 
  ~HeaVna102() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_3, 7 entries
  //SEQ_255, 6 entries

  //ACTIONTIMELINEEVENTBASEROOKIE = 855
  //ACTIONTIMELINEEVENTBASESPEECH = 796
  //ACTOR0 = 1013036
  //ACTOR1 = 1013037
  //ACTOR10 = 1012319
  //ACTOR11 = 1012180
  //ACTOR12 = 1012320
  //ACTOR13 = 1012321
  //ACTOR14 = 1012322
  //ACTOR15 = 1012323
  //ACTOR16 = 1012324
  //ACTOR17 = 1012325
  //ACTOR2 = 1013033
  //ACTOR3 = 1013034
  //ACTOR4 = 1013035
  //ACTOR5 = 1012316
  //ACTOR6 = 1012335
  //ACTOR7 = 1012336
  //ACTOR8 = 1012317
  //ACTOR9 = 1012318
  //CUTSCENEN01 = 789
  //LOCACTOR0 = 5853031
  //LOCACTOR1 = 5853032
  //LOCACTOR2 = 5853035
  //LOCACTOR3 = 5853036
  //LOCACTOR4 = 5853034
  //LOCPOSCAM0 = 5896043
  //LOCPOSCAM1 = 5896050
  //POPRANGE0 = 5853013
  //QSTACTOR1 = 5853011
  //QSTACTOR2 = 5853012

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1013036 || param2 == 1013036 ) // ACTOR0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(CutScene, AutoFadeIn), id=unknown
            // +Callback Scene00002: Normal(QuestAccept, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1013037 || param2 == 1013037 ) // ACTOR1 = TATARU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1013033 || param2 == 1013033 ) // ACTOR2 = EDMONT
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=EDMONT
          break;
        }
        if( param1 == 1013034 || param2 == 1013034 ) // ACTOR3 = ARTOIREL
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1013035 || param2 == 1013035 ) // ACTOR4 = EMMANELLAIN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012316 || param2 == 1012316 ) // ACTOR5 = BUTLER01581
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=BUTLER01581
          }
          break;
        }
        if( param1 == 1012335 || param2 == 1012335 ) // ACTOR6 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012336 || param2 == 1012336 ) // ACTOR7 = TATARU
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1013033 || param2 == 1013033 ) // ACTOR2 = EDMONT
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=EDMONT
          break;
        }
        if( param1 == 1013034 || param2 == 1013034 ) // ACTOR3 = ARTOIREL
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1013035 || param2 == 1013035 ) // ACTOR4 = EMMANELLAIN
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1012317 || param2 == 1012317 ) // ACTOR8 = BUTLER01581
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=BUTLER01581
          }
          break;
        }
        if( param1 == 1012318 || param2 == 1012318 ) // ACTOR9 = ALPHINAUD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012319 || param2 == 1012319 ) // ACTOR10 = TATARU
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1013033 || param2 == 1013033 ) // ACTOR2 = EDMONT
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=EDMONT
          break;
        }
        if( param1 == 1013034 || param2 == 1013034 ) // ACTOR3 = ARTOIREL
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1013035 || param2 == 1013035 ) // ACTOR4 = EMMANELLAIN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1012180 || param2 == 1012180 ) // ACTOR11 = ELAISSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ELAISSE
          }
          break;
        }
        if( param1 == 1012320 || param2 == 1012320 ) // ACTOR12 = BUTLER01581
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=BUTLER01581
          break;
        }
        if( param1 == 1012321 || param2 == 1012321 ) // ACTOR13 = ALPHINAUD
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012322 || param2 == 1012322 ) // ACTOR14 = TATARU
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1013033 || param2 == 1013033 ) // ACTOR2 = EDMONT
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=EDMONT
          break;
        }
        if( param1 == 1013034 || param2 == 1013034 ) // ACTOR3 = ARTOIREL
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1013035 || param2 == 1013035 ) // ACTOR4 = EMMANELLAIN
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012323 || param2 == 1012323 ) // ACTOR15 = BUTLER01581
        {
          Scene00026( player ); // Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BUTLER01581
          break;
        }
        if( param1 == 1012324 || param2 == 1012324 ) // ACTOR16 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012325 || param2 == 1012325 ) // ACTOR17 = TATARU
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1013033 || param2 == 1013033 ) // ACTOR2 = EDMONT
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=EDMONT
          break;
        }
        if( param1 == 1013034 || param2 == 1013034 ) // ACTOR3 = ARTOIREL
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1013035 || param2 == 1013035 ) // ACTOR4 = EMMANELLAIN
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=EMMANELLAIN
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
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
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
    player.sendDebug( "HeaVna102:67117 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna102:67117 calling Scene00001: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00002: Normal(QuestAccept, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00004: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00005: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00006: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=BUTLER01581" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00009: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00010: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00011: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00012: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR8, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00013: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=BUTLER01581" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00015: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00016: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00017: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00018: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_3: ACTOR11, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00019: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ELAISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00020: Normal(Talk, TargetCanMove), id=BUTLER01581" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_3: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_3: ACTOR14, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00022: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00023: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00024: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00025: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BUTLER01581" );
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
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00028: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00029: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00030: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna102:67117 calling Scene00031: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna102 );
