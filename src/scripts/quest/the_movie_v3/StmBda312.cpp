// FFXIVTheMovie.ParserV3.1
// id hint used:
//EVENTRANGE1 = range1
//SCENE_10 = range1
//ACTOR5 = LYSE
//ACTOR6 = dummy6
//ACTOR7 = dummy7
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda312 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda312() : Sapphire::ScriptAPI::EventScript( 68024 ){}; 
  ~StmBda312() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 6 entries
  //SEQ_4, 3 entries
  //SEQ_5, 4 entries
  //SEQ_255, 2 entries

  //ACTIONTIMELINEEVENTSPIRIT = 1071
  //ACTOR0 = 1019961
  //ACTOR1 = 1019962
  //ACTOR10 = 1019985
  //ACTOR11 = 1019986
  //ACTOR2 = 1019981
  //ACTOR3 = 1019982
  //ACTOR4 = 1019178
  //ACTOR5 = 1020624
  //ACTOR6 = 1023093
  //ACTOR7 = 1020207
  //ACTOR8 = 1019983
  //ACTOR9 = 1019984
  //BINDACTOR0 = 6830024
  //BINDACTOR1 = 6836813
  //CUTSCENEN01 = 1417
  //ENEMY0 = 6913091
  //ENEMY1 = 6836836
  //ENEMY2 = 6836839
  //ENEMY3 = 6836841
  //ENEMY4 = 6913092
  //ENEMY5 = 6913377
  //EOBJECT0 = 2007922
  //EOBJECT1 = 2007921
  //EVENTRANGE0 = 6836822
  //EVENTRANGE1 = 6836824
  //POPRANGE0 = 6842986

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1019961 || param2 == 1019961 ) // ACTOR0 = ALISAIE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, Menu), id=ALISAIE
        }
        if( param1 == 1019962 || param2 == 1019962 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019981 || param2 == 1019981 ) // ACTOR2 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE
          }
        }
        if( param1 == 1019982 || param2 == 1019982 ) // ACTOR3 = LYSE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019178 || param2 == 1019178 ) // ACTOR4 = BUNCHIN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=BUNCHIN
        }
        break;
      }
      case 2:
      {
        if( param1 == 6836822 || param2 == 6836822 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00006( player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 6913091 || param2 == 6913091 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( param1 == 6836836 || param2 == 6836836 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( param1 == 2007922 || param2 == 2007922 ) // EOBJECT0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( param1 == 6836824 || param2 == 6836824 ) // EVENTRANGE1 = range1
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00010( player ); // Scene00010: Normal(Message, PopBNpc), id=range1
          }
        }
        if( param1 == 6836839 || param2 == 6836839 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( param1 == 6836841 || param2 == 6836841 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( param1 == 6913092 || param2 == 6913092 ) // ENEMY4 = unknown
        {
          // empty entry
        }
        if( param1 == 6913377 || param2 == 6913377 ) // ENEMY5 = unknown
        {
          // empty entry
        }
        if( param1 == 2007921 || param2 == 2007921 ) // EOBJECT1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020624 || param2 == 1020624 ) // ACTOR5 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE
          }
        }
        if( param1 == 1023093 || param2 == 1023093 ) // ACTOR6 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( param1 == 1020207 || param2 == 1020207 ) // ACTOR7 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        break;
      }
      case 5:
      {
        if( param1 == 1019983 || param2 == 1019983 ) // ACTOR8 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE
            // +Callback Scene00020: Normal(CutScene, AutoFadeIn), id=unknown
          }
        }
        if( param1 == 1019984 || param2 == 1019984 ) // ACTOR9 = LYSE
        {
          Scene00021( player ); // Scene00021: Normal(Talk), id=LYSE
        }
        if( param1 == 1023093 || param2 == 1023093 ) // ACTOR6 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
        }
        if( param1 == 1020207 || param2 == 1020207 ) // ACTOR7 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019985 || param2 == 1019985 ) // ACTOR10 = ALISAIE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019986 || param2 == 1019986 ) // ACTOR11 = LYSE
        {
          Scene00025( player ); // Scene00025: Normal(Talk), id=LYSE
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
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 4 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda312:68024 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, Menu), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00005: Normal(Talk, TargetCanMove), id=BUNCHIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00010: Normal(Message, PopBNpc), id=range1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 4 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00020: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00021: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
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
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda312:68024 calling Scene00025: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda312 );
