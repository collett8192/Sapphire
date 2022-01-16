// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna108 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna108() : Sapphire::ScriptAPI::EventScript( 67123 ){}; 
  ~HeaVna108() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_4, 7 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINEEVENTBASEKNEESUFFERING = 936
  //ACTOR0 = 1011231
  //ACTOR1 = 1012334
  //ACTOR2 = 1012404
  //ACTOR3 = 1012338
  //ACTOR4 = 1012339
  //ACTOR5 = 1012340
  //ENEMY0 = 5856587
  //ENEMY1 = 5856588
  //ENEMY2 = 5856589
  //EOBJECT0 = 2005406
  //EVENTRANGE0 = 5856600
  //EVENTACTIONRESCURE = 26
  //LOCACTOR0 = 1012463

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=REDWALD
        break;
      }
      case 1:
      {
        if( param1 == 1012334 || param2 == 1012334 ) // ACTOR1 = ARTOIREL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=ARTOIREL
          }
          break;
        }
        if( param1 == 1011231 || param2 == 1011231 ) // ACTOR0 = REDWALD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=REDWALD
          break;
        }
        break;
      }
      case 2:
      {
        if( type != 2 ) Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ARTOIREL
        break;
      }
      case 3:
      {
        if( type != 2 ) Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=ARTOIREL
        break;
      }
      case 4:
      {
        if( param1 == 5856600 || param2 == 5856600 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00006( player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5856587 || param2 == 5856587 ) // ENEMY0 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 5856588 || param2 == 5856588 ) // ENEMY1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 5856589 || param2 == 5856589 ) // ENEMY2 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012339 || param2 == 1012339 ) // ACTOR4 = ARTOIREL
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 2005406 || param2 == 2005406 ) // EOBJECT0 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1012340 || param2 == 1012340 ) // ACTOR5 = KIGHT01583
        {
          Scene00012( player ); // Scene00012: Normal(Talk, Message, TargetCanMove), id=KIGHT01583
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00014( player ); // Scene00014: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=KIGHT01583
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna108:67123 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna108:67123 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna108:67123 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna108:67123 calling Scene00003: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna108:67123 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna108:67123 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_4: EVENTRANGE0, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "HeaVna108:67123 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_4: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna108:67123 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_4: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna108:67123 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00009( Entity::Player& player ) //SEQ_4: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna108:67123 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00010( Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna108:67123 calling Scene00010: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_4: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna108:67123 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00012( Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna108:67123 calling Scene00012: Normal(Talk, Message, TargetCanMove), id=KIGHT01583" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna108:67123 calling Scene00014: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=KIGHT01583" );
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
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( HeaVna108 );
