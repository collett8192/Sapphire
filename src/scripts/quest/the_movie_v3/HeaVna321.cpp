// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna321 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna321() : Sapphire::ScriptAPI::EventScript( 67158 ){}; 
  ~HeaVna321() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 4 entries
  //SEQ_2, 3 entries
  //SEQ_3, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1012083
  //ACTOR1 = 1015174
  //ACTOR2 = 1012079
  //ACTOR3 = 1012081
  //EOBJECT0 = 2005456
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001583
  //LOCMOTION0 = 958
  //LOCQUESTHEAVNA319 = 67156
  //LOCQUESTHEAVNA320 = 67157

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012083 || actorId == 1012083 ) // ACTOR0 = MOGWIN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MOGWIN
        }
        if( actor == 1015174 || actorId == 1015174 ) // ACTOR1 = MOGC01622
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MOGC01622
        }
        break;
      }
      case 1:
      {
        if( actor == 1015174 || actorId == 1015174 ) // ACTOR1 = MOGC01622
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=MOGC01622
          }
        }
        if( actor == 1012079 || actorId == 1012079 ) // ACTOR2 = MOGTOE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MOGTOE
            // +Callback Scene00005: Normal(Talk, TargetCanMove), id=MOGTOE
          }
        }
        if( actor == 1012081 || actorId == 1012081 ) // ACTOR3 = MOGOMO
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MOGOMO
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=MOGOMO
          }
        }
        if( actor == 1012083 || actorId == 1012083 ) // ACTOR0 = MOGWIN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MOGWIN
        }
        break;
      }
      case 2:
      {
        if( actor == 1012083 || actorId == 1012083 ) // ACTOR0 = MOGWIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=MOGWIN
          }
        }
        if( actor == 1012079 || actorId == 1012079 ) // ACTOR2 = MOGTOE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MOGTOE
        }
        if( actor == 1012081 || actorId == 1012081 ) // ACTOR3 = MOGOMO
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=MOGOMO
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( actor == 2005456 || actorId == 2005456 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
            // +Callback Scene00013: Normal(None), id=unknown
          }
        }
        if( actor == 1012083 || actorId == 1012083 ) // ACTOR0 = MOGWIN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=MOGWIN
        }
        if( actor == 1012079 || actorId == 1012079 ) // ACTOR2 = MOGTOE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=MOGTOE
        }
        if( actor == 1012081 || actorId == 1012081 ) // ACTOR3 = MOGOMO
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MOGOMO
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        Scene00017( player ); // Scene00017: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MOGWIN
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
    onProgress( player, param1, param1, 3, param1 );
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
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna321:67158 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MOGWIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00002: Normal(Talk, TargetCanMove), id=MOGC01622" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=MOGC01622" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00004: Normal(Talk, TargetCanMove), id=MOGTOE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling [BranchTrue]Scene00005: Normal(Talk, TargetCanMove), id=MOGTOE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00006: Normal(Talk, TargetCanMove), id=MOGOMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling [BranchTrue]Scene00007: Normal(Talk, TargetCanMove), id=MOGOMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00008: Normal(Talk, TargetCanMove), id=MOGWIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00009: Normal(Talk, TargetCanMove), id=MOGWIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00010: Normal(Talk, TargetCanMove), id=MOGTOE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00011: Normal(Talk, TargetCanMove), id=MOGOMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling [BranchTrue]Scene00013: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00014: Normal(Talk, TargetCanMove), id=MOGWIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00015: Normal(Talk, TargetCanMove), id=MOGTOE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00016: Normal(Talk, TargetCanMove), id=MOGOMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling Scene00017: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00018( player );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna321:67158 calling [BranchTrue]Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MOGWIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna321 );
