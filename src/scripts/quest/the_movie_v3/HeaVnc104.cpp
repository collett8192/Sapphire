// FFXIVTheMovie.ParserV3.9
// param used:
//_ACTOR9 = B
//_ACTOR9B = 1|2
//_ACTOR10 = B
//_ACTOR10B = 1|2
//_ACTOR4 = B
//_ACTOR4B = 1|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc104 : public Sapphire::ScriptAPI::QuestScript
{
public:
  HeaVnc104() : Sapphire::ScriptAPI::QuestScript( 67770 ){}; 
  ~HeaVnc104() = default; 

  //SEQ_0, 9 entries
  //SEQ_1, 10 entries
  //SEQ_255, 10 entries

  //ACTOR0 = 1016564
  //ACTOR1 = 1016565
  //ACTOR10 = 1011236
  //ACTOR2 = 1016566
  //ACTOR3 = 1016567
  //ACTOR4 = 1016568
  //ACTOR5 = 1016569
  //ACTOR6 = 1016570
  //ACTOR7 = 1016571
  //ACTOR8 = 1016572
  //ACTOR9 = 1011231
  //LOCACTOR0 = 1008193
  //LOCACTOR1 = 6184575
  //LOCACTOR2 = 6184576
  //LOCACTOR3 = 1012497

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
        if( param1 == 1016564 ) // ACTOR0 = LUCIA
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LUCIA
          }
          break;
        }
        if( param1 == 1016565 ) // ACTOR1 = ARTOIREL
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1016566 ) // ACTOR2 = EMMANELLAIN
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1016567 ) // ACTOR3 = HONOROIT
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1016568 ) // ACTOR4 = CITIZENA02233
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1016569 ) // ACTOR5 = CITIZENB02233
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR6 = CITIZENC02233
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        if( param1 == 1016571 ) // ACTOR7 = unknown
        {
          Scene00008( quest, player ); // Scene00008: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016572 ) // ACTOR8 = unknown
        {
          Scene00009( quest, player ); // Scene00009: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1011231 ) // ACTOR9 = REDWALD, CB=2
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=REDWALD
          }
          else
          {
            Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=REDWALD
          }
          break;
        }
        if( param1 == 1011236 ) // ACTOR10 = ROTHE, CB=2
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=ROTHE
          }
          else
          {
            Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=ROTHE
          }
          break;
        }
        if( param1 == 1016568 ) // ACTOR4 = CITIZENA02233, CB=2
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00014( quest, player ); // Scene00014: Normal(Talk, TargetCanMove), id=CITIZENA02233
          }
          else
          {
            Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=CITIZENA02233
          }
          break;
        }
        if( param1 == 1016565 ) // ACTOR1 = ARTOIREL
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1016566 ) // ACTOR2 = EMMANELLAIN
        {
          Scene00017( quest, player ); // Scene00017: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1016567 ) // ACTOR3 = HONOROIT
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1016569 ) // ACTOR5 = CITIZENB02233
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR6 = CITIZENC02233
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        if( param1 == 1016571 ) // ACTOR7 = unknown
        {
          Scene00021( quest, player ); // Scene00021: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016572 ) // ACTOR8 = unknown
        {
          Scene00022( quest, player ); // Scene00022: Empty(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016565 ) // ACTOR1 = ARTOIREL
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=ARTOIREL
          break;
        }
        if( param1 == 1011231 ) // ACTOR9 = REDWALD
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=REDWALD
          break;
        }
        if( param1 == 1011236 ) // ACTOR10 = ROTHE
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=ROTHE
          break;
        }
        if( param1 == 1016566 ) // ACTOR2 = EMMANELLAIN
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1016567 ) // ACTOR3 = HONOROIT
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=HONOROIT
          break;
        }
        if( param1 == 1016568 ) // ACTOR4 = CITIZENA02233
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=CITIZENA02233
          break;
        }
        if( param1 == 1016569 ) // ACTOR5 = CITIZENB02233
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=CITIZENB02233
          break;
        }
        if( param1 == 1016570 ) // ACTOR6 = CITIZENC02233
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=CITIZENC02233
          break;
        }
        if( param1 == 1016571 ) // ACTOR7 = unknown
        {
          Scene00031( quest, player ); // Scene00031: Empty(None), id=unknown
          break;
        }
        if( param1 == 1016572 ) // ACTOR8 = unknown
        {
          Scene00032( quest, player ); // Scene00032: Empty(None), id=unknown
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
          quest.setSeq( 255 );
        }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, NONE, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00002: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, NONE, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, NONE, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00004: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, NONE, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00005: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, NONE, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00006: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, NONE, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00007: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, NONE, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00008: Empty(None), id=unknown" );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00009: Empty(None), id=unknown" );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, UI8BL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00010: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, NONE, callback );
  }
  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR9, UI8BL = 1, Flag8(1)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00011: Normal(Talk, TargetCanMove), id=REDWALD" );
    eventMgr().playQuestScene( player, getId(), 11, NONE, nullptr );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00012: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, NONE, callback );
  }
  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR10, UI8AL = 1, Flag8(2)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00013: Normal(Talk, TargetCanMove), id=ROTHE" );
    eventMgr().playQuestScene( player, getId(), 13, NONE, nullptr );
  }

  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00014: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 14, NONE, callback );
  }
  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, UI8BH = 1, Flag8(3)=True, Branch
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00015: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    eventMgr().playQuestScene( player, getId(), 15, NONE, nullptr );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00016: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, NONE, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00017: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 17, NONE, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00018: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, NONE, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00019: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, NONE, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00020: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, NONE, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00021: Empty(None), id=unknown" );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00022: Empty(None), id=unknown" );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00023: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=ARTOIREL" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00024: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, NONE, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00025: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, NONE, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00026: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, NONE, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00027: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, NONE, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00028: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, NONE, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00029: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, NONE, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00030: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, NONE, callback );
  }

  void Scene00031( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00031: Empty(None), id=unknown" );
  }

  void Scene00032( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "HeaVnc104:67770 calling Scene00032: Empty(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( HeaVnc104 );
