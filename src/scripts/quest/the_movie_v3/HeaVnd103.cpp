// FFXIVTheMovie.ParserV3.10
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnd103 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVnd103() : Sapphire::ScriptAPI::QuestScript( 67780 ){}; 
  ~HeaVnd103() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 4 entries
  //SEQ_3, 2 entries
  //SEQ_4, 3 entries
  //SEQ_5, 3 entries
  //SEQ_6, 2 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1016819
  //ACTOR1 = 1016810
  //ACTOR10 = 1017022
  //ACTOR11 = 1017023
  //ACTOR12 = 5010000
  //ACTOR2 = 1016811
  //ACTOR3 = 1016822
  //ACTOR4 = 1012078
  //ACTOR5 = 1016825
  //ACTOR6 = 1016882
  //ACTOR7 = 1016813
  //ACTOR8 = 1017011
  //ACTOR9 = 1016812
  //CUTSCENEN01 = 1174
  //CUTSCENEN02 = 1175
  //CUTSCENEN03 = 1176
  //EOBJECT0 = 2006956
  //INSTANCEDUNGEON0 = 44
  //LOCACTION0 = 962
  //LOCACTION1 = 967
  //LOCACTION2 = 958
  //LOCACTION3 = 954
  //LOCACTOR0 = 6275933
  //LOCACTOR1 = 1013802
  //LOCACTOR2 = 6211082
  //LOCACTOR3 = 1012904
  //LOCACTOR4 = 6211059
  //LOCACTOR5 = 6276424
  //LOCBGM0 = 322
  //LOCIDLE0 = 983
  //LOCQUEST0 = 66608
  //LOCSCREENIMAGE0 = 402
  //LOCSE0 = 99
  //LOCSE2 = 101
  //LOCSE3 = 102
  //LOCSE4 = 103
  //LOCSE5 = 104
  //POPRANGE0 = 6253216
  //POPRANGE1 = 6211086
  //TERRITORYTYPE0 = 400

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
        if( param1 == 1016819 ) // ACTOR0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=unknown
          }
          break;
        }
        if( param1 == 1016810 ) // ACTOR1 = AYMERIC
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1016811 ) // ACTOR2 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00003( quest, player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn, ENpcBind), id=unknown
          }
          break;
        }
        if( param1 == 1016822 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2006956 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00005( quest, player ); // Scene00005: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1012078 ) // ACTOR4 = MOGHAN
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=MOGHAN
          break;
        }
        if( param1 == 1016825 ) // ACTOR5 = ALPHINAUD
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1016882 ) // ACTOR6 = AYMERIC
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1016813 ) // ACTOR7 = AYMERIC
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00009( quest, player ); // Scene00009: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=AYMERIC
          }
          break;
        }
        if( param1 == 1017011 ) // ACTOR8 = ALPHINAUD
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1016812 ) // ACTOR9 = WYVERN02244
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, Message, TargetCanMove), id=WYVERN02244
          }
          break;
        }
        if( param1 == 1017022 ) // ACTOR10 = ALPHINAUD
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1017023 ) // ACTOR11 = AYMERIC
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1016812 ) // ACTOR9 = WYVERN02244
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=WYVERN02244
          break;
        }
        if( param1 == 1017022 ) // ACTOR10 = ALPHINAUD
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1017023 ) // ACTOR11 = AYMERIC
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        break;
      }
      case 6:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00017( quest, player ); // Scene00017: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1016812 ) // ACTOR9 = WYVERN02244
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=WYVERN02244
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1017011 ) // ACTOR8 = ALPHINAUD
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind), id=ALPHINAUD
          // +Callback Scene00020: Normal(CutScene, AutoFadeIn), id=unknown
          // +Callback Scene00021: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1016813 ) // ACTOR7 = AYMERIC
        {
          Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1016812 ) // ACTOR9 = WYVERN02244
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=WYVERN02244
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
    quest.setSeq( 6 );
  }
  void checkProgressSeq6( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 255 );
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00002: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn, ENpcBind), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 1, true );
        eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
        checkProgressSeq1( quest, player );
        playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
        eventMgr().eventFinish( player, result.eventId, 1 );
        player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
      }
    };
    eventMgr().playQuestScene( player, getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00005: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00006: Normal(Talk, TargetCanMove), id=MOGHAN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00008: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00011: Normal(Talk, Message, TargetCanMove), id=WYVERN02244" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00013: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00014: Normal(Talk, TargetCanMove), id=WYVERN02244" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00016: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_6: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00017: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00018: Normal(Talk, TargetCanMove), id=WYVERN02244" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00019: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00020( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00020: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00021( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00021: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00022: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnd103:67780 calling Scene00023: Normal(Talk, TargetCanMove), id=WYVERN02244" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnd103 );
