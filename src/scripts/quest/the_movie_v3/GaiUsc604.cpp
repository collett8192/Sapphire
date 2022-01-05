// FFXIVTheMovie.ParserV3.6
// id hint used:
//_ACTOR1 = E
//_ACTOR1E = 1|3,59
//WARP_SCENE21 = 156|0.64|-158.5|13.4|3.14|false
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc604 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc604() : Sapphire::ScriptAPI::EventScript( 66540 ){}; 
  ~GaiUsc604() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_2, 8 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006531
  //ACTOR1 = 1006709
  //ACTOR2 = 1006553
  //ACTOR3 = 1006706
  //ACTOR4 = 1006707
  //ACTOR5 = 1006708
  //ACTOR6 = 1006554
  //ACTOR7 = 1006705
  //ACTOR8 = 1006555
  //ACTOR9 = 1006530
  //EOBJECT0 = 2002329
  //EQUIPCHECKBODY = 6224
  //EQUIPCHECKHEAD = 6223
  //ITEM0 = 2000771
  //POPRANGE0 = 4321644
  //QUESTBATTLE0 = 63
  //TERRITORYTYPE0 = 308
  //TERRITORYTYPE1 = 156

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GLAUMUNT
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 1006709 || param2 == 1006709 ) // ACTOR1 = NPCF, EB=3(emote=59)
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            if( type == 0 ) Scene00002( player ); // onTalk Scene00002: Normal(Talk, TargetCanMove), id=NPCF
            if( type == 1 ) // onEmote
            {
                if( param3 == 59 ) Scene00003( player ); // Correct Scene00003: Normal(Talk, TargetCanMove), id=NPCF
                else Scene00004( player ); // Incorrect Scene00004: Normal(Talk, TargetCanMove), id=NPCF
            }
          }
          break;
        }
        if( param1 == 1006553 || param2 == 1006553 ) // ACTOR2 = NPCA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=NPCA
          break;
        }
        if( param1 == 1006706 || param2 == 1006706 ) // ACTOR3 = NPCC
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=NPCC
          break;
        }
        if( param1 == 1006707 || param2 == 1006707 ) // ACTOR4 = NPCD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=NPCD
          break;
        }
        if( param1 == 1006708 || param2 == 1006708 ) // ACTOR5 = NPCE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=NPCE
          break;
        }
        if( param1 == 1006554 || param2 == 1006554 ) // ACTOR6 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006705 || param2 == 1006705 ) // ACTOR7 = NPCB
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=NPCB
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( param1 == 2002329 || param2 == 2002329 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Inventory), id=unknown
            // +Callback Scene00012: Normal(QuestBattle, YesNo), id=unknown
          }
          break;
        }
        if( param1 == 1006553 || param2 == 1006553 ) // ACTOR2 = NPCA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=NPCA
          break;
        }
        if( param1 == 1006706 || param2 == 1006706 ) // ACTOR3 = NPCC
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=NPCC
          break;
        }
        if( param1 == 1006707 || param2 == 1006707 ) // ACTOR4 = NPCD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=NPCD
          break;
        }
        if( param1 == 1006708 || param2 == 1006708 ) // ACTOR5 = NPCE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=NPCE
          break;
        }
        if( param1 == 1006709 || param2 == 1006709 ) // ACTOR1 = NPCF
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=NPCF
          break;
        }
        if( param1 == 1006705 || param2 == 1006705 ) // ACTOR7 = NPCB
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=NPCB
          break;
        }
        if( param1 == 1006554 || param2 == 1006554 ) // ACTOR6 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006555 || param2 == 1006555 ) // ACTOR8 = CID
        {
          Scene00020( player ); // Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1006530 || param2 == 1006530 ) // ACTOR9 = SLAFBORN
        {
          Scene00021( player ); // Scene00021: Normal(Talk, YesNo, TargetCanMove), id=SLAFBORN
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
    player.sendDebug( "emote: {}", emoteId );
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
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00000: Normal(QuestOffer), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GLAUMUNT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True, Branch
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00002: Normal(Talk, TargetCanMove), id=NPCF" );
    player.playScene( getId(), 2, NONE, nullptr );
  }
  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True, Branch
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00003: Normal(Talk, TargetCanMove), id=NPCF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True, Branch
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00004: Normal(Talk, TargetCanMove), id=NPCF" );
    player.playScene( getId(), 4, NONE, nullptr );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00005: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00006: Normal(Talk, TargetCanMove), id=NPCC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00007: Normal(Talk, TargetCanMove), id=NPCD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00008: Normal(Talk, TargetCanMove), id=NPCE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00010: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00011: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00012: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        //quest battle
        player.eventFinish( getId(), 1 );
        auto& pTeriMgr = Common::Service< Sapphire::World::Manager::TerritoryMgr >::ref();
        pTeriMgr.createAndJoinQuestBattle( player, 63 );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00013: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00014: Normal(Talk, TargetCanMove), id=NPCC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00015: Normal(Talk, TargetCanMove), id=NPCD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00016: Normal(Talk, TargetCanMove), id=NPCE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00017: Normal(Talk, TargetCanMove), id=NPCF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00018: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID" );
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

  void Scene00021( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc604:66540 calling Scene00021: Normal(Talk, YesNo, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 156, 0.64f, -158.5f, 13.4f, 3.14f, false );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsc604 );
