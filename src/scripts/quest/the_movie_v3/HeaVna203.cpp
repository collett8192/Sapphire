// FFXIVTheMovie.ParserV3.6
// param used:
//SCENE_9 = HOUZAN
//SCENE_36 = PAPASHAN_2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna203 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna203() : Sapphire::ScriptAPI::EventScript( 67137 ){}; 
  ~HeaVna203() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 6 entries
  //SEQ_2, 1 entries
  //SEQ_3, 3 entries
  //SEQ_4, 7 entries
  //SEQ_5, 8 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1013028
  //ACTOR1 = 1013029
  //ACTOR10 = 1013031
  //ACTOR11 = 1013030
  //ACTOR12 = 1013269
  //ACTOR13 = 1013270
  //ACTOR14 = 1013271
  //ACTOR15 = 1013272
  //ACTOR16 = 1013032
  //ACTOR17 = 1013038
  //ACTOR18 = 1003995
  //ACTOR19 = 1012843
  //ACTOR2 = 1012129
  //ACTOR3 = 1012130
  //ACTOR4 = 1012131
  //ACTOR5 = 1013026
  //ACTOR6 = 1013027
  //ACTOR7 = 1013071
  //ACTOR8 = 1013070
  //ACTOR9 = 1013024
  //CUTSCENENHEAVNA20310 = 800
  //CUTSCENENHEAVNA20320 = 801
  //CUTSCENENHEAVNA20330 = 802
  //EOBJECT0 = 2005430
  //LOCACTORAL = 1008181
  //LOCACTORCH = 1013343
  //LOCACTORHI = 5855011
  //LOCACTORHO = 5852818
  //LOCACTORNA = 1012450
  //LOCACTORRA = 1010832
  //LOCACTORYU = 1011896
  //LOCMAKERCHO = 5889540
  //NCUTHEAVNA20410 = 803
  //POPRANGE0 = 5856212
  //QUESTBATTLE0 = 106
  //TERRITORYTYPE0 = 460
  //TERRITORYTYPE1 = 145
  //TERRITORYTYPE2 = 212

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1013028 || param2 == 1013028 ) // ACTOR0 = HOUZAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HOUZAN
          }
          break;
        }
        if( param1 == 1013029 || param2 == 1013029 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012129 || param2 == 1012129 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012130 || param2 == 1012130 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012131 || param2 == 1012131 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013026 || param2 == 1013026 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013027 || param2 == 1013027 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1013028 || param2 == 1013028 ) // ACTOR0 = HOUZAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(QuestBattle, YesNo, CanCancel), id=unknown
            // +Callback Scene00009: Normal(CutScene, AutoFadeIn), id=HOUZAN
          }
          break;
        }
        if( param1 == 2005430 || param2 == 2005430 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013029 || param2 == 1013029 ) // ACTOR1 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012129 || param2 == 1012129 ) // ACTOR2 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012130 || param2 == 1012130 ) // ACTOR3 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012131 || param2 == 1012131 ) // ACTOR4 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00015( player ); // Scene00015: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1013071 || param2 == 1013071 ) // ACTOR7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=unknown
          }
          break;
        }
        if( param1 == 1013070 || param2 == 1013070 ) // ACTOR8 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013024 || param2 == 1013024 ) // ACTOR9 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1013031 || param2 == 1013031 ) // ACTOR10 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1013030 || param2 == 1013030 ) // ACTOR11 = YUGIRI
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1013269 || param2 == 1013269 ) // ACTOR12 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013270 || param2 == 1013270 ) // ACTOR13 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013271 || param2 == 1013271 ) // ACTOR14 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013272 || param2 == 1013272 ) // ACTOR15 = MESSENGER01601
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=MESSENGER01601
          break;
        }
        if( param1 == 1013032 || param2 == 1013032 ) // ACTOR16 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00026( player ); // Scene00026: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1013269 || param2 == 1013269 ) // ACTOR12 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013270 || param2 == 1013270 ) // ACTOR13 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013271 || param2 == 1013271 ) // ACTOR14 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013032 || param2 == 1013032 ) // ACTOR16 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013272 || param2 == 1013272 ) // ACTOR15 = MESSENGER01601
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=MESSENGER01601
          break;
        }
        if( param1 == 1013030 || param2 == 1013030 ) // ACTOR11 = YUGIRI
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1013031 || param2 == 1013031 ) // ACTOR10 = ALPHINAUD
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1013038 || param2 == 1013038 ) // ACTOR17 = ALPHINAUD
        {
          Scene00034( player ); // Scene00034: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1003995 || param2 == 1003995 ) // ACTOR18 = PAPASHAN
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=PAPASHAN
          break;
        }
        if( param1 == 1012843 || param2 == 1012843 ) // ACTOR19 = PAPASHAN_2
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=PAPASHAN_2
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna203:67137 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00008: Normal(QuestBattle, YesNo, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00009( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00009: Normal(CutScene, AutoFadeIn), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      //quest battle
      player.eventFinish( getId(), 1 );
      auto& pTeriMgr = Common::Service< Sapphire::World::Manager::TerritoryMgr >::ref();
      pTeriMgr.createAndJoinQuestBattle( player, 106 );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00015: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00016: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player ) //SEQ_4: ACTOR10, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player ) //SEQ_4: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player ) //SEQ_4: ACTOR14, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player ) //SEQ_4: ACTOR15, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00024: Normal(Talk, TargetCanMove), id=MESSENGER01601" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_4: ACTOR16, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player ) //SEQ_5: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00026: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_5: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player ) //SEQ_5: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player ) //SEQ_5: ACTOR14, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player ) //SEQ_5: ACTOR16, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player ) //SEQ_5: ACTOR15, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00031: Normal(Talk, TargetCanMove), id=MESSENGER01601" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player ) //SEQ_5: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00032: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player ) //SEQ_5: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00033: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00034: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00035: Normal(Talk, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna203:67137 calling Scene00036: Normal(Talk, TargetCanMove), id=PAPASHAN_2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna203 );
