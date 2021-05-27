// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKme104 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKme104() : Sapphire::ScriptAPI::EventScript( 69169 ){}; 
  ~LucKme104() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_2, 8 entries
  //SEQ_3, 11 entries
  //SEQ_4, 9 entries
  //SEQ_255, 12 entries

  //ACTOR0 = 1030196
  //ACTOR1 = 1030197
  //ACTOR10 = 1030204
  //ACTOR11 = 1030205
  //ACTOR12 = 1030206
  //ACTOR2 = 1030198
  //ACTOR3 = 1030199
  //ACTOR4 = 1030200
  //ACTOR5 = 1030201
  //ACTOR6 = 1030202
  //ACTOR7 = 1030203
  //ACTOR8 = 1027288
  //ACTOR9 = 1027441
  //EOBJECT0 = 2010088
  //EOBJECT1 = 2010089
  //EVENTACTION0 = 3
  //ITEM0 = 2002635
  //ITEM1 = 2002633
  //ITEM2 = 2002634
  //LOCACTOR01 = 1029427
  //LOCSE01 = 39
  //LOCSE02 = 40

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( param1 == 1030197 || param2 == 1030197 ) // ACTOR1 = URIANGER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=URIANGER
          }
          break;
        }
        if( param1 == 1030198 || param2 == 1030198 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030199 || param2 == 1030199 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030200 || param2 == 1030200 ) // ACTOR4 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030201 || param2 == 1030201 ) // ACTOR5 = YSHTOLA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030202 || param2 == 1030202 ) // ACTOR6 = DULIACHAI
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1030203 || param2 == 1030203 ) // ACTOR7 = CHAINUZZ
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1027288 || param2 == 1027288 ) // ACTOR8 = IRVITHE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove, SystemTalk), id=IRVITHE
          }
          break;
        }
        if( param1 == 1030197 || param2 == 1030197 ) // ACTOR1 = URIANGER
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030198 || param2 == 1030198 ) // ACTOR2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030199 || param2 == 1030199 ) // ACTOR3 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030200 || param2 == 1030200 ) // ACTOR4 = ALPHINAUD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030201 || param2 == 1030201 ) // ACTOR5 = YSHTOLA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030202 || param2 == 1030202 ) // ACTOR6 = DULIACHAI
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1030203 || param2 == 1030203 ) // ACTOR7 = CHAINUZZ
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        break;
      }
      //seq 3 event item ITEM1 = UI8CH max stack ?
      //seq 3 event item ITEM2 = UI8CL max stack ?
      //seq 3 event item ITEM0 = UI8DH max stack ?
      case 3:
      {
        if( param1 == 1027441 || param2 == 1027441 ) // ACTOR9 = GRITHIL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=GRITHIL
            // +Callback Scene00018: Normal(Talk, TargetCanMove, SystemTalk), id=GRITHIL
          }
          break;
        }
        if( param1 == 2010088 || param2 == 2010088 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2010089 || param2 == 2010089 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1030197 || param2 == 1030197 ) // ACTOR1 = URIANGER
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030198 || param2 == 1030198 ) // ACTOR2 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030199 || param2 == 1030199 ) // ACTOR3 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030200 || param2 == 1030200 ) // ACTOR4 = ALPHINAUD
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030201 || param2 == 1030201 ) // ACTOR5 = YSHTOLA
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030202 || param2 == 1030202 ) // ACTOR6 = DULIACHAI
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1030203 || param2 == 1030203 ) // ACTOR7 = CHAINUZZ
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1027288 || param2 == 1027288 ) // ACTOR8 = IRVITHE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=IRVITHE
          break;
        }
        break;
      }
      //seq 4 event item ITEM1 = UI8BH max stack ?
      //seq 4 event item ITEM2 = UI8BL max stack ?
      //seq 4 event item ITEM0 = UI8CH max stack ?
      case 4:
      {
        if( param1 == 1027288 || param2 == 1027288 ) // ACTOR8 = IRVITHE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove, Menu, SystemTalk, CanCancel), id=IRVITHE
          }
          break;
        }
        if( param1 == 1030197 || param2 == 1030197 ) // ACTOR1 = URIANGER
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030198 || param2 == 1030198 ) // ACTOR2 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030199 || param2 == 1030199 ) // ACTOR3 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030200 || param2 == 1030200 ) // ACTOR4 = ALPHINAUD
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030201 || param2 == 1030201 ) // ACTOR5 = YSHTOLA
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030202 || param2 == 1030202 ) // ACTOR6 = DULIACHAI
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1030203 || param2 == 1030203 ) // ACTOR7 = CHAINUZZ
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1027441 || param2 == 1027441 ) // ACTOR9 = GRITHIL
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove, SystemTalk), id=GRITHIL
          break;
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack ?
      //seq 255 event item ITEM2 = UI8BL max stack ?
      //seq 255 event item ITEM0 = UI8CH max stack ?
      case 255:
      {
        if( param1 == 1030197 || param2 == 1030197 ) // ACTOR1 = URIANGER
        {
          Scene00040( player ); // Scene00040: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030198 || param2 == 1030198 ) // ACTOR2 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030199 || param2 == 1030199 ) // ACTOR3 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030200 || param2 == 1030200 ) // ACTOR4 = ALPHINAUD
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030201 || param2 == 1030201 ) // ACTOR5 = YSHTOLA
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030202 || param2 == 1030202 ) // ACTOR6 = DULIACHAI
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1030203 || param2 == 1030203 ) // ACTOR7 = CHAINUZZ
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030204 || param2 == 1030204 ) // ACTOR10 = ALISAIE
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030205 || param2 == 1030205 ) // ACTOR11 = THANCRED
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030206 || param2 == 1030206 ) // ACTOR12 = RYNE
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1027288 || param2 == 1027288 ) // ACTOR8 = IRVITHE
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=IRVITHE
          break;
        }
        if( param1 == 1027441 || param2 == 1027441 ) // ACTOR9 = GRITHIL
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=GRITHIL
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
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.setQuestUI8DH( getId(), 0 );
          player.updateQuest( getId(), 4 );
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
    player.sendDebug( "LucKme104:69169 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKme104:69169 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00002: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00007: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00008: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00009: Normal(Talk, TargetCanMove, SystemTalk), id=IRVITHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00010: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00014: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00015: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00016: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00017: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=GRITHIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00018: Normal(Talk, TargetCanMove, SystemTalk), id=GRITHIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00020: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00022: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00023: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00027: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00028: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00029: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00030: Normal(Talk, TargetCanMove), id=IRVITHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00031: Normal(Talk, TargetCanMove, Menu, SystemTalk, CanCancel), id=IRVITHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq4( player );
      }
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00032: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00036: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00037: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00038: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00039: Normal(Talk, TargetCanMove, SystemTalk), id=GRITHIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00040: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER" );
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
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00044: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00045: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00046: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00048: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00049: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00050: Normal(Talk, TargetCanMove), id=IRVITHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "LucKme104:69169 calling Scene00051: Normal(Talk, TargetCanMove), id=GRITHIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKme104 );
