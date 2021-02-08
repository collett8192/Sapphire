// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma402 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma402() : Sapphire::ScriptAPI::EventScript( 68837 ){}; 
  ~LucKma402() = default; 

  //SEQ_0, 10 entries
  //SEQ_1, 8 entries
  //SEQ_2, 8 entries
  //SEQ_3, 7 entries
  //SEQ_255, 4 entries

  //ACTIONTIMELINEEVENTBASESTANDDRINKMUG = 5650
  //ACTIONTIMELINEEVENTBASEWALL = 807
  //ACTIONTIMELINEEVENTSALUTECLM = 5618
  //ACTOR0 = 1029846
  //ACTOR1 = 1029847
  //ACTOR10 = 1028929
  //ACTOR11 = 1028936
  //ACTOR12 = 1028923
  //ACTOR13 = 1027224
  //ACTOR14 = 1027322
  //ACTOR15 = 1029889
  //ACTOR16 = 1030964
  //ACTOR17 = 1031158
  //ACTOR18 = 1028389
  //ACTOR19 = 1030610
  //ACTOR2 = 1029848
  //ACTOR20 = 1030830
  //ACTOR3 = 1029849
  //ACTOR4 = 1028930
  //ACTOR5 = 1028931
  //ACTOR6 = 1028932
  //ACTOR7 = 1028933
  //ACTOR8 = 1028934
  //ACTOR9 = 1028935
  //BINDACTOR0 = 7929693
  //BINDACTOR1 = 7929694
  //BINDACTOR2 = 7929695
  //BINDACTOR3 = 7929696
  //BINDACTOR4 = 7928725
  //BINDACTOR5 = 7960743
  //CUTSCENE0 = 1979
  //CUTSCENE1 = 1980
  //CUTSCENE2 = 1981
  //LCUTACTOR0 = 1028190
  //LCUTACTOR1 = 1030128
  //LCUTACTOR2 = 1028882
  //LCUTACTOR3 = 1029423
  //LCUTBGM0 = 647
  //LCUTPOS0 = 7928683
  //LCUTPOS1 = 7964570
  //LCUTPOS2 = 7951534
  //LCUTPOS3 = 8030880
  //POPRANGE0 = 7947223

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029846 || param2 == 1029846 ) // ACTOR0 = MYSTERYVOICE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1029847 || param2 == 1029847 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029848 || param2 == 1029848 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1029849 || param2 == 1029849 ) // ACTOR3 = LYNA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        if( param1 == 1028930 || param2 == 1028930 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028931 || param2 == 1028931 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028932 || param2 == 1028932 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028933 || param2 == 1028933 ) // ACTOR7 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028934 || param2 == 1028934 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028935 || param2 == 1028935 ) // ACTOR9 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1028929 || param2 == 1028929 ) // ACTOR10 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1028936 || param2 == 1028936 ) // ACTOR11 = LYNA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        if( param1 == 1028923 || param2 == 1028923 ) // ACTOR12 = MYSTERYVOICE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1028931 || param2 == 1028931 ) // ACTOR5 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028932 || param2 == 1028932 ) // ACTOR6 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028933 || param2 == 1028933 ) // ACTOR7 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028934 || param2 == 1028934 ) // ACTOR8 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028935 || param2 == 1028935 ) // ACTOR9 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1027224 || param2 == 1027224 ) // ACTOR13 = BRAGI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=BRAGI
          }
          break;
        }
        if( param1 == 1028936 || param2 == 1028936 ) // ACTOR11 = LYNA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        if( param1 == 1028923 || param2 == 1028923 ) // ACTOR12 = MYSTERYVOICE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1028931 || param2 == 1028931 ) // ACTOR5 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028932 || param2 == 1028932 ) // ACTOR6 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028933 || param2 == 1028933 ) // ACTOR7 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028934 || param2 == 1028934 ) // ACTOR8 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028935 || param2 == 1028935 ) // ACTOR9 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1027322 || param2 == 1027322 ) // ACTOR14 = GLYNARD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=GLYNARD
          }
          break;
        }
        if( param1 == 1029889 || param2 == 1029889 ) // ACTOR15 = GRANSON
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=GRANSON
          break;
        }
        if( param1 == 1030964 || param2 == 1030964 ) // ACTOR16 = LUEREEQ
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=LUEREEQ
          break;
        }
        if( param1 == 1031158 || param2 == 1031158 ) // ACTOR17 = GIOTT
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=GIOTT
          break;
        }
        if( param1 == 1028389 || param2 == 1028389 ) // ACTOR18 = CERIGG
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=CERIGG
          break;
        }
        if( param1 == 1027224 || param2 == 1027224 ) // ACTOR13 = BRAGI
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=BRAGI
          break;
        }
        if( param1 == 1028923 || param2 == 1028923 ) // ACTOR12 = MYSTERYVOICE
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030610 || param2 == 1030610 ) // ACTOR19 = GUIDEOFTHEPENDANTS
        {
          Scene00034( player ); // Scene00034: Normal(Talk, YesNo, QuestReward, QuestComplete, TargetCanMove, CanCancel), id=GUIDEOFTHEPENDANTS
          // +Callback Scene00035: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1027322 || param2 == 1027322 ) // ACTOR14 = GLYNARD
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=GLYNARD
          break;
        }
        if( param1 == 1030830 || param2 == 1030830 ) // ACTOR20 = CYELLA
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=CYELLA
          break;
        }
        if( param1 == 1028923 || param2 == 1028923 ) // ACTOR12 = MYSTERYVOICE
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKma402:68837 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00004: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00012: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00013: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00019: Normal(Talk, TargetCanMove), id=BRAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00020: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00021: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00027: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=GLYNARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00028: Normal(Talk, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00029: Normal(Talk, TargetCanMove), id=LUEREEQ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00030: Normal(Talk, TargetCanMove), id=GIOTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00031: Normal(Talk, TargetCanMove), id=CERIGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00032: Normal(Talk, TargetCanMove), id=BRAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00033: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00034: Normal(Talk, YesNo, QuestReward, QuestComplete, TargetCanMove, CanCancel), id=GUIDEOFTHEPENDANTS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00035( player );
      }
    };
    player.playScene( getId(), 34, NONE, callback );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00035: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
        player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
        player.eventFinish( getId(), 1 );
        player.forceZoneing();
      }
    };
    player.playScene( getId(), 35, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00036: Normal(Talk, TargetCanMove), id=GLYNARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00037: Normal(Talk, TargetCanMove), id=CYELLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKma402:68837 calling Scene00038: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKma402 );
