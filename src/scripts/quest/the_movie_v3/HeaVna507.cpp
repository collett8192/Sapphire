// FFXIVTheMovie.ParserV3.8
// param used:
//SCENE_2 = ALPHINAUD
//WARP_SCENE2 = 401|-584.1|-52.4|-445.3|2.88|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna507 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna507() : Sapphire::ScriptAPI::QuestScript( 67184 ){}; 
  ~HeaVna507() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 7 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1014575
  //ACTOR1 = 1014564
  //ACTOR2 = 1014622
  //ACTOR3 = 1014573
  //ACTOR4 = 1013100
  //ACTOR5 = 1013102
  //ACTOR6 = 1013103
  //ACTOR7 = 1012064
  //ACTOR8 = 1012195
  //LOCACTIONNADERU = 848
  //LOCACTORAL = 1011887
  //LOCACTORBI = 5920875
  //LOCACTORENTA = 2006048
  //LOCACTORMAD = 1012494
  //LOCACTORRUKIA = 1008193
  //LOCACTORUE = 5931576
  //LOCMAKERENTA = 5923411
  //LOCMAKERMAD = 5931613
  //LOCMAKERRUKIA = 5938137
  //NCUTHEAVNA50710 = 871
  //POPRANGE0 = 5859454

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
        if( param1 == 1014575 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn), id=ALPHINAUD
            // +Callback Scene00002: Normal(CutScene, FadeIn, AutoFadeIn), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1014564 ) // ACTOR1 = BIGGS
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1014622 ) // ACTOR2 = CID
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1014573 ) // ACTOR3 = WEDGE
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1013100 ) // ACTOR4 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1013102 ) // ACTOR5 = LUCIA
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1013103 ) // ACTOR6 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1014564 ) // ACTOR1 = BIGGS
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1014622 ) // ACTOR2 = CID
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1014573 ) // ACTOR3 = WEDGE
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        if( param1 == 1012064 ) // ACTOR7 = SONUVANU
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=SONUVANU
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012195 ) // ACTOR8 = CID
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=CID
          break;
        }
        if( param1 == 1014573 ) // ACTOR3 = WEDGE
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        if( param1 == 1014564 ) // ACTOR1 = BIGGS
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1013100 ) // ACTOR4 = ALPHINAUD
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013102 ) // ACTOR5 = LUCIA
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1013103 ) // ACTOR6 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Normal(None), id=unknown
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
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00002( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }
  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00002: Normal(CutScene, FadeIn, AutoFadeIn), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 401, -584.1f, -52.4f, -445.3f, 2.88f, false );
    };
    eventMgr().playQuestScene( player, getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00003: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00004: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00005: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00007: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00009: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00010: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00011: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00012: Normal(Talk, TargetCanMove), id=SONUVANU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00014: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00015: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00017: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna507:67184 calling Scene00018: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( HeaVna507 );
