// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class XxaUse204 : public Sapphire::ScriptAPI::EventScript
{
public:
  XxaUse204() : Sapphire::ScriptAPI::EventScript( 69416 ){}; 
  ~XxaUse204() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1008616
  //ACTOR1 = 1008612
  //ACTOR10 = 1008619
  //ACTOR11 = 1008618
  //ACTOR12 = 1008623
  //ACTOR2 = 1008613
  //ACTOR3 = 1008614
  //ACTOR4 = 1008615
  //ACTOR5 = 1008617
  //ACTOR6 = 1008700
  //ACTOR7 = 1008620
  //ACTOR8 = 1008621
  //ACTOR9 = 1008622
  //LEVELIDNPC01 = 4621005
  //LEVELIDNPC02 = 4621006
  //LEVELIDNPC03 = 4621007
  //LEVELIDNPC04 = 4621008
  //LEVELIDNPC05 = 4621009
  //LOCACTOR0 = 4620901
  //LOCACTOR1 = 4620902
  //LOCACTOR10 = 3146810
  //LOCACTOR11 = 1008185
  //LOCACTOR12 = 1007097
  //LOCACTOR13 = 1007098
  //LOCACTOR14 = 1007099
  //LOCACTOR15 = 1008927
  //LOCACTOR2 = 4620903
  //LOCACTOR3 = 4620904
  //LOCACTOR4 = 4620905
  //LOCPOSACTOR1 = 4678739
  //LOCPOSACTOR2 = 4678741
  //QSTACCEPTCHECK = 66884

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1008616 || param2 == 1008616 ) // ACTOR0 = RAUBAHN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=RAUBAHN
          break;
        }
        if( param1 == 1008612 || param2 == 1008612 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1008613 || param2 == 1008613 ) // ACTOR2 = YUGIRI
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1008614 || param2 == 1008614 ) // ACTOR3 = KASASAGI
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=KASASAGI
          break;
        }
        if( param1 == 1008615 || param2 == 1008615 ) // ACTOR4 = KIKYOU
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=KIKYOU
          break;
        }
        if( param1 == 1008617 || param2 == 1008617 ) // ACTOR5 = TELEDJIADELEDJI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=TELEDJIADELEDJI
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1008700 || param2 == 1008700 ) // ACTOR6 = RAUBAHN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1008620 || param2 == 1008620 ) // ACTOR7 = YUGIRI
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1008621 || param2 == 1008621 ) // ACTOR8 = KASASAGI
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=KASASAGI
          break;
        }
        if( param1 == 1008622 || param2 == 1008622 ) // ACTOR9 = KIKYOU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=KIKYOU
          break;
        }
        if( param1 == 1008619 || param2 == 1008619 ) // ACTOR10 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1008618 || param2 == 1008618 ) // ACTOR11 = TELEDJIADELEDJI
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=TELEDJIADELEDJI
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00013( player ); // Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=ALPHINAUD
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "XxaUse204:69416 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown" );
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
    player.sendDebug( "XxaUse204:69416 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse204:69416 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse204:69416 calling Scene00003: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse204:69416 calling Scene00004: Normal(Talk, TargetCanMove), id=KASASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse204:69416 calling Scene00005: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse204:69416 calling Scene00006: Normal(Talk, TargetCanMove), id=TELEDJIADELEDJI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "XxaUse204:69416 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse204:69416 calling Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse204:69416 calling Scene00009: Normal(Talk, TargetCanMove), id=KASASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse204:69416 calling Scene00010: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse204:69416 calling Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse204:69416 calling Scene00012: Normal(Talk, TargetCanMove), id=TELEDJIADELEDJI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "XxaUse204:69416 calling Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=ALPHINAUD" );
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
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( XxaUse204 );
