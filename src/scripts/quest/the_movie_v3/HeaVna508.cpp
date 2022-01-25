// FFXIVTheMovie.ParserV3.8
// param used:
//WARP_SCENE2 = 419|166.7|-14.5|39.3|-2.1|true
//SCENE_2 = CID
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna508 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna508() : Sapphire::ScriptAPI::QuestScript( 67185 ){}; 
  ~HeaVna508() = default; 

  //SEQ_0, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1013386
  //ACTOR1 = 1014573
  //ACTOR10 = 1013115
  //ACTOR11 = 1013116
  //ACTOR2 = 1013099
  //ACTOR3 = 1014564
  //ACTOR4 = 1014567
  //ACTOR5 = 1014568
  //ACTOR6 = 1013111
  //ACTOR7 = 1013112
  //ACTOR8 = 1013113
  //ACTOR9 = 1013114
  //CHOCOBONADERU = 848
  //LOCACTORAL = 1011887
  //LOCACTORBI = 1012125
  //LOCACTORENTA = 2006048
  //LOCACTORMAD = 1012494
  //LOCACTORRUKIA = 1008193
  //LOCACTORUE = 1012492
  //LOCMAKERAL = 5923535
  //LOCMAKERBI = 5923540
  //LOCMAKERENTA = 5923411
  //LOCMAKERMAD = 5923538
  //LOCMAKERRUKIA = 5923536
  //LOCMAKERUE = 5923539
  //NCUTHEAVNA50810 = 872
  //NCUTHEAVNA50820 = 873
  //PLAYBGMSAKUSEN = 317
  //PLAYBUK = 86
  //PLAYSEMOVE = 97
  //PLAYSEOFF = 98
  //POPRANGE0 = 5862287

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
        if( param1 == 1013386 ) // ACTOR0 = CID
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, AutoFadeIn), id=CID
            // +Callback Scene00002: Normal(CutScene, AutoFadeIn), id=CID
          }
          break;
        }
        if( param1 == 1014573 ) // ACTOR1 = WEDGE
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        if( param1 == 1013099 ) // ACTOR2 = ALPHINAUD
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1014564 ) // ACTOR3 = BIGGS
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1014567 ) // ACTOR4 = unknown
        {
          Scene00006( quest, player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1014568 ) // ACTOR5 = LUCIA
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1013111 ) // ACTOR6 = CID
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1013112 ) // ACTOR7 = ALPHINAUD
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013113 ) // ACTOR8 = LUCIA
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1013114 ) // ACTOR9 = unknown
        {
          Scene00011( quest, player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1013115 ) // ACTOR10 = WEDGE
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        if( param1 == 1013116 ) // ACTOR11 = BIGGS
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=BIGGS
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
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, AutoFadeIn), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00002( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00002: Normal(CutScene, AutoFadeIn), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 419, 166.7f, -14.5f, 39.3f, -2.1f, true );
    };
    eventMgr().playQuestScene( player, getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00003: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00005: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00007: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00010: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00012: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna508:67185 calling Scene00013: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna508 );
