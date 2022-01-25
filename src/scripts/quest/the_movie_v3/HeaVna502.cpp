// FFXIVTheMovie.ParserV3.8
// param used:
//WARP_WEDGE = 401|-807.3|-57.7|158.4|1|true
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna502 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna502() : Sapphire::ScriptAPI::QuestScript( 67179 ){}; 
  ~HeaVna502() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 6 entries
  //SEQ_3, 7 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1013385
  //ACTOR1 = 1013077
  //ACTOR10 = 1013086
  //ACTOR2 = 1013078
  //ACTOR3 = 1013079
  //ACTOR4 = 1013965
  //ACTOR5 = 1013125
  //ACTOR6 = 1013081
  //ACTOR7 = 1013082
  //ACTOR8 = 1013083
  //ACTOR9 = 1013085
  //EOBJECT0 = 2005537
  //EVENTACTIONSEARCH = 1
  //LOCMAKERAL = 1011887
  //LOCMAKERBI = 5859511
  //LOCMAKERUE = 5859510
  //LOCMOVEPOSCID = 5898885
  //LOCMOVEPOSUE = 5898886
  //NCUTHEAVNA50210 = 864
  //POPRANGE0 = 5895978
  //POPRANGE1 = 5858487
  //TERRITORYTYPE0 = 401

  static constexpr auto EVENT_ON_TALK = 0;
  static constexpr auto EVENT_ON_EMOTE = 1;
  static constexpr auto EVENT_ON_BNPC_KILL = 2;
  static constexpr auto EVENT_ON_WITHIN_RANGE = 3;
  static constexpr auto EVENT_ON_ENTER_TERRITORY = 4;
  static constexpr auto EVENT_ON_EVENT_ITEM = 5;
  static constexpr auto EVENT_ON_EOBJ_HIT = 6;

private:
  void onProgress( World::Quest& quest, Entity::Player& player, uint32_t type, uint64_t param1, uint32_t param2, uint32_t param3 )
  {
    switch( quest.getSeq() )
    {
      case 0:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( param1 == 1013077 ) // ACTOR1 = CID
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind), id=CID
          }
          break;
        }
        if( param1 == 1013078 ) // ACTOR2 = WEDGE
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        if( param1 == 1013079 ) // ACTOR3 = BIGGS
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1013965 ) // ACTOR4 = LKHONEBB
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=LKHONEBB
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1013125 ) // ACTOR5 = WEDGE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=WEDGE
          }
          break;
        }
        if( param1 == 1013081 ) // ACTOR6 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013082 ) // ACTOR7 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013083 ) // ACTOR8 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005537 ) // EOBJECT0 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013965 ) // ACTOR4 = LKHONEBB
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=LKHONEBB
          break;
        }
        break;
      }
      case 3:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00014( quest, player ); // Scene00014: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1013125 ) // ACTOR5 = WEDGE
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, YesNo, TargetCanMove), id=WEDGE
          break;
        }
        if( param1 == 1013081 ) // ACTOR6 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013082 ) // ACTOR7 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013083 ) // ACTOR8 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005537 ) // EOBJECT0 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013965 ) // ACTOR4 = LKHONEBB
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=LKHONEBB
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1013085 ) // ACTOR9 = ALPHINAUD
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013086 ) // ACTOR10 = CID
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=CID
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
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00003: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 401, -807.3f, -57.7f, 158.4f, 1.0f, true );
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00004: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00005: Normal(Talk, TargetCanMove), id=LKHONEBB" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 && result.numOfResults >= 1 && result.getResult( 0 ) == 1 )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 1, true );
        checkProgressSeq2( quest, player );
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.forceZoneing( 401, -807.3f, -57.7f, 158.4f, 1.0f, true );
      }
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq2( quest, player );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00013: Normal(Talk, TargetCanMove), id=LKHONEBB" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00014: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00015: Normal(Talk, YesNo, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.forceZoneing( 401, -807.3f, -57.7f, 158.4f, 1.0f, true );
      }
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00021: Normal(Talk, TargetCanMove), id=LKHONEBB" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna502:67179 calling Scene00023: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna502 );
