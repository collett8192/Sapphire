// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna112 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna112() : Sapphire::ScriptAPI::EventScript( 67127 ){}; 
  ~HeaVna112() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 2 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINETALKJOKE = 4220
  //ACTOR0 = 1011952
  //ACTOR1 = 1012354
  //ACTOR2 = 1012355
  //QSTACTOR0 = 5857463

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1011952 || param2 == 1011952 ) // ACTOR0 = LANIAITTE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LANIAITTE
          }
          break;
        }
        if( param1 == 1012354 || param2 == 1012354 ) // ACTOR1 = EMMANELLAIN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1012355 || param2 == 1012355 ) // ACTOR2 = HONOROIT
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove, ENpcBind), id=HONOROIT
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012354 || param2 == 1012354 ) // ACTOR1 = EMMANELLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove, Menu, CanCancel), id=EMMANELLAIN
          }
          break;
        }
        if( param1 == 1012355 || param2 == 1012355 ) // ACTOR2 = HONOROIT
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1011952 || param2 == 1011952 ) // ACTOR0 = LANIAITTE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=LANIAITTE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1012355 || param2 == 1012355 ) // ACTOR2 = HONOROIT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=HONOROIT
          }
          break;
        }
        if( param1 == 1011952 || param2 == 1011952 ) // ACTOR0 = LANIAITTE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LANIAITTE
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00009( player ); // Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LANIAITTE
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna112:67127 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna112:67127 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LANIAITTE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna112:67127 calling Scene00002: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna112:67127 calling Scene00003: Normal(Talk, TargetCanMove, ENpcBind), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna112:67127 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove, Menu, CanCancel), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        player.setQuestBitFlag8( getId(), 1, true );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna112:67127 calling Scene00005: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna112:67127 calling Scene00006: Normal(Talk, TargetCanMove), id=LANIAITTE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna112:67127 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna112:67127 calling Scene00008: Normal(Talk, TargetCanMove), id=LANIAITTE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna112:67127 calling Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LANIAITTE" );
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
    player.playScene( getId(), 9, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna112 );
