// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb610 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb610() : Sapphire::ScriptAPI::EventScript( 66428 ){}; 
  ~GaiUsb610() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006388
  //ACTOR1 = 1006386
  //EOBJECT0 = 2002113
  //EOBJECT1 = 2002114
  //EOBJECT2 = 2002115
  //EOBJECT3 = 2002116
  //EOBJECT4 = 2002117
  //EOBJECT5 = 2002118
  //EOBJECT6 = 2002119
  //EOBJECT7 = 2002120
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000698

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PRAIRILLOT
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 8
      case 1:
      {
        if( param1 == 2002113 || param2 == 2002113 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002114 || param2 == 2002114 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002115 || param2 == 2002115 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002116 || param2 == 2002116 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002117 || param2 == 2002117 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00011( player ); // Scene00011: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002118 || param2 == 2002118 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00013( player ); // Scene00013: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002119 || param2 == 2002119 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00015( player ); // Scene00015: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002120 || param2 == 2002120 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00017( player ); // Scene00017: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 8
      case 255:
      {
        if( type != 2 ) Scene00018( player ); // Scene00018: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=STEPHANNOT
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
    if( player.getQuestUI8AL( getId() ) == 8 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.setQuestBitFlag8( getId(), 4, false );
      player.setQuestBitFlag8( getId(), 5, false );
      player.setQuestBitFlag8( getId(), 6, false );
      player.setQuestBitFlag8( getId(), 7, false );
      player.setQuestBitFlag8( getId(), 8, false );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 8 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb610:66428 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb610:66428 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PRAIRILLOT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 8, Flag8(1)=True
  {
    player.sendDebug( "GaiUsb610:66428 calling Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8AL = 8, Flag8(2)=True
  {
    player.sendDebug( "GaiUsb610:66428 calling Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: EOBJECT2, UI8AL = 8, Flag8(3)=True
  {
    player.sendDebug( "GaiUsb610:66428 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: EOBJECT3, UI8AL = 8, Flag8(4)=True
  {
    player.sendDebug( "GaiUsb610:66428 calling Scene00009: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 4, true );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: EOBJECT4, UI8AL = 8, Flag8(5)=True
  {
    player.sendDebug( "GaiUsb610:66428 calling Scene00011: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 5, true );
    checkProgressSeq1( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_1: EOBJECT5, UI8AL = 8, Flag8(6)=True
  {
    player.sendDebug( "GaiUsb610:66428 calling Scene00013: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 6, true );
    checkProgressSeq1( player );
  }

  void Scene00015( Entity::Player& player ) //SEQ_1: EOBJECT6, UI8AL = 8, Flag8(7)=True
  {
    player.sendDebug( "GaiUsb610:66428 calling Scene00015: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 7, true );
    checkProgressSeq1( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_1: EOBJECT7, UI8AL = 8, Flag8(8)=True
  {
    player.sendDebug( "GaiUsb610:66428 calling Scene00017: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 8, true );
    checkProgressSeq1( player );
  }

  void Scene00018( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb610:66428 calling Scene00018: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00019( player );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb610:66428 calling Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=STEPHANNOT" );
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
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb610 );
