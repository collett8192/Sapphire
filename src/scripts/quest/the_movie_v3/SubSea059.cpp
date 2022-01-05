// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea059 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea059() : Sapphire::ScriptAPI::EventScript( 66007 ){}; 
  ~SubSea059() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002633
  //EOBJECT0 = 2001272
  //EOBJECT1 = 2001243
  //EOBJECT2 = 2001244
  //EOBJECT3 = 2001245
  //EOBJECT4 = 2001246
  //EOBJECT5 = 2001247
  //EOBJECT6 = 2001248
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONSEARCHSHORT = 2
  //ITEM0 = 2000350

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=GRYNEWYDA
        // +Callback Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GRYNEWYDA
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( type != 2 ) Scene00001( player ); // Scene00001: Normal(None), id=unknown
        break;
      }
      //seq 2 event item ITEM0 = UI8BL max stack ?
      case 2:
      {
        if( param1 == 2001243 || param2 == 2001243 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            Scene00099( player ); // Scene00099: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001244 || param2 == 2001244 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            Scene00091( player ); // Scene00091: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001245 || param2 == 2001245 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            Scene00089( player ); // Scene00089: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001246 || param2 == 2001246 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00087( player ); // Scene00087: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001247 || param2 == 2001247 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00002( player ); // Scene00002: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 2001248 || param2 == 2001248 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00003( player ); // Scene00003: Normal(Inventory), id=unknown
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( type != 2 ) Scene00004( player ); // Scene00004: Normal(Inventory), id=unknown
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
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestBitFlag8( getId(), 1, false );
        player.setQuestBitFlag8( getId(), 2, false );
        player.setQuestBitFlag8( getId(), 3, false );
        player.setQuestBitFlag8( getId(), 4, false );
        player.setQuestBitFlag8( getId(), 5, false );
        player.setQuestBitFlag8( getId(), 6, false );
        player.setQuestUI8BL( getId(), 0 );
        player.updateQuest( getId(), 255 );
      }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea059:66007 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=GRYNEWYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00008( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00008( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea059:66007 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GRYNEWYDA" );
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
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00001( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea059:66007 calling Scene00001: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00099( Entity::Player& player ) //SEQ_2: EOBJECT1, UI8BH = 3, Flag8(1)=True
  {
    player.sendDebug( "SubSea059:66007 calling Scene00099: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq2( player );
  }

  void Scene00091( Entity::Player& player ) //SEQ_2: EOBJECT2, UI8BH = 3, Flag8(2)=True
  {
    player.sendDebug( "SubSea059:66007 calling Scene00091: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq2( player );
  }

  void Scene00089( Entity::Player& player ) //SEQ_2: EOBJECT3, UI8BH = 3, Flag8(3)=True
  {
    player.sendDebug( "SubSea059:66007 calling Scene00089: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq2( player );
  }

  void Scene00087( Entity::Player& player ) //SEQ_2: EOBJECT4, UI8AL = 3, Flag8(4)=True
  {
    player.sendDebug( "SubSea059:66007 calling Scene00087: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 4, true );
    checkProgressSeq2( player );
  }

  void Scene00002( Entity::Player& player ) //SEQ_2: EOBJECT5, UI8AL = 3, Flag8(5)=True
  {
    player.sendDebug( "SubSea059:66007 calling Scene00002: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 5, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_2: EOBJECT6, UI8AL = 3, Flag8(6)=True
  {
    player.sendDebug( "SubSea059:66007 calling Scene00003: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 6, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea059:66007 calling Scene00004: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea059 );
