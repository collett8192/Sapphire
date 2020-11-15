// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda418 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda418() : Sapphire::ScriptAPI::EventScript( 68053 ){}; 
  ~StmBda418() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 7 entries
  //SEQ_2, 8 entries
  //SEQ_255, 9 entries

  //ACTIONTIMELINEFACIALWINK = 621
  //ACTOR0 = 1021633
  //ACTOR1 = 1021632
  //ACTOR10 = 1020280
  //ACTOR11 = 1021645
  //ACTOR12 = 1021642
  //ACTOR13 = 1021644
  //ACTOR14 = 1021643
  //ACTOR15 = 1021646
  //ACTOR16 = 1021647
  //ACTOR17 = 1021649
  //ACTOR18 = 1021648
  //ACTOR19 = 1019319
  //ACTOR2 = 1021631
  //ACTOR3 = 1021924
  //ACTOR4 = 1019417
  //ACTOR5 = 1021733
  //ACTOR6 = 1021730
  //ACTOR7 = 1021732
  //ACTOR8 = 1021731
  //ACTOR9 = 1019382
  //JPBOW2 = 5481
  //LOCBGMYUSO = 463
  //LOCBINDGOUSETSU001 = 6871034
  //LOCBINDGOUSETSU002 = 6872468
  //LOCBINDGOUSETSU003 = 6872514
  //LOCBINDGOUSETSU004 = 6872561
  //LOCBINDHIEN002 = 6872466
  //LOCBINDHIEN003 = 6872512
  //LOCBINDHIEN004 = 6872545
  //LOCBINDLISE001 = 6871033
  //LOCBINDLISE002 = 6872467
  //LOCBINDLISE003 = 6872513
  //LOCBINDLISE004 = 6872560
  //LOCBINDSHARU = 6841536
  //LOCBINDSHIRINA001 = 6851362
  //LOCBINDSHIRINA001002 = 6872465
  //LOCBINDSHIRINA002 = 6872511
  //LOCBINDTEMURUN = 6719188
  //LOCMAGUNAIWEP = 2008349
  //LOCMAGUNAIWEPPOS = 7021939
  //LOCSTMBGM = 457
  //LOCTOSHOBGM = 465

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1021633 || param2 == 1021633 ) // ACTOR0 = HIEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021632 || param2 == 1021632 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021631 || param2 == 1021631 ) // ACTOR2 = GOSETSU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021924 || param2 == 1021924 ) // ACTOR3 = DORBEI
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR4 = MAGNAI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=MAGNAI
          }
          break;
        }
        if( param1 == 1021733 || param2 == 1021733 ) // ACTOR5 = CIRINA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021730 || param2 == 1021730 ) // ACTOR6 = HIEN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021732 || param2 == 1021732 ) // ACTOR7 = LYSE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021731 || param2 == 1021731 ) // ACTOR8 = GOSETSU
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021924 || param2 == 1021924 ) // ACTOR3 = DORBEI
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020280 || param2 == 1020280 ) // ACTOR10 = SADU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, FadeIn, TargetCanMove), id=SADU
          }
          break;
        }
        if( param1 == 1021645 || param2 == 1021645 ) // ACTOR11 = CIRINA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021642 || param2 == 1021642 ) // ACTOR12 = HIEN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021644 || param2 == 1021644 ) // ACTOR13 = LYSE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021643 || param2 == 1021643 ) // ACTOR14 = GOSETSU
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR4 = MAGNAI
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MAGNAI
          break;
        }
        if( param1 == 1021924 || param2 == 1021924 ) // ACTOR3 = DORBEI
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021646 || param2 == 1021646 ) // ACTOR15 = CIRINA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021647 || param2 == 1021647 ) // ACTOR16 = HIEN
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021649 || param2 == 1021649 ) // ACTOR17 = LYSE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021648 || param2 == 1021648 ) // ACTOR18 = GOSETSU
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR4 = MAGNAI
        {
          Scene00024( player ); // Scene00024: Normal(Talk), id=MAGNAI
          break;
        }
        if( param1 == 1019319 || param2 == 1019319 ) // ACTOR19 = SHAR
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=SHAR
          break;
        }
        if( param1 == 1020280 || param2 == 1020280 ) // ACTOR10 = SADU
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=SADU
          break;
        }
        if( param1 == 1021924 || param2 == 1021924 ) // ACTOR3 = DORBEI
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=TEMULUN
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda418:68053 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00004: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=MAGNAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00006: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00007: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00008: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00009: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00010: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00011: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00012: Normal(Talk, FadeIn, TargetCanMove), id=SADU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00013: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00014: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00015: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00016: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00017: Normal(Talk, TargetCanMove), id=MAGNAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00018: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00019: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CIRINA" );
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
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00021: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00022: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00023: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00024: Normal(Talk), id=MAGNAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00025: Normal(Talk, TargetCanMove), id=SHAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00026: Normal(Talk, TargetCanMove), id=SADU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00027: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda418:68053 calling Scene00028: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda418 );
