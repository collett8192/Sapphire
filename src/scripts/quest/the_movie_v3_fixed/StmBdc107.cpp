// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdc107 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdc107() : Sapphire::ScriptAPI::EventScript( 68564 ){}; 
  ~StmBdc107() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 5 entries
  //SEQ_255, 10 entries

  //ACTOR0 = 1024989
  //ACTOR1 = 1024990
  //ACTOR10 = 1024997
  //ACTOR11 = 1024998
  //ACTOR12 = 1025000
  //ACTOR13 = 1025001
  //ACTOR2 = 1024991
  //ACTOR3 = 1025026
  //ACTOR4 = 1024971
  //ACTOR5 = 1024994
  //ACTOR6 = 1024995
  //ACTOR7 = 1024996
  //ACTOR8 = 1024999
  //ACTOR9 = 1024974
  //LEVELCHOUNINALISAIE = 7226672
  //LEVELNAMAIALISAIE = 7226603
  //LEVELNAMAIYUUGIRI = 7226602
  //LEVELYAKATAALISAIE = 7227010
  //LEVELYAKATAALPH = 7227009
  //LEVELYAKATAHAKU = 7227012
  //LEVELYAKATASAMURAI = 7227013
  //LOCENPCALISAIE01 = 1019541
  //LOCQUESTCHECK = 68510
  //NCUT01 = 1685
  //POPRANGE0 = 7226900
  //POPRANGE1 = 7226901
  //TERRITORYTYPE0 = 744

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1024989 || param2 == 1024989 ) // ACTOR0 = ASAHI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ASAHI
          break;
        }
        if( param1 == 1024990 || param2 == 1024990 ) // ACTOR1 = YUGIRI
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024991 || param2 == 1024991 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1025026 || param2 == 1025026 ) // ACTOR3 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1024971 || param2 == 1024971 ) // ACTOR4 = ALISAIE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1024994 || param2 == 1024994 ) // ACTOR5 = ASAHI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ASAHI
          break;
        }
        if( param1 == 1024995 || param2 == 1024995 ) // ACTOR6 = MAXIMA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=MAXIMA
          break;
        }
        if( param1 == 1024996 || param2 == 1024996 ) // ACTOR7 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1024999 || param2 == 1024999 ) // ACTOR8 = HIEN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, CutScene, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, AutoFadeIn), id=HIEN
          break;
        }
        if( param1 == 1024974 || param2 == 1024974 ) // ACTOR9 = KIENKANGATEKEEPER03028
        {
          Scene00010( player ); // Scene00010: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=KIENKANGATEKEEPER03028
          break;
        }
        if( param1 == 1024997 || param2 == 1024997 ) // ACTOR10 = ALISAIE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1024998 || param2 == 1024998 ) // ACTOR11 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025000 || param2 == 1025000 ) // ACTOR12 = HAKURO
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1025026 || param2 == 1025026 ) // ACTOR3 = YUGIRI
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024994 || param2 == 1024994 ) // ACTOR5 = ASAHI
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ASAHI
          break;
        }
        if( param1 == 1024995 || param2 == 1024995 ) // ACTOR6 = MAXIMA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MAXIMA
          break;
        }
        if( param1 == 1024996 || param2 == 1024996 ) // ACTOR7 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025001 || param2 == 1025001 ) // ACTOR13 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
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
    player.sendDebug( "StmBdc107:68564 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdc107:68564 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ASAHI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00006: Normal(Talk, TargetCanMove), id=ASAHI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00007: Normal(Talk, TargetCanMove), id=MAXIMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00009: Normal(Talk, CutScene, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, AutoFadeIn), id=HIEN" );
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
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00010: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=KIENKANGATEKEEPER03028" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 744 );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00013: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00015: Normal(Talk, TargetCanMove), id=ASAHI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00016: Normal(Talk, TargetCanMove), id=MAXIMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdc107:68564 calling Scene00018: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBdc107 );
