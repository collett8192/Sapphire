// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdd103 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdd103() : Sapphire::ScriptAPI::EventScript( 68608 ){}; 
  ~StmBdd103() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 9 entries
  //SEQ_2, 4 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1025095
  //ACTOR1 = 1025094
  //ACTOR10 = 1025101
  //ACTOR11 = 1025102
  //ACTOR12 = 1024999
  //ACTOR13 = 1024998
  //ACTOR14 = 1025009
  //ACTOR15 = 1024974
  //ACTOR16 = 1025545
  //ACTOR2 = 1025096
  //ACTOR3 = 1025097
  //ACTOR4 = 1025098
  //ACTOR5 = 1025099
  //ACTOR6 = 1025100
  //ACTOR7 = 1025104
  //ACTOR8 = 1025103
  //ACTOR9 = 1025105
  //BINDACTOR01 = 7235772
  //BINDACTOR02 = 7235774
  //LOCACTION01 = 4312
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019541
  //LOCACTOR03 = 1019544
  //LOCBGM01 = 459
  //NCUTEVENTSTMBDD10301 = 1695
  //NCUTEVENTSTMBDD10302 = 1696
  //NCUTEVENTSTMBDD10303 = 1697
  //NCUTEVENTSTMBDD10304 = 1698
  //NCUTEVENTSTMBDD10305 = 1699
  //POPRANGE0 = 7244810
  //POPRANGE1 = 7226900
  //TERRITORYTYPE0 = 744

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1025095 || param2 == 1025095 ) // ACTOR0 = HIEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1025094 || param2 == 1025094 ) // ACTOR1 = YUGIRI
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1025096 || param2 == 1025096 ) // ACTOR2 = YOTSUYU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YOTSUYU
          break;
        }
        if( param1 == 1025097 || param2 == 1025097 ) // ACTOR3 = ISSE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1025098 || param2 == 1025098 ) // ACTOR4 = AZAMI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=AZAMI
          break;
        }
        if( param1 == 1025099 || param2 == 1025099 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025100 || param2 == 1025100 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1025104 || param2 == 1025104 ) // ACTOR7 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=HIEN
            // +Callback Scene00009: Normal(CutScene, AutoFadeIn), id=unknown
            // +Callback Scene00010: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=HIEN
          }
          break;
        }
        if( param1 == 1025103 || param2 == 1025103 ) // ACTOR8 = YUGIRI
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1025105 || param2 == 1025105 ) // ACTOR9 = YOTSUYU
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YOTSUYU
          break;
        }
        if( param1 == 1025101 || param2 == 1025101 ) // ACTOR10 = ALPHINAUD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025102 || param2 == 1025102 ) // ACTOR11 = ALISAIE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025097 || param2 == 1025097 ) // ACTOR3 = ISSE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1025098 || param2 == 1025098 ) // ACTOR4 = AZAMI
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=AZAMI
          break;
        }
        if( param1 == 1025099 || param2 == 1025099 ) // ACTOR5 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025100 || param2 == 1025100 ) // ACTOR6 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1024999 || param2 == 1024999 ) // ACTOR12 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=HIEN
            // +Callback Scene00020: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1024998 || param2 == 1024998 ) // ACTOR13 = ALPHINAUD
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025009 || param2 == 1025009 ) // ACTOR14 = ALISAIE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1024974 || param2 == 1024974 ) // ACTOR15 = KIENKANGATEKEEPER03028
        {
          Scene00023( player ); // Scene00023: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=KIENKANGATEKEEPER03028
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1024999 || param2 == 1024999 ) // ACTOR12 = HIEN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1024998 || param2 == 1024998 ) // ACTOR13 = ALPHINAUD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025009 || param2 == 1025009 ) // ACTOR14 = ALISAIE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025545 || param2 == 1025545 ) // ACTOR16 = YUGIRI
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024974 || param2 == 1024974 ) // ACTOR15 = KIENKANGATEKEEPER03028
        {
          Scene00028( player ); // Scene00028: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=KIENKANGATEKEEPER03028
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
    player.sendDebug( "StmBdd103:68608 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdd103:68608 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00002: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00003: Normal(Talk, TargetCanMove), id=YOTSUYU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00004: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00005: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00008: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00009: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00010: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00012: Normal(Talk, TargetCanMove), id=YOTSUYU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00015: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00016: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00019: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00020: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00023: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=KIENKANGATEKEEPER03028" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 744 );
      }
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN" );
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
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00026: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00027: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBdd103:68608 calling Scene00028: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=KIENKANGATEKEEPER03028" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 744 );
      }
    };
    player.playScene( getId(), 28, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdd103 );
