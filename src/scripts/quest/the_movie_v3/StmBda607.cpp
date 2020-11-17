// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda607 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda607() : Sapphire::ScriptAPI::EventScript( 68069 ){}; 
  ~StmBda607() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 6 entries
  //SEQ_255, 8 entries

  //ACTOR0 = 1020589
  //ACTOR1 = 1020590
  //ACTOR10 = 1022332
  //ACTOR11 = 1022333
  //ACTOR12 = 1020596
  //ACTOR13 = 1020597
  //ACTOR14 = 1020579
  //ACTOR15 = 1020806
  //ACTOR16 = 1021565
  //ACTOR2 = 1020591
  //ACTOR3 = 1020592
  //ACTOR4 = 1020817
  //ACTOR5 = 1020827
  //ACTOR6 = 1020586
  //ACTOR7 = 1020587
  //ACTOR8 = 1020588
  //ACTOR9 = 1020578
  //BINDACTOR01 = 6853912
  //BINDACTOR02 = 6853914
  //BINDACTOR03 = 6853915
  //BINDACTOR04 = 6853903
  //BINDACTOR05 = 6853905
  //BINDACTOR06 = 6853906
  //BINDACTOR07 = 6794381
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019541
  //LOCACTOR03 = 1018509
  //LOCACTOR04 = 1021985
  //LOCACTOR05 = 1021986
  //LOCACTOR06 = 1015903
  //LOCACTOR07 = 1019082
  //LOCACTOR08 = 1022004
  //LOCBGM01 = 400
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //LOCOBJECT01 = 2008208
  //LOCWEATHER01 = 2
  //POPRANGE0 = 6904795

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020589 || param2 == 1020589 ) // ACTOR0 = VAJRA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=VAJRA
          break;
        }
        if( param1 == 1020590 || param2 == 1020590 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020591 || param2 == 1020591 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020592 || param2 == 1020592 ) // ACTOR3 = LYSE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020817 || param2 == 1020817 ) // ACTOR4 = SARISHA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=SARISHA
          }
          break;
        }
        if( param1 == 1020827 || param2 == 1020827 ) // ACTOR5 = VAJRA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=VAJRA
          break;
        }
        if( param1 == 1020586 || param2 == 1020586 ) // ACTOR6 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020587 || param2 == 1020587 ) // ACTOR7 = ALISAIE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020588 || param2 == 1020588 ) // ACTOR8 = LYSE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020578 || param2 == 1020578 ) // ACTOR9 = MNAAGO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, FadeIn, TargetCanMove), id=MNAAGO
          }
          break;
        }
        if( param1 == 1022332 || param2 == 1022332 ) // ACTOR10 = PIPIN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1022333 || param2 == 1022333 ) // ACTOR11 = CONRAD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020827 || param2 == 1020827 ) // ACTOR5 = VAJRA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=VAJRA
          break;
        }
        if( param1 == 1020817 || param2 == 1020817 ) // ACTOR4 = SARISHA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=SARISHA
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020578 || param2 == 1020578 ) // ACTOR9 = MNAAGO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=MNAAGO
            // +Callback Scene00016: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1020596 || param2 == 1020596 ) // ACTOR12 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020597 || param2 == 1020597 ) // ACTOR13 = ALISAIE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020579 || param2 == 1020579 ) // ACTOR14 = LYSE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020827 || param2 == 1020827 ) // ACTOR5 = VAJRA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=VAJRA
          break;
        }
        if( param1 == 1020817 || param2 == 1020817 ) // ACTOR4 = SARISHA
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=SARISHA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020596 || param2 == 1020596 ) // ACTOR12 = ALPHINAUD
        {
          Scene00022( player ); // Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020579 || param2 == 1020579 ) // ACTOR14 = LYSE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020597 || param2 == 1020597 ) // ACTOR13 = ALISAIE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020578 || param2 == 1020578 ) // ACTOR9 = MNAAGO
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020806 || param2 == 1020806 ) // ACTOR15 = MHAHTOA
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=MHAHTOA
          break;
        }
        if( param1 == 1021565 || param2 == 1021565 ) // ACTOR16 = MRAHZNUN
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=MRAHZNUN
          break;
        }
        if( param1 == 1020827 || param2 == 1020827 ) // ACTOR5 = VAJRA
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=VAJRA
          break;
        }
        if( param1 == 1020817 || param2 == 1020817 ) // ACTOR4 = SARISHA
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=SARISHA
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
    player.sendDebug( "StmBda607:68069 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda607:68069 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=VAJRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00005: Normal(Talk, TargetCanMove), id=SARISHA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00006: Normal(Talk, TargetCanMove), id=VAJRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00009: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00010: Normal(Talk, FadeIn, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00011: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00012: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00013: Normal(Talk, TargetCanMove), id=VAJRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00014: Normal(Talk, TargetCanMove), id=SARISHA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00015: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00016: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq3( player );
        player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
        player.eventFinish( getId(), 1 );
        player.forceZoneing();
      }
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00019: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00020: Normal(Talk, TargetCanMove), id=VAJRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00021: Normal(Talk, TargetCanMove), id=SARISHA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.sendDebug( "StmBda607:68069 calling Scene00023: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00025: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00026: Normal(Talk, TargetCanMove), id=MHAHTOA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00027: Normal(Talk, TargetCanMove), id=MRAHZNUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00028: Normal(Talk, TargetCanMove), id=VAJRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda607:68069 calling Scene00029: Normal(Talk, TargetCanMove), id=SARISHA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda607 );
