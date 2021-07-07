// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmh106 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmh106() : Sapphire::ScriptAPI::EventScript( 69302 ){}; 
  ~LucKmh106() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 5 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1029234
  //ACTOR1 = 1032506
  //ACTOR10 = 1032516
  //ACTOR11 = 1032517
  //ACTOR2 = 1032507
  //ACTOR3 = 1032508
  //ACTOR4 = 1032263
  //ACTOR5 = 1032532
  //ACTOR6 = 1027750
  //ACTOR7 = 1032513
  //ACTOR8 = 1032515
  //ACTOR9 = 1029197
  //ITEM0 = 2002970
  //LOCACTIONEVENTADDLOOK = 5522
  //LOCBINDALMET = 8259969
  //LOCBINDCYMET = 8259971
  //LOCBINDUIMET = 8259970
  //LOCBINDYSHTOLA = 8261104
  //NCUTLUCKMH00100 = 2241
  //NCUTLUCKMH00110 = 2242
  //POPRANGE0 = 8260018
  //QUESTLUCKRA206 = 69328

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029234 || param2 == 1029234 ) // ACTOR0 = YSHTOLA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032506 || param2 == 1032506 ) // ACTOR1 = ALMET
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1032507 || param2 == 1032507 ) // ACTOR2 = UIMET
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1032508 || param2 == 1032508 ) // ACTOR3 = CYMET
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1032263 || param2 == 1032263 ) // ACTOR4 = RUNAR
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=RUNAR
          }
          break;
        }
        if( param1 == 1032532 || param2 == 1032532 ) // ACTOR5 = YSHTOLA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032506 || param2 == 1032506 ) // ACTOR1 = ALMET
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1032507 || param2 == 1032507 ) // ACTOR2 = UIMET
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1032508 || param2 == 1032508 ) // ACTOR3 = CYMET
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( param1 == 1027750 || param2 == 1027750 ) // ACTOR6 = ASGEIR
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ASGEIR
          }
          break;
        }
        if( param1 == 1032513 || param2 == 1032513 ) // ACTOR7 = YSHTOLA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032506 || param2 == 1032506 ) // ACTOR1 = ALMET
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1032507 || param2 == 1032507 ) // ACTOR2 = UIMET
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1032508 || param2 == 1032508 ) // ACTOR3 = CYMET
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 1032513 || param2 == 1032513 ) // ACTOR7 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00016: Normal(Talk, TargetCanMove), id=YSHTOLA
            // +Callback Scene00017: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1027750 || param2 == 1027750 ) // ACTOR6 = ASGEIR
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ASGEIR
          break;
        }
        if( param1 == 1032506 || param2 == 1032506 ) // ACTOR1 = ALMET
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1032507 || param2 == 1032507 ) // ACTOR2 = UIMET
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1032508 || param2 == 1032508 ) // ACTOR3 = CYMET
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1032515 || param2 == 1032515 ) // ACTOR8 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1029197 || param2 == 1029197 ) // ACTOR9 = RUNAR
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=RUNAR
          break;
        }
        if( param1 == 1032516 || param2 == 1032516 ) // ACTOR10 = RYNE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1032517 || param2 == 1032517 ) // ACTOR11 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1032506 || param2 == 1032506 ) // ACTOR1 = ALMET
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1032507 || param2 == 1032507 ) // ACTOR2 = UIMET
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1032508 || param2 == 1032508 ) // ACTOR3 = CYMET
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=CYMET
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
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmh106:69302 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00002: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00003: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00004: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00007: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00008: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00009: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00010: Normal(Talk, TargetCanMove), id=ASGEIR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00012: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00013: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00014: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00016( player );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00016: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00017: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00018: Normal(Talk, TargetCanMove), id=ASGEIR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00019: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00020: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00021: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00022: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00023: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00024: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00026: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00027: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmh106:69302 calling Scene00028: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmh106 );
