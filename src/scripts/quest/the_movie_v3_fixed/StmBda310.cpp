// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda310 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda310() : Sapphire::ScriptAPI::EventScript( 68022 ){}; 
  ~StmBda310() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 4 entries
  //SEQ_2, 5 entries
  //SEQ_3, 5 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1019971
  //ACTOR1 = 1019970
  //ACTOR2 = 1019978
  //ACTOR3 = 1019977
  //ACTOR4 = 1022365
  //ACTOR5 = 1022366
  //ACTOR6 = 5010000
  //BINDACTOR0 = 6830040
  //BINDACTOR1 = 6830042
  //EOBJECT0 = 2007920
  //EVENTACTION0 = 2
  //ITEM0 = 2002243
  //ITEM1 = 2002095
  //LOCACTOR0 = 1021995
  //LOCACTOR1 = 1021996

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( param1 == 1019971 || param2 == 1019971 ) // ACTOR0 = ALISAIE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=ALISAIE
        }
        if( param1 == 1019970 || param2 == 1019970 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 1019978 || param2 == 1019978 ) // ACTOR2 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          }
        }
        if( param1 == 1019977 || param2 == 1019977 ) // ACTOR3 = LYSE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1022365 || param2 == 1022365 ) // ACTOR4 = IHANAMI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=IHANAMI
        }
        if( param1 == 1022366 || param2 == 1022366 ) // ACTOR5 = YUNAGI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YUNAGI
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( param1 == 5010000 || param2 == 5010000 ) // ACTOR6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
        }
        if( param1 == 1019977 || param2 == 1019977 ) // ACTOR3 = LYSE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019978 || param2 == 1019978 ) // ACTOR2 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1022365 || param2 == 1022365 ) // ACTOR4 = IHANAMI
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=IHANAMI
        }
        if( param1 == 1022366 || param2 == 1022366 ) // ACTOR5 = YUNAGI
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YUNAGI
        }
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack 1
      //seq 3 event item ITEM0 = UI8BL max stack ?
      case 3:
      {
        if( param1 == 2007920 || param2 == 2007920 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(None), id=unknown
          }
        }
        if( param1 == 1019977 || param2 == 1019977 ) // ACTOR3 = LYSE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019978 || param2 == 1019978 ) // ACTOR2 = ALISAIE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1022365 || param2 == 1022365 ) // ACTOR4 = IHANAMI
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=IHANAMI
        }
        if( param1 == 1022366 || param2 == 1022366 ) // ACTOR5 = YUNAGI
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=YUNAGI
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 1
      //seq 255 event item ITEM0 = UI8BL max stack ?
      case 255:
      {
        if( param1 == 1019978 || param2 == 1019978 ) // ACTOR2 = ALISAIE
        {
          Scene00019( player ); // Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019977 || param2 == 1019977 ) // ACTOR3 = LYSE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=LYSE
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
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestUI8BL( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda310:68022 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=ALISAIE" );
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
    player.sendDebug( "StmBda310:68022 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      //checkProgressSeq1( player );
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 3 );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00005: Normal(Talk, TargetCanMove), id=IHANAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00006: Normal(Talk, TargetCanMove), id=YUNAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00009: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00011: Normal(Talk, TargetCanMove), id=IHANAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00012: Normal(Talk, TargetCanMove), id=YUNAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00014: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00015: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00017: Normal(Talk, TargetCanMove), id=IHANAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00018: Normal(Talk, TargetCanMove), id=YUNAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda310:68022 calling [BranchTrue]Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda310:68022 calling Scene00021: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda310 );
