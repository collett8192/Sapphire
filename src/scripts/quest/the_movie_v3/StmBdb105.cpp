// FFXIVTheMovie.ParserV3.12
// param used:
//PRIVATE_RESONATORIUMGUARD = 738
//_ACTOR8 = B
//_ACTOR8B = 3|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBdb105 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBdb105() : Sapphire::ScriptAPI::QuestScript( 68502 ){}; 
  ~StmBdb105() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 1 entries
  //SEQ_2, 7 entries
  //SEQ_3, 9 entries
  //SEQ_4, 7 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1024125
  //ACTOR1 = 1024126
  //ACTOR10 = 1020555
  //ACTOR11 = 1024119
  //ACTOR12 = 1024120
  //ACTOR13 = 1024121
  //ACTOR2 = 1024127
  //ACTOR3 = 1024113
  //ACTOR4 = 1024114
  //ACTOR5 = 1024115
  //ACTOR6 = 1024116
  //ACTOR7 = 1024117
  //ACTOR8 = 1024118
  //ACTOR9 = 1020517
  //BINDACTOR0 = 7074670
  //BINDACTOR1 = 7074676
  //BINDACTOR2 = 7075127
  //BINDACTOR3 = 7074686
  //BINDACTOR4 = 7080993
  //BINDACTOR5 = 7081697
  //BINDACTOR6 = 7080995
  //BINDACTOR7 = 7081697
  //EOBJECT0 = 2009058
  //EOBJECT1 = 2009059
  //EVENTACTION0 = 54
  //EVENTACTION1 = 1
  //LOCACTOR0 = 1021968
  //LOCACTOR1 = 1011887
  //LOCACTOR2 = 1019537
  //LOCACTOR3 = 1019559
  //LOCBGM01 = 495
  //POPRANGE0 = 7080999
  //POPRANGE1 = 7074693
  //TERRITORYTYPE0 = 738

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
        if( param1 == 1024125 ) // ACTOR0 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=LYSE
          }
          break;
        }
        if( param1 == 1024126 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024127 ) // ACTOR2 = ARENVALD
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 1:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00004( quest, player ); // Scene00004: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD
        break;
      }
      case 2:
      {
        if( param1 == 1024114 ) // ACTOR4 = RAUBAHN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1024113 ) // ACTOR3 = RESONATORIUMGUARD
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD
          break;
        }
        if( param1 == 1024115 ) // ACTOR5 = LYSE
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1024116 ) // ACTOR6 = ALPHINAUD
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024117 ) // ACTOR7 = ARENVALD
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024118 ) // ACTOR8 = FLAMEDOCTOR
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR
          break;
        }
        if( param1 == 1020517 ) // ACTOR9 = IRONWORKSENGINEER
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=IRONWORKSENGINEER
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2009058 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00012( quest, player ); // Scene00012: Normal(None), id=unknown
            // +Callback Scene00013: Normal(Talk, SystemTalk, ENpcBind), id=unknown
          }
          break;
        }
        if( param1 == 1024118 ) // ACTOR8 = FLAMEDOCTOR, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR
          }
          else
          {
            Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR
          }
          break;
        }
        if( param1 == 1024113 ) // ACTOR3 = RESONATORIUMGUARD
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD
          break;
        }
        if( param1 == 2009059 ) // EOBJECT1 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1020517 ) // ACTOR9 = IRONWORKSENGINEER
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=IRONWORKSENGINEER
          break;
        }
        if( param1 == 1020555 ) // ACTOR10 = LYSE
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1024114 ) // ACTOR4 = RAUBAHN
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1024116 ) // ACTOR6 = ALPHINAUD
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024117 ) // ACTOR7 = ARENVALD
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1024114 ) // ACTOR4 = RAUBAHN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00024( quest, player ); // Scene00024: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1024113 ) // ACTOR3 = RESONATORIUMGUARD
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD
          break;
        }
        if( param1 == 1024116 ) // ACTOR6 = ALPHINAUD
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024117 ) // ACTOR7 = ARENVALD
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024118 ) // ACTOR8 = FLAMEDOCTOR
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR
          break;
        }
        if( param1 == 1020517 ) // ACTOR9 = IRONWORKSENGINEER
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=IRONWORKSENGINEER
          break;
        }
        if( param1 == 1020555 ) // ACTOR10 = LYSE
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1024119 ) // ACTOR11 = LYSE
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=LYSE
          break;
        }
        if( param1 == 1024120 ) // ACTOR12 = ALPHINAUD
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024121 ) // ACTOR13 = ARENVALD
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=ARENVALD
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
    if( quest.getUI8BH() == 1 )
      if( quest.getUI8AL() == 1 )
      {
        quest.setUI8BH( 0 );
        quest.setUI8AL( 0 );
        quest.setBitFlag8( 1, false );
        quest.setBitFlag8( 2, false );
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
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00003: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00004: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
        checkProgressSeq1( quest, player );
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 738 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 738 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00007: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00009: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00010: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00011: Normal(Talk, TargetCanMove), id=IRONWORKSENGINEER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, UI8BH = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00012: Normal(None), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00013( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }
  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, UI8BH = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00013: Normal(Talk, SystemTalk, ENpcBind), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00014: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }
  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00015: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR" );
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, nullptr );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00016: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 738 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00018: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00019: Normal(Talk, TargetCanMove), id=IRONWORKSENGINEER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00020: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00021: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00023: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00024: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind), id=RAUBAHN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00025: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=RESONATORIUMGUARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.enterPredefinedPrivateInstance( 738 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00027: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00028: Normal(Talk, TargetCanMove), id=FLAMEDOCTOR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00029: Normal(Talk, TargetCanMove), id=IRONWORKSENGINEER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00030: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00031: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 31, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb105:68502 calling Scene00033: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBdb105 );
