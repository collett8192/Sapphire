// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda611 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda611() : Sapphire::ScriptAPI::EventScript( 68073 ){}; 
  ~StmBda611() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 8 entries
  //SEQ_3, 7 entries
  //SEQ_4, 7 entries
  //SEQ_5, 7 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1020608
  //ACTOR1 = 1020406
  //ACTOR10 = 1022335
  //ACTOR11 = 1020613
  //ACTOR12 = 1020611
  //ACTOR13 = 1020615
  //ACTOR14 = 1020616
  //ACTOR15 = 1022338
  //ACTOR2 = 1020407
  //ACTOR3 = 1020609
  //ACTOR4 = 1020610
  //ACTOR5 = 1020612
  //ACTOR6 = 1020614
  //ACTOR7 = 1020617
  //ACTOR8 = 1020618
  //ACTOR9 = 1020619
  //BINDACTOR01 = 6858342
  //BINDACTOR02 = 6904983
  //CUTSCENEN01 = 1473
  //CUTSCENEN02 = 1474
  //EOBJECT0 = 2008944
  //EVENTACTION0 = 35
  //EVENTACTION1 = 36
  //LOCACTOR01 = 1018509
  //LOCFACIAL01 = 616
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //LOCIDLE03 = 4206
  //POPRANGE0 = 6906453
  //POPRANGE1 = 7021963
  //TERRITORYTYPE0 = 620

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020608 || param2 == 1020608 ) // ACTOR0 = ALISAIE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020406 || param2 == 1020406 ) // ACTOR1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020407 || param2 == 1020407 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020609 || param2 == 1020609 ) // ACTOR3 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1020406 || param2 == 1020406 ) // ACTOR1 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020407 || param2 == 1020407 ) // ACTOR2 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020610 || param2 == 1020610 ) // ACTOR4 = RAUBAHN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1020612 || param2 == 1020612 ) // ACTOR5 = ALISAIE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020614 || param2 == 1020614 ) // ACTOR6 = PIPIN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020617 || param2 == 1020617 ) // ACTOR7 = WOUNDEDSERPENTSOLDIER
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=WOUNDEDSERPENTSOLDIER
          break;
        }
        if( param1 == 1020618 || param2 == 1020618 ) // ACTOR8 = WOUNDEDFLAMESOLDIER
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=WOUNDEDFLAMESOLDIER
          break;
        }
        if( param1 == 1020619 || param2 == 1020619 ) // ACTOR9 = WOUNDEDSTORMSOLDIER
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=WOUNDEDSTORMSOLDIER
          break;
        }
        if( param1 == 1022335 || param2 == 1022335 ) // ACTOR10 = WOUNDEDISHGARDIANSOLDIER
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=WOUNDEDISHGARDIANSOLDIER
          break;
        }
        if( param1 == 2008944 || param2 == 2008944 ) // EOBJECT0 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(YesNo, SystemTalk, CanCancel), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020617 || param2 == 1020617 ) // ACTOR7 = WOUNDEDSERPENTSOLDIER
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=WOUNDEDSERPENTSOLDIER
            // +Callback Scene00017: Normal(Talk, TargetCanMove), id=WOUNDEDSERPENTSOLDIER
          }
          break;
        }
        if( param1 == 1020618 || param2 == 1020618 ) // ACTOR8 = WOUNDEDFLAMESOLDIER
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=WOUNDEDFLAMESOLDIER
            // +Callback Scene00020: Normal(Talk, TargetCanMove), id=WOUNDEDFLAMESOLDIER
          }
          break;
        }
        if( param1 == 1020619 || param2 == 1020619 ) // ACTOR9 = WOUNDEDSTORMSOLDIER
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=WOUNDEDSTORMSOLDIER
            // +Callback Scene00023: Normal(Talk, TargetCanMove), id=WOUNDEDSTORMSOLDIER
          }
          break;
        }
        if( param1 == 1020610 || param2 == 1020610 ) // ACTOR4 = RAUBAHN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020614 || param2 == 1020614 ) // ACTOR6 = PIPIN
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1022335 || param2 == 1022335 ) // ACTOR10 = WOUNDEDISHGARDIANSOLDIER
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=WOUNDEDISHGARDIANSOLDIER
          break;
        }
        if( param1 == 2008944 || param2 == 2008944 ) // EOBJECT0 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(YesNo, CanCancel), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1022335 || param2 == 1022335 ) // ACTOR10 = WOUNDEDISHGARDIANSOLDIER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00029( player ); // Scene00029: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=WOUNDEDISHGARDIANSOLDIER
          }
          break;
        }
        if( param1 == 1020610 || param2 == 1020610 ) // ACTOR4 = RAUBAHN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020614 || param2 == 1020614 ) // ACTOR6 = PIPIN
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 2008944 || param2 == 2008944 ) // EOBJECT0 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(YesNo, CanCancel), id=unknown
          break;
        }
        if( param1 == 1020617 || param2 == 1020617 ) // ACTOR7 = WOUNDEDSERPENTSOLDIER
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=WOUNDEDSERPENTSOLDIER
          break;
        }
        if( param1 == 1020618 || param2 == 1020618 ) // ACTOR8 = WOUNDEDFLAMESOLDIER
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=WOUNDEDFLAMESOLDIER
          break;
        }
        if( param1 == 1020619 || param2 == 1020619 ) // ACTOR9 = WOUNDEDSTORMSOLDIER
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=WOUNDEDSTORMSOLDIER
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1020613 || param2 == 1020613 ) // ACTOR11 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00036( player ); // Scene00036: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1020610 || param2 == 1020610 ) // ACTOR4 = RAUBAHN
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020614 || param2 == 1020614 ) // ACTOR6 = PIPIN
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020611 || param2 == 1020611 ) // ACTOR12 = ALPHINAUD
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020615 || param2 == 1020615 ) // ACTOR13 = MNAAGO
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020616 || param2 == 1020616 ) // ACTOR14 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        if( param1 == 2008944 || param2 == 2008944 ) // EOBJECT0 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(YesNo, CanCancel), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020611 || param2 == 1020611 ) // ACTOR12 = ALPHINAUD
        {
          Scene00043( player ); // Scene00043: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020610 || param2 == 1020610 ) // ACTOR4 = RAUBAHN
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020614 || param2 == 1020614 ) // ACTOR6 = PIPIN
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020613 || param2 == 1020613 ) // ACTOR11 = LYSE
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1022338 || param2 == 1022338 ) // ACTOR15 = MNAAGO
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020616 || param2 == 1020616 ) // ACTOR14 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
          break;
        }
        if( param1 == 2008944 || param2 == 2008944 ) // EOBJECT0 = unknown
        {
          Scene00049( player ); // Scene00049: Normal(YesNo, CanCancel), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 3 )
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
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda611:68073 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00002: Normal(None), id=unknown" );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00007: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00009: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00010: Normal(Talk, TargetCanMove), id=WOUNDEDSERPENTSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00011: Normal(Talk, TargetCanMove), id=WOUNDEDFLAMESOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00012: Normal(Talk, TargetCanMove), id=WOUNDEDSTORMSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00013: Normal(Talk, TargetCanMove), id=WOUNDEDISHGARDIANSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00014: Normal(YesNo, SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00016: Normal(Talk, TargetCanMove), id=WOUNDEDSERPENTSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00017: Normal(Talk, TargetCanMove), id=WOUNDEDSERPENTSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00019: Normal(Talk, TargetCanMove), id=WOUNDEDFLAMESOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00020: Normal(Talk, TargetCanMove), id=WOUNDEDFLAMESOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00022: Normal(Talk, TargetCanMove), id=WOUNDEDSTORMSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00023: Normal(Talk, TargetCanMove), id=WOUNDEDSTORMSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00024: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00025: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00026: Normal(Talk, TargetCanMove), id=WOUNDEDISHGARDIANSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00027: Normal(YesNo, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00029: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=WOUNDEDISHGARDIANSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00030: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00031: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00032: Normal(YesNo, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        checkProgressSeq4( player );
      }
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00033: Normal(Talk, TargetCanMove), id=WOUNDEDSERPENTSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00034: Normal(Talk, TargetCanMove), id=WOUNDEDFLAMESOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00035: Normal(Talk, TargetCanMove), id=WOUNDEDSTORMSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00036: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00037: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00038: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00039: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00040: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00042: Normal(YesNo, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        checkProgressSeq5( player );
      }
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00043: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00044: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00045: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00046: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00047: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00048: Normal(None), id=unknown" );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "StmBda611:68073 calling Scene00049: Normal(YesNo, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
      }
    };
    player.playScene( getId(), 49, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda611 );
