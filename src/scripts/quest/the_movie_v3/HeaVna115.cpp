// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna115 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna115() : Sapphire::ScriptAPI::EventScript( 67130 ){}; 
  ~HeaVna115() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 3 entries
  //SEQ_3, 3 entries
  //SEQ_4, 9 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINETALKJOKE = 4220
  //ACTOR0 = 1012060
  //ACTOR1 = 1011952
  //ACTOR2 = 1012354
  //ACTOR3 = 1012355
  //ACTOR4 = 1012363
  //ACTOR5 = 1012364
  //ACTOR6 = 1012365
  //EOBJECT0 = 2005412
  //EOBJECT1 = 2005413
  //EOBJECT2 = 2005414
  //EOBJECT3 = 2005415
  //EOBJECT4 = 2005416
  //EOBJECT5 = 2005417
  //EOBJECT6 = 2005492
  //EVENTACTIONSEEKUPPERLONG = 55
  //EVENTACTIONSEEKUPPERMIDDLE = 54
  //ITEM0 = 2001574
  //QSTACTOR1 = 5857464

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MARIELLE
        break;
      }
      case 1:
      {
        if( param1 == 1011952 || param2 == 1011952 ) // ACTOR1 = LANIAITTE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LANIAITTE
          }
          break;
        }
        if( param1 == 1012354 || param2 == 1012354 ) // ACTOR2 = EMMANELLAIN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1012355 || param2 == 1012355 ) // ACTOR3 = HONOROIT
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1012060 || param2 == 1012060 ) // ACTOR0 = MARIELLE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MARIELLE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1012354 || param2 == 1012354 ) // ACTOR2 = EMMANELLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove, Menu, CanCancel, ENpcBind), id=EMMANELLAIN
          }
          break;
        }
        if( param1 == 1012355 || param2 == 1012355 ) // ACTOR3 = HONOROIT
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1011952 || param2 == 1011952 ) // ACTOR1 = LANIAITTE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LANIAITTE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1012363 || param2 == 1012363 ) // ACTOR4 = EMMANELLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=EMMANELLAIN
          }
          break;
        }
        if( param1 == 1011952 || param2 == 1011952 ) // ACTOR1 = LANIAITTE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=LANIAITTE
          break;
        }
        if( param1 == 1012364 || param2 == 1012364 ) // ACTOR5 = HONOROIT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 2005412 || param2 == 2005412 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1012365 || param2 == 1012365 ) // ACTOR6 = EMMANELLAIN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1012364 || param2 == 1012364 ) // ACTOR5 = HONOROIT
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 2005413 || param2 == 2005413 ) // EOBJECT1 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2005414 || param2 == 2005414 ) // EOBJECT2 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2005415 || param2 == 2005415 ) // EOBJECT3 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2005416 || param2 == 2005416 ) // EOBJECT4 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2005417 || param2 == 2005417 ) // EOBJECT5 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2005492 || param2 == 2005492 ) // EOBJECT6 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( type != 2 ) Scene00028( player ); // Scene00028: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HONOROIT
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna115:67130 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MARIELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00002: Normal(Talk, TargetCanMove), id=LANIAITTE" );
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
    player.sendDebug( "HeaVna115:67130 calling Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00004: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00005: Normal(Talk, TargetCanMove), id=MARIELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove, Menu, CanCancel, ENpcBind), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        player.setQuestBitFlag8( getId(), 1, true );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00007: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00008: Normal(Talk, TargetCanMove), id=LANIAITTE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_3: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00010: Normal(Talk, TargetCanMove), id=LANIAITTE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00011: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_4: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00013: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00014: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00015: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00017: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00019: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_4: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00021: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_4: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00023: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_4: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00025: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_4: EOBJECT6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00027: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00028: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00029( player );
      }
    };
    player.playScene( getId(), 28, NONE, callback );
  }
  void Scene00029( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HONOROIT" );
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
};

EXPOSE_SCRIPT( HeaVna115 );
