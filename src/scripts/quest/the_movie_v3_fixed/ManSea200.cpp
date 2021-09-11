// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManSea200 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManSea200() : Sapphire::ScriptAPI::EventScript( 66082 ){}; 
  ~ManSea200() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 3 entries
  //SEQ_4, 4 entries
  //SEQ_5, 4 entries
  //SEQ_6, 3 entries
  //SEQ_7, 4 entries
  //SEQ_8, 5 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1002694
  //ACTOR1 = 1001029
  //ACTOR10 = 1001821
  //ACTOR2 = 1000972
  //ACTOR3 = 1002695
  //ACTOR4 = 1002830
  //ACTOR5 = 1000109
  //ACTOR6 = 1000460
  //ACTOR7 = 1000106
  //ACTOR8 = 1004336
  //ACTOR9 = 1004434
  //EOBJECT0 = 2001675
  //EOBJECT1 = 2001668
  //EOBJECT2 = 2001678
  //EOBJECT3 = 2001671
  //EOBJECT4 = 2001688
  //EVENTACTIONWAITINGSHOR = 11
  //ITEM0 = 2000458
  //ITEM1 = 2000459
  //NCUTEVENT001 = 212
  //NCUTEVENT002 = 213
  //NCUTEVENT003 = 214
  //NCUTEVENT004 = 154
  //NCUTEVENT005 = 67
  //NCUTEVENT006 = 99
  //NCUTEVENT007 = 156
  //NCUTEVENT008 = 100
  //NCUTEVENT009 = 159
  //NCUTEVENT010 = 232
  //NCUTEVENT011 = 231
  //NCUTEVENT012 = 228
  //NCUTEVENT013 = 227
  //NCUTEVENT014 = 231
  //NCUTEVENT015 = 229
  //POPRANGE0 = 4146949
  //POPRANGE1 = 4103402
  //POPRANGE2 = 4102803
  //POPRANGE3 = 4103382
  //POPRANGE4 = 4103392
  //POPRANGE5 = 4102780
  //POPRANGE6 = 4103339
  //TERRITORYTYPE0 = 198
  //TERRITORYTYPE1 = 128
  //TERRITORYTYPE2 = 132
  //TERRITORYTYPE3 = 130
  //UNLOCKIMAGEAIRSHIP = 68

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack 1
      //seq 0 event item ITEM1 = UI8BL max stack 1
      case 0:
      {
        if( param1 == 1002694 || param2 == 1002694 ) // ACTOR0 = MERLWYB
        {
          Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=MERLWYB
          // +Callback Scene00001: Normal(CutScene, QuestAccept), id=unknown
          break;
        }
        if( param1 == 1001029 || param2 == 1001029 ) // ACTOR1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(YesNo, TargetCanMove), id=unknown
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      //seq 1 event item ITEM1 = UI8BL max stack 1
      case 1:
      {
        Scene00003( player ); // Scene00003: Normal(CutScene), id=unknown
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      //seq 2 event item ITEM1 = UI8BL max stack 1
      case 2:
      {
        if( param1 == 1002695 || param2 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          }
          break;
        }
        if( param1 == 2001675 || param2 == 2001675 ) // EOBJECT0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      //seq 3 event item ITEM1 = UI8BL max stack 1
      case 3:
      {
        if( param1 == 2001668 || param2 == 2001668 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(YesNo, CanCancel), id=unknown
            // +Callback Scene00008: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1002695 || param2 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00009( player ); // Scene00009: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          break;
        }
        if( param1 == 2001675 || param2 == 2001675 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      //seq 4 event item ITEM1 = UI8BL max stack 1
      case 4:
      {
        if( param1 == 1002830 || param2 == 1002830 ) // ACTOR4 = SERPENT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=SERPENT
          }
          break;
        }
        if( param1 == 4296108319  || param2 == 1000109 ) // ACTOR5 = CABINCREW
        {
          Scene00012( player ); // Scene00012: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CABINCREW
          break;
        }
        if( param1 == 2001678 || param2 == 2001678 ) // EOBJECT2 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002695 || param2 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00014( player ); // Scene00014: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          // +Callback Scene00015: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 1
      //seq 5 event item ITEM1 = UI8BL max stack 1
      case 5:
      {
        if( param1 == 1000460 || param2 == 1000460 ) // ACTOR6 = DOORMANLOTUS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00017: Normal(Talk, TargetCanMove), id=DOORMANLOTUS
            // +Callback Scene00018: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1002830 || param2 == 1002830 ) // ACTOR4 = SERPENT
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=SERPENT
          break;
        }
        if( param1 == 2001678 || param2 == 2001678 ) // EOBJECT2 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002695 || param2 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00022( player ); // Scene00022: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          // +Callback Scene00023: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      //seq 6 event item ITEM1 = UI8BH max stack 1
      case 6:
      {
        if( param1 == 1000106 || param2 == 1000106 ) // ACTOR7 = LIONNELLAIS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS
          }
          break;
        }
        if( param1 == 2001678 || param2 == 2001678 ) // EOBJECT2 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002695 || param2 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00026( player ); // Scene00026: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          // +Callback Scene00027: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      //seq 7 event item ITEM1 = UI8BH max stack 1
      case 7:
      {
        if( param1 == 2001671 || param2 == 2001671 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00029( player ); // Scene00029: Normal(YesNo, CanCancel), id=unknown
            // +Callback Scene00030: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1000106 || param2 == 1000106 ) // ACTOR7 = LIONNELLAIS
        {
          Scene00031( player ); // Scene00031: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS
          break;
        }
        if( param1 == 2001678 || param2 == 2001678 ) // EOBJECT2 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002695 || param2 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00033( player ); // Scene00033: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          // +Callback Scene00034: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      //seq 8 event item ITEM1 = UI8BH max stack 1
      case 8:
      {
        if( param1 == 1004336 || param2 == 1004336 ) // ACTOR8 = FLAMEA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=FLAMEA
          }
          break;
        }
        if( param1 == 1004434 || param2 == 1004434 ) // ACTOR9 = CABINCREW
        {
          Scene00036( player ); // Scene00036: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CABINCREW
          break;
        }
        if( param1 == 2001688 || param2 == 2001688 ) // EOBJECT4 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002695 || param2 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00038( player ); // Scene00038: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          // +Callback Scene00039: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1000106 || param2 == 1000106 ) // ACTOR7 = LIONNELLAIS
        {
          Scene00040( player ); // Scene00040: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS
          // +Callback Scene00041: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1001821 || param2 == 1001821 ) // ACTOR10 = BARTHOLOMEW
        {
          Scene00042( player ); // Scene00042: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00043: Normal(Talk, TargetCanMove), id=BARTHOLOMEW
          // +Callback Scene00044: Normal(CutScene), id=unknown
          // +Callback Scene00045: Normal(QuestReward, QuestComplete, SystemTalk), id=unknown
          break;
        }
        if( param1 == 1004336 || param2 == 1004336 ) // ACTOR8 = FLAMEA
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=FLAMEA
          break;
        }
        if( param1 == 2001688 || param2 == 2001688 ) // EOBJECT4 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002695 || param2 == 1002695 ) // ACTOR3 = LNOPHLO
        {
          Scene00049( player ); // Scene00049: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO
          // +Callback Scene00050: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1000106 || param2 == 1000106 ) // ACTOR7 = LIONNELLAIS
        {
          Scene00051( player ); // Scene00051: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS
          // +Callback Scene00052: Normal(CutScene, AutoFadeIn), id=unknown
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestUI8BL( getId(), 1 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 8 );
    }
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=MERLWYB" );
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
    player.sendDebug( "ManSea200:66082 calling Scene00001: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00002: Normal(YesNo, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00004: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 128, -24.3, 92, 2.47, -0.37, false );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00007: Normal(YesNo, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00008( player );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00008: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 132, 7.8, -21.97, 123.88, 1.58, true );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00009: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 128, -24.3, 92, 2.47, -0.37, false );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00011: Normal(Talk, TargetCanMove), id=SERPENT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00012: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CABINCREW" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 132, 35.5, -19, 105, -3.14, false );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00014: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00015( player );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00015: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 132, 7.8, -21.97, 123.88, 1.58, true );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00016: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00017( player );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00017: Normal(Talk, TargetCanMove), id=DOORMANLOTUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00018: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00020: Normal(Talk, TargetCanMove), id=SERPENT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00022: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00023( player );
      }
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00023: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00024: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq6( player );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 132, 22.55, -19, 114.2, 0, false );
      }
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00025: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00026: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00027( player );
      }
    };
    player.playScene( getId(), 26, NONE, callback );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00027: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00029: Normal(YesNo, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00030( player );
      }
    };
    player.playScene( getId(), 29, NONE, callback );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00030: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 130, -44.14, 84, -0.47, 1.3, true );
    };
    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00031: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 132, 22.55, -19, 114.2, 0, false );
      }
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00032: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00033: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00034( player );
      }
    };
    player.playScene( getId(), 33, NONE, callback );
  }
  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00034: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 34, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00035: Normal(Talk, TargetCanMove), id=FLAMEA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00036: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CABINCREW" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 130, -19.45, 83.2, 3.85, 1.8, false );
      }
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00037: Normal(None), id=unknown" );
    checkProgressSeq8( player );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00038: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00039( player );
      }
    };
    player.playScene( getId(), 38, NONE, callback );
  }
  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00039: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 39, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00040: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00041( player );
      }
    };
    player.playScene( getId(), 40, NONE, callback );
  }
  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00041: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 130, -44.14, 84, -0.47, 1.3, true );
    };
    player.playScene( getId(), 41, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00042: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00043( player );
      }
    };
    player.playScene( getId(), 42, NONE, callback );
  }
  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00043: Normal(Talk, TargetCanMove), id=BARTHOLOMEW" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00044( player );
    };
    player.playScene( getId(), 43, NONE, callback );
  }
  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00044: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00045( player );
    };
    player.playScene( getId(), 44, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00045: Normal(QuestReward, QuestComplete, SystemTalk), id=unknown" );
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
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00047: Normal(Talk, TargetCanMove), id=FLAMEA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00048: Normal(None), id=unknown" );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00049: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LNOPHLO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00050( player );
      }
    };
    player.playScene( getId(), 49, NONE, callback );
  }
  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00050: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 50, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00051: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=LIONNELLAIS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00052( player );
      }
    };
    player.playScene( getId(), 51, NONE, callback );
  }
  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "ManSea200:66082 calling Scene00052: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 52, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( ManSea200 );
