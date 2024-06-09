// FFXIVTheMovie.ParserV3.12
// param used:
//PRIVATE_SCENE6 = 737
//PRIVATE_SCENE14 = 737
//PRIVATE_SCENE16 = 737
//PRIVATE_SCENE18 = 737
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBdb111 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBdb111() : Sapphire::ScriptAPI::QuestScript( 68508 ){}; 
  ~StmBdb111() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 3 entries
  //SEQ_4, 2 entries
  //SEQ_5, 2 entries
  //SEQ_6, 3 entries
  //SEQ_7, 6 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1024063
  //ACTOR1 = 1024064
  //ACTOR10 = 1024069
  //ACTOR11 = 1024070
  //ACTOR12 = 1024071
  //ACTOR13 = 1024072
  //ACTOR14 = 1024073
  //ACTOR15 = 1019468
  //ACTOR2 = 1024065
  //ACTOR3 = 1024150
  //ACTOR4 = 1024151
  //ACTOR5 = 1024152
  //ACTOR6 = 1024153
  //ACTOR7 = 1024066
  //ACTOR8 = 1024206
  //ACTOR9 = 1024068
  //EOBJECT0 = 2009048
  //EOBJECT1 = 2009072
  //EVENTACTION0 = 11
  //EVENTACTION1 = 1
  //LOCBGM01 = 459
  //LOCBINDALPH02 = 7074877
  //LOCBINDALPHEVENTZONE = 7081698
  //LOCBINDAREN01 = 7074873
  //LOCBINDAREN03 = 7074876
  //LOCBINDARENEVENTZONE = 7081696
  //LOCBINDRAUEVENTZONE = 7081693
  //LOCBINDTHAN01 = 7074897
  //LOCBINDYSHTEVENTZONE = 7081695
  //LOCENPCALISAIE01 = 1019541
  //LOCENPCALPH01 = 1011887
  //LOCENPCAREN01 = 1019537
  //LOCENPCMNAAGO01 = 1018318
  //LOCENPCTHAN01 = 1015842
  //LOCENPCYSHT01 = 1011889
  //NCUT01 = 1628
  //NCUT02 = 1630
  //NCUT03 = 1631
  //NCUT04 = 1632
  //NCUT05 = 1633
  //NCUT06 = 1634
  //NCUT07 = 1635
  //NCUT08 = 1636
  //POPRANGE0 = 7081686
  //POPRANGE1 = 7081797
  //POPRANGE2 = 7081687
  //POPRANGE3 = 7074883
  //QUESTBATTLE0 = 5024
  //TERRITORYTYPE0 = 403
  //TERRITORYTYPE1 = 737

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
        if( param1 == 1024063 ) // ACTOR0 = RAUBAHN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, Menu, ENpcBind), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1024064 ) // ACTOR1 = ARENVALD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 1:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00004( quest, player ); // Scene00004: Normal(Talk, FadeIn, CreateCharacterTalk), id=unknown
        break;
      }
      case 2:
      {
        if( param1 == 1024065 ) // ACTOR2 = RESISTANCEGATEGUARD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD
            // +Callback Scene00006: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1024150 ) // ACTOR3 = ALPHINAUD
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024151 ) // ACTOR4 = ARENVALD
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024152 ) // ACTOR5 = YSHTOLA
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1024153 ) // ACTOR6 = THANCRED
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1024066 ) // ACTOR7 = ARENVALD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, SystemTalk), id=ARENVALD
          }
          break;
        }
        if( param1 == 2009072 ) // EOBJECT1 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Empty(None), id=unknown
          break;
        }
        if( param1 == 1024065 ) // ACTOR2 = RESISTANCEGATEGUARD
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEGUARD
          break;
        }
        break;
      }
      case 4:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00015( quest, player ); // Scene00015: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1024065 ) // ACTOR2 = RESISTANCEGATEGUARD
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEGUARD
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1024206 ) // ACTOR8 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00017( quest, player ); // Scene00017: Normal(Talk, CutScene, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind), id=LYSE
          }
          break;
        }
        if( param1 == 1024065 ) // ACTOR2 = RESISTANCEGATEGUARD
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEGUARD
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1024068 ) // ACTOR9 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00019( quest, player ); // Scene00019: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1024069 ) // ACTOR10 = ARENVALD
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024070 ) // ACTOR11 = ALPHINAUD
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 1024068 ) // ACTOR9 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00022( quest, player ); // Scene00022: Normal(Talk, NpcDespawn, TargetCanMove, SystemTalk, ENpcBind), id=LYSE
          }
          break;
        }
        if( param1 == 1024069 ) // ACTOR10 = ARENVALD
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024070 ) // ACTOR11 = ALPHINAUD
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024071 ) // ACTOR12 = NANAMOULNAMO
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=NANAMOULNAMO
          break;
        }
        if( param1 == 1024072 ) // ACTOR13 = RAUBAHN
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1024073 ) // ACTOR14 = PIPIN
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019468 ) // ACTOR15 = LYSE
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, CutScene, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1024071 ) // ACTOR12 = NANAMOULNAMO
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=NANAMOULNAMO
          break;
        }
        if( param1 == 1024072 ) // ACTOR13 = RAUBAHN
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1024073 ) // ACTOR14 = PIPIN
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=PIPIN
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
    quest.setSeq( 5 );
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
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, Menu, ENpcBind), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        checkProgressSeq0( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00002: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00004: Normal(Talk, FadeIn, CreateCharacterTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI | INVIS_ENPC, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00005: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00006( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }
  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00006: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.enterPredefinedPrivateInstance( 737 );
    };
    eventMgr().playQuestScene( player, getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00008: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00010: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00011: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, SystemTalk), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        //quest battle
        eventMgr().eventFinish( player, result.eventId, 1 );
        teriMgr().createAndJoinQuestBattle( player, 5024 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00013: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00014: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 737 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_4: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00015: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00016: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 737 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR8, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00017: Normal(Talk, CutScene, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00018: Normal(Talk, YesNo, TargetCanMove), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 737 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:5)
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00019: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 5, 0, 0, 0 );
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00020: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:6)
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00022: Normal(Talk, NpcDespawn, TargetCanMove, SystemTalk, ENpcBind), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 6, 0, 0, 0 );
      checkProgressSeq7( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00023: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00025: Normal(Talk, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00026: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00027: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00028: Normal(Talk, CutScene, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 28, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00029: Normal(Talk, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00030: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb111:68508 calling Scene00031: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBdb111 );
