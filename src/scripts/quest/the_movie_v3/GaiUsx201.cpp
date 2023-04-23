// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class GaiUsx201 : public Sapphire::ScriptAPI::QuestScript
{
public:
  GaiUsx201() : Sapphire::ScriptAPI::QuestScript( 67245 ){}; 
  ~GaiUsx201() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_4, 1 entries
  //SEQ_5, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1007753
  //ACTOR1 = 1006725
  //ENEMY0 = 7625695
  //ENEMY1 = 7625884
  //ENEMY2 = 7625951
  //ENEMY3 = 7626039
  //EOBJECT0 = 2000075
  //EOBJECT1 = 2000076
  //EOBJECT2 = 2000077
  //EOBJECT3 = 2000078
  //EVENTACTION0 = 50
  //EVENTACTION1 = 1
  //ITEM0 = 2002484
  //ITEM1 = 2002485
  //ITEM2 = 2002486
  //ITEM3 = 2002487
  //LOCACTOR0 = 1003855
  //LOCPOSCAM1 = 4509927
  //NCUTEVENTGAIUSD2011 = 459
  //QSTACCEPTCHECK = 66735

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NERO
        break;
      }
      case 1:
      {
        if( param1 == 1006725 ) // ACTOR1 = RAMMBROES
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=RAMMBROES
            // +Callback Scene00003: Normal(CutScene, AutoFadeIn), id=unknown
            // +Callback Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=RAMMBROES
          }
          break;
        }
        if( param1 == 1007753 ) // ACTOR0 = NERO
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=NERO
          break;
        }
        break;
      }
      case 2:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=RAMMBROES
        break;
      }
      //seq 3 event item ITEM0 = UI8BL max stack 1
      //seq 3 event item ITEM1 = UI8CH max stack 1
      case 3:
      {
        if( param1 == 2000075 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT0
        if( param1 == 7625695 ) // ENEMY0 = unknown
        {
          Scene00010( quest, player ); // Scene00010: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2000076 ) // EOBJECT1 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00012( quest, player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        // BNpcHack credit moved to EOBJECT1
        if( param1 == 7625884 ) // ENEMY1 = unknown
        {
          Scene00014( quest, player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      //seq 4 event item ITEM1 = UI8BL max stack 1
      case 4:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00015( quest, player ); // Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00016: Normal(Talk, TargetCanMove), id=RAMMBROES
        break;
      }
      //seq 5 event item ITEM2 = UI8BL max stack 1
      //seq 5 event item ITEM3 = UI8CH max stack 1
      case 5:
      {
        if( param1 == 2000077 ) // EOBJECT2 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7625951 ) // ENEMY2 = unknown
        {
          Scene00020( quest, player ); // Scene00020: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2000078 ) // EOBJECT3 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7626039 ) // ENEMY3 = unknown
        {
          Scene00024( quest, player ); // Scene00024: Normal(Message, PopBNpc), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM2 = UI8BH max stack 1
      //seq 255 event item ITEM3 = UI8BL max stack 1
      case 255:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00025( quest, player ); // Scene00025: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAMMBROES
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
    quest.setSeq( 3 );
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8BH() == 1 )
      if( quest.getUI8AL() == 1 )
      {
        quest.setUI8BH( 0 );
        quest.setUI8AL( 0 );
        quest.setBitFlag8( 1, false );
        quest.setBitFlag8( 2, false );
        quest.setUI8BL( 0 );
        quest.setUI8CH( 0 );
        quest.setSeq( 4 );
        quest.setUI8BH( 1 );
        quest.setUI8BL( 1 );
      }
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    quest.setUI8BH( 0 );
    quest.setUI8BL( 0 );
    quest.setSeq( 5 );
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    quest.setBitFlag8( 1, false );
    quest.setBitFlag8( 2, false );
    quest.setUI8BL( 0 );
    quest.setUI8CH( 0 );
    quest.setSeq( 255 );
    quest.setUI8BH( 1 );
    quest.setUI8BL( 1 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown" );
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
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NERO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=RAMMBROES" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00003( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00003: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00004( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00005: Normal(Talk, TargetCanMove), id=NERO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00006: Normal(Talk, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT0, UI8BH = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_3: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, UI8AL = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_4: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00016( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }
  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_4: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00016: Normal(Talk, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT2, <No Var>, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00018: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setBitFlag8( 1, true );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_5: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00020: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT3, <No Var>, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00022: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setBitFlag8( 2, true );
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_5: ENEMY3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00024: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00025: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00026( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }
  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsx201:67245 calling Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( GaiUsx201 );
