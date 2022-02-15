// FFXIVTheMovie.ParserV3.8
// param used:
//WARP_SCENE4 = 128|-24.3|92|2.47|-0.37|false
//WARP_SCENE8 = 132|7.8|-21.97|123.88|1.58|true
//WARP_SCENE9 = 128|-24.3|92|2.47|-0.37|false
//WARP_SCENE12 = 132|35.5|-19|105|-3.14|false
//WARP_SCENE15 = 132|7.8|-21.97|123.88|1.58|true
//WARP_SCENE24 = 132|22.55|-19|114.2|0|false
//WARP_SCENE30 = 130|-44.14|84|-0.47|1.3|true
//WARP_SCENE31 = 132|22.55|-19|114.2|0|false
//WARP_SCENE36 = 130|-19.45|83.2|3.85|1.8|false
//WARP_SCENE41 = 130|-44.14|84|-0.47|1.3|true
//ID_ACTOR5 = 4296108319
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManSea200 : public Sapphire::ScriptAPI::QuestScript
{
public:
  ManSea200() : Sapphire::ScriptAPI::QuestScript( 66082 ){}; 
  ~ManSea200() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 3 entries
  //SEQ_4, 4 entries
  //SEQ_5, 4 entries
  //SEQ_6, 3 entries
  //SEQ_7, 4 entries
  //SEQ_8, 5 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1002694
  //ACTOR1 = 1001029
  //ACTOR10 = 1001821
  //ACTOR2 = 1000972
  //ACTOR3 = 1002695
  //ACTOR4 = 1002830
  //ACTOR5 = 1000109
  //ACTOR6 = 1000460
  //ACTOR7 = 1000106
  //ACTOR8 = 1004336
  //ACTOR9 = 1004434
  //EOBJECT0 = 2001675
  //EOBJECT1 = 2001668
  //EOBJECT2 = 2001678
  //EOBJECT3 = 2001671
  //EOBJECT4 = 2001688
  //EVENTACTIONWAITINGSHOR = 11
  //ITEM0 = 2000458
  //ITEM1 = 2000459
  //NCUTEVENT001 = 212
  //NCUTEVENT002 = 213
  //NCUTEVENT003 = 214
  //NCUTEVENT004 = 154
  //NCUTEVENT005 = 67
  //NCUTEVENT006 = 99
  //NCUTEVENT007 = 156
  //NCUTEVENT008 = 100
  //NCUTEVENT009 = 159
  //NCUTEVENT010 = 232
  //NCUTEVENT011 = 231
  //NCUTEVENT012 = 228
  //NCUTEVENT013 = 227
  //NCUTEVENT014 = 231
  //NCUTEVENT015 = 229
  //POPRANGE0 = 4146949
  //POPRANGE1 = 4103402
  //POPRANGE2 = 4102803
  //POPRANGE3 = 4103382
  //POPRANGE4 = 4103392
  //POPRANGE5 = 4102780
  //POPRANGE6 = 4103339
  //TERRITORYTYPE0 = 198
  //TERRITORYTYPE1 = 128
  //TERRITORYTYPE2 = 132
  //TERRITORYTYPE3 = 130
  //UNLOCKIMAGEAIRSHIP = 68

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
      //seq 0 event item ITEM0 = UI8BH max stack 1
      //seq 0 event item ITEM1 = UI8BL max stack 1
      case 0:
      {
        if( param1 == 1002694 ) // ACTOR0 = MERLWYB
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=MERLWYB
            // +Callback Scene00001: Normal(CutScene, QuestAccept), id=unknown
          }
          break;
        }
        if( param1 == 1001029 ) // ACTOR1 = unknown
        {
          Scene00002( quest, player ); // Scene00002: Normal(YesNo, TargetCanMove), id=unknown
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      //seq 1 event item ITEM1 = UI8BL max stack 1
      case 1:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00003( quest, player ); // Scene00003: Normal(CutScene), id=unknown
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      //seq 2 event item ITEM1 = UI8BL max stack 1
      case 2:
      {
        if( param1 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          }
          break;
        }
        if( param1 == 2001675 ) // EOBJECT0 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      //seq 3 event item ITEM1 = UI8BL max stack 1
      case 3:
      {
        if( param1 == 2001668 ) // EOBJECT1 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00007( quest, player ); // Scene00007: Normal(YesNo, CanCancel), id=unknown
            // +Callback Scene00008: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          break;
        }
        if( param1 == 2001675 ) // EOBJECT0 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      //seq 4 event item ITEM1 = UI8BL max stack 1
      case 4:
      {
        if( param1 == 1002830 ) // ACTOR4 = SERPENT
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=SERPENT
          }
          break;
        }
        if( param1 == 1000109 || param1 == 4296108319 ) // ACTOR5 = CABINCREW
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CABINCREW
          break;
        }
        if( param1 == 2001678 ) // EOBJECT2 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          // +Callback Scene00015: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 1
      //seq 5 event item ITEM1 = UI8BL max stack 1
      case 5:
      {
        if( param1 == 1000460 ) // ACTOR6 = DOORMANLOTUS
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00016( quest, player ); // Scene00016: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00017: Normal(Talk, TargetCanMove), id=DOORMANLOTUS
            // +Callback Scene00018: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1002830 ) // ACTOR4 = SERPENT
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=SERPENT
          break;
        }
        if( param1 == 2001678 ) // EOBJECT2 = unknown
        {
          Scene00021( quest, player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          // +Callback Scene00023: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      //seq 6 event item ITEM1 = UI8BH max stack 1
      case 6:
      {
        if( param1 == 1000106 ) // ACTOR7 = LIONNELLAIS
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00024( quest, player ); // Scene00024: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS
          }
          break;
        }
        if( param1 == 2001678 ) // EOBJECT2 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          // +Callback Scene00027: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      //seq 7 event item ITEM1 = UI8BH max stack 1
      case 7:
      {
        if( param1 == 2001671 ) // EOBJECT3 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00029( quest, player ); // Scene00029: Normal(YesNo, CanCancel), id=unknown
            // +Callback Scene00030: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1000106 ) // ACTOR7 = LIONNELLAIS
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS
          break;
        }
        if( param1 == 2001678 ) // EOBJECT2 = unknown
        {
          Scene00032( quest, player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          // +Callback Scene00034: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      //seq 8 event item ITEM1 = UI8BH max stack 1
      case 8:
      {
        if( param1 == 1004336 ) // ACTOR8 = FLAMEA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=FLAMEA
          }
          break;
        }
        if( param1 == 1004434 ) // ACTOR9 = CABINCREW
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CABINCREW
          break;
        }
        if( param1 == 2001688 ) // EOBJECT4 = unknown
        {
          Scene00037( quest, player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          // +Callback Scene00039: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1000106 ) // ACTOR7 = LIONNELLAIS
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS
          // +Callback Scene00041: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1001821 ) // ACTOR10 = BARTHOLOMEW
        {
          Scene00042( quest, player ); // Scene00042: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00043: Normal(Talk, TargetCanMove), id=BARTHOLOMEW
          // +Callback Scene00044: Normal(CutScene), id=unknown
          // +Callback Scene00045: Normal(QuestReward, QuestComplete, SystemTalk), id=unknown
          break;
        }
        if( param1 == 1004336 ) // ACTOR8 = FLAMEA
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=FLAMEA
          break;
        }
        if( param1 == 2001688 ) // EOBJECT4 = unknown
        {
          Scene00048( quest, player ); // Scene00048: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          // +Callback Scene00050: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1000106 ) // ACTOR7 = LIONNELLAIS
        {
          Scene00051( quest, player ); // Scene00051: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS
          // +Callback Scene00052: Normal(CutScene, AutoFadeIn), id=unknown
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

  void onBNpcKill( World::Quest& quest, uint16_t nameId, uint32_t entityId, Sapphire::Entity::Player& player ) override
  {
    onProgress( quest, player, EVENT_ON_BNPC_KILL, static_cast< uint64_t >( nameId ), entityId, 0 );
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
    quest.setSeq( 2 );
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
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 5 );
      quest.setUI8BH( 1 );
      quest.setUI8BL( 1 );
    }
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setUI8BH( 0 );
      quest.setUI8BL( 0 );
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
      quest.setUI8BH( 1 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00001: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00002: Normal(YesNo, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
      }
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00004: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 1, true );
        checkProgressSeq2( quest, player );
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.forceZoneing( 128, -24.3f, 92.0f, 2.47f, -0.37f, false );
      }
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00007: Normal(YesNo, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00008( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }
  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00008: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 132, 7.8f, -21.97f, 123.88f, 1.58f, true );
    };
    eventMgr().playQuestScene( player, getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00009: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.forceZoneing( 128, -24.3f, 92.0f, 2.47f, -0.37f, false );
      }
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00011: Normal(Talk, TargetCanMove), id=SERPENT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00012: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CABINCREW" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.forceZoneing( 132, 35.5f, -19.0f, 105.0f, -3.14f, false );
      }
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq4( quest, player );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00014: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00015( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }
  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00015: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 132, 7.8f, -21.97f, 123.88f, 1.58f, true );
    };
    eventMgr().playQuestScene( player, getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00016: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00017( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }
  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00017: Normal(Talk, TargetCanMove), id=DOORMANLOTUS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00018( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }
  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00018: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00020: Normal(Talk, TargetCanMove), id=SERPENT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq5( quest, player );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00022: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00023( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }
  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00023: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00024: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 1, true );
        checkProgressSeq6( quest, player );
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.forceZoneing( 132, 22.55f, -19.0f, 114.2f, 0.0f, false );
      }
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_6: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00025: Normal(None), id=unknown" );
    checkProgressSeq6( quest, player );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00026: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00027( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }
  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00027: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_7: EOBJECT3, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00029: Normal(YesNo, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00030( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }
  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_7: EOBJECT3, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00030: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq7( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 130, -44.14f, 84.0f, -0.47f, 1.3f, true );
    };
    eventMgr().playQuestScene( player, getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00031: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.forceZoneing( 132, 22.55f, -19.0f, 114.2f, 0.0f, false );
      }
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_7: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00032: Normal(None), id=unknown" );
    checkProgressSeq7( quest, player );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00033: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00034( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 33, NONE, callback );
  }
  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00034: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 34, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_8: ACTOR8, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00035: Normal(Talk, TargetCanMove), id=FLAMEA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq8( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 35, NONE, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_8: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00036: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CABINCREW" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.forceZoneing( 130, -19.45f, 83.2f, 3.85f, 1.8f, false );
      }
    };
    eventMgr().playQuestScene( player, getId(), 36, NONE, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_8: EOBJECT4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00037: Normal(None), id=unknown" );
    checkProgressSeq8( quest, player );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_8: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00038: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00039( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 38, NONE, callback );
  }
  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_8: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00039: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 39, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_8: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00040: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00041( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 40, NONE, callback );
  }
  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_8: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00041: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 130, -44.14f, 84.0f, -0.47f, 1.3f, true );
    };
    eventMgr().playQuestScene( player, getId(), 41, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00042: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00043( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 42, NONE, callback );
  }
  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00043: Normal(Talk, TargetCanMove), id=BARTHOLOMEW" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00044( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 43, NONE, callback );
  }
  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00044: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00045( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 44, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00045: Normal(QuestReward, QuestComplete, SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 45, NONE, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00047: Normal(Talk, TargetCanMove), id=FLAMEA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, NONE, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00048: Normal(None), id=unknown" );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00049: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00050( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 49, NONE, callback );
  }
  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00050: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 50, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00051: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00052( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 51, NONE, callback );
  }
  void Scene00052( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "ManSea200:66082 calling Scene00052: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 52, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( ManSea200 );
