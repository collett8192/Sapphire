// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class XxaUsc908 : public Sapphire::ScriptAPI::EventScript
{
public:
  XxaUsc908() : Sapphire::ScriptAPI::EventScript( 69408 ){}; 
  ~XxaUsc908() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_2, 9 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006638
  //ACTOR1 = 1006647
  //ACTOR10 = 1006646
  //ACTOR2 = 1006724
  //ACTOR3 = 1006723
  //ACTOR4 = 1006722
  //ACTOR5 = 1006721
  //ACTOR6 = 1006678
  //ACTOR7 = 1006648
  //ACTOR8 = 1006649
  //ACTOR9 = 1006650
  //QSTACCEPTCHECK01 = 66575
  //QSTACCEPTCHECK02 = 66578
  //QSTACCEPTCHECK03 = 66579

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CRACKEDFIST
        break;
      }
      case 1:
      {
        if( param1 == 1006647 || param2 == 1006647 ) // ACTOR1 = RAUBAHN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1006724 || param2 == 1006724 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006723 || param2 == 1006723 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006722 || param2 == 1006722 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006721 || param2 == 1006721 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006678 || param2 == 1006678 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006638 || param2 == 1006638 ) // ACTOR0 = CRACKEDFIST
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=CRACKEDFIST
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1006648 || param2 == 1006648 ) // ACTOR7 = ENPC1
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ENPC1
            // +Callback Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC1
          }
          else
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ENPC1
          }
          break;
        }
        if( param1 == 1006649 || param2 == 1006649 ) // ACTOR8 = ENPC2
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ENPC2
            // +Callback Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC2
          }
          else
          {
            Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ENPC2
          }
          break;
        }
        if( param1 == 1006650 || param2 == 1006650 ) // ACTOR9 = ENPC3
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ENPC3
            // +Callback Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC3
          }
          else
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ENPC3
          }
          break;
        }
        if( param1 == 1006647 || param2 == 1006647 ) // ACTOR1 = RAUBAHN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1006721 || param2 == 1006721 ) // ACTOR5 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006722 || param2 == 1006722 ) // ACTOR4 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006723 || param2 == 1006723 ) // ACTOR3 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006724 || param2 == 1006724 ) // ACTOR2 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006678 || param2 == 1006678 ) // ACTOR6 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=EDELSTEIN
        // +Callback Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=EDELSTEIN
        // +Callback Scene00026: Normal(Talk, TargetCanMove), id=EDELSTEIN
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown" );
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
    player.sendDebug( "XxaUsc908:69408 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CRACKEDFIST" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00002: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00008: Normal(Talk, TargetCanMove), id=CRACKEDFIST" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00009: Normal(Talk, TargetCanMove), id=ENPC1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00011: Normal(Talk, TargetCanMove), id=ENPC1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00012: Normal(Talk, TargetCanMove), id=ENPC2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00014: Normal(Talk, TargetCanMove), id=ENPC2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00015: Normal(Talk, TargetCanMove), id=ENPC3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=ENPC3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00017: Normal(Talk, TargetCanMove), id=ENPC3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00018: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00024: Normal(Talk, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00025( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00026( player );
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc908:69408 calling Scene00026: Normal(Talk, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 26, NONE, callback );
  }
};

EXPOSE_SCRIPT( XxaUsc908 );
