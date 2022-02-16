// FFXIVTheMovie.ParserV3.9
// param used:
//EOBJECT0 = dummy0
//EOBJECT1 = dummy1
//EOBJECT2 = dummy2
//EOBJECT3 = dummy3
//SCENE_8 = dummy0
//SCENE_10 = dummy1
//SCENE_12 = dummy2
//SCENE_24 = dummy3
//WARP_SCENE24 = 402|-644.12|-176.45|-583.89|0|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna702 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna702() : Sapphire::ScriptAPI::QuestScript( 67200 ){}; 
  ~HeaVna702() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 8 entries
  //SEQ_2, 5 entries
  //SEQ_3, 6 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1012792
  //ACTOR1 = 1013268
  //ACTOR10 = 1013266
  //ACTOR11 = 1015137
  //ACTOR12 = 1015135
  //ACTOR13 = 1015136
  //ACTOR14 = 1015134
  //ACTOR2 = 1012789
  //ACTOR3 = 1012790
  //ACTOR4 = 1012791
  //ACTOR5 = 1012793
  //ACTOR6 = 1014675
  //ACTOR7 = 1013267
  //ACTOR8 = 1013264
  //ACTOR9 = 1013265
  //CUTSCENEN01 = 891
  //CUTSCENEN02 = 892
  //EOBJECT0 = 2006236
  //EOBJECT1 = 2006237
  //EOBJECT2 = 2006238
  //EOBJECT3 = 2005565
  //EVENTACTIONLOOKOUTMIDDLE = 50
  //LOCACTOR0 = 5867072
  //LOCACTOR1 = 5867073
  //LOCACTOR10 = 5867471
  //LOCACTOR11 = 5867474
  //LOCACTOR12 = 5867472
  //LOCACTOR2 = 5867074
  //LOCACTOR20 = 5938230
  //LOCACTOR21 = 5938226
  //LOCACTOR3 = 5867076
  //LOCACTOR4 = 5867468
  //LOCQUEST0 = 66849
  //POPRANGE0 = 5932751

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
        if( param1 == 1012792 ) // ACTOR0 = CID
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=CID
          }
          break;
        }
        if( param1 == 1013268 ) // ACTOR1 = WEDGE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        if( param1 == 1012789 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012790 ) // ACTOR3 = ESTINIEN
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012791 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012793 ) // ACTOR5 = BIGGS
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2006236 ) // EOBJECT0 = dummy0
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, ENpcBind), id=dummy0
          }
          break;
        }
        if( param1 == 2006237 ) // EOBJECT1 = dummy1
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, ENpcBind), id=dummy1
          }
          break;
        }
        if( param1 == 2006238 ) // EOBJECT2 = dummy2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00012( quest, player ); // Scene00012: Normal(Talk, ENpcBind), id=dummy2
          }
          break;
        }
        if( param1 == 1014675 ) // ACTOR6 = CID
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1013267 ) // ACTOR7 = BIGGS
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1013264 ) // ACTOR8 = ALPHINAUD
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013265 ) // ACTOR9 = ESTINIEN
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013266 ) // ACTOR10 = YSHTOLA
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1014675 ) // ACTOR6 = CID
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=CID
          }
          break;
        }
        if( param1 == 1013267 ) // ACTOR7 = BIGGS
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1013264 ) // ACTOR8 = ALPHINAUD
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013265 ) // ACTOR9 = ESTINIEN
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013266 ) // ACTOR10 = YSHTOLA
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2005565 ) // EOBJECT3 = dummy3
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00024( quest, player ); // Scene00024: Normal(CutScene), id=dummy3
          }
          break;
        }
        if( param1 == 1014675 ) // ACTOR6 = CID
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1013267 ) // ACTOR7 = BIGGS
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1013264 ) // ACTOR8 = ALPHINAUD
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013265 ) // ACTOR9 = ESTINIEN
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013266 ) // ACTOR10 = YSHTOLA
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1014675 ) // ACTOR6 = CID
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove, ENpcBind), id=CID
          // +Callback Scene00031: Normal(CutScene), id=unknown
          // +Callback Scene00032: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1015137 ) // ACTOR11 = GUIDANCESYSTEM
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM
          break;
        }
        if( param1 == 1015135 ) // ACTOR12 = BIGGS
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1015136 ) // ACTOR13 = WEDGE
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        if( param1 == 1015134 ) // ACTOR14 = ALPHINAUD
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013265 ) // ACTOR9 = ESTINIEN
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013266 ) // ACTOR10 = YSHTOLA
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=YSHTOLA
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
    if( quest.getUI8BL() == 1 )
      if( quest.getUI8AL() == 1 )
        if( quest.getUI8BH() == 1 )
        {
          quest.setUI8BL( 0 );
          quest.setUI8AL( 0 );
          quest.setUI8BH( 0 );
          quest.setBitFlag8( 1, false );
          quest.setBitFlag8( 2, false );
          quest.setBitFlag8( 3, false );
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
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00002: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00004: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00006: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8BL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00008: Normal(Talk, ENpcBind), id=dummy0" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT1, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00010: Normal(Talk, ENpcBind), id=dummy1" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT2, UI8BH = 1, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00012: Normal(Talk, ENpcBind), id=dummy2" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00013: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00014: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00016: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00017: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00018: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00019: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00021: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT3, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00024: Normal(CutScene), id=dummy3" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 402, -644.12f, -176.45f, -583.89f, 0.0f, false );
    };
    eventMgr().playQuestScene( player, getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00025: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00026: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00028: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00030: Normal(Talk, TargetCanMove, ENpcBind), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00031( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }
  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00031: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00032( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 31, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00032: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 32, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00033: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, NONE, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00034: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, NONE, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00035: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, NONE, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, NONE, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00037: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, NONE, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna702:67200 calling Scene00038: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna702 );
