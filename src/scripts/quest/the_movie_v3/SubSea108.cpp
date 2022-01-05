// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea108 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea108() : Sapphire::ScriptAPI::EventScript( 65941 ){}; 
  ~SubSea108() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 12 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1003244
  //ENEMY0 = 3929524
  //ENEMY1 = 3929555
  //ENEMY2 = 3929528
  //ENEMY3 = 3929560
  //ENEMY4 = 3929529
  //ENEMY5 = 3929563
  //ENEMY6 = 3929531
  //ENEMY7 = 3929569
  //EOBJECT0 = 2001265
  //EOBJECT1 = 2001266
  //EOBJECT2 = 2001267
  //EOBJECT3 = 2001268
  //EVENTACTION = 32
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000346

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=LYULF
        break;
      }
      //seq 1 event item ITEM0 = UI8CL max stack 3
      case 1:
      {
        if( param1 == 2001265 || param2 == 2001265 ) // EOBJECT0 = unknown
        {
          Scene00001( player ); // Scene00001: Normal(None), id=unknown
          break;
        }
        if( param1 == 3929524 || param2 == 3929524 ) // ENEMY0 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 3929555 || param2 == 3929555 ) // ENEMY1 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001266 || param2 == 2001266 ) // EOBJECT1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 3929528 || param2 == 3929528 ) // ENEMY2 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 3929560 || param2 == 3929560 ) // ENEMY3 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001267 || param2 == 2001267 ) // EOBJECT2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 3929529 || param2 == 3929529 ) // ENEMY4 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 3929563 || param2 == 3929563 ) // ENEMY5 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001268 || param2 == 2001268 ) // EOBJECT3 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 3929531 || param2 == 3929531 ) // ENEMY6 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 3929569 || param2 == 3929569 ) // ENEMY7 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        if( type != 2 ) Scene00013( player ); // Scene00013: NpcTrade(Talk), id=unknown
        // +Callback Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYULF
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
    player.setQuestBitFlag8( getId(), 1, false );
    player.setQuestBitFlag8( getId(), 2, false );
    player.setQuestBitFlag8( getId(), 3, false );
    player.setQuestBitFlag8( getId(), 4, false );
    player.setQuestUI8CL( getId(), 0 );
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 3 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea108:65941 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=LYULF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, Flag8(1)=True
  {
    player.sendDebug( "SubSea108:65941 calling Scene00001: Normal(None), id=unknown" );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq1( player );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea108:65941 calling Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea108:65941 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: EOBJECT1, <No Var>, Flag8(2)=True
  {
    player.sendDebug( "SubSea108:65941 calling Scene00004: Normal(None), id=unknown" );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea108:65941 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ENEMY3, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea108:65941 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: EOBJECT2, <No Var>, Flag8(3)=True
  {
    player.sendDebug( "SubSea108:65941 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ENEMY4, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea108:65941 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ENEMY5, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea108:65941 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: EOBJECT3, <No Var>, Flag8(4)=True
  {
    player.sendDebug( "SubSea108:65941 calling Scene00010: Normal(None), id=unknown" );
    player.setQuestBitFlag8( getId(), 4, true );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ENEMY6, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea108:65941 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: ENEMY7, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea108:65941 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea108:65941 calling Scene00013: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00014( player );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea108:65941 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYULF" );
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
    player.playScene( getId(), 14, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea108 );
