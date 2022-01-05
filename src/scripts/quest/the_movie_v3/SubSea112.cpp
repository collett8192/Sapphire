// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea112 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea112() : Sapphire::ScriptAPI::EventScript( 65945 ){}; 
  ~SubSea112() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002233
  //ACTOR1 = 1002453
  //ACTOR2 = 1002455
  //EOBJECT0 = 2000762
  //EOBJECT1 = 2000763
  //EVENTACTIONGATHERSHORT = 6
  //ITEM0 = 2000218
  //SEQ0ACTOR0 = 0
  //SEQ1ACTOR1 = 1
  //SEQ1ACTOR2 = 2
  //SEQ1EOBJECT0 = 3
  //SEQ1EOBJECT0EVENTACTIONNO = 99
  //SEQ1EOBJECT0EVENTACTIONOK = 100
  //SEQ1EOBJECT1 = 4
  //SEQ1EOBJECT1EVENTACTIONNO = 97
  //SEQ1EOBJECT1EVENTACTIONOK = 98
  //SEQ2ACTOR0 = 5
  //SEQ2ACTOR0NPCTRADENO = 95
  //SEQ2ACTOR0NPCTRADEOK = 96

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WAFUFU
        break;
      }
      //seq 1 event item ITEM0 = UI8CL max stack 4
      case 1:
      {
        if( param1 == 1002453 || param2 == 1002453 ) // ACTOR1 = LYNGSTYRM
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=LYNGSTYRM
          }
          break;
        }
        if( param1 == 1002455 || param2 == 1002455 ) // ACTOR2 = MAETIMYND
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MAETIMYND
          }
          break;
        }
        if( param1 == 2000762 || param2 == 2000762 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00099( player ); // Scene00099: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2000763 || param2 == 2000763 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00097( player ); // Scene00097: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 4
      case 255:
      {
        if( type != 2 ) Scene00005( player ); // Scene00005: NpcTrade(Talk, TargetCanMove), id=WAFUFU
        // +Callback Scene00096: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WAFUFU
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
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestBitFlag8( getId(), 1, false );
            player.setQuestBitFlag8( getId(), 2, false );
            player.setQuestBitFlag8( getId(), 3, false );
            player.setQuestBitFlag8( getId(), 4, false );
            player.setQuestUI8CL( getId(), 0 );
            player.updateQuest( getId(), 255 );
            player.setQuestUI8BH( getId(), 4 );
          }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea112:65945 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WAFUFU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubSea112:65945 calling Scene00001: Normal(Talk, TargetCanMove), id=LYNGSTYRM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "SubSea112:65945 calling Scene00002: Normal(Talk, TargetCanMove), id=MAETIMYND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00099( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "SubSea112:65945 calling Scene00099: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq1( player );
  }

  void Scene00097( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8CH = 1, Flag8(4)=True
  {
    player.sendDebug( "SubSea112:65945 calling Scene00097: Normal(None), id=unknown" );
    player.setQuestUI8CH( getId(), 1 );
    player.setQuestBitFlag8( getId(), 4, true );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea112:65945 calling Scene00005: NpcTrade(Talk, TargetCanMove), id=WAFUFU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00096( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00096( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea112:65945 calling Scene00096: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WAFUFU" );
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
    player.playScene( getId(), 96, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea112 );
