// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda327 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda327() : Sapphire::ScriptAPI::EventScript( 68489 ){}; 
  ~StmBda327() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_2, 5 entries
  //SEQ_3, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1021507
  //ACTOR1 = 1023682
  //ENEMY0 = 7011281
  //EOBJECT0 = 2009002
  //EOBJECT1 = 2009003
  //EOBJECT2 = 2009004
  //EOBJECT3 = 2008572
  //EVENTACTION0 = 1
  //EVENTACTION1 = 5
  //EVENTRANGE0 = 7011338
  //ITEM0 = 2002387
  //ITEM1 = 2002388
  //LOGMES01 = 3757

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=KAJIKA
        break;
      }
      case 1:
      {
        if( param1 == 7011338 || param2 == 7011338 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 7011281 || param2 == 7011281 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( param1 == 1023682 || param2 == 1023682 ) // ACTOR1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(SystemTalk), id=unknown
        }
        if( param1 == 2009002 || param2 == 2009002 ) // EOBJECT0 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        if( param1 == 2009003 || param2 == 2009003 ) // EOBJECT1 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( param1 == 2009004 || param2 == 2009004 ) // EOBJECT2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( param1 == 2008572 || param2 == 2008572 ) // EOBJECT3 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( param1 == 1021507 || param2 == 1021507 ) // ACTOR0 = KAJIKA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=KAJIKA
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 3
      case 2:
      {
        if( param1 == 1023682 || param2 == 1023682 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
          }
        }
        if( param1 == 2009002 || param2 == 2009002 ) // EOBJECT0 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( param1 == 2009003 || param2 == 2009003 ) // EOBJECT1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( param1 == 2009004 || param2 == 2009004 ) // EOBJECT2 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( param1 == 1021507 || param2 == 1021507 ) // ACTOR0 = KAJIKA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=KAJIKA
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 3
      //seq 3 event item ITEM1 = UI8BL max stack 8
      case 3:
      {
        if( param1 == 1023682 || param2 == 1023682 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(None), id=unknown
          }
        }
        if( param1 == 1021507 || param2 == 1021507 ) // ACTOR0 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(NpcDespawn), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      //seq 255 event item ITEM1 = UI8BL max stack 8
      case 255:
      {
        Scene00019( player ); // Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KAJIKA
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
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 3 );
      player.setQuestUI8BL( getId(), 8 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=KAJIKA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00004: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00009: Normal(Talk, TargetCanMove), id=KAJIKA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00010: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00015: Normal(Talk, TargetCanMove), id=KAJIKA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00016: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00017: Normal(NpcDespawn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00020( player );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda327:68489 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KAJIKA" );
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
    player.playScene( getId(), 20, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda327 );
