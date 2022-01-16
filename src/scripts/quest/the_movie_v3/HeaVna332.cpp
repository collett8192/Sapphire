// FFXIVTheMovie.ParserV3.6
// param used:
//SCENE_13 = TEMPLEKIGHTGATE
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna332 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna332() : Sapphire::ScriptAPI::EventScript( 67169 ){}; 
  ~HeaVna332() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 5 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1012733
  //ACTOR1 = 1012734
  //ACTOR2 = 1012717
  //ACTOR3 = 1012718
  //ACTOR4 = 1012719
  //ACTOR5 = 1012744
  //ACTOR6 = 1011223
  //ACTOR7 = 1012589
  //CUTSCENEN01 = 836
  //LOCACTOR0 = 5860488
  //POPRANGE0 = 5827491

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012733 || param2 == 1012733 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1012734 || param2 == 1012734 ) // ACTOR1 = YUGIRI
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012717 || param2 == 1012717 ) // ACTOR2 = CID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=CID
          }
          break;
        }
        if( param1 == 1012733 || param2 == 1012733 ) // ACTOR0 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012734 || param2 == 1012734 ) // ACTOR1 = YUGIRI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1012718 || param2 == 1012718 ) // ACTOR3 = BIGGS
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1012719 || param2 == 1012719 ) // ACTOR4 = WEDGE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1012744 || param2 == 1012744 ) // ACTOR5 = ESTINIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=ESTINIEN
          }
          break;
        }
        if( param1 == 1012717 || param2 == 1012717 ) // ACTOR2 = CID
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1012718 || param2 == 1012718 ) // ACTOR3 = BIGGS
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1012719 || param2 == 1012719 ) // ACTOR4 = WEDGE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1011223 || param2 == 1011223 ) // ACTOR6 = TEMPLEKIGHTGATE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=TEMPLEKIGHTGATE
            // +Callback Scene00013: Normal(CutScene, AutoFadeIn), id=TEMPLEKIGHTGATE
          }
          break;
        }
        if( param1 == 1012717 || param2 == 1012717 ) // ACTOR2 = CID
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1012718 || param2 == 1012718 ) // ACTOR3 = BIGGS
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1012719 || param2 == 1012719 ) // ACTOR4 = WEDGE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012589 || param2 == 1012589 ) // ACTOR7 = ESTINIEN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012717 || param2 == 1012717 ) // ACTOR2 = CID
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1012718 || param2 == 1012718 ) // ACTOR3 = BIGGS
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1012719 || param2 == 1012719 ) // ACTOR4 = WEDGE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=WEDGE
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
    player.sendDebug( "HeaVna332:67169 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna332:67169 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00003: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00006: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00007: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00009: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00010: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00011: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_3: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00012: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=TEMPLEKIGHTGATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player ) //SEQ_3: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00013: Normal(CutScene, AutoFadeIn), id=TEMPLEKIGHTGATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00014: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00015: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00016: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ESTINIEN" );
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
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00018: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00019: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna332:67169 calling Scene00020: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna332 );
