// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda406 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda406() : Sapphire::ScriptAPI::QuestScript( 68041 ){}; 
  ~StmBda406() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 5 entries
  //SEQ_3, 11 entries
  //SEQ_4, 7 entries
  //SEQ_5, 2 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1020501
  //ACTOR1 = 1020546
  //ACTOR2 = 1020544
  //ACTOR3 = 1019396
  //ACTOR4 = 1020549
  //ACTOR5 = 1021741
  //ACTOR6 = 1021742
  //ACTOR7 = 1021743
  //ACTOR8 = 1021744
  //ACTOR9 = 1020545
  //EOBJECT0 = 2008245
  //EOBJECT1 = 2008246
  //EOBJECT2 = 2008247
  //EOBJECT3 = 2008248
  //EVENTACTION0 = 1
  //EVENTPLAYLIGHT = 914
  //ITEM0 = 2002203
  //LOCBGMEVENTEASTSAD = 489
  //LOCKODOMO1 = 1021969
  //LOCKODOMO2 = 1021970
  //LOCKODOMO3 = 1021971
  //LOCKODOMO4 = 1021972
  //NCUTEVENT04040 = 1439
  //POPRANGE0 = 6975820

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
        if( param1 == 1020501 ) // ACTOR0 = CIRINA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CIRINA
          }
          break;
        }
        if( param1 == 1020546 ) // ACTOR1 = GOSETSU
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020544 ) // ACTOR2 = HIEN
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019396 ) // ACTOR3 = DORBEI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=DORBEI
          }
          break;
        }
        if( param1 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1020546 ) // ACTOR1 = GOSETSU
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020544 ) // ACTOR2 = HIEN
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020549 ) // ACTOR4 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1020546 ) // ACTOR1 = GOSETSU
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020544 ) // ACTOR2 = HIEN
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1019396 ) // ACTOR3 = DORBEI
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 4
      case 3:
      {
        if( param1 == 2008245 ) // EOBJECT0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00014( quest, player ); // Scene00014: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008246 ) // EOBJECT1 = unknown
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00016( quest, player ); // Scene00016: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008247 ) // EOBJECT2 = unknown
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00018( quest, player ); // Scene00018: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 2008248 ) // EOBJECT3 = unknown
        {
          if( !quest.getBitFlag8( 4 ) )
          {
            Scene00020( quest, player ); // Scene00020: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1020549 ) // ACTOR4 = LYSE
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021741 ) // ACTOR5 = 01GIRL02505
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=01GIRL02505
          break;
        }
        if( param1 == 1021742 ) // ACTOR6 = 02BOY02505
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=02BOY02505
          break;
        }
        if( param1 == 1021743 ) // ACTOR7 = 03BOY02505
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=03BOY02505
          break;
        }
        if( param1 == 1021744 ) // ACTOR8 = 04GIRL02505
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=04GIRL02505
          break;
        }
        if( param1 == 1019396 ) // ACTOR3 = DORBEI
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 4
      case 4:
      {
        if( param1 == 1020549 ) // ACTOR4 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00028( quest, player ); // Scene00028: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00029: Normal(Talk, FadeIn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021741 ) // ACTOR5 = 01GIRL02505
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=01GIRL02505
          break;
        }
        if( param1 == 1021742 ) // ACTOR6 = 02BOY02505
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=02BOY02505
          break;
        }
        if( param1 == 1021743 ) // ACTOR7 = 03BOY02505
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=03BOY02505
          break;
        }
        if( param1 == 1021744 ) // ACTOR8 = 04GIRL02505
        {
          Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=04GIRL02505
          break;
        }
        if( param1 == 1019396 ) // ACTOR3 = DORBEI
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1020501 ) // ACTOR0 = CIRINA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=CIRINA
            // +Callback Scene00037: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1019396 ) // ACTOR3 = DORBEI
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020544 ) // ACTOR2 = HIEN
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020546 ) // ACTOR1 = GOSETSU
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020545 ) // ACTOR9 = LYSE
        {
          Scene00041( quest, player ); // Scene00041: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00042( quest, player ); // Scene00042: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1019396 ) // ACTOR3 = DORBEI
        {
          Scene00043( quest, player ); // Scene00043: Normal(Talk, TargetCanMove), id=DORBEI
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
    if( quest.getUI8AL() == 4 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setBitFlag8( 2, false );
      quest.setBitFlag8( 3, false );
      quest.setBitFlag8( 4, false );
      quest.setSeq( 4 );
      quest.setUI8BH( 4 );
    }
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setUI8BH( 0 );
      quest.setSeq( 5 );
    }
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
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
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00002: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00003: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00004: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00005: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00007: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00008: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00009: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00011: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00012: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, UI8AL = 4, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00014: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 4 );
    checkProgressSeq3( quest, player );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, UI8AL = 4, Flag8(2)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00016: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 2, true );
    eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 4 );
    checkProgressSeq3( quest, player );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT2, UI8AL = 4, Flag8(3)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00018: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 3, true );
    eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 4 );
    checkProgressSeq3( quest, player );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT3, UI8AL = 4, Flag8(4)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00020: Empty(None), id=unknown" );
    quest.setUI8AL( quest.getUI8AL() + 1 );
    quest.setBitFlag8( 4, true );
    eventMgr().sendEventNotice( player, getId(), 2, 2, quest.getUI8AL(), 4 );
    checkProgressSeq3( quest, player );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00021: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00022: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00023: Normal(Talk, TargetCanMove), id=01GIRL02505" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00024: Normal(Talk, TargetCanMove), id=02BOY02505" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00025: Normal(Talk, TargetCanMove), id=03BOY02505" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00026: Normal(Talk, TargetCanMove), id=04GIRL02505" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00027: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00028: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00029( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }
  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00029: Normal(Talk, FadeIn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00030: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00031: Normal(Talk, TargetCanMove), id=01GIRL02505" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, HIDE_HOTBAR, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00032: Normal(Talk, TargetCanMove), id=02BOY02505" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, HIDE_HOTBAR, callback );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00033: Normal(Talk, TargetCanMove), id=03BOY02505" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, HIDE_HOTBAR, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00034: Normal(Talk, TargetCanMove), id=04GIRL02505" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 34, HIDE_HOTBAR, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00035: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, HIDE_HOTBAR, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR0, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00036: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00037( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 36, HIDE_HOTBAR, callback );
  }
  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR0, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00037: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 37, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00038: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, HIDE_HOTBAR, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00039: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 39, HIDE_HOTBAR, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00040: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, HIDE_HOTBAR, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00041: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 41, HIDE_HOTBAR, callback );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00042: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 42, HIDE_HOTBAR, callback );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda406:68041 calling Scene00043: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 43, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda406 );
