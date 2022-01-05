// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc811 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc811() : Sapphire::ScriptAPI::EventScript( 66571 ){}; 
  ~GaiUsc811() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 10 entries
  //SEQ_2, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006614
  //ACTOR1 = 1007488
  //ENEMY0 = 4309128
  //ENEMY1 = 4309129
  //ENEMY2 = 4309130
  //ENEMY3 = 4309131
  //ENEMY4 = 4309132
  //ENEMY5 = 4309133
  //EOBJECT0 = 2002455
  //EOBJECT1 = 2002456
  //EOBJECT2 = 2002457
  //ITEM0 = 2000782

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FALKBRYDA
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack ?
      case 1:
      {
        if( param1 == 2002455 || param2 == 2002455 ) // EOBJECT0 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(Inventory), id=unknown
          // +Callback Scene00003: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown
          break;
        }
        if( param1 == 4309128 || param2 == 4309128 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4309129 || param2 == 4309129 ) // ENEMY1 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 2002456 || param2 == 2002456 ) // EOBJECT1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(Inventory), id=unknown
          // +Callback Scene00005: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown
          break;
        }
        if( param1 == 4309130 || param2 == 4309130 ) // ENEMY2 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4309131 || param2 == 4309131 ) // ENEMY3 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 2002457 || param2 == 2002457 ) // EOBJECT2 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(Inventory), id=unknown
          // +Callback Scene00007: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown
          break;
        }
        if( param1 == 4309132 || param2 == 4309132 ) // ENEMY4 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4309133 || param2 == 4309133 ) // ENEMY5 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 1006614 || param2 == 1006614 ) // ACTOR0 = FALKBRYDA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=FALKBRYDA
          break;
        }
        break;
      }
      case 2:
      {
        if( type != 2 ) Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=FALKBRYDA
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00010( player ); // Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RADOLF
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
    player.setQuestBitFlag8( getId(), 1, false );
    player.setQuestBitFlag8( getId(), 2, false );
    player.setQuestBitFlag8( getId(), 3, false );
    player.setQuestUI8CH( getId(), 0 );
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc811:66571 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc811:66571 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc811:66571 calling Scene00002: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc811:66571 calling Scene00003: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }



  void Scene00004( Entity::Player& player ) //SEQ_1: EOBJECT1, <No Var>, Flag8(2)=True
  {
    player.sendDebug( "GaiUsc811:66571 calling Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player ) //SEQ_1: EOBJECT1, <No Var>, Flag8(2)=True
  {
    player.sendDebug( "GaiUsc811:66571 calling Scene00005: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }



  void Scene00006( Entity::Player& player ) //SEQ_1: EOBJECT2, <No Var>, Flag8(3)=True
  {
    player.sendDebug( "GaiUsc811:66571 calling Scene00006: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player ) //SEQ_1: EOBJECT2, <No Var>, Flag8(3)=True
  {
    player.sendDebug( "GaiUsc811:66571 calling Scene00007: Normal(Message, PopBNpc, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }



  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc811:66571 calling Scene00008: Normal(Talk, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc811:66571 calling Scene00009: Normal(Talk, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc811:66571 calling Scene00010: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RADOLF" );
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
    player.playScene( getId(), 10, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsc811 );
