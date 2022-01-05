// FFXIVTheMovie.ParserV3.6
// id hint used:
//SCENE_3 = ADALBERT
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc901 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc901() : Sapphire::ScriptAPI::EventScript( 66572 ){}; 
  ~GaiUsc901() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 4 entries
  //SEQ_3, 3 entries
  //SEQ_4, 2 entries
  //SEQ_5, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006690
  //ACTOR1 = 1006578
  //ACTOR2 = 1006633
  //ACTOR3 = 1006712
  //ACTOR4 = 1006713
  //CUTSCENE01 = 117
  //CUTSCENE02 = 261
  //CUTSCENEAFTER01 = 294
  //CUTSCENEAFTER02 = 264
  //EOBJECT0 = 2002252
  //EVENTACTIONTOUCHMIDDLE = 46
  //INSTANCEDUNGEON0 = 20007
  //POPRANGE0 = 4309569
  //QSTCHECK01 = 66236
  //QSTCHECK02 = 66237
  //QSTCHECK03 = 66238
  //REWARDMOUNTOPEN = 17
  //TERRITORYTYPE0 = 140
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKIMAGECONTENTBATTLE = 114

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, SystemTalk, CanCancel), id=unknown
        // +Callback Scene00001: Normal(CutScene, QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=KANRIKAN
        break;
      }
      case 2:
      {
        if( param1 == 1006633 || param2 == 1006633 ) // ACTOR2 = ADALBERT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(CutScene), id=ADALBERT
          }
          break;
        }
        if( param1 == 1006712 || param2 == 1006712 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006713 || param2 == 1006713 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006578 || param2 == 1006578 ) // ACTOR1 = KANRIKAN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=KANRIKAN
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2002252 || param2 == 2002252 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Message), id=unknown
          }
          break;
        }
        if( param1 == 1006633 || param2 == 1006633 ) // ACTOR2 = ADALBERT
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ADALBERT
          break;
        }
        if( param1 == 1006578 || param2 == 1006578 ) // ACTOR1 = KANRIKAN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=KANRIKAN
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1006633 || param2 == 1006633 ) // ACTOR2 = ADALBERT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ADALBERT
          break;
        }
        if( param1 == 1006578 || param2 == 1006578 ) // ACTOR1 = KANRIKAN
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=KANRIKAN
          break;
        }
        break;
      }
      case 5:
      {
        if( type != 2 ) Scene00013( player ); // Scene00013: Normal(CutScene, AutoFadeIn), id=unknown
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KANRIKAN
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
    player.updateQuest( getId(), 2 );
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
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc901:66572 calling Scene00000: Normal(QuestOffer, SystemTalk, CanCancel), id=unknown" );
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
    player.sendDebug( "GaiUsc901:66572 calling Scene00001: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc901:66572 calling Scene00002: Normal(Talk, TargetCanMove), id=KANRIKAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc901:66572 calling Scene00003: Normal(CutScene), id=ADALBERT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc901:66572 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc901:66572 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc901:66572 calling Scene00006: Normal(Talk, TargetCanMove), id=KANRIKAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_3: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc901:66572 calling Scene00008: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc901:66572 calling Scene00009: Normal(Talk, TargetCanMove), id=ADALBERT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc901:66572 calling Scene00010: Normal(Talk, TargetCanMove), id=KANRIKAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_4: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc901:66572 calling Scene00011: Normal(Talk, TargetCanMove), id=ADALBERT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_4: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc901:66572 calling Scene00012: Normal(Talk, TargetCanMove), id=KANRIKAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_5: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc901:66572 calling Scene00013: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc901:66572 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KANRIKAN" );
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

EXPOSE_SCRIPT( GaiUsc901 );
