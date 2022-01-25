// FFXIVTheMovie.ParserV3.8
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna404 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVna404() : Sapphire::ScriptAPI::QuestScript( 67176 ){}; 
  ~HeaVna404() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 7 entries
  //SEQ_2, 2 entries
  //SEQ_3, 2 entries
  //SEQ_4, 2 entries
  //SEQ_5, 1 entries
  //SEQ_6, 2 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1012780
  //ACTOR1 = 1012776
  //ACTOR10 = 1013101
  //ACTOR11 = 1013227
  //ACTOR12 = 1012580
  //ACTOR13 = 1012377
  //ACTOR14 = 1012337
  //ACTOR2 = 1012777
  //ACTOR3 = 1012778
  //ACTOR4 = 1012779
  //ACTOR5 = 1012781
  //ACTOR6 = 1012782
  //ACTOR7 = 1012212
  //ACTOR8 = 1013381
  //ACTOR9 = 5010000
  //CUTSCENEN01 = 856
  //CUTSCENEN02 = 857
  //INSTANCEDUNGEON0 = 34
  //LOCACTOR0 = 5864726
  //LOCACTOR1 = 5864729
  //LOCACTOR2 = 5864731
  //LOCACTOR3 = 5864732
  //LOCACTOR4 = 5864734
  //LOCACTOR5 = 5864735
  //LOCACTOR6 = 5864736
  //LOCMUSIC0 = 317
  //LOCSCREENIMAGE0 = 305
  //POPRANGE0 = 5865411
  //POPRANGE1 = 5827750
  //TERRITORYTYPE0 = 419

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
        if( param1 == 1012780 ) // ACTOR0 = HILDA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=HILDA
          }
          break;
        }
        if( param1 == 1012776 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012777 ) // ACTOR2 = TATARU
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1012778 ) // ACTOR3 = LUCIA
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1012779 ) // ACTOR4 = HAURCHEFANT
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=HAURCHEFANT
          break;
        }
        if( param1 == 1012781 ) // ACTOR5 = REVOLUTIONARY1
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1
          break;
        }
        if( param1 == 1012782 ) // ACTOR6 = REVOLUTIONARY2A
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2A
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012778 ) // ACTOR3 = LUCIA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove, ENpcBind), id=LUCIA
          }
          break;
        }
        if( param1 == 1012776 ) // ACTOR1 = ALPHINAUD
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012777 ) // ACTOR2 = TATARU
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1012779 ) // ACTOR4 = HAURCHEFANT
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=HAURCHEFANT
          break;
        }
        if( param1 == 1012780 ) // ACTOR0 = HILDA
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=HILDA
          break;
        }
        if( param1 == 1012781 ) // ACTOR5 = REVOLUTIONARY1
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1
          break;
        }
        if( param1 == 1012782 ) // ACTOR6 = REVOLUTIONARY2A
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2A
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1012212 ) // ACTOR7 = TEMPLEKNIGHT01640
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00015( quest, player ); // Scene00015: Normal(Talk, Message, TargetCanMove), id=TEMPLEKNIGHT01640
          }
          break;
        }
        if( param1 == 1013381 ) // ACTOR8 = TATARU
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1012212 ) // ACTOR7 = TEMPLEKNIGHT01640
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT01640
          break;
        }
        if( param1 == 1013381 ) // ACTOR8 = TATARU
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 4:
      {
        if( type == EVENT_ON_ENTER_TERRITORY ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00019( quest, player ); // Scene00019: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1013381 ) // ACTOR8 = TATARU
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 5:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT01640
        break;
      }
      case 6:
      {
        if( param1 == 1013101 ) // ACTOR10 = HOUSEFORTEMPSGUARD01580
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove, AutoFadeIn), id=HOUSEFORTEMPSGUARD01580
            // +Callback Scene00023: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1012212 ) // ACTOR7 = TEMPLEKNIGHT01640
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT01640
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1013227 ) // ACTOR11 = ALPHINAUD
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012580 ) // ACTOR12 = TATARU
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1012377 ) // ACTOR13 = HOUSEFORTEMPSSTEWARD
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSSTEWARD
          break;
        }
        if( param1 == 1012337 ) // ACTOR14 = BUTLER01580
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=BUTLER01580
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
    quest.setSeq( 4 );
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 5 );
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 6 );
  }
  void checkProgressSeq6( World::Quest& quest, Entity::Player& player )
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
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00004: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00005: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00006: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00007: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2A" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00008: Normal(Talk, TargetCanMove, ENpcBind), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 8, NONE, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00010: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00011: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00012: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00013: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00014: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2A" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00015: Normal(Talk, Message, TargetCanMove), id=TEMPLEKNIGHT01640" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00016: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00017: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT01640" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00018: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_4: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00019: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00020: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_5: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00021: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT01640" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq5( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR10, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00022: Normal(Talk, TargetCanMove, AutoFadeIn), id=HOUSEFORTEMPSGUARD01580" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00023( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }
  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR10, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00023: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq6( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00024: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT01640" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00026: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00027: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSSTEWARD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVna404:67176 calling Scene00028: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna404 );
