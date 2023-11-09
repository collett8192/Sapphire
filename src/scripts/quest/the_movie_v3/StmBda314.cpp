// FFXIVTheMovie.ParserV3.11
// param used:
//_ACTOR2 = B
//_ACTOR2B = 1|2
//_ACTOR3 = B
//_ACTOR3B = 1|2
//_ACTOR4 = B
//_ACTOR4B = 1|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda314 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda314() : Sapphire::ScriptAPI::QuestScript( 68026 ){}; 
  ~StmBda314() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1019988
  //ACTOR1 = 1019989
  //ACTOR2 = 1019990
  //ACTOR3 = 1019991
  //ACTOR4 = 1019992
  //ACTOR5 = 1019993
  //ACTOR6 = 1019947
  //BINDACTOR0 = 6836865
  //CUTSCENEN01 = 1421
  //EVENTACTION0 = 26

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
        if( param1 == 1019988 ) // ACTOR0 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=LYSE
          }
          break;
        }
        if( param1 == 1019989 ) // ACTOR1 = ALISAIE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1019990 ) // ACTOR2 = VILLAGERA02489
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=VILLAGERA02489
          break;
        }
        if( param1 == 1019991 ) // ACTOR3 = VILLAGERB02489
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=VILLAGERB02489
          break;
        }
        if( param1 == 1019992 ) // ACTOR4 = PIRATE02481
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=PIRATE02481
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019990 ) // ACTOR2 = VILLAGERA02489, CB=2
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=VILLAGERA02489
          }
          else
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=VILLAGERA02489
          }
          break;
        }
        if( param1 == 1019991 ) // ACTOR3 = VILLAGERB02489, CB=2
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=VILLAGERB02489
          }
          else
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=VILLAGERB02489
          }
          break;
        }
        if( param1 == 1019992 ) // ACTOR4 = PIRATE02481, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=PIRATE02481
          }
          else
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=PIRATE02481
          }
          break;
        }
        if( param1 == 1019993 ) // ACTOR5 = LYSE
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1019947 ) // ACTOR6 = PIRATE02490
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=PIRATE02490
          break;
        }
        if( param1 == 1019989 ) // ACTOR1 = ALISAIE
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019989 ) // ACTOR1 = ALISAIE
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE
          // +Callback Scene00018: Normal(CutScene, AutoFadeIn), id=unknown
          // +Callback Scene00019: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1019993 ) // ACTOR5 = LYSE
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1019947 ) // ACTOR6 = PIRATE02490
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=PIRATE02490
          break;
        }
        if( param1 == 1019990 ) // ACTOR2 = VILLAGERA02489
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=VILLAGERA02489
          break;
        }
        if( param1 == 1019991 ) // ACTOR3 = VILLAGERB02489
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=VILLAGERB02489
          break;
        }
        if( param1 == 1019992 ) // ACTOR4 = PIRATE02481
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=PIRATE02481
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
    if( quest.getUI8BH() == 2 )
      if( quest.getUI8AL() == 1 )
      {
        quest.setUI8BH( 0 );
        quest.setUI8AL( 0 );
        quest.setBitFlag8( 1, false );
        quest.setBitFlag8( 2, false );
        quest.setBitFlag8( 3, false );
        quest.setSeq( 255 );
      }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00003: Normal(Talk, TargetCanMove), id=VILLAGERA02489" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00004: Normal(Talk, TargetCanMove), id=VILLAGERB02489" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00005: Normal(Talk, TargetCanMove), id=PIRATE02481" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8BH = 2, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00007: Normal(Talk, TargetCanMove), id=VILLAGERA02489" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( quest.getUI8BH() + 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }
  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8BH = 2, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00008: Normal(Talk, TargetCanMove), id=VILLAGERA02489" );
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, nullptr );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8BH = 2, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00010: Normal(Talk, TargetCanMove), id=VILLAGERB02489" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( quest.getUI8BH() + 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }
  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8BH = 2, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00011: Normal(Talk, TargetCanMove), id=VILLAGERB02489" );
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, nullptr );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00012: Normal(Talk, TargetCanMove), id=PIRATE02481" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }
  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00013: Normal(Talk, TargetCanMove), id=PIRATE02481" );
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, nullptr );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00014: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00015: Normal(Talk, TargetCanMove), id=PIRATE02490" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00018( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }
  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00018: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00019( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00019: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00020: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00021: Normal(Talk, TargetCanMove), id=PIRATE02490" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00022: Normal(Talk, TargetCanMove), id=VILLAGERA02489" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00023: Normal(Talk, TargetCanMove), id=VILLAGERB02489" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda314:68026 calling Scene00024: Normal(Talk, TargetCanMove), id=PIRATE02481" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda314 );
