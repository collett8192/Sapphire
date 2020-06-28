// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb802 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb802() : Sapphire::ScriptAPI::EventScript( 66447 ){}; 
  ~GaiUsb802() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 4 entries
  //SEQ_3, 10 entries
  //SEQ_4, 7 entries
  //SEQ_255, 8 entries

  //ACTOR0 = 1006384
  //ACTOR1 = 1006412
  //ACTOR2 = 1006413
  //ACTOR3 = 1006414
  //EOBJECT0 = 2002137
  //EOBJECT1 = 2002138
  //EOBJECT2 = 2002139
  //EOBJECT3 = 2002141
  //EOBJECT4 = 2002140
  //EOBJECT5 = 2002678
  //EOBJECT6 = 2002679
  //EOBJECT7 = 2002680
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000711

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HAURCHEFANT
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=RICKEMAN
        break;
      }
      case 2:
      {
        if( actor == 1006413 || actorId == 1006413 ) // ACTOR2 = NPCB
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=NPCB
          }
        }
        if( actor == 1006414 || actorId == 1006414 ) // ACTOR3 = NPCA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=NPCA
        }
        if( actor == 2002137 || actorId == 2002137 ) // EOBJECT0 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          // +Callback Scene00006: Normal(None), id=unknown
        }
        if( actor == 2002138 || actorId == 2002138 ) // EOBJECT1 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          // +Callback Scene00008: Normal(None), id=unknown
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8CH max stack 2
      case 3:
      {
        if( actor == 2002139 || actorId == 2002139 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
          }
        }
        if( actor == 2002141 || actorId == 2002141 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Message), id=unknown
            // +Callback Scene00011: Normal(None), id=unknown
          }
        }
        if( actor == 2002140 || actorId == 2002140 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
            // +Callback Scene00013: Normal(None), id=unknown
          }
        }
        if( actor == 2002137 || actorId == 2002137 ) // EOBJECT0 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(Message), id=unknown
          // +Callback Scene00015: Normal(None), id=unknown
        }
        if( actor == 2002138 || actorId == 2002138 ) // EOBJECT1 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          // +Callback Scene00017: Normal(None), id=unknown
        }
        if( actor == 1006413 || actorId == 1006413 ) // ACTOR2 = NPCB
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          // +Callback Scene00019: Normal(Talk, TargetCanMove), id=NPCB
        }
        if( actor == 1006414 || actorId == 1006414 ) // ACTOR3 = NPCA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=NPCA
        }
        if( actor == 2002678 || actorId == 2002678 ) // EOBJECT5 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          // +Callback Scene00022: Normal(None), id=unknown
        }
        if( actor == 2002679 || actorId == 2002679 ) // EOBJECT6 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          // +Callback Scene00024: Normal(None), id=unknown
        }
        if( actor == 2002680 || actorId == 2002680 ) // EOBJECT7 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          // +Callback Scene00026: Normal(None), id=unknown
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 2
      case 4:
      {
        if( actor == 1006413 || actorId == 1006413 ) // ACTOR2 = NPCB
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00028: Normal(Talk, TargetCanMove), id=NPCB
          }
        }
        if( actor == 2002137 || actorId == 2002137 ) // EOBJECT0 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          // +Callback Scene00030: Normal(None), id=unknown
        }
        if( actor == 2002138 || actorId == 2002138 ) // EOBJECT1 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          // +Callback Scene00032: Normal(None), id=unknown
        }
        if( actor == 1006414 || actorId == 1006414 ) // ACTOR3 = NPCA
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=NPCA
        }
        if( actor == 2002678 || actorId == 2002678 ) // EOBJECT5 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          // +Callback Scene00035: Normal(None), id=unknown
        }
        if( actor == 2002679 || actorId == 2002679 ) // EOBJECT6 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          // +Callback Scene00037: Normal(None), id=unknown
        }
        if( actor == 2002680 || actorId == 2002680 ) // EOBJECT7 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          // +Callback Scene00039: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 2
      case 255:
      {
        if( actor == 1006384 || actorId == 1006384 ) // ACTOR0 = HAURCHEFANT
        {
          Scene00040( player ); // Scene00040: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00041: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 2002138 || actorId == 2002138 ) // EOBJECT1 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
          // +Callback Scene00043: Normal(None), id=unknown
        }
        if( actor == 2002137 || actorId == 2002137 ) // EOBJECT0 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
          // +Callback Scene00045: Normal(None), id=unknown
        }
        if( actor == 1006413 || actorId == 1006413 ) // ACTOR2 = NPCB
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=NPCB
        }
        if( actor == 1006414 || actorId == 1006414 ) // ACTOR3 = NPCA
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=NPCA
        }
        if( actor == 2002678 || actorId == 2002678 ) // EOBJECT5 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
          // +Callback Scene00049: Normal(None), id=unknown
        }
        if( actor == 2002679 || actorId == 2002679 ) // EOBJECT6 = unknown
        {
          Scene00050( player ); // Scene00050: Normal(None), id=unknown
          // +Callback Scene00051: Normal(None), id=unknown
        }
        if( actor == 2002680 || actorId == 2002680 ) // EOBJECT7 = unknown
        {
          Scene00052( player ); // Scene00052: Normal(None), id=unknown
          // +Callback Scene00053: Normal(None), id=unknown
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
    onProgress( player, param1, param1, 3, param1 );
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
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
        {
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.updateQuest( getId(), 4 );
          player.setQuestUI8BH( getId(), 2 );
        }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00002: Normal(Talk, TargetCanMove), id=RICKEMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00003: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00004: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00006: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00009: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00010: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00011: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00013: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00014: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00015: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00016: Normal(None), id=unknown" );
    Scene00017( player );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00017: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00018: Normal(None), id=unknown" );
    Scene00019( player );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00019: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00020: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00021: Normal(None), id=unknown" );
    Scene00022( player );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00022: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00023: Normal(None), id=unknown" );
    Scene00024( player );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00024: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00025: Normal(None), id=unknown" );
    Scene00026( player );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00026: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00027: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00028( player );
      }
    };
    player.playScene( getId(), 27, NONE, callback );
  }
  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00028: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00029: Normal(None), id=unknown" );
    Scene00030( player );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00030: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00031: Normal(None), id=unknown" );
    Scene00032( player );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00032: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00033: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00034: Normal(None), id=unknown" );
    Scene00035( player );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00035: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00036: Normal(None), id=unknown" );
    Scene00037( player );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00037: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00038: Normal(None), id=unknown" );
    Scene00039( player );
  }
  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00039: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00040: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00041( player );
      }
    };
    player.playScene( getId(), 40, NONE, callback );
  }
  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00041: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00042: Normal(None), id=unknown" );
    Scene00043( player );
  }
  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00044: Normal(None), id=unknown" );
    Scene00045( player );
  }
  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00045: Normal(None), id=unknown" );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00046: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00047: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00048: Normal(None), id=unknown" );
    Scene00049( player );
  }
  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00049: Normal(None), id=unknown" );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00050: Normal(None), id=unknown" );
    Scene00051( player );
  }
  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00051: Normal(None), id=unknown" );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling Scene00052: Normal(None), id=unknown" );
    Scene00053( player );
  }
  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb802:66447 calling [BranchTrue]Scene00053: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb802 );
