// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse309 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse309() : Sapphire::ScriptAPI::EventScript( 66986 ){}; 
  ~GaiUse309() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 4 entries
  //SEQ_2, 3 entries
  //SEQ_3, 3 entries
  //SEQ_4, 5 entries
  //SEQ_5, 1 entries
  //SEQ_6, 3 entries
  //SEQ_7, 4 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1009100
  //ACTOR1 = 1009101
  //ACTOR2 = 1009102
  //ACTOR3 = 1009099
  //ACTOR4 = 1009114
  //ACTOR5 = 1009113
  //ACTOR6 = 1009105
  //ACTOR7 = 1009414
  //ACTOR8 = 1009106
  //ACTOR9 = 1009115
  //ENEMY0 = 4868005
  //ENEMY1 = 4868006
  //ENEMY2 = 4868007
  //ENEMY3 = 4868012
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001312
  //LEVELIDNPC01 = 4867985
  //LEVELIDNPC02 = 4867983
  //LEVELIDNPC03 = 4867984
  //LOCVFX01 = 300
  //LOGMSGEVENTGRANDTARGETNOTHING = 1309

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1009100 || param2 == 1009100 ) // ACTOR0 = NAMIDA01449
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=NAMIDA01449
          break;
        }
        if( param1 == 1009101 || param2 == 1009101 ) // ACTOR1 = MODAE01449
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MODAE01449
          break;
        }
        if( param1 == 1009102 || param2 == 1009102 ) // ACTOR2 = SEKI01449
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=SEKI01449
          break;
        }
        if( param1 == 1009099 || param2 == 1009099 ) // ACTOR3 = MAXIO
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MAXIO
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1009114 || param2 == 1009114 ) // ACTOR4 = DUMMYPAPALYMO01450
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, Message, PopBNpc, TargetCanMove), id=DUMMYPAPALYMO01450
          }
          break;
        }
        if( param1 == 4868005 || param2 == 4868005 ) // ENEMY0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1009113 || param2 == 1009113 ) // ACTOR5 = DUMMYYDAO01450
        {
          Scene00007( player ); // Scene00007: Normal(Talk, Message, TargetCanMove), id=DUMMYYDAO01450
          break;
        }
        if( param1 == 1009105 || param2 == 1009105 ) // ACTOR6 = MAXIO
        {
          Scene00008( player ); // Scene00008: Normal(Talk, Message, TargetCanMove), id=MAXIO
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1009114 || param2 == 1009114 ) // ACTOR4 = DUMMYPAPALYMO01450
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=DUMMYPAPALYMO01450
          }
          break;
        }
        if( param1 == 1009113 || param2 == 1009113 ) // ACTOR5 = DUMMYYDAO01450
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=DUMMYYDAO01450
          break;
        }
        if( param1 == 1009105 || param2 == 1009105 ) // ACTOR6 = MAXIO
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=MAXIO
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      case 3:
      {
        if( param1 == 1009105 || param2 == 1009105 ) // ACTOR6 = MAXIO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MAXIO
          }
          break;
        }
        if( param1 == 1009113 || param2 == 1009113 ) // ACTOR5 = DUMMYYDAO01450
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=DUMMYYDAO01450
          break;
        }
        if( param1 == 1009114 || param2 == 1009114 ) // ACTOR4 = DUMMYPAPALYMO01450
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=DUMMYPAPALYMO01450
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BL max stack ?
      case 4:
      {
        if( param1 == 1009113 || param2 == 1009113 ) // ACTOR5 = DUMMYYDAO01450
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, Inventory, TargetCanMove), id=DUMMYYDAO01450
          }
          break;
        }
        if( param1 == 4868006 || param2 == 4868006 ) // ENEMY1 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00018: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1009114 || param2 == 1009114 ) // ACTOR4 = DUMMYPAPALYMO01450
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, Inventory, TargetCanMove), id=DUMMYPAPALYMO01450
          }
          break;
        }
        if( param1 == 4868007 || param2 == 4868007 ) // ENEMY2 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1009105 || param2 == 1009105 ) // ACTOR6 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(Message, PopBNpc), id=unknown
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack ?
      case 5:
      {
        if( type != 2 ) Scene00023( player ); // Scene00023: Normal(Talk, Message, TargetCanMove), id=MAXIO
        // +Callback Scene00024: Normal(Talk, NpcDespawn, TargetCanMove), id=MAXIO
        break;
      }
      //seq 6 event item ITEM0 = UI8BH max stack ?
      case 6:
      {
        if( param1 == 1009414 || param2 == 1009414 ) // ACTOR7 = YDA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=YDA
          }
          break;
        }
        if( param1 == 1009106 || param2 == 1009106 ) // ACTOR8 = MAXIO
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=MAXIO
          break;
        }
        if( param1 == 1009115 || param2 == 1009115 ) // ACTOR9 = DUMMYTHANCRED01450
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=DUMMYTHANCRED01450
          break;
        }
        break;
      }
      //seq 7 event item ITEM0 = UI8BL max stack ?
      case 7:
      {
        if( param1 == 1009115 || param2 == 1009115 ) // ACTOR9 = DUMMYTHANCRED01450
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00028( player ); // Scene00028: Normal(Talk, Inventory, TargetCanMove), id=DUMMYTHANCRED01450
          }
          break;
        }
        if( param1 == 4868012 || param2 == 4868012 ) // ENEMY3 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00031: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1009414 || param2 == 1009414 ) // ACTOR7 = YDA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00032( player ); // Scene00032: Normal(Talk, Inventory, TargetCanMove), id=YDA
            // +Callback Scene00033: Normal(Talk, TargetCanMove), id=YDA
            // +Callback Scene00034: Normal(Talk, Message, TargetCanMove), id=YDA
          }
          break;
        }
        if( param1 == 1009106 || param2 == 1009106 ) // ACTOR8 = MAXIO
        {
          Scene00035( player ); // Scene00035: Normal(Talk, Message, TargetCanMove), id=MAXIO
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1009414 || param2 == 1009414 ) // ACTOR7 = YDA
        {
          Scene00036( player ); // Scene00036: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1009106 || param2 == 1009106 ) // ACTOR8 = MAXIO
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=MAXIO
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
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestBitFlag8( getId(), 1, false );
        player.setQuestBitFlag8( getId(), 2, false );
        player.setQuestUI8BL( getId(), 0 );
        player.updateQuest( getId(), 5 );
      }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 6 );
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestBitFlag8( getId(), 1, false );
        player.setQuestBitFlag8( getId(), 2, false );
        player.setQuestUI8BL( getId(), 0 );
        player.updateQuest( getId(), 255 );
      }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=NAMIDA01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00002: Normal(Talk, TargetCanMove), id=MODAE01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00003: Normal(Talk, TargetCanMove), id=SEKI01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00004: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00005: Normal(Talk, Message, PopBNpc, TargetCanMove), id=DUMMYPAPALYMO01450" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00007: Normal(Talk, Message, TargetCanMove), id=DUMMYYDAO01450" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00008: Normal(Talk, Message, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00009: Normal(Talk, TargetCanMove), id=DUMMYPAPALYMO01450" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00010: Normal(Talk, TargetCanMove), id=DUMMYYDAO01450" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00011: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_3: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00012: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00013: Normal(Talk, TargetCanMove), id=DUMMYYDAO01450" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00014: Normal(Talk, TargetCanMove), id=DUMMYPAPALYMO01450" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_4: ACTOR5, UI8BH = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00015: Normal(Talk, Inventory, TargetCanMove), id=DUMMYYDAO01450" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_4: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00016: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00018( Entity::Player& player ) //SEQ_4: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00018: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_4: ACTOR4, UI8AL = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00019: Normal(Talk, Inventory, TargetCanMove), id=DUMMYPAPALYMO01450" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_4: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00020: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00022: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_5: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00023: Normal(Talk, Message, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00024( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }
  void Scene00024( Entity::Player& player ) //SEQ_5: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00024: Normal(Talk, NpcDespawn, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_6: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00025: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_6: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00026: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_6: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00027: Normal(Talk, TargetCanMove), id=DUMMYTHANCRED01450" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_7: ACTOR9, UI8BH = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00028: Normal(Talk, Inventory, TargetCanMove), id=DUMMYTHANCRED01450" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player ) //SEQ_7: ENEMY3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00029: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00031( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }
  void Scene00031( Entity::Player& player ) //SEQ_7: ENEMY3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00031: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player ) //SEQ_7: ACTOR7, UI8AL = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00032: Normal(Talk, Inventory, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00033( player );
    };
    player.playScene( getId(), 32, NONE, callback );
  }
  void Scene00033( Entity::Player& player ) //SEQ_7: ACTOR7, UI8AL = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00033: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00034( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }
  void Scene00034( Entity::Player& player ) //SEQ_7: ACTOR7, UI8AL = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00034: Normal(Talk, Message, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player ) //SEQ_7: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00035: Normal(Talk, Message, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00036: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YDA" );
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
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse309:66986 calling Scene00037: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse309 );
