// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea158 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea158() : Sapphire::ScriptAPI::EventScript( 66827 ){}; 
  ~SubSea158() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_2, 3 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1005394
  //ACTOR1 = 1005396
  //ACTOR2 = 1005397
  //ENEMY0 = 4507190
  //ENEMY1 = 4507192
  //EOBJECT0 = 2002863
  //EVENTRANGE0 = 4497402
  //EVENTACTIONRESCURE = 26
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001086
  //LOCACTOR0 = 1005400
  //LOCSE1 = 55
  //VFXREACTION = 177

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SKRIBYLD
        break;
      }
      case 1:
      {
        if( param1 == 4497402 || param2 == 4497402 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 2 )
          {
            Scene00002( player ); // Scene00002: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4507190 || param2 == 4507190 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4507192 || param2 == 4507192 ) // ENEMY1 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 1005396 || param2 == 1005396 ) // ACTOR1 = COEURLCHILD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=COEURLCHILD
          break;
        }
        if( param1 == 1005397 || param2 == 1005397 ) // ACTOR2 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1005394 || param2 == 1005394 ) // ACTOR0 = SKRIBYLD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=SKRIBYLD
          break;
        }
        if( param1 == 2002863 || param2 == 2002863 ) // EOBJECT0 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BL max stack 1
      case 2:
      {
        if( param1 == 1005396 || param2 == 1005396 ) // ACTOR1 = COEURLCHILD
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=COEURLCHILD
            // +Callback Scene00009: Normal(Talk, NpcDespawn, TargetCanMove, SystemTalk), id=COEURLCHILD
          }
          break;
        }
        if( param1 == 1005397 || param2 == 1005397 ) // ACTOR2 = SKRIBYLD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=SKRIBYLD
          break;
        }
        if( param1 == 1005394 || param2 == 1005394 ) // ACTOR0 = SKRIBYLD
        {
          Scene00012( player ); // Scene00012: NpcTrade(Talk, TargetCanMove), id=SKRIBYLD
          // +Callback Scene00013: Normal(Talk, FadeIn, TargetCanMove), id=SKRIBYLD
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BL max stack 1
      case 255:
      {
        if( param1 == 1005394 || param2 == 1005394 ) // ACTOR0 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1005397 || param2 == 1005397 ) // ACTOR2 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
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
    if( player.getQuestUI8BL( getId() ) == 2 )
    {
      player.setQuestUI8BL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 2 );
      player.setQuestUI8BL( getId(), 1 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 1 )
    {
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea158:66827 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "SubSea158:66827 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SKRIBYLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: EVENTRANGE0, UI8BL = 2, Flag8(1)=True
  {
    player.sendDebug( "SubSea158:66827 calling Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 2 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }



  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea158:66827 calling Scene00003: Normal(Talk, TargetCanMove), id=COEURLCHILD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea158:66827 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea158:66827 calling Scene00005: Normal(Talk, TargetCanMove), id=SKRIBYLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea158:66827 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR1, UI8BH = 1, Flag8(1)=True
  {
    player.sendDebug( "SubSea158:66827 calling Scene00008: Normal(Talk, TargetCanMove), id=COEURLCHILD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR1, UI8BH = 1, Flag8(1)=True
  {
    player.sendDebug( "SubSea158:66827 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove, SystemTalk), id=COEURLCHILD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea158:66827 calling Scene00011: Normal(Talk, TargetCanMove), id=SKRIBYLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea158:66827 calling Scene00012: NpcTrade(Talk, TargetCanMove), id=SKRIBYLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea158:66827 calling Scene00013: Normal(Talk, FadeIn, TargetCanMove), id=SKRIBYLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea158:66827 calling Scene00014: Normal(QuestReward, QuestComplete), id=unknown" );
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

  void Scene00015( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea158:66827 calling Scene00015: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubSea158 );
