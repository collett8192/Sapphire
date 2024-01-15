// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda506 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda506() : Sapphire::ScriptAPI::QuestScript( 68060 ){}; 
  ~StmBda506() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 4 entries
  //SEQ_2, 3 entries
  //SEQ_3, 5 entries
  //SEQ_4, 5 entries
  //SEQ_5, 1 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1020524
  //ACTOR1 = 1019975
  //ACTOR10 = 1021695
  //ACTOR11 = 1021696
  //ACTOR12 = 5010000
  //ACTOR13 = 1020248
  //ACTOR14 = 1020249
  //ACTOR15 = 1020250
  //ACTOR16 = 1020251
  //ACTOR17 = 1020252
  //ACTOR18 = 1020253
  //ACTOR19 = 1019976
  //ACTOR2 = 1020241
  //ACTOR3 = 1020242
  //ACTOR4 = 1020243
  //ACTOR5 = 1020244
  //ACTOR6 = 1020245
  //ACTOR7 = 1020246
  //ACTOR8 = 1020247
  //ACTOR9 = 1021694
  //BINDALPHINAUD001 = 6851108
  //BINDGOSETSU001 = 6870450
  //BINDGOSETSU002 = 6851118
  //BINDHIEN001 = 6870448
  //BINDYUGIRI001 = 6870449
  //BINDYUGIRI002 = 6851117
  //EOBJECT0 = 2007932
  //EOBJECT1 = 2007893
  //EVENTACTION0 = 10
  //INSTANCEDUNGEON0 = 54
  //NCUTEVENT05040 = 1452
  //NCUTEVENT05050 = 1453
  //NCUTEVENT05060 = 1454
  //NCUTEVENT05070 = 1455
  //NCUTEVENT05080 = 1456
  //NCUTEVENT05090 = 1457
  //POPRANGE0 = 6851133
  //POPRANGE1 = 6851134
  //SCREENIMAGE0 = 494
  //TERRITORYTYPE0 = 614

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
        if( param1 == 1020524 ) // ACTOR0 = HIEN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=HIEN
          }
          break;
        }
        if( param1 == 1019975 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2007932 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1020241 ) // ACTOR2 = HIEN
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020242 ) // ACTOR3 = YUGIRI
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020243 ) // ACTOR4 = GOSETSU
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020244 ) // ACTOR5 = HIEN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1020245 ) // ACTOR6 = YUGIRI
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020246 ) // ACTOR7 = GOSETSU
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020247 ) // ACTOR8 = AOKORA02524
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove, ENpcBind), id=AOKORA02524
          }
          break;
        }
        if( param1 == 2007893 ) // EOBJECT1 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Empty(None), id=unknown
          break;
        }
        if( param1 == 1021694 ) // ACTOR9 = HIEN
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021695 ) // ACTOR10 = YUGIRI
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1021696 ) // ACTOR11 = GOSETSU
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020247 ) // ACTOR8 = AOKORA02524
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=AOKORA02524
          break;
        }
        if( param1 == 1021694 ) // ACTOR9 = HIEN
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021695 ) // ACTOR10 = YUGIRI
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1021696 ) // ACTOR11 = GOSETSU
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 2007893 ) // EOBJECT1 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00021( quest, player ); // Scene00021: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020248 ) // ACTOR13 = ALPHINAUD
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020249 ) // ACTOR14 = ALISAIE
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020250 ) // ACTOR15 = LYSE
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020251 ) // ACTOR16 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1020252 ) // ACTOR17 = YUGIRI
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020253 ) // ACTOR18 = unknown
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1019976 ) // ACTOR19 = SOROBAN
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=SOROBAN
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
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 3 );
    }
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
    quest.setSeq( 5 );
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00004: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00005: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00007: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00011: Normal(Talk, TargetCanMove, ENpcBind), id=AOKORA02524" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00012: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00013: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00015: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00016: Normal(Talk, TargetCanMove), id=AOKORA02524" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00017: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00018: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00019: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00020: Empty(None), id=unknown" );
    checkProgressSeq4( quest, player );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_5: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00021: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00024: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00025: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00026: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00027: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda506:68060 calling Scene00028: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda506 );
