// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_3 = CRYSTALGATEKEEPER
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmf103 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmf103() : Sapphire::ScriptAPI::EventScript( 69182 ){}; 
  ~LucKmf103() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 2 entries
  //SEQ_255, 12 entries

  //ACTOR0 = 1030369
  //ACTOR1 = 1030533
  //ACTOR10 = 1027854
  //ACTOR11 = 1027232
  //ACTOR12 = 1027248
  //ACTOR13 = 1027246
  //ACTOR14 = 1027224
  //ACTOR15 = 1027322
  //ACTOR2 = 1030370
  //ACTOR3 = 1027225
  //ACTOR4 = 1030327
  //ACTOR5 = 1030322
  //ACTOR6 = 1030323
  //ACTOR7 = 1030324
  //ACTOR8 = 1030325
  //ACTOR9 = 1030326
  //CUTSCENE0 = 2056
  //CUTSCENE1 = 2057
  //LOCBGM01 = 659
  //POPRANGE0 = 7936302
  //QUEST01 = 66031
  //QUEST02 = 66737

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LYNA
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CRYSTALGATEKEEPER
        // +Callback Scene00003: Normal(CutScene, AutoFadeIn), id=CRYSTALGATEKEEPER
        break;
      }
      case 2:
      {
        Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove, Menu), id=LYNA
        break;
      }
      case 3:
      {
        if( param1 == 1027225 || param2 == 1027225 ) // ACTOR3 = BOARDINGGATETOKHOLUSIA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=BOARDINGGATETOKHOLUSIA
            // +Callback Scene00006: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1030370 || param2 == 1030370 ) // ACTOR2 = LYNA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030327 || param2 == 1030327 ) // ACTOR4 = URIANGER
        {
          Scene00008( player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030322 || param2 == 1030322 ) // ACTOR5 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030323 || param2 == 1030323 ) // ACTOR6 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030324 || param2 == 1030324 ) // ACTOR7 = THANCRED
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030325 || param2 == 1030325 ) // ACTOR8 = RYNE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030326 || param2 == 1030326 ) // ACTOR9 = YSHTOLA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1027854 || param2 == 1027854 ) // ACTOR10 = CASSARD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=CASSARD
          break;
        }
        if( param1 == 1027232 || param2 == 1027232 ) // ACTOR11 = KATLISS
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=KATLISS
          break;
        }
        if( param1 == 1027248 || param2 == 1027248 ) // ACTOR12 = CHESSAMILE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=CHESSAMILE
          break;
        }
        if( param1 == 1027246 || param2 == 1027246 ) // ACTOR13 = SZEMDJENMAI
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=SZEMDJENMAI
          break;
        }
        if( param1 == 1027224 || param2 == 1027224 ) // ACTOR14 = BRAGI
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=BRAGI
          break;
        }
        if( param1 == 1027322 || param2 == 1027322 ) // ACTOR15 = GLYNARD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=GLYNARD
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmf103:69182 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00002: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CRYSTALGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00003( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00003: Normal(CutScene, AutoFadeIn), id=CRYSTALGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00004: Normal(Talk, TargetCanMove, Menu), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00005: Normal(Talk, TargetCanMove), id=BOARDINGGATETOKHOLUSIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00006: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00007: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER" );
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
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00011: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00012: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00014: Normal(Talk, TargetCanMove), id=CASSARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00015: Normal(Talk, TargetCanMove), id=KATLISS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00016: Normal(Talk, TargetCanMove), id=CHESSAMILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00017: Normal(Talk, TargetCanMove), id=SZEMDJENMAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00018: Normal(Talk, TargetCanMove), id=BRAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmf103:69182 calling Scene00019: Normal(Talk, TargetCanMove), id=GLYNARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmf103 );
