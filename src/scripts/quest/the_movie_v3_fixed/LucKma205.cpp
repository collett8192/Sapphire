// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma205 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma205() : Sapphire::ScriptAPI::EventScript( 68822 ){}; 
  ~LucKma205() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 2 entries
  //SEQ_3, 3 entries
  //SEQ_4, 1 entries
  //SEQ_5, 2 entries
  //SEQ_6, 5 entries
  //SEQ_7, 3 entries
  //SEQ_8, 2 entries
  //SEQ_9, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1029822
  //ACTOR1 = 1029823
  //ACTOR10 = 1029990
  //ACTOR11 = 1029829
  //ACTOR12 = 1029830
  //ACTOR2 = 1029814
  //ACTOR3 = 1029824
  //ACTOR4 = 1029825
  //ACTOR5 = 1029826
  //ACTOR6 = 1027524
  //ACTOR7 = 1027526
  //ACTOR8 = 1029827
  //ACTOR9 = 5010000
  //BINDACTOR01 = 7929613
  //BINDACTOR02 = 7929614
  //BINDACTOR03 = 7929630
  //CUTSCENE0 = 1966
  //CUTSCENE1 = 1967
  //EOBJECT0 = 2009964
  //EOBJECT1 = 2009965
  //EOBJECT2 = 2009966
  //EOBJECT3 = 2009967
  //EVENTACTION0 = 12
  //EVENTACTION1 = 45
  //ITEM0 = 2002700
  //ITEM1 = 2002575
  //LOCACTION01 = 85
  //LOCACTOR01 = 1028361
  //LOCACTOR02 = 1028116
  //LOCACTOR03 = 1028117
  //LOCACTOR04 = 1028362
  //LOCACTOR05 = 1028363
  //LOCACTOR06 = 1028364
  //LOCACTOR07 = 1029366
  //LOCBGM01 = 362
  //LOCBGM02 = 711
  //LOCOBJECT01 = 2010515
  //LOCSE01 = 232
  //LOCSE02 = 124
  //LOCVFX01 = 739
  //POPRANGE0 = 7929610
  //POPRANGE1 = 8051279
  //POPRANGE2 = 7981125
  //TERRITORYTYPE0 = 820

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029822 || param2 == 1029822 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029823 || param2 == 1029823 ) // ACTOR1 = TRISTOL
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=TRISTOL
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2009964 || param2 == 2009964 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1029814 || param2 == 1029814 ) // ACTOR2 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029823 || param2 == 1029823 ) // ACTOR1 = TRISTOL
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=TRISTOL
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00007( player ); // Scene00007: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 2009964 || param2 == 2009964 ) // EOBJECT0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(YesNo), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1029824 || param2 == 1029824 ) // ACTOR3 = CLOWNOFRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=CLOWNOFRED
          }
          break;
        }
        if( param1 == 1029825 || param2 == 1029825 ) // ACTOR4 = CLOWNOFBLUE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CLOWNOFBLUE
          break;
        }
        if( param1 == 1029826 || param2 == 1029826 ) // ACTOR5 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        Scene00012( player ); // Scene00012: Normal(Talk, FadeIn, TargetCanMove), id=BUREAUOFIMMIGRATION
        break;
      }
      //seq 5 event item ITEM1 = UI8BH max stack ?
      //seq 5 event item ITEM0 = UI8BL max stack 1
      case 5:
      {
        if( param1 == 1027526 || param2 == 1027526 ) // ACTOR7 = BUREAUOFREGISTRATION
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00014: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=BUREAUOFREGISTRATION
          }
          break;
        }
        if( param1 == 1027524 || param2 == 1027524 ) // ACTOR6 = BUREAUOFIMMIGRATION
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=BUREAUOFIMMIGRATION
          break;
        }
        break;
      }
      //seq 6 event item ITEM1 = UI8BH max stack ?
      case 6:
      {
        if( param1 == 2009965 || param2 == 2009965 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(FadeIn, AutoFadeIn, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2009966 || param2 == 2009966 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(FadeIn, AutoFadeIn, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2009967 || param2 == 2009967 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(FadeIn, AutoFadeIn, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1029827 || param2 == 1029827 ) // ACTOR8 = ALPHINAUD
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1027526 || param2 == 1027526 ) // ACTOR7 = BUREAUOFREGISTRATION
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=BUREAUOFREGISTRATION
          break;
        }
        break;
      }
      //seq 7 event item ITEM1 = UI8BH max stack ?
      case 7:
      {
        if( param1 == 5010000 || param2 == 5010000 ) // ACTOR9 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1029827 || param2 == 1029827 ) // ACTOR8 = ALPHINAUD
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1027526 || param2 == 1027526 ) // ACTOR7 = BUREAUOFREGISTRATION
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=BUREAUOFREGISTRATION
          break;
        }
        break;
      }
      case 8:
      {
        if( param1 == 1029827 || param2 == 1029827 ) // ACTOR8 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove, Menu), id=ALPHINAUD
            // +Callback Scene00029: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1027526 || param2 == 1027526 ) // ACTOR7 = BUREAUOFREGISTRATION
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=BUREAUOFREGISTRATION
          break;
        }
        break;
      }
      case 9:
      {
        if( param1 == 1029990 || param2 == 1029990 ) // ACTOR10 = CORNENN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=CORNENN
          }
          break;
        }
        if( param1 == 1029829 || param2 == 1029829 ) // ACTOR11 = ALPHINAUD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1027526 || param2 == 1027526 ) // ACTOR7 = BUREAUOFREGISTRATION
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=BUREAUOFREGISTRATION
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029830 || param2 == 1029830 ) // ACTOR12 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(CutScene, AutoFadeIn), id=unknown
          // +Callback Scene00035: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1029990 || param2 == 1029990 ) // ACTOR10 = CORNENN
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=CORNENN
          break;
        }
        if( param1 == 1027526 || param2 == 1027526 ) // ACTOR7 = BUREAUOFREGISTRATION
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=BUREAUOFREGISTRATION
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
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
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 5 );
    player.setQuestUI8BH( getId(), 1 );
    player.setQuestUI8BL( getId(), 1 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
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
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 8 );
    }
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKma205:68822 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00002: Normal(Talk, TargetCanMove), id=TRISTOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00004: Normal(Talk, FadeIn, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 820, 0, -5, -110, 0, false );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00006: Normal(Talk, TargetCanMove), id=TRISTOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00007: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00008: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 820, 0, -5, -110, 0, false );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=CLOWNOFRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00010: Normal(Talk, TargetCanMove), id=CLOWNOFBLUE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00012: Normal(Talk, FadeIn, TargetCanMove), id=BUREAUOFIMMIGRATION" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00013: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00014( player );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00014: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=BUREAUOFREGISTRATION" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00015: Normal(Talk, TargetCanMove), id=BUREAUOFIMMIGRATION" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00017: Normal(FadeIn, AutoFadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
      player.sendUrgent( "Talk to Alphinaud for event item workaround." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00019: Normal(FadeIn, AutoFadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
      player.sendUrgent( "Talk to Alphinaud for event item workaround." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00021: Normal(FadeIn, AutoFadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
      player.sendUrgent( "Talk to Alphinaud for event item workaround." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00023: Normal(Talk, TargetCanMove), id=BUREAUOFREGISTRATION" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00024: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00024( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00027: Normal(Talk, TargetCanMove), id=BUREAUOFREGISTRATION" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00028: Normal(Talk, TargetCanMove, Menu), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00029( player );
      }
    };
    player.playScene( getId(), 28, NONE, callback );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00029: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00030: Normal(Talk, TargetCanMove), id=BUREAUOFREGISTRATION" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00031: Normal(Talk, TargetCanMove), id=CORNENN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq9( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00033: Normal(Talk, TargetCanMove), id=BUREAUOFREGISTRATION" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00034: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00035( player );
    };
    player.playScene( getId(), 34, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00035: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 35, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00036: Normal(Talk, TargetCanMove), id=CORNENN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKma205:68822 calling Scene00037: Normal(Talk, TargetCanMove), id=BUREAUOFREGISTRATION" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKma205 );
