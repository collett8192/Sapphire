// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb406 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb406() : Sapphire::ScriptAPI::EventScript( 66398 ){}; 
  ~GaiUsb406() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 12 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1006331
  //ACTOR1 = 1007542
  //ACTOR2 = 1007543
  //ACTOR3 = 1007544
  //ACTOR4 = 1007545
  //ACTOR5 = 1007546
  //ACTOR6 = 1007547
  //EOBJECT0 = 2002341
  //EOBJECT1 = 2002342
  //EOBJECT2 = 2002343
  //EOBJECT3 = 2002338
  //EOBJECT4 = 2002339
  //EOBJECT5 = 2002340
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000669
  //ITEM1 = 2000929

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SWYGRAEL
        break;
      }
      //seq 1 event item ITEM0 = UI8BL max stack 3
      //seq 1 event item ITEM1 = UI8CH max stack 3
      case 1:
      {
        if( param1 == 2002341 || param2 == 2002341 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002342 || param2 == 2002342 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002343 || param2 == 2002343 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1007542 || param2 == 1007542 ) // ACTOR1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007543 || param2 == 1007543 ) // ACTOR2 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007544 || param2 == 1007544 ) // ACTOR3 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007545 || param2 == 1007545 ) // ACTOR4 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007546 || param2 == 1007546 ) // ACTOR5 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007547 || param2 == 1007547 ) // ACTOR6 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002338 || param2 == 2002338 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            Scene00015( player ); // Scene00015: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002339 || param2 == 2002339 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            Scene00017( player ); // Scene00017: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002340 || param2 == 2002340 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            Scene00019( player ); // Scene00019: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      //seq 255 event item ITEM1 = UI8BL max stack 3
      case 255:
      {
        if( param1 == 1006331 || param2 == 1006331 ) // ACTOR0 = SWYGRAEL
        {
          Scene00020( player ); // Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SWYGRAEL
          break;
        }
        if( param1 == 1007542 || param2 == 1007542 ) // ACTOR1 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007543 || param2 == 1007543 ) // ACTOR2 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007544 || param2 == 1007544 ) // ACTOR3 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007545 || param2 == 1007545 ) // ACTOR4 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007546 || param2 == 1007546 ) // ACTOR5 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007547 || param2 == 1007547 ) // ACTOR6 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8BH( getId() ) == 3 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestBitFlag16( getId(), 1, false );
        player.setQuestBitFlag16( getId(), 2, false );
        player.setQuestBitFlag16( getId(), 3, false );
        player.setQuestBitFlag16( getId(), 10, false );
        player.setQuestBitFlag16( getId(), 11, false );
        player.setQuestBitFlag16( getId(), 12, false );
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.updateQuest( getId(), 255 );
        player.setQuestUI8BH( getId(), 3 );
        player.setQuestUI8BL( getId(), 3 );
      }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb406:66398 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SWYGRAEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 3, Flag16(1)=True
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag16( getId(), 1, true );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8AL = 3, Flag16(2)=True
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag16( getId(), 2, true );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: EOBJECT2, UI8AL = 3, Flag16(3)=True
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag16( getId(), 3, true );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player ) //SEQ_1: EOBJECT3, UI8BH = 3, Flag16(10)=True
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00015: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    player.setQuestBitFlag16( getId(), 10, true );
    checkProgressSeq1( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_1: EOBJECT4, UI8BH = 3, Flag16(11)=True
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00017: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    player.setQuestBitFlag16( getId(), 11, true );
    checkProgressSeq1( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_1: EOBJECT5, UI8BH = 3, Flag16(12)=True
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00019: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    player.setQuestBitFlag16( getId(), 12, true );
    checkProgressSeq1( player );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00021( player );
      }
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SWYGRAEL" );
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
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb406:66398 calling Scene00027: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb406 );
