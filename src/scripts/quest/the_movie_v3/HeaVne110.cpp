// FFXIVTheMovie.ParserV3.10
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVne110 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVne110() : Sapphire::ScriptAPI::QuestScript( 67886 ){}; 
  ~HeaVne110() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 5 entries
  //SEQ_255, 16 entries

  //ACTOR0 = 1017767
  //ACTOR1 = 1017768
  //ACTOR10 = 1017793
  //ACTOR11 = 1017773
  //ACTOR12 = 1017776
  //ACTOR13 = 1017777
  //ACTOR14 = 1017778
  //ACTOR15 = 1017779
  //ACTOR16 = 1017780
  //ACTOR17 = 1017781
  //ACTOR18 = 1017782
  //ACTOR19 = 1017783
  //ACTOR2 = 1017769
  //ACTOR20 = 1017784
  //ACTOR21 = 1017794
  //ACTOR22 = 1017795
  //ACTOR23 = 1017796
  //ACTOR3 = 1017770
  //ACTOR4 = 1017771
  //ACTOR5 = 1017772
  //ACTOR6 = 1017417
  //ACTOR7 = 1017775
  //ACTOR8 = 1006215
  //ACTOR9 = 1017792
  //CUTSCENEN01 = 1268
  //CUTSCENEN02 = 1269
  //CUTSCENEN03 = 1270
  //CUTSCENEN04 = 1271
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1017699
  //LOCACTOR2 = 6433909
  //LOCACTOR3 = 6433910
  //LOCACTOR4 = 6433912
  //LOCACTOR5 = 1016788
  //POPRANGE0 = 6445540
  //POPRANGE1 = 6584515

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
        if( param1 == 1017767 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1017768 ) // ACTOR1 = ALISAIE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1017769 ) // ACTOR2 = unknown
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1017770 ) // ACTOR3 = URIANGER
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1017768 ) // ACTOR1 = ALISAIE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=ALISAIE
          }
          break;
        }
        if( param1 == 1017770 ) // ACTOR3 = URIANGER
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1017771 ) // ACTOR4 = PAPALYMO
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00007( quest, player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=PAPALYMO
          }
          break;
        }
        if( param1 == 1017772 ) // ACTOR5 = YDA
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1017417 ) // ACTOR6 = ALPHINAUD
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1017775 ) // ACTOR7 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00011: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1006215 ) // ACTOR8 = GUNDOBALD
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=GUNDOBALD
          break;
        }
        if( param1 == 1017792 ) // ACTOR9 = HOARYBOULDER
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=HOARYBOULDER
          break;
        }
        if( param1 == 1017793 ) // ACTOR10 = COULTENET
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=COULTENET
          break;
        }
        if( param1 == 1017773 ) // ACTOR11 = FLHAMINN
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=FLHAMINN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1017776 ) // ACTOR12 = ALPHINAUD
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          // +Callback Scene00017: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1017773 ) // ACTOR11 = FLHAMINN
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=FLHAMINN
          break;
        }
        if( param1 == 1017777 ) // ACTOR13 = ALISAIE
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1017778 ) // ACTOR14 = TATARU
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1017779 ) // ACTOR15 = THANCRED
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1017780 ) // ACTOR16 = YSHTOLA
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1017781 ) // ACTOR17 = URIANGER
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1017782 ) // ACTOR18 = KRILE
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1017783 ) // ACTOR19 = YDA
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1017784 ) // ACTOR20 = PAPALYMO
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=PAPALYMO
          break;
        }
        if( param1 == 1017792 ) // ACTOR9 = HOARYBOULDER
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=HOARYBOULDER
          break;
        }
        if( param1 == 1017793 ) // ACTOR10 = COULTENET
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=COULTENET
          break;
        }
        if( param1 == 1017794 ) // ACTOR21 = OCHERBOULDER
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=OCHERBOULDER
          break;
        }
        if( param1 == 1017795 ) // ACTOR22 = AENOR
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=AENOR
          break;
        }
        if( param1 == 1017796 ) // ACTOR23 = CLEMENCE
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=CLEMENCE
          break;
        }
        if( param1 == 1006215 ) // ACTOR8 = GUNDOBALD
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=GUNDOBALD
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
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00003: Normal(Talk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00004: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00006: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00008: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00011( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }
  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00011: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00012: Normal(Talk, TargetCanMove), id=GUNDOBALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00013: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00014: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00015: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00017( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }
  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00017: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      player.finishQuest( getId(), result.getResult( 1 ) );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00018: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00020: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00021: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00023: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, NONE, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00024: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00025: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00026: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00027: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00028: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR21, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00029: Normal(Talk, TargetCanMove), id=OCHERBOULDER" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00030: Normal(Talk, TargetCanMove), id=AENOR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00031: Normal(Talk, TargetCanMove), id=CLEMENCE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne110:67886 calling Scene00032: Normal(Talk, TargetCanMove), id=GUNDOBALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVne110 );
