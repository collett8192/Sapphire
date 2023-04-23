// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class GaiUsd202 : public Sapphire::ScriptAPI::QuestScript
{
public:
  GaiUsd202() : Sapphire::ScriptAPI::QuestScript( 66736 ){}; 
  ~GaiUsd202() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_4, 4 entries
  //SEQ_5, 2 entries
  //SEQ_6, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006725
  //ACTOR1 = 1004093
  //ACTOR2 = 1007755
  //ACTOR3 = 1007756
  //ACTOR4 = 1007757
  //ACTOR5 = 1007758
  //ACTOR6 = 1007759
  //EOBJECT0 = 2002892
  //EVENTACTIONPROCESSLONG = 17
  //EVENTACTIONRESCUEUNDERMIDDLE = 35
  //EVENTREACTIONROEGAM = 777
  //ITEM0 = 2001099
  //ITEM1 = 2001097
  //ITEM2 = 2001098
  //LOCACTION1 = 1005
  //LOCACTION2 = 990
  //LOCACTOR0 = 1002280
  //LOCACTOR1 = 1003836
  //LOCACTOR2 = 1008298
  //LOCACTOR3 = 1003855
  //LOCEOBJ1 = 2003058
  //LOCFACE0 = 604
  //LOCFACE1 = 605
  //LOCPOSACTOR0 = 4510539
  //LOCPOSACTOR1 = 3643124
  //LOCPOSACTOR2 = 4510880
  //LOCPOSACTOR3 = 4510881
  //LOCPOSEOBJ1 = 4520859
  //LOCSE1 = 51
  //POPRANGE0 = 4585912

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
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RAMMBROES
        break;
      }
      //seq 1 event item ITEM1 = UI8BH max stack 1
      //seq 1 event item ITEM0 = UI8BL max stack 1
      case 1:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00002( quest, player ); // Scene00002: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00003: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=SERENDIPITY
        break;
      }
      //seq 2 event item ITEM1 = UI8BH max stack 1
      case 2:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=BIGGS
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 1007756 ) // ACTOR3 = NPC
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=NPC
          }
          break;
        }
        if( param1 == 1007757 ) // ACTOR4 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Empty(None), id=unknown
          break;
        }
        if( param1 == 1007758 ) // ACTOR5 = unknown
        {
          Scene00007( quest, player ); // Scene00007: Empty(None), id=unknown
          break;
        }
        if( param1 == 1007755 ) // ACTOR2 = BIGGS
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        break;
      }
      //seq 4 event item ITEM1 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 1007759 ) // ACTOR6 = WEDGE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, FadeIn, TargetCanMove), id=WEDGE
          }
          break;
        }
        if( param1 == 1007756 ) // ACTOR3 = NPC
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=NPC
          break;
        }
        if( param1 == 1007757 ) // ACTOR4 = unknown
        {
          Scene00012( quest, player ); // Scene00012: Empty(None), id=unknown
          break;
        }
        if( param1 == 1007758 ) // ACTOR5 = unknown
        {
          Scene00013( quest, player ); // Scene00013: Empty(None), id=unknown
          break;
        }
        break;
      }
      //seq 5 event item ITEM1 = UI8BH max stack 1
      //seq 5 event item ITEM2 = UI8BL max stack 1
      case 5:
      {
        if( param1 == 2002892 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          }
          break;
        }
        if( param1 == 1007759 ) // ACTOR6 = WEDGE
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      //seq 6 event item ITEM1 = UI8BH max stack 1
      //seq 6 event item ITEM2 = UI8BL max stack 1
      case 6:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00017( quest, player ); // Scene00017: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00018: Normal(Talk, NpcDespawn, TargetCanMove), id=WEDGE
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 1
      //seq 255 event item ITEM2 = UI8BL max stack 1
      case 255:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00019( quest, player ); // Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAMMBROES
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
    quest.setUI8BL( 1 );
  }
  void checkProgressSeq1( World::Quest& quest, Entity::Player& player )
  {
    quest.setUI8BL( 0 );
    quest.setSeq( 2 );
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 3 );
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
    }
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 6 );
      quest.setUI8BH( 1 );
      quest.setUI8BL( 1 );
    }
  }
  void checkProgressSeq6( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>(Todo:0)
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00002: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00003( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }
  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>(Todo:0)
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=SERENDIPITY" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>(Todo:1)
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00004: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00005: Normal(Talk, TargetCanMove), id=NPC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00006: Empty(None), id=unknown" );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00007: Empty(None), id=unknown" );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00008: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00010: Normal(Talk, FadeIn, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00011: Normal(Talk, TargetCanMove), id=NPC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00012: Empty(None), id=unknown" );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00013: Empty(None), id=unknown" );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_5: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00015: Empty(None), id=unknown" );
    quest.setUI8AL( 1 );
    quest.setBitFlag8( 1, true );
    eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
    checkProgressSeq5( quest, player );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00016: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_6: , <No Var>, <No Flag>(Todo:5)
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00017: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00018( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }
  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_6: , <No Var>, <No Flag>(Todo:5)
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00018: Normal(Talk, NpcDespawn, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      eventMgr().sendEventNotice( player, getId(), 5, 0, 0, 0 );
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00020( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }
  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "GaiUsd202:66736 calling Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( GaiUsd202 );
