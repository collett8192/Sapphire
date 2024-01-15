// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda501 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda501() : Sapphire::ScriptAPI::QuestScript( 68055 ){}; 
  ~StmBda501() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1020519
  //ACTOR1 = 1020520
  //ACTOR2 = 1020521
  //ACTOR3 = 1020523
  //ACTOR4 = 1020522
  //ACTOR5 = 1020524
  //ACTOR6 = 1023084
  //ACTOR7 = 1020622
  //BINDYUGIRI001 = 6843952
  //NCUTEVENT05010 = 1449
  //POPRANGE0 = 6973936

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
        if( param1 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00002: Normal(CutScene, QuestAccept), id=unknown
          }
          break;
        }
        if( param1 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020521 ) // ACTOR2 = LYSE
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020523 ) // ACTOR3 = YUGIRI
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020522 ) // ACTOR4 = GOSETSU
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020524 ) // ACTOR5 = HIEN
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020524 ) // ACTOR5 = HIEN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020521 ) // ACTOR2 = LYSE
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020523 ) // ACTOR3 = YUGIRI
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020522 ) // ACTOR4 = GOSETSU
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020523 ) // ACTOR3 = YUGIRI
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020521 ) // ACTOR2 = LYSE
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020522 ) // ACTOR4 = GOSETSU
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020524 ) // ACTOR5 = HIEN
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1023084 ) // ACTOR6 = TATARU
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020521 ) // ACTOR2 = LYSE
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020522 ) // ACTOR4 = GOSETSU
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020524 ) // ACTOR5 = HIEN
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020622 ) // ACTOR7 = HANCOCK
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=HANCOCK
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
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00001: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00002( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }
  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00002: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00007: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00008: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00011: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00012: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00014: Normal(Talk, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00015: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00017: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00018: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00019: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00022: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00023: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00024: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda501:68055 calling Scene00025: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda501 );
