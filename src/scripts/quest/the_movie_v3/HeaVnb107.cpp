// FFXIVTheMovie.ParserV3.9
// param used:
//WARP_SCENE1 = 418|85|24|-6.53|-1.77|false
//_ACTOR12 = B
//_ACTOR12B = 2|2
//_ACTOR13 = B
//_ACTOR13B = 2|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnb107 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVnb107() : Sapphire::ScriptAPI::QuestScript( 67698 ){}; 
  ~HeaVnb107() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 14 entries
  //SEQ_2, 12 entries
  //SEQ_3, 11 entries
  //SEQ_4, 10 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1016008
  //ACTOR1 = 1016009
  //ACTOR10 = 1016025
  //ACTOR11 = 1016026
  //ACTOR12 = 1016015
  //ACTOR13 = 1016018
  //ACTOR14 = 1016019
  //ACTOR15 = 1016020
  //ACTOR16 = 1016016
  //ACTOR17 = 1016017
  //ACTOR18 = 1013167
  //ACTOR19 = 1016028
  //ACTOR2 = 1016010
  //ACTOR20 = 1016027
  //ACTOR21 = 1016031
  //ACTOR22 = 1016032
  //ACTOR23 = 1016033
  //ACTOR24 = 1016057
  //ACTOR25 = 1016059
  //ACTOR26 = 1012163
  //ACTOR3 = 1016011
  //ACTOR4 = 1016012
  //ACTOR5 = 1012384
  //ACTOR6 = 1016029
  //ACTOR7 = 1016030
  //ACTOR8 = 1016058
  //ACTOR9 = 1012385
  //LOCACTOR0 = 6080791
  //LOCACTOR1 = 6080792
  //LOCACTOR10 = 6081061
  //LOCACTOR11 = 6081062
  //LOCACTOR12 = 5895161
  //LOCACTOR2 = 6080793
  //LOCACTOR20 = 1015848
  //LOCACTOR21 = 1015858
  //LOCACTOR3 = 6080794
  //LOCACTOR30 = 6081083
  //LOCACTOR40 = 1011895
  //LOCACTOR41 = 1015842
  //LOCACTOR42 = 6081142
  //LOCACTOR43 = 6081693
  //LOCACTOR44 = 6081143
  //LOCACTOR50 = 1011893
  //LOCACTOR60 = 5838636
  //POPRANGE0 = 6163372

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
        if( param1 == 1016008 ) // ACTOR0 = LUCIA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=LUCIA
          }
          break;
        }
        if( param1 == 1016009 ) // ACTOR1 = HILDA
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1016010 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1016011 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1016012 ) // ACTOR4 = THANCRED
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012384 ) // ACTOR5 = EMMANELLAIN
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove, ENpcBind), id=EMMANELLAIN
          }
          break;
        }
        if( param1 == 1016029 ) // ACTOR6 = ALPHINAUD
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1016030 ) // ACTOR7 = TATARU
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1016058 ) // ACTOR8 = YSHTOLA
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012385 ) // ACTOR9 = HONOROIT
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1016025 ) // ACTOR10 = HILDA
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1016026 ) // ACTOR11 = THANCRED
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1016015 ) // ACTOR12 = BEAUTY02162
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=BEAUTY02162
          break;
        }
        if( param1 == 1016018 ) // ACTOR13 = MAELIE
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=MAELIE
          break;
        }
        if( param1 == 1016019 ) // ACTOR14 = unknown
        {
          Scene00015( quest, player ); // Scene00015: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016020 ) // ACTOR15 = ISHGARDIANPRIEST02162
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=ISHGARDIANPRIEST02162
          break;
        }
        if( param1 == 1016016 ) // ACTOR16 = unknown
        {
          Scene00017( quest, player ); // Scene00017: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016017 ) // ACTOR17 = unknown
        {
          Scene00018( quest, player ); // Scene00018: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013167 ) // ACTOR18 = LUCIA
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1016015 ) // ACTOR12 = BEAUTY02162, CB=2
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=BEAUTY02162
          }
          else
          {
            Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=BEAUTY02162
          }
          break;
        }
        if( param1 == 1016018 ) // ACTOR13 = MAELIE, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=MAELIE
          }
          else
          {
            Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=MAELIE
          }
          break;
        }
        if( param1 == 1016020 ) // ACTOR15 = ISHGARDIANPRIEST02162
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00024( quest, player ); // Scene00024: Normal(Talk, FadeIn, TargetCanMove), id=ISHGARDIANPRIEST02162
          }
          break;
        }
        if( param1 == 1016029 ) // ACTOR6 = ALPHINAUD
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1016030 ) // ACTOR7 = TATARU
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1016058 ) // ACTOR8 = YSHTOLA
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1012384 ) // ACTOR5 = EMMANELLAIN
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1012385 ) // ACTOR9 = HONOROIT
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1016019 ) // ACTOR14 = unknown
        {
          Scene00030( quest, player ); // Scene00030: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016016 ) // ACTOR16 = unknown
        {
          Scene00031( quest, player ); // Scene00031: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016017 ) // ACTOR17 = unknown
        {
          Scene00032( quest, player ); // Scene00032: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013167 ) // ACTOR18 = LUCIA
        {
          Scene00033( quest, player ); // Scene00033: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1016028 ) // ACTOR19 = THANCRED
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00034( quest, player ); // Scene00034: Normal(Talk, TargetCanMove), id=THANCRED
          }
          break;
        }
        if( param1 == 1016027 ) // ACTOR20 = HILDA
        {
          Scene00035( quest, player ); // Scene00035: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1016029 ) // ACTOR6 = ALPHINAUD
        {
          Scene00036( quest, player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1016030 ) // ACTOR7 = TATARU
        {
          Scene00037( quest, player ); // Scene00037: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1016058 ) // ACTOR8 = YSHTOLA
        {
          Scene00038( quest, player ); // Scene00038: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1016015 ) // ACTOR12 = BEAUTY02162
        {
          Scene00039( quest, player ); // Scene00039: Normal(Talk, TargetCanMove), id=BEAUTY02162
          break;
        }
        if( param1 == 1016018 ) // ACTOR13 = MAELIE
        {
          Scene00040( quest, player ); // Scene00040: Normal(Talk, TargetCanMove), id=MAELIE
          break;
        }
        if( param1 == 1016019 ) // ACTOR14 = unknown
        {
          Scene00041( quest, player ); // Scene00041: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016016 ) // ACTOR16 = unknown
        {
          Scene00042( quest, player ); // Scene00042: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016017 ) // ACTOR17 = unknown
        {
          Scene00043( quest, player ); // Scene00043: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013167 ) // ACTOR18 = LUCIA
        {
          Scene00044( quest, player ); // Scene00044: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1016031 ) // ACTOR21 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00045( quest, player ); // Scene00045: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1016032 ) // ACTOR22 = TATARU
        {
          Scene00046( quest, player ); // Scene00046: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1016033 ) // ACTOR23 = PYROMANIAC02162
        {
          Scene00047( quest, player ); // Scene00047: Normal(Talk, TargetCanMove), id=PYROMANIAC02162
          break;
        }
        if( param1 == 1016057 ) // ACTOR24 = YSHTOLA
        {
          Scene00048( quest, player ); // Scene00048: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1016015 ) // ACTOR12 = BEAUTY02162
        {
          Scene00049( quest, player ); // Scene00049: Normal(Talk, TargetCanMove), id=BEAUTY02162
          break;
        }
        if( param1 == 1016018 ) // ACTOR13 = MAELIE
        {
          Scene00050( quest, player ); // Scene00050: Normal(Talk, TargetCanMove), id=MAELIE
          break;
        }
        if( param1 == 1016019 ) // ACTOR14 = unknown
        {
          Scene00051( quest, player ); // Scene00051: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016016 ) // ACTOR16 = unknown
        {
          Scene00052( quest, player ); // Scene00052: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016017 ) // ACTOR17 = unknown
        {
          Scene00053( quest, player ); // Scene00053: Empty(None), id=unknown
          break;
        }
        if( param1 == 1013167 ) // ACTOR18 = LUCIA
        {
          Scene00054( quest, player ); // Scene00054: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016008 ) // ACTOR0 = LUCIA
        {
          Scene00055( quest, player ); // Scene00055: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=LUCIA
          break;
        }
        if( param1 == 1016009 ) // ACTOR1 = HILDA
        {
          Scene00056( quest, player ); // Scene00056: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1016010 ) // ACTOR2 = ALPHINAUD
        {
          Scene00057( quest, player ); // Scene00057: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1016011 ) // ACTOR3 = YSHTOLA
        {
          Scene00058( quest, player ); // Scene00058: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1016032 ) // ACTOR22 = TATARU
        {
          Scene00059( quest, player ); // Scene00059: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1016059 ) // ACTOR25 = THANCRED
        {
          Scene00060( quest, player ); // Scene00060: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1012163 ) // ACTOR26 = HANDELOUP
        {
          Scene00061( quest, player ); // Scene00061: Normal(Talk, TargetCanMove), id=HANDELOUP
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
    if( quest.getUI8BL() == 1 )
      if( quest.getUI8AL() == 1 )
        if( quest.getUI8BH() == 1 )
        {
          quest.setUI8BL( 0 );
          quest.setUI8AL( 0 );
          quest.setUI8BH( 0 );
          quest.setBitFlag8( 1, false );
          quest.setBitFlag8( 2, false );
          quest.setBitFlag8( 3, false );
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

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.forceZoneing( 418, 85.0f, 24.0f, -6.53f, -1.77f, false );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00002: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00005: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00006: Normal(Talk, TargetCanMove, ENpcBind), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00008: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00010: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00011: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00012: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00013: Normal(Talk, TargetCanMove), id=BEAUTY02162" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00014: Normal(Talk, TargetCanMove), id=MAELIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00015: Empty(None), id=unknown" );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR15, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00016: Normal(Talk, TargetCanMove), id=ISHGARDIANPRIEST02162" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00017: Empty(None), id=unknown" );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00018: Empty(None), id=unknown" );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00019: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, UI8BL = 1, Flag8(1)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00020: Normal(Talk, TargetCanMove), id=BEAUTY02162" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }
  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR12, UI8BL = 1, Flag8(1)=True, Branch(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00021: Normal(Talk, TargetCanMove), id=BEAUTY02162" );
    eventMgr().playQuestScene( player, getId(), 21, NONE, nullptr );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, UI8AL = 1, Flag8(2)=True, Branch(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00022: Normal(Talk, TargetCanMove), id=MAELIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }
  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR13, UI8AL = 1, Flag8(2)=True, Branch(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00023: Normal(Talk, TargetCanMove), id=MAELIE" );
    eventMgr().playQuestScene( player, getId(), 23, NONE, nullptr );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR15, UI8BH = 1, Flag8(3)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00024: Normal(Talk, FadeIn, TargetCanMove), id=ISHGARDIANPRIEST02162" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 3, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00026: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00027: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00028: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00029: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00030: Empty(None), id=unknown" );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00031: Empty(None), id=unknown" );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00032: Empty(None), id=unknown" );
  }

  void Scene00033( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00033: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 33, NONE, callback );
  }

  void Scene00034( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR19, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00034: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 34, NONE, callback );
  }

  void Scene00035( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR20, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00035: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 35, NONE, callback );
  }

  void Scene00036( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 36, NONE, callback );
  }

  void Scene00037( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00037: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 37, NONE, callback );
  }

  void Scene00038( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00038: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 38, NONE, callback );
  }

  void Scene00039( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00039: Normal(Talk, TargetCanMove), id=BEAUTY02162" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 39, NONE, callback );
  }

  void Scene00040( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00040: Normal(Talk, TargetCanMove), id=MAELIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 40, NONE, callback );
  }

  void Scene00041( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00041: Empty(None), id=unknown" );
  }

  void Scene00042( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00042: Empty(None), id=unknown" );
  }

  void Scene00043( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00043: Empty(None), id=unknown" );
  }

  void Scene00044( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00044: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 44, NONE, callback );
  }

  void Scene00045( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR21, UI8AL = 1, Flag8(1)=True(Todo:5)
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00045: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 5, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 45, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00046( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00046: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 46, NONE, callback );
  }

  void Scene00047( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR23, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00047: Normal(Talk, TargetCanMove), id=PYROMANIAC02162" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 47, NONE, callback );
  }

  void Scene00048( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR24, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00048: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 48, NONE, callback );
  }

  void Scene00049( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00049: Normal(Talk, TargetCanMove), id=BEAUTY02162" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 49, NONE, callback );
  }

  void Scene00050( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00050: Normal(Talk, TargetCanMove), id=MAELIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 50, NONE, callback );
  }

  void Scene00051( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00051: Empty(None), id=unknown" );
  }

  void Scene00052( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR16, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00052: Empty(None), id=unknown" );
  }

  void Scene00053( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR17, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00053: Empty(None), id=unknown" );
  }

  void Scene00054( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR18, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00054: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 54, NONE, callback );
  }

  void Scene00055( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00055: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 55, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00056( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00056: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 56, NONE, callback );
  }

  void Scene00057( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00057: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 57, NONE, callback );
  }

  void Scene00058( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00058: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 58, NONE, callback );
  }

  void Scene00059( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR22, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00059: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 59, NONE, callback );
  }

  void Scene00060( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR25, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00060: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 60, NONE, callback );
  }

  void Scene00061( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR26, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnb107:67698 calling Scene00061: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 61, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnb107 );
