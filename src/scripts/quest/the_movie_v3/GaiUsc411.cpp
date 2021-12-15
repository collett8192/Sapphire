// FFXIVTheMovie.ParserV3.4
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc411 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc411() : Sapphire::ScriptAPI::EventScript( 66522 ){}; 
  ~GaiUsc411() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006531
  //ACTOR1 = 1006534
  //ACTOR2 = 1006535
  //ENEMY0 = 4301976
  //ENEMY1 = 4301980
  //ENEMY2 = 4301981
  //ENEMY3 = 4301983
  //EOBJECT0 = 2002201
  //EOBJECT1 = 2002202
  //EVENTACTIONSEARCH = 1

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GLAUMUNT
        break;
      }
      case 1:
      {
        if( param1 == 2002201 || param2 == 2002201 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00003( player ); // Scene00003: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4301976 || param2 == 4301976 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4301980 || param2 == 4301980 ) // ENEMY1 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4301981 || param2 == 4301981 ) // ENEMY2 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4301983 || param2 == 4301983 ) // ENEMY3 = unknown
        {
          // empty entry
          break;
        }
        break;
      }
      case 2:
      {
        if( type != 2 ) Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=unknown
        break;
      }
      case 3:
      {
        if( type != 2 ) Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00007( player ); // Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID
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
    if( player.getQuestUI8AL( getId() ) == 4 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc411:66522 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc411:66522 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GLAUMUNT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc411:66522 calling Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 4 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }





  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc411:66522 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc411:66522 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc411:66522 calling Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID" );
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
    player.playScene( getId(), 7, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsc411 );
