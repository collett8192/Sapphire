// FFXIVTheMovie.ParserV3.9
// param used:
//SCENE_3 = ESTINIEN
//SCENE_7 = dummy0
//SCENE_8 = dummy1
//SCENE_9 = dummy2
//SCENE_10 = dummy3
//SCENE_11 = dummy4
//SCENE_12 = dummy5
//SCENE_13 = dummy6
//SCENE_14 = dummye0
//ENEMY0 = dummy0
//ENEMY1 = dummy1
//ENEMY2 = dummy2
//ENEMY3 = dummy3
//ENEMY4 = dummy4
//ENEMY5 = dummy5
//ENEMY6 = dummy6
//EOBJECT0 = dummye0
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna705 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna705() : Sapphire::ScriptAPI::QuestScript( 67203 ){}; 
  ~HeaVna705() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 9 entries
  //SEQ_3, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1014850
  //ACTOR1 = 1012829
  //ACTOR2 = 1012828
  //ACTOR3 = 1012830
  //ACTOR4 = 1012827
  //ACTOR5 = 1012834
  //CUTSCENEN01 = 894
  //CUTSCENEN02 = 895
  //CUTSCENEN03 = 896
  //ENEMY0 = 5867945
  //ENEMY1 = 5867947
  //ENEMY2 = 5867948
  //ENEMY3 = 5867949
  //ENEMY4 = 5867950
  //ENEMY5 = 5867951
  //ENEMY6 = 5867952
  //EOBJECT0 = 2006357
  //EOBJECT1 = 2005764
  //QUESTBATTLE0 = 110
  //TERRITORYTYPE0 = 459

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
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUIDANCESYSTEM
        break;
      }
      case 1:
      {
        if( param1 == 1012829 ) // ACTOR1 = ESTINIEN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN
            // +Callback Scene00003: Normal(CutScene), id=ESTINIEN
          }
          break;
        }
        if( param1 == 1012828 ) // ACTOR2 = ALPHINAUD
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012830 ) // ACTOR3 = YSHTOLA
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1012827 ) // ACTOR4 = GUIDANCESYSTEM
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, Message, PopBNpc, TargetCanMove), id=GUIDANCESYSTEM
          }
          break;
        }
        // BNpcHack credit moved to ACTOR4
        if( param1 == 5867945 ) // ENEMY0 = dummy0
        {
          Scene00007( quest, player ); // Scene00007: Normal(Message, PopBNpc), id=dummy0
          break;
        }
        if( param1 == 5867947 ) // ENEMY1 = dummy1
        {
          Scene00008( quest, player ); // Scene00008: Normal(Message, PopBNpc), id=dummy1
          break;
        }
        if( param1 == 5867948 ) // ENEMY2 = dummy2
        {
          Scene00009( quest, player ); // Scene00009: Normal(Message, PopBNpc), id=dummy2
          break;
        }
        if( param1 == 5867949 ) // ENEMY3 = dummy3
        {
          Scene00010( quest, player ); // Scene00010: Normal(Message, PopBNpc), id=dummy3
          break;
        }
        if( param1 == 5867950 ) // ENEMY4 = dummy4
        {
          Scene00011( quest, player ); // Scene00011: Normal(Message, PopBNpc), id=dummy4
          break;
        }
        if( param1 == 5867951 ) // ENEMY5 = dummy5
        {
          Scene00012( quest, player ); // Scene00012: Normal(Message, PopBNpc), id=dummy5
          break;
        }
        if( param1 == 5867952 ) // ENEMY6 = dummy6
        {
          Scene00013( quest, player ); // Scene00013: Normal(Message, PopBNpc), id=dummy6
          break;
        }
        if( param1 == 2006357 ) // EOBJECT0 = dummye0
        {
          Scene00014( quest, player ); // Scene00014: Empty(None), id=dummye0
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1012827 ) // ACTOR4 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00015( quest, player ); // Scene00015: Normal(QuestBattle, YesNo), id=unknown
          }
          break;
        }
        if( param1 == 2005764 ) // EOBJECT1 = unknown
        {
          Scene00016( quest, player ); // Scene00016: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00017( quest, player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GUIDANCESYSTEM
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
    if( quest.getUI8AL() == 7 )
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
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00003( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }
  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00003: Normal(CutScene), id=ESTINIEN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 7, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00006: Normal(Talk, Message, PopBNpc, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 7 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 2, quest.getUI8AL(), 7 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00007: Normal(Message, PopBNpc), id=dummy0" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00008: Normal(Message, PopBNpc), id=dummy1" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00009: Normal(Message, PopBNpc), id=dummy2" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00010: Normal(Message, PopBNpc), id=dummy3" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00011: Normal(Message, PopBNpc), id=dummy4" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00012: Normal(Message, PopBNpc), id=dummy5" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ENEMY6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00013: Normal(Message, PopBNpc), id=dummy6" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00014: Empty(None), id=dummye0" );
    checkProgressSeq2( quest, player );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00015: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        //quest battle
        eventMgr().eventFinish( player, result.eventId, 1 );
        teriMgr().createAndJoinQuestBattle( player, 110 );
      }
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00016: Empty(None), id=unknown" );
    checkProgressSeq3( quest, player );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna705:67203 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna705 );
