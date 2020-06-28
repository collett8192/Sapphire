// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea120 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea120() : Sapphire::ScriptAPI::EventScript( 65953 ){}; 
  ~SubSea120() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 9 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002445
  //ACTOR1 = 1002237
  //ENEMY0 = 3818788
  //ENEMY1 = 3818789
  //ENEMY2 = 3818790
  //ENEMY3 = 3818791
  //ENEMY4 = 3818792
  //ENEMY5 = 3818793
  //EOBJECT0 = 2000775
  //EOBJECT1 = 2000776
  //EOBJECT2 = 2000777
  //EVENTACTION = 32
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000225

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ROSTNZEH
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 1
      case 1:
      {
        if( actor == 2000775 || actorId == 2000775 ) // EOBJECT0 = unknown
        {
          Scene00001( player ); // Scene00001: Normal(None), id=unknown
        }
        if( actor == 3818788 || actorId == 3818788 ) // ENEMY0 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(Message), id=unknown
        }
        if( actor == 3818789 || actorId == 3818789 ) // ENEMY1 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
        }
        if( actor == 2000776 || actorId == 2000776 ) // EOBJECT1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( actor == 3818790 || actorId == 3818790 ) // ENEMY2 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 3818791 || actorId == 3818791 ) // ENEMY3 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( actor == 2000777 || actorId == 2000777 ) // EOBJECT2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( actor == 3818792 || actorId == 3818792 ) // ENEMY4 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 3818793 || actorId == 3818793 ) // ENEMY5 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        Scene00010( player ); // Scene00010: Normal(None), id=unknown
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
    player.setQuestUI8CH( getId(), 0 );
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea120:65953 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=ROSTNZEH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "SubSea120:65953 calling Scene00001: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea120:65953 calling Scene00002: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea120:65953 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea120:65953 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubSea120:65953 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubSea120:65953 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubSea120:65953 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubSea120:65953 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubSea120:65953 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubSea120:65953 calling Scene00010: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubSea120 );
