// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda206 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda206() : Sapphire::ScriptAPI::EventScript( 68011 ){}; 
  ~StmBda206() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 1 entries
  //SEQ_2, 7 entries
  //SEQ_3, 6 entries
  //SEQ_4, 6 entries
  //SEQ_5, 6 entries
  //SEQ_255, 5 entries

  //ACTIONTIMELINEBATTLECORPSE = 73
  //ACTIONTIMELINEEVENTJOY = 953
  //ACTOR0 = 1020476
  //ACTOR1 = 1020477
  //ACTOR10 = 1020490
  //ACTOR11 = 1020466
  //ACTOR12 = 1020481
  //ACTOR13 = 1020482
  //ACTOR14 = 1020483
  //ACTOR2 = 1020478
  //ACTOR3 = 1020479
  //ACTOR4 = 1020480
  //ACTOR5 = 1020464
  //ACTOR6 = 1020465
  //ACTOR7 = 1020467
  //ACTOR8 = 1020468
  //ACTOR9 = 1020489
  //BINDACTOR0 = 6843856
  //BINDACTOR1 = 6843857
  //BINDACTOR10 = 6843880
  //BINDACTOR11 = 6843881
  //BINDACTOR2 = 6843858
  //BINDACTOR3 = 6843859
  //BINDACTOR4 = 6843428
  //BINDACTOR5 = 6843431
  //BINDACTOR6 = 6843430
  //BINDACTOR7 = 6843429
  //BINDACTOR8 = 6875102
  //BINDACTOR9 = 6875103
  //CUTSCENEN01 = 1407
  //EOBJECT0 = 2007910
  //EOBJECT1 = 2008333
  //EVENTACTION0 = 11
  //EVENTACTION1 = 12
  //LOCACTOR0 = 1018509
  //LOCACTOR1 = 1011887
  //LOCACTOR2 = 1019541
  //LOCACTOR3 = 1019084
  //LOCACTOR4 = 1019085
  //LOCACTOR5 = 1019548
  //LOCACTOR6 = 1008182
  //LOCPOSLYSE001 = 6943626
  //LOCPOSNAMAZU001 = 6943623
  //POPRANGE0 = 6843863
  //POPRANGE1 = 6843917
  //TERRITORYTYPE0 = 639

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020476 || param2 == 1020476 ) // ACTOR0 = LYSE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYSE
        }
        if( param1 == 1020477 || param2 == 1020477 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020478 || param2 == 1020478 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020479 || param2 == 1020479 ) // ACTOR3 = SOROBAN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=SOROBAN
        }
        if( param1 == 1020480 || param2 == 1020480 ) // ACTOR4 = HANCOCK
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=HANCOCK
        }
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00006( player ); // Scene00006: Normal(Talk, FadeIn), id=unknown
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020464 || param2 == 1020464 ) // ACTOR5 = HANCOCK
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=HANCOCK
          }
        }
        if( param1 == 1020465 || param2 == 1020465 ) // ACTOR6 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020467 || param2 == 1020467 ) // ACTOR7 = LYSE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020468 || param2 == 1020468 ) // ACTOR8 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020489 || param2 == 1020489 ) // ACTOR9 = SOROBAN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=SOROBAN
        }
        if( param1 == 1020490 || param2 == 1020490 ) // ACTOR10 = GYODO
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=GYODO
        }
        if( param1 == 1020466 || param2 == 1020466 ) // ACTOR11 = TATARU
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020481 || param2 == 1020481 ) // ACTOR12 = HANCOCK
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=HANCOCK
          }
        }
        if( param1 == 1020482 || param2 == 1020482 ) // ACTOR13 = ALISAIE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020483 || param2 == 1020483 ) // ACTOR14 = LYSE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020465 || param2 == 1020465 ) // ACTOR6 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020490 || param2 == 1020490 ) // ACTOR10 = GYODO
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=GYODO
        }
        if( param1 == 1020466 || param2 == 1020466 ) // ACTOR11 = TATARU
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 4:
      {
        if( param1 == 2007910 || param2 == 2007910 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player );
          }
        }
        if( param1 == 1020482 || param2 == 1020482 ) // ACTOR13 = ALISAIE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020483 || param2 == 1020483 ) // ACTOR14 = LYSE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020465 || param2 == 1020465 ) // ACTOR6 = ALPHINAUD
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020490 || param2 == 1020490 ) // ACTOR10 = GYODO
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=GYODO
        }
        if( param1 == 1020466 || param2 == 1020466 ) // ACTOR11 = TATARU
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 5:
      {
        if( param1 == 2008333 || param2 == 2008333 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00028( player );
          }
        }
        if( param1 == 1020482 || param2 == 1020482 ) // ACTOR13 = ALISAIE
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020483 || param2 == 1020483 ) // ACTOR14 = LYSE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020465 || param2 == 1020465 ) // ACTOR6 = ALPHINAUD
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020490 || param2 == 1020490 ) // ACTOR10 = GYODO
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=GYODO
        }
        if( param1 == 1020466 || param2 == 1020466 ) // ACTOR11 = TATARU
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020483 || param2 == 1020483 ) // ACTOR14 = LYSE
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=LYSE
          // +Callback Scene00035: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( param1 == 1020465 || param2 == 1020465 ) // ACTOR6 = ALPHINAUD
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020490 || param2 == 1020490 ) // ACTOR10 = GYODO
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=GYODO
        }
        if( param1 == 1020482 || param2 == 1020482 ) // ACTOR13 = ALISAIE
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020466 || param2 == 1020466 ) // ACTOR11 = TATARU
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=TATARU
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
    if( player.getQuestUI8AL( getId() ) == 1 )
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
    player.sendDebug( "StmBda206:68011 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda206:68011 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 639 );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00004: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00005: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00006: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00009: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00011: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00012: Normal(Talk, TargetCanMove), id=GYODO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00013: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00014: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00016: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00018: Normal(Talk, TargetCanMove), id=GYODO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00019: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {

  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00021: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "StmBda206:68011 calling Scene00020: Normal(None), id=unknown" );
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling [BranchTrue]Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00023: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00025: Normal(Talk, TargetCanMove), id=GYODO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00026: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {

  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00028: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "StmBda206:68011 calling Scene00027: Normal(None), id=unknown" );
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling [BranchTrue]Scene00029: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00030: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00032: Normal(Talk, TargetCanMove), id=GYODO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00033: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00034: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00035( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling [BranchTrue]Scene00035: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.eventFinish( getId(), 1 );
          player.forceZoneing();
        }
      }
    };
    player.playScene( getId(), 35, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00037: Normal(Talk, TargetCanMove), id=GYODO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00038: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda206:68011 calling Scene00039: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda206 );
