// FFXIVTheMovie.ParserV3
//fix: change zone
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc110 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnc110() : Sapphire::ScriptAPI::EventScript( 67776 ){}; 
  ~HeaVnc110() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 1 entries
  //SEQ_2, 17 entries
  //SEQ_255, 16 entries

  //ACTOR0 = 1016074
  //ACTOR1 = 1016587
  //ACTOR10 = 1010385
  //ACTOR11 = 1010386
  //ACTOR12 = 1010387
  //ACTOR13 = 1016568
  //ACTOR14 = 1016569
  //ACTOR15 = 1016570
  //ACTOR16 = 1011231
  //ACTOR17 = 1011232
  //ACTOR18 = 1011233
  //ACTOR19 = 1011236
  //ACTOR2 = 1016588
  //ACTOR20 = 1011238
  //ACTOR21 = 1011240
  //ACTOR22 = 1013709
  //ACTOR3 = 1016075
  //ACTOR4 = 1016076
  //ACTOR5 = 1016589
  //ACTOR6 = 1016565
  //ACTOR7 = 1016590
  //ACTOR8 = 1010383
  //ACTOR9 = 1010384
  //CUTSCENEN01 = 1152
  //CUTSCENEN02 = 1170
  //CUTSCENEN03 = 1153
  //LOCACTOR0 = 6207043
  //LOCACTOR1 = 6207045
  //LOCACTOR10 = 1015909
  //LOCACTOR11 = 1016778
  //LOCACTOR12 = 1015911
  //LOCBGM0 = 313
  //POPRANGE0 = 6197372

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1016074 || param2 == 1016074 ) // ACTOR0 = AYMERIC
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AYMERIC
          // +Callback Scene00002: Normal(CutScene), id=unknown
        }
        if( param1 == 1016587 || param2 == 1016587 ) // ACTOR1 = EMMANELLAIN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( param1 == 1016588 || param2 == 1016588 ) // ACTOR2 = THANCRED
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016075 || param2 == 1016075 ) // ACTOR3 = LUCIA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016076 || param2 == 1016076 ) // ACTOR4 = HILDA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=HILDA
        }
        break;
      }
      case 1:
      {
        Scene00007( player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 2:
      {
        if( param1 == 1016565 || param2 == 1016565 ) // ACTOR6 = ARTOIREL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=ARTOIREL
          }
        }
        if( param1 == 1016590 || param2 == 1016590 ) // ACTOR7 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1010383 || param2 == 1010383 ) // ACTOR8 = CITIZENA02240
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CITIZENA02240
        }
        if( param1 == 1010384 || param2 == 1010384 ) // ACTOR9 = CITIZENB02240
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=CITIZENB02240
        }
        if( param1 == 1010385 || param2 == 1010385 ) // ACTOR10 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( param1 == 1010386 || param2 == 1010386 ) // ACTOR11 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( param1 == 1010387 || param2 == 1010387 ) // ACTOR12 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( param1 == 1016568 || param2 == 1016568 ) // ACTOR13 = CITIZENA02233
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=CITIZENA02233
        }
        if( param1 == 1016569 || param2 == 1016569 ) // ACTOR14 = CITIZENB02233
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=CITIZENB02233
        }
        if( param1 == 1016570 || param2 == 1016570 ) // ACTOR15 = CITIZENC02233
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=CITIZENC02233
        }
        if( param1 == 1011231 || param2 == 1011231 ) // ACTOR16 = REDWALD
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=REDWALD
        }
        if( param1 == 1011232 || param2 == 1011232 ) // ACTOR17 = TOURCENET
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=TOURCENET
        }
        if( param1 == 1011233 || param2 == 1011233 ) // ACTOR18 = EMERISSEL
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=EMERISSEL
        }
        if( param1 == 1011236 || param2 == 1011236 ) // ACTOR19 = ROTHE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ROTHE
        }
        if( param1 == 1011238 || param2 == 1011238 ) // ACTOR20 = NOIRTEREL
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=NOIRTEREL
        }
        if( param1 == 1011240 || param2 == 1011240 ) // ACTOR21 = INGARET
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=INGARET
        }
        if( param1 == 1013709 || param2 == 1013709 ) // ACTOR22 = AURIAUNE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=AURIAUNE
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016590 || param2 == 1016590 ) // ACTOR7 = ALPHINAUD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
          // +Callback Scene00026: Normal(CutScene), id=unknown
          // +Callback Scene00027: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1010383 || param2 == 1010383 ) // ACTOR8 = CITIZENA02240
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=CITIZENA02240
        }
        if( param1 == 1010384 || param2 == 1010384 ) // ACTOR9 = CITIZENB02240
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=CITIZENB02240
        }
        if( param1 == 1010385 || param2 == 1010385 ) // ACTOR10 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
        }
        if( param1 == 1010386 || param2 == 1010386 ) // ACTOR11 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
        }
        if( param1 == 1010387 || param2 == 1010387 ) // ACTOR12 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
        }
        if( param1 == 1016568 || param2 == 1016568 ) // ACTOR13 = CITIZENA02233
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=CITIZENA02233
        }
        if( param1 == 1016569 || param2 == 1016569 ) // ACTOR14 = CITIZENB02233
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=CITIZENB02233
        }
        if( param1 == 1016570 || param2 == 1016570 ) // ACTOR15 = CITIZENC02233
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=CITIZENC02233
        }
        if( param1 == 1011231 || param2 == 1011231 ) // ACTOR16 = REDWALD
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=REDWALD
        }
        if( param1 == 1011232 || param2 == 1011232 ) // ACTOR17 = TOURCENET
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=TOURCENET
        }
        if( param1 == 1011233 || param2 == 1011233 ) // ACTOR18 = EMERISSEL
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=EMERISSEL
        }
        if( param1 == 1011236 || param2 == 1011236 ) // ACTOR19 = ROTHE
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=ROTHE
        }
        if( param1 == 1011238 || param2 == 1011238 ) // ACTOR20 = NOIRTEREL
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=NOIRTEREL
        }
        if( param1 == 1011240 || param2 == 1011240 ) // ACTOR21 = INGARET
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=INGARET
        }
        if( param1 == 1013709 || param2 == 1013709 ) // ACTOR22 = AURIAUNE
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=AURIAUNE
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnc110:67776 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling [BranchChain]Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 418, 0.758, 1.3, 110.3, 3.1415 );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00004: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00005: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00006: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00010: Normal(Talk, TargetCanMove), id=CITIZENA02240" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00011: Normal(Talk, TargetCanMove), id=CITIZENB02240" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00015: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00016: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00017: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00018: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00019: Normal(Talk, TargetCanMove), id=TOURCENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00020: Normal(Talk, TargetCanMove), id=EMERISSEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00021: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00022: Normal(Talk, TargetCanMove), id=NOIRTEREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00023: Normal(Talk, TargetCanMove), id=INGARET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00024: Normal(Talk, TargetCanMove), id=AURIAUNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00026( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling [BranchTrue]Scene00026: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00027( player );
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling [BranchChain]Scene00027: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00028: Normal(Talk, TargetCanMove), id=CITIZENA02240" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00029: Normal(Talk, TargetCanMove), id=CITIZENB02240" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00033: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00034: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00035: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00036: Normal(Talk, TargetCanMove), id=REDWALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00037: Normal(Talk, TargetCanMove), id=TOURCENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00038: Normal(Talk, TargetCanMove), id=EMERISSEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00039: Normal(Talk, TargetCanMove), id=ROTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00040: Normal(Talk, TargetCanMove), id=NOIRTEREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00041: Normal(Talk, TargetCanMove), id=INGARET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc110:67776 calling Scene00042: Normal(Talk, TargetCanMove), id=AURIAUNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnc110 );
