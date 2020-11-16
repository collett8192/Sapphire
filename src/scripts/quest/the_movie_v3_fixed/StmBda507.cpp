// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda507 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda507() : Sapphire::ScriptAPI::EventScript( 68061 ){}; 
  ~StmBda507() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 9 entries
  //SEQ_2, 3 entries
  //SEQ_3, 12 entries
  //SEQ_4, 13 entries
  //SEQ_255, 12 entries

  //ACTOR0 = 1020248
  //ACTOR1 = 1020249
  //ACTOR10 = 1020258
  //ACTOR11 = 1020259
  //ACTOR12 = 1020260
  //ACTOR13 = 1020261
  //ACTOR14 = 1020262
  //ACTOR15 = 1019979
  //ACTOR16 = 1020236
  //ACTOR17 = 1021060
  //ACTOR18 = 1021062
  //ACTOR19 = 1021072
  //ACTOR2 = 1020250
  //ACTOR20 = 1021063
  //ACTOR21 = 1020644
  //ACTOR22 = 1020263
  //ACTOR23 = 1020264
  //ACTOR24 = 1020265
  //ACTOR25 = 1020266
  //ACTOR26 = 1020267
  //ACTOR27 = 1020268
  //ACTOR28 = 1020269
  //ACTOR3 = 1020251
  //ACTOR4 = 1020252
  //ACTOR5 = 1020253
  //ACTOR6 = 1019976
  //ACTOR7 = 1020255
  //ACTOR8 = 1020256
  //ACTOR9 = 1020257
  //BINDALISAIE001 = 6851123
  //BINDALISAIE002 = 6851276
  //BINDCIRINA001 = 6851127
  //BINDCIRINA002 = 6851281
  //BINDHIEN001 = 6851125
  //BINDLYSE001 = 6851124
  //BINDLYSE002 = 6851278
  //BINDSOROBAN001 = 6851258
  //BINDSOROBAN002 = 6851283
  //BINDYUGIRI001 = 6851126
  //EOBJECT0 = 2007934
  //EOBJECT1 = 2007935
  //LOCACTOR0 = 1018975
  //LOCACTOR1 = 1018976
  //LOCOBJ01 = 2008992
  //NCUTEVENT05100 = 1458
  //POPRANGE0 = 6851359
  //POPRANGE1 = 7030552
  //POPRANGE2 = 6851373
  //TERRITORYTYPE0 = 682
  //TERRITORYTYPE1 = 614

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020248 || param2 == 1020248 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020249 || param2 == 1020249 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020250 || param2 == 1020250 ) // ACTOR2 = LYSE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020251 || param2 == 1020251 ) // ACTOR3 = HIEN
        {
          Scene00004( player ); // Scene00004: Normal(Talk), id=HIEN
          break;
        }
        if( param1 == 1020252 || param2 == 1020252 ) // ACTOR4 = YUGIRI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020253 || param2 == 1020253 ) // ACTOR5 = CIRINA
        {
          Scene00006( player ); // Scene00006: Normal(Talk), id=CIRINA
          break;
        }
        if( param1 == 1019976 || param2 == 1019976 ) // ACTOR6 = SOROBAN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=SOROBAN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020255 || param2 == 1020255 ) // ACTOR7 = TANSUI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove, Menu, CanCancel), id=TANSUI
          }
          break;
        }
        if( param1 == 1019976 || param2 == 1019976 ) // ACTOR6 = SOROBAN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=SOROBAN
          break;
        }
        if( param1 == 1020256 || param2 == 1020256 ) // ACTOR8 = HIEN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020257 || param2 == 1020257 ) // ACTOR9 = LYSE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020248 || param2 == 1020248 ) // ACTOR0 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020249 || param2 == 1020249 ) // ACTOR1 = ALISAIE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020252 || param2 == 1020252 ) // ACTOR4 = YUGIRI
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020253 || param2 == 1020253 ) // ACTOR5 = CIRINA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 2007934 || param2 == 2007934 ) // EOBJECT0 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00017( player ); // Scene00017: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1020255 || param2 == 1020255 ) // ACTOR7 = TANSUI
        {
          Scene00018( player ); // Scene00018: Normal(Talk, YesNo, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 2007934 || param2 == 2007934 ) // EOBJECT0 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020258 || param2 == 1020258 ) // ACTOR10 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020259 || param2 == 1020259 ) // ACTOR11 = ALISAIE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020260 || param2 == 1020260 ) // ACTOR12 = LYSE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020261 || param2 == 1020261 ) // ACTOR13 = CIRINA
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1020262 || param2 == 1020262 ) // ACTOR14 = SOROBAN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=SOROBAN
          break;
        }
        if( param1 == 1019979 || param2 == 1019979 ) // ACTOR15 = YUGIRI
        {
          Scene00025( player ); // Scene00025: Normal(Talk), id=YUGIRI
          break;
        }
        if( param1 == 1020236 || param2 == 1020236 ) // ACTOR16 = RESISTANCE02492
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=RESISTANCE02492
          break;
        }
        if( param1 == 1021060 || param2 == 1021060 ) // ACTOR17 = HIEN
        {
          Scene00027( player ); // Scene00027: Normal(Talk), id=HIEN
          break;
        }
        if( param1 == 1021062 || param2 == 1021062 ) // ACTOR18 = ISSE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1021072 || param2 == 1021072 ) // ACTOR19 = AZAMI
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=AZAMI
          break;
        }
        if( param1 == 1021063 || param2 == 1021063 ) // ACTOR20 = TSURANUKI
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020644 || param2 == 1020644 ) // ACTOR21 = DOMABOATMAN
        {
          Scene00031( player ); // Scene00031: Normal(Talk, YesNo, TargetCanMove), id=DOMABOATMAN
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020263 || param2 == 1020263 ) // ACTOR22 = RASHO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove, Menu, CanCancel), id=RASHO
          }
          break;
        }
        if( param1 == 1020264 || param2 == 1020264 ) // ACTOR23 = TANSUI
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 2007935 || param2 == 2007935 ) // EOBJECT1 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020258 || param2 == 1020258 ) // ACTOR10 = ALPHINAUD
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020259 || param2 == 1020259 ) // ACTOR11 = ALISAIE
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020260 || param2 == 1020260 ) // ACTOR12 = LYSE
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021060 || param2 == 1021060 ) // ACTOR17 = HIEN
        {
          Scene00038( player ); // Scene00038: Normal(Talk), id=HIEN
          break;
        }
        if( param1 == 1019979 || param2 == 1019979 ) // ACTOR15 = YUGIRI
        {
          Scene00039( player ); // Scene00039: Normal(Talk), id=YUGIRI
          break;
        }
        if( param1 == 1021062 || param2 == 1021062 ) // ACTOR18 = ISSE
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1021072 || param2 == 1021072 ) // ACTOR19 = AZAMI
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=AZAMI
          break;
        }
        if( param1 == 1020236 || param2 == 1020236 ) // ACTOR16 = RESISTANCE02492
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=RESISTANCE02492
          break;
        }
        if( param1 == 1021063 || param2 == 1021063 ) // ACTOR20 = TSURANUKI
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020644 || param2 == 1020644 ) // ACTOR21 = DOMABOATMAN
        {
          Scene00044( player ); // Scene00044: Normal(Talk, YesNo, TargetCanMove), id=DOMABOATMAN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020265 || param2 == 1020265 ) // ACTOR24 = RASHO
        {
          Scene00045( player ); // Scene00045: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RASHO
          break;
        }
        if( param1 == 1020266 || param2 == 1020266 ) // ACTOR25 = TANSUI
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1020267 || param2 == 1020267 ) // ACTOR26 = ALPHINAUD
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020268 || param2 == 1020268 ) // ACTOR27 = ALISAIE
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020269 || param2 == 1020269 ) // ACTOR28 = LYSE
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021060 || param2 == 1021060 ) // ACTOR17 = HIEN
        {
          Scene00050( player ); // Scene00050: Normal(Talk), id=HIEN
          break;
        }
        if( param1 == 1019979 || param2 == 1019979 ) // ACTOR15 = YUGIRI
        {
          Scene00051( player ); // Scene00051: Normal(Talk), id=YUGIRI
          break;
        }
        if( param1 == 1021062 || param2 == 1021062 ) // ACTOR18 = ISSE
        {
          Scene00052( player ); // Scene00052: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1021072 || param2 == 1021072 ) // ACTOR19 = AZAMI
        {
          Scene00053( player ); // Scene00053: Normal(Talk, TargetCanMove), id=AZAMI
          break;
        }
        if( param1 == 1020236 || param2 == 1020236 ) // ACTOR16 = RESISTANCE02492
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=RESISTANCE02492
          break;
        }
        if( param1 == 1021063 || param2 == 1021063 ) // ACTOR20 = TSURANUKI
        {
          Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020644 || param2 == 1020644 ) // ACTOR21 = DOMABOATMAN
        {
          Scene00056( player ); // Scene00056: Normal(Talk, YesNo, TargetCanMove), id=DOMABOATMAN
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda507:68061 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00004: Normal(Talk), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00006: Normal(Talk), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00007: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00008: Normal(Talk, TargetCanMove, Menu, CanCancel), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 682 );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00009: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00010: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00011: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00015: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00017: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00018: Normal(Talk, YesNo, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 682 );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00020: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00022: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00023: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00024: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00025: Normal(Talk), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00026: Normal(Talk, TargetCanMove), id=RESISTANCE02492" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00027: Normal(Talk), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00028: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00029: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00030: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00031: Normal(Talk, YesNo, TargetCanMove), id=DOMABOATMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.exitInstance();
      }
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00032: Normal(Talk, TargetCanMove, Menu, CanCancel), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq4( player );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 628, -173.78, -7, 51.5, 0, true );
      }
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00033: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00034: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00036: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00037: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00038: Normal(Talk), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00039: Normal(Talk), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00040: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00041: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00042: Normal(Talk, TargetCanMove), id=RESISTANCE02492" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00043: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00044: Normal(Talk, YesNo, TargetCanMove), id=DOMABOATMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.exitInstance();
      }
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00045: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RASHO" );
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
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00046: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00048: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00049: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00050: Normal(Talk), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00051: Normal(Talk), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00052: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00053: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00054: Normal(Talk, TargetCanMove), id=RESISTANCE02492" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00055: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "StmBda507:68061 calling Scene00056: Normal(Talk, YesNo, TargetCanMove), id=DOMABOATMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.exitInstance();
      }
    };
    player.playScene( getId(), 56, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda507 );
