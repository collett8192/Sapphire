// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdz003 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdz003() : Sapphire::ScriptAPI::EventScript( 68173 ){}; 
  ~StmBdz003() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1021167
  //ACTOR1 = 1021168
  //ACTOR2 = 1021169
  //ACTOR3 = 1021170
  //ACTOR4 = 1021171
  //ACTOR5 = 1021172
  //QSTACTION0 = 954

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ANANTASOLDIER02637
        break;
      }
      case 1:
      {
        if( param1 == 1021168 || param2 == 1021168 ) // ACTOR1 = BRAVESOLDIER02637
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=BRAVESOLDIER02637
          }
        }
        if( param1 == 1021169 || param2 == 1021169 ) // ACTOR2 = YOUNGSOLDIER02637
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=YOUNGSOLDIER02637
          }
        }
        if( param1 == 1021170 || param2 == 1021170 ) // ACTOR3 = YANGSOLDIER02637
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=YANGSOLDIER02637
          }
        }
        if( param1 == 1021171 || param2 == 1021171 ) // ACTOR4 = SINGANSOLDIER02637
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=SINGANSOLDIER02637
          }
        }
        if( param1 == 1021172 || param2 == 1021172 ) // ACTOR5 = SOWASOWAUSOLDIER02637
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=SOWASOWAUSOLDIER02637
          }
        }
        if( param1 == 1021167 || param2 == 1021167 ) // ACTOR0 = ANANTASOLDIER
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ANANTASOLDIER
        }
        break;
      }
      case 255:
      {
        Scene00008( player ); // Scene00008: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=ANANTASOLDIER02637
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
    if( player.getQuestUI8AL( getId() ) == 5 )
      if( player.getQuestUI8AL( getId() ) == 5 )
        if( player.getQuestUI8AL( getId() ) == 5 )
          if( player.getQuestUI8AL( getId() ) == 5 )
            if( player.getQuestUI8AL( getId() ) == 5 )
            {
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.updateQuest( getId(), 255 );
            }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBdz003:68173 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdz003:68173 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ANANTASOLDIER02637" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdz003:68173 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=BRAVESOLDIER02637" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdz003:68173 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=YOUNGSOLDIER02637" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdz003:68173 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=YANGSOLDIER02637" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdz003:68173 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=SINGANSOLDIER02637" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdz003:68173 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=SOWASOWAUSOLDIER02637" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdz003:68173 calling Scene00007: Normal(Talk, TargetCanMove), id=ANANTASOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdz003:68173 calling Scene00008: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=ANANTASOLDIER02637" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdz003 );
