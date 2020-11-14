// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda301 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda301() : Sapphire::ScriptAPI::EventScript( 68013 ){}; 
  ~StmBda301() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 4 entries
  //SEQ_2, 4 entries
  //SEQ_255, 5 entries

  //ACTIONTIMELINEEVENTJOY = 953
  //ACTOR0 = 1019891
  //ACTOR1 = 1019888
  //ACTOR10 = 1019899
  //ACTOR11 = 1019900
  //ACTOR12 = 1019901
  //ACTOR13 = 1019902
  //ACTOR2 = 1019889
  //ACTOR3 = 1019890
  //ACTOR4 = 1019893
  //ACTOR5 = 1019894
  //ACTOR6 = 1019895
  //ACTOR7 = 1019896
  //ACTOR8 = 1019897
  //ACTOR9 = 1019898
  //BINDACTOR0 = 6793860
  //BINDACTOR1 = 6793862
  //BINDACTOR2 = 6793863
  //BINDACTOR3 = 6793888
  //BINDACTOR4 = 6793889
  //BINDACTOR5 = 6793895
  //EOBJECT0 = 2007845

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1019891 || param2 == 1019891 ) // ACTOR0 = SOROBAN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SOROBAN
        }
        if( param1 == 1019888 || param2 == 1019888 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019889 || param2 == 1019889 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019890 || param2 == 1019890 ) // ACTOR3 = GOSETSU
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 2007845 || param2 == 2007845 ) // EOBJECT0 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019893 || param2 == 1019893 ) // ACTOR4 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE
          }
        }
        if( param1 == 1019894 || param2 == 1019894 ) // ACTOR5 = ALISAIE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019895 || param2 == 1019895 ) // ACTOR6 = GOSETSU
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1019896 || param2 == 1019896 ) // ACTOR7 = SOROBAN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=SOROBAN
        }
        break;
      }
      case 2:
      {
        if( param1 == 1019896 || param2 == 1019896 ) // ACTOR7 = SOROBAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=SOROBAN
          }
        }
        if( param1 == 1019894 || param2 == 1019894 ) // ACTOR5 = ALISAIE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019895 || param2 == 1019895 ) // ACTOR6 = GOSETSU
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1019897 || param2 == 1019897 ) // ACTOR8 = LYSE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019898 || param2 == 1019898 ) // ACTOR9 = TANSUI
        {
          Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TANSUI
        }
        if( param1 == 1019899 || param2 == 1019899 ) // ACTOR10 = LYSE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019900 || param2 == 1019900 ) // ACTOR11 = ALISAIE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019901 || param2 == 1019901 ) // ACTOR12 = GOSETSU
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1019902 || param2 == 1019902 ) // ACTOR13 = SOROBAN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=SOROBAN
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
    player.sendDebug( "StmBda301:68013 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda301:68013 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq0( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00008: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00009: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00010: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00012: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TANSUI" );
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
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00015: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00017: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda301:68013 calling Scene00018: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda301 );
