// FFXIVTheMovie.ParserV3.9
// param used:
//SCENE_15 = GUIDANCESYSTEM
//WARP_SCENE22 = 402|214.35|-66|-615.7|2.97|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna703 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna703() : Sapphire::ScriptAPI::QuestScript( 67201 ){}; 
  ~HeaVna703() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 6 entries
  //SEQ_2, 7 entries
  //SEQ_3, 8 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1012796
  //ACTOR1 = 1014675
  //ACTOR10 = 1012800
  //ACTOR11 = 1012802
  //ACTOR12 = 1012803
  //ACTOR13 = 1012804
  //ACTOR14 = 1012805
  //ACTOR2 = 1014676
  //ACTOR3 = 1012795
  //ACTOR4 = 1014677
  //ACTOR5 = 1014678
  //ACTOR6 = 1014679
  //ACTOR7 = 1012797
  //ACTOR8 = 1012798
  //ACTOR9 = 1012799
  //CUTSCENEN01 = 1019
  //CUTSCENEN02 = 1037
  //EOBJECT0 = 2006363
  //LOCACTOR0 = 5916698
  //LOCACTOR1 = 5916699
  //LOCACTOR10 = 5867519
  //LOCACTOR11 = 5867523
  //LOCACTOR12 = 5867521
  //LOCACTOR2 = 5916695
  //LOCACTOR3 = 5916696
  //LOCACTOR4 = 5867476
  //POPRANGE0 = 5890159

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
        if( param1 == 1012796 ) // ACTOR0 = GUIDANCESYSTEM
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, Menu), id=GUIDANCESYSTEM
          }
          break;
        }
        if( param1 == 1014675 ) // ACTOR1 = CID
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1014676 ) // ACTOR2 = BIGGS
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1012795 ) // ACTOR3 = WEDGE
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        if( param1 == 1014677 ) // ACTOR4 = ALPHINAUD
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1014678 ) // ACTOR5 = ESTINIEN
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1014679 ) // ACTOR6 = YSHTOLA
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1014677 ) // ACTOR4 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1014678 ) // ACTOR5 = ESTINIEN
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1014679 ) // ACTOR6 = YSHTOLA
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1014675 ) // ACTOR1 = CID
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1014676 ) // ACTOR2 = BIGGS
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1012795 ) // ACTOR3 = WEDGE
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1012797 ) // ACTOR7 = GUIDANCESYSTEM
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM
            // +Callback Scene00015: Normal(CutScene), id=GUIDANCESYSTEM
          }
          break;
        }
        if( param1 == 1012798 ) // ACTOR8 = ALPHINAUD
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012799 ) // ACTOR9 = ESTINIEN
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012800 ) // ACTOR10 = YSHTOLA
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1014675 ) // ACTOR1 = CID
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1014676 ) // ACTOR2 = BIGGS
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1012795 ) // ACTOR3 = WEDGE
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2006363 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00022( quest, player ); // Scene00022: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1012797 ) // ACTOR7 = GUIDANCESYSTEM
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM
          break;
        }
        if( param1 == 1012798 ) // ACTOR8 = ALPHINAUD
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012799 ) // ACTOR9 = ESTINIEN
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012800 ) // ACTOR10 = YSHTOLA
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1014675 ) // ACTOR1 = CID
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1014676 ) // ACTOR2 = BIGGS
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1012795 ) // ACTOR3 = WEDGE
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012802 ) // ACTOR11 = GUIDANCESYSTEM
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GUIDANCESYSTEM
          break;
        }
        if( param1 == 1012803 ) // ACTOR12 = ALPHINAUD
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012804 ) // ACTOR13 = ESTINIEN
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012805 ) // ACTOR14 = YSHTOLA
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1014675 ) // ACTOR1 = CID
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1014676 ) // ACTOR2 = BIGGS
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1012795 ) // ACTOR3 = WEDGE
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=WEDGE
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
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, Menu), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        checkProgressSeq0( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00002: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00003: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00004: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00006: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00007: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00008: Normal(Talk, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00009: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00010: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00011: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00012: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00013: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00014: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00015( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }
  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00015: Normal(CutScene), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00017: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00019: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00020: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00021: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00022: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 402, 214.35f, -66.0f, -615.7f, 2.97f, false );
    };
    eventMgr().playQuestScene( player, getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00023: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, NONE, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00025: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00026: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00027: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00028: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00029: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00032: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, NONE, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00033: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, NONE, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00034: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, NONE, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00035: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, NONE, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna703:67201 calling Scene00036: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna703 );
