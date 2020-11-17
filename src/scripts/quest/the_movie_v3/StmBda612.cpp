// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda612 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda612() : Sapphire::ScriptAPI::EventScript( 68074 ){}; 
  ~StmBda612() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 7 entries
  //SEQ_2, 5 entries
  //SEQ_255, 13 entries

  //ACTOR0 = 1020611
  //ACTOR1 = 1020613
  //ACTOR10 = 1023836
  //ACTOR11 = 1023837
  //ACTOR12 = 1020601
  //ACTOR13 = 1020600
  //ACTOR14 = 1020602
  //ACTOR15 = 1020603
  //ACTOR16 = 1020604
  //ACTOR17 = 1020632
  //ACTOR18 = 1020638
  //ACTOR19 = 1020639
  //ACTOR2 = 1022338
  //ACTOR3 = 1020616
  //ACTOR4 = 1019945
  //ACTOR5 = 1022336
  //ACTOR6 = 1022337
  //ACTOR7 = 1020623
  //ACTOR8 = 1023834
  //ACTOR9 = 1023835
  //BINDACTOR01 = 6904984
  //BINDACTOR02 = 6904985
  //EVENTACTION0 = 35

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020611 || param2 == 1020611 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020613 || param2 == 1020613 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1022338 || param2 == 1022338 ) // ACTOR2 = MNAAGO
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020616 || param2 == 1020616 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019945 || param2 == 1019945 ) // ACTOR4 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1022336 || param2 == 1022336 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1022337 || param2 == 1022337 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020611 || param2 == 1020611 ) // ACTOR0 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020613 || param2 == 1020613 ) // ACTOR1 = LYSE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1022338 || param2 == 1022338 ) // ACTOR2 = MNAAGO
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020616 || param2 == 1020616 ) // ACTOR3 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020623 || param2 == 1020623 ) // ACTOR7 = WOUNDEDRESISTANCESOLDIER
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIER
            // +Callback Scene00014: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIER
          }
          break;
        }
        if( param1 == 1023834 || param2 == 1023834 ) // ACTOR8 = WOUNDEDRESISTANCESOLDIERB
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERB
            // +Callback Scene00017: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERB
          }
          break;
        }
        if( param1 == 1023835 || param2 == 1023835 ) // ACTOR9 = WOUNDEDIMPERIALSOLDIER
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=WOUNDEDIMPERIALSOLDIER
            // +Callback Scene00020: Normal(Talk, TargetCanMove), id=WOUNDEDIMPERIALSOLDIER
          }
          break;
        }
        if( param1 == 1023836 || param2 == 1023836 ) // ACTOR10 = WOUNDEDRESISTANCESOLDIERC
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERC
          break;
        }
        if( param1 == 1023837 || param2 == 1023837 ) // ACTOR11 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020601 || param2 == 1020601 ) // ACTOR12 = ALPHINAUD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020600 || param2 == 1020600 ) // ACTOR13 = MNAAGO
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020602 || param2 == 1020602 ) // ACTOR14 = ALISAIE
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020603 || param2 == 1020603 ) // ACTOR15 = LYSE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020604 || param2 == 1020604 ) // ACTOR16 = RAUBAHN
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020632 || param2 == 1020632 ) // ACTOR17 = PIPIN
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020638 || param2 == 1020638 ) // ACTOR18 = SERPENTOFFICER
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 || param2 == 1020639 ) // ACTOR19 = STORMOFFICER
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1020623 || param2 == 1020623 ) // ACTOR7 = WOUNDEDRESISTANCESOLDIER
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIER
          break;
        }
        if( param1 == 1023834 || param2 == 1023834 ) // ACTOR8 = WOUNDEDRESISTANCESOLDIERB
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERB
          break;
        }
        if( param1 == 1023835 || param2 == 1023835 ) // ACTOR9 = WOUNDEDIMPERIALSOLDIER
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=WOUNDEDIMPERIALSOLDIER
          break;
        }
        if( param1 == 1023836 || param2 == 1023836 ) // ACTOR10 = WOUNDEDRESISTANCESOLDIERC
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERC
          break;
        }
        if( param1 == 1023837 || param2 == 1023837 ) // ACTOR11 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda612:68074 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00003: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00009: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00010: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00013: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00014: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00016: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00017: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00019: Normal(Talk, TargetCanMove), id=WOUNDEDIMPERIALSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00020: Normal(Talk, TargetCanMove), id=WOUNDEDIMPERIALSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00021: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00023: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00024: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00026: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00027: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00028: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00029: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00030: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00031: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00032: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00033: Normal(Talk, TargetCanMove), id=WOUNDEDIMPERIALSOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00034: Normal(Talk, TargetCanMove), id=WOUNDEDRESISTANCESOLDIERC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda612:68074 calling Scene00035: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda612 );
