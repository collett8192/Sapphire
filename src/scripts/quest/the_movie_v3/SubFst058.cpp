// FFXIVTheMovie.ParserV3.6
// id hint used:
//SCENE_6 REMOVED!!
//SCENE_92 REMOVED!!
//SCENE_91 REMOVED!!
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst058 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst058() : Sapphire::ScriptAPI::EventScript( 65915 ){}; 
  ~SubFst058() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1000436
  //ACTOR1 = 1000748
  //EOBJECT0 = 2000688
  //EOBJECT1 = 2000689
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000191
  //SEQ0ACTOR0 = 0
  //SEQ1ACTOR1 = 1
  //SEQ1EOBJECT0 = 2
  //SEQ1EOBJECT0EVENTACTIONNO = 99
  //SEQ1EOBJECT0EVENTACTIONOK = 100
  //SEQ2EOBJECT0 = 4
  //SEQ2EOBJECT0EVENTACTIONNO = 95
  //SEQ2EOBJECT0EVENTACTIONOK = 96
  //SEQ2EOBJECT1 = 3
  //SEQ2EOBJECT1EVENTACTIONNO = 97
  //SEQ2EOBJECT1EVENTACTIONOK = 98
  //SEQ3ACTOR1 = 5
  //SEQ3ACTOR1NPCTRADENO = 93
  //SEQ3ACTOR1NPCTRADEOK = 94
  //SEQ3EOBJECT0 = 6
  //SEQ3EOBJECT0EVENTACTIONNO = 91
  //SEQ3EOBJECT0EVENTACTIONOK = 92

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=THEODORE
        break;
      }
      case 1:
      {
        if( param1 == 1000748 || param2 == 1000748 ) // ACTOR1 = ROSELINE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=ROSELINE
          }
          break;
        }
        if( param1 == 2000688 || param2 == 2000688 ) // EOBJECT0 = unknown
        {
          Scene00099( player ); // Scene00099: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( param1 == 2000689 || param2 == 2000689 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00097( player ); // Scene00097: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2000688 || param2 == 2000688 ) // EOBJECT0 = unknown
        {
          Scene00095( player ); // Scene00095: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1000748 || param2 == 1000748 ) // ACTOR1 = ROSELINE
        {
          Scene00005( player ); // Scene00005: NpcTrade(Talk, TargetCanMove), id=ROSELINE
          // +Callback Scene00094: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ROSELINE
          break;
        }
        if( param1 == 2000688 || param2 == 2000688 ) // EOBJECT0 = unknown
        {
          Scene00093( player ); // Scene00093: Normal(None), id=unknown
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
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst058:65915 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=THEODORE" );
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
    player.sendDebug( "SubFst058:65915 calling Scene00001: Normal(Talk, TargetCanMove), id=ROSELINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00099( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst058:65915 calling Scene00099: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00097( Entity::Player& player ) //SEQ_2: EOBJECT1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubFst058:65915 calling Scene00097: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq2( player );
  }

  void Scene00095( Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst058:65915 calling Scene00095: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst058:65915 calling Scene00005: NpcTrade(Talk, TargetCanMove), id=ROSELINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00094( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00094( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst058:65915 calling Scene00094: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ROSELINE" );
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
    player.playScene( getId(), 94, NONE, callback );
  }

  void Scene00093( Entity::Player& player ) //SEQ_255: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst058:65915 calling Scene00093: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubFst058 );
