// FFXIVTheMovie.ParserV3.3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb003 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb003() : Sapphire::ScriptAPI::EventScript( 66346 ){}; 
  ~GaiUsb003() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1006264
  //ENEMY0 = 4291318
  //EOBJECT0 = 2002034
  //EOBJECT1 = 2002633
  //EOBJECT2 = 2002634
  //EOBJECT3 = 2002635
  //EOBJECT4 = 2002636
  //EOBJECT5 = 2002637
  //EVENTACTIONLOOKOUTLONG = 41
  //EVENTACTIONSEARCH = 1

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TRACHTOUM
        break;
      }
      case 1:
      {
        if( param1 == 2002034 || param2 == 2002034 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4291318 || param2 == 4291318 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 2002633 || param2 == 2002633 ) // EOBJECT1 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002634 || param2 == 2002634 ) // EOBJECT2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002635 || param2 == 2002635 ) // EOBJECT3 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002636 || param2 == 2002636 ) // EOBJECT4 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002637 || param2 == 2002637 ) // EOBJECT5 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006264 || param2 == 1006264 ) // ACTOR0 = TRACHTOUM
        {
          Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TRACHTOUM
          break;
        }
        if( param1 == 2002633 || param2 == 2002633 ) // EOBJECT1 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002634 || param2 == 2002634 ) // EOBJECT2 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002635 || param2 == 2002635 ) // EOBJECT3 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002636 || param2 == 2002636 ) // EOBJECT4 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002637 || param2 == 2002637 ) // EOBJECT5 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
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
    //onProgress( player, npcId, 0, 2, 0 );
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb003:66346 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb003:66346 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TRACHTOUM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb003:66346 calling Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }


  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb003:66346 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb003:66346 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb003:66346 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb003:66346 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb003:66346 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb003:66346 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TRACHTOUM" );
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

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb003:66346 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb003:66346 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb003:66346 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb003:66346 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb003:66346 calling Scene00024: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb003 );
