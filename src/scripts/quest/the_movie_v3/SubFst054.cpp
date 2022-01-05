// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst054 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst054() : Sapphire::ScriptAPI::EventScript( 65696 ){}; 
  ~SubFst054() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 9 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000494
  //ENEMY0 = 1886902
  //ENEMY1 = 1886903
  //ENEMY2 = 1887083
  //ENEMY3 = 1887164
  //ENEMY4 = 1887165
  //ENEMY5 = 1887166
  //EOBJECT0 = 2000043
  //EOBJECT1 = 2000044
  //EOBJECT2 = 2000045
  //ITEM0 = 2000100
  //SEQ0ACTOR0 = 0
  //SEQ1EOBJECT0 = 1
  //SEQ1EOBJECT0USEITEMNO = 99
  //SEQ1EOBJECT0USEITEMOK = 100
  //SEQ1EOBJECT1 = 2
  //SEQ1EOBJECT1USEITEMNO = 97
  //SEQ1EOBJECT1USEITEMOK = 98
  //SEQ1EOBJECT2 = 3
  //SEQ1EOBJECT2USEITEMNO = 95
  //SEQ1EOBJECT2USEITEMOK = 96
  //SEQ2ACTOR0 = 4

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=FINNEA
        // +Callback Scene00004: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FINNEA
        break;
      }
      //seq 1 event item ITEM0 = UI8DL max stack ?
      case 1:
      {
        if( param1 == 2000043 || param2 == 2000043 ) // EOBJECT0 = unknown
        {
          Scene00001( player ); // Scene00001: Normal(Inventory), id=unknown
          // +Callback Scene00100: Normal(Message), id=unknown
          break;
        }
        if( param1 == 1886902 || param2 == 1886902 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
          break;
        }
        if( param1 == 1886903 || param2 == 1886903 ) // ENEMY1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
          break;
        }
        if( param1 == 2000044 || param2 == 2000044 ) // EOBJECT1 = unknown
        {
          Scene00099( player ); // Scene00099: Normal(None), id=unknown
          break;
        }
        if( param1 == 1887083 || param2 == 1887083 ) // ENEMY2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 2 )
          {
            player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
          break;
        }
        if( param1 == 1887164 || param2 == 1887164 ) // ENEMY3 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 2 )
          {
            player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
          break;
        }
        if( param1 == 2000045 || param2 == 2000045 ) // EOBJECT2 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(Inventory), id=unknown
          // +Callback Scene00098: Normal(Message), id=unknown
          break;
        }
        if( param1 == 1887165 || param2 == 1887165 ) // ENEMY4 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 2 )
          {
            player.setQuestUI8CL( getId(), player.getQuestUI8CL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
          break;
        }
        if( param1 == 1887166 || param2 == 1887166 ) // ENEMY5 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 2 )
          {
            Scene00097( player ); // Scene00097: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( type != 2 ) Scene00003( player ); // Scene00003: Normal(Inventory), id=unknown
        // +Callback Scene00096: Normal(Message), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 2 )
      if( player.getQuestUI8BL( getId() ) == 2 )
        if( player.getQuestUI8CL( getId() ) == 2 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.setQuestBitFlag8( getId(), 1, false );
          player.setQuestBitFlag8( getId(), 2, false );
          player.setQuestBitFlag8( getId(), 3, false );
          player.setQuestUI8DL( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst054:65696 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=FINNEA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00004( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00004( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst054:65696 calling Scene00004: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FINNEA" );
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
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00001( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, Flag8(1)=True
  {
    player.sendDebug( "SubFst054:65696 calling Scene00001: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00100( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00100( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, Flag8(1)=True
  {
    player.sendDebug( "SubFst054:65696 calling Scene00100: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 100, NONE, callback );
  }



  void Scene00099( Entity::Player& player ) //SEQ_1: EOBJECT1, <No Var>, Flag8(2)=True
  {
    player.sendDebug( "SubFst054:65696 calling Scene00099: Normal(None), id=unknown" );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq1( player );
  }



  void Scene00002( Entity::Player& player ) //SEQ_1: EOBJECT2, <No Var>, Flag8(3)=True
  {
    player.sendDebug( "SubFst054:65696 calling Scene00002: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00098( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00098( Entity::Player& player ) //SEQ_1: EOBJECT2, <No Var>, Flag8(3)=True
  {
    player.sendDebug( "SubFst054:65696 calling Scene00098: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 98, NONE, callback );
  }


  void Scene00097( Entity::Player& player ) //SEQ_1: ENEMY5, UI8CL = 2, <No Flag>
  {
    player.sendDebug( "SubFst054:65696 calling Scene00097: Normal(None), id=unknown" );
    player.setQuestUI8CL( getId(), player.getQuestUI8CL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00003( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst054:65696 calling Scene00003: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00096( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00096( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst054:65696 calling Scene00096: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 96, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubFst054 );
