// FFXIVTheMovie.ParserV3.5
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class XxaUsc603 : public Sapphire::ScriptAPI::EventScript
{
public:
  XxaUsc603() : Sapphire::ScriptAPI::EventScript( 69407 ){}; 
  ~XxaUsc603() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006552
  //ACTOR1 = 1006988
  //ENEMY0 = 64
  //ENEMY1 = 63
  //ENEMY2 = 62
  //ENEMY3 = 55
  //ENEMY4 = 61
  //ITEM0 = 2003021
  //ITEM1 = 2003022
  //ITEM2 = 2003023
  //ITEM3 = 2003024
  //QSTACCEPTCHECK = 66539

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SARKMALARK
        break;
      }
      //seq 1 event item ITEM0 = UI8BL max stack 3
      //seq 1 event item ITEM1 = UI8CH max stack 3
      case 1:
      {
        if( param1 == /*UNKNOWN*/1 || param2 == /*UNKNOWN*/1 ) // ENEMY0 or A3_67 == A0_64.ENEMY1 or A3_67 == A0_64.ENEMY2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 3 )
          {
            player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
          break;
        }
        if( param1 == /*UNKNOWN*/1 || param2 == /*UNKNOWN*/1 ) // ENEMY3 or A3_67 == A0_64.ENEMY4 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 3 )
          {
            player.setQuestUI8CH( getId(), player.getQuestUI8CH( getId() ) + 1 );
            checkProgressSeq1( player );
          }
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 3
      //seq 2 event item ITEM1 = UI8BL max stack 3
      case 2:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00003: Normal(Talk, TargetCanMove), id=SARKMALARK
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 3
      //seq 3 event item ITEM1 = UI8BL max stack 3
      //seq 3 event item ITEM2 = UI8CH max stack 3
      //seq 3 event item ITEM3 = UI8CL max stack 3
      case 3:
      {
        if( type != 2 ) Scene00004( player ); // Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=EGINOLF
        break;
      }
      //seq 255 event item ITEM2 = UI8BH max stack 3
      //seq 255 event item ITEM3 = UI8BL max stack 3
      case 255:
      {
        if( type != 2 ) Scene00006( player ); // Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SARKMALARK
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
    //player.updateQuest( getId(), 1 );
    player.updateQuest( getId(), 2 );
    player.setQuestUI8BH( getId(), 3 );
    player.setQuestUI8BL( getId(), 3 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 3 )
      if( player.getQuestUI8CH( getId() ) == 3 )
      {
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.updateQuest( getId(), 2 );
        player.setQuestUI8BH( getId(), 3 );
        player.setQuestUI8BL( getId(), 3 );
      }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
    player.setQuestUI8CH( getId(), 3 );
    player.setQuestUI8CL( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.setQuestUI8BL( getId(), 0 );
    player.setQuestUI8CH( getId(), 0 );
    player.setQuestUI8CL( getId(), 0 );
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 3 );
    player.setQuestUI8BL( getId(), 3 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc603:69407 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown" );
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
    player.sendDebug( "XxaUsc603:69407 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SARKMALARK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }



  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc603:69407 calling Scene00002: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00003( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc603:69407 calling Scene00003: Normal(Talk, TargetCanMove), id=SARKMALARK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc603:69407 calling Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00005( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc603:69407 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=EGINOLF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc603:69407 calling Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00007( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "XxaUsc603:69407 calling Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SARKMALARK" );
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

EXPOSE_SCRIPT( XxaUsc603 );
