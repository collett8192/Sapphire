// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst999 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst999() : Sapphire::ScriptAPI::EventScript( 66973 ){}; 
  ~SubFst999() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_2, 5 entries
  //SEQ_3, 14 entries
  //SEQ_4, 2 entries
  //SEQ_5, 12 entries
  //SEQ_6, 2 entries
  //SEQ_7, 7 entries
  //SEQ_8, 2 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1008961
  //ACTOR1 = 1008962
  //ACTOR10 = 1001217
  //ACTOR2 = 1008963
  //ACTOR3 = 1008964
  //ACTOR4 = 1001294
  //ACTOR5 = 1002768
  //ACTOR6 = 1003556
  //ACTOR7 = 1001474
  //ACTOR8 = 1003908
  //ACTOR9 = 1000768
  //EOBJECT0 = 2004132
  //EOBJECT1 = 2004113
  //EOBJECT10 = 2004120
  //EOBJECT11 = 2004121
  //EOBJECT12 = 2004122
  //EOBJECT13 = 2004123
  //EOBJECT14 = 2004124
  //EOBJECT15 = 2004125
  //EOBJECT16 = 2004126
  //EOBJECT17 = 2004127
  //EOBJECT18 = 2004128
  //EOBJECT19 = 2004153
  //EOBJECT2 = 2004109
  //EOBJECT20 = 2004133
  //EOBJECT21 = 2004134
  //EOBJECT22 = 2004136
  //EOBJECT3 = 2004107
  //EOBJECT4 = 2004110
  //EOBJECT5 = 2004111
  //EOBJECT6 = 2004112
  //EOBJECT7 = 2004108
  //EOBJECT8 = 2004114
  //EOBJECT9 = 2004115
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONSEARCHMIDDLE = 3
  //ITEM0 = 2001307
  //ITEMNOBRACE01 = 4109
  //ITEMNOBRACE02 = 4113
  //ITEMNOBRACE03 = 4117
  //ITEMNOEAR01 = 4214
  //ITEMNOEAR02 = 4218
  //ITEMNOEAR03 = 4222
  //ITEMNONEK01 = 4305
  //ITEMNORING01 = 4442
  //ITEMNORING02 = 4446
  //ITEMNORING03 = 4450
  //LOCENPC01 = 1008965
  //LOCPOSACTOR1 = 4721965

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(Talk, YesNo, QuestAccept, TargetCanMove), id=VALLIANTHART
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack ?
      case 1:
      {
        if( actor == 1008962 || actorId == 1008962 ) // ACTOR1 = EXPLORERA01437
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=EXPLORERA01437
        }
        if( actor == 1008963 || actorId == 1008963 ) // ACTOR2 = EXPLORERA01437
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=EXPLORERA01437
        }
        if( actor == 1008964 || actorId == 1008964 ) // ACTOR3 = EXPLORERA01437
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=EXPLORERA01437
        }
        if( actor == 1001294 || actorId == 1001294 ) // ACTOR4 = YAYAROKU
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YAYAROKU
        }
        if( actor == 1008961 || actorId == 1008961 ) // ACTOR0 = VALLIANTHART
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=VALLIANTHART
        }
        if( actor == 2004132 || actorId == 2004132 ) // EOBJECT0 = IBUN01437
        {
          Scene00007( player ); // Scene00007: Normal(Talk), id=IBUN01437
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( actor == 1008961 || actorId == 1008961 ) // ACTOR0 = VALLIANTHART
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=VALLIANTHART
          }
        }
        if( actor == 2004132 || actorId == 2004132 ) // EOBJECT0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1008962 || actorId == 1008962 ) // ACTOR1 = EXPLORERA01437
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=EXPLORERA01437
        }
        if( actor == 1008963 || actorId == 1008963 ) // ACTOR2 = EXPLORERA01437
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=EXPLORERA01437
        }
        if( actor == 1008964 || actorId == 1008964 ) // ACTOR3 = EXPLORERA01437
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=EXPLORERA01437
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8CH max stack ?
      case 3:
      {
        if( actor == 2004113 || actorId == 2004113 ) // EOBJECT1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 2004109 || actorId == 2004109 ) // EOBJECT2 = IBUN01437
        {
          Scene00014( player ); // Scene00014: Normal(Talk), id=IBUN01437
        }
        if( actor == 2004107 || actorId == 2004107 ) // EOBJECT3 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( actor == 2004110 || actorId == 2004110 ) // EOBJECT4 = IBUN01437
        {
          Scene00016( player ); // Scene00016: Normal(Talk), id=IBUN01437
        }
        if( actor == 2004111 || actorId == 2004111 ) // EOBJECT5 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( actor == 2004112 || actorId == 2004112 ) // EOBJECT6 = IBUN01437
        {
          Scene00018( player ); // Scene00018: Normal(Talk), id=IBUN01437
        }
        if( actor == 2004108 || actorId == 2004108 ) // EOBJECT7 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( actor == 2004114 || actorId == 2004114 ) // EOBJECT8 = IBUN01437
        {
          Scene00020( player ); // Scene00020: Normal(Talk), id=IBUN01437
        }
        if( actor == 2004115 || actorId == 2004115 ) // EOBJECT9 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
        }
        if( actor == 1002768 || actorId == 1002768 ) // ACTOR5 = IBUN01437
        {
          Scene00022( player ); // Scene00022: Normal(Talk), id=IBUN01437
        }
        if( actor == 1003556 || actorId == 1003556 ) // ACTOR6 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        if( actor == 1001474 || actorId == 1001474 ) // ACTOR7 = IBUN01437
        {
          Scene00024( player ); // Scene00024: Normal(Talk), id=IBUN01437
        }
        if( actor == 2004132 || actorId == 2004132 ) // EOBJECT0 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
        }
        if( actor == 1008961 || actorId == 1008961 ) // ACTOR0 = IBUN01437
        {
          Scene00026( player ); // Scene00026: Normal(Talk), id=IBUN01437
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      case 4:
      {
        if( actor == 1008961 || actorId == 1008961 ) // ACTOR0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(None), id=unknown
          }
        }
        if( actor == 2004132 || actorId == 2004132 ) // EOBJECT0 = IBUN01437
        {
          Scene00028( player ); // Scene00028: Normal(Talk), id=IBUN01437
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8CH max stack ?
      case 5:
      {
        if( actor == 2004120 || actorId == 2004120 ) // EOBJECT10 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
        }
        if( actor == 2004121 || actorId == 2004121 ) // EOBJECT11 = IBUN01437
        {
          Scene00030( player ); // Scene00030: Normal(Talk), id=IBUN01437
        }
        if( actor == 2004122 || actorId == 2004122 ) // EOBJECT12 = JAHELLE
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=JAHELLE
        }
        if( actor == 2004123 || actorId == 2004123 ) // EOBJECT13 = ISOUDA
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ISOUDA
        }
        if( actor == 2004124 || actorId == 2004124 ) // EOBJECT14 = MEMENUGU
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=MEMENUGU
        }
        if( actor == 2004125 || actorId == 2004125 ) // EOBJECT15 = IBUN01437
        {
          Scene00034( player ); // Scene00034: Normal(Talk), id=IBUN01437
        }
        if( actor == 2004126 || actorId == 2004126 ) // EOBJECT16 = VALLIANTHART
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=VALLIANTHART
        }
        if( actor == 2004127 || actorId == 2004127 ) // EOBJECT17 = VALLIANTHART
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=VALLIANTHART
        }
        if( actor == 2004128 || actorId == 2004128 ) // EOBJECT18 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
        }
        if( actor == 2004153 || actorId == 2004153 ) // EOBJECT19 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
        }
        if( actor == 2004132 || actorId == 2004132 ) // EOBJECT0 = IBUN01437
        {
          Scene00039( player ); // Scene00039: Normal(Talk), id=IBUN01437
        }
        if( actor == 1008961 || actorId == 1008961 ) // ACTOR0 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
        }
        break;
      }
      //seq 6 event item ITEM0 = UI8BH max stack ?
      case 6:
      {
        if( actor == 1008961 || actorId == 1008961 ) // ACTOR0 = IBUN01437
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00041( player ); // Scene00041: Normal(Talk), id=IBUN01437
          }
        }
        if( actor == 2004132 || actorId == 2004132 ) // EOBJECT0 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
        }
        break;
      }
      //seq 7 event item ITEM0 = UI8CH max stack ?
      case 7:
      {
        if( actor == 2004132 || actorId == 2004132 ) // EOBJECT0 = IBUN01437
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00043( player ); // Scene00043: Normal(Talk), id=IBUN01437
          }
        }
        if( actor == 2004133 || actorId == 2004133 ) // EOBJECT20 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00044( player ); // Scene00044: Normal(None), id=unknown
          }
        }
        if( actor == 2004134 || actorId == 2004134 ) // EOBJECT21 = IBUN01437
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00045( player ); // Scene00045: Normal(Talk), id=IBUN01437
          }
        }
        if( actor == 1003908 || actorId == 1003908 ) // ACTOR8 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
        }
        if( actor == 1000768 || actorId == 1000768 ) // ACTOR9 = IBUN01437
        {
          Scene00047( player ); // Scene00047: Normal(Talk), id=IBUN01437
        }
        if( actor == 1001217 || actorId == 1001217 ) // ACTOR10 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
        }
        if( actor == 1008961 || actorId == 1008961 ) // ACTOR0 = IBUN01437
        {
          Scene00049( player ); // Scene00049: Normal(Talk), id=IBUN01437
        }
        break;
      }
      //seq 8 event item ITEM0 = UI8BH max stack ?
      case 8:
      {
        if( actor == 1008961 || actorId == 1008961 ) // ACTOR0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00050( player ); // Scene00050: Normal(None), id=unknown
          }
        }
        if( actor == 2004132 || actorId == 2004132 ) // EOBJECT0 = IBUN01437
        {
          Scene00051( player ); // Scene00051: Normal(Talk), id=IBUN01437
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( actor == 2004136 || actorId == 2004136 ) // EOBJECT22 = unknown
        {
          Scene00052( player ); // Scene00052: Normal(None), id=unknown
        }
        if( actor == 2004132 || actorId == 2004132 ) // EOBJECT0 = IBUN01437
        {
          Scene00053( player ); // Scene00053: Normal(Talk), id=IBUN01437
        }
        if( actor == 1008961 || actorId == 1008961 ) // ACTOR0 = unknown
        {
          Scene00054( player ); // Scene00054: Normal(None), id=unknown
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
    player.setQuestUI8CH( getId(), 0 );
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.setQuestUI8CH( getId(), 0 );
    player.updateQuest( getId(), 4 );
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
    player.setQuestUI8CH( getId(), 0 );
    player.updateQuest( getId(), 6 );
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.updateQuest( getId(), 8 );
        }
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "SubFst999:66973 calling [BranchTrue]Scene00001: Normal(Talk, YesNo, QuestAccept, TargetCanMove), id=VALLIANTHART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00002: Normal(Talk, TargetCanMove), id=EXPLORERA01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00003: Normal(Talk, TargetCanMove), id=EXPLORERA01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00004: Normal(Talk, TargetCanMove), id=EXPLORERA01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00005: Normal(Talk, TargetCanMove), id=YAYAROKU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00006: Normal(Talk, TargetCanMove), id=VALLIANTHART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00007: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00008: Normal(Talk, TargetCanMove), id=VALLIANTHART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00010: Normal(Talk, TargetCanMove), id=EXPLORERA01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00011: Normal(Talk, TargetCanMove), id=EXPLORERA01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00012: Normal(Talk, TargetCanMove), id=EXPLORERA01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00014: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00016: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00018: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00020: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00022: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00024: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00025: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00026: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00027: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00028: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00029: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00030: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00031: Normal(Talk, TargetCanMove), id=JAHELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00032: Normal(Talk, TargetCanMove), id=ISOUDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00033: Normal(Talk, TargetCanMove), id=MEMENUGU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00034: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00035: Normal(Talk, TargetCanMove), id=VALLIANTHART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00036: Normal(Talk, TargetCanMove), id=VALLIANTHART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00037: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00038: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00039: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00041: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00042: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00043: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00044: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq7( player );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00045: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00046: Normal(None), id=unknown" );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00047: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00048: Normal(None), id=unknown" );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00049: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00050: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq8( player );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00051: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00052: Normal(None), id=unknown" );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00053: Normal(Talk), id=IBUN01437" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "SubFst999:66973 calling Scene00054: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubFst999 );
