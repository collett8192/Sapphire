// FFXIVTheMovie.ParserV3
//fix: black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc106 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnc106() : Sapphire::ScriptAPI::EventScript( 67772 ){}; 
  ~HeaVnc106() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 12 entries
  //SEQ_2, 13 entries
  //SEQ_255, 13 entries

  //ACTOR0 = 1016566
  //ACTOR1 = 1016567
  //ACTOR10 = 1011231
  //ACTOR11 = 1011232
  //ACTOR12 = 1011233
  //ACTOR13 = 1011236
  //ACTOR14 = 1011238
  //ACTOR15 = 1011240
  //ACTOR16 = 1013709
  //ACTOR17 = 1011235
  //ACTOR18 = 1016580
  //ACTOR2 = 1016568
  //ACTOR3 = 1016569
  //ACTOR4 = 1016570
  //ACTOR5 = 1016077
  //ACTOR6 = 1016571
  //ACTOR7 = 1016572
  //ACTOR8 = 1016579
  //ACTOR9 = 1016578
  //CUTSCENEN01 = 1145
  //CUTSCENEN02 = 1146
  //CUTSCENEN03 = 1147
  //LOCACTOR0 = 6184576
  //LOCACTOR1 = 6200079
  //POPRANGE0 = 6184802

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1016566 || param2 == 1016566 ) // ACTOR0 = EMMANELLAIN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EMMANELLAIN
          // +Callback Scene00002: Normal(CutScene), id=unknown
        }
        if( param1 == 1016567 || param2 == 1016567 ) // ACTOR1 = HONOROIT
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( param1 == 1016568 || param2 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=CITIZENA02233
        }
        if( param1 == 1016569 || param2 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=CITIZENB02233
        }
        if( param1 == 1016570 || param2 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CITIZENC02233
        }
        if( param1 == 1016077 || param2 == 1016077 ) // ACTOR5 = THANCRED
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016571 || param2 == 1016571 ) // ACTOR6 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( param1 == 1016572 || param2 == 1016572 ) // ACTOR7 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        break;
      }
      case 1:
      {
        if( param1 == 1016579 || param2 == 1016579 ) // ACTOR8 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED
          }
        }
        if( param1 == 1016578 || param2 == 1016578 ) // ACTOR9 = EMMANELLAIN
        {
          Scene00011( player ); // Scene00011: Normal(Talk), id=EMMANELLAIN
        }
        if( param1 == 1016568 || param2 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=CITIZENA02233
        }
        if( param1 == 1016569 || param2 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=CITIZENB02233
        }
        if( param1 == 1016570 || param2 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=CITIZENC02233
        }
        if( param1 == 1011231 || param2 == 1011231 ) // ACTOR10 = REDWALD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=REDWALD
        }
        if( param1 == 1011232 || param2 == 1011232 ) // ACTOR11 = TOURCENET
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=TOURCENET
        }
        if( param1 == 1011233 || param2 == 1011233 ) // ACTOR12 = EMERISSEL
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=EMERISSEL
        }
        if( param1 == 1011236 || param2 == 1011236 ) // ACTOR13 = ROTHE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ROTHE
        }
        if( param1 == 1011238 || param2 == 1011238 ) // ACTOR14 = NOIRTEREL
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=NOIRTEREL
        }
        if( param1 == 1011240 || param2 == 1011240 ) // ACTOR15 = INGARET
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=INGARET
        }
        if( param1 == 1013709 || param2 == 1013709 ) // ACTOR16 = AURIAUNE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=AURIAUNE
        }
        break;
      }
      case 2:
      {
        if( param1 == 1016569 || param2 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=CITIZENB02233
            // +Callback Scene00023: Normal(Talk, TargetCanMove), id=CITIZENB02233
          }
        }
        if( param1 == 1016570 || param2 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=CITIZENC02233
            // +Callback Scene00025: Normal(Talk, TargetCanMove), id=CITIZENC02233
          }
        }
        if( param1 == 1011235 || param2 == 1011235 ) // ACTOR17 = JOSSELOUX
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=JOSSELOUX
            // +Callback Scene00027: Normal(Talk, TargetCanMove), id=JOSSELOUX
          }
        }
        if( param1 == 1016580 || param2 == 1016580 ) // ACTOR18 = THANCRED
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016578 || param2 == 1016578 ) // ACTOR9 = EMMANELLAIN
        {
          Scene00029( player ); // Scene00029: Normal(Talk), id=EMMANELLAIN
        }
        if( param1 == 1016568 || param2 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=CITIZENA02233
        }
        if( param1 == 1011231 || param2 == 1011231 ) // ACTOR10 = REDWALD
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=REDWALD
        }
        if( param1 == 1011232 || param2 == 1011232 ) // ACTOR11 = TOURCENET
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=TOURCENET
        }
        if( param1 == 1011233 || param2 == 1011233 ) // ACTOR12 = EMERISSEL
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=EMERISSEL
        }
        if( param1 == 1011236 || param2 == 1011236 ) // ACTOR13 = ROTHE
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=ROTHE
        }
        if( param1 == 1011238 || param2 == 1011238 ) // ACTOR14 = NOIRTEREL
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=NOIRTEREL
        }
        if( param1 == 1011240 || param2 == 1011240 ) // ACTOR15 = INGARET
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=INGARET
        }
        if( param1 == 1013709 || param2 == 1013709 ) // ACTOR16 = AURIAUNE
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=AURIAUNE
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016580 || param2 == 1016580 ) // ACTOR18 = THANCRED
        {
          Scene00038( player ); // Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016569 || param2 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=CITIZENB02233
        }
        if( param1 == 1016570 || param2 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=CITIZENC02233
        }
        if( param1 == 1011235 || param2 == 1011235 ) // ACTOR17 = JOSSELOUX
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=JOSSELOUX
        }
        if( param1 == 1016578 || param2 == 1016578 ) // ACTOR9 = EMMANELLAIN
        {
          Scene00042( player ); // Scene00042: Normal(Talk), id=EMMANELLAIN
        }
        if( param1 == 1016568 || param2 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=CITIZENA02233
        }
        if( param1 == 1011231 || param2 == 1011231 ) // ACTOR10 = REDWALD
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=REDWALD
        }
        if( param1 == 1011232 || param2 == 1011232 ) // ACTOR11 = TOURCENET
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=TOURCENET
        }
        if( param1 == 1011233 || param2 == 1011233 ) // ACTOR12 = EMERISSEL
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=EMERISSEL
        }
        if( param1 == 1011236 || param2 == 1011236 ) // ACTOR13 = ROTHE
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=ROTHE
        }
        if( param1 == 1011238 || param2 == 1011238 ) // ACTOR14 = NOIRTEREL
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=NOIRTEREL
        }
        if( param1 == 1011240 || param2 == 1011240 ) // ACTOR15 = INGARET
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=INGARET
        }
        if( param1 == 1013709 || param2 == 1013709 ) // ACTOR16 = AURIAUNE
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=AURIAUNE
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
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnc106:67772 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling [BranchChain]Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 397, 508.8, 218, 771.2, -2.28 );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00003: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00004: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00005: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00006: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00007: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00011: Normal(Talk), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00012: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00013: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00014: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00015: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00016: Normal(Talk, TargetCanMove), id=TOURCENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00017: Normal(Talk, TargetCanMove), id=EMERISSEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00018: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00019: Normal(Talk, TargetCanMove), id=NOIRTEREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00020: Normal(Talk, TargetCanMove), id=INGARET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00021: Normal(Talk, TargetCanMove), id=AURIAUNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00022: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling [BranchTrue]Scene00023: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00024: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00025( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling [BranchTrue]Scene00025: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00026: Normal(Talk, TargetCanMove), id=JOSSELOUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00027( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling [BranchTrue]Scene00027: Normal(Talk, TargetCanMove), id=JOSSELOUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00028: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00029: Normal(Talk), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00030: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00031: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00032: Normal(Talk, TargetCanMove), id=TOURCENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00033: Normal(Talk, TargetCanMove), id=EMERISSEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00034: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00035: Normal(Talk, TargetCanMove), id=NOIRTEREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00036: Normal(Talk, TargetCanMove), id=INGARET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00037: Normal(Talk, TargetCanMove), id=AURIAUNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00039: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00040: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00041: Normal(Talk, TargetCanMove), id=JOSSELOUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00042: Normal(Talk), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00043: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00044: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00045: Normal(Talk, TargetCanMove), id=TOURCENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00046: Normal(Talk, TargetCanMove), id=EMERISSEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00047: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00048: Normal(Talk, TargetCanMove), id=NOIRTEREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00049: Normal(Talk, TargetCanMove), id=INGARET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc106:67772 calling Scene00050: Normal(Talk, TargetCanMove), id=AURIAUNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnc106 );
