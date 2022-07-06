// FFXIVTheMovie.ParserV3.9
// param used:
//_ACTOR7 = B
//_ACTOR7B = 3|2
//_ACTOR8 = B
//_ACTOR8B = 3|2
//_ACTOR9 = B
//_ACTOR9B = 3|2
//TODO_REMOVE = 0
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnb104 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVnb104() : Sapphire::ScriptAPI::QuestScript( 67695 ){}; 
  ~HeaVnb104() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 1 entries
  //SEQ_2, 4 entries
  //SEQ_3, 7 entries
  //SEQ_4, 7 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1015992
  //ACTOR1 = 1012422
  //ACTOR10 = 1015994
  //ACTOR11 = 1015995
  //ACTOR12 = 1015996
  //ACTOR13 = 1015997
  //ACTOR2 = 1012423
  //ACTOR3 = 1012405
  //ACTOR4 = 1012406
  //ACTOR5 = 1015993
  //ACTOR6 = 1012138
  //ACTOR7 = 1011916
  //ACTOR8 = 1011917
  //ACTOR9 = 1011922
  //CUTSCENEN01 = 1048
  //EOBJECT0 = 2006610
  //EVENTACTIONWAITING2MIDDLE = 12
  //ITEM0 = 2001899
  //LOCACTOR1 = 1011887
  //LOCACTOR10 = 5860039
  //LOCACTOR11 = 6081187
  //LOCACTOR2 = 1011889
  //LOCACTOR20 = 5860123
  //LOCACTOR21 = 5860124
  //LOCACTOR3 = 6081170
  //POPRANGE0 = 6080829
  //TERRITORYTYPE0 = 463

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
        if( param1 == 1015992 ) // ACTOR0 = KRILE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=KRILE
          }
          break;
        }
        if( param1 == 1012422 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012423 ) // ACTOR2 = YSHTOLA
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 1:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00004( quest, player ); // Scene00004: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( param1 == 1012405 ) // ACTOR3 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1012406 ) // ACTOR4 = YSHTOLA
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1015993 ) // ACTOR5 = KRILE
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1012138 ) // ACTOR6 = MATOYA
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=MATOYA
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8CH max stack 1
      case 3:
      {
        if( param1 == 1011916 ) // ACTOR7 = MARCECHAMP, CB=2
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00009( quest, player ); // Scene00009: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=MARCECHAMP
          }
          else
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=MARCECHAMP
          }
          break;
        }
        if( param1 == 1011917 ) // ACTOR8 = LOUPARD, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00012( quest, player ); // Scene00012: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00013: Normal(Talk, TargetCanMove), id=LOUPARD
          }
          else
          {
            Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=LOUPARD
          }
          break;
        }
        if( param1 == 1011922 ) // ACTOR9 = GRIMOLD, CB=2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00015( quest, player ); // Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00016: Normal(Talk, TargetCanMove), id=GRIMOLD
          }
          else
          {
            Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=GRIMOLD
          }
          break;
        }
        if( param1 == 1015994 ) // ACTOR10 = KRILE
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1015995 ) // ACTOR11 = ALPHINAUD
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1015996 ) // ACTOR12 = YSHTOLA
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012138 ) // ACTOR6 = MATOYA
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=MATOYA
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 1015994 ) // ACTOR10 = KRILE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00022( quest, player ); // Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=KRILE
          }
          break;
        }
        if( param1 == 1015995 ) // ACTOR11 = ALPHINAUD
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1015996 ) // ACTOR12 = YSHTOLA
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1011916 ) // ACTOR7 = MARCECHAMP
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=MARCECHAMP
          break;
        }
        if( param1 == 1011917 ) // ACTOR8 = LOUPARD
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=LOUPARD
          break;
        }
        if( param1 == 1011922 ) // ACTOR9 = GRIMOLD
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=GRIMOLD
          break;
        }
        if( param1 == 1012138 ) // ACTOR6 = MATOYA
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=MATOYA
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 2006610 ) // EOBJECT0 = unknown
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, FadeIn, QuestReward, QuestComplete, ENpcBind), id=unknown
          break;
        }
        if( param1 == 1015997 ) // ACTOR13 = KRILE
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1011916 ) // ACTOR7 = MARCECHAMP
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=MARCECHAMP
          break;
        }
        if( param1 == 1011917 ) // ACTOR8 = LOUPARD
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=LOUPARD
          break;
        }
        if( param1 == 1011922 ) // ACTOR9 = GRIMOLD
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=GRIMOLD
          break;
        }
        if( param1 == 1012138 ) // ACTOR6 = MATOYA
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=MATOYA
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
      quest.setUI8BH( 0 );
      quest.setSeq( 3 );
      quest.setUI8CH( 1 );
    }
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
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
          quest.setUI8CH( 0 );
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
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00007: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00008: Normal(Talk, TargetCanMove), id=MATOYA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8BL = 1, Flag8(1)=True, Branch(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00009: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00010( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }
  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8BL = 1, Flag8(1)=True, Branch(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00010: Normal(Talk, TargetCanMove), id=MARCECHAMP" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }
  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8BL = 1, Flag8(1)=True, Branch(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00011: Normal(Talk, TargetCanMove), id=MARCECHAMP" );
    eventMgr().playQuestScene( player, getId(), 11, NONE, nullptr );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(2)=True, Branch(Todo:3)
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00012: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00013( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }
  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(2)=True, Branch(Todo:3)
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00013: Normal(Talk, TargetCanMove), id=LOUPARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }
  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(2)=True, Branch(Todo:3)
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00014: Normal(Talk, TargetCanMove), id=LOUPARD" );
    eventMgr().playQuestScene( player, getId(), 14, NONE, nullptr );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, UI8BH = 1, Flag8(3)=True, Branch(Todo:4)
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00016( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }
  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, UI8BH = 1, Flag8(3)=True, Branch(Todo:4)
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00016: Normal(Talk, TargetCanMove), id=GRIMOLD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 3, true );
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }
  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, UI8BH = 1, Flag8(3)=True, Branch(Todo:4)
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00017: Normal(Talk, TargetCanMove), id=GRIMOLD" );
    eventMgr().playQuestScene( player, getId(), 17, NONE, nullptr );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00018: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00020: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00021: Normal(Talk, TargetCanMove), id=MATOYA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, UI8AL = 1, Flag8(1)=True(Todo:5)
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 5, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, NONE, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00025: Normal(Talk, TargetCanMove), id=MARCECHAMP" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00026: Normal(Talk, TargetCanMove), id=LOUPARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00027: Normal(Talk, TargetCanMove), id=GRIMOLD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00028: Normal(Talk, TargetCanMove), id=MATOYA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00030: Normal(Talk, FadeIn, QuestReward, QuestComplete, ENpcBind), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00031: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00032: Normal(Talk, TargetCanMove), id=MARCECHAMP" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, NONE, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00033: Normal(Talk, TargetCanMove), id=LOUPARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, NONE, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00034: Normal(Talk, TargetCanMove), id=GRIMOLD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, NONE, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb104:67695 calling Scene00035: Normal(Talk, TargetCanMove), id=MATOYA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnb104 );
