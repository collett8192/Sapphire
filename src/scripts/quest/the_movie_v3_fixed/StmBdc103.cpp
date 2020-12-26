// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdc103 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdc103() : Sapphire::ScriptAPI::EventScript( 68560 ){}; 
  ~StmBdc103() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 5 entries
  //SEQ_2, 6 entries
  //SEQ_3, 1 entries
  //SEQ_4, 9 entries
  //SEQ_5, 12 entries
  //SEQ_255, 11 entries

  //ACTOR0 = 1024738
  //ACTOR1 = 1024737
  //ACTOR10 = 1024825
  //ACTOR11 = 1024826
  //ACTOR12 = 1024827
  //ACTOR13 = 1024828
  //ACTOR14 = 1024829
  //ACTOR15 = 1019898
  //ACTOR16 = 1021505
  //ACTOR17 = 1019167
  //ACTOR18 = 1019169
  //ACTOR19 = 1019168
  //ACTOR2 = 1024743
  //ACTOR20 = 1024830
  //ACTOR21 = 1024831
  //ACTOR22 = 1024832
  //ACTOR23 = 1024833
  //ACTOR24 = 1024834
  //ACTOR25 = 1024835
  //ACTOR26 = 1024836
  //ACTOR27 = 1024837
  //ACTOR28 = 1024838
  //ACTOR29 = 1024839
  //ACTOR3 = 1024744
  //ACTOR30 = 1024840
  //ACTOR31 = 1024841
  //ACTOR4 = 1024745
  //ACTOR5 = 1020451
  //ACTOR6 = 1024821
  //ACTOR7 = 1024822
  //ACTOR8 = 1024823
  //ACTOR9 = 1024824
  //EOBJECT0 = 2009228
  //EOBJECT1 = 2009229
  //EOBJECT2 = 2009238
  //EVENTACTION0 = 1
  //LOCEQUIP01 = 27
  //NCUTEVENTSTMBDC10301 = 1676
  //NCUTEVENTSTMBDC10302 = 1677
  //NCUTEVENTSTMBDC10303 = 1678
  //POPRANGE0 = 7182479
  //POPRANGE1 = 7182520
  //QUESTBATTLE0 = 181
  //TERRITORYTYPE0 = 757
  //TERRITORYTYPE1 = 613

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1024738 || param2 == 1024738 ) // ACTOR0 = YUGIRI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024737 || param2 == 1024737 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1024743 || param2 == 1024743 ) // ACTOR2 = SOROBAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=SOROBAN
          }
          break;
        }
        if( param1 == 1024744 || param2 == 1024744 ) // ACTOR3 = YUGIRI
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024745 || param2 == 1024745 ) // ACTOR4 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020451 || param2 == 1020451 ) // ACTOR5 = ALISAIE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1024821 || param2 == 1024821 ) // ACTOR6 = TATARU
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1024822 || param2 == 1024822 ) // ACTOR7 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1024823 || param2 == 1024823 ) // ACTOR8 = YUGIRI
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024824 || param2 == 1024824 ) // ACTOR9 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1024825 || param2 == 1024825 ) // ACTOR10 = SOROBAN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=SOROBAN
          break;
        }
        if( param1 == 2009228 || param2 == 2009228 ) // EOBJECT0 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 2009229 || param2 == 2009229 ) // EOBJECT1 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00016( player ); // Scene00016: Normal(CutScene, FadeIn, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1024826 || param2 == 1024826 ) // ACTOR11 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1024827 || param2 == 1024827 ) // ACTOR12 = YUGIRI
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024828 || param2 == 1024828 ) // ACTOR13 = GOSETSU
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1024829 || param2 == 1024829 ) // ACTOR14 = YOTSUYU
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YOTSUYU
          break;
        }
        if( param1 == 1019898 || param2 == 1019898 ) // ACTOR15 = TANSUI
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR16 = RASHO
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=RASHO
          break;
        }
        if( param1 == 1019167 || param2 == 1019167 ) // ACTOR17 = HIUN
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=HIUN
          break;
        }
        if( param1 == 1019169 || param2 == 1019169 ) // ACTOR18 = SHIHOJI
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=SHIHOJI
          break;
        }
        if( param1 == 1019168 || param2 == 1019168 ) // ACTOR19 = YUSUI
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=YUSUI
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1024830 || param2 == 1024830 ) // ACTOR20 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=ALISAIE
          }
          break;
        }
        if( param1 == 1024831 || param2 == 1024831 ) // ACTOR21 = YUGIRI
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024832 || param2 == 1024832 ) // ACTOR22 = GOSETSU
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1024833 || param2 == 1024833 ) // ACTOR23 = YOTSUYU
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=YOTSUYU
          break;
        }
        if( param1 == 1024834 || param2 == 1024834 ) // ACTOR24 = SOROBAN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=SOROBAN
          break;
        }
        if( param1 == 1024835 || param2 == 1024835 ) // ACTOR25 = ALPHINAUD
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1019898 || param2 == 1019898 ) // ACTOR15 = TANSUI
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR16 = RASHO
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=RASHO
          break;
        }
        if( param1 == 1019167 || param2 == 1019167 ) // ACTOR17 = HIUN
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=HIUN
          break;
        }
        if( param1 == 1019169 || param2 == 1019169 ) // ACTOR18 = SHIHOJI
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=SHIHOJI
          break;
        }
        if( param1 == 1019168 || param2 == 1019168 ) // ACTOR19 = YUSUI
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=YUSUI
          break;
        }
        if( param1 == 2009238 || param2 == 2009238 ) // EOBJECT2 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1024836 || param2 == 1024836 ) // ACTOR26 = SOROBAN
        {
          Scene00039( player ); // Scene00039: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SOROBAN
          break;
        }
        if( param1 == 1024837 || param2 == 1024837 ) // ACTOR27 = YUGIRI
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024838 || param2 == 1024838 ) // ACTOR28 = ALPHINAUD
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024839 || param2 == 1024839 ) // ACTOR29 = ALISAIE
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1024840 || param2 == 1024840 ) // ACTOR30 = GOSETSU
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1024841 || param2 == 1024841 ) // ACTOR31 = YOTSUYU
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=YOTSUYU
          break;
        }
        if( param1 == 1019898 || param2 == 1019898 ) // ACTOR15 = TANSUI
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR16 = RASHO
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=RASHO
          break;
        }
        if( param1 == 1019167 || param2 == 1019167 ) // ACTOR17 = HIUN
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=HIUN
          break;
        }
        if( param1 == 1019169 || param2 == 1019169 ) // ACTOR18 = SHIHOJI
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=SHIHOJI
          break;
        }
        if( param1 == 1019168 || param2 == 1019168 ) // ACTOR19 = YUSUI
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=YUSUI
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
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdc103:68560 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00007: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00008: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00016( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00011: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00016: Normal(CutScene, FadeIn, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 613, 460, 30.57, 747.71, -2.45, false );
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00018: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00019: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00020: Normal(Talk, TargetCanMove), id=YOTSUYU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00021: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00022: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00023: Normal(Talk, TargetCanMove), id=HIUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00024: Normal(Talk, TargetCanMove), id=SHIHOJI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00025: Normal(Talk, TargetCanMove), id=YUSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00026: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 613, -788.3, 11.304, -287.27, 0, false );
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00027: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00028: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00029: Normal(Talk, TargetCanMove), id=YOTSUYU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00030: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00032: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00033: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00034: Normal(Talk, TargetCanMove), id=HIUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00035: Normal(Talk, TargetCanMove), id=SHIHOJI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00036: Normal(Talk, TargetCanMove), id=YUSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00038: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00039: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SOROBAN" );
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
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00040: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00041: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00042: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00043: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00044: Normal(Talk, TargetCanMove), id=YOTSUYU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00045: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00046: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00047: Normal(Talk, TargetCanMove), id=HIUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00048: Normal(Talk, TargetCanMove), id=SHIHOJI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "StmBdc103:68560 calling Scene00049: Normal(Talk, TargetCanMove), id=YUSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdc103 );
