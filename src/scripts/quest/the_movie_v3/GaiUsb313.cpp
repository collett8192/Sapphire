// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb313 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb313() : Sapphire::ScriptAPI::EventScript( 66390 ){}; 
  ~GaiUsb313() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_4, 8 entries
  //SEQ_255, 9 entries

  //ACTOR0 = 1006266
  //ACTOR1 = 1006272
  //EOBJECT0 = 2002676
  //EOBJECT1 = 2002675
  //EOBJECT2 = 2002072
  //EOBJECT3 = 2002073
  //EOBJECT4 = 2002074
  //EOBJECT5 = 2002067
  //EOBJECT6 = 2002068
  //EOBJECT7 = 2002069
  //EOBJECT8 = 2002070
  //EOBJECT9 = 2002071
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000662
  //ITEM1 = 2000663
  //ITEM2 = 2000664

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=WHEISKAET
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      //seq 1 event item ITEM1 = UI8BL max stack 3
      //seq 1 event item ITEM2 = UI8CH max stack 2
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=DYRSTWEITZ
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      //seq 2 event item ITEM1 = UI8BL max stack 3
      //seq 2 event item ITEM2 = UI8CH max stack 2
      case 2:
      {
        Scene00003( player ); // Scene00003: NpcTrade(None), id=unknown
        // +Callback Scene00004: Normal(None), id=unknown
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      //seq 3 event item ITEM2 = UI8BL max stack 2
      case 3:
      {
        if( actor == 2002675 || actorId == 2002675 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: NpcTrade(None), id=unknown
            // +Callback Scene00006: Normal(None), id=unknown
          }
        }
        if( actor == 2002072 || actorId == 2002072 ) // EOBJECT2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          // +Callback Scene00008: Normal(None), id=unknown
        }
        if( actor == 2002073 || actorId == 2002073 ) // EOBJECT3 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          // +Callback Scene00010: Normal(None), id=unknown
        }
        if( actor == 2002074 || actorId == 2002074 ) // EOBJECT4 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          // +Callback Scene00012: Normal(None), id=unknown
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      case 4:
      {
        if( actor == 2002067 || actorId == 2002067 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00013( player ); // Scene00013: Normal(Inventory), id=unknown
            // +Callback Scene00014: Normal(None), id=unknown
          }
        }
        if( actor == 2002068 || actorId == 2002068 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00015( player ); // Scene00015: Normal(Inventory), id=unknown
            // +Callback Scene00016: Normal(None), id=unknown
          }
        }
        if( actor == 2002069 || actorId == 2002069 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00017( player ); // Scene00017: Normal(Inventory), id=unknown
            // +Callback Scene00018: Normal(None), id=unknown
          }
        }
        if( actor == 2002072 || actorId == 2002072 ) // EOBJECT2 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          // +Callback Scene00020: Normal(None), id=unknown
        }
        if( actor == 2002073 || actorId == 2002073 ) // EOBJECT3 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          // +Callback Scene00022: Normal(None), id=unknown
        }
        if( actor == 2002074 || actorId == 2002074 ) // EOBJECT4 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          // +Callback Scene00024: Normal(None), id=unknown
        }
        if( actor == 2002070 || actorId == 2002070 ) // EOBJECT8 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          // +Callback Scene00026: Normal(None), id=unknown
        }
        if( actor == 2002071 || actorId == 2002071 ) // EOBJECT9 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          // +Callback Scene00028: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1006266 || actorId == 1006266 ) // ACTOR0 = WHEISKAET
        {
          Scene00029( player ); // Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WHEISKAET
        }
        if( actor == 2002067 || actorId == 2002067 ) // EOBJECT5 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          // +Callback Scene00031: Normal(None), id=unknown
        }
        if( actor == 2002068 || actorId == 2002068 ) // EOBJECT6 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          // +Callback Scene00033: Normal(None), id=unknown
        }
        if( actor == 2002069 || actorId == 2002069 ) // EOBJECT7 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          // +Callback Scene00035: Normal(None), id=unknown
        }
        if( actor == 2002070 || actorId == 2002070 ) // EOBJECT8 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          // +Callback Scene00037: Normal(None), id=unknown
        }
        if( actor == 2002071 || actorId == 2002071 ) // EOBJECT9 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          // +Callback Scene00039: Normal(None), id=unknown
        }
        if( actor == 2002072 || actorId == 2002072 ) // EOBJECT2 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
          // +Callback Scene00041: Normal(None), id=unknown
        }
        if( actor == 2002073 || actorId == 2002073 ) // EOBJECT3 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
          // +Callback Scene00043: Normal(None), id=unknown
        }
        if( actor == 2002074 || actorId == 2002074 ) // EOBJECT4 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
          // +Callback Scene00045: Normal(None), id=unknown
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
    player.setQuestUI8BH( getId(), 1 );
    player.setQuestUI8BL( getId(), 3 );
    player.setQuestUI8CH( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.setQuestUI8BL( getId(), 0 );
    player.setQuestUI8CH( getId(), 0 );
    player.updateQuest( getId(), 3 );
    player.setQuestUI8BL( getId(), 2 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=WHEISKAET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00002: Normal(Talk, TargetCanMove), id=DYRSTWEITZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00003: NpcTrade(None), id=unknown" );
    Scene00004( player );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00004: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00005: NpcTrade(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00006: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00010: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00012: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00013: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00014: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq4( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00015: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00016: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq4( player );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00017: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00018: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq4( player );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00019: Normal(None), id=unknown" );
    Scene00020( player );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00020: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00021: Normal(None), id=unknown" );
    Scene00022( player );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00022: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00023: Normal(None), id=unknown" );
    Scene00024( player );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00024: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00025: Normal(None), id=unknown" );
    Scene00026( player );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00026: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00027: Normal(None), id=unknown" );
    Scene00028( player );
  }
  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00028: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WHEISKAET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00030: Normal(None), id=unknown" );
    Scene00031( player );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00032: Normal(None), id=unknown" );
    Scene00033( player );
  }
  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00034: Normal(None), id=unknown" );
    Scene00035( player );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00036: Normal(None), id=unknown" );
    Scene00037( player );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00037: Normal(None), id=unknown" );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00038: Normal(None), id=unknown" );
    Scene00039( player );
  }
  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00040: Normal(None), id=unknown" );
    Scene00041( player );
  }
  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00042: Normal(None), id=unknown" );
    Scene00043( player );
  }
  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling Scene00044: Normal(None), id=unknown" );
    Scene00045( player );
  }
  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb313:66390 calling [BranchTrue]Scene00045: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb313 );
