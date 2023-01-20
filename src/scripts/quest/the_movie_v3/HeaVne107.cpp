// FFXIVTheMovie.ParserV3.10
// param used:
//_ACTOR2 = B
//_ACTOR2B = 1|2
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

class HeaVne107 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVne107() : Sapphire::ScriptAPI::QuestScript( 67883 ){}; 
  ~HeaVne107() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 6 entries
  //SEQ_4, 6 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1017750
  //ACTOR1 = 1017751
  //ACTOR10 = 1017756
  //ACTOR11 = 1017757
  //ACTOR12 = 1017758
  //ACTOR13 = 1017759
  //ACTOR2 = 1006224
  //ACTOR3 = 1006213
  //ACTOR4 = 1006223
  //ACTOR5 = 1017753
  //ACTOR6 = 1017752
  //ACTOR7 = 1006215
  //ACTOR8 = 1017754
  //ACTOR9 = 1017755
  //CUTSCENEN01 = 1261
  //LOCACTION0 = 1071
  //LOCACTOR0 = 6433884
  //LOCACTOR1 = 6433885
  //LOCACTOR2 = 6433796
  //LOCACTOR3 = 6433875
  //LOCACTOR4 = 6433876
  //LOCFACIAL0 = 607
  //POPRANGE0 = 6433886

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
        if( param1 == 1017750 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1017751 ) // ACTOR1 = ALISAIE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1006224 ) // ACTOR2 = TALEBOT, CB=2
        {
          if( !quest.getBitFlag8( 1 ) )
          {
            Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=TALEBOT
          }
          else
          {
            Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=TALEBOT
          }
          break;
        }
        if( param1 == 1006213 ) // ACTOR3 = OTELIN, CB=2
        {
          if( !quest.getBitFlag8( 2 ) )
          {
            Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=OTELIN
          }
          else
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=OTELIN
          }
          break;
        }
        if( param1 == 1006223 ) // ACTOR4 = SIFRID, CB=2
        {
          if( !quest.getBitFlag8( 3 ) )
          {
            Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=SIFRID
          }
          else
          {
            Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=SIFRID
          }
          break;
        }
        if( param1 == 1017753 ) // ACTOR5 = ALISAIE
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1017752 ) // ACTOR6 = ALPHINAUD
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1017750 ) // ACTOR0 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1017751 ) // ACTOR1 = ALISAIE
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1006224 ) // ACTOR2 = TALEBOT
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=TALEBOT
          break;
        }
        if( param1 == 1006213 ) // ACTOR3 = OTELIN
        {
          Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=OTELIN
          break;
        }
        if( param1 == 1006223 ) // ACTOR4 = SIFRID
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=SIFRID
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1006215 ) // ACTOR7 = GUNDOBALD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove, ENpcBind), id=GUNDOBALD
          }
          break;
        }
        if( param1 == 1017754 ) // ACTOR8 = ALPHINAUD
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1017755 ) // ACTOR9 = ALISAIE
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1006224 ) // ACTOR2 = TALEBOT
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=TALEBOT
          break;
        }
        if( param1 == 1006213 ) // ACTOR3 = OTELIN
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=OTELIN
          break;
        }
        if( param1 == 1006223 ) // ACTOR4 = SIFRID
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=SIFRID
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1017756 ) // ACTOR10 = ALPHINAUD
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00023: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1017755 ) // ACTOR9 = ALISAIE
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1006224 ) // ACTOR2 = TALEBOT
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=TALEBOT
          break;
        }
        if( param1 == 1006213 ) // ACTOR3 = OTELIN
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=OTELIN
          break;
        }
        if( param1 == 1006223 ) // ACTOR4 = SIFRID
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=SIFRID
          break;
        }
        if( param1 == 1006215 ) // ACTOR7 = GUNDOBALD
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=GUNDOBALD
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1017757 ) // ACTOR11 = ALPHINAUD
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=ALPHINAUD
          break;
        }
        if( param1 == 1017755 ) // ACTOR9 = ALISAIE
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1017758 ) // ACTOR12 = YDA
        {
          Scene00031( quest, player ); // Scene00031: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1017759 ) // ACTOR13 = PAPALYMO
        {
          Scene00032( quest, player ); // Scene00032: Normal(Talk, TargetCanMove), id=PAPALYMO
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
    if( quest.getUI8AL() == 3 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setBitFlag8( 2, false );
      quest.setBitFlag8( 3, false );
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

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 3, Flag8(1)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00003: Normal(Talk, TargetCanMove), id=TALEBOT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 3 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }
  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 3, Flag8(1)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00004: Normal(Talk, TargetCanMove), id=TALEBOT" );
    eventMgr().playQuestScene( player, getId(), 4, NONE, nullptr );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 3, Flag8(2)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00005: Normal(Talk, TargetCanMove), id=OTELIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 2, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 3 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }
  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 3, Flag8(2)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00006: Normal(Talk, TargetCanMove), id=OTELIN" );
    eventMgr().playQuestScene( player, getId(), 6, NONE, nullptr );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 3, Flag8(3)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00007: Normal(Talk, TargetCanMove), id=SIFRID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( quest.getUI8AL() + 1 );
      quest.setBitFlag8( 3, true );
      eventMgr().sendEventNotice( player, getId(), 0, 2, quest.getUI8AL(), 3 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }
  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 3, Flag8(3)=True, Branch(Todo:0)
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00008: Normal(Talk, TargetCanMove), id=SIFRID" );
    eventMgr().playQuestScene( player, getId(), 8, NONE, nullptr );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, NONE, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR0, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00011: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 11, NONE, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00013: Normal(Talk, TargetCanMove), id=TALEBOT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, NONE, callback );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00014: Normal(Talk, TargetCanMove), id=OTELIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00015: Normal(Talk, TargetCanMove), id=SIFRID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, NONE, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00016: Normal(Talk, TargetCanMove, ENpcBind), id=GUNDOBALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00019: Normal(Talk, TargetCanMove), id=TALEBOT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00020: Normal(Talk, TargetCanMove), id=OTELIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00021: Normal(Talk, TargetCanMove), id=SIFRID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, NONE, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00023( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, NONE, callback );
  }
  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR10, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00023: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
      playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
      eventMgr().eventFinish( player, result.eventId, 1 );
      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );
    };
    eventMgr().playQuestScene( player, getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00025: Normal(Talk, TargetCanMove), id=TALEBOT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00026: Normal(Talk, TargetCanMove), id=OTELIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00027: Normal(Talk, TargetCanMove), id=SIFRID" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00028: Normal(Talk, TargetCanMove), id=GUNDOBALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00029: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00030: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00031: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 31, NONE, callback );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVne107:67883 calling Scene00032: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 32, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVne107 );
