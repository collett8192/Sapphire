// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil127 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil127() : Sapphire::ScriptAPI::EventScript( 66173 ){}; 
  ~SubWil127() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_4, 1 entries
  //SEQ_5, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1003941
  //ENEMY0 = 4097176
  //ENEMY1 = 4097181
  //ENEMY2 = 3986940
  //EOBJECT0 = 2001422
  //EOBJECT1 = 2001446
  //EOBJECT2 = 2001447
  //EOBJECT3 = 2001448
  //EOBJECT4 = 2001449
  //EOBJECT5 = 2001450
  //EOBJECT6 = 2001451
  //EOBJECT7 = 2001452
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000395
  //ITEM1 = 2000407

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=JOSPAIRE
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( type != 2 ) Scene00003( player ); // Scene00003: Normal(None), id=unknown
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( type != 2 ) Scene00004( player ); // Scene00004: NpcTrade(Talk, TargetCanMove), id=JOSPAIRE
        // +Callback Scene00005: Normal(Talk, TargetCanMove), id=JOSPAIRE
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 2001446 || param2 == 2001446 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001447 || param2 == 2001447 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001448 || param2 == 2001448 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00013( player ); // Scene00013: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001449 || param2 == 2001449 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00016( player ); // Scene00016: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      //seq 4 event item ITEM1 = UI8BL max stack ?
      case 4:
      {
        if( type != 2 ) Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=JOSPAIRE
        break;
      }
      //seq 5 event item ITEM0 = UI8CH max stack 1
      //seq 5 event item ITEM1 = UI8CL max stack ?
      case 5:
      {
        if( param1 == 2001450 || param2 == 2001450 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 4097176 || param2 == 4097176 ) // ENEMY0 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2001451 || param2 == 2001451 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 4097181 || param2 == 4097181 ) // ENEMY1 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2001452 || param2 == 2001452 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 3986940 || param2 == 3986940 ) // ENEMY2 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(Message, PopBNpc), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack ?
      case 255:
      {
        if( type != 2 ) Scene00026( player ); // Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=JOSPAIRE
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
    player.setQuestUI8BH( getId(), 1 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 4 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.setQuestBitFlag8( getId(), 4, false );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.setQuestUI8BL( getId(), 0 );
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestBitFlag8( getId(), 1, false );
          player.setQuestBitFlag8( getId(), 2, false );
          player.setQuestBitFlag8( getId(), 3, false );
          player.setQuestUI8CH( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil127:66173 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=JOSPAIRE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil127:66173 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil127:66173 calling Scene00004: NpcTrade(Talk, TargetCanMove), id=JOSPAIRE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00005( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil127:66173 calling Scene00005: Normal(Talk, TargetCanMove), id=JOSPAIRE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_3: EOBJECT1, UI8AL = 4, Flag8(1)=True
  {
    player.sendDebug( "SubWil127:66173 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq3( player );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: EOBJECT2, UI8AL = 4, Flag8(2)=True
  {
    player.sendDebug( "SubWil127:66173 calling Scene00010: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq3( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: EOBJECT3, UI8AL = 4, Flag8(3)=True
  {
    player.sendDebug( "SubWil127:66173 calling Scene00013: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: EOBJECT4, UI8AL = 4, Flag8(4)=True
  {
    player.sendDebug( "SubWil127:66173 calling Scene00016: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 4, true );
    checkProgressSeq3( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_4: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil127:66173 calling Scene00019: Normal(Talk, TargetCanMove), id=JOSPAIRE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_5: EOBJECT5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubWil127:66173 calling Scene00020: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_5: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil127:66173 calling Scene00021: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_5: EOBJECT6, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "SubWil127:66173 calling Scene00022: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_5: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil127:66173 calling Scene00023: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_5: EOBJECT7, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "SubWil127:66173 calling Scene00024: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_5: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil127:66173 calling Scene00025: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil127:66173 calling Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=JOSPAIRE" );
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
    player.playScene( getId(), 26, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil127 );
