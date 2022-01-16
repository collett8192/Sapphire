// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna304 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna304() : Sapphire::ScriptAPI::EventScript( 67141 ){}; 
  ~HeaVna304() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 7 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1012592
  //ACTOR1 = 1012594
  //ACTOR2 = 1012595
  //ACTOR3 = 1012596
  //ACTOR4 = 1012600
  //ACTOR5 = 1012601
  //ACTOR6 = 1012602
  //EOBJECT0 = 2005432
  //EOBJECT1 = 2005433
  //EOBJECT2 = 2005434
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001578
  //LOCACTOR0 = 5853380

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012592 || param2 == 1012592 ) // ACTOR0 = KIGHTLEADER01605
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=KIGHTLEADER01605
          }
          break;
        }
        if( param1 == 1012594 || param2 == 1012594 ) // ACTOR1 = ESTINIEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012595 || param2 == 1012595 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012596 || param2 == 1012596 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 3
      case 1:
      {
        if( param1 == 2005432 || param2 == 2005432 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2005433 || param2 == 2005433 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2005434 || param2 == 2005434 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1012600 || param2 == 1012600 ) // ACTOR4 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012601 || param2 == 1012601 ) // ACTOR5 = KIGHTLEADER01605
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=KIGHTLEADER01605
          break;
        }
        if( param1 == 1012602 || param2 == 1012602 ) // ACTOR6 = ESTINIEN
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012596 || param2 == 1012596 ) // ACTOR3 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        if( param1 == 1012601 || param2 == 1012601 ) // ACTOR5 = KIGHTLEADER01605
        {
          Scene00015( player ); // Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KIGHTLEADER01605
          break;
        }
        if( param1 == 1012600 || param2 == 1012600 ) // ACTOR4 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012602 || param2 == 1012602 ) // ACTOR6 = ESTINIEN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012596 || param2 == 1012596 ) // ACTOR3 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
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
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 3 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=KIGHTLEADER01605" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00006: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8AL = 3, Flag8(2)=True
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00008: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: EOBJECT2, UI8AL = 3, Flag8(3)=True
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00010: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00012: Normal(Talk, TargetCanMove), id=KIGHTLEADER01605" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00013: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00016( player );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KIGHTLEADER01605" );
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
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00018: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna304:67141 calling Scene00019: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( HeaVna304 );
