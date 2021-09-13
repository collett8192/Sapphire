// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil113 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil113() : Sapphire::ScriptAPI::EventScript( 66157 ){}; 
  ~SubWil113() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 10 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1003929
  //ACTOR1 = 1003976
  //ACTOR2 = 1003971
  //ACTOR3 = 1003972
  //ACTOR4 = 1003973
  //ACTOR5 = 1003974
  //ACTOR6 = 1003975
  //ENEMY0 = 4102012
  //ENEMY1 = 4102013
  //EOBJECT0 = 2001868
  //EVENTRANGE0 = 4102016
  //EVENTACTIONRESCUEUNDERMIDDLE = 35
  //EVENTACTIONSEARCH = 1

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ISEMBARD
        break;
      }
      case 1:
      {
        if( param1 == 1003976 || param2 == 1003976 ) // ACTOR1 = CHILD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=CHILD
          }
          break;
        }
        if( param1 == 1003971 || param2 == 1003971 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003972 || param2 == 1003972 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003973 || param2 == 1003973 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003974 || param2 == 1003974 ) // ACTOR5 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 4102016 || param2 == 4102016 ) // EVENTRANGE0 = unknown
        {
          //Scene00008( player ); // Scene00008: Normal(Message), id=unknown
          break;
        }
        if( param1 == 1003975 || param2 == 1003975 ) // ACTOR6 = OURCEN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=OURCEN
          break;
        }
        if( param1 == 4102012 || param2 == 4102012 ) // ENEMY0 = unknown
        {
          /*
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq2( player );
          }
          */
          break;
        }
        if( param1 == 4102013 || param2 == 4102013 ) // ENEMY1 = unknown
        {
          /*
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq2( player );
          }
          */
          break;
        }
        if( param1 == 1003976 || param2 == 1003976 ) // ACTOR1 = CHILD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CHILD
          break;
        }
        if( param1 == 1003971 || param2 == 1003971 ) // ACTOR2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003972 || param2 == 1003972 ) // ACTOR3 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003973 || param2 == 1003973 ) // ACTOR4 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003974 || param2 == 1003974 ) // ACTOR5 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001868 || param2 == 2001868 ) // EOBJECT0 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        Scene00017( player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ISEMBARD
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
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "SubWil113:66157 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ISEMBARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00002: Normal(Talk, TargetCanMove), id=CHILD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00008: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=OURCEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }



  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00010: Normal(Talk, TargetCanMove), id=CHILD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubWil113:66157 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ISEMBARD" );
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
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil113 );
