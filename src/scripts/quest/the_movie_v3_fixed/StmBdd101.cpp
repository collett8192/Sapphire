// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdd101 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdd101() : Sapphire::ScriptAPI::EventScript( 68606 ){}; 
  ~StmBdd101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1025023
  //ACTOR1 = 1025552
  //ACTOR2 = 1025553
  //ACTOR3 = 1025554
  //ACTOR4 = 1020622
  //ACTOR5 = 1020214
  //ACTOR6 = 1024974
  //ACTOR7 = 1025555
  //ACTOR8 = 1025556
  //ACTOR9 = 1025558
  //BINDACTOR01 = 7021290
  //BINDACTOR02 = 7021294
  //BINDACTOR03 = 7226659
  //BINDACTOR04 = 7350605
  //BINDACTOR05 = 7350606
  //BINDACTOR06 = 7350619
  //BINDACTOR07 = 7182300
  //LOCACTION01 = 624
  //LOCACTION02 = 4312
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019541
  //LOCACTOR03 = 1019096
  //LOCACTOR04 = 1019544
  //LOCBASE01 = 4309
  //LOCBASE02 = 812
  //LOCBGM01 = 458
  //LOCBGM02 = 465
  //NCUTEVENTSTMBDD10101 = 1693
  //POPRANGE0 = 7226900
  //TERRITORYTYPE0 = 744

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( param1 == 1025552 || param2 == 1025552 ) // ACTOR1 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HIEN
            // +Callback Scene00003: Normal(CutScene, AutoFadeIn), id=unknown
            // +Callback Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1025553 || param2 == 1025553 ) // ACTOR2 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025554 || param2 == 1025554 ) // ACTOR3 = ALISAIE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR4 = HANCOCK
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1020214 || param2 == 1020214 ) // ACTOR5 = TATARU
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1024974 || param2 == 1024974 ) // ACTOR6 = KIENKANGATEKEEPER03028
        {
          Scene00009( player ); // Scene00009: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=KIENKANGATEKEEPER03028
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1025555 || param2 == 1025555 ) // ACTOR7 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
          // +Callback Scene00011: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025556 || param2 == 1025556 ) // ACTOR8 = ALISAIE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025552 || param2 == 1025552 ) // ACTOR1 = HIEN
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1025558 || param2 == 1025558 ) // ACTOR9 = YUGIRI
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020214 || param2 == 1020214 ) // ACTOR5 = TATARU
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=TATARU
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdd101:68606 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00002: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00003: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00007: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00008: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00009: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=KIENKANGATEKEEPER03028" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 744 );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00011: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00013: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdd101:68606 calling Scene00015: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdd101 );
