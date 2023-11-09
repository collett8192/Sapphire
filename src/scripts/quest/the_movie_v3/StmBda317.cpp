// FFXIVTheMovie.ParserV3.11
// param used:
//_ACTOR5 = B
//_ACTOR5B = 2|2
//_ACTOR6 = B
//_ACTOR6B = 2|2
//_ACTOR7 = B
//_ACTOR7B = 2|2
//_ACTOR8 = B
//_ACTOR8B = 2|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda317 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda317() : Sapphire::ScriptAPI::QuestScript( 68029 ){}; 
  ~StmBda317() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 2 entries
  //SEQ_2, 4 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1020011
  //ACTOR1 = 1020010
  //ACTOR2 = 1020017
  //ACTOR3 = 1020012
  //ACTOR4 = 1020013
  //ACTOR5 = 1020015
  //ACTOR6 = 1019263
  //ACTOR7 = 1022719
  //ACTOR8 = 1019259
  //BINDACTOR0 = 6782229
  //LOCACTOR0 = 1018509

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
        if( param1 == 1020011 ) // ACTOR0 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1020010 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020017 ) // ACTOR2 = RESISTANCE02492
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=RESISTANCE02492
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020012 ) // ACTOR3 = YUGIRI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove, ENpcBind), id=YUGIRI
          }
          break;
        }
        if( param1 == 1020013 ) // ACTOR4 = LYSE
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020015 ) // ACTOR5 = MIYAMA, CB=2
        {
          if( quest.getUI8CH() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=MIYAMA
          }
          else
          {
            Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=MIYAMA
          }
          break;
        }
        if( param1 == 1019263 ) // ACTOR6 = HONAMI, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=HONAMI
          }
          else
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=HONAMI
          }
          break;
        }
        if( param1 == 1022719 ) // ACTOR7 = CHIGUSA, CB=2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove, Menu, CanCancel), id=CHIGUSA
          }
          else
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=CHIGUSA
          }
          break;
        }
        if( param1 == 1019259 ) // ACTOR8 = MASATSUCHI, CB=2
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=MASATSUCHI
          }
          else
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=MASATSUCHI
          }
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020012 ) // ACTOR3 = YUGIRI
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=YUGIRI
          break;
        }
        if( param1 == 1020013 ) // ACTOR4 = LYSE
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020015 ) // ACTOR5 = MIYAMA
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=MIYAMA
          break;
        }
        if( param1 == 1019263 ) // ACTOR6 = HONAMI
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=HONAMI
          break;
        }
        if( param1 == 1022719 ) // ACTOR7 = CHIGUSA
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=CHIGUSA
          break;
        }
        if( param1 == 1019259 ) // ACTOR8 = MASATSUCHI
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=MASATSUCHI
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
    if( quest.getUI8CH() == 1 )
      if( quest.getUI8AL() == 1 )
        if( quest.getUI8BH() == 1 )
          if( quest.getUI8BL() == 1 )
          {
            quest.setUI8CH( 0 );
            quest.setUI8AL( 0 );
            quest.setUI8BH( 0 );
            quest.setUI8BL( 0 );
            quest.setBitFlag8( 1, false );
            quest.setBitFlag8( 2, false );
            quest.setBitFlag8( 3, false );
            quest.setBitFlag8( 4, false );
            quest.setSeq( 255 );
          }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00003: Normal(Talk, TargetCanMove), id=RESISTANCE02492" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00004: Normal(Talk, TargetCanMove, ENpcBind), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00005: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, UI8CH = 1, Flag8(1)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00006: Normal(Talk, TargetCanMove), id=MIYAMA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8CH( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }
  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, UI8CH = 1, Flag8(1)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00007: Normal(Talk, TargetCanMove), id=MIYAMA" );
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, nullptr );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00008: Normal(Talk, TargetCanMove), id=HONAMI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }
  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00009: Normal(Talk, TargetCanMove), id=HONAMI" );
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, nullptr );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00010: Normal(Talk, TargetCanMove, Menu, CanCancel), id=CHIGUSA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        quest.setUI8BH( 1 );
        quest.setBitFlag8( 3, true );
        checkProgressSeq2( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }
  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00011: Normal(Talk, TargetCanMove), id=CHIGUSA" );
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, nullptr );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, UI8BL = 1, Flag8(4)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00012: Normal(Talk, TargetCanMove), id=MASATSUCHI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 4, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }
  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, UI8BL = 1, Flag8(4)=True, Branch
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00013: Normal(Talk, TargetCanMove), id=MASATSUCHI" );
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, nullptr );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=YUGIRI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00015: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00016: Normal(Talk, TargetCanMove), id=MIYAMA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00017: Normal(Talk, TargetCanMove), id=HONAMI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00018: Normal(Talk, TargetCanMove), id=CHIGUSA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda317:68029 calling Scene00019: Normal(Talk, TargetCanMove), id=MASATSUCHI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda317 );
