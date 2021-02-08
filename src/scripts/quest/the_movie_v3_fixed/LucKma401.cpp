// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma401 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma401() : Sapphire::ScriptAPI::EventScript( 68836 ){}; 
  ~LucKma401() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_4, 4 entries
  //SEQ_5, 1 entries
  //SEQ_255, 10 entries

  //ACTOR0 = 1028923
  //ACTOR1 = 1028928
  //ACTOR10 = 1028933
  //ACTOR11 = 1028934
  //ACTOR12 = 1028935
  //ACTOR2 = 1029846
  //ACTOR3 = 1029847
  //ACTOR4 = 1029848
  //ACTOR5 = 1029849
  //ACTOR6 = 5010000
  //ACTOR7 = 1028930
  //ACTOR8 = 1028931
  //ACTOR9 = 1028932
  //BINDACTOR0 = 7929693
  //BINDACTOR1 = 7929694
  //BINDACTOR2 = 7929695
  //BINDACTOR3 = 7929696
  //CUTSCENE0 = 1975
  //CUTSCENE1 = 1976
  //CUTSCENE2 = 1977
  //CUTSCENE3 = 1978
  //INSTANCEDUNGEON0 = 72
  //LCUTBGM0 = 590
  //LCUTBGM1 = 707
  //POPRANGE0 = 7929699
  //SCREENIMAGE0 = 742
  //SCREENIMAGE1 = 829
  //TERRITORYTYPE0 = 813

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(CutScene, FadeIn, QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=MYSTERYVOICE
        break;
      }
      case 2:
      {
        Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=MYSTERYVOICE
        break;
      }
      case 3:
      {
        if( param1 == 1029846 || param2 == 1029846 ) // ACTOR2 = MYSTERYVOICE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=MYSTERYVOICE
          }
          break;
        }
        if( param1 == 1029847 || param2 == 1029847 ) // ACTOR3 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029848 || param2 == 1029848 ) // ACTOR4 = ALISAIE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1029849 || param2 == 1029849 ) // ACTOR5 = LYNA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1029846 || param2 == 1029846 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove, Menu), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1029847 || param2 == 1029847 ) // ACTOR3 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove, Menu), id=ALPHINAUD
          break;
        }
        if( param1 == 1029848 || param2 == 1029848 ) // ACTOR4 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove, Menu), id=ALISAIE
          break;
        }
        if( param1 == 1029849 || param2 == 1029849 ) // ACTOR5 = LYNA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove, Menu), id=LYNA
          break;
        }
        break;
      }
      case 5:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00012( player ); // Scene00012: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029846 || param2 == 1029846 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1029847 || param2 == 1029847 ) // ACTOR3 = ALPHINAUD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029848 || param2 == 1029848 ) // ACTOR4 = ALISAIE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1029849 || param2 == 1029849 ) // ACTOR5 = LYNA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        if( param1 == 1028930 || param2 == 1028930 ) // ACTOR7 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028931 || param2 == 1028931 ) // ACTOR8 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028932 || param2 == 1028932 ) // ACTOR9 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028933 || param2 == 1028933 ) // ACTOR10 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028934 || param2 == 1028934 ) // ACTOR11 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028935 || param2 == 1028935 ) // ACTOR12 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
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
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "LucKma401:68836 calling Scene00001: Normal(CutScene, FadeIn, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00007: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00008: Normal(Talk, TargetCanMove, Menu), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 )
      {
        Scene00012( player );
      }
      else
        player.sendUrgent( "Select anyone and hit cancel to progress." );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00009: Normal(Talk, TargetCanMove, Menu), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 )
      {
        Scene00012( player );
      }
      else
        player.sendUrgent( "Select anyone and hit cancel to progress." );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00010: Normal(Talk, TargetCanMove, Menu), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 )
      {
        Scene00012( player );
      }
      else
        player.sendUrgent( "Select anyone and hit cancel to progress." );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00011: Normal(Talk, TargetCanMove, Menu), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 )
      {
        Scene00012( player );
      }
      else
        player.sendUrgent( "Select anyone and hit cancel to progress." );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00012: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=MYSTERYVOICE" );
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
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00016: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKma401:68836 calling Scene00022: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( LucKma401 );
