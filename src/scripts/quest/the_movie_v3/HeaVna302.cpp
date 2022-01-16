// FFXIVTheMovie.ParserV3.6
// param used:
//SCENE_9 = TEMPLEKIGHTGATE
//SCENE_13 = ALPHINAUD
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna302 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna302() : Sapphire::ScriptAPI::EventScript( 67139 ){}; 
  ~HeaVna302() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1012579
  //ACTOR1 = 1012581
  //ACTOR2 = 1012586
  //ACTOR3 = 1012585
  //ACTOR4 = 1012580
  //ACTOR5 = 1011223
  //ACTOR6 = 1013197
  //ACTOR7 = 1012588
  //ACTOR8 = 1012589
  //CUTSCENEN01 = 804
  //CUTSCENEN02 = 805
  //CUTSCENEN03 = 806
  //LOCACTOR0 = 5852760
  //LOCACTOR10 = 1012443
  //LOCACTOR11 = 5852706
  //POPRANGE0 = 5862870

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012579 || param2 == 1012579 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1012581 || param2 == 1012581 ) // ACTOR1 = HAURCHEFANT
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HAURCHEFANT
          break;
        }
        if( param1 == 1012586 || param2 == 1012586 ) // ACTOR2 = TATARU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
          // +Callback Scene00004: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012585 || param2 == 1012585 ) // ACTOR3 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1012580 || param2 == 1012580 ) // ACTOR4 = TATARU
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1012581 || param2 == 1012581 ) // ACTOR1 = HAURCHEFANT
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HAURCHEFANT
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1011223 || param2 == 1011223 ) // ACTOR5 = TEMPLEKIGHTGATE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=TEMPLEKIGHTGATE
            // +Callback Scene00009: Normal(CutScene, AutoFadeIn), id=TEMPLEKIGHTGATE
          }
          break;
        }
        if( param1 == 1013197 || param2 == 1013197 ) // ACTOR6 = TATARU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1012581 || param2 == 1012581 ) // ACTOR1 = HAURCHEFANT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HAURCHEFANT
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012588 || param2 == 1012588 ) // ACTOR7 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          // +Callback Scene00013: Normal(CutScene), id=ALPHINAUD
          break;
        }
        if( param1 == 1012589 || param2 == 1012589 ) // ACTOR8 = ESTINIEN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013197 || param2 == 1013197 ) // ACTOR6 = TATARU
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=TATARU
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
    player.sendDebug( "HeaVna302:67139 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna302:67139 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00002: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00004: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00006: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00007: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00008: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=TEMPLEKIGHTGATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00009( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00009: Normal(CutScene, AutoFadeIn), id=TEMPLEKIGHTGATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00010: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00011: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00013: Normal(CutScene), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00014: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna302:67139 calling Scene00015: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna302 );
