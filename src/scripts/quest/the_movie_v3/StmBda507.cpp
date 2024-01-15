// FFXIVTheMovie.ParserV3.12
// param used:
//WARP_SCENE32 = 628|-173.78|-7|51.5|0|true
//PRIVATE_SCENE8 = 682
//PRIVATE_SCENE18 = 682
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda507 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda507() : Sapphire::ScriptAPI::QuestScript( 68061 ){}; 
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

  static constexpr auto EVENT_ON_TALK = 0;
  static constexpr auto EVENT_ON_EMOTE = 1;
  static constexpr auto EVENT_ON_BNPC_KILL = 2;
  static constexpr auto EVENT_ON_WITHIN_RANGE = 3;
  static constexpr auto EVENT_ON_ENTER_TERRITORY = 4;
  static constexpr auto EVENT_ON_EVENT_ITEM = 5;
  static constexpr auto EVENT_ON_EOBJ_HIT = 6;
  static constexpr auto EVENT_ON_SAY = 7;

private:
  void onProgress( World::Quest& quest, Entity::Player& player, uint32_t type, uint64_t param1, uint32_t param2, uint32_t param3 )
  {
    switch( quest.getSeq() )
    {
      case 0:
      {
        if( param1 == 1020248 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020249 ) // ACTOR1 = ALISAIE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020250 ) // ACTOR2 = LYSE
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020251 ) // ACTOR3 = unknown
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1020252 ) // ACTOR4 = YUGIRI
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020253 ) // ACTOR5 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1019976 ) // ACTOR6 = SOROBAN
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=SOROBAN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020255 ) // ACTOR7 = TANSUI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove, Menu, CanCancel), id=TANSUI
          }
          break;
        }
        if( param1 == 1019976 ) // ACTOR6 = SOROBAN
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=SOROBAN
          break;
        }
        if( param1 == 1020256 ) // ACTOR8 = HIEN
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020257 ) // ACTOR9 = LYSE
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020248 ) // ACTOR0 = ALPHINAUD
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020249 ) // ACTOR1 = ALISAIE
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020252 ) // ACTOR4 = YUGIRI
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020253 ) // ACTOR5 = CIRINA
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 2007934 ) // EOBJECT0 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00017( quest, player ); // Scene00017: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1020255 ) // ACTOR7 = TANSUI
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, YesNo, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 2007934 ) // EOBJECT0 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020258 ) // ACTOR10 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00020( quest, player ); // Scene00020: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020259 ) // ACTOR11 = ALISAIE
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020260 ) // ACTOR12 = LYSE
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020261 ) // ACTOR13 = CIRINA
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1020262 ) // ACTOR14 = SOROBAN
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=SOROBAN
          break;
        }
        if( param1 == 1019979 ) // ACTOR15 = YUGIRI
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020236 ) // ACTOR16 = RESISTANCE02492
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=RESISTANCE02492
          break;
        }
        if( param1 == 1021060 ) // ACTOR17 = HIEN
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021062 ) // ACTOR18 = ISSE
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1021072 ) // ACTOR19 = AZAMI
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=AZAMI
          break;
        }
        if( param1 == 1021063 ) // ACTOR20 = TSURANUKI
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020644 ) // ACTOR21 = DOMABOATMAN
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, YesNo, TargetCanMove), id=DOMABOATMAN
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020263 ) // ACTOR22 = RASHO
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove, Menu, CanCancel), id=RASHO
          }
          break;
        }
        if( param1 == 1020264 ) // ACTOR23 = TANSUI
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 2007935 ) // EOBJECT1 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020258 ) // ACTOR10 = ALPHINAUD
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020259 ) // ACTOR11 = ALISAIE
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020260 ) // ACTOR12 = LYSE
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021060 ) // ACTOR17 = HIEN
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1019979 ) // ACTOR15 = YUGIRI
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1021062 ) // ACTOR18 = ISSE
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1021072 ) // ACTOR19 = AZAMI
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=AZAMI
          break;
        }
        if( param1 == 1020236 ) // ACTOR16 = RESISTANCE02492
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=RESISTANCE02492
          break;
        }
        if( param1 == 1021063 ) // ACTOR20 = TSURANUKI
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020644 ) // ACTOR21 = DOMABOATMAN
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, YesNo, TargetCanMove), id=DOMABOATMAN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020265 ) // ACTOR24 = RASHO
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RASHO
          break;
        }
        if( param1 == 1020266 ) // ACTOR25 = TANSUI
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1020267 ) // ACTOR26 = ALPHINAUD
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020268 ) // ACTOR27 = ALISAIE
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020269 ) // ACTOR28 = LYSE
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021060 ) // ACTOR17 = HIEN
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1019979 ) // ACTOR15 = YUGIRI
        {
          Scene00051( quest, player ); // Scene00051: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1021062 ) // ACTOR18 = ISSE
        {
          Scene00052( quest, player ); // Scene00052: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1021072 ) // ACTOR19 = AZAMI
        {
          Scene00053( quest, player ); // Scene00053: Normal(Talk, TargetCanMove), id=AZAMI
          break;
        }
        if( param1 == 1020236 ) // ACTOR16 = RESISTANCE02492
        {
          Scene00054( quest, player ); // Scene00054: Normal(Talk, TargetCanMove), id=RESISTANCE02492
          break;
        }
        if( param1 == 1021063 ) // ACTOR20 = TSURANUKI
        {
          Scene00055( quest, player ); // Scene00055: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020644 ) // ACTOR21 = DOMABOATMAN
        {
          Scene00056( quest, player ); // Scene00056: Normal(Talk, YesNo, TargetCanMove), id=DOMABOATMAN
          break;
        }
        break;
      }
      default:
      {
        playerMgr().sendUrgent( player, "Sequence {} not defined.", quest.getSeq() );
        break;
      }
    }
  }

public:
  void onTalk( World::Quest& quest, Entity::Player& player, uint64_t actorId ) override
  {
    onProgress( quest, player, EVENT_ON_TALK, actorId, 0, 0 );
  }

  void onEmote( World::Quest& quest, uint64_t actorId, uint32_t emoteId, Sapphire::Entity::Player& player ) override
  {
    playerMgr().sendDebug( player, "emote: {}", emoteId );
    onProgress( quest, player, EVENT_ON_EMOTE, actorId, 0, emoteId );
  }

  void onBNpcKill( World::Quest& quest, Entity::BNpc& bnpc, Entity::Player& player ) override
  {
    onProgress( quest, player, EVENT_ON_BNPC_KILL, static_cast< uint64_t >( bnpc.getBNpcNameId() ), bnpc.getLayoutId(), 0 );
  }

  void onWithinRange( World::Quest& quest, Sapphire::Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( quest, player, EVENT_ON_WITHIN_RANGE, static_cast< uint64_t >( param1 ), 0, 0 );
  }

  void onEnterTerritory( World::Quest& quest, Sapphire::Entity::Player& player, uint16_t param1, uint16_t param2 ) override
  {
    onProgress( quest, player, EVENT_ON_ENTER_TERRITORY, static_cast< uint64_t >( param1 ), static_cast< uint32_t >( param2 ), 0 );
  }
  void onEventItem( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId ) override
  {
    onProgress( quest, player, EVENT_ON_EVENT_ITEM, actorId, 0, 0 );
  }
  void onEObjHit( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId, uint32_t actionId ) override
  {
    onProgress( quest, player, EVENT_ON_EOBJ_HIT, actorId, actionId, 0 );
  }
  void onSay( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId, uint32_t sayId ) override
  {
    onProgress( quest, player, EVENT_ON_SAY, actorId, sayId, 0 );
  }

private:
  void checkProgressSeq0( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 1 );
  }
  void checkProgressSeq1( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 2 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 3 );
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 4 );
    }
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, HIDE_HOTBAR, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00004: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00006: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00007: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00008: Normal(Talk, TargetCanMove, Menu, CanCancel), id=TANSUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 1, true );
        eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
        checkProgressSeq1( quest, player );
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 682 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00009: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00010: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00011: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00015: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00016: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00017: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00018: Normal(Talk, YesNo, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 682 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00019: Empty(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00020: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00022: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00023: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00024: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00026: Normal(Talk, TargetCanMove), id=RESISTANCE02492" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00027: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00028: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00029: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00030: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00031: Normal(Talk, YesNo, TargetCanMove), id=DOMABOATMAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
      }
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR22, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00032: Normal(Talk, TargetCanMove, Menu, CanCancel), id=RASHO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 1, true );
        eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
        checkProgressSeq4( quest, player );
        eventMgr().eventFinish( player, result.eventId, 1 );
        //warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 628 )->getGuId(), { -173.78, -7, 51.5 }, 0 );
        //warpMgr not supporting show zone text, fallback to old api
        player.forceZoneing( 628, -173.78f, -7.0f, 51.5f, 0.0f, true );
      }
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00033: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00034: Empty(None), id=unknown" );
    checkProgressSeq4( quest, player );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, HIDE_HOTBAR, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00036: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00037: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00038: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, HIDE_HOTBAR, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00039: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, HIDE_HOTBAR, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00040: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, HIDE_HOTBAR, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00041: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, HIDE_HOTBAR, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00042: Normal(Talk, TargetCanMove), id=RESISTANCE02492" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00043: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, HIDE_HOTBAR, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00044: Normal(Talk, YesNo, TargetCanMove), id=DOMABOATMAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
      }
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00045: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR25, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00046: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, HIDE_HOTBAR, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR26, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, HIDE_HOTBAR, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR27, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00048: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, HIDE_HOTBAR, callback );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR28, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00049: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 49, HIDE_HOTBAR, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00050: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 50, HIDE_HOTBAR, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00051: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 51, HIDE_HOTBAR, callback );
  }

  void Scene00052( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00052: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 52, HIDE_HOTBAR, callback );
  }

  void Scene00053( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00053: Normal(Talk, TargetCanMove), id=AZAMI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 53, HIDE_HOTBAR, callback );
  }

  void Scene00054( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00054: Normal(Talk, TargetCanMove), id=RESISTANCE02492" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 54, HIDE_HOTBAR, callback );
  }

  void Scene00055( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00055: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 55, HIDE_HOTBAR, callback );
  }

  void Scene00056( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda507:68061 calling Scene00056: Normal(Talk, YesNo, TargetCanMove), id=DOMABOATMAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
      }
    };
    eventMgr().playQuestScene( player, getId(), 56, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda507 );
