// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmg106 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmg106() : Sapphire::ScriptAPI::EventScript( 69214 ){}; 
  ~LucKmg106() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 7 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1031742
  //ACTOR1 = 1031743
  //ACTOR10 = 1031747
  //ACTOR2 = 1027544
  //ACTOR3 = 1031744
  //ACTOR4 = 1031745
  //ACTOR5 = 1031838
  //ACTOR6 = 1030611
  //ACTOR7 = 1029990
  //ACTOR8 = 1027602
  //ACTOR9 = 1031746
  //ITEM0 = 2002917
  //ITEM1 = 2002918
  //ITEM2 = 2002919
  //LOCBINDACTOR0 = 8132561
  //LOCBINDACTOR1 = 8132573
  //LOCBINDACTOR2 = 8151119

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1031742 || param2 == 1031742 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031743 || param2 == 1031743 ) // ACTOR1 = KAISHIRR
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 1
      //seq 1 event item ITEM1 = UI8CL max stack 1
      //seq 1 event item ITEM2 = UI8DH max stack 1
      case 1:
      {
        if( param1 == 1027544 || param2 == 1027544 ) // ACTOR2 = MOWEN
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove, SystemTalk), id=MOWEN
            // +Callback Scene00004: Normal(Talk, TargetCanMove), id=MOWEN
          }
          break;
        }
        if( param1 == 1031744 || param2 == 1031744 ) // ACTOR3 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031745 || param2 == 1031745 ) // ACTOR4 = KAISHIRR
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 1031838 || param2 == 1031838 ) // ACTOR5 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030611 || param2 == 1030611 ) // ACTOR6 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1029990 || param2 == 1029990 ) // ACTOR7 = CORNENNE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove, SystemTalk), id=CORNENNE
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=CORNENNE
          }
          break;
        }
        if( param1 == 4302764757 || param2 == 1027602 ) // ACTOR8 = HATHENBET
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove, SystemTalk), id=HATHENBET
            // +Callback Scene00012: Normal(Talk, TargetCanMove), id=HATHENBET
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      //seq 255 event item ITEM2 = UI8CH max stack 1
      case 255:
      {
        if( param1 == 1031746 || param2 == 1031746 ) // ACTOR9 = ALPHINAUD
        {
          Scene00013( player ); // Scene00013: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031747 || param2 == 1031747 ) // ACTOR10 = KAISHIRR
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 1027544 || param2 == 1027544 ) // ACTOR2 = MOWEN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MOWEN
          break;
        }
        if( param1 == 1029990 || param2 == 1029990 ) // ACTOR7 = CORNENNE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=CORNENNE
          break;
        }
        if( param1 == 1027602 || param2 == 1027602 ) // ACTOR8 = HATHENBET
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=HATHENBET
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
          player.setQuestUI8CH( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.setQuestUI8DH( getId(), 0 );
          player.updateQuest( getId(), 255 );
          player.setQuestUI8BH( getId(), 1 );
          player.setQuestUI8BL( getId(), 1 );
          player.setQuestUI8CH( getId(), 1 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmg106:69214 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00002: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00003: Normal(Talk, TargetCanMove, SystemTalk), id=MOWEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00004: Normal(Talk, TargetCanMove), id=MOWEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00006: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00008: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00009: Normal(Talk, TargetCanMove, SystemTalk), id=CORNENNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00010: Normal(Talk, TargetCanMove), id=CORNENNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00011: Normal(Talk, TargetCanMove, SystemTalk), id=HATHENBET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00012: Normal(Talk, TargetCanMove), id=HATHENBET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00013: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00014( player );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.sendDebug( "LucKmg106:69214 calling Scene00015: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00016: Normal(Talk, TargetCanMove), id=MOWEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00017: Normal(Talk, TargetCanMove), id=CORNENNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmg106:69214 calling Scene00018: Normal(Talk, TargetCanMove), id=HATHENBET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmg106 );
