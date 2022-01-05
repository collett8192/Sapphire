// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil122 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil122() : Sapphire::ScriptAPI::EventScript( 66168 ){}; 
  ~SubWil122() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 6 entries
  //SEQ_3, 5 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1003939
  //ACTOR1 = 1003952
  //ACTOR2 = 1003953
  //ACTOR3 = 1003954
  //ACTOR4 = 1003955
  //ACTOR5 = 1003956
  //EOBJECT0 = 2001423
  //EOBJECT1 = 2001424
  //EOBJECT2 = 2001425
  //EOBJECT3 = 2001453
  //EOBJECT4 = 2001454
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000393
  //ITEM1 = 2000412

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=BENEGER
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 2001423 || param2 == 2001423 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00001( player ); // Scene00001: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2001424 || param2 == 2001424 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00004( player ); // Scene00004: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2001425 || param2 == 2001425 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00007( player ); // Scene00007: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2001453 || param2 == 2001453 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00010( player ); // Scene00010: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2001454 || param2 == 2001454 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00013( player ); // Scene00013: Normal(Inventory), id=unknown
          }
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      //seq 2 event item ITEM1 = UI8BL max stack 1
      case 2:
      {
        if( param1 == 1003939 || param2 == 1003939 ) // ACTOR0 = BENEGER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=BENEGER
          }
          break;
        }
        if( param1 == 2001423 || param2 == 2001423 ) // EOBJECT0 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001424 || param2 == 2001424 ) // EOBJECT1 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001425 || param2 == 2001425 ) // EOBJECT2 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001453 || param2 == 2001453 ) // EOBJECT3 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001454 || param2 == 2001454 ) // EOBJECT4 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8DH max stack ?
      //seq 3 event item ITEM1 = UI8DL max stack 1
      case 3:
      {
        if( param1 == 1003952 || param2 == 1003952 ) // ACTOR1 = MOBA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00028: Normal(Talk, TargetCanMove), id=MOBA
            // +Callback Scene00030: Normal(Talk, TargetCanMove), id=MOBA
          }
          break;
        }
        if( param1 == 1003953 || param2 == 1003953 ) // ACTOR2 = MOBB
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00031( player ); // Scene00031: NpcTrade(Talk, TargetCanMove), id=MOBB
            // +Callback Scene00032: Normal(Talk, TargetCanMove), id=MOBB
            // +Callback Scene00034: Normal(Talk, TargetCanMove), id=MOBB
          }
          break;
        }
        if( param1 == 1003954 || param2 == 1003954 ) // ACTOR3 = MOBC
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00035( player ); // Scene00035: NpcTrade(Talk, TargetCanMove), id=MOBC
            // +Callback Scene00036: Normal(Talk, TargetCanMove), id=MOBC
            // +Callback Scene00038: Normal(Talk, TargetCanMove), id=MOBC
          }
          break;
        }
        if( param1 == 1003955 || param2 == 1003955 ) // ACTOR4 = MOBD
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00039( player ); // Scene00039: NpcTrade(Talk, TargetCanMove), id=MOBD
            // +Callback Scene00040: Normal(Talk, TargetCanMove), id=MOBD
            // +Callback Scene00042: Normal(Talk, TargetCanMove), id=MOBD
          }
          break;
        }
        if( param1 == 1003956 || param2 == 1003956 ) // ACTOR5 = MOBE
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00043( player ); // Scene00043: NpcTrade(Talk, TargetCanMove), id=MOBE
            // +Callback Scene00044: Normal(Talk, TargetCanMove), id=MOBE
            // +Callback Scene00046: Normal(Talk, TargetCanMove), id=MOBE
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      //seq 255 event item ITEM1 = UI8BL max stack 1
      case 255:
      {
        if( param1 == 1003939 || param2 == 1003939 ) // ACTOR0 = BENEGER
        {
          Scene00047( player ); // Scene00047: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BENEGER
          break;
        }
        if( param1 == 1003952 || param2 == 1003952 ) // ACTOR1 = MOBA
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=MOBA
          break;
        }
        if( param1 == 1003953 || param2 == 1003953 ) // ACTOR2 = MOBB
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=MOBB
          break;
        }
        if( param1 == 1003954 || param2 == 1003954 ) // ACTOR3 = MOBC
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=MOBC
          break;
        }
        if( param1 == 1003955 || param2 == 1003955 ) // ACTOR4 = MOBD
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=MOBD
          break;
        }
        if( param1 == 1003956 || param2 == 1003956 ) // ACTOR5 = MOBE
        {
          Scene00052( player ); // Scene00052: Normal(Talk, TargetCanMove), id=MOBE
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
    if( player.getQuestUI8AL( getId() ) == 5 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.setQuestBitFlag8( getId(), 4, false );
      player.setQuestBitFlag8( getId(), 5, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 3 );
      player.setQuestUI8DH( getId(), 1 );
      player.setQuestUI8DL( getId(), 1 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
            if( player.getQuestUI8CL( getId() ) == 1 )
            {
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8BH( getId(), 0 );
              player.setQuestUI8BL( getId(), 0 );
              player.setQuestUI8CH( getId(), 0 );
              player.setQuestUI8CL( getId(), 0 );
              player.setQuestBitFlag8( getId(), 1, false );
              player.setQuestBitFlag8( getId(), 2, false );
              player.setQuestBitFlag8( getId(), 3, false );
              player.setQuestBitFlag8( getId(), 4, false );
              player.setQuestBitFlag8( getId(), 5, false );
              player.setQuestUI8DH( getId(), 0 );
              player.setQuestUI8DL( getId(), 0 );
              player.updateQuest( getId(), 255 );
            }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil122:66168 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=BENEGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 5, Flag8(1)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00001: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8AL = 5, Flag8(2)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: EOBJECT2, UI8AL = 5, Flag8(3)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00007: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: EOBJECT3, UI8AL = 5, Flag8(4)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00010: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 4, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_1: EOBJECT4, UI8AL = 5, Flag8(5)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00013: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 5, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_2: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00016: Normal(Talk, TargetCanMove), id=BENEGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil122:66168 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00020( Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil122:66168 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00022( Entity::Player& player ) //SEQ_2: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil122:66168 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00024( Entity::Player& player ) //SEQ_2: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil122:66168 calling Scene00024: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00026( Entity::Player& player ) //SEQ_2: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil122:66168 calling Scene00026: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00027( Entity::Player& player ) //SEQ_3: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00027: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00028( player );
      }
    };
    player.playScene( getId(), 27, NONE, callback );
  }
  void Scene00028( Entity::Player& player ) //SEQ_3: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00028: Normal(Talk, TargetCanMove), id=MOBA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00030( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }
  void Scene00030( Entity::Player& player ) //SEQ_3: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00030: Normal(Talk, TargetCanMove), id=MOBA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_3: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00031: NpcTrade(Talk, TargetCanMove), id=MOBB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00032( player );
      }
    };
    player.playScene( getId(), 31, NONE, callback );
  }
  void Scene00032( Entity::Player& player ) //SEQ_3: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00032: Normal(Talk, TargetCanMove), id=MOBB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00034( player );
    };
    player.playScene( getId(), 32, NONE, callback );
  }
  void Scene00034( Entity::Player& player ) //SEQ_3: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00034: Normal(Talk, TargetCanMove), id=MOBB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player ) //SEQ_3: ACTOR3, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00035: NpcTrade(Talk, TargetCanMove), id=MOBC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00036( player );
      }
    };
    player.playScene( getId(), 35, NONE, callback );
  }
  void Scene00036( Entity::Player& player ) //SEQ_3: ACTOR3, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00036: Normal(Talk, TargetCanMove), id=MOBC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00038( player );
    };
    player.playScene( getId(), 36, NONE, callback );
  }
  void Scene00038( Entity::Player& player ) //SEQ_3: ACTOR3, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00038: Normal(Talk, TargetCanMove), id=MOBC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player ) //SEQ_3: ACTOR4, UI8CH = 1, Flag8(4)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00039: NpcTrade(Talk, TargetCanMove), id=MOBD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00040( player );
      }
    };
    player.playScene( getId(), 39, NONE, callback );
  }
  void Scene00040( Entity::Player& player ) //SEQ_3: ACTOR4, UI8CH = 1, Flag8(4)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00040: Normal(Talk, TargetCanMove), id=MOBD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00042( player );
    };
    player.playScene( getId(), 40, NONE, callback );
  }
  void Scene00042( Entity::Player& player ) //SEQ_3: ACTOR4, UI8CH = 1, Flag8(4)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00042: Normal(Talk, TargetCanMove), id=MOBD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 4, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player ) //SEQ_3: ACTOR5, UI8CL = 1, Flag8(5)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00043: NpcTrade(Talk, TargetCanMove), id=MOBE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00044( player );
      }
    };
    player.playScene( getId(), 43, NONE, callback );
  }
  void Scene00044( Entity::Player& player ) //SEQ_3: ACTOR5, UI8CL = 1, Flag8(5)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00044: Normal(Talk, TargetCanMove), id=MOBE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00046( player );
    };
    player.playScene( getId(), 44, NONE, callback );
  }
  void Scene00046( Entity::Player& player ) //SEQ_3: ACTOR5, UI8CL = 1, Flag8(5)=True
  {
    player.sendDebug( "SubWil122:66168 calling Scene00046: Normal(Talk, TargetCanMove), id=MOBE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 5, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil122:66168 calling Scene00047: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BENEGER" );
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
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil122:66168 calling Scene00048: Normal(Talk, TargetCanMove), id=MOBA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil122:66168 calling Scene00049: Normal(Talk, TargetCanMove), id=MOBB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil122:66168 calling Scene00050: Normal(Talk, TargetCanMove), id=MOBC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil122:66168 calling Scene00051: Normal(Talk, TargetCanMove), id=MOBD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil122:66168 calling Scene00052: Normal(Talk, TargetCanMove), id=MOBE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil122 );
