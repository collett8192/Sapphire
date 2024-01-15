// FFXIVTheMovie.ParserV3.11
// fix condition in seq1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda509 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda509() : Sapphire::ScriptAPI::QuestScript( 68482 ){}; 
  ~StmBda509() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 7 entries
  //SEQ_2, 6 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1023084
  //ACTOR1 = 1020520
  //ACTOR2 = 1020222
  //ACTOR3 = 1020221
  //ACTOR4 = 1020223
  //ACTOR5 = 1020622
  //ACTOR6 = 1020224
  //ACTOR7 = 1020225
  //ACTOR8 = 1020519
  //ACTOR9 = 1020523
  //BINDHANCOCK001 = 7021290
  //ITEM0 = 2002379
  //ITEM1 = 2002174
  //ITEM2 = 2002175
  //LCUTSE0 = 39
  //LCUTSE1 = 40

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
      //seq 0 event item ITEM0 = UI8BH max stack 1
      case 0:
      {
        if( param1 == 1023084 ) // ACTOR0 = TATARU
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=TATARU
          }
          break;
        }
        if( param1 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      //seq 1 event item ITEM1 = UI8CH max stack 1
      //seq 1 event item ITEM0 = UI8CL max stack 1
      case 1:
      {
        if( param1 == 1020222 ) // ACTOR2 = MANC02946
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00003( quest, player ); // Scene00003: NpcTrade(Talk), id=unknown
            // +Callback Scene00004: Normal(Talk, TargetCanMove), id=MANC02946
          }
          break;
        }
        if( param1 == 1020221 ) // ACTOR3 = MANA02946
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00006: Normal(Talk, TargetCanMove, CanCancel), id=MANA02946
          }
          break;
        }
        if( param1 == 1020223 ) // ACTOR4 = MANB02946
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00007( quest, player ); // Scene00007: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00008: Normal(Talk, TargetCanMove, CanCancel), id=MANB02946
          }
          break;
        }
        if( param1 == 1020622 ) // ACTOR5 = HANCOCK
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020224 ) // ACTOR6 = MAND02946
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=MAND02946
          break;
        }
        if( param1 == 1020225 ) // ACTOR7 = TATARU
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      //seq 2 event item ITEM1 = UI8BH max stack 1
      //seq 2 event item ITEM2 = UI8BL max stack 1
      case 2:
      {
        if( param1 == 1023084 ) // ACTOR0 = TATARU
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00013( quest, player ); // Scene00013: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00014: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=TATARU
          }
          break;
        }
        if( param1 == 1020622 ) // ACTOR5 = HANCOCK
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020221 ) // ACTOR3 = MANA02946
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=MANA02946
          break;
        }
        if( param1 == 1020222 ) // ACTOR2 = MANC02946
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=MANC02946
          break;
        }
        if( param1 == 1020223 ) // ACTOR4 = MANB02946
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=MANB02946
          break;
        }
        break;
      }
      //seq 255 event item ITEM2 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1020519 ) // ACTOR8 = ALPHINAUD
        {
          Scene00020( quest, player ); // Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020622 ) // ACTOR5 = HANCOCK
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1023084 ) // ACTOR0 = TATARU
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020523 ) // ACTOR9 = YUGIRI
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI
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
    quest.setUI8CH( 1 );
    quest.setUI8CL( 1 );
  }
  void checkProgressSeq1( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8BL() == 1 )
    //  if( quest.getUI8AL() == 1 )
    //    if( quest.getUI8BH() == 1 )
        {
          quest.setUI8BL( 0 );
          quest.setUI8AL( 0 );
          quest.setUI8BH( 0 );
          quest.setBitFlag8( 1, false );
          quest.setBitFlag8( 2, false );
          quest.setBitFlag8( 3, false );
          quest.setUI8CH( 0 );
          quest.setUI8CL( 0 );
          quest.setSeq( 2 );
          quest.setUI8BH( 1 );
          quest.setUI8BL( 1 );
        }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setUI8BH( 0 );
      quest.setUI8BL( 0 );
      quest.setSeq( 255 );
      quest.setUI8BH( 1 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8BL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00003: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00004( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }
  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8BL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00004: Normal(Talk, TargetCanMove), id=MANC02946" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00005: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00006( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }
  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00006: Normal(Talk, TargetCanMove, CanCancel), id=MANA02946" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 2, true );
        checkProgressSeq1( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8BH = 1, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00007: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00008( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }
  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8BH = 1, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00008: Normal(Talk, TargetCanMove, CanCancel), id=MANB02946" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        quest.setUI8BH( 1 );
        quest.setBitFlag8( 3, true );
        checkProgressSeq1( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00009: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00011: Normal(Talk, TargetCanMove), id=MAND02946" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00012: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00013: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00014( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }
  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00014: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00015: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00017: Normal(Talk, TargetCanMove), id=MANA02946" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00018: Normal(Talk, TargetCanMove), id=MANC02946" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00019: Normal(Talk, TargetCanMove), id=MANB02946" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00021( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }
  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00022: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00023: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda509:68482 calling Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda509 );
