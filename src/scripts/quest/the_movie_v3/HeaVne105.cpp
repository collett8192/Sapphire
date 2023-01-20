// FFXIVTheMovie.ParserV3.10
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVne105 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVne105() : Sapphire::ScriptAPI::QuestScript( 67881 ){}; 
  ~HeaVne105() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_3, 8 entries
  //SEQ_4, 6 entries
  //SEQ_5, 3 entries
  //SEQ_6, 2 entries
  //SEQ_7, 3 entries
  //SEQ_8, 3 entries
  //SEQ_255, 3 entries

  //ACTIONTIMELINEEVENTBASEKNEEL = 1014
  //ACTIONTIMELINEEVENTBASESITRELAX = 789
  //ACTOR0 = 1016815
  //ACTOR1 = 1017736
  //ACTOR10 = 1017873
  //ACTOR11 = 1017868
  //ACTOR12 = 1017869
  //ACTOR13 = 1017870
  //ACTOR14 = 1018112
  //ACTOR15 = 1018111
  //ACTOR16 = 1018113
  //ACTOR17 = 1017739
  //ACTOR18 = 1017740
  //ACTOR19 = 1017741
  //ACTOR2 = 1017737
  //ACTOR20 = 1017742
  //ACTOR21 = 1017743
  //ACTOR22 = 5010000
  //ACTOR23 = 1017744
  //ACTOR24 = 1017745
  //ACTOR25 = 1017746
  //ACTOR3 = 1017865
  //ACTOR4 = 1017866
  //ACTOR5 = 1017867
  //ACTOR6 = 1018109
  //ACTOR7 = 1018110
  //ACTOR8 = 1017871
  //ACTOR9 = 1017872
  //BINDACTOR1 = 6433069
  //BINDACTOR2 = 6433070
  //BINDACTOR3 = 6433683
  //BINDACTOR4 = 6433684
  //BINDACTOR5 = 6433685
  //BINDACTOR6 = 6481755
  //BINDACTOR7 = 6481757
  //EOBJECT0 = 2007458
  //EOBJECT1 = 2007415
  //EOBJECT2 = 2007416
  //EOBJECT3 = 2007460
  //EOBJECT4 = 2007459
  //EOBJECT5 = 2007462
  //EVENTACTIONLOOKOUTMIDDLE = 50
  //EVENTACTIONSEARCH = 1
  //INSTANCEDUNGEON0 = 20005
  //ITEM0 = 2002012
  //LCUTEOBJ1 = 2007461
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1017687
  //LOCACTOR2 = 1017689
  //NCUT01 = 1258

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
        if( param1 == 1016815 ) // ACTOR0 = GABU
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=GABU
          }
          break;
        }
        if( param1 == 1017736 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1017737 ) // ACTOR2 = ALISAIE
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1017865 ) // ACTOR3 = GABU
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=GABU
          }
          break;
        }
        if( param1 == 1017866 ) // ACTOR4 = ALPHINAUD
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1017867 ) // ACTOR5 = ALISAIE
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1018109 ) // ACTOR6 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          break;
        }
        if( param1 == 1018110 ) // ACTOR7 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Empty(None), id=unknown
          break;
        }
        if( param1 == 2007458 ) // EOBJECT0 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 2
      case 2:
      {
        if( param1 == 2007415 ) // EOBJECT1 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, QuestGimmickReaction, ENpcBind), id=unknown
          }
          break;
        }
        if( param1 == 1017866 ) // ACTOR4 = ALPHINAUD
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1017867 ) // ACTOR5 = ALISAIE
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1017865 ) // ACTOR3 = GABU
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=GABU
          break;
        }
        if( param1 == 1018109 ) // ACTOR6 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        if( param1 == 1018110 ) // ACTOR7 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 2
      case 3:
      {
        if( param1 == 2007416 ) // EOBJECT2 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00018( quest, player ); // Scene00018: Normal(Talk, FadeIn, QuestGimmickReaction), id=unknown
          }
          break;
        }
        if( param1 == 1017871 ) // ACTOR8 = GABU
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=GABU
          break;
        }
        if( param1 == 1017872 ) // ACTOR9 = ALPHINAUD
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1017873 ) // ACTOR10 = ALISAIE
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 2007460 ) // EOBJECT3 = unknown
        {
          Scene00023( quest, player ); // Scene00023: Empty(None), id=unknown
          break;
        }
        if( param1 == 1018109 ) // ACTOR6 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Empty(None), id=unknown
          break;
        }
        if( param1 == 1018110 ) // ACTOR7 = unknown
        {
          Scene00025( quest, player ); // Scene00025: Empty(None), id=unknown
          break;
        }
        if( param1 == 2007415 ) // EOBJECT1 = unknown
        {
          Scene00027( quest, player ); // Scene00027: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 2
      case 4:
      {
        if( param1 == 2007459 ) // EOBJECT4 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00028( quest, player ); // Scene00028: Normal(SystemTalk), id=unknown
            // +Callback Scene00029: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1017868 ) // ACTOR11 = GABU
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=GABU
          break;
        }
        if( param1 == 1017869 ) // ACTOR12 = ALPHINAUD
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1017870 ) // ACTOR13 = ALISAIE
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 2007462 ) // EOBJECT5 = unknown
        {
          Scene00034( quest, player ); // Scene00034: Empty(None), id=unknown
          break;
        }
        if( param1 == 2007416 ) // EOBJECT2 = unknown
        {
          Scene00035( quest, player ); // Scene00035: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 2
      case 5:
      {
        if( param1 == 1018112 ) // ACTOR14 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00036( quest, player ); // Scene00036: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00037: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1018111 ) // ACTOR15 = GABU
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=GABU
          break;
        }
        if( param1 == 1018113 ) // ACTOR16 = ALISAIE
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1017739 ) // ACTOR17 = ALISAIE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=ALISAIE
            // +Callback Scene00041: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1017740 ) // ACTOR18 = GABU
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=GABU
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 1017741 ) // ACTOR19 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1017742 ) // ACTOR20 = ALISAIE
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1017743 ) // ACTOR21 = GABU
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=GABU
          break;
        }
        break;
      }
      case 8:
      {
        if( param1 == 1017741 ) // ACTOR19 = ALPHINAUD
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1017742 ) // ACTOR20 = ALISAIE
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1017743 ) // ACTOR21 = GABU
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=GABU
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1017744 ) // ACTOR23 = ALPHINAUD
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1017745 ) // ACTOR24 = ALISAIE
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1017746 ) // ACTOR25 = GABU
        {
          Scene00051( quest, player ); // Scene00051: Normal(Talk, TargetCanMove), id=GABU
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
      quest.setUI8BH( 2 );
    }
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setUI8BH( 0 );
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
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=GABU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00004: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00007: Empty(None), id=unknown" );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00008: Empty(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00010: Empty(None), id=unknown" );
    checkProgressSeq1( quest, player );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00011: Normal(Talk, QuestGimmickReaction, ENpcBind), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00014: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00016: Empty(None), id=unknown" );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT2, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00018: Normal(Talk, FadeIn, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00019: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00023: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00024: Empty(None), id=unknown" );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00025: Empty(None), id=unknown" );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00027: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT4, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00028: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00029( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }
  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT4, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00029: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00030: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00032: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, NONE, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00034: Empty(None), id=unknown" );
    checkProgressSeq4( quest, player );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00035: Empty(None), id=unknown" );
    checkProgressSeq4( quest, player );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR14, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00036: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00037( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 36, NONE, callback );
  }
  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR14, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00037: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 37, NONE, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00038: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, NONE, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00039: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, NONE, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR17, UI8AL = 1, Flag8(1)=True(Todo:5)
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00040: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00041( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 40, NONE, callback );
  }
  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR17, UI8AL = 1, Flag8(1)=True(Todo:5)
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00041: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 5, 0, 0, 0 );
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 41, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00042: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, NONE, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR19, UI8AL = 1, Flag8(1)=True(Todo:6)
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 6, 0, 0, 0 );
      checkProgressSeq7( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 43, NONE, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00044: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, NONE, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_7: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00045: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, NONE, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_8: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, NONE, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_8: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, NONE, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_8: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00048: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, NONE, callback );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00049: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 49, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00050: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 50, NONE, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR25, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne105:67881 calling Scene00051: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 51, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVne105 );
