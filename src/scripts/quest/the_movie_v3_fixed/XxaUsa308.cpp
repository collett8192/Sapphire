// FFXIVTheMovie.ParserV3.3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class XxaUsa308 : public Sapphire::ScriptAPI::EventScript
{
public:
  XxaUsa308() : Sapphire::ScriptAPI::EventScript( 69398 ){}; 
  ~XxaUsa308() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 3 entries
  //SEQ_3, 2 entries
  //SEQ_4, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000590
  //ACTOR1 = 1006199
  //ACTOR2 = 1006201
  //ACTOR3 = 1006203
  //ENEMY0 = 4293402
  //EOBJECT0 = 2001954
  //EOBJECT1 = 2002271
  //QSTACCEPTCHECK = 66276
  //QUESTBATTLE0 = 13
  //TERRITORYTYPE0 = 232

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=BUSCARRON
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS
        break;
      }
      case 2:
      {
        if( param1 == 1006201 || param2 == 1006201 ) // ACTOR2 = LAURENTIUS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, Message, PopBNpc, TargetCanMove), id=LAURENTIUS
          }
          break;
        }
        if( param1 == 4293402 || param2 == 4293402 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 2001954 || param2 == 2001954 ) // EOBJECT0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(Message, PopBNpc), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1006201 || param2 == 1006201 ) // ACTOR2 = LAURENTIUS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS
          }
          break;
        }
        if( param1 == 2001954 || param2 == 2001954 ) // EOBJECT0 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1006203 || param2 == 1006203 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(QuestBattle, YesNo), id=unknown
          }
          break;
        }
        if( param1 == 2002271 || param2 == 2002271 ) // EOBJECT1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001954 || param2 == 2001954 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        Scene00011( player ); // Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BUSCARRON
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
    player.sendDebug( "XxaUsa308:69398 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown" );
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
    player.sendDebug( "XxaUsa308:69398 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=BUSCARRON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "XxaUsa308:69398 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "XxaUsa308:69398 calling Scene00003: Normal(Talk, Message, PopBNpc, TargetCanMove), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }


  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "XxaUsa308:69398 calling Scene00004: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "XxaUsa308:69398 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "XxaUsa308:69398 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "XxaUsa308:69398 calling Scene00008: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        //quest battle
        player.eventFinish( getId(), 1 );
        //auto& pTeriMgr = Common::Service< Sapphire::World::Manager::TerritoryMgr >::ref();
        //pTeriMgr.createAndJoinQuestBattle( player, 13 );
        player.sendUrgent( "quest battle 13 missing" );
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq4( player );
        player.forceZoneing();
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "XxaUsa308:69398 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "XxaUsa308:69398 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "XxaUsa308:69398 calling Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BUSCARRON" );
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
    player.playScene( getId(), 11, NONE, callback );
  }
};

EXPOSE_SCRIPT( XxaUsa308 );
