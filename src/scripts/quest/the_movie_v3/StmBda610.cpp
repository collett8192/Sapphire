// FFXIVTheMovie.ParserV3.12
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda610 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda610() : Sapphire::ScriptAPI::QuestScript( 68072 ){}; 
  ~StmBda610() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1020630
  //ACTOR1 = 1020608
  //ACTOR2 = 1020406
  //ACTOR3 = 1020407
  //CUTSCENEN01 = 1470
  //CUTSCENEN02 = 1471
  //CUTSCENEN03 = 1472
  //ENEMY0 = 7021918
  //ENEMY1 = 7021919
  //ENEMY2 = 7021920
  //ENEMY3 = 7021921
  //EOBJECT0 = 2008202
  //EOBJECT1 = 2008203
  //EVENTACTION0 = 50
  //EVENTACTION1 = 1
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALISAIE
        break;
      }
      case 1:
      {
        if( param1 == 2008202 ) // EOBJECT0 = unknown
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00003( quest, player ); // Scene00003: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT0
        if( param1 == 7021918 ) // ENEMY0 = unknown
        {
          Scene00005( quest, player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7021919 ) // ENEMY1 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2008203 ) // EOBJECT1 = unknown
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT1
        if( param1 == 7021920 ) // ENEMY2 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7021921 ) // ENEMY3 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Normal(Message, PopBNpc), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020608 ) // ACTOR1 = ALISAIE
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
          // +Callback Scene00015: Normal(CutScene, AutoFadeIn), id=unknown
          // +Callback Scene00016: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020406 ) // ACTOR2 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          break;
        }
        if( param1 == 1020407 ) // ACTOR3 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Empty(None), id=unknown
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
      if( quest.getUI8AL() == 2 )
      {
        quest.setUI8BH( 0 );
        quest.setUI8AL( 0 );
        quest.setBitFlag8( 1, false );
        quest.setBitFlag8( 2, false );
        quest.setSeq( 255 );
      }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda610:68072 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, HIDE_HOTBAR, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda610:68072 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8BH = 2, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda610:68072 calling Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 2 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8BH(), 2 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda610:68072 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda610:68072 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT1, UI8AL = 2, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda610:68072 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 2 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda610:68072 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ENEMY3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda610:68072 calling Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda610:68072 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00015( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }
  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda610:68072 calling Scene00015: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00016( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda610:68072 calling Scene00016: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      player.finishQuest( getId(), result.getResult( 1 ) );
    };
    eventMgr().playQuestScene( player, getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda610:68072 calling Scene00017: Empty(None), id=unknown" );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda610:68072 calling Scene00018: Empty(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda610 );
