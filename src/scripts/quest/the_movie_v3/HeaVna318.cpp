// FFXIVTheMovie.ParserV3.6
// param used:
//SCENE_5 = DOORMANLOTUS
//SCENE_12 = ESTINIEN
//_SCENE_12 = Z
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna318 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna318() : Sapphire::ScriptAPI::EventScript( 67155 ){}; 
  ~HeaVna318() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 3 entries
  //SEQ_4, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1012664
  //ACTOR1 = 1012846
  //ACTOR2 = 1012667
  //ACTOR3 = 1000460
  //ACTOR4 = 1012668
  //ACTOR5 = 1012077
  //ACTOR6 = 1015174
  //ACTOR7 = 1012675
  //CUTSCENEN01 = 821
  //CUTSCENEN02 = 822
  //LOCACTOR0 = 1012443
  //LOCACTOR1 = 1012456
  //LOCACTOR10 = 1011887
  //LOCACTOR11 = 1008184
  //LOCACTOR12 = 1012461
  //LOCACTOR13 = 1012462
  //LOCACTOR14 = 1008362
  //LOCMOTION0 = 958
  //LOCMUSIC0 = 73
  //POPRANGE0 = 5912460

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( param1 == 1012846 || param2 == 1012846 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1012667 || param2 == 1012667 ) // ACTOR2 = ESTINIEN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1000460 || param2 == 1000460 ) // ACTOR3 = DOORMANLOTUS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=DOORMANLOTUS
            // +Callback Scene00005: Normal(CutScene), id=DOORMANLOTUS
          }
          break;
        }
        if( param1 == 1012846 || param2 == 1012846 ) // ACTOR1 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012667 || param2 == 1012667 ) // ACTOR2 = ESTINIEN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1012846 || param2 == 1012846 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1000460 || param2 == 1000460 ) // ACTOR3 = DOORMANLOTUS
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=DOORMANLOTUS
          break;
        }
        if( param1 == 1012667 || param2 == 1012667 ) // ACTOR2 = ESTINIEN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1012667 || param2 == 1012667 ) // ACTOR2 = ESTINIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=ESTINIEN
            // +Callback Scene00012: Normal(CutScene, AutoFadeIn), id=ESTINIEN
          }
          break;
        }
        if( param1 == 1012846 || param2 == 1012846 ) // ACTOR1 = ALPHINAUD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012668 || param2 == 1012668 ) // ACTOR4 = ICEHEART
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012077 || param2 == 1012077 ) // ACTOR5 = MOGLIN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MOGLIN
          break;
        }
        if( param1 == 1015174 || param2 == 1015174 ) // ACTOR6 = MOGC01622
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MOGC01622
          break;
        }
        if( param1 == 1012675 || param2 == 1012675 ) // ACTOR7 = ICEHEART
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ICEHEART
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
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna318:67155 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00004: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=DOORMANLOTUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00005( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00005: Normal(CutScene), id=DOORMANLOTUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00007: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_3: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00009: Normal(Talk, TargetCanMove), id=DOORMANLOTUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00010: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_4: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00012( Entity::Player& player ) //SEQ_4: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00012: Normal(CutScene, AutoFadeIn), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_4: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00014: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MOGLIN" );
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
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00016: Normal(Talk, TargetCanMove), id=MOGC01622" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna318:67155 calling Scene00017: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna318 );
