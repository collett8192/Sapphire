// FFXIVTheMovie.ParserV3.6
// id hint used:
//SCENE_3 = RAUBAHN
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class XxaFst502 : public Sapphire::ScriptAPI::EventScript
{
public:
  XxaFst502() : Sapphire::ScriptAPI::EventScript( 69409 ){}; 
  ~XxaFst502() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 8 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006646
  //ACTOR1 = 1006657
  //ACTOR2 = 5010000
  //ACTOR3 = 1006662
  //ACTOR4 = 1006663
  //ACTOR5 = 1006664
  //ACTOR6 = 1006660
  //ACTOR7 = 1006661
  //ACTOR8 = 1007682
  //ACTOR9 = 1007683
  //CONTENTSTART = 15
  //CUTSCENE01 = 265
  //INSTANCEDUNGEON0 = 15
  //POPRANGE0 = 4332876
  //QSTACCEPTCHECK01 = 66582
  //QSTACCEPTCHECK02 = 66672
  //UNLOCKIMAGEDUNGEON = 98

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EDELSTEIN
        break;
      }
      case 1:
      {
        if( param1 == 1006657 || param2 == 1006657 ) // ACTOR1 = RAUBAHN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=RAUBAHN
            // +Callback Scene00003: Normal(CutScene, FadeIn), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1006646 || param2 == 1006646 ) // ACTOR0 = EDELSTEIN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=EDELSTEIN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1006662 || param2 == 1006662 ) // ACTOR3 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006663 || param2 == 1006663 ) // ACTOR4 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006664 || param2 == 1006664 ) // ACTOR5 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006660 || param2 == 1006660 ) // ACTOR6 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006661 || param2 == 1006661 ) // ACTOR7 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007682 || param2 == 1007682 ) // ACTOR8 = MINFILIA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1007683 || param2 == 1007683 ) // ACTOR9 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1006657 || param2 == 1006657 ) // ACTOR1 = RAUBAHN
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00013( player ); // Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "XxaFst502:69409 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown" );
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
    player.sendDebug( "XxaFst502:69409 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "XxaFst502:69409 calling Scene00002: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "XxaFst502:69409 calling Scene00003: Normal(CutScene, FadeIn), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaFst502:69409 calling Scene00004: Normal(Talk, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaFst502:69409 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaFst502:69409 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaFst502:69409 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaFst502:69409 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaFst502:69409 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaFst502:69409 calling Scene00010: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaFst502:69409 calling Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaFst502:69409 calling Scene00012: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "XxaFst502:69409 calling Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN" );
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
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( XxaFst502 );
