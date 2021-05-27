// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKme103 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKme103() : Sapphire::ScriptAPI::EventScript( 69168 ){}; 
  ~LucKme103() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 7 entries
  //SEQ_2, 7 entries
  //SEQ_3, 9 entries
  //SEQ_4, 8 entries
  //SEQ_5, 9 entries
  //SEQ_6, 7 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1030184
  //ACTOR1 = 1030185
  //ACTOR10 = 1030193
  //ACTOR2 = 1030186
  //ACTOR3 = 1030187
  //ACTOR4 = 1030188
  //ACTOR5 = 1030194
  //ACTOR6 = 1030195
  //ACTOR7 = 1030190
  //ACTOR8 = 1030191
  //ACTOR9 = 1030192
  //BINDACTOR01 = 7945827
  //CUTSCENE0 = 2043
  //ITEM0 = 2002609
  //LOCBGM01 = 661

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( param1 == 1030184 || param2 == 1030184 ) // ACTOR0 = THANCRED
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030185 || param2 == 1030185 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030186 || param2 == 1030186 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030187 || param2 == 1030187 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030188 || param2 == 1030188 ) // ACTOR4 = URIANGER
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030194 || param2 == 1030194 ) // ACTOR5 = RYNE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030195 || param2 == 1030195 ) // ACTOR6 = PATIENT03631
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=PATIENT03631
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 1030190 || param2 == 1030190 ) // ACTOR7 = THOARICH
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=THOARICH
          }
          break;
        }
        if( param1 == 1030185 || param2 == 1030185 ) // ACTOR1 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030186 || param2 == 1030186 ) // ACTOR2 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030187 || param2 == 1030187 ) // ACTOR3 = YSHTOLA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030188 || param2 == 1030188 ) // ACTOR4 = URIANGER
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030194 || param2 == 1030194 ) // ACTOR5 = RYNE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030195 || param2 == 1030195 ) // ACTOR6 = PATIENT03631
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=PATIENT03631
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( param1 == 1030190 || param2 == 1030190 ) // ACTOR7 = THOARICH
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, Inventory, TargetCanMove), id=THOARICH
            // +Callback Scene00016: Normal(Talk, TargetCanMove), id=THOARICH
          }
          break;
        }
        if( param1 == 1030185 || param2 == 1030185 ) // ACTOR1 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030186 || param2 == 1030186 ) // ACTOR2 = ALISAIE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030187 || param2 == 1030187 ) // ACTOR3 = YSHTOLA
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030188 || param2 == 1030188 ) // ACTOR4 = URIANGER
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030194 || param2 == 1030194 ) // ACTOR5 = RYNE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030195 || param2 == 1030195 ) // ACTOR6 = PATIENT03631
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=PATIENT03631
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      case 3:
      {
        if( param1 == 1030191 || param2 == 1030191 ) // ACTOR8 = LADY03287
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=LADY03287
          }
          break;
        }
        if( param1 == 1030185 || param2 == 1030185 ) // ACTOR1 = ALPHINAUD
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030186 || param2 == 1030186 ) // ACTOR2 = ALISAIE
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030187 || param2 == 1030187 ) // ACTOR3 = YSHTOLA
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030188 || param2 == 1030188 ) // ACTOR4 = URIANGER
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030190 || param2 == 1030190 ) // ACTOR7 = THOARICH
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=THOARICH
          break;
        }
        if( param1 == 1030192 || param2 == 1030192 ) // ACTOR9 = EMPLOYEE03287
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=EMPLOYEE03287
          break;
        }
        if( param1 == 1030194 || param2 == 1030194 ) // ACTOR5 = RYNE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030195 || param2 == 1030195 ) // ACTOR6 = PATIENT03631
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=PATIENT03631
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      case 4:
      {
        if( param1 == 1030191 || param2 == 1030191 ) // ACTOR8 = LADY03287
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00032( player ); // Scene00032: Normal(Talk, Inventory, TargetCanMove), id=LADY03287
            // +Callback Scene00033: Normal(Talk), id=unknown
          }
          break;
        }
        if( param1 == 1030185 || param2 == 1030185 ) // ACTOR1 = ALPHINAUD
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030186 || param2 == 1030186 ) // ACTOR2 = ALISAIE
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030187 || param2 == 1030187 ) // ACTOR3 = YSHTOLA
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030188 || param2 == 1030188 ) // ACTOR4 = URIANGER
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030192 || param2 == 1030192 ) // ACTOR9 = EMPLOYEE03287
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=EMPLOYEE03287
          break;
        }
        if( param1 == 1030194 || param2 == 1030194 ) // ACTOR5 = RYNE
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030195 || param2 == 1030195 ) // ACTOR6 = PATIENT03631
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=PATIENT03631
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack ?
      case 5:
      {
        if( param1 == 1030193 || param2 == 1030193 ) // ACTOR10 = GENTLEMAN03289
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=GENTLEMAN03289
          }
          break;
        }
        if( param1 == 1030185 || param2 == 1030185 ) // ACTOR1 = ALPHINAUD
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030186 || param2 == 1030186 ) // ACTOR2 = ALISAIE
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030187 || param2 == 1030187 ) // ACTOR3 = YSHTOLA
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030188 || param2 == 1030188 ) // ACTOR4 = URIANGER
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030191 || param2 == 1030191 ) // ACTOR8 = LADY03287
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=LADY03287
          break;
        }
        if( param1 == 1030192 || param2 == 1030192 ) // ACTOR9 = EMPLOYEE03287
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=EMPLOYEE03287
          break;
        }
        if( param1 == 1030194 || param2 == 1030194 ) // ACTOR5 = RYNE
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030195 || param2 == 1030195 ) // ACTOR6 = PATIENT03631
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=PATIENT03631
          break;
        }
        break;
      }
      //seq 6 event item ITEM0 = UI8BH max stack ?
      case 6:
      {
        if( param1 == 1030193 || param2 == 1030193 ) // ACTOR10 = GENTLEMAN03289
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00050( player ); // Scene00050: Normal(Talk, Inventory, TargetCanMove), id=GENTLEMAN03289
            // +Callback Scene00051: Normal(Talk, TargetCanMove), id=GENTLEMAN03289
          }
          break;
        }
        if( param1 == 1030185 || param2 == 1030185 ) // ACTOR1 = ALPHINAUD
        {
          Scene00052( player ); // Scene00052: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030186 || param2 == 1030186 ) // ACTOR2 = ALISAIE
        {
          Scene00053( player ); // Scene00053: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030187 || param2 == 1030187 ) // ACTOR3 = YSHTOLA
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030188 || param2 == 1030188 ) // ACTOR4 = URIANGER
        {
          Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030194 || param2 == 1030194 ) // ACTOR5 = RYNE
        {
          Scene00056( player ); // Scene00056: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030195 || param2 == 1030195 ) // ACTOR6 = PATIENT03631
        {
          Scene00057( player ); // Scene00057: Normal(Talk, TargetCanMove), id=PATIENT03631
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030194 || param2 == 1030194 ) // ACTOR5 = RYNE
        {
          Scene00058( player ); // Scene00058: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, Menu), id=RYNE
          // +Callback Scene00059: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1030185 || param2 == 1030185 ) // ACTOR1 = ALPHINAUD
        {
          Scene00060( player ); // Scene00060: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030186 || param2 == 1030186 ) // ACTOR2 = ALISAIE
        {
          Scene00061( player ); // Scene00061: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030187 || param2 == 1030187 ) // ACTOR3 = YSHTOLA
        {
          Scene00062( player ); // Scene00062: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030188 || param2 == 1030188 ) // ACTOR4 = URIANGER
        {
          Scene00063( player ); // Scene00063: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030193 || param2 == 1030193 ) // ACTOR10 = GENTLEMAN03289
        {
          Scene00064( player ); // Scene00064: Normal(Talk, TargetCanMove), id=GENTLEMAN03289
          break;
        }
        if( param1 == 1030195 || param2 == 1030195 ) // ACTOR6 = PATIENT03631
        {
          Scene00065( player ); // Scene00065: Normal(Talk, TargetCanMove), id=PATIENT03631
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKme103:69168 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00005: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00006: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00007: Normal(Talk, TargetCanMove), id=PATIENT03631" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00008: Normal(Talk, TargetCanMove), id=THOARICH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00012: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00013: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00014: Normal(Talk, TargetCanMove), id=PATIENT03631" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00015: Normal(Talk, Inventory, TargetCanMove), id=THOARICH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00016: Normal(Talk, TargetCanMove), id=THOARICH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00019: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00020: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00021: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00022: Normal(Talk, TargetCanMove), id=PATIENT03631" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00023: Normal(Talk, TargetCanMove), id=LADY03287" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00026: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00027: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00028: Normal(Talk, TargetCanMove), id=THOARICH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00029: Normal(Talk, TargetCanMove), id=EMPLOYEE03287" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00030: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00031: Normal(Talk, TargetCanMove), id=PATIENT03631" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00032: Normal(Talk, Inventory, TargetCanMove), id=LADY03287" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00033( player );
    };
    player.playScene( getId(), 32, NONE, callback );
  }
  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00033: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00034: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00035: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00036: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00037: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00038: Normal(Talk, TargetCanMove), id=EMPLOYEE03287" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00039: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00040: Normal(Talk, TargetCanMove), id=PATIENT03631" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00041: Normal(Talk, TargetCanMove), id=GENTLEMAN03289" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00042: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00043: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00044: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00045: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00046: Normal(Talk, TargetCanMove), id=LADY03287" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00047: Normal(Talk, TargetCanMove), id=EMPLOYEE03287" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00048: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00049: Normal(Talk, TargetCanMove), id=PATIENT03631" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00050: Normal(Talk, Inventory, TargetCanMove), id=GENTLEMAN03289" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00051( player );
    };
    player.playScene( getId(), 50, NONE, callback );
  }
  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00051: Normal(Talk, TargetCanMove), id=GENTLEMAN03289" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00052: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00053: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00054: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00055: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00056: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00057: Normal(Talk, TargetCanMove), id=PATIENT03631" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 57, NONE, callback );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00058: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, Menu), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00059( player );
      }
    };
    player.playScene( getId(), 58, NONE, callback );
  }
  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00059: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 59, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00060: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 60, NONE, callback );
  }

  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00061: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 61, NONE, callback );
  }

  void Scene00062( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00062: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 62, NONE, callback );
  }

  void Scene00063( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00063: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 63, NONE, callback );
  }

  void Scene00064( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00064: Normal(Talk, TargetCanMove), id=GENTLEMAN03289" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 64, NONE, callback );
  }

  void Scene00065( Entity::Player& player )
  {
    player.sendDebug( "LucKme103:69168 calling Scene00065: Normal(Talk, TargetCanMove), id=PATIENT03631" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 65, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKme103 );
