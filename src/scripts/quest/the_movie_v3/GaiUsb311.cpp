// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb311 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb311() : Sapphire::ScriptAPI::EventScript( 66388 ){}; 
  ~GaiUsb311() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_2, 12 entries
  //SEQ_3, 12 entries
  //SEQ_255, 13 entries

  //ACTOR0 = 1006273
  //ACTOR1 = 1006320
  //ACTOR10 = 1007554
  //ACTOR11 = 1007555
  //ACTOR12 = 1007556
  //ACTOR13 = 1007557
  //ACTOR14 = 1007558
  //ACTOR2 = 1006321
  //ACTOR3 = 1006322
  //ACTOR4 = 1007549
  //ACTOR5 = 1007550
  //ACTOR6 = 1007551
  //ACTOR7 = 1007552
  //ACTOR8 = 1007553
  //ACTOR9 = 1006323
  //EOBJECT0 = 2002064
  //EOBJECT1 = 2002065
  //EOBJECT2 = 2002066
  //EOBJECT3 = 2002677
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000661

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GEGERUJU
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 1006320 || param2 == 1006320 ) // ACTOR1 = POACHER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=POACHER
          }
          break;
        }
        if( param1 == 1006321 || param2 == 1006321 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006322 || param2 == 1006322 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007549 || param2 == 1007549 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007550 || param2 == 1007550 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007551 || param2 == 1007551 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007552 || param2 == 1007552 ) // ACTOR7 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007553 || param2 == 1007553 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8CL max stack ?
      case 2:
      {
        if( param1 == 2002064 || param2 == 2002064 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2002065 || param2 == 2002065 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2002066 || param2 == 2002066 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 1006320 || param2 == 1006320 ) // ACTOR1 = POACHER
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=POACHER
          break;
        }
        if( param1 == 1006321 || param2 == 1006321 ) // ACTOR2 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006322 || param2 == 1006322 ) // ACTOR3 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007549 || param2 == 1007549 ) // ACTOR4 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007550 || param2 == 1007550 ) // ACTOR5 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007551 || param2 == 1007551 ) // ACTOR6 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007552 || param2 == 1007552 ) // ACTOR7 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007553 || param2 == 1007553 ) // ACTOR8 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002677 || param2 == 2002677 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Inventory), id=unknown
          }
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1006320 || param2 == 1006320 ) // ACTOR1 = POACHER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=POACHER
          }
          break;
        }
        if( param1 == 1006322 || param2 == 1006322 ) // ACTOR3 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006323 || param2 == 1006323 ) // ACTOR9 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007554 || param2 == 1007554 ) // ACTOR10 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007555 || param2 == 1007555 ) // ACTOR11 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007556 || param2 == 1007556 ) // ACTOR12 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007557 || param2 == 1007557 ) // ACTOR13 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007558 || param2 == 1007558 ) // ACTOR14 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002064 || param2 == 2002064 ) // EOBJECT0 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002065 || param2 == 2002065 ) // EOBJECT1 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002066 || param2 == 2002066 ) // EOBJECT2 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002677 || param2 == 2002677 ) // EOBJECT3 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006273 || param2 == 1006273 ) // ACTOR0 = GEGERUJU
        {
          Scene00042( player ); // Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GEGERUJU
          break;
        }
        if( param1 == 1006320 || param2 == 1006320 ) // ACTOR1 = POACHER
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=POACHER
          break;
        }
        if( param1 == 1006322 || param2 == 1006322 ) // ACTOR3 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006323 || param2 == 1006323 ) // ACTOR9 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007554 || param2 == 1007554 ) // ACTOR10 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007555 || param2 == 1007555 ) // ACTOR11 = unknown
        {
          Scene00047( player ); // Scene00047: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007556 || param2 == 1007556 ) // ACTOR12 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007557 || param2 == 1007557 ) // ACTOR13 = unknown
        {
          Scene00049( player ); // Scene00049: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007558 || param2 == 1007558 ) // ACTOR14 = unknown
        {
          Scene00050( player ); // Scene00050: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002064 || param2 == 2002064 ) // EOBJECT0 = unknown
        {
          Scene00052( player ); // Scene00052: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002065 || param2 == 2002065 ) // EOBJECT1 = unknown
        {
          Scene00054( player ); // Scene00054: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002066 || param2 == 2002066 ) // EOBJECT2 = unknown
        {
          Scene00056( player ); // Scene00056: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002677 || param2 == 2002677 ) // EOBJECT3 = unknown
        {
          Scene00058( player ); // Scene00058: Normal(None), id=unknown
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
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestBitFlag16( getId(), 1, false );
            player.setQuestBitFlag16( getId(), 2, false );
            player.setQuestBitFlag16( getId(), 3, false );
            player.setQuestBitFlag16( getId(), 12, false );
            player.setQuestUI8CL( getId(), 0 );
            player.updateQuest( getId(), 3 );
          }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag16( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb311:66388 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GEGERUJU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00002: Normal(Talk, TargetCanMove), id=POACHER" );
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
    player.sendDebug( "GaiUsb311:66388 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag16(1)=True
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00010: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag16( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: EOBJECT1, UI8BH = 1, Flag16(2)=True
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00012: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag16( getId(), 2, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: EOBJECT2, UI8BL = 1, Flag16(3)=True
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00014: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      player.setQuestBitFlag16( getId(), 3, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00016: Normal(Talk, TargetCanMove), id=POACHER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player ) //SEQ_2: EOBJECT3, UI8CH = 1, Flag16(12)=True
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00024: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      player.setQuestBitFlag16( getId(), 12, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_3: ACTOR1, UI8AL = 1, Flag16(1)=True
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00026: Normal(Talk, TargetCanMove), id=POACHER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag16( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player ) //SEQ_3: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player ) //SEQ_3: ACTOR14, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00035: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00037( Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00037: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00039( Entity::Player& player ) //SEQ_3: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00039: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00041( Entity::Player& player ) //SEQ_3: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00041: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00042( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GEGERUJU" );
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
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00043: Normal(Talk, TargetCanMove), id=POACHER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00044: Normal(None), id=unknown" );
  }

  void Scene00045( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00045: Normal(None), id=unknown" );
  }

  void Scene00046( Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00046: Normal(None), id=unknown" );
  }

  void Scene00047( Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00047: Normal(None), id=unknown" );
  }

  void Scene00048( Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00048: Normal(None), id=unknown" );
  }

  void Scene00049( Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00049: Normal(None), id=unknown" );
  }

  void Scene00050( Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00050: Normal(None), id=unknown" );
  }

  void Scene00052( Entity::Player& player ) //SEQ_255: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00052: Normal(None), id=unknown" );
  }

  void Scene00054( Entity::Player& player ) //SEQ_255: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00054: Normal(None), id=unknown" );
  }

  void Scene00056( Entity::Player& player ) //SEQ_255: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00056: Normal(None), id=unknown" );
  }

  void Scene00058( Entity::Player& player ) //SEQ_255: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00058: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb311 );
