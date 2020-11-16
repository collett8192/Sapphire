// FFXIVTheMovie.ParserV3.2
// id hint used:
//EOBJECT0 = dummye0
//EOBJECT1 = dummye1
//SCENE_8 = dummye0
//SCENE_13 = dummye1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda502 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda502() : Sapphire::ScriptAPI::EventScript( 68056 ){}; 
  ~StmBda502() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_4, 4 entries
  //SEQ_5, 7 entries
  //SEQ_6, 10 entries
  //SEQ_7, 4 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1020519
  //ACTOR1 = 1020520
  //ACTOR10 = 1020273
  //ACTOR11 = 1019934
  //ACTOR12 = 1020521
  //ACTOR13 = 1023091
  //ACTOR2 = 1020523
  //ACTOR3 = 1020226
  //ACTOR4 = 1020227
  //ACTOR5 = 1020228
  //ACTOR6 = 1020229
  //ACTOR7 = 1020230
  //ACTOR8 = 1020271
  //ACTOR9 = 1020272
  //BINDALISAIE001 = 6843996
  //BINDALISAIE002 = 6843998
  //BINDEMPIRE001 = 6869169
  //BINDEMPIRE002 = 6869170
  //ENEMY0 = 6848182
  //ENEMY1 = 6869167
  //EOBJECT0 = 2007923
  //EOBJECT1 = 2007924
  //EOBJECT2 = 2007925
  //EVENTACTION0 = 50
  //EVENTRANGE0 = 6869459
  //NCUTEVENT05010 = 1493

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR1 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2007923 || param2 == 2007923 ) // EOBJECT0 = dummye0
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk), id=dummye0
          }
          break;
        }
        if( param1 == 1020226 || param2 == 1020226 ) // ACTOR3 = ALISAIE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2007924 || param2 == 2007924 ) // EOBJECT1 = dummye1
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk), id=dummye1
          }
          break;
        }
        if( param1 == 1020227 || param2 == 1020227 ) // ACTOR4 = ALISAIE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020228 || param2 == 1020228 ) // ACTOR5 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove, Menu), id=ALISAIE
          }
          break;
        }
        if( param1 == 1020229 || param2 == 1020229 ) // ACTOR6 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1020230 || param2 == 1020230 ) // ACTOR7 = HENSO02520
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk, NpcDespawn, TargetCanMove), id=HENSO02520
          }
          break;
        }
        if( param1 == 1020271 || param2 == 1020271 ) // ACTOR8 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020272 || param2 == 1020272 ) // ACTOR9 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020228 || param2 == 1020228 ) // ACTOR5 = ALISAIE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020229 || param2 == 1020229 ) // ACTOR6 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 6869459 || param2 == 6869459 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00028( player ); // Scene00028: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 6848182 || param2 == 6848182 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 6869167 || param2 == 6869167 ) // ENEMY1 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 1020271 || param2 == 1020271 ) // ACTOR8 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020272 || param2 == 1020272 ) // ACTOR9 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020228 || param2 == 1020228 ) // ACTOR5 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020229 || param2 == 1020229 ) // ACTOR6 = ALISAIE
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 2007925 || param2 == 2007925 ) // EOBJECT2 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 1020273 || param2 == 1020273 ) // ACTOR10 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00038( player ); // Scene00038: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1019934 || param2 == 1019934 ) // ACTOR11 = HENSO02520
        {
          Scene00039( player ); // Scene00039: Normal(Talk), id=HENSO02520
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00042( player ); // Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR2 = YUGIRI
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020521 || param2 == 1020521 ) // ACTOR12 = LYSE
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1023091 || param2 == 1023091 ) // ACTOR13 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
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
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda502:68056 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00003: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00008: Normal(Talk), id=dummye0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00013: Normal(Talk), id=dummye1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00017: Normal(Talk, TargetCanMove, Menu), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq4( player );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00021: Normal(Talk, NpcDespawn, TargetCanMove), id=HENSO02520" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00027: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00028: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00033: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00036: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00037: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00038: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 38, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00039: Normal(Talk), id=HENSO02520" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00040: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00041: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00042: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
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
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00044: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00045: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda502:68056 calling Scene00046: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda502 );
