// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb609 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb609() : Sapphire::ScriptAPI::EventScript( 66427 ){}; 
  ~GaiUsb609() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1006385
  //ENEMY0 = 4290140
  //EOBJECT0 = 2002112
  //EOBJECT1 = 2002623
  //EOBJECT2 = 2002624
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONWAITING = 10

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=DUVICAUROIX
        break;
      }
      case 1:
      {
        if( actor == 2002112 || actorId == 2002112 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
            // +Callback Scene00003: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4290140 || actorId == 4290140 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 2002623 || actorId == 2002623 ) // EOBJECT1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          // +Callback Scene00005: Normal(None), id=unknown
        }
        if( actor == 2002624 || actorId == 2002624 ) // EOBJECT2 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          // +Callback Scene00007: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1006385 || actorId == 1006385 ) // ACTOR0 = DUVICAUROIX
        {
          Scene00008( player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=DUVICAUROIX
        }
        if( actor == 2002623 || actorId == 2002623 ) // EOBJECT1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          // +Callback Scene00010: Normal(None), id=unknown
        }
        if( actor == 2002624 || actorId == 2002624 ) // EOBJECT2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          // +Callback Scene00012: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb609:66427 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb609:66427 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=DUVICAUROIX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb609:66427 calling Scene00002: Normal(None), id=unknown" );
    Scene00003( player );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb609:66427 calling [BranchTrue]Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb609:66427 calling Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb609:66427 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb609:66427 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb609:66427 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb609:66427 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=DUVICAUROIX" );
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

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb609:66427 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb609:66427 calling [BranchTrue]Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb609:66427 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb609:66427 calling [BranchTrue]Scene00012: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb609 );
