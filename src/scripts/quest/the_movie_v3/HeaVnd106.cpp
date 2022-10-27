// FFXIVTheMovie.ParserV3.10
// param used:
//SCENE_9 = ALPHINAUD
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnd106 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVnd106() : Sapphire::ScriptAPI::QuestScript( 67783 ){}; 
  ~HeaVnd106() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1012380
  //ACTOR1 = 1016823
  //ACTOR2 = 1016827
  //ACTOR3 = 1013167
  //ACTOR4 = 1012163
  //ACTOR5 = 1016828
  //ACTOR6 = 1012857
  //ACTOR7 = 1012858
  //CUTSCENEN01 = 1182
  //CUTSCENEN02 = 1183
  //CUTSCENEN03 = 1184
  //CUTSCENEN04 = 1185
  //CUTSCENEN05 = 1186
  //CUTSCENEN06 = 1187
  //CUTSCENEN07 = 1188
  //CUTSCENEN08 = 1252
  //LOCACTION0 = 1022
  //LOCACTOR0 = 1015889
  //LOCACTOR1 = 1014558
  //LOCACTOR2 = 1016820
  //LOCACTOR3 = 1017117
  //LOCBGM0 = 313
  //LOCQUEST0 = 66608
  //LOCSE0 = 95
  //POPRANGE0 = 6212250
  //POPRANGE1 = 6388919

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
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=AYMERIC
        break;
      }
      case 1:
      {
        if( param1 == 1016823 ) // ACTOR1 = AYMERIC
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Talk, YesNo, TargetCanMove, SystemTalk, CanCancel), id=AYMERIC
            // +Callback Scene00003: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1016827 ) // ACTOR2 = TEMPLEKNIGHT02247
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT02247
          break;
        }
        if( param1 == 1013167 ) // ACTOR3 = LUCIA
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1012163 ) // ACTOR4 = HANDELOUP
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=HANDELOUP
          break;
        }
        break;
      }
      case 2:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00007( quest, player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=AYMERIC
        break;
      }
      case 255:
      {
        if( param1 == 1012857 ) // ACTOR6 = ALPHINAUD
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=ALPHINAUD
          // +Callback Scene00009: Normal(CutScene, AutoFadeIn), id=ALPHINAUD
          break;
        }
        if( param1 == 1012858 ) // ACTOR7 = TATARU
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=TATARU
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
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd106:67783 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVnd106:67783 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVnd106:67783 calling Scene00002: Normal(Talk, YesNo, TargetCanMove, SystemTalk, CanCancel), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )
      {
        Scene00003( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }
  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVnd106:67783 calling Scene00003: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd106:67783 calling Scene00004: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT02247" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd106:67783 calling Scene00005: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd106:67783 calling Scene00006: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd106:67783 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd106:67783 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00009( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }
  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd106:67783 calling Scene00009: Normal(CutScene, AutoFadeIn), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      player.finishQuest( getId(), result.getResult( 1 ) );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd106:67783 calling Scene00010: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnd106 );
