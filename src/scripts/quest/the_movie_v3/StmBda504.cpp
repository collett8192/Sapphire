// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda504 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda504() : Sapphire::ScriptAPI::EventScript( 68058 ){}; 
  ~StmBda504() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 8 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_4, 6 entries
  //SEQ_5, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1020234
  //ACTOR1 = 1020233
  //ACTOR10 = 1020238
  //ACTOR11 = 1020239
  //ACTOR2 = 1020232
  //ACTOR3 = 1020519
  //ACTOR4 = 1020523
  //ACTOR5 = 1019285
  //ACTOR6 = 1019286
  //ACTOR7 = 1019287
  //ACTOR8 = 1023083
  //ACTOR9 = 1020237
  //EOBJECT0 = 2007931
  //EVENTACTION0 = 1
  //ITEM0 = 2002178
  //LOCBGM01 = 489

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020234 || param2 == 1020234 ) // ACTOR0 = LYSE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020233 || param2 == 1020233 ) // ACTOR1 = ISSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1020232 || param2 == 1020232 ) // ACTOR2 = TSURANUKI
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019285 || param2 == 1019285 ) // ACTOR5 = HANAME
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=HANAME
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=HANAME
          }
          break;
        }
        if( param1 == 1019286 || param2 == 1019286 ) // ACTOR6 = KAIDATE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=KAIDATE
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=KAIDATE
          }
          break;
        }
        if( param1 == 1019287 || param2 == 1019287 ) // ACTOR7 = MOTOJIRO
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MOTOJIRO
            // +Callback Scene00011: Normal(Talk, TargetCanMove), id=MOTOJIRO
          }
          break;
        }
        if( param1 == 1020232 || param2 == 1020232 ) // ACTOR2 = TSURANUKI
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020233 || param2 == 1020233 ) // ACTOR1 = ISSE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1020234 || param2 == 1020234 ) // ACTOR0 = LYSE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1023083 || param2 == 1023083 ) // ACTOR8 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1019285 || param2 == 1019285 ) // ACTOR5 = HANAME
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=HANAME
          break;
        }
        if( param1 == 1019286 || param2 == 1019286 ) // ACTOR6 = KAIDATE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=KAIDATE
          break;
        }
        if( param1 == 1019287 || param2 == 1019287 ) // ACTOR7 = MOTOJIRO
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=MOTOJIRO
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020237 || param2 == 1020237 ) // ACTOR9 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1019285 || param2 == 1019285 ) // ACTOR5 = HANAME
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=HANAME
          break;
        }
        if( param1 == 1019286 || param2 == 1019286 ) // ACTOR6 = KAIDATE
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=KAIDATE
          break;
        }
        if( param1 == 1019287 || param2 == 1019287 ) // ACTOR7 = MOTOJIRO
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=MOTOJIRO
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020238 || param2 == 1020238 ) // ACTOR10 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00029( player ); // Scene00029: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1019285 || param2 == 1019285 ) // ACTOR5 = HANAME
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=HANAME
          break;
        }
        if( param1 == 1019286 || param2 == 1019286 ) // ACTOR6 = KAIDATE
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=KAIDATE
          break;
        }
        if( param1 == 1019287 || param2 == 1019287 ) // ACTOR7 = MOTOJIRO
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=MOTOJIRO
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 1
      case 5:
      {
        if( param1 == 2007931 || param2 == 2007931 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00036( player ); // Scene00036: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1019285 || param2 == 1019285 ) // ACTOR5 = HANAME
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=HANAME
          break;
        }
        if( param1 == 1019286 || param2 == 1019286 ) // ACTOR6 = KAIDATE
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=KAIDATE
          break;
        }
        if( param1 == 1019287 || param2 == 1019287 ) // ACTOR7 = MOTOJIRO
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=MOTOJIRO
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1020239 || param2 == 1020239 ) // ACTOR11 = HIEN
        {
          Scene00042( player ); // Scene00042: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00043: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1019285 || param2 == 1019285 ) // ACTOR5 = HANAME
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=HANAME
          break;
        }
        if( param1 == 1019286 || param2 == 1019286 ) // ACTOR6 = KAIDATE
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=KAIDATE
          break;
        }
        if( param1 == 1019287 || param2 == 1019287 ) // ACTOR7 = MOTOJIRO
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=MOTOJIRO
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=YUGIRI
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
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
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
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda504:68058 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00002: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00003: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00006: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00007: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00008: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00009: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00010: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00011: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00012: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00013: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00014: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00018: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00019: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00020: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00022: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00024: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00025: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00026: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00028: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00029: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00030: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00031: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00032: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00033: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00034: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00036: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq5( player );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00037: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00038: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00039: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00040: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00041: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00042: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00043( player );
      }
    };
    player.playScene( getId(), 42, NONE, callback );
  }
  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00043: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=HIEN" );
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
    player.playScene( getId(), 43, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00044: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00045: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00046: Normal(Talk, TargetCanMove), id=MOTOJIRO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda504:68058 calling Scene00048: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda504 );