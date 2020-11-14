// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda323 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda323() : Sapphire::ScriptAPI::EventScript( 68035 ){}; 
  ~StmBda323() = default; 

  //SEQ_0, 9 entries
  //SEQ_1, 9 entries
  //SEQ_2, 7 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1020059
  //ACTOR1 = 1020057
  //ACTOR10 = 1020063
  //ACTOR11 = 1020064
  //ACTOR12 = 1020065
  //ACTOR13 = 1020066
  //ACTOR14 = 1020067
  //ACTOR15 = 1023080
  //ACTOR16 = 1023081
  //ACTOR2 = 1020058
  //ACTOR3 = 1020189
  //ACTOR4 = 1020060
  //ACTOR5 = 1020061
  //ACTOR6 = 1023077
  //ACTOR7 = 1023078
  //ACTOR8 = 1023079
  //ACTOR9 = 1020062
  //BINDACTOR0 = 6782495
  //BINDACTOR1 = 6782494
  //LOCACTOR0 = 1018509
  //LOCACTOR1 = 1019096
  //LOCACTOR2 = 1019710
  //LOCACTOR3 = 1018977
  //NCUT01 = 1432
  //NCUT02 = 1433
  //NCUT03 = 1434

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020059 || param2 == 1020059 ) // ACTOR0 = ISSE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ISSE
        }
        if( param1 == 1020057 || param2 == 1020057 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020058 || param2 == 1020058 ) // ACTOR2 = GOSETSU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1020189 || param2 == 1020189 ) // ACTOR3 = YUGIRI
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020060 || param2 == 1020060 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        if( param1 == 1020061 || param2 == 1020061 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( param1 == 1023077 || param2 == 1023077 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( param1 == 1023078 || param2 == 1023078 ) // ACTOR7 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( param1 == 1023079 || param2 == 1023079 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020062 || param2 == 1020062 ) // ACTOR9 = ISSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ISSE
            // +Callback Scene00011: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1020057 || param2 == 1020057 ) // ACTOR1 = ALISAIE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1020058 || param2 == 1020058 ) // ACTOR2 = GOSETSU
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1020189 || param2 == 1020189 ) // ACTOR3 = YUGIRI
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020060 || param2 == 1020060 ) // ACTOR4 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( param1 == 1020061 || param2 == 1020061 ) // ACTOR5 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( param1 == 1023077 || param2 == 1023077 ) // ACTOR6 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( param1 == 1023078 || param2 == 1023078 ) // ACTOR7 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        if( param1 == 1023079 || param2 == 1023079 ) // ACTOR8 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020063 || param2 == 1020063 ) // ACTOR10 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI
            // +Callback Scene00021: Normal(Talk, TargetCanMove), id=YUGIRI
          }
        }
        if( param1 == 1020064 || param2 == 1020064 ) // ACTOR11 = GOSETSU
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=GOSETSU
            // +Callback Scene00023: Normal(Talk, TargetCanMove), id=GOSETSU
          }
        }
        if( param1 == 1020065 || param2 == 1020065 ) // ACTOR12 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=LYSE
            // +Callback Scene00025: Normal(Talk, TargetCanMove), id=LYSE
          }
        }
        if( param1 == 1020066 || param2 == 1020066 ) // ACTOR13 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALISAIE
            // +Callback Scene00027: Normal(Talk, TargetCanMove), id=ALISAIE
          }
        }
        if( param1 == 1020067 || param2 == 1020067 ) // ACTOR14 = ALPHINAUD
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1023080 || param2 == 1023080 ) // ACTOR15 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
        }
        if( param1 == 1023081 || param2 == 1023081 ) // ACTOR16 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020067 || param2 == 1020067 ) // ACTOR14 = ALPHINAUD
        {
          Scene00031( player ); // Scene00031: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          // +Callback Scene00032: Normal(CutScene), id=unknown
        }
        if( param1 == 1020063 || param2 == 1020063 ) // ACTOR10 = YUGIRI
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020064 || param2 == 1020064 ) // ACTOR11 = GOSETSU
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1020065 || param2 == 1020065 ) // ACTOR12 = LYSE
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020066 || param2 == 1020066 ) // ACTOR13 = ALISAIE
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1023080 || param2 == 1023080 ) // ACTOR15 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
        }
        if( param1 == 1023081 || param2 == 1023081 ) // ACTOR16 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 4 )
      if( player.getQuestUI8AL( getId() ) == 4 )
        if( player.getQuestUI8AL( getId() ) == 4 )
          if( player.getQuestUI8AL( getId() ) == 4 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.updateQuest( getId(), 255 );
          }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda323:68035 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00010: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00011: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00020: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00021: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00022: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00023: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00024: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00025( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00025: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00026: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00027( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00027: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00031: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00032( player );
      }
    };
    player.playScene( getId(), 31, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00032: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 32, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00034: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00035: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00036: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00037: Normal(None), id=unknown" );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda323:68035 calling Scene00038: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda323 );
