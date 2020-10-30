// FFXIVTheMovie.ParserV3
// id hint used:
//ACTOR3 = RAUBAHN
//ACTOR4 = ALISAIE
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda113 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda113() : Sapphire::ScriptAPI::EventScript( 67989 ){}; 
  ~StmBda113() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 5 entries
  //SEQ_2, 6 entries
  //SEQ_3, 1 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1020304
  //ACTOR1 = 1020355
  //ACTOR2 = 1020354
  //ACTOR3 = 1020503
  //ACTOR4 = 1020502
  //ACTOR5 = 1020504
  //ACTOR6 = 1020505
  //ACTOR7 = 1020361
  //ACTOR8 = 1020358
  //BINDACTOR01 = 6829573
  //BINDACTOR02 = 6829576
  //CUTSCENEN01 = 1386
  //CUTSCENEN02 = 1387
  //ENEMY0 = 7021908
  //ENEMY1 = 7021909
  //EOBJECT0 = 2007955
  //EOBJECT1 = 2007956
  //EVENTACTION0 = 50
  //EVENTACTION1 = 1
  //LOCACTOR01 = 1017687
  //LOCACTOR02 = 1022485
  //LOCACTOR03 = 1018318
  //LOCACTOR04 = 1019082
  //LOCACTOR05 = 1019700
  //LOCACTOR06 = 1019701
  //LOCACTOR07 = 1019702
  //LOCACTOR08 = 1019703
  //LOCIDLE01 = 4295
  //QUESTBATTLE0 = 159
  //TERRITORYTYPE0 = 670
  //TERRITORYTYPE1 = 612

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020304 || param2 == 1020304 ) // ACTOR0 = RAUBAHN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RAUBAHN
        }
        if( param1 == 1020355 || param2 == 1020355 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020354 || param2 == 1020354 ) // ACTOR2 = PIPIN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=PIPIN
        }
        break;
      }
      case 1:
      {
        if( param1 == 2007955 || param2 == 2007955 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 7021908 || param2 == 7021908 ) // ENEMY0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( param1 == 7021909 || param2 == 7021909 ) // ENEMY1 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00009: Normal(Message, PopBNpc), id=unknown
        }
        if( param1 == 1020354 || param2 == 1020354 ) // ACTOR2 = PIPIN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=PIPIN
        }
        if( param1 == 1020304 || param2 == 1020304 ) // ACTOR0 = RAUBAHN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=RAUBAHN
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020503 || param2 == 1020503 ) // ACTOR3 = RAUBAHN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=RAUBAHN
            // +Callback Scene00013: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1020502 || param2 == 1020502 ) // ACTOR4 = ALISAIE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020504 || param2 == 1020504 ) // ACTOR5 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( param1 == 1020505 || param2 == 1020505 ) // ACTOR6 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( param1 == 2007956 || param2 == 2007956 ) // EOBJECT1 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( param1 == 1020354 || param2 == 1020354 ) // ACTOR2 = PIPIN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=PIPIN
          // +Callback Scene00019: Normal(CutScene), id=unknown
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00020( player ); // Scene00020: Normal(FadeIn, Dismount), id=unknown
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020361 || param2 == 1020361 ) // ACTOR7 = MNAAGO
        {
          Scene00021( player ); // Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MNAAGO
        }
        if( param1 == 1020358 || param2 == 1020358 ) // ACTOR8 = ALISAIE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020354 || param2 == 1020354 ) // ACTOR2 = PIPIN
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=PIPIN
        }
        if( param1 == 1020304 || param2 == 1020304 ) // ACTOR0 = RAUBAHN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=RAUBAHN
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda113:67989 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00003: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling [BranchTrue]Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00010: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00011: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00012: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 != 50 )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling [BranchTrue]Scene00013: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00018: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling [BranchTrue]Scene00019: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00020: Normal(FadeIn, Dismount), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00023: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda113:67989 calling Scene00024: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda113 );
