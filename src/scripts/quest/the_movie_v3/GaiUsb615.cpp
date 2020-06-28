// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb615 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb615() : Sapphire::ScriptAPI::EventScript( 66847 ){}; 
  ~GaiUsb615() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 2 entries
  //SEQ_4, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006385
  //EOBJECT0 = 2003306
  //EOBJECT1 = 2003163
  //EVENTACTIONSEARCH = 1

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
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=DUVICAUROIX
        break;
      }
      case 2:
      {
        if( actor == 2003306 || actorId == 2003306 ) // EOBJECT0 = DUVICAUROIX
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=DUVICAUROIX
          }
        }
        if( actor == 2003163 || actorId == 2003163 ) // EOBJECT1 = DUVICAUROIX
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=DUVICAUROIX
        }
        break;
      }
      case 3:
      {
        if( actor == 2003306 || actorId == 2003306 ) // EOBJECT0 = SNOWMAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk), id=SNOWMAN
          }
        }
        if( actor == 2003163 || actorId == 2003163 ) // EOBJECT1 = SNOWMAN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, QuestGimmickReaction), id=SNOWMAN
        }
        break;
      }
      case 4:
      {
        if( actor == 2003306 || actorId == 2003306 ) // EOBJECT0 = SNOWMAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk), id=SNOWMAN
          }
        }
        if( actor == 2003163 || actorId == 2003163 ) // EOBJECT1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1006385 || actorId == 1006385 ) // ACTOR0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 2003163 || actorId == 2003163 ) // EOBJECT1 = SNOWMAN
        {
          Scene00010( player ); // Scene00010: Normal(Talk), id=SNOWMAN
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
    player.updateQuest( getId(), 2 );
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
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb615:66847 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb615:66847 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=DUVICAUROIX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb615:66847 calling Scene00002: Normal(Talk, TargetCanMove), id=DUVICAUROIX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb615:66847 calling Scene00003: Normal(Talk, TargetCanMove), id=DUVICAUROIX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb615:66847 calling Scene00004: Normal(Talk, TargetCanMove), id=DUVICAUROIX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb615:66847 calling Scene00005: Normal(Talk), id=SNOWMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb615:66847 calling Scene00006: Normal(Talk, QuestGimmickReaction), id=SNOWMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb615:66847 calling Scene00007: Normal(Talk), id=SNOWMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb615:66847 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb615:66847 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb615:66847 calling Scene00010: Normal(Talk), id=SNOWMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb615 );
