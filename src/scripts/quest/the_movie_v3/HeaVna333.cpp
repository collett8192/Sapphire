// FFXIVTheMovie.ParserV3.6
// param used:
//SCENE_3 = CID
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna333 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna333() : Sapphire::ScriptAPI::EventScript( 67170 ){}; 
  ~HeaVna333() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1012589
  //ACTOR1 = 1013168
  //ACTOR2 = 1012745
  //ACTOR3 = 1013169
  //ACTOR4 = 1013170
  //ACTOR5 = 1013177
  //ACTOR6 = 5010000
  //ACTOR7 = 1012746
  //CUTSCENEN01 = 838
  //CUTSCENEN02 = 839
  //CUTSCENEN03 = 840
  //CUTSCENEN04 = 841
  //CUTSCENEN05 = 842
  //CUTSCENEN10 = 945
  //INSTANCEDUNGEON0 = 39
  //LOCACTOR0 = 5860758
  //LOCACTOR1 = 5860759
  //LOCACTOR2 = 5860756
  //LOCSCREENIMAGE0 = 307
  //POPRANGE0 = 5860775
  //TERRITORYTYPE0 = 400

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ESTINIEN
        break;
      }
      case 1:
      {
        if( param1 == 1013168 || param2 == 1013168 ) // ACTOR1 = CID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove, AutoFadeIn, ENpcBind), id=CID
            // +Callback Scene00003: Normal(CutScene, Message), id=CID
          }
          break;
        }
        if( param1 == 1012745 || param2 == 1012745 ) // ACTOR2 = ESTINIEN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013169 || param2 == 1013169 ) // ACTOR3 = BIGGS
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1013170 || param2 == 1013170 ) // ACTOR4 = WEDGE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        if( param1 == 1013177 || param2 == 1013177 ) // ACTOR5 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1012745 || param2 == 1012745 ) // ACTOR2 = ESTINIEN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013168 || param2 == 1013168 ) // ACTOR1 = CID
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1013169 || param2 == 1013169 ) // ACTOR3 = BIGGS
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1013170 || param2 == 1013170 ) // ACTOR4 = WEDGE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        if( param1 == 1013177 || param2 == 1013177 ) // ACTOR5 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( type != 2 ) Scene00013( player ); // Scene00013: Normal(CutScene), id=unknown
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ESTINIEN
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna333:67170 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00002: Normal(Talk, TargetCanMove, AutoFadeIn, ENpcBind), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00003: Normal(CutScene, Message), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00004: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00005: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00006: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00008: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00009: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00010: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00011: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00013: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna333:67170 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ESTINIEN" );
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
    player.playScene( getId(), 14, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna333 );
