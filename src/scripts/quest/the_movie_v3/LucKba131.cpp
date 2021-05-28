// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKba131 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKba131() : Sapphire::ScriptAPI::EventScript( 68782 ){}; 
  ~LucKba131() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 3 entries
  //SEQ_3, 3 entries
  //SEQ_4, 2 entries
  //SEQ_5, 5 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1029959
  //ACTOR1 = 1029960
  //ACTOR2 = 1027670
  //ACTOR3 = 1027671
  //ACTOR4 = 1029961
  //ACTOR5 = 1029963
  //ACTOR6 = 1029966
  //BINDACTOR01 = 7929591
  //ENEMY0 = 7929593
  //ENEMY1 = 7929594
  //EOBJECT0 = 2009946
  //EVENTACTION0 = 41
  //EVENTACTION1 = 1
  //EVENTPICTRUELUCKBA13101 = 801
  //EVENTPICTRUELUCKBA13102 = 800
  //EVENTPICTRUELUCKBA13103 = 802
  //LOCACTOR01 = 1028190
  //LOCBGM01 = 647
  //NCUTEVENTLUCKBA13101 = 2091
  //QSTLUCKMB113 = 68850

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=GRANSON
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove, Menu), id=GRANSON
        break;
      }
      case 2:
      {
        if( param1 == 1027670 || param2 == 1027670 ) // ACTOR2 = IALAOUL
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=IALAOUL
            // +Callback Scene00004: Normal(Talk, TargetCanMove), id=IALAOUL
          }
          break;
        }
        if( param1 == 1027671 || param2 == 1027671 ) // ACTOR3 = DAENKENN
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=DAENKENN
            // +Callback Scene00006: Normal(Talk, TargetCanMove), id=DAENKENN
          }
          break;
        }
        if( param1 == 1029961 || param2 == 1029961 ) // ACTOR4 = GRANSON
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=GRANSON
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1029961 || param2 == 1029961 ) // ACTOR4 = GRANSON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON
          }
          break;
        }
        if( param1 == 1027670 || param2 == 1027670 ) // ACTOR2 = IALAOUL
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=IALAOUL
          break;
        }
        if( param1 == 1027671 || param2 == 1027671 ) // ACTOR3 = DAENKENN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=DAENKENN
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1029963 || param2 == 1029963 ) // ACTOR5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1029966 || param2 == 1029966 ) // ACTOR6 = GRANSON
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=GRANSON
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 2009946 || param2 == 2009946 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00014( player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 7929593 || param2 == 7929593 ) // ENEMY0 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7929594 || param2 == 7929594 ) // ENEMY1 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1029963 || param2 == 1029963 ) // ACTOR5 = SULOUL
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=SULOUL
          break;
        }
        if( param1 == 1029966 || param2 == 1029966 ) // ACTOR6 = GRANSON
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=GRANSON
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029963 || param2 == 1029963 ) // ACTOR5 = SULOUL
        {
          Scene00021( player ); // Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SULOUL
          break;
        }
        if( param1 == 1029966 || param2 == 1029966 ) // ACTOR6 = GRANSON
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=GRANSON
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
    player.updateQuest( getId(), 2 );
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
    if( player.getQuestUI8AL( getId() ) == 1 )
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
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk), id=unknown" );
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
    player.sendDebug( "LucKba131:68782 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove, Menu), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00003: Normal(Talk, TargetCanMove), id=IALAOUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00004: Normal(Talk, TargetCanMove), id=IALAOUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00005: Normal(Talk, TargetCanMove), id=DAENKENN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00006: Normal(Talk, TargetCanMove), id=DAENKENN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00007: Normal(Talk, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00009: Normal(Talk, TargetCanMove), id=IALAOUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00010: Normal(Talk, TargetCanMove), id=DAENKENN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00011: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00012: Normal(Talk, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00016: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00018: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00019: Normal(Talk, TargetCanMove), id=SULOUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00020: Normal(Talk, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SULOUL" );
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
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKba131:68782 calling Scene00022: Normal(Talk, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKba131 );
