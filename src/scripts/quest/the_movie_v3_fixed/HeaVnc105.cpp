// FFXIVTheMovie.ParserV3
//fix: bnpc credit moved wrong
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc105 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnc105() : Sapphire::ScriptAPI::EventScript( 67771 ){}; 
  ~HeaVnc105() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 12 entries
  //SEQ_2, 7 entries
  //SEQ_3, 12 entries
  //SEQ_255, 10 entries

  //ACTOR0 = 1016566
  //ACTOR1 = 1016567
  //ACTOR10 = 1016576
  //ACTOR11 = 1016577
  //ACTOR12 = 1016077
  //ACTOR2 = 1016568
  //ACTOR3 = 1016569
  //ACTOR4 = 1016570
  //ACTOR5 = 1016571
  //ACTOR6 = 1016572
  //ACTOR7 = 1016573
  //ACTOR8 = 1016574
  //ACTOR9 = 1016575
  //ENEMY0 = 6185517
  //ENEMY1 = 6185518
  //ENEMY2 = 6185519
  //ENEMY3 = 6200474
  //ENEMY4 = 6200475
  //EOBJECT0 = 2006869
  //EOBJECT1 = 2006870
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONWATCHGUARDMIDDLE = 56
  //LOCACTOR0 = 6184576
  //LOCACTOR10 = 6184664
  //LOCACTOR11 = 6184665

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
        }
        if( param1 == 1016567 || param2 == 1016567 ) // ACTOR1 = HONOROIT
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( param1 == 1016568 || param2 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=CITIZENA02233
        }
        if( param1 == 1016569 || param2 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=CITIZENB02233
        }
        if( param1 == 1016570 || param2 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=CITIZENC02233
        }
        if( param1 == 1016571 || param2 == 1016571 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( param1 == 1016572 || param2 == 1016572 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        break;
      }
      case 1:
      {
        if( param1 == 2006869 || param2 == 2006869 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
            // +Callback Scene00009: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 6185517 || param2 == 6185517 ) // ENEMY0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          // +Callback Scene00011: Normal(Message, PopBNpc), id=unknown
        }
        if( param1 == 6185518 || param2 == 6185518 ) // ENEMY1 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          // +Callback Scene00013: Normal(Message, PopBNpc), id=unknown
        }
        if( param1 == 6185519 || param2 == 6185519 ) // ENEMY2 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          // +Callback Scene00015: Normal(Message, PopBNpc), id=unknown
        }
        if( param1 == 1016568 || param2 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          //if( player.getQuestUI8AL( getId() ) != 2 )
          //{
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=CITIZENA02233
          //}
        }
        if( param1 == 1016569 || param2 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          //if( player.getQuestUI8AL( getId() ) != 2 )
          //{
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=CITIZENB02233
          //}
        }
        if( param1 == 1016570 || param2 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=CITIZENC02233
        }
        if( param1 == 1016571 || param2 == 1016571 ) // ACTOR5 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( param1 == 1016572 || param2 == 1016572 ) // ACTOR6 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        if( param1 == 2006870 || param2 == 2006870 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00021( player ); // Scene00021: Normal(None), id=unknown
            // +Callback Scene00022: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 6200474 || param2 == 6200474 ) // ENEMY3 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          // +Callback Scene00024: Normal(Message, PopBNpc), id=unknown
        }
        if( param1 == 6200475 || param2 == 6200475 ) // ENEMY4 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          // +Callback Scene00026: Normal(Message, PopBNpc), id=unknown
        }
        break;
      }
      case 2:
      {
        if( param1 == 1016566 || param2 == 1016566 ) // ACTOR0 = EMMANELLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          }
        }
        if( param1 == 1016567 || param2 == 1016567 ) // ACTOR1 = HONOROIT
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( param1 == 1016568 || param2 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=CITIZENA02233
        }
        if( param1 == 1016569 || param2 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=CITIZENB02233
        }
        if( param1 == 1016570 || param2 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=CITIZENC02233
        }
        if( param1 == 1016571 || param2 == 1016571 ) // ACTOR5 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
        }
        if( param1 == 1016572 || param2 == 1016572 ) // ACTOR6 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( param1 == 1016573 || param2 == 1016573 ) // ACTOR7 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=THANCRED
          }
        }
        if( param1 == 1016574 || param2 == 1016574 ) // ACTOR8 = HERETIC02235
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=HERETIC02235
        }
        if( param1 == 1016566 || param2 == 1016566 ) // ACTOR0 = EMMANELLAIN
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( param1 == 1016567 || param2 == 1016567 ) // ACTOR1 = HONOROIT
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( param1 == 1016568 || param2 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=CITIZENA02233
        }
        if( param1 == 1016569 || param2 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=CITIZENB02233
        }
        if( param1 == 1016570 || param2 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=CITIZENC02233
        }
        if( param1 == 1016575 || param2 == 1016575 ) // ACTOR9 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
        }
        if( param1 == 1016576 || param2 == 1016576 ) // ACTOR10 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
        }
        if( param1 == 1016577 || param2 == 1016577 ) // ACTOR11 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
        }
        if( param1 == 1016571 || param2 == 1016571 ) // ACTOR5 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
        }
        if( param1 == 1016572 || param2 == 1016572 ) // ACTOR6 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016566 || param2 == 1016566 ) // ACTOR0 = EMMANELLAIN
        {
          Scene00046( player ); // Scene00046: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=EMMANELLAIN
        }
        if( param1 == 1016567 || param2 == 1016567 ) // ACTOR1 = HONOROIT
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( param1 == 1016568 || param2 == 1016568 ) // ACTOR2 = CITIZENA02233
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=CITIZENA02233
        }
        if( param1 == 1016569 || param2 == 1016569 ) // ACTOR3 = CITIZENB02233
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=CITIZENB02233
        }
        if( param1 == 1016570 || param2 == 1016570 ) // ACTOR4 = CITIZENC02233
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=CITIZENC02233
        }
        if( param1 == 1016077 || param2 == 1016077 ) // ACTOR12 = THANCRED
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016571 || param2 == 1016571 ) // ACTOR5 = unknown
        {
          Scene00052( player ); // Scene00052: Normal(None), id=unknown
        }
        if( param1 == 1016572 || param2 == 1016572 ) // ACTOR6 = unknown
        {
          Scene00053( player ); // Scene00053: Normal(None), id=unknown
        }
        if( param1 == 1016576 || param2 == 1016576 ) // ACTOR10 = unknown
        {
          Scene00054( player ); // Scene00054: Normal(None), id=unknown
        }
        if( param1 == 1016577 || param2 == 1016577 ) // ACTOR11 = unknown
        {
          Scene00055( player ); // Scene00055: Normal(None), id=unknown
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
    if( player.getQuestUI8BH( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 2 )
        if( player.getQuestUI8AL( getId() ) == 2 )
        {
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
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
    player.sendDebug( "HeaVnc105:67771 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnc105:67771 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00002: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00003: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00004: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00005: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling [BranchTrue]Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 3 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling [BranchTrue]Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling [BranchTrue]Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00014: Normal(None), id=unknown" );
    Scene00015( player );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling [BranchTrue]Scene00015: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00016: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00017: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00018: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00021: Normal(None), id=unknown" );
    Scene00022( player );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling [BranchTrue]Scene00022: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00023: Normal(None), id=unknown" );
    Scene00024( player );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling [BranchTrue]Scene00024: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00025: Normal(None), id=unknown" );
    Scene00026( player );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling [BranchTrue]Scene00026: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00027: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00028: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00029: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00030: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00031: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00034: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00035: Normal(Talk, TargetCanMove), id=HERETIC02235" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00036: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00037: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00038: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00039: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00040: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00044: Normal(None), id=unknown" );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00045: Normal(None), id=unknown" );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00046: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00047: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00048: Normal(Talk, TargetCanMove), id=CITIZENA02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00049: Normal(Talk, TargetCanMove), id=CITIZENB02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00050: Normal(Talk, TargetCanMove), id=CITIZENC02233" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00051: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00052: Normal(None), id=unknown" );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00053: Normal(None), id=unknown" );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00054: Normal(None), id=unknown" );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc105:67771 calling Scene00055: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( HeaVnc105 );
