// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc410 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc410() : Sapphire::ScriptAPI::EventScript( 66521 ){}; 
  ~GaiUsc410() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006538
  //ACTOR1 = 1006540
  //ACTOR2 = 1006518
  //ENEMY0 = 4301829
  //ENEMY1 = 4301830
  //ENEMY2 = 4301839
  //ENEMY3 = 4301840
  //ENEMY4 = 4301841
  //EOBJECT0 = 2002540
  //EOBJECT1 = 2002541
  //EVENTACTIONSEARCH = 1

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CAILEAN
        break;
      }
      case 1:
      {
        if( param1 == 2002540 || param2 == 2002540 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00003( player ); // Scene00003: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4301829 || param2 == 4301829 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4301830 || param2 == 4301830 ) // ENEMY1 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 1006540 || param2 == 1006540 ) // ACTOR1 = IMPERIALSOLB
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=IMPERIALSOLB
            // +Callback Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=IMPERIALSOLB
            // +Callback Scene00006: Normal(Talk, TargetCanMove), id=IMPERIALSOLB
          }
          break;
        }
        if( param1 == 2002541 || param2 == 2002541 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 3 )
          {
            Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4301839 || param2 == 4301839 ) // ENEMY2 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4301840 || param2 == 4301840 ) // ENEMY3 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4301841 || param2 == 4301841 ) // ENEMY4 = unknown
        {
          // empty entry
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00009( player ); // Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PIERREMONS
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
    player.sendDebug( "emote: {}", emoteId );
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
    if( player.getQuestUI8BH( getId() ) == 2 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 3 )
        {
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestBitFlag8( getId(), 1, false );
          player.setQuestBitFlag8( getId(), 2, false );
          player.setQuestBitFlag8( getId(), 3, false );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc410:66521 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc410:66521 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CAILEAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8BH = 2, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc410:66521 calling Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 2 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }



  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUsc410:66521 calling Scene00004: Normal(Talk, TargetCanMove), id=IMPERIALSOLB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUsc410:66521 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=IMPERIALSOLB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUsc410:66521 calling Scene00006: Normal(Talk, TargetCanMove), id=IMPERIALSOLB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8BL = 3, Flag8(3)=True
  {
    player.sendDebug( "GaiUsc410:66521 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }




  void Scene00009( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc410:66521 calling Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PIERREMONS" );
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
    player.playScene( getId(), 9, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsc410 );
