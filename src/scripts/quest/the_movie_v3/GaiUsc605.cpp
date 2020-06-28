// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc605 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc605() : Sapphire::ScriptAPI::EventScript( 66541 ){}; 
  ~GaiUsc605() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_3, 2 entries
  //SEQ_4, 4 entries
  //SEQ_5, 5 entries
  //SEQ_6, 5 entries
  //SEQ_7, 5 entries
  //SEQ_8, 4 entries
  //SEQ_9, 4 entries
  //SEQ_10, 5 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006555
  //ACTOR1 = 1006530
  //ACTOR2 = 1006557
  //ACTOR3 = 1004093
  //ACTOR4 = 1006559
  //ACTOR5 = 1006558
  //ACTOR6 = 1006560
  //ACTOR7 = 1006561
  //EOBJECT0 = 2002523
  //EOBJECT1 = 2002524
  //EOBJECT2 = 2002525
  //EOBJECT3 = 2002531
  //EVENTRANGE0 = 4322856
  //EVENTRANGE1 = 4322857
  //EVENTRANGE2 = 4322858
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000772
  //LEVELARMORID = 4265706
  //LEVELBIGGSID = 4265705
  //LEVELCIDID = 4265703
  //LEVELWEDGEID = 4265704
  //LINKSE1 = 42
  //LINKTALKSHAPE1 = 6
  //LOCACTION0 = 1015
  //LOCACTION1 = 858
  //LOCACTION2 = 112
  //LOCACTION3 = 1005
  //LOCACTOR0 = 1002908
  //LOCACTOR1 = 1003837
  //LOCACTOR2 = 1003855
  //LOCACTOR3 = 1003836
  //LOCACTOR9 = 1003075
  //LOCFACE0 = 604
  //LOCFACE1 = 605
  //LOCFACE2 = 620
  //LOCPOSACTOR0 = 4330073
  //LOCPOSACTOR1 = 4330075
  //LOCSE1 = 46
  //MOUNT0 = 14
  //POPRANGE0 = 4321644
  //POPRANGE1 = 4322935
  //QUESTBATTLE0 = 64
  //TERRITORYTYPE0 = 156
  //TERRITORYTYPE1 = 309

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1006555 || actorId == 1006555 ) // ACTOR0 = CID
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CID
        }
        if( actor == 1006530 || actorId == 1006530 ) // ACTOR1 = SLAFBORN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, YesNo, TargetCanMove), id=SLAFBORN
        }
        break;
      }
      case 1:
      {
        if( actor == 1006557 || actorId == 1006557 ) // ACTOR2 = WEDGE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=WEDGE
          }
        }
        if( actor == 1006530 || actorId == 1006530 ) // ACTOR1 = SLAFBORN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, YesNo, TargetCanMove), id=SLAFBORN
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=SERENDIPITY
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( actor == 1006557 || actorId == 1006557 ) // ACTOR2 = WEDGE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=WEDGE
          }
        }
        if( actor == 1006530 || actorId == 1006530 ) // ACTOR1 = SLAFBORN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, YesNo, TargetCanMove), id=SLAFBORN
        }
        break;
      }
      case 4:
      {
        if( actor == 1006559 || actorId == 1006559 ) // ACTOR4 = WEDGE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=WEDGE
          }
        }
        if( actor == 1006558 || actorId == 1006558 ) // ACTOR5 = CID
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1006560 || actorId == 1006560 ) // ACTOR6 = BIGGS
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1006561 || actorId == 1006561 ) // ACTOR7 = MAGITEKARMOR
        {
          Scene00012( player ); // Scene00012: Normal(Talk), id=MAGITEKARMOR
          // +Callback Scene00013: Normal(None), id=unknown
        }
        break;
      }
      case 5:
      {
        if( actor == 4322856 || actorId == 4322856 ) // EVENTRANGE0 = WEDGE
        {
          Scene00014( player ); // Scene00014: Normal(Talk), id=WEDGE
        }
        if( actor == 1006558 || actorId == 1006558 ) // ACTOR5 = CID
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          // +Callback Scene00016: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1006559 || actorId == 1006559 ) // ACTOR4 = WEDGE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1006560 || actorId == 1006560 ) // ACTOR6 = BIGGS
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 2002523 || actorId == 2002523 ) // EOBJECT0 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          // +Callback Scene00020: Normal(None), id=unknown
        }
        break;
      }
      case 6:
      {
        if( actor == 4322857 || actorId == 4322857 ) // EVENTRANGE1 = WEDGE
        {
          Scene00021( player ); // Scene00021: Normal(Talk), id=WEDGE
        }
        if( actor == 1006558 || actorId == 1006558 ) // ACTOR5 = CID
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1006559 || actorId == 1006559 ) // ACTOR4 = WEDGE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1006560 || actorId == 1006560 ) // ACTOR6 = BIGGS
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 2002524 || actorId == 2002524 ) // EOBJECT1 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          // +Callback Scene00026: Normal(None), id=unknown
        }
        break;
      }
      case 7:
      {
        if( actor == 4322858 || actorId == 4322858 ) // EVENTRANGE2 = WEDGE
        {
          Scene00027( player ); // Scene00027: Normal(Talk, Dismount), id=WEDGE
        }
        if( actor == 1006558 || actorId == 1006558 ) // ACTOR5 = CID
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          // +Callback Scene00029: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1006559 || actorId == 1006559 ) // ACTOR4 = WEDGE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1006560 || actorId == 1006560 ) // ACTOR6 = BIGGS
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 2002525 || actorId == 2002525 ) // EOBJECT2 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          // +Callback Scene00033: Normal(None), id=unknown
        }
        break;
      }
      case 8:
      {
        if( actor == 1006559 || actorId == 1006559 ) // ACTOR4 = WEDGE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=WEDGE
          }
        }
        if( actor == 1006558 || actorId == 1006558 ) // ACTOR5 = CID
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1006560 || actorId == 1006560 ) // ACTOR6 = BIGGS
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1006561 || actorId == 1006561 ) // ACTOR7 = MAGITEKARMOR
        {
          Scene00037( player ); // Scene00037: Normal(Talk), id=MAGITEKARMOR
        }
        break;
      }
      case 9:
      {
        if( actor == 1006559 || actorId == 1006559 ) // ACTOR4 = WEDGE
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1006558 || actorId == 1006558 ) // ACTOR5 = CID
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1006560 || actorId == 1006560 ) // ACTOR6 = BIGGS
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1006561 || actorId == 1006561 ) // ACTOR7 = MAGITEKARMOR
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00041( player ); // Scene00041: Normal(Talk), id=MAGITEKARMOR
            // +Callback Scene00042: Normal(Talk), id=MAGITEKARMOR
          }
          else
          {
            Scene00043( player ); // Scene00043: Normal(Talk), id=MAGITEKARMOR
          }
        }
        break;
      }
      case 10:
      {
        if( actor == 1006560 || actorId == 1006560 ) // ACTOR6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00044( player ); // Scene00044: Normal(QuestBattle, YesNo), id=unknown
          }
        }
        if( actor == 1006558 || actorId == 1006558 ) // ACTOR5 = CID
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1006559 || actorId == 1006559 ) // ACTOR4 = WEDGE
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1006561 || actorId == 1006561 ) // ACTOR7 = MAGITEKARMOR
        {
          Scene00047( player ); // Scene00047: Normal(Talk), id=MAGITEKARMOR
        }
        if( actor == 2002531 || actorId == 2002531 ) // EOBJECT3 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
          // +Callback Scene00049: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1006555 || actorId == 1006555 ) // ACTOR0 = CID
        {
          Scene00050( player ); // Scene00050: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID
        }
        if( actor == 1006530 || actorId == 1006530 ) // ACTOR1 = SLAFBORN
        {
          Scene00051( player ); // Scene00051: Normal(Talk, YesNo, TargetCanMove), id=SLAFBORN
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
    onProgress( player, actorId, actor, 1, emoteId );
  }

  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
  {
    onProgress( player, npcId, 0, 2, 0 );
  }

  void onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( player, param1, param1, 3, param1 );
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
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
    player.setQuestUI8BH( getId(), 1 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 6 );
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    player.updateQuest( getId(), 7 );
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    player.updateQuest( getId(), 8 );
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 9 );
    }
  }
  void checkProgressSeq9( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 10 );
    }
  }
  void checkProgressSeq10( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00002: Normal(Talk, YesNo, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.setPosAndSendActorMove( 0.64, -158.5, 13.4, 3.13 );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00003: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00004: Normal(Talk, YesNo, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.setPosAndSendActorMove( 0.64, -158.5, 13.4, 3.13 );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00005: Normal(Talk, TargetCanMove), id=SERENDIPITY" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00007( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling [BranchTrue]Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00008: Normal(Talk, YesNo, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.setPosAndSendActorMove( 0.64, -158.5, 13.4, 3.13 );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00009: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
      player.eventFinish( getId(), 1 );
      player.mount( 14 );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00010: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00011: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00012: Normal(Talk), id=MAGITEKARMOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling [BranchTrue]Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00014: Normal(Talk), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00015: Normal(None), id=unknown" );
    Scene00016( player );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling [BranchTrue]Scene00016: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00017: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.eventFinish( getId(), 1 );
      player.mount( 14 );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00018: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00019: Normal(None), id=unknown" );
    Scene00020( player );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling [BranchTrue]Scene00020: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00021: Normal(Talk), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00022: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00023: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.eventFinish( getId(), 1 );
      player.mount( 14 );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00024: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00025: Normal(None), id=unknown" );
    Scene00026( player );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling [BranchTrue]Scene00026: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00027: Normal(Talk, Dismount), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00028: Normal(None), id=unknown" );
    Scene00029( player );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling [BranchTrue]Scene00029: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00030: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.eventFinish( getId(), 1 );
      player.mount( 14 );
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00031: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00032: Normal(None), id=unknown" );
    Scene00033( player );
  }
  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling [BranchTrue]Scene00033: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00034: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 53 )
      {
        player.sendUrgent( "There is a bug after the dismount preventing the client from playing further events. Please re-login." );
      }
      else
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq8( player );
      }
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00035: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00036: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00037: Normal(Talk), id=MAGITEKARMOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00038: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00039: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00040: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00041: Normal(Talk), id=MAGITEKARMOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00042( player );
    };
    player.playScene( getId(), 41, NONE, callback );
  }
  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling [BranchTrue]Scene00042: Normal(Talk), id=MAGITEKARMOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq9( player );
    };
    player.playScene( getId(), 42, NONE, callback );
  }
  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling [BranchFalse]Scene00043: Normal(Talk), id=MAGITEKARMOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00044: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq10( player );
      }
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00045: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00046: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00047: Normal(Talk), id=MAGITEKARMOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00048: Normal(None), id=unknown" );
    Scene00049( player );
  }
  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling [BranchTrue]Scene00049: Normal(None), id=unknown" );
    checkProgressSeq10( player );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00050: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc605:66541 calling Scene00051: Normal(Talk, YesNo, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.setPosAndSendActorMove( 0.64, -158.5, 13.4, 3.13 );
      }
    };
    player.playScene( getId(), 51, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsc605 );
