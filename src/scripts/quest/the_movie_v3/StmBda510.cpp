// FFXIVTheMovie.ParserV3.12
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda510 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda510() : Sapphire::ScriptAPI::QuestScript( 68483 ){}; 
  ~StmBda510() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 4 entries
  //SEQ_2, 6 entries
  //SEQ_3, 4 entries
  //SEQ_4, 9 entries
  //SEQ_255, 5 entries

  //ACTIONTIMELINEEVENTQUESTIONHEAD = 669
  //ACTOR0 = 1020232
  //ACTOR1 = 1020233
  //ACTOR2 = 1020234
  //ACTOR3 = 1020519
  //ACTOR4 = 1020523
  //BINDISSE001 = 6850943
  //BINDLYSE001 = 6850944
  //EOBJECT0 = 2007926
  //EOBJECT1 = 2007928
  //EOBJECT10 = 2008193
  //EOBJECT2 = 2007929
  //EOBJECT3 = 2007930
  //EOBJECT4 = 2007927
  //EOBJECT5 = 2008188
  //EOBJECT6 = 2008189
  //EOBJECT7 = 2008190
  //EOBJECT8 = 2008191
  //EOBJECT9 = 2008192
  //EVENTACTION0 = 4
  //EVENTACTION1 = 2
  //EVENTACTION2 = 3
  //ITEM0 = 2002176
  //ITEM1 = 2002177
  //LCUTBGM01 = 465

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
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( param1 == 1020232 ) // ACTOR0 = TSURANUKI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=TSURANUKI
          }
          break;
        }
        if( param1 == 1020233 ) // ACTOR1 = ISSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1020234 ) // ACTOR2 = LYSE
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 2007926 || param1 == 0xF000000000000000/*Ground aoe hack enabled*/ ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            if( type == EVENT_ON_TALK ) Scene00006( quest, player ); // Scene00006: Normal(Inventory), id=unknown
            if( type == EVENT_ON_EVENT_ITEM ) Scene00007( quest, player ); // Scene00007: Normal(QuestGimmickReaction), id=unknown
          }
          break;
        }
        if( param1 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020232 ) // ACTOR0 = TSURANUKI
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8CH max stack ?
      //seq 2 event item ITEM1 = UI8CL max stack 15
      case 2:
      {
        if( param1 == 2007928 ) // EOBJECT1 = unknown
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00012( quest, player ); // Scene00012: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020232 ) // ACTOR0 = TSURANUKI
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 2007929 ) // EOBJECT2 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2007930 ) // EOBJECT3 = unknown
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00019( quest, player ); // Scene00019: Empty(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      //seq 3 event item ITEM1 = UI8BL max stack 15
      case 3:
      {
        if( param1 == 2007927 || param1 == 0xF000000000000000/*Ground aoe hack enabled*/ ) // EOBJECT4 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            if( type == EVENT_ON_TALK ) Scene00020( quest, player ); // Scene00020: Normal(Inventory), id=unknown
            if( type == EVENT_ON_EVENT_ITEM ) Scene00021( quest, player ); // Scene00021: Normal(QuestGimmickReaction), id=unknown
          }
          break;
        }
        if( param1 == 1020232 ) // ACTOR0 = TSURANUKI
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8DL max stack ?
      //seq 4 event item ITEM1 = UI8EH max stack 15
      case 4:
      {
        if( param1 == 2008188 ) // EOBJECT5 = unknown
        {
          if( quest.getUI8DH() != 1 )
          {
            Scene00026( quest, player ); // Scene00026: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008189 ) // EOBJECT6 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00028( quest, player ); // Scene00028: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008190 ) // EOBJECT7 = unknown
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00030( quest, player ); // Scene00030: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1020232 ) // ACTOR0 = TSURANUKI
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 2008191 ) // EOBJECT8 = unknown
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00035( quest, player ); // Scene00035: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008192 ) // EOBJECT9 = unknown
        {
          if( quest.getUI8CH() != 1 )
          {
            Scene00037( quest, player ); // Scene00037: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008193 ) // EOBJECT10 = unknown
        {
          if( quest.getUI8CL() != 1 )
          {
            Scene00039( quest, player ); // Scene00039: Empty(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      //seq 255 event item ITEM1 = UI8BL max stack 15
      case 255:
      {
        if( param1 == 1020232 ) // ACTOR0 = TSURANUKI
        {
          Scene00040( quest, player ); // Scene00040: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00041: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=TSURANUKI
          break;
        }
        if( param1 == 1020233 ) // ACTOR1 = ISSE
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1020234 ) // ACTOR2 = LYSE
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00045( quest, player ); // Scene00045: Normal(Talk, TargetCanMove), id=YUGIRI
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
    quest.setUI8BH( 1 );
  }
  void checkProgressSeq1( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setUI8BH( 0 );
      quest.setSeq( 2 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
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
          quest.setUI8CL( 0 );
          quest.setSeq( 3 );
          quest.setUI8BH( 1 );
          quest.setUI8BL( 15 );
        }
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setUI8BH( 0 );
      quest.setUI8BL( 0 );
      quest.setSeq( 4 );
    }
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8DH() == 1 )
      if( quest.getUI8AL() == 1 )
        if( quest.getUI8BH() == 1 )
          if( quest.getUI8BL() == 1 )
            if( quest.getUI8CH() == 1 )
              if( quest.getUI8CL() == 1 )
              {
                quest.setUI8DH( 0 );
                quest.setUI8AL( 0 );
                quest.setUI8BH( 0 );
                quest.setUI8BL( 0 );
                quest.setUI8CH( 0 );
                quest.setUI8CL( 0 );
                quest.setBitFlag8( 1, false );
                quest.setBitFlag8( 2, false );
                quest.setBitFlag8( 3, false );
                quest.setBitFlag8( 4, false );
                quest.setBitFlag8( 5, false );
                quest.setBitFlag8( 6, false );
                quest.setUI8DL( 0 );
                quest.setUI8EH( 0 );
                quest.setSeq( 255 );
                quest.setUI8BH( 1 );
                quest.setUI8BL( 15 );
              }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=TSURANUKI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00002: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00006: Normal(Inventory), id=unknown" );
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, nullptr );
  }
  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00007: Normal(QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00010: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, UI8BL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00012: Empty(None), id=unknown" );
    quest.setUI8BL( 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
    checkProgressSeq2( quest, player );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00015: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT2, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00017: Empty(None), id=unknown" );
    quest.setUI8AL( 1 );
    quest.setBitFlag8( 2, true );
    checkProgressSeq2( quest, player );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT3, UI8BH = 1, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00019: Empty(None), id=unknown" );
    quest.setUI8BH( 1 );
    quest.setBitFlag8( 3, true );
    checkProgressSeq2( quest, player );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT4, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00020: Normal(Inventory), id=unknown" );
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, nullptr );
  }
  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT4, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00021: Normal(QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00022: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00024: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT5, UI8DH = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00026: Empty(None), id=unknown" );
    quest.setUI8DH( 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
    checkProgressSeq4( quest, player );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT6, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00028: Empty(None), id=unknown" );
    quest.setUI8AL( 1 );
    quest.setBitFlag8( 2, true );
    checkProgressSeq4( quest, player );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT7, UI8BH = 1, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00030: Empty(None), id=unknown" );
    quest.setUI8BH( 1 );
    quest.setBitFlag8( 3, true );
    checkProgressSeq4( quest, player );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00031: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT8, UI8BL = 1, Flag8(4)=True
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00035: Empty(None), id=unknown" );
    quest.setUI8BL( 1 );
    quest.setBitFlag8( 4, true );
    checkProgressSeq4( quest, player );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT9, UI8CH = 1, Flag8(5)=True
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00037: Empty(None), id=unknown" );
    quest.setUI8CH( 1 );
    quest.setBitFlag8( 5, true );
    checkProgressSeq4( quest, player );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT10, UI8CL = 1, Flag8(6)=True
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00039: Empty(None), id=unknown" );
    quest.setUI8CL( 1 );
    quest.setBitFlag8( 6, true );
    checkProgressSeq4( quest, player );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00040: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00041( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 40, HIDE_HOTBAR, callback );
  }
  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00041: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=TSURANUKI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 41, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00042: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00043: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, HIDE_HOTBAR, callback );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00044: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, HIDE_HOTBAR, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda510:68483 calling Scene00045: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 45, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda510 );
