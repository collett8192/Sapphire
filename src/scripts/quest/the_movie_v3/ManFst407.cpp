// FFXIVTheMovie.ParserV3.6
// id hint used:
//WARP_SLAFBORN = 156|0.64|-158.5|13.4|3.14|false
//SCENE_2 REMOVED!!
//SCENE_8 = CID
//_ACTOR5 = B
//_ACTOR5B = 1|2
//_ACTOR7 = E
//_ACTOR7E = 2|3,59
//_ACTOR9 = E
//_ACTOR9E = 2|3,59
//_ACTOR10 = E
//_ACTOR10E = 2|3,59
//_ACTOR11 = E
//_ACTOR11E = 3|3,59
//PRIVATE_SCENE8 = 335
//PRIVATE_SCENE14 = 335
//PRIVATE_SCENE26 = 335
//PRIVATE_SCENE31 = 335
//PRIVATE_SCENE36 = 335
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManFst407 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManFst407() : Sapphire::ScriptAPI::EventScript( 66057 ){}; 
  ~ManFst407() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 5 entries
  //SEQ_2, 6 entries
  //SEQ_3, 4 entries
  //SEQ_4, 4 entries
  //SEQ_5, 5 entries
  //SEQ_6, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006555
  //ACTOR1 = 1006530
  //ACTOR10 = 1006569
  //ACTOR11 = 1007611
  //ACTOR12 = 1006562
  //ACTOR13 = 1007694
  //ACTOR14 = 1007696
  //ACTOR15 = 1006573
  //ACTOR16 = 1004433
  //ACTOR2 = 1007538
  //ACTOR3 = 1007539
  //ACTOR4 = 1007670
  //ACTOR5 = 1007537
  //ACTOR6 = 1006531
  //ACTOR7 = 1006567
  //ACTOR8 = 1007614
  //ACTOR9 = 1006568
  //CUTSCENE01 = 293
  //CUTSCENE02 = 113
  //CUTSCENEAFTER00 = 456
  //CUTSCENEAFTER01 = 287
  //CUTSCENEAFTER02 = 114
  //CUTSCENEAFTER03 = 288
  //CUTSCENEAFTER04 = 260
  //EOBJECT0 = 2002376
  //EVENTACTIONTOUCHMIDDLE = 46
  //ITEM0 = 2000773
  //LOCACTION1 = 990
  //LOCACTOR0 = 1007697
  //LOCACTOR1 = 1007006
  //LOCACTOR2 = 1007023
  //LOCACTOR8 = 1006563
  //LOCACTOR9 = 1007614
  //LOCFACE1 = 617
  //LOCFACE2 = 620
  //LOCPOSACTOR0 = 4332128
  //LOCPOSACTOR1 = 4332129
  //LOCSE1 = 44
  //LOCSE2 = 45
  //POPRANGE0 = 4321644
  //POPRANGE1 = 4304063
  //POPRANGE2 = 4305281
  //POPRANGE3 = 4103351
  //QUESTBATTLE0 = 65
  //RITEM0 = 6223
  //RITEM1 = 6224
  //TERRITORYTYPE0 = 156
  //TERRITORYTYPE1 = 335
  //TERRITORYTYPE2 = 305
  //TERRITORYTYPE3 = 130

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1006555 || param2 == 1006555 ) // ACTOR0 = CID
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1006530 || param2 == 1006530 ) // ACTOR1 = SLAFBORN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, YesNo, TargetCanMove), id=SLAFBORN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1007538 || param2 == 1007538 ) // ACTOR2 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007539 || param2 == 1007539 ) // ACTOR3 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007670 || param2 == 1007670 ) // ACTOR4 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007537 || param2 == 1007537 ) // ACTOR5 = CID, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(CutScene, AutoFadeIn), id=CID
          }
          else
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=CID
          }
          break;
        }
        if( param1 == 1006531 || param2 == 1006531 ) // ACTOR6 = GLAUMUNT
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=GLAUMUNT
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1006567 || param2 == 1006567 ) // ACTOR7 = IMPERIALSOLDIER_A, EB=3(emote=59)
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            if( type == 0 ) Scene00011( player ); // onTalk Scene00011: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_A
            if( type == 1 ) // onEmote
            {
                if( param3 == 59 ) Scene00012( player ); // Correct Scene00012: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_A
                else Scene00013( player ); // Incorrect Scene00013: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_A
            }
          }
          break;
        }
        if( param1 == 1007537 || param2 == 1007537 ) // ACTOR5 = CID
        {
          Scene00014( player ); // Scene00014: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CID
          break;
        }
        if( param1 == 1006531 || param2 == 1006531 ) // ACTOR6 = GLAUMUNT
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=GLAUMUNT
          break;
        }
        if( param1 == 1007614 || param2 == 1007614 ) // ACTOR8 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006568 || param2 == 1006568 ) // ACTOR9 = IMPERIALSOLDIER_B, EB=3(emote=59)
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            if( type == 0 ) Scene00017( player ); // onTalk Scene00017: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_B
            if( type == 1 ) // onEmote
            {
                if( param3 == 59 ) Scene00018( player ); // Correct Scene00018: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_B
                else Scene00019( player ); // Incorrect Scene00019: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_B
            }
          }
          break;
        }
        if( param1 == 1006569 || param2 == 1006569 ) // ACTOR10 = IMPERIALSOLDIER_C, EB=3(emote=59)
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            if( type == 0 ) Scene00020( player ); // onTalk Scene00020: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_C
            if( type == 1 ) // onEmote
            {
                if( param3 == 59 ) Scene00021( player ); // Correct Scene00021: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_C
                else Scene00022( player ); // Incorrect Scene00022: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_C
            }
          }
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 1007611 || param2 == 1007611 ) // ACTOR11 = IMPERIALSOLDIER_D, EB=3(emote=59)
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            if( type == 0 ) Scene00023( player ); // onTalk Scene00023: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_D
            if( type == 1 ) // onEmote
            {
                if( param3 == 59 ) Scene00024( player ); // Correct Scene00024: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_D
                else Scene00025( player ); // Incorrect Scene00025: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_D
            }
          }
          break;
        }
        if( param1 == 1007537 || param2 == 1007537 ) // ACTOR5 = CID
        {
          Scene00026( player ); // Scene00026: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CID
          break;
        }
        if( param1 == 1006531 || param2 == 1006531 ) // ACTOR6 = GLAUMUNT
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=GLAUMUNT
          break;
        }
        if( param1 == 1007614 || param2 == 1007614 ) // ACTOR8 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 1006562 || param2 == 1006562 ) // ACTOR12 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00029( player ); // Scene00029: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00030: Normal(FadeIn, TargetCanMove, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1007537 || param2 == 1007537 ) // ACTOR5 = CID
        {
          Scene00031( player ); // Scene00031: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CID
          break;
        }
        if( param1 == 1006531 || param2 == 1006531 ) // ACTOR6 = GLAUMUNT
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=GLAUMUNT
          break;
        }
        if( param1 == 1007614 || param2 == 1007614 ) // ACTOR8 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 2002376 || param2 == 2002376 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00035( player ); // Scene00035: Normal(QuestBattle, YesNo), id=unknown
          }
          break;
        }
        if( param1 == 1007537 || param2 == 1007537 ) // ACTOR5 = CID
        {
          Scene00036( player ); // Scene00036: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CID
          break;
        }
        if( param1 == 1006531 || param2 == 1006531 ) // ACTOR6 = GLAUMUNT
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=GLAUMUNT
          break;
        }
        if( param1 == 1007694 || param2 == 1007694 ) // ACTOR13 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007696 || param2 == 1007696 ) // ACTOR14 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 6:
      {
        if( type != 2 ) Scene00040( player ); // Scene00040: Normal(CutScene, AutoFadeIn), id=unknown
        break;
      }
      case 255:
      {
        if( param1 == 1006573 || param2 == 1006573 ) // ACTOR15 = MINFILIA
        {
          Scene00041( player ); // Scene00041: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1004433 || param2 == 1004433 ) // ACTOR16 = ELYENORA
        {
          Scene00042( player ); // Scene00042: Normal(Talk, YesNo, TargetCanMove), id=ELYENORA
          break;
        }
        break;
      }
      default:
      {
        player.sendUrgent( "Sequence {} not defined.", player.getQuestSeq( getId() ) );
        break;
      }
    }
  }

public:
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    onProgress( player, actorId, actor, 0, 0 );
  }

  void onEmote( uint64_t actorId, uint32_t eventId, uint32_t emoteId, Entity::Player& player ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    player.sendDebug( "emote: {}", emoteId );
    onProgress( player, actorId, actor, 1, emoteId );
  }

  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
  {
    onProgress( player, npcId, 0, 2, 0 );
  }

  void onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( player, param1, param1, 3, 0 );
  }

  void onEnterTerritory( Sapphire::Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2 ) override
  {
    onProgress( player, param1, param2, 4, 0 );
  }

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 4, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestBitFlag8( getId(), 1, false );
          player.setQuestBitFlag8( getId(), 5, false );
          player.setQuestBitFlag8( getId(), 6, false );
          player.updateQuest( getId(), 3 );
        }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 4 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "ManFst407:66057 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "ManFst407:66057 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00003: Normal(Talk, YesNo, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 156, 0.64f, -158.5f, 13.4f, 3.14f, false );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(4)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00008: Normal(CutScene, AutoFadeIn), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 4, true );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 335 );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 1, Flag8(4)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00009: Normal(Talk, TargetCanMove), id=CID" );
    player.playScene( getId(), 9, NONE, nullptr );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00010: Normal(Talk, TargetCanMove), id=GLAUMUNT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR7, UI8BL = 1, Flag8(1)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00011: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_A" );
    player.playScene( getId(), 11, NONE, nullptr );
  }
  void Scene00012( Entity::Player& player ) //SEQ_2: ACTOR7, UI8BL = 1, Flag8(1)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00012: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_A" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR7, UI8BL = 1, Flag8(1)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00013: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_A" );
    player.playScene( getId(), 13, NONE, nullptr );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00014: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 335 );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00015: Normal(Talk, TargetCanMove), id=GLAUMUNT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player ) //SEQ_2: ACTOR9, UI8AL = 1, Flag8(5)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00017: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_B" );
    player.playScene( getId(), 17, NONE, nullptr );
  }
  void Scene00018( Entity::Player& player ) //SEQ_2: ACTOR9, UI8AL = 1, Flag8(5)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00018: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_B" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 5, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player ) //SEQ_2: ACTOR9, UI8AL = 1, Flag8(5)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00019: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_B" );
    player.playScene( getId(), 19, NONE, nullptr );
  }

  void Scene00020( Entity::Player& player ) //SEQ_2: ACTOR10, UI8BH = 1, Flag8(6)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00020: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_C" );
    player.playScene( getId(), 20, NONE, nullptr );
  }
  void Scene00021( Entity::Player& player ) //SEQ_2: ACTOR10, UI8BH = 1, Flag8(6)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00021: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_C" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 6, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }
  void Scene00022( Entity::Player& player ) //SEQ_2: ACTOR10, UI8BH = 1, Flag8(6)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00022: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_C" );
    player.playScene( getId(), 22, NONE, nullptr );
  }

  void Scene00023( Entity::Player& player ) //SEQ_3: ACTOR11, UI8AL = 1, Flag8(1)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00023: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_D" );
    player.playScene( getId(), 23, NONE, nullptr );
  }
  void Scene00024( Entity::Player& player ) //SEQ_3: ACTOR11, UI8AL = 1, Flag8(1)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00024: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_D" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }
  void Scene00025( Entity::Player& player ) //SEQ_3: ACTOR11, UI8AL = 1, Flag8(1)=True, Branch
  {
    player.sendDebug( "ManFst407:66057 calling Scene00025: Normal(Talk, TargetCanMove), id=IMPERIALSOLDIER_D" );
    player.playScene( getId(), 25, NONE, nullptr );
  }

  void Scene00026( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00026: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 335 );
      }
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00027: Normal(Talk, TargetCanMove), id=GLAUMUNT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player ) //SEQ_4: ACTOR12, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "ManFst407:66057 calling Scene00029: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00030( player );
      }
    };
    player.playScene( getId(), 29, NONE, callback );
  }
  void Scene00030( Entity::Player& player ) //SEQ_4: ACTOR12, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "ManFst407:66057 calling Scene00030: Normal(FadeIn, TargetCanMove, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00031: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 335 );
      }
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00032: Normal(Talk, TargetCanMove), id=GLAUMUNT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player ) //SEQ_5: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "ManFst407:66057 calling Scene00035: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        //quest battle
        player.eventFinish( getId(), 1 );
        auto& pTeriMgr = Common::Service< Sapphire::World::Manager::TerritoryMgr >::ref();
        pTeriMgr.createAndJoinQuestBattle( player, 65 );
      }
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player ) //SEQ_5: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00036: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 335 );
      }
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player ) //SEQ_5: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00037: Normal(Talk, TargetCanMove), id=GLAUMUNT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player ) //SEQ_5: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00038: Normal(None), id=unknown" );
  }

  void Scene00039( Entity::Player& player ) //SEQ_5: ACTOR14, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player ) //SEQ_6: , <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00040: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 40, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00041( Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00041: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    player.sendDebug( "ManFst407:66057 calling Scene00042: Normal(Talk, YesNo, TargetCanMove), id=ELYENORA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 42, NONE, callback );
  }
};

EXPOSE_SCRIPT( ManFst407 );
