// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_2 = ALISAIE
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBde107 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBde107() : Sapphire::ScriptAPI::EventScript( 68685 ){}; 
  ~StmBde107() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 4 entries
  //SEQ_2, 5 entries
  //SEQ_3, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1026242
  //ACTOR1 = 1026243
  //ACTOR10 = 1026250
  //ACTOR11 = 1026251
  //ACTOR12 = 1025549
  //ACTOR2 = 1026244
  //ACTOR3 = 1026245
  //ACTOR4 = 1026246
  //ACTOR5 = 1026247
  //ACTOR6 = 1026248
  //ACTOR7 = 1026240
  //ACTOR8 = 1026342
  //ACTOR9 = 1026249
  //LCUTENPCCAM01 = 1010402
  //LOCBINDALNSTN01 = 7605906
  //LOCBINDHYBSTN01 = 7588250
  //LOCBINDKNSMED01 = 7587634
  //LOCBINDLYSMED01 = 7587636
  //LOCBINDMLSLMS01 = 7588935
  //LOCBINDWRDMED01 = 7587635
  //LOCBINDYSHMED01 = 7587638
  //LOCFACE01 = 613
  //LOCFACE02 = 6215
  //LOCNCUT01 = 1819
  //LOCNCUT02 = 1820
  //LOCNCUT03 = 1821
  //LOCNCUT04 = 1822
  //POPRANGE0 = 7588253

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1026242 || param2 == 1026242 ) // ACTOR0 = ALISAIE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALISAIE
          // +Callback Scene00002: Normal(CutScene, AutoFadeIn), id=ALISAIE
          break;
        }
        if( param1 == 1026243 || param2 == 1026243 ) // ACTOR1 = KANESENNA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=KANESENNA
          break;
        }
        if( param1 == 1026244 || param2 == 1026244 ) // ACTOR2 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1026245 || param2 == 1026245 ) // ACTOR3 = LYSE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1026246 || param2 == 1026246 ) // ACTOR4 = YSHTOLA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1026247 || param2 == 1026247 ) // ACTOR5 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1026248 || param2 == 1026248 ) // ACTOR6 = HOARYBOULDER
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=HOARYBOULDER
          break;
        }
        if( param1 == 1026240 || param2 == 1026240 ) // ACTOR7 = RIOL
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=RIOL
          break;
        }
        if( param1 == 1026342 || param2 == 1026342 ) // ACTOR8 = EPHEMIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=EPHEMIE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1026249 || param2 == 1026249 ) // ACTOR9 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE
            // +Callback Scene00012: Normal(CutScene, TargetCanMove), id=unknown
          }
          break;
        }
        if( param1 == 1026248 || param2 == 1026248 ) // ACTOR6 = HOARYBOULDER
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=HOARYBOULDER
          break;
        }
        if( param1 == 1026250 || param2 == 1026250 ) // ACTOR10 = MAELSTROMOFFICER
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=MAELSTROMOFFICER
          break;
        }
        if( param1 == 1026240 || param2 == 1026240 ) // ACTOR7 = RIOL
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=RIOL
          break;
        }
        if( param1 == 1026342 || param2 == 1026342 ) // ACTOR8 = EPHEMIE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=EPHEMIE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1026249 || param2 == 1026249 ) // ACTOR9 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1026251 || param2 == 1026251 ) // ACTOR11 = MAELSTROMOFFICER
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=MAELSTROMOFFICER
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1025549 || param2 == 1025549 ) // ACTOR12 = ALISAIE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn), id=ALISAIE
          // +Callback Scene00020: Normal(CutScene, TargetCanMove), id=unknown
          break;
        }
        if( param1 == 1026251 || param2 == 1026251 ) // ACTOR11 = MAELSTROMOFFICER
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=MAELSTROMOFFICER
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
    player.sendDebug( "StmBde107:68685 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBde107:68685 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00002: Normal(CutScene, AutoFadeIn), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00003: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00005: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00008: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00009: Normal(Talk, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00010: Normal(Talk, TargetCanMove), id=EPHEMIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00012: Normal(CutScene, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00013: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00014: Normal(Talk, TargetCanMove), id=MAELSTROMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00015: Normal(Talk, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00016: Normal(Talk, TargetCanMove), id=EPHEMIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00018: Normal(Talk, TargetCanMove), id=MAELSTROMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00020( player );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00020: Normal(CutScene, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBde107:68685 calling Scene00021: Normal(Talk, TargetCanMove), id=MAELSTROMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBde107 );
