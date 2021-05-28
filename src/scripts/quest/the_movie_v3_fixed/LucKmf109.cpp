// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmf109 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmf109() : Sapphire::ScriptAPI::EventScript( 69188 ){}; 
  ~LucKmf109() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 1 entries
  //SEQ_2, 7 entries
  //SEQ_3, 4 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1030341
  //ACTOR1 = 1030340
  //ACTOR10 = 1030549
  //ACTOR11 = 1030550
  //ACTOR12 = 1030551
  //ACTOR13 = 1030552
  //ACTOR14 = 1030553
  //ACTOR15 = 1030554
  //ACTOR16 = 1030555
  //ACTOR2 = 1030342
  //ACTOR3 = 1030343
  //ACTOR4 = 1030344
  //ACTOR5 = 1030345
  //ACTOR6 = 1030546
  //ACTOR7 = 1030545
  //ACTOR8 = 1030547
  //ACTOR9 = 1030548
  //BINDACTOR01 = 7935542
  //BINDACTOR02 = 7935544
  //BINDACTOR03 = 7935545
  //BINDACTOR04 = 7935546
  //BINDACTOR05 = 7935547
  //EOBJECT0 = 2010144
  //EOBJECT1 = 2010764
  //EVENTACTION0 = 54
  //LOCACTOR01 = 1026568
  //LOCACTOR02 = 1026567
  //LOCACTOR03 = 1026569
  //LOCACTOR04 = 1027137
  //LOCACTOR05 = 1026571
  //LOCACTOR06 = 1026570
  //LOCACTOR07 = 1029449
  //LOCSE01 = 239
  //LOCSE02 = 240
  //LOCSE03 = 241
  //LOCSE04 = 242
  //LOCSE05 = 243
  //LOCVOICE01 = 203
  //LOCVOICE02 = 204
  //LOCVOICE03 = 205
  //LOCVOICE04 = 206
  //LOCVOICE05 = 207
  //POPRANGE0 = 7952512
  //POPRANGE1 = 8049390
  //TERRITORYTYPE0 = 818

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030341 || param2 == 1030341 ) // ACTOR0 = ALISAIE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030340 || param2 == 1030340 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030342 || param2 == 1030342 ) // ACTOR2 = THANCRED
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030343 || param2 == 1030343 ) // ACTOR3 = RYNE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030344 || param2 == 1030344 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030345 || param2 == 1030345 ) // ACTOR5 = URIANGER
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 1:
      {
        Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, AutoFadeIn), id=unknown
        break;
      }
      case 2:
      {
        if( param1 == 1030546 || param2 == 1030546 ) // ACTOR6 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn), id=ALISAIE
          }
          break;
        }
        if( param1 == 1030545 || param2 == 1030545 ) // ACTOR7 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030547 || param2 == 1030547 ) // ACTOR8 = THANCRED
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030548 || param2 == 1030548 ) // ACTOR9 = RYNE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030549 || param2 == 1030549 ) // ACTOR10 = YSHTOLA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030550 || param2 == 1030550 ) // ACTOR11 = URIANGER
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 2010764 || param2 == 2010764 ) // EOBJECT1 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(YesNo), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1030551 || param2 == 1030551 ) // ACTOR12 = AMAUROTRESIDENTA03652
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=AMAUROTRESIDENTA03652
          }
          break;
        }
        if( param1 == 1030552 || param2 == 1030552 ) // ACTOR13 = AMAUROTRESIDENTB03652
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=AMAUROTRESIDENTB03652
          }
          break;
        }
        if( param1 == 1030553 || param2 == 1030553 ) // ACTOR14 = AMAUROTRESIDENTC03652
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, NpcDespawn, TargetCanMove), id=AMAUROTRESIDENTC03652
          }
          break;
        }
        if( param1 == 2010764 || param2 == 2010764 ) // EOBJECT1 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(YesNo), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030554 || param2 == 1030554 ) // ACTOR15 = ALPHINAUD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030555 || param2 == 1030555 ) // ACTOR16 = ALISAIE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 2010764 || param2 == 2010764 ) // EOBJECT1 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(YesNo), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmf109:69188 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00003: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00004: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00006: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00008: Normal(Talk, FadeIn, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 818, -596, -288, 137.3, 0.29, false );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00009: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
        player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
        player.eventFinish( getId(), 1 );
        player.forceZoneing();
      }
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00011: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00012: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00013: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00014: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00015: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 818, -596, -288, 137.3, 0.29, false );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=AMAUROTRESIDENTA03652" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=AMAUROTRESIDENTB03652" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00018: Normal(Talk, NpcDespawn, TargetCanMove), id=AMAUROTRESIDENTC03652" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00019: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 818, -596, -288, 137.3, 0.29, false );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmf109:69188 calling Scene00022: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 818, -596, -288, 137.3, 0.29, false );
      }
    };
    player.playScene( getId(), 22, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmf109 );
