// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc014 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc014() : Sapphire::ScriptAPI::EventScript( 66487 ){}; 
  ~GaiUsc014() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006488
  //ACTOR1 = 1006701
  //ACTOR2 = 1006489
  //EOBJECT0 = 2002186
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000739

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=BRIANNAIX
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( type != 2 ) Scene00001( player ); // Scene00001: Normal(None), id=unknown
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( param1 == 1006701 || param2 == 1006701 ) // ACTOR1 = NPCA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=NPCA
          }
          break;
        }
        if( param1 == 1006489 || param2 == 1006489 ) // ACTOR2 = NPCB
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=NPCB
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 1006489 || param2 == 1006489 ) // ACTOR2 = NPCB
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=NPCB
          }
          break;
        }
        if( param1 == 1006701 || param2 == 1006701 ) // ACTOR1 = NPCA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=NPCA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006488 || param2 == 1006488 ) // ACTOR0 = BRIANNAIX
        {
          Scene00009( player ); // Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BRIANNAIX
          break;
        }
        if( param1 == 1006489 || param2 == 1006489 ) // ACTOR2 = NPCB
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=NPCB
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 3 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc014:66487 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=BRIANNAIX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc014:66487 calling Scene00001: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc014:66487 calling Scene00004: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc014:66487 calling Scene00005: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_3: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc014:66487 calling Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00007( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player ) //SEQ_3: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc014:66487 calling Scene00007: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc014:66487 calling Scene00008: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc014:66487 calling Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BRIANNAIX" );
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

  void Scene00010( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc014:66487 calling Scene00010: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsc014 );
