// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda316 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda316() : Sapphire::ScriptAPI::EventScript( 68028 ){}; 
  ~StmBda316() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 4 entries
  //SEQ_3, 3 entries
  //SEQ_255, 4 entries

  //ACTIONTIMELINEEVENTSUFFERING = 961
  //ACTOR0 = 1019997
  //ACTOR1 = 1019998
  //ACTOR10 = 1020007
  //ACTOR11 = 1020004
  //ACTOR2 = 1019999
  //ACTOR3 = 1020000
  //ACTOR4 = 1020001
  //ACTOR5 = 1020002
  //ACTOR6 = 1020003
  //ACTOR7 = 1020016
  //ACTOR8 = 1020005
  //ACTOR9 = 1020006
  //BINDACTOR0 = 6790175
  //BINDACTOR1 = 6790176
  //BINDACTOR2 = 6790177
  //EOBJECT0 = 2007834
  //EVENTACTION0 = 50
  //NCUT01 = 1424
  //POPRANGE0 = 6790178

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1019997 || param2 == 1019997 ) // ACTOR0 = GOSETSU
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1019998 || param2 == 1019998 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019999 || param2 == 1019999 ) // ACTOR2 = LYSE
        {
          Scene00003( player ); // Scene00003: Normal(Talk), id=LYSE
        }
        break;
      }
      case 1:
      {
        if( param1 == 2007834 || param2 == 2007834 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(CutScene, AutoFadeIn), id=unknown
          }
        }
        if( param1 == 1019997 || param2 == 1019997 ) // ACTOR0 = GOSETSU
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1019998 || param2 == 1019998 ) // ACTOR1 = ALISAIE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019999 || param2 == 1019999 ) // ACTOR2 = LYSE
        {
          Scene00008( player ); // Scene00008: Normal(Talk), id=LYSE
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020000 || param2 == 1020000 ) // ACTOR3 = ISSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, FadeIn, TargetCanMove), id=ISSE
          }
        }
        if( param1 == 1020001 || param2 == 1020001 ) // ACTOR4 = GOSETSU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1020002 || param2 == 1020002 ) // ACTOR5 = ALISAIE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020003 || param2 == 1020003 ) // ACTOR6 = LYSE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020016 || param2 == 1020016 ) // ACTOR7 = GOSETSU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=GOSETSU
          }
        }
        if( param1 == 1020005 || param2 == 1020005 ) // ACTOR8 = LYSE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020006 || param2 == 1020006 ) // ACTOR9 = ALISAIE
        {
          Scene00015( player ); // Scene00015: Normal(Talk), id=ALISAIE
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020007 || param2 == 1020007 ) // ACTOR10 = GOSETSU
        {
          Scene00016( player ); // Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1020005 || param2 == 1020005 ) // ACTOR8 = LYSE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020006 || param2 == 1020006 ) // ACTOR9 = ALISAIE
        {
          Scene00018( player ); // Scene00018: Normal(Talk), id=ALISAIE
        }
        if( param1 == 1020004 || param2 == 1020004 ) // ACTOR11 = RESSIANGATEKEEPER
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=RESSIANGATEKEEPER
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
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda316:68028 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00003: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00005: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00008: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00009: Normal(Talk, FadeIn, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00012: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00014: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00015: Normal(Talk), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GOSETSU" );
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
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00017: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00018: Normal(Talk), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda316:68028 calling Scene00019: Normal(Talk, TargetCanMove), id=RESSIANGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda316 );
