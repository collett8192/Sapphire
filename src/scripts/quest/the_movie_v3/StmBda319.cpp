// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda319 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda319() : Sapphire::ScriptAPI::QuestScript( 68031 ){}; 
  ~StmBda319() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 1 entries
  //SEQ_3, 3 entries
  //SEQ_4, 3 entries
  //SEQ_5, 7 entries
  //SEQ_6, 9 entries
  //SEQ_7, 4 entries
  //SEQ_8, 3 entries
  //SEQ_255, 3 entries

  //ACTIONTIMELINEEVENTBASEWOUNDED = 4204
  //ACTIONTIMELINEEVENTEMPIRIALSALUTE = 587
  //ACTIONTIMELINEEVENTFRIGHTENED = 4215
  //ACTIONTIMELINEEVENTLOOKKNEEL = 4323
  //ACTIONTIMELINEEVENTLOOKSTAND = 4322
  //ACTOR0 = 1020020
  //ACTOR1 = 1020021
  //ACTOR10 = 1020212
  //ACTOR11 = 1020213
  //ACTOR12 = 1020025
  //ACTOR13 = 1020026
  //ACTOR14 = 1020027
  //ACTOR15 = 1019966
  //ACTOR16 = 1019967
  //ACTOR17 = 1020283
  //ACTOR2 = 1020022
  //ACTOR3 = 1020023
  //ACTOR4 = 1020024
  //ACTOR5 = 1020210
  //ACTOR6 = 1020211
  //ACTOR7 = 1020282
  //ACTOR8 = 1019892
  //ACTOR9 = 1019980
  //BINDACTOR0 = 6782246
  //BINDACTOR1 = 6941236
  //EOBJECT0 = 2007838
  //EOBJECT1 = 2007835
  //EOBJECT2 = 2007915
  //EVENTACTION0 = 11
  //EVENTACTION1 = 50
  //ITEM0 = 2002068
  //LOCACTOR0 = 1019553
  //LOCACTOR1 = 1019552
  //LOCACTOR2 = 1019547
  //LOCACTOR3 = 1018527
  //LOCACTOR4 = 1018528
  //LOCACTOR5 = 1018533
  //LOCACTOR6 = 1018977
  //LOCACTOR7 = 1019554
  //LOCMAKERPC = 6981179
  //NCUT01 = 1426
  //SNIPE0 = 8
  //SNIPE1 = 9
  //SNIPE2 = 10

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
        if( param1 == 1020020 ) // ACTOR0 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1020021 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2007838 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1020022 ) // ACTOR2 = YUGIRI
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020023 ) // ACTOR3 = LYSE
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 2:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00007( quest, player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      case 3:
      {
        if( param1 == 1020024 ) // ACTOR4 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1020210 ) // ACTOR5 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020211 ) // ACTOR6 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      case 4:
      {
        if( param1 == 1020282 ) // ACTOR7 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove, SystemTalk), id=YUGIRI
            // +Callback Scene00012: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00013: Normal(Talk, FadeIn, ENpcBind), id=unknown
          }
          break;
        }
        if( param1 == 1020210 ) // ACTOR5 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020211 ) // ACTOR6 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack ?
      case 5:
      {
        if( param1 == 2007835 ) // EOBJECT1 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00017( quest, player ); // Scene00017: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00018: Normal(FadeIn, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1020210 ) // ACTOR5 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020211 ) // ACTOR6 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019892 ) // ACTOR8 = unknown
        {
          Scene00021( quest, player ); // Scene00021: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019980 ) // ACTOR9 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020212 ) // ACTOR10 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020213 ) // ACTOR11 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 6 event item ITEM0 = UI8BH max stack ?
      case 6:
      {
        if( param1 == 1020025 ) // ACTOR12 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1020210 ) // ACTOR5 = unknown
        {
          Scene00026( quest, player ); // Scene00026: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020211 ) // ACTOR6 = unknown
        {
          Scene00027( quest, player ); // Scene00027: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020026 ) // ACTOR13 = SOLDIERA02495
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=SOLDIERA02495
          break;
        }
        if( param1 == 1020027 ) // ACTOR14 = SOLDIERB02495
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=SOLDIERB02495
          break;
        }
        if( param1 == 1019892 ) // ACTOR8 = unknown
        {
          Scene00030( quest, player ); // Scene00030: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019980 ) // ACTOR9 = unknown
        {
          Scene00031( quest, player ); // Scene00031: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020212 ) // ACTOR10 = unknown
        {
          Scene00032( quest, player ); // Scene00032: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020213 ) // ACTOR11 = unknown
        {
          Scene00033( quest, player ); // Scene00033: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 7 event item ITEM0 = UI8BH max stack ?
      case 7:
      {
        if( param1 == 2007915 ) // EOBJECT2 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00035( quest, player ); // Scene00035: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00036: Normal(FadeIn, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1020026 ) // ACTOR13 = SOLDIERA02495
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=SOLDIERA02495
          break;
        }
        if( param1 == 1020027 ) // ACTOR14 = SOLDIERB02495
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=SOLDIERB02495
          break;
        }
        if( param1 == 1020025 ) // ACTOR12 = YUGIRI
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      //seq 8 event item ITEM0 = UI8BH max stack ?
      case 8:
      {
        if( param1 == 1020025 ) // ACTOR12 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00040( quest, player ); // Scene00040: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1019966 ) // ACTOR15 = unknown
        {
          Scene00041( quest, player ); // Scene00041: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019967 ) // ACTOR16 = unknown
        {
          Scene00042( quest, player ); // Scene00042: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( param1 == 1020283 ) // ACTOR17 = YUGIRI
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1019966 ) // ACTOR15 = unknown
        {
          Scene00044( quest, player ); // Scene00044: Empty(None), id=unknown
          break;
        }
        if( param1 == 1019967 ) // ACTOR16 = unknown
        {
          Scene00045( quest, player ); // Scene00045: Empty(None), id=unknown
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
      quest.setSeq( 5 );
    }
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 6 );
    }
  }
  void checkProgressSeq6( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 7 );
    }
  }
  void checkProgressSeq7( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 8 );
    }
  }
  void checkProgressSeq8( World::Quest& quest, Entity::Player& player )
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
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00006: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00009: Empty(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00010: Empty(None), id=unknown" );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00011: Normal(Talk, TargetCanMove, SystemTalk), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00012( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }
  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00012: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00013( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 12, INVIS_ENPC, callback );
  }
  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00013: Normal(Talk, FadeIn, ENpcBind), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00014: Empty(None), id=unknown" );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT1, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00017: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00018( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 17, INVIS_ENPC, callback );
  }
  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT1, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00018: Normal(FadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00019: Empty(None), id=unknown" );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00020: Empty(None), id=unknown" );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00021: Empty(None), id=unknown" );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00022: Empty(None), id=unknown" );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00023: Empty(None), id=unknown" );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00024: Empty(None), id=unknown" );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR12, UI8AL = 1, Flag8(1)=True(Todo:5)
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 5, 0, 0, 0 );
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00026: Empty(None), id=unknown" );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00027: Empty(None), id=unknown" );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00028: Normal(Talk, TargetCanMove), id=SOLDIERA02495" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00029: Normal(Talk, TargetCanMove), id=SOLDIERB02495" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00030: Empty(None), id=unknown" );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00031: Empty(None), id=unknown" );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00032: Empty(None), id=unknown" );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00033: Empty(None), id=unknown" );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_7: EOBJECT2, UI8AL = 1, Flag8(1)=True(Todo:6)
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00035: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00036( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 35, INVIS_ENPC, callback );
  }
  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_7: EOBJECT2, UI8AL = 1, Flag8(1)=True(Todo:6)
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00036: Normal(FadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 6, 0, 0, 0 );
      checkProgressSeq7( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00037: Normal(Talk, TargetCanMove), id=SOLDIERA02495" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, HIDE_HOTBAR, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00038: Normal(Talk, TargetCanMove), id=SOLDIERB02495" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, HIDE_HOTBAR, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00039: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, HIDE_HOTBAR, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_8: ACTOR12, UI8AL = 1, Flag8(1)=True(Todo:7)
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00040: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 7, 0, 0, 0 );
      checkProgressSeq8( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 40, HIDE_HOTBAR, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_8: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00041: Empty(None), id=unknown" );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_8: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00042: Empty(None), id=unknown" );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00043: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 43, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00044: Empty(None), id=unknown" );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda319:68031 calling Scene00045: Empty(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda319 );
