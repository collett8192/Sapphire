// FFXIVTheMovie.ParserV3.8
// param used:
//SCENE_13 = TATARU
//_ACTOR3 = B
//_ACTOR3B = 1|2
//_ACTOR4 = B
//_ACTOR4B = 1|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna604 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna604() : Sapphire::ScriptAPI::QuestScript( 67189 ){}; 
  ~HeaVna604() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 5 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1012398
  //ACTOR1 = 1012399
  //ACTOR2 = 1006756
  //ACTOR3 = 1000691
  //ACTOR4 = 1000692
  //CUTSCENEN01 = 879
  //CUTSCENEN02 = 969
  //ITEM0 = 2001798
  //ITEM1 = 2001799
  //QSTCOMPCHECK01 = 65641
  //QSTCOMPCHECK02 = 65747
  //QSTCOMPCHECK03 = 65558

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
        if( param1 == 1012398 ) // ACTOR0 = TATARU
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TATARU
          }
          break;
        }
        if( param1 == 1012399 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1006756 ) // ACTOR2 = YMHITRA
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=YMHITRA
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BL max stack 1
      //seq 1 event item ITEM1 = UI8CH max stack 1
      case 1:
      {
        if( param1 == 1000691 ) // ACTOR3 = GEVA, CB=2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=GEVA
          }
          else
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=GEVA
          }
          break;
        }
        if( param1 == 1012398 ) // ACTOR0 = TATARU
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1012399 ) // ACTOR1 = ALPHINAUD
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1006756 ) // ACTOR2 = YMHITRA
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=YMHITRA
          break;
        }
        if( param1 == 1000692 ) // ACTOR4 = ESUMIYAN, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ESUMIYAN
          }
          else
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=ESUMIYAN
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      case 255:
      {
        if( param1 == 1012398 ) // ACTOR0 = TATARU
        {
          Scene00011( quest, player ); // Scene00011: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00012: Normal(Talk, QuestReward, TargetCanMove), id=TATARU
          // +Callback Scene00013: Normal(CutScene, QuestComplete), id=TATARU
          break;
        }
        if( param1 == 1012399 ) // ACTOR1 = ALPHINAUD
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1000691 ) // ACTOR3 = GEVA
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=GEVA
          break;
        }
        if( param1 == 1000692 ) // ACTOR4 = ESUMIYAN
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=ESUMIYAN
          break;
        }
        if( param1 == 1006756 ) // ACTOR2 = YMHITRA
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=YMHITRA
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
    if( quest.getUI8BH() == 1 )
      if( quest.getUI8AL() == 1 )
      {
        quest.setUI8BH( 0 );
        quest.setUI8AL( 0 );
        quest.setBitFlag8( 1, false );
        quest.setBitFlag8( 2, false );
        quest.setUI8BL( 0 );
        quest.setUI8CH( 0 );
        quest.setSeq( 255 );
        quest.setUI8BH( 1 );
        quest.setUI8BL( 1 );
      }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, NONE, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00003: Normal(Talk, TargetCanMove), id=YMHITRA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8BH = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00004: Normal(Talk, TargetCanMove), id=GEVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }
  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8BH = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00005: Normal(Talk, TargetCanMove), id=GEVA" );
    eventMgr().playQuestScene( player, getId(), 5, NONE, nullptr );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00006: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00008: Normal(Talk, TargetCanMove), id=YMHITRA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00009: Normal(Talk, TargetCanMove), id=ESUMIYAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }
  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00010: Normal(Talk, TargetCanMove), id=ESUMIYAN" );
    eventMgr().playQuestScene( player, getId(), 10, NONE, nullptr );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00011: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00012( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }
  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00012: Normal(Talk, QuestReward, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00013( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }
  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00013: Normal(CutScene, QuestComplete), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      player.finishQuest( getId(), result.getResult( 1 ) );
    };
    eventMgr().playQuestScene( player, getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00015: Normal(Talk, TargetCanMove), id=GEVA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00016: Normal(Talk, TargetCanMove), id=ESUMIYAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna604:67189 calling Scene00017: Normal(Talk, TargetCanMove), id=YMHITRA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna604 );
