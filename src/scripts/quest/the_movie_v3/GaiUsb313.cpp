// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb313 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb313() : Sapphire::ScriptAPI::EventScript( 66390 ){}; 
  ~GaiUsb313() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_4, 8 entries
  //SEQ_255, 9 entries

  //ACTOR0 = 1006266
  //ACTOR1 = 1006272
  //EOBJECT0 = 2002676
  //EOBJECT1 = 2002675
  //EOBJECT2 = 2002072
  //EOBJECT3 = 2002073
  //EOBJECT4 = 2002074
  //EOBJECT5 = 2002067
  //EOBJECT6 = 2002068
  //EOBJECT7 = 2002069
  //EOBJECT8 = 2002070
  //EOBJECT9 = 2002071
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000662
  //ITEM1 = 2000663
  //ITEM2 = 2000664

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=WHEISKAET
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      //seq 1 event item ITEM1 = UI8BL max stack 3
      //seq 1 event item ITEM2 = UI8CH max stack 2
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=DYRSTWEITZ
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      //seq 2 event item ITEM1 = UI8BL max stack 3
      //seq 2 event item ITEM2 = UI8CH max stack 2
      case 2:
      {
        if( type != 2 ) Scene00004( player ); // Scene00004: Normal(None), id=unknown
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      //seq 3 event item ITEM2 = UI8BL max stack 2
      case 3:
      {
        if( param1 == 2002675 || param2 == 2002675 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002072 || param2 == 2002072 ) // EOBJECT2 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002073 || param2 == 2002073 ) // EOBJECT3 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002074 || param2 == 2002074 ) // EOBJECT4 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      case 4:
      {
        if( param1 == 2002067 || param2 == 2002067 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00013( player ); // Scene00013: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2002068 || param2 == 2002068 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00015( player ); // Scene00015: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2002069 || param2 == 2002069 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00017( player ); // Scene00017: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2002072 || param2 == 2002072 ) // EOBJECT2 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002073 || param2 == 2002073 ) // EOBJECT3 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002074 || param2 == 2002074 ) // EOBJECT4 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002070 || param2 == 2002070 ) // EOBJECT8 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002071 || param2 == 2002071 ) // EOBJECT9 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006266 || param2 == 1006266 ) // ACTOR0 = WHEISKAET
        {
          Scene00029( player ); // Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WHEISKAET
          break;
        }
        if( param1 == 2002067 || param2 == 2002067 ) // EOBJECT5 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002068 || param2 == 2002068 ) // EOBJECT6 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002069 || param2 == 2002069 ) // EOBJECT7 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002070 || param2 == 2002070 ) // EOBJECT8 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002071 || param2 == 2002071 ) // EOBJECT9 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002072 || param2 == 2002072 ) // EOBJECT2 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002073 || param2 == 2002073 ) // EOBJECT3 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002074 || param2 == 2002074 ) // EOBJECT4 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.setQuestUI8BL( getId(), 0 );
    player.setQuestUI8CH( getId(), 0 );
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb313:66390 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=WHEISKAET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00002: Normal(Talk, TargetCanMove), id=DYRSTWEITZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00006( Entity::Player& player ) //SEQ_3: EOBJECT1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00006: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq3( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_3: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00012( Entity::Player& player ) //SEQ_3: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_4: EOBJECT5, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00013: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_4: EOBJECT6, UI8AL = 3, Flag8(2)=True
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00015: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_4: EOBJECT7, UI8AL = 3, Flag8(3)=True
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00017: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00022( Entity::Player& player ) //SEQ_4: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00024( Entity::Player& player ) //SEQ_4: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00024: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00026( Entity::Player& player ) //SEQ_4: EOBJECT8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00026: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00028( Entity::Player& player ) //SEQ_4: EOBJECT9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00028: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00029( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WHEISKAET" );
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
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_255: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player ) //SEQ_255: EOBJECT6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player ) //SEQ_255: EOBJECT7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player ) //SEQ_255: EOBJECT8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00037: Normal(None), id=unknown" );
  }

  void Scene00039( Entity::Player& player ) //SEQ_255: EOBJECT9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player ) //SEQ_255: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player ) //SEQ_255: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00045( Entity::Player& player ) //SEQ_255: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00045: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb313 );
