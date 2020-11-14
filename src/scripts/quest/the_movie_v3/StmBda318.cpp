// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda318 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda318() : Sapphire::ScriptAPI::EventScript( 68030 ){}; 
  ~StmBda318() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 7 entries
  //SEQ_2, 1 entries
  //SEQ_3, 3 entries
  //SEQ_4, 1 entries
  //SEQ_5, 1 entries
  //SEQ_255, 3 entries

  //ACTIONTIMELINEEVENTSTANDPRAY = 4254
  //ACTOR0 = 1020012
  //ACTOR1 = 1020013
  //ACTOR2 = 1020018
  //ACTOR3 = 1020071
  //ACTOR4 = 1020072
  //ACTOR5 = 1020019
  //ACTOR6 = 1020020
  //ACTOR7 = 1020021
  //BINDACTOR0 = 6782229
  //ENEMY0 = 6791550
  //ENEMY1 = 6791551
  //ENEMY2 = 6791564
  //EOBJECT0 = 2007844
  //EOBJECT1 = 2007836
  //EOBJECT2 = 2007837
  //EVENTACTION0 = 1
  //EVENTACTION1 = 26
  //EVENTRANGE0 = 6793562
  //ITEM0 = 2002067
  //LOCACTOR0 = 1018977
  //LOCEOBJ01 = 2008780

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020012 || param2 == 1020012 ) // ACTOR0 = YUGIRI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020013 || param2 == 1020013 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 1:
      {
        if( param1 == 6793562 || param2 == 6793562 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00003( player ); // Scene00003: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 6791550 || param2 == 6791550 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( param1 == 6791551 || param2 == 6791551 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( param1 == 1020018 || param2 == 1020018 ) // ACTOR2 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( param1 == 1020071 || param2 == 1020071 ) // ACTOR3 = AZAMI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, Message), id=AZAMI
        }
        if( param1 == 1020072 || param2 == 1020072 ) // ACTOR4 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( param1 == 2007844 || param2 == 2007844 ) // EOBJECT0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=AZAMI
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 2007836 || param2 == 2007836 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 6791564 || param2 == 6791564 ) // ENEMY2 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(Message, PopBNpc), id=unknown
        }
        if( param1 == 1020018 || param2 == 1020018 ) // ACTOR2 = AZAMI
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=AZAMI
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        Scene00018( player ); // Scene00018: NpcTrade(Talk), id=unknown
        // +Callback Scene00019: Normal(Talk, NpcDespawn, TargetCanMove), id=AZAMI
        break;
      }
      case 5:
      {
        Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=AZAMI
        // +Callback Scene00021: Normal(Talk, FadeIn, TargetCanMove, Menu), id=AZAMI
        break;
      }
      case 255:
      {
        if( param1 == 1020020 || param2 == 1020020 ) // ACTOR6 = YUGIRI
        {
          Scene00022( player ); // Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020021 || param2 == 1020021 ) // ACTOR7 = LYSE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 2007837 || param2 == 2007837 ) // EOBJECT2 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda318:68030 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00006: Normal(Talk, Message), id=AZAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00012: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00016: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00017: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00018: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00019( player );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00019: Normal(Talk, NpcDespawn, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00020: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00021: Normal(Talk, FadeIn, TargetCanMove, Menu), id=AZAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq5( player );
      }
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YUGIRI" );
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
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00023: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda318:68030 calling Scene00024: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda318 );
