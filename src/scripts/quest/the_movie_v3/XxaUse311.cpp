// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class XxaUse311 : public Sapphire::ScriptAPI::EventScript
{
public:
  XxaUse311() : Sapphire::ScriptAPI::EventScript( 69421 ){}; 
  ~XxaUse311() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 5 entries
  //SEQ_4, 5 entries
  //SEQ_5, 1 entries
  //SEQ_6, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1009097
  //ACTOR1 = 1009098
  //ACTOR10 = 5010000
  //ACTOR2 = 1033555
  //ACTOR3 = 1009119
  //ACTOR4 = 1009120
  //ACTOR5 = 1009121
  //ACTOR6 = 1009116
  //ACTOR7 = 1009124
  //ACTOR8 = 1009125
  //ACTOR9 = 1009126
  //BINDACTOR0 = 4868018
  //BINDACTOR1 = 4868019
  //BINDACTOR2 = 4868015
  //CUTSCENEN01 = 534
  //CUTSCENEN02 = 535
  //EVENTRANGE0 = 8361398
  //INSTANCEDUNGEON0 = 20022
  //LOCACTOR10 = 1009667
  //LOCPOSPC = 8361516
  //POPRANGE0 = 4868026
  //QSTACCEPTCHECK01 = 66985
  //QSTACCEPTCHECK02 = 66986
  //QSTACCEPTCHECK03 = 66987
  //QSTACCEPTCHECK04 = 66988
  //TERRITORYTYPE0 = 152
  //UNLOCKDUNGEONRAMUHHARD = 222

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=LIEUTENANT01448
        break;
      }
      case 1:
      {
        if( param1 == 1009098 || param2 == 1009098 ) // ACTOR1 = MAXIO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=MAXIO
          }
          break;
        }
        if( param1 == 1009097 || param2 == 1009097 ) // ACTOR0 = LIEUTENANT01448
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LIEUTENANT01448
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1033555 || param2 == 1033555 ) // ACTOR2 = MAXIO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=MAXIO
          }
          break;
        }
        if( param1 == 1009097 || param2 == 1009097 ) // ACTOR0 = LIEUTENANT01448
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=LIEUTENANT01448
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1009119 || param2 == 1009119 ) // ACTOR3 = PAPALYMO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=PAPALYMO
          }
          break;
        }
        if( param1 == 1009120 || param2 == 1009120 ) // ACTOR4 = THANCRED
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1009121 || param2 == 1009121 ) // ACTOR5 = YSHTOLA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1009116 || param2 == 1009116 ) // ACTOR6 = YDA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1009097 || param2 == 1009097 ) // ACTOR0 = LIEUTENANT01448
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=LIEUTENANT01448
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 8361398 || param2 == 8361398 ) // EVENTRANGE0 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(CutScene, AutoFadeIn), id=unknown
          // +Callback Scene00012: Normal(FadeIn, Dismount), id=unknown
          break;
        }
        if( param1 == 1009124 || param2 == 1009124 ) // ACTOR7 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009125 || param2 == 1009125 ) // ACTOR8 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009126 || param2 == 1009126 ) // ACTOR9 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009097 || param2 == 1009097 ) // ACTOR0 = LIEUTENANT01448
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=LIEUTENANT01448
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1009097 || param2 == 1009097 ) // ACTOR0 = LIEUTENANT01448
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=LIEUTENANT01448
          break;
        }
        break;
      }
      case 6:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00018( player ); // Scene00018: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1009097 || param2 == 1009097 ) // ACTOR0 = LIEUTENANT01448
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=LIEUTENANT01448
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00020( player ); // Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LIEUTENANT01448
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
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.setQuestBitFlag8( getId(), 1, false );
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 6 );
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=LIEUTENANT01448" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00003: Normal(Talk, TargetCanMove), id=LIEUTENANT01448" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00005: Normal(Talk, TargetCanMove), id=LIEUTENANT01448" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_3: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00007: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00009: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00010: Normal(Talk, TargetCanMove), id=LIEUTENANT01448" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_4: EVENTRANGE0, <No Var>, Flag8(1)=True
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00011: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00012( Entity::Player& player ) //SEQ_4: EVENTRANGE0, <No Var>, Flag8(1)=True
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00012: Normal(FadeIn, Dismount), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player ) //SEQ_4: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00016: Normal(Talk, TargetCanMove), id=LIEUTENANT01448" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_5: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00017: Normal(Talk, TargetCanMove), id=LIEUTENANT01448" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_6: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00018: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_6: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00019: Normal(Talk, TargetCanMove), id=LIEUTENANT01448" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse311:69421 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LIEUTENANT01448" );
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
    player.playScene( getId(), 20, NONE, callback );
  }
};

EXPOSE_SCRIPT( XxaUse311 );
