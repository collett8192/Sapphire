// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmd103 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmd103() : Sapphire::ScriptAPI::EventScript( 69144 ){}; 
  ~LucKmd103() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 6 entries
  //SEQ_2, 10 entries
  //SEQ_3, 10 entries
  //SEQ_4, 13 entries
  //SEQ_255, 9 entries

  //ACTOR0 = 1030587
  //ACTOR1 = 1029602
  //ACTOR2 = 1029603
  //ACTOR3 = 1029604
  //ACTOR4 = 1029605
  //ACTOR5 = 1029607
  //ACTOR6 = 1029608
  //ACTOR7 = 1027248
  //ACTOR8 = 1030315
  //EOBJECT0 = 2010544
  //EOBJECT1 = 2010545
  //EOBJECT2 = 2010661
  //EOBJECT3 = 2010662
  //EOBJECT4 = 2009899
  //EOBJECT5 = 2009901
  //EOBJECT6 = 2009902
  //EOBJECT7 = 2009900
  //EVENTACTION0 = 53
  //ITEM0 = 2002555
  //LOCACTORCHESSAMILE = 1028133
  //LOCACTORMINFILIA = 1026572
  //LOCACTORSOLDIER = 1029397
  //LOCACTORTHANCRED = 1026569

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030587 || param2 == 1030587 ) // ACTOR0 = LYNA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYNA
          break;
        }
        if( param1 == 1029602 || param2 == 1029602 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029603 || param2 == 1029603 ) // ACTOR2 = URIANGER
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029604 || param2 == 1029604 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029605 || param2 == 1029605 ) // ACTOR4 = ALISAIE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029607 || param2 == 1029607 ) // ACTOR5 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=THANCRED
          }
          break;
        }
        if( param1 == 1029602 || param2 == 1029602 ) // ACTOR1 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029603 || param2 == 1029603 ) // ACTOR2 = URIANGER
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029604 || param2 == 1029604 ) // ACTOR3 = YSHTOLA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029605 || param2 == 1029605 ) // ACTOR4 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030587 || param2 == 1030587 ) // ACTOR0 = LYNA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1029608 || param2 == 1029608 ) // ACTOR6 = RYNE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove, SystemTalk), id=RYNE
          }
          break;
        }
        if( param1 == 1029602 || param2 == 1029602 ) // ACTOR1 = ALPHINAUD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029603 || param2 == 1029603 ) // ACTOR2 = URIANGER
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029604 || param2 == 1029604 ) // ACTOR3 = YSHTOLA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029605 || param2 == 1029605 ) // ACTOR4 = ALISAIE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1029607 || param2 == 1029607 ) // ACTOR5 = THANCRED
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 2010544 || param2 == 2010544 ) // EOBJECT0 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010545 || param2 == 2010545 ) // EOBJECT1 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010661 || param2 == 2010661 ) // EOBJECT2 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010662 || param2 == 2010662 ) // EOBJECT3 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1029608 || param2 == 1029608 ) // ACTOR6 = RYNE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove, SystemTalk), id=RYNE
            // +Callback Scene00023: Normal(Talk, NpcDespawn, TargetCanMove, Menu), id=RYNE
            // +Callback Scene00024: Normal(Talk, TargetCanMove, SystemTalk), id=RYNE
          }
          break;
        }
        if( param1 == 1029602 || param2 == 1029602 ) // ACTOR1 = ALPHINAUD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029603 || param2 == 1029603 ) // ACTOR2 = URIANGER
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029604 || param2 == 1029604 ) // ACTOR3 = YSHTOLA
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029605 || param2 == 1029605 ) // ACTOR4 = ALISAIE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1029607 || param2 == 1029607 ) // ACTOR5 = THANCRED
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 2010544 || param2 == 2010544 ) // EOBJECT0 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010545 || param2 == 2010545 ) // EOBJECT1 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010661 || param2 == 2010661 ) // EOBJECT2 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2010662 || param2 == 2010662 ) // EOBJECT3 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BL max stack 2
      case 4:
      {
        if( param1 == 2009899 || param2 == 2009899 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00037( player ); // Scene00037: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2009901 || param2 == 2009901 ) // EOBJECT5 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        if( param1 == 2009902 || param2 == 2009902 ) // EOBJECT6 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1029602 || param2 == 1029602 ) // ACTOR1 = ALPHINAUD
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029603 || param2 == 1029603 ) // ACTOR2 = URIANGER
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029604 || param2 == 1029604 ) // ACTOR3 = YSHTOLA
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029605 || param2 == 1029605 ) // ACTOR4 = ALISAIE
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1029607 || param2 == 1029607 ) // ACTOR5 = THANCRED
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 2009900 || param2 == 2009900 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00046( player ); // Scene00046: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2010544 || param2 == 2010544 ) // EOBJECT0 = unknown
        {
          Scene00047( player ); // Scene00047: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010545 || param2 == 2010545 ) // EOBJECT1 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010661 || param2 == 2010661 ) // EOBJECT2 = unknown
        {
          Scene00049( player ); // Scene00049: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010662 || param2 == 2010662 ) // EOBJECT3 = unknown
        {
          Scene00050( player ); // Scene00050: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 2
      case 255:
      {
        if( param1 == 1027248 || param2 == 1027248 ) // ACTOR7 = CHESSAMILE
        {
          Scene00051( player ); // Scene00051: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00052: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CHESSAMILE
          break;
        }
        if( param1 == 1029602 || param2 == 1029602 ) // ACTOR1 = ALPHINAUD
        {
          Scene00053( player ); // Scene00053: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029603 || param2 == 1029603 ) // ACTOR2 = URIANGER
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029604 || param2 == 1029604 ) // ACTOR3 = YSHTOLA
        {
          Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029605 || param2 == 1029605 ) // ACTOR4 = ALISAIE
        {
          Scene00056( player ); // Scene00056: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1029607 || param2 == 1029607 ) // ACTOR5 = THANCRED
        {
          Scene00057( player ); // Scene00057: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030315 || param2 == 1030315 ) // ACTOR8 = RYNE
        {
          Scene00058( player ); // Scene00058: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 2010661 || param2 == 2010661 ) // EOBJECT2 = unknown
        {
          Scene00059( player ); // Scene00059: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010662 || param2 == 2010662 ) // EOBJECT3 = unknown
        {
          Scene00060( player ); // Scene00060: Normal(None), id=unknown
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
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.updateQuest( getId(), 255 );
        player.setQuestUI8BH( getId(), 2 );
      }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "LucKmd103:69144 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00003: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00006: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00008: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00011: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00012: Normal(Talk, TargetCanMove, SystemTalk), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00014: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00015: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00017: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00022: Normal(Talk, TargetCanMove, SystemTalk), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00023: Normal(Talk, NpcDespawn, TargetCanMove, Menu), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00024( player );
      }
    };
    player.playScene( getId(), 23, NONE, callback );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00024: Normal(Talk, TargetCanMove, SystemTalk), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00026: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00027: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00029: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00031: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00033: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00035: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00036: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00037: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00038: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00039: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00040: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00041: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00042: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00043: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00044: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00046: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00047: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00048: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00049: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00050: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00051: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00052( player );
      }
    };
    player.playScene( getId(), 51, NONE, callback );
  }
  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00052: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CHESSAMILE" );
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
    player.playScene( getId(), 52, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00053: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00054: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00055: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00056: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00057: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 57, NONE, callback );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00058: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 58, NONE, callback );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00059: Normal(None), id=unknown" );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "LucKmd103:69144 calling Scene00060: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( LucKmd103 );
