// FFXIVTheMovie.ParserV3.9
// param used:
//SCENE_18 = HOARYBOULDER
//_ACTOR10 = B
//_ACTOR10B = 3|2
//_ACTOR11 = B
//_ACTOR11B = 3|2
//_ACTOR12 = B
//_ACTOR12B = 3|2
//_ACTOR13 = B
//_ACTOR13B = 3|2
//_ACTOR14 = B
//_ACTOR14B = 3|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc101 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVnc101() : Sapphire::ScriptAPI::QuestScript( 67767 ){}; 
  ~HeaVnc101() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 15 entries
  //SEQ_255, 15 entries

  //ACTOR0 = 1012580
  //ACTOR1 = 1013227
  //ACTOR10 = 1016541
  //ACTOR11 = 1016538
  //ACTOR12 = 1016542
  //ACTOR13 = 1016543
  //ACTOR14 = 1016540
  //ACTOR15 = 1016534
  //ACTOR16 = 1016535
  //ACTOR17 = 1016536
  //ACTOR18 = 1016537
  //ACTOR19 = 1016539
  //ACTOR2 = 1016531
  //ACTOR20 = 1016553
  //ACTOR21 = 1016554
  //ACTOR22 = 1016555
  //ACTOR23 = 1016556
  //ACTOR24 = 1016557
  //ACTOR3 = 1016532
  //ACTOR4 = 1016533
  //ACTOR5 = 1012692
  //ACTOR6 = 1012693
  //ACTOR7 = 1010388
  //ACTOR8 = 1010389
  //ACTOR9 = 1010390
  //CUTSCENEN01 = 1140
  //LOCACTOR0 = 6184280
  //LOCACTOR1 = 6184281
  //LOCACTOR10 = 6203498
  //LOCACTOR11 = 6203499
  //LOCACTOR12 = 6184224
  //LOCACTOR13 = 6184233
  //LOCACTOR14 = 6184253
  //LOCACTOR2 = 6184283
  //LOCACTOR20 = 6239638
  //LOCACTOR21 = 6239639
  //LOCACTOR3 = 6184246
  //LOCACTOR4 = 6184225
  //LOCACTOR5 = 1015842
  //LOCACTOR6 = 1015833
  //LOCACTOR7 = 5865011

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
        if( param1 == 1012580 ) // ACTOR0 = TATARU
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=TATARU
          }
          break;
        }
        if( param1 == 1013227 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1016531 ) // ACTOR2 = FLHAMINN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00003( quest, player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind), id=FLHAMINN
            // +Callback Scene00004: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1016532 ) // ACTOR3 = HOARYBOULDER
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=HOARYBOULDER
          break;
        }
        if( param1 == 1016533 ) // ACTOR4 = COULTENET
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=COULTENET
          break;
        }
        if( param1 == 1012692 ) // ACTOR5 = ALPHINAUD
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012693 ) // ACTOR6 = TATARU
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1010388 ) // ACTOR7 = FLHAMINN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove, ENpcBind), id=FLHAMINN
          }
          break;
        }
        if( param1 == 1010389 ) // ACTOR8 = HOARYBOULDER
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=HOARYBOULDER
          break;
        }
        if( param1 == 1010390 ) // ACTOR9 = COULTENET
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=COULTENET
          break;
        }
        if( param1 == 1012692 ) // ACTOR5 = ALPHINAUD
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012693 ) // ACTOR6 = TATARU
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1016541 ) // ACTOR10 = FLHAMINN, CB=2
        {
          if( quest.getUI8CL() != 1 )
          {
            Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove, ENpcBind), id=unknown
          }
          else
          {
            Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=FLHAMINN
          }
          break;
        }
        if( param1 == 1016538 ) // ACTOR11 = AERGMHUS, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=AERGMHUS
          }
          else
          {
            Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=AERGMHUS
          }
          break;
        }
        if( param1 == 1016542 ) // ACTOR12 = HOARYBOULDER, CB=2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00018( quest, player ); // Scene00018: Normal(Talk, ENpcBind), id=HOARYBOULDER
          }
          else
          {
            Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=HOARYBOULDER
          }
          break;
        }
        if( param1 == 1016543 ) // ACTOR13 = COULTENET, CB=2
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=COULTENET
          }
          else
          {
            Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=COULTENET
          }
          break;
        }
        if( param1 == 1016540 ) // ACTOR14 = HOUMEI, CB=2
        {
          if( quest.getUI8CH() != 1 )
          {
            Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove, ENpcBind), id=HOUMEI
          }
          else
          {
            Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=HOUMEI
          }
          break;
        }
        if( param1 == 1016534 ) // ACTOR15 = ALPHINAUD
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1016535 ) // ACTOR16 = TATARU
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1016536 ) // ACTOR17 = ALIANNE
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALIANNE
          break;
        }
        if( param1 == 1016537 ) // ACTOR18 = EPHEMIE
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=EPHEMIE
          break;
        }
        if( param1 == 1016539 ) // ACTOR19 = ISILDAURE
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=ISILDAURE
          break;
        }
        if( param1 == 1016553 ) // ACTOR20 = BLUOMWYDA
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=BLUOMWYDA
          break;
        }
        if( param1 == 1016554 ) // ACTOR21 = OCHERBOULDER
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=OCHERBOULDER
          break;
        }
        if( param1 == 1016555 ) // ACTOR22 = VMAHTIA
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1016556 ) // ACTOR23 = AENOR
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=AENOR
          break;
        }
        if( param1 == 1016557 ) // ACTOR24 = CLEMENCE
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=CLEMENCE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016535 ) // ACTOR16 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=unknown
          break;
        }
        if( param1 == 1016534 ) // ACTOR15 = ALPHINAUD
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1016536 ) // ACTOR17 = ALIANNE
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALIANNE
          break;
        }
        if( param1 == 1016537 ) // ACTOR18 = EPHEMIE
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=EPHEMIE
          break;
        }
        if( param1 == 1016538 ) // ACTOR11 = AERGMHUS
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=AERGMHUS
          break;
        }
        if( param1 == 1016539 ) // ACTOR19 = ISILDAURE
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=ISILDAURE
          break;
        }
        if( param1 == 1016540 ) // ACTOR14 = HOUMEI
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=HOUMEI
          break;
        }
        if( param1 == 1016541 ) // ACTOR10 = FLHAMINN
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=FLHAMINN
          break;
        }
        if( param1 == 1016542 ) // ACTOR12 = HOARYBOULDER
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=HOARYBOULDER
          break;
        }
        if( param1 == 1016543 ) // ACTOR13 = COULTENET
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=COULTENET
          break;
        }
        if( param1 == 1016553 ) // ACTOR20 = BLUOMWYDA
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=BLUOMWYDA
          break;
        }
        if( param1 == 1016554 ) // ACTOR21 = OCHERBOULDER
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=OCHERBOULDER
          break;
        }
        if( param1 == 1016555 ) // ACTOR22 = VMAHTIA
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1016556 ) // ACTOR23 = AENOR
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=AENOR
          break;
        }
        if( param1 == 1016557 ) // ACTOR24 = CLEMENCE
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=CLEMENCE
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
    if( quest.getUI8CL() == 1 )
      if( quest.getUI8AL() == 1 )
        if( quest.getUI8BH() == 1 )
          if( quest.getUI8BL() == 1 )
            if( quest.getUI8CH() == 1 )
            {
              quest.setUI8CL( 0 );
              quest.setUI8AL( 0 );
              quest.setUI8BH( 0 );
              quest.setUI8BL( 0 );
              quest.setUI8CH( 0 );
              quest.setBitFlag8( 1, false );
              quest.setBitFlag8( 2, false );
              quest.setBitFlag8( 3, false );
              quest.setBitFlag8( 4, false );
              quest.setBitFlag8( 5, false );
              quest.setSeq( 255 );
            }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind), id=FLHAMINN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00004( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00005: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00006: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00008: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00009: Normal(Talk, TargetCanMove, ENpcBind), id=FLHAMINN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00010: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00011: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00013: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, UI8CL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00014: Normal(Talk, TargetCanMove, ENpcBind), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8CL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }
  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, UI8CL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00015: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    eventMgr().playQuestScene( player, getId(), 15, NONE, nullptr );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00016: Normal(Talk, TargetCanMove), id=AERGMHUS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }
  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00017: Normal(Talk, TargetCanMove), id=AERGMHUS" );
    eventMgr().playQuestScene( player, getId(), 17, NONE, nullptr );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00018: Normal(Talk, ENpcBind), id=HOARYBOULDER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }
  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00019: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    eventMgr().playQuestScene( player, getId(), 19, NONE, nullptr );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR13, UI8BL = 1, Flag8(4)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00020: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 4, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }
  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR13, UI8BL = 1, Flag8(4)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00021: Normal(Talk, TargetCanMove), id=COULTENET" );
    eventMgr().playQuestScene( player, getId(), 21, NONE, nullptr );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR14, UI8CH = 1, Flag8(5)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00022: Normal(Talk, TargetCanMove, ENpcBind), id=HOUMEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8CH( 1 );
      quest.setBitFlag8( 5, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }
  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR14, UI8CH = 1, Flag8(5)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00023: Normal(Talk, TargetCanMove), id=HOUMEI" );
    eventMgr().playQuestScene( player, getId(), 23, NONE, nullptr );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00025: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00026: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00027: Normal(Talk, TargetCanMove), id=EPHEMIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00028: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00029: Normal(Talk, TargetCanMove), id=BLUOMWYDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00030: Normal(Talk, TargetCanMove), id=OCHERBOULDER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00031: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00032: Normal(Talk, TargetCanMove), id=AENOR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, NONE, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00033: Normal(Talk, TargetCanMove), id=CLEMENCE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, NONE, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00034: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 34, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, NONE, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00036: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, NONE, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00037: Normal(Talk, TargetCanMove), id=EPHEMIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, NONE, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00038: Normal(Talk, TargetCanMove), id=AERGMHUS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, NONE, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00039: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, NONE, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00040: Normal(Talk, TargetCanMove), id=HOUMEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, NONE, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00041: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, NONE, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00042: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, NONE, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00043: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, NONE, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00044: Normal(Talk, TargetCanMove), id=BLUOMWYDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, NONE, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00045: Normal(Talk, TargetCanMove), id=OCHERBOULDER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, NONE, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00046: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, NONE, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00047: Normal(Talk, TargetCanMove), id=AENOR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, NONE, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc101:67767 calling Scene00048: Normal(Talk, TargetCanMove), id=CLEMENCE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnc101 );
