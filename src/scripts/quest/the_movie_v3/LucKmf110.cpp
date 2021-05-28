// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_6 = dummye0
//ACTOR2 = OFFICIALA03653
//_ACTOR2 SET!!
//ACTOR3 = AMAUROTADMINISTRATOR
//_ACTOR3 SET!!
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmf110 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmf110() : Sapphire::ScriptAPI::EventScript( 69189 ){}; 
  ~LucKmf110() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 1 entries
  //SEQ_4, 16 entries
  //SEQ_5, 16 entries
  //SEQ_6, 1 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1030554
  //ACTOR1 = 1030555
  //ACTOR10 = 1030353
  //ACTOR11 = 1030354
  //ACTOR12 = 1030355
  //ACTOR13 = 1030356
  //ACTOR14 = 1030357
  //ACTOR15 = 1030358
  //ACTOR16 = 1030359
  //ACTOR17 = 1030360
  //ACTOR18 = 1030558
  //ACTOR19 = 1030556
  //ACTOR2 = 1027772
  //ACTOR20 = 1030557
  //ACTOR21 = 1030559
  //ACTOR22 = 1030560
  //ACTOR23 = 1030561
  //ACTOR3 = 1027773
  //ACTOR4 = 1030347
  //ACTOR5 = 1030348
  //ACTOR6 = 1030349
  //ACTOR7 = 1030350
  //ACTOR8 = 1030351
  //ACTOR9 = 1030352
  //BINDACTOR01 = 7952528
  //BINDACTOR02 = 7952533
  //BINDACTOR03 = 7952534
  //BINDACTOR04 = 7952538
  //BINDACTOR05 = 7952539
  //BINDACTOR06 = 7952540
  //BINDACTOR07 = 7823536
  //CUTSCENE0 = 2063
  //EOBJECT0 = 2010147
  //EOBJECT1 = 2010148
  //EVENTACTION0 = 13
  //EVENTACTION1 = 12
  //ITEM0 = 2002676
  //ITEM1 = 2002677
  //LOCACTOR01 = 1026569
  //LOCACTOR02 = 1027137
  //LOCACTOR03 = 1026571
  //LOCACTOR04 = 1026570
  //POPRANGE0 = 7954628

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030554 || param2 == 1030554 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          // +Callback Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030555 || param2 == 1030555 ) // ACTOR1 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 1:
      {
        Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=OFFICIALA03653
        break;
      }
      case 2:
      {
        if( param1 == 2010147 || param2 == 2010147 ) // EOBJECT0 = dummye0
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk), id=dummye0
          }
          break;
        }
        if( param1 == 1027772 || param2 == 1027772 ) // ACTOR2 = OFFICIALA03653
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=OFFICIALA03653
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=OFFICIALA03653
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 1027773 || param2 == 1027773 ) // ACTOR3 = AMAUROTADMINISTRATOR
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=AMAUROTADMINISTRATOR
          }
          break;
        }
        if( param1 == 1027772 || param2 == 1027772 ) // ACTOR2 = OFFICIALA03653
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=OFFICIALA03653
          break;
        }
        if( param1 == 1030347 || param2 == 1030347 ) // ACTOR4 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030348 || param2 == 1030348 ) // ACTOR5 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030349 || param2 == 1030349 ) // ACTOR6 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030350 || param2 == 1030350 ) // ACTOR7 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030351 || param2 == 1030351 ) // ACTOR8 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030352 || param2 == 1030352 ) // ACTOR9 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030353 || param2 == 1030353 ) // ACTOR10 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030354 || param2 == 1030354 ) // ACTOR11 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030355 || param2 == 1030355 ) // ACTOR12 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030356 || param2 == 1030356 ) // ACTOR13 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030357 || param2 == 1030357 ) // ACTOR14 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030358 || param2 == 1030358 ) // ACTOR15 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030359 || param2 == 1030359 ) // ACTOR16 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030360 || param2 == 1030360 ) // ACTOR17 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 2010148 || param2 == 2010148 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1027773 || param2 == 1027773 ) // ACTOR3 = AMAUROTADMINISTRATOR
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=AMAUROTADMINISTRATOR
          break;
        }
        if( param1 == 1030347 || param2 == 1030347 ) // ACTOR4 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030348 || param2 == 1030348 ) // ACTOR5 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030349 || param2 == 1030349 ) // ACTOR6 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030350 || param2 == 1030350 ) // ACTOR7 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030351 || param2 == 1030351 ) // ACTOR8 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030352 || param2 == 1030352 ) // ACTOR9 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030353 || param2 == 1030353 ) // ACTOR10 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030354 || param2 == 1030354 ) // ACTOR11 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030355 || param2 == 1030355 ) // ACTOR12 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030356 || param2 == 1030356 ) // ACTOR13 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030357 || param2 == 1030357 ) // ACTOR14 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030358 || param2 == 1030358 ) // ACTOR15 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030359 || param2 == 1030359 ) // ACTOR16 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030360 || param2 == 1030360 ) // ACTOR17 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 6 event item ITEM1 = UI8BH max stack 1
      case 6:
      {
        Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=AMAUROTADMINISTRATOR
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1030558 || param2 == 1030558 ) // ACTOR18 = THANCRED
        {
          Scene00044( player ); // Scene00044: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00045: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1027773 || param2 == 1027773 ) // ACTOR3 = AMAUROTADMINISTRATOR
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=AMAUROTADMINISTRATOR
          break;
        }
        if( param1 == 1030556 || param2 == 1030556 ) // ACTOR19 = ALPHINAUD
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030557 || param2 == 1030557 ) // ACTOR20 = ALISAIE
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030559 || param2 == 1030559 ) // ACTOR21 = unknown
        {
          Scene00049( player ); // Scene00049: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 1030560 || param2 == 1030560 ) // ACTOR22 = YSHTOLA
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030561 || param2 == 1030561 ) // ACTOR23 = URIANGER
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=URIANGER
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
    player.updateQuest( getId(), 4 );
    player.setQuestUI8BH( getId(), 1 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 1 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmf110:69189 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00004: Normal(Talk, TargetCanMove), id=OFFICIALA03653" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00006: Normal(Talk), id=dummye0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00007: Normal(Talk, TargetCanMove), id=OFFICIALA03653" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00008: Normal(Talk, TargetCanMove), id=OFFICIALA03653" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00009: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00010( player );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00010: Normal(Talk, TargetCanMove), id=AMAUROTADMINISTRATOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00011: Normal(Talk, TargetCanMove), id=OFFICIALA03653" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00027: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00028: Normal(Talk, TargetCanMove), id=AMAUROTADMINISTRATOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00037: Normal(None), id=unknown" );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00038: Normal(None), id=unknown" );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00043: Normal(Talk, TargetCanMove), id=AMAUROTADMINISTRATOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00044: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00045( player );
      }
    };
    player.playScene( getId(), 44, NONE, callback );
  }
  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00045: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=THANCRED" );
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
    player.playScene( getId(), 45, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00046: Normal(Talk, TargetCanMove), id=AMAUROTADMINISTRATOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00048: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00049: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00050: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "LucKmf110:69189 calling Scene00051: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmf110 );
