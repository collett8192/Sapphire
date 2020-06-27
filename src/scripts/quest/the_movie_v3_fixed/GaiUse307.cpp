// FFXIVTheMovie.ParserV3
//fix: add code to enter instance
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse307 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse307() : Sapphire::ScriptAPI::EventScript( 66984 ){}; 
  ~GaiUse307() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 8 entries
  //SEQ_255, 2 entries

  //ACTIONTIMELINEEVENTJOY = 953
  //ACTIONTIMELINEFACIALFEAR = 614
  //ACTIONTIMELINEFACIALSMILE = 605
  //ACTIONTIMELINEFACIALSPEWING = 617
  //ACTOR0 = 1008579
  //ACTOR1 = 1009089
  //ACTOR10 = 1000460
  //ACTOR11 = 1009097
  //ACTOR2 = 1000168
  //ACTOR3 = 1008969
  //ACTOR4 = 1003027
  //ACTOR5 = 1009091
  //ACTOR6 = 1009092
  //ACTOR7 = 1009093
  //ACTOR8 = 1009094
  //ACTOR9 = 1009090
  //CUTSCENEN01 = 533
  //EVENTACTIONSEARCH = 1
  //LOCACTOR0 = 1008176
  //LOCACTOR1 = 1008177
  //LOCACTOR2 = 1008178
  //LOCACTOR3 = 1008179
  //LOCACTOR4 = 4866717
  //POPRANGE0 = 3877982
  //POPRANGE1 = 3878860
  //TERRITORYTYPE0 = 205

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1008579 || actorId == 1008579 ) // ACTOR0 = MINFILIA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MINFILIA
        }
        if( actor == 1009089 || actorId == 1009089 ) // ACTOR1 = MESSENGER01447
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MESSENGER01447
        }
        break;
      }
      case 1:
      {
        if( actor == 1000168 || actorId == 1000168 ) // ACTOR2 = VORSAILE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=VORSAILE
          }
        }
        if( actor == 1009089 || actorId == 1009089 ) // ACTOR1 = MESSENGER01447
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MESSENGER01447
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR3 = MINFILIA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        break;
      }
      case 2:
      {
        if( actor == 1003027 || actorId == 1003027 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1009091 || actorId == 1009091 ) // ACTOR5 = YDA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1009092 || actorId == 1009092 ) // ACTOR6 = PAPALYMO
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1009093 || actorId == 1009093 ) // ACTOR7 = THANCRED
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1009094 || actorId == 1009094 ) // ACTOR8 = YSHTOLA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1009090 || actorId == 1009090 ) // ACTOR9 = SYLPH01448
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=SYLPH01448
        }
        if( actor == 1000168 || actorId == 1000168 ) // ACTOR2 = VORSAILE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=VORSAILE
        }
        if( actor == 1000460 || actorId == 1000460 ) // ACTOR10 = DOORMANLOTUS
        {
          Scene00013( player ); // Scene00013: Normal(Talk, YesNo, TargetCanMove), id=DOORMANLOTUS
        }
        break;
      }
      case 255:
      {
        if( actor == 1009097 || actorId == 1009097 ) // ACTOR11 = LIEUTENANT01448
        {
          Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LIEUTENANT01448
        }
        if( actor == 1000460 || actorId == 1000460 ) // ACTOR10 = DOORMANLOTUS
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=DOORMANLOTUS
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
    onProgress( player, param1, param1, 3, param1 );
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse307:66984 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00002: Normal(Talk, TargetCanMove), id=MESSENGER01447" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00003: Normal(Talk, TargetCanMove), id=VORSAILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00004: Normal(Talk, TargetCanMove), id=MESSENGER01447" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00005: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00006: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00007: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00008: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00009: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00010: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00011: Normal(Talk, TargetCanMove), id=SYLPH01448" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00012: Normal(Talk, TargetCanMove), id=VORSAILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00013: Normal(Talk, YesNo, TargetCanMove), id=DOORMANLOTUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 205 );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LIEUTENANT01448" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse307:66984 calling Scene00015: Normal(Talk, TargetCanMove), id=DOORMANLOTUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse307 );
