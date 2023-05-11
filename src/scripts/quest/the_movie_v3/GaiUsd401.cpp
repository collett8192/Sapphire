// FFXIVTheMovie.ParserV3.11
// param used:
//WARP_SCENE3 = 156|731.26|15.43|-58.536|0.8927|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class GaiUsd401 : public Sapphire::ScriptAPI::QuestScript
{
public:
  GaiUsd401() : Sapphire::ScriptAPI::QuestScript( 67010 ){}; 
  ~GaiUsd401() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 7 entries
  //SEQ_3, 6 entries
  //SEQ_4, 6 entries
  //SEQ_5, 1 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1006725
  //ACTOR1 = 1009372
  //ACTOR10 = 1007754
  //ACTOR11 = 1007761
  //ACTOR12 = 1007762
  //ACTOR13 = 5010000
  //ACTOR14 = 1007763
  //ACTOR2 = 1009373
  //ACTOR3 = 1009374
  //ACTOR4 = 1009375
  //ACTOR5 = 1009376
  //ACTOR6 = 1009377
  //ACTOR7 = 1009378
  //ACTOR8 = 1009379
  //ACTOR9 = 1009380
  //EVENTACTIONSEARCH = 1
  //INSTANCEDUNGEON0 = 30011
  //LOCACTION1 = 1047
  //LOCACTOR0 = 1005518
  //LOCACTOR1 = 1009149
  //LOCACTOR2 = 1009150
  //LOCACTOR3 = 1003855
  //LOCACTOR4 = 1023900
  //LOCACTOR5 = 1023901
  //LOCACTOR6 = 1023902
  //LOCSE1 = 75
  //MUSICEVENTUNEDOGA01 = 212
  //NCUTEVENTGAIUSD4011 = 546
  //NCUTEVENTGAIUSD4012 = 547
  //NCUTEVENTGAIUSD4013 = 548
  //NCUTEVENTGAIUSD4014 = 549
  //NCUTEVENTGAIUSD4015 = 574
  //NCUTEVENTGAIUSD4016 = 575
  //NCUTEVENTGAIUSD4017 = 576
  //POPRANGE0 = 4833641
  //POPRANGE1 = 4585913
  //QUESTCOMPCHECK = 66899
  //TERRITORYTYPE0 = 156
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKIMAGEDUNGEONCRYSTALTOWER2 = 226

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=RAMMBROES
        break;
      }
      case 1:
      {
        if( param1 == 1009372 ) // ACTOR1 = BIGGS
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=BIGGS
            // +Callback Scene00003: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1009373 ) // ACTOR2 = WEDGE
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1009374 ) // ACTOR3 = DOGA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=DOGA
            // +Callback Scene00006: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1009375 ) // ACTOR4 = UNEI
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=UNEI
          break;
        }
        if( param1 == 1009376 ) // ACTOR5 = GRAHATIA
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=GRAHATIA
          break;
        }
        if( param1 == 1009377 ) // ACTOR6 = CID
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1009378 ) // ACTOR7 = NERO
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=NERO
          break;
        }
        if( param1 == 1009379 ) // ACTOR8 = BIGGS
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1009380 ) // ACTOR9 = WEDGE
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1009376 ) // ACTOR5 = GRAHATIA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, Message, FadeIn, TargetCanMove), id=GRAHATIA
          }
          break;
        }
        if( param1 == 1009374 ) // ACTOR3 = DOGA
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=DOGA
          break;
        }
        if( param1 == 1009375 ) // ACTOR4 = UNEI
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=UNEI
          break;
        }
        if( param1 == 1007754 ) // ACTOR10 = CID
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1007761 ) // ACTOR11 = BIGGS
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1007762 ) // ACTOR12 = WEDGE
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1009376 ) // ACTOR5 = GRAHATIA
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=GRAHATIA
          break;
        }
        if( param1 == 1009374 ) // ACTOR3 = DOGA
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=DOGA
          break;
        }
        if( param1 == 1009375 ) // ACTOR4 = UNEI
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=UNEI
          break;
        }
        if( param1 == 1007754 ) // ACTOR10 = CID
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1007761 ) // ACTOR11 = BIGGS
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1007762 ) // ACTOR12 = WEDGE
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 5:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00025( quest, player ); // Scene00025: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006725 ) // ACTOR0 = RAMMBROES
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAMMBROES
          break;
        }
        if( param1 == 1007763 ) // ACTOR14 = GRAHATIA
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=GRAHATIA
          break;
        }
        if( param1 == 1007754 ) // ACTOR10 = CID
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1007761 ) // ACTOR11 = BIGGS
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1007762 ) // ACTOR12 = WEDGE
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=WEDGE
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

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, HIDE_HOTBAR, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00002: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00003( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }
  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00003: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( 156 )->getGuId(), { 731.26, 15.43, -58.536 }, 0.8927 );
    };
    eventMgr().playQuestScene( player, getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00004: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00005: Normal(Talk, TargetCanMove), id=DOGA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00006( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }
  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00006: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00007: Normal(Talk, TargetCanMove), id=UNEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00008: Normal(Talk, TargetCanMove), id=GRAHATIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00009: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00010: Normal(Talk, TargetCanMove), id=NERO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00011: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00012: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00013: Normal(Talk, Message, FadeIn, TargetCanMove), id=GRAHATIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00014: Normal(Talk, TargetCanMove), id=DOGA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00015: Normal(Talk, TargetCanMove), id=UNEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00016: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00017: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00018: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00019: Normal(Talk, TargetCanMove), id=GRAHATIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00020: Normal(Talk, TargetCanMove), id=DOGA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00021: Normal(Talk, TargetCanMove), id=UNEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00022: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00023: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00024: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_5: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:4)
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00025: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00026: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00027: Normal(Talk, TargetCanMove), id=GRAHATIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00028: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00029: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd401:67010 calling Scene00030: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( GaiUsd401 );
