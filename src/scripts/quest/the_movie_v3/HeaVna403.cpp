// FFXIVTheMovie.ParserV3.8
// param used:
//WARP_SCENE6 = 418|20.37|-12|46|0.63|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna403 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna403() : Sapphire::ScriptAPI::QuestScript( 67175 ){}; 
  ~HeaVna403() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 5 entries
  //SEQ_4, 6 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1013260
  //ACTOR1 = 1013228
  //ACTOR10 = 1012775
  //ACTOR11 = 1012774
  //ACTOR12 = 1012780
  //ACTOR13 = 1012781
  //ACTOR14 = 1012782
  //ACTOR15 = 1012776
  //ACTOR16 = 1012777
  //ACTOR17 = 1012778
  //ACTOR18 = 1012779
  //ACTOR2 = 1012768
  //ACTOR3 = 1012769
  //ACTOR4 = 1012770
  //ACTOR5 = 1014653
  //ACTOR6 = 1014654
  //ACTOR7 = 1012773
  //ACTOR8 = 1012771
  //ACTOR9 = 1012772
  //CUTSCENEN01 = 853
  //CUTSCENEN02 = 854
  //CUTSCENEN03 = 855
  //EOBJECT0 = 2005551
  //EOBJECT1 = 2005550
  //EOBJECT2 = 2005763
  //EVENTACTIONLOOKOUTMIDDLE = 50
  //LOCACTOR0 = 5913112
  //LOCACTOR1 = 5913113
  //LOCACTOR10 = 5864726
  //LOCACTOR11 = 5864729
  //LOCACTOR12 = 5864731
  //LOCACTOR13 = 5864732
  //LOCACTOR14 = 5864735
  //LOCACTOR15 = 5864736
  //LOCACTOR2 = 5913110
  //LOCACTOR20 = 1012453
  //LOCACTOR21 = 1012434
  //LOCACTOR22 = 1012433
  //LOCACTOR23 = 5865258
  //LOCACTOR24 = 1011887
  //LOCACTOR3 = 5913111
  //LOCMUSIC0 = 117
  //LOCMUSIC1 = 313
  //LOCQUEST0 = 67232
  //POPRANGE0 = 5913118
  //QUESTBATTLE0 = 109
  //TERRITORYTYPE0 = 458

  static constexpr auto EVENT_ON_TALK = 0;
  static constexpr auto EVENT_ON_EMOTE = 1;
  static constexpr auto EVENT_ON_BNPC_KILL = 2;
  static constexpr auto EVENT_ON_WITHIN_RANGE = 3;
  static constexpr auto EVENT_ON_ENTER_TERRITORY = 4;
  static constexpr auto EVENT_ON_EVENT_ITEM = 5;
  static constexpr auto EVENT_ON_EOBJ_HIT = 6;

private:
  void onProgress( World::Quest& quest, Entity::Player& player, uint32_t type, uint64_t param1, uint32_t param2, uint32_t param3 )
  {
    switch( quest.getSeq() )
    {
      case 0:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( param1 == 2005551 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00003( quest, player ); // Scene00003: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1013228 ) // ACTOR1 = ALPHINAUD
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2005550 ) // EOBJECT1 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, CutScene, FadeIn, QuestGimmickReaction), id=unknown
          }
          break;
        }
        if( param1 == 1013228 ) // ACTOR1 = ALPHINAUD
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1012768 ) // ACTOR2 = HILDA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove, ENpcBind), id=HILDA
          }
          break;
        }
        if( param1 == 1012769 ) // ACTOR3 = REVOLUTIONARY1
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1
          break;
        }
        if( param1 == 1012770 ) // ACTOR4 = REVOLUTIONARY2
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2
          break;
        }
        if( param1 == 1014653 ) // ACTOR5 = ALPHINAUD
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1014654 ) // ACTOR6 = TATARU
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1012773 ) // ACTOR7 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00014( quest, player ); // Scene00014: Normal(QuestBattle, YesNo), id=unknown
          }
          break;
        }
        if( param1 == 1012771 ) // ACTOR8 = ALPHINAUD
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012772 ) // ACTOR9 = TATARU
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1012775 ) // ACTOR10 = REVOLUTIONARY2
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2
          break;
        }
        if( param1 == 1012774 ) // ACTOR11 = REVOLUTIONARY1
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1
          break;
        }
        if( param1 == 2005763 ) // EOBJECT2 = unknown
        {
          Scene00019( quest, player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012780 ) // ACTOR12 = HILDA
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=HILDA
          break;
        }
        if( param1 == 1012781 ) // ACTOR13 = REVOLUTIONARY1
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1
          break;
        }
        if( param1 == 1012782 ) // ACTOR14 = REVOLUTIONARY2
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2
          break;
        }
        if( param1 == 1012776 ) // ACTOR15 = ALPHINAUD
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012777 ) // ACTOR16 = TATARU
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1012778 ) // ACTOR17 = LUCIA
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1012779 ) // ACTOR18 = HAURCHEFANT
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=HAURCHEFANT
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
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00003: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT1, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00006: Normal(Talk, CutScene, FadeIn, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 418, 20.37f, -12.0f, 46.0f, 0.63f, false );
    };
    eventMgr().playQuestScene( player, getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00009: Normal(Talk, TargetCanMove, ENpcBind), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00010: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00011: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00013: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00014: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        //quest battle
        eventMgr().eventFinish( player, result.eventId, 1 );
        teriMgr().createAndJoinQuestBattle( player, 109 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00016: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00017: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00018: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq4( quest, player );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00021: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00022: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, NONE, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00024: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00025: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna403:67175 calling Scene00026: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna403 );
