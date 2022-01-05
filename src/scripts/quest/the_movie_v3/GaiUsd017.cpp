// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsd017 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsd017() : Sapphire::ScriptAPI::EventScript( 66948 ){}; 
  ~GaiUsd017() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1007478
  //ACTOR1 = 1000168
  //ACTOR2 = 1008544
  //ACTOR3 = 1008545
  //EOBJECT0 = 2004032
  //EVENTACTIONSEARCH = 1
  //LOCACTOR0 = 1008001
  //LOCPOSACTOR0 = 4629276
  //QSTCOMPCHK1 = 66733
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKIMAGEDUNGEON = 187

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=VORSAILE
        break;
      }
      case 255:
      {
        if( param1 == 1008544 || param2 == 1008544 ) // ACTOR2 = KUPLOKOPP
        {
          Scene00003( player ); // Scene00003: Normal(Talk, Message, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=KUPLOKOPP
          break;
        }
        if( param1 == 1008545 || param2 == 1008545 ) // ACTOR3 = BODYGUARD01412
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=BODYGUARD01412
          break;
        }
        if( param1 == 1000168 || param2 == 1000168 ) // ACTOR1 = VORSAILE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=VORSAILE
          break;
        }
        if( param1 == 2004032 || param2 == 2004032 ) // EOBJECT0 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd017:66948 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsd017:66948 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd017:66948 calling Scene00002: Normal(Talk, TargetCanMove), id=VORSAILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd017:66948 calling Scene00003: Normal(Talk, Message, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=KUPLOKOPP" );
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
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd017:66948 calling Scene00004: Normal(Talk, TargetCanMove), id=BODYGUARD01412" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd017:66948 calling Scene00005: Normal(Talk, TargetCanMove), id=VORSAILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_255: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd017:66948 calling Scene00007: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsd017 );
