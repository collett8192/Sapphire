// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb311 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb311() : Sapphire::ScriptAPI::EventScript( 66388 ){}; 
  ~GaiUsb311() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_2, 12 entries
  //SEQ_3, 12 entries
  //SEQ_255, 13 entries

  //ACTOR0 = 1006273
  //ACTOR1 = 1006320
  //ACTOR10 = 1007554
  //ACTOR11 = 1007555
  //ACTOR12 = 1007556
  //ACTOR13 = 1007557
  //ACTOR14 = 1007558
  //ACTOR2 = 1006321
  //ACTOR3 = 1006322
  //ACTOR4 = 1007549
  //ACTOR5 = 1007550
  //ACTOR6 = 1007551
  //ACTOR7 = 1007552
  //ACTOR8 = 1007553
  //ACTOR9 = 1006323
  //EOBJECT0 = 2002064
  //EOBJECT1 = 2002065
  //EOBJECT2 = 2002066
  //EOBJECT3 = 2002677
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000661

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GEGERUJU
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( actor == 1006320 || actorId == 1006320 ) // ACTOR1 = POACHER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=POACHER
          }
        }
        if( actor == 1006321 || actorId == 1006321 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
        }
        if( actor == 1006322 || actorId == 1006322 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( actor == 1007549 || actorId == 1007549 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        if( actor == 1007550 || actorId == 1007550 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( actor == 1007551 || actorId == 1007551 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( actor == 1007552 || actorId == 1007552 ) // ACTOR7 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( actor == 1007553 || actorId == 1007553 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8CL max stack ?
      case 2:
      {
        if( actor == 2002064 || actorId == 2002064 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Inventory), id=unknown
            // +Callback Scene00011: Normal(None), id=unknown
          }
        }
        if( actor == 2002065 || actorId == 2002065 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Inventory), id=unknown
            // +Callback Scene00013: Normal(None), id=unknown
          }
        }
        if( actor == 2002066 || actorId == 2002066 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Inventory), id=unknown
            // +Callback Scene00015: Normal(None), id=unknown
          }
        }
        if( actor == 1006320 || actorId == 1006320 ) // ACTOR1 = POACHER
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=POACHER
        }
        if( actor == 1006321 || actorId == 1006321 ) // ACTOR2 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( actor == 1006322 || actorId == 1006322 ) // ACTOR3 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        if( actor == 1007549 || actorId == 1007549 ) // ACTOR4 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( actor == 1007550 || actorId == 1007550 ) // ACTOR5 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        if( actor == 1007551 || actorId == 1007551 ) // ACTOR6 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
        }
        if( actor == 1007552 || actorId == 1007552 ) // ACTOR7 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
        }
        if( actor == 1007553 || actorId == 1007553 ) // ACTOR8 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        if( actor == 2002677 || actorId == 2002677 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Inventory), id=unknown
            // +Callback Scene00025: Normal(None), id=unknown
          }
        }
        break;
      }
      case 3:
      {
        if( actor == 1006320 || actorId == 1006320 ) // ACTOR1 = POACHER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=POACHER
          }
        }
        if( actor == 1006322 || actorId == 1006322 ) // ACTOR3 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
        }
        if( actor == 1006323 || actorId == 1006323 ) // ACTOR9 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
        }
        if( actor == 1007554 || actorId == 1007554 ) // ACTOR10 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
        }
        if( actor == 1007555 || actorId == 1007555 ) // ACTOR11 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
        }
        if( actor == 1007556 || actorId == 1007556 ) // ACTOR12 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
        }
        if( actor == 1007557 || actorId == 1007557 ) // ACTOR13 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
        }
        if( actor == 1007558 || actorId == 1007558 ) // ACTOR14 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
        }
        if( actor == 2002064 || actorId == 2002064 ) // EOBJECT0 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          // +Callback Scene00035: Normal(None), id=unknown
        }
        if( actor == 2002065 || actorId == 2002065 ) // EOBJECT1 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          // +Callback Scene00037: Normal(None), id=unknown
        }
        if( actor == 2002066 || actorId == 2002066 ) // EOBJECT2 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          // +Callback Scene00039: Normal(None), id=unknown
        }
        if( actor == 2002677 || actorId == 2002677 ) // EOBJECT3 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
          // +Callback Scene00041: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1006273 || actorId == 1006273 ) // ACTOR0 = GEGERUJU
        {
          Scene00042( player ); // Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GEGERUJU
        }
        if( actor == 1006320 || actorId == 1006320 ) // ACTOR1 = POACHER
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=POACHER
        }
        if( actor == 1006322 || actorId == 1006322 ) // ACTOR3 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
        }
        if( actor == 1006323 || actorId == 1006323 ) // ACTOR9 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
        }
        if( actor == 1007554 || actorId == 1007554 ) // ACTOR10 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
        }
        if( actor == 1007555 || actorId == 1007555 ) // ACTOR11 = unknown
        {
          Scene00047( player ); // Scene00047: Normal(None), id=unknown
        }
        if( actor == 1007556 || actorId == 1007556 ) // ACTOR12 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
        }
        if( actor == 1007557 || actorId == 1007557 ) // ACTOR13 = unknown
        {
          Scene00049( player ); // Scene00049: Normal(None), id=unknown
        }
        if( actor == 1007558 || actorId == 1007558 ) // ACTOR14 = unknown
        {
          Scene00050( player ); // Scene00050: Normal(None), id=unknown
        }
        if( actor == 2002064 || actorId == 2002064 ) // EOBJECT0 = unknown
        {
          Scene00051( player ); // Scene00051: Normal(None), id=unknown
          // +Callback Scene00052: Normal(None), id=unknown
        }
        if( actor == 2002065 || actorId == 2002065 ) // EOBJECT1 = unknown
        {
          Scene00053( player ); // Scene00053: Normal(None), id=unknown
          // +Callback Scene00054: Normal(None), id=unknown
        }
        if( actor == 2002066 || actorId == 2002066 ) // EOBJECT2 = unknown
        {
          Scene00055( player ); // Scene00055: Normal(None), id=unknown
          // +Callback Scene00056: Normal(None), id=unknown
        }
        if( actor == 2002677 || actorId == 2002677 ) // EOBJECT3 = unknown
        {
          Scene00057( player ); // Scene00057: Normal(None), id=unknown
          // +Callback Scene00058: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestUI8CL( getId(), 0 );
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
    player.sendDebug( "GaiUsb311:66388 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb311:66388 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GEGERUJU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00002: Normal(Talk, TargetCanMove), id=POACHER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00010: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling [BranchTrue]Scene00011: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00012: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling [BranchTrue]Scene00013: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00014: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling [BranchTrue]Scene00015: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00016: Normal(Talk, TargetCanMove), id=POACHER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00024: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00025( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling [BranchTrue]Scene00025: Normal(None), id=unknown" );
    player.setQuestUI8CH( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00026: Normal(Talk, TargetCanMove), id=POACHER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00034: Normal(None), id=unknown" );
    Scene00035( player );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling [BranchTrue]Scene00035: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00036: Normal(None), id=unknown" );
    Scene00037( player );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling [BranchTrue]Scene00037: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00038: Normal(None), id=unknown" );
    Scene00039( player );
  }
  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling [BranchTrue]Scene00039: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00040: Normal(None), id=unknown" );
    Scene00041( player );
  }
  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling [BranchTrue]Scene00041: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GEGERUJU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00043: Normal(Talk, TargetCanMove), id=POACHER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00044: Normal(None), id=unknown" );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00045: Normal(None), id=unknown" );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00046: Normal(None), id=unknown" );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00047: Normal(None), id=unknown" );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00048: Normal(None), id=unknown" );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00049: Normal(None), id=unknown" );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00050: Normal(None), id=unknown" );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00051: Normal(None), id=unknown" );
    Scene00052( player );
  }
  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling [BranchTrue]Scene00052: Normal(None), id=unknown" );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00053: Normal(None), id=unknown" );
    Scene00054( player );
  }
  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling [BranchTrue]Scene00054: Normal(None), id=unknown" );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00055: Normal(None), id=unknown" );
    Scene00056( player );
  }
  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling [BranchTrue]Scene00056: Normal(None), id=unknown" );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling Scene00057: Normal(None), id=unknown" );
    Scene00058( player );
  }
  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb311:66388 calling [BranchTrue]Scene00058: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb311 );
