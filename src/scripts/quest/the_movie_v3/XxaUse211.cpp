// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class XxaUse211 : public Sapphire::ScriptAPI::EventScript
{
public:
  XxaUse211() : Sapphire::ScriptAPI::EventScript( 69418 ){}; 
  ~XxaUse211() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 4 entries
  //SEQ_2, 3 entries
  //SEQ_3, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1008623
  //ACTOR1 = 1008656
  //ACTOR2 = 1008657
  //ACTOR3 = 1008658
  //ACTOR4 = 1006530
  //ACTOR5 = 1008659
  //ACTOR6 = 1008660
  //ACTOR7 = 1008661
  //ACTOR8 = 1008547
  //ACTOR9 = 1008554
  //CUTSCENEN01 = 464
  //CUTSCENEN02 = 465
  //CUTSCENEN03 = 466
  //LOCACTOR0 = 1007097
  //LOCACTOR1 = 1007098
  //LOCACTOR2 = 1007099
  //LOCACTOR3 = 1007766
  //LOCACTOR4 = 1007767
  //LOCPOSACTOR0 = 4680581
  //LOCPOSACTOR1 = 4680587
  //QSTACCEPTCHECK01 = 66889
  //QSTACCEPTCHECK02 = 66890
  //QSTACCEPTCHECK03 = 66891

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1008623 || param2 == 1008623 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1008656 || param2 == 1008656 ) // ACTOR1 = YUGIRI
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1008657 || param2 == 1008657 ) // ACTOR2 = KSASAGI
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=KSASAGI
          break;
        }
        if( param1 == 1008658 || param2 == 1008658 ) // ACTOR3 = KIKYOU
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=KIKYOU
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1006530 || param2 == 1006530 ) // ACTOR4 = SLAFBORN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=SLAFBORN
          }
          break;
        }
        if( param1 == 1008656 || param2 == 1008656 ) // ACTOR1 = YUGIRI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1008657 || param2 == 1008657 ) // ACTOR2 = KSASAGI
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KSASAGI
          break;
        }
        if( param1 == 1008658 || param2 == 1008658 ) // ACTOR3 = KIKYOU
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=KIKYOU
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1008659 || param2 == 1008659 ) // ACTOR5 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1008660 || param2 == 1008660 ) // ACTOR6 = KSASAGI
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=KSASAGI
          break;
        }
        if( param1 == 1008661 || param2 == 1008661 ) // ACTOR7 = KIKYOU
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=KIKYOU
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1008547 || param2 == 1008547 ) // ACTOR8 = MINFILIA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=MINFILIA
          }
          break;
        }
        if( param1 == 1008659 || param2 == 1008659 ) // ACTOR5 = YUGIRI
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1008660 || param2 == 1008660 ) // ACTOR6 = KSASAGI
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=KSASAGI
          break;
        }
        if( param1 == 1008661 || param2 == 1008661 ) // ACTOR7 = KIKYOU
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=KIKYOU
          break;
        }
        break;
      }
      case 255:
      {
        Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MINFILIA
        // +Callback Scene00017: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown
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
    player.sendDebug( "XxaUse211:69418 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown" );
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
    player.sendDebug( "XxaUse211:69418 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00003: Normal(Talk, TargetCanMove), id=KSASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00004: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00007: Normal(Talk, TargetCanMove), id=KSASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00008: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00010: Normal(Talk, TargetCanMove), id=KSASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00011: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00012: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00013: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00014: Normal(Talk, TargetCanMove), id=KSASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00015: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00016: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "XxaUse211:69418 calling Scene00017: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
          player.eventFinish( getId(), 1 );
          player.forceZoneing();
        }
      }
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( XxaUse211 );
