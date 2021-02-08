// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma309 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma309() : Sapphire::ScriptAPI::EventScript( 68835 ){}; 
  ~LucKma309() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 9 entries
  //SEQ_2, 3 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1029010
  //ACTOR1 = 1029012
  //ACTOR10 = 1027911
  //ACTOR11 = 1029014
  //ACTOR12 = 1027854
  //ACTOR13 = 1029015
  //ACTOR14 = 1028923
  //ACTOR15 = 1029842
  //ACTOR2 = 1029013
  //ACTOR3 = 1028961
  //ACTOR4 = 1028964
  //ACTOR5 = 1028965
  //ACTOR6 = 1028966
  //ACTOR7 = 1028967
  //ACTOR8 = 1028968
  //ACTOR9 = 1028969
  //LOCACTOR0 = 1026567
  //LOCACTOR1 = 1029338
  //LOCACTOR2 = 1029339
  //LOCBINDACTOR0 = 7925644
  //LOCBINDACTOR1 = 7926112
  //POPRANGE0 = 7926816
  //QSTCHK00 = 65580
  //QSTCHK01 = 68826

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029010 || param2 == 1029010 ) // ACTOR0 = ALISAIE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1029012 || param2 == 1029012 ) // ACTOR1 = HALRIC
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HALRIC
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029013 || param2 == 1029013 ) // ACTOR2 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove, Menu), id=ALISAIE
          }
          break;
        }
        if( param1 == 1028961 || param2 == 1028961 ) // ACTOR3 = CASSARD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=CASSARD
          break;
        }
        if( param1 == 1028964 || param2 == 1028964 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028965 || param2 == 1028965 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028966 || param2 == 1028966 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028967 || param2 == 1028967 ) // ACTOR7 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028968 || param2 == 1028968 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028969 || param2 == 1028969 ) // ACTOR9 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 1027911 || param2 == 1027911 ) // ACTOR10 = WILLFORT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=WILLFORT
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1029014 || param2 == 1029014 ) // ACTOR11 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1027911 || param2 == 1027911 ) // ACTOR10 = WILLFORT
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=WILLFORT
          break;
        }
        if( param1 == 1027854 || param2 == 1027854 ) // ACTOR12 = CASSARD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=CASSARD
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029015 || param2 == 1029015 ) // ACTOR13 = ALISAIE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1028923 || param2 == 1028923 ) // ACTOR14 = MYSTERYVOICE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1029842 || param2 == 1029842 ) // ACTOR15 = MALPHINAUD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MALPHINAUD
          break;
        }
        if( param1 == 1027911 || param2 == 1027911 ) // ACTOR10 = WILLFORT
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=WILLFORT
          break;
        }
        if( param1 == 1027854 || param2 == 1027854 ) // ACTOR12 = CASSARD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=CASSARD
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "LucKma309:68835 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00002: Normal(Talk, TargetCanMove), id=HALRIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00003: Normal(Talk, TargetCanMove, Menu), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 819, 50, 36.2, -171, 0.43, true );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00004: Normal(Talk, TargetCanMove), id=CASSARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00011: Normal(Talk, TargetCanMove), id=WILLFORT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00013: Normal(Talk, TargetCanMove), id=WILLFORT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00014: Normal(Talk, TargetCanMove), id=CASSARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
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
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00016: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00017: Normal(Talk, TargetCanMove), id=MALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00018: Normal(Talk, TargetCanMove), id=WILLFORT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKma309:68835 calling Scene00019: Normal(Talk, TargetCanMove), id=CASSARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKma309 );
