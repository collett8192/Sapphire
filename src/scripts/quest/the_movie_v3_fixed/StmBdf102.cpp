// FFXIVTheMovie.ParserV3.2
// id table disabled
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdf102 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdf102() : Sapphire::ScriptAPI::EventScript( 68716 ){}; 
  ~StmBdf102() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_255, 13 entries

  //ACTIONTIMELINEFACIALSALUTE = 624
  //ACTOR0 = 1026781
  //ACTOR1 = 1026782
  //ACTOR10 = 1026791
  //ACTOR11 = 1026792
  //ACTOR12 = 1026793
  //ACTOR13 = 1024974
  //ACTOR14 = 1019935
  //ACTOR15 = 1020539
  //ACTOR2 = 1024065
  //ACTOR3 = 1026783
  //ACTOR4 = 1026784
  //ACTOR5 = 1026785
  //ACTOR6 = 1026786
  //ACTOR7 = 1026788
  //ACTOR8 = 1026789
  //ACTOR9 = 1026790
  //BGMEVENTSTORMBLOOD02 = 458
  //BGMEVENTSTORMBLOOD05 = 485
  //BINDACTOR0 = 7732630
  //BINDACTOR1 = 7732672
  //BINDACTOR2 = 7732673
  //BINDACTOR3 = 7732674
  //BINDACTOR4 = 7732675
  //BINDACTOR5 = 7732676
  //BINDACTOR6 = 7732677
  //BINDACTOR7 = 7732678
  //CUTSCENE0 = 1880
  //LCUTACTOR0 = 1019541
  //POPRANGE0 = 7226900
  //TERRITORYTYPE0 = 744

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1026781 || param2 == 1026781 ) // ACTOR0 = ALISAIE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1026782 || param2 == 1026782 ) // ACTOR1 = KRILE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1024065 || param2 == 1024065 ) // ACTOR2 = RESISTANCEGATEGUARD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD
            // +Callback Scene00004: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1026783 || param2 == 1026783 ) // ACTOR3 = ALISAIE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1026783 || param2 == 1026783 ) // ACTOR3 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1024065 || param2 == 1024065 ) // ACTOR2 = RESISTANCEGATEGUARD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1026784 || param2 == 1026784 ) // ACTOR4 = HIEN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1026785 || param2 == 1026785 ) // ACTOR5 = YUGIRI
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1026786 || param2 == 1026786 ) // ACTOR6 = HAKUROU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HAKUROU
          break;
        }
        if( param1 == 1026788 || param2 == 1026788 ) // ACTOR7 = TANSUI
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1026789 || param2 == 1026789 ) // ACTOR8 = CIRINA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1026790 || param2 == 1026790 ) // ACTOR9 = AOKORAHERALD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=AOKORAHERALD
          break;
        }
        if( param1 == 1026791 || param2 == 1026791 ) // ACTOR10 = NAGUSAHERALD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=NAGUSAHERALD
          break;
        }
        if( param1 == 1026792 || param2 == 1026792 ) // ACTOR11 = DALMASCAHERALD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=DALMASCAHERALD
          break;
        }
        if( param1 == 1026793 || param2 == 1026793 ) // ACTOR12 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1024974 || param2 == 1024974 ) // ACTOR13 = KIENKANGATEKEEPER03028
        {
          Scene00017( player ); // Scene00017: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028
          break;
        }
        if( param1 == 1019935 || param2 == 1019935 ) // ACTOR14 = TANSUI
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR15 = CIRINA
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1024065 || param2 == 1024065 ) // ACTOR2 = RESISTANCEGATEGUARD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD
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
    player.sendDebug( "StmBdf102:68716 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdf102:68716 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00002: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00003: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00004( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00007: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00008: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HIEN" );
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
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00010: Normal(Talk, TargetCanMove), id=HAKUROU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00011: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00012: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00013: Normal(Talk, TargetCanMove), id=AOKORAHERALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00014: Normal(Talk, TargetCanMove), id=NAGUSAHERALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00015: Normal(Talk, TargetCanMove), id=DALMASCAHERALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00017: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER03028" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 744 );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00018: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00019: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBdf102:68716 calling Scene00020: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdf102 );
